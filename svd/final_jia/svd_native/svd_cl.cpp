//复数矩阵的SVD分解 OpenCL程序
//贾海鹏   jiahaipeng95@gmail.com
//复数矩阵的奇异值分解，复数矩阵的存储格式为矩阵实部与虚部分离存储，即：前m行存储实部矩阵，后m行存储虚部矩阵
//一个m*n的复数矩阵的大小为2m*n
//计算结果与matlab结果比较，奇异值S相等，变换后A的精度在10的-5次方，V的精度为10的-3次方
//当矩阵规模为256 * 256时，收敛的迭代次数为10
//本程序只实现了复数矩阵的SVD分解

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <memory.h>
#include <sys/time.h>

#include <CL/cl.h>

using namespace std;
using std::cout;
using std::endl;

#define COLS  256 
#define ROWS  256 
#define TYPE  double 
#define MAX_ITERATIONS 40 
#define THRESHOLD  0.00001

#define FLAG   1      //0 为实数矩阵， 1为复数矩阵
#define IN_PRODUCT  1

//OpenCL kernel字符串，见kernels.cpp
extern const char *svd;

//打印矩阵 只为调试
void print_matrix(TYPE *A)
{
    cout.setf(ios::fixed);
    for(int i = 0; i < ROWS * 2; i++)
    {
        for(int j = 0; j < COLS; j++)
            cout << setprecision(5) <<  A[i * COLS + j] << " ";
        cout << endl;
    }
}
//打印向量  只为调试
void print_vector(TYPE *A)
{
    for(int i = 0; i < COLS; i++)
    {
        cout << setprecision(6) << A[i] << " ";
        cout << endl;
    }
}
//比较两个向量是否相等，只为测试
bool is_matrix_equal(TYPE *A, TYPE *B, TYPE eps) 
{
    for(int i = 0; i < ROWS * 2; i++)
        for(int j = 0; j < COLS; j++)
        {
            if(fabs(A[i * COLS + j] - B[i * COLS +j]) > eps)
            {
                cout << "i = " << i << "j = " << j  <<endl;
                cout << "A = " << A[i * COLS + j] <<endl;
                cout << "B= "  << B[i * COLS + j] << endl; 
                return 0;
            }
        }

    return 1;
}
//比较两个奇异值是否相等，只为测试
bool is_vector_equal(TYPE *A, TYPE *B, TYPE eps) 
{
    for(int j = 0; j < COLS; j++)
    {
        if(fabs(A[j] - B[j]) > eps)
        {
            cout << "j = " << j  <<endl;
            cout << "A = " << A[j] <<endl;
            cout << "B= "  << B[j] << endl; 
            return 0;
        }
    }

    return 1;
}

//svd计算   A = BSV
//SVD 最主要的计算在矩阵两列的正交变换上
//在GPU计算中，对于行优先存储的矩阵，如果按列读取数据的话，性能会非常低
//因此，OpenCL实现的第一步是对A进行转置
int svd_compute(TYPE *A, TYPE *B, TYPE *S, TYPE *V)
{
    /**************************前期准备**************************/

    //对A进行转置转置后的矩阵存储于A_H中
    //对复数矩阵的实部矩阵和虚部矩阵分别进行转置
    //因为矩阵的规模较小（一般为16 * 16 ~ 256 *256），因此，矩阵转置放在CPU端进行
    //TODO: 矩阵A的转置先放在CPU端进行，是否移植到GPU端，下面评估性能后再决定
    TYPE *A_H = new TYPE[ROWS * COLS * 2];
    TYPE *V_H = new TYPE[ROWS * COLS * 2];

    //对A的实部矩阵进行转置
    for(int i = 0; i < ROWS; i++) 
        for(int j = 0; j < COLS; j++)
            A_H[i * ROWS + j] = A[j * ROWS + i];

    //对A的虚部矩阵进行转置
    for(int i = 0; i < ROWS; i++) 
        for(int j = 0; j < COLS; j++)
            A_H[COLS * ROWS + i * ROWS + j] = A[COLS * ROWS + j * ROWS + i];

    //将矩阵V_H初始化为单位矩阵, V_H为V的转置矩阵
    memset(V_H, 0, ROWS * COLS * 2 * sizeof(TYPE));
    for(int i = 0; i < ROWS; i++)
        V_H[i * ROWS + i] = 1.0f;

    //初始化列索引,因矩阵规模较小，所以初始化操作在CPU进行
    int *rorate_col_index = new int[COLS];
    for(int i = 0; i < COLS; i++)
        rorate_col_index[i] = i;

    /**********OpenCL初始化***************************/
    //OpenCL初始化可以提取出来，形成库，没有必要为每一个OpenCL程序写OpenCL初始化代码

    cl_int status;

    //查找OpenCL平台
    cl_uint num_platforms;
    cl_platform_id platform = NULL;
    status = clGetPlatformIDs(0,NULL,&num_platforms);
    if(status != CL_SUCCESS || num_platforms <= 0)
    {
        cout << "Error: Getting Platfroms.(clGetPlatfroms), no platform supported OpenCL founded, status = " 
            << status <<endl;
        return EXIT_FAILURE;
    }

    cl_platform_id * platforms = (cl_platform_id * )malloc(num_platforms * sizeof(cl_platform_id));
    status = clGetPlatformIDs(num_platforms,platforms,NULL);
    if(status!=CL_SUCCESS)
    {
        cout << "Error: Getting Platfrom Ids.(clGetPlatformIDs), status = " << status << endl;
        return EXIT_FAILURE;
    }
    //获得AMD平台, 在Nvidia平台上运行程序时，需修改这个地方
    for(unsigned int i=0;i < num_platforms; i++)
    {
        char pbuff[100];
        status = clGetPlatformInfo(platforms[i], CL_PLATFORM_VENDOR, sizeof(pbuff), pbuff, NULL);
        platform = platforms[i];
        if(!strcmp(pbuff,"Advanced Micro Devices, Inc."))//查找AMD平台
            break;
    }
    free(platforms);

    // 寻找OpenCL设备,默认情况下使用GPU
    cl_uint num_devices = 0;
    status = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 0, NULL, &num_devices);
    if (status != CL_SUCCESS && num_devices <= 0)
    {
        cout << "Error: Getting Context Info,(device list size ,clGetDeviceIDs), status = " << status << endl;
        return EXIT_FAILURE;
    }
    cl_device_id * devices = (cl_device_id *)malloc(num_devices);
    status = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, num_devices, devices, NULL);
    if ( status != CL_SUCCESS)
    {
        cout << "Error: Getting Context Info (device list,clGetContextInfo), status = " << status << endl;
        return EXIT_FAILURE;
    }

    //生成上下文	
    cl_context context = clCreateContext(NULL, num_devices, devices, NULL, NULL, &status);
    if(status != CL_SUCCESS)
    {
        cout <<"Error: Creating Context.(clCreateContextFromType), status = " << status << endl;
        return EXIT_FAILURE;
    }

    // 创建OpenCL command queue,默认情况下使用第0号设备
    // 如果需要的设备不是第0号，请修改这个地方
    cl_command_queue commandQueue = clCreateCommandQueue(context, devices[1], 0, &status);
    if(status != CL_SUCCESS)
    {
        cout << "Create Command Queue.(clCreateCommandQueue), status = " << status << endl;
        return EXIT_FAILURE;
    }

    //创建 OpenCL buffer 对象
    cl_mem A_CL = clCreateBuffer(context, CL_MEM_READ_WRITE, ROWS*COLS*2*sizeof(TYPE), NULL, &status);
    if(status != CL_SUCCESS)
    {
        cout << "Error: clCreateBuffer,A_CL buffer, status = " << status << endl;
        return EXIT_FAILURE;
    }

    cl_mem V_CL = clCreateBuffer(context, CL_MEM_READ_WRITE, ROWS*COLS*2*sizeof(TYPE), NULL, &status);
    if(status != CL_SUCCESS)
    {
        cout << "Error: clCreateBuffer,V_CL buffer, status = " << status << endl;
        return EXIT_FAILURE;
    }

    cl_mem S_CL = clCreateBuffer(context, CL_MEM_READ_WRITE, COLS*sizeof(TYPE), NULL, &status);
    if(status != CL_SUCCESS)
    {
        cout << "Error: clCreateBuffer,S_CL buffer, status = " << status << endl;
        return EXIT_FAILURE;
    }

    cl_mem rorate_col_index_CL = clCreateBuffer(context, CL_MEM_READ_WRITE, COLS*sizeof(int), NULL, &status);
    if(status != CL_SUCCESS)
    {
        cout << "Error: clCreateBuffer,rorate_col_index_CL buffer, status = " << status << endl;
        return EXIT_FAILURE;
    }

    cl_mem  is_convergence = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(int), NULL, &status);
    if(status != CL_SUCCESS)
    {
        cout << "Error: clCreateBuffer, is_convergence, status = " << status << endl;
        return EXIT_FAILURE;
    }

    //向CPU端传递数据
    status = clEnqueueWriteBuffer(commandQueue, A_CL, CL_TRUE, 0, ROWS*COLS*2*sizeof(TYPE), A_H, 0, NULL, NULL);
    if(status != CL_SUCCESS)
    {
        cout << "Error: writeBuffer, A_CL buffer, status = " << status << endl;
        return EXIT_FAILURE;
    }
    status = clEnqueueWriteBuffer(commandQueue, V_CL, CL_TRUE, 0, ROWS*COLS*2*sizeof(TYPE), V_H, 0, NULL, NULL);
    if(status != CL_SUCCESS)
    {
        cout << "Error: writeBuffer, V_CL buffer, status = " << status << endl;
        return EXIT_FAILURE;
    }
    status = clEnqueueWriteBuffer(commandQueue, rorate_col_index_CL, CL_TRUE, 0, COLS*sizeof(int), rorate_col_index, 0, NULL, NULL);
    if(status != CL_SUCCESS)
    {
        cout << "Error: writeBuffer, rorate_col_index_CL buffer, status = " << status << endl;
        return EXIT_FAILURE;
    }

    // 装载内核程序，编译CL program，生成CL内核实例
    cl_program program = clCreateProgramWithSource(context, 1, (const char **)&svd, NULL, &status);
    if(status != CL_SUCCESS)
    {
        cout << "Error:Loading Binary into cl_program, (clCreateProgramWithBinary), status = " << status << endl;
        return EXIT_FAILURE;
    }

    status = clBuildProgram(program,1,&(devices[1]),NULL,NULL,NULL);
    if(status != CL_SUCCESS)
    {
        cout << ("Error: Building Program ,(clBuildProgram), status = ") << status << endl;

        if(status == CL_BUILD_PROGRAM_FAILURE)
        {
            //打印编译出错信息
            cl_int log_status;
            char *build_log = NULL;
            size_t build_log_size = 0;

            log_status = clGetProgramBuildInfo(program, devices[1], CL_PROGRAM_BUILD_LOG, 0, NULL, &build_log_size);
            if(log_status != CL_SUCCESS)
                cout << "Failed to build the program and get the build info." << endl;

            build_log = new char[build_log_size];
            memset(build_log, 0, build_log_size);
            log_status = clGetProgramBuildInfo(program, devices[1], CL_PROGRAM_BUILD_LOG, build_log_size, build_log, NULL);
            if(log_status != CL_SUCCESS)
                cout << "Failed to build the program and get the build info." << endl;

            cout << "\n\t\t\tBUILD LOG\n";
            cout << build_log << endl;
            delete [] build_log;

            return EXIT_FAILURE;
        }
    }

    cl_kernel kernel = clCreateKernel(program, "svd_op", &status);
    if(status != CL_SUCCESS)
    {
        cout << "Error: Creating Kernel from program,(clCreateKernel), status = " << status << endl;
        return EXIT_FAILURE;
    }
    /******************************进行SVD计算*******************************************/

    //设置NDRANGE
    size_t local_threads[]  = {ROWS, 1, 1};
    size_t global_threads[] = {COLS/2 * local_threads[0], 1, 1};

    int iteration = MAX_ITERATIONS;
    int *pass = new int[1]; 

    //计时函数
    struct timeval begin, end;

    //计时说明
    //计时只包括计算V和S的主要计算时间
    //没有包括OpenCL初始化时间：如运行大量OpenCL程序，OpenCL初始化只进行一次即可
    //没有包括CPU与GPU的数据传输时间：在批量处理中，这个数据传输时间完全可以与GPU计算时间重叠
    gettimeofday(&begin, NULL);
    while(iteration > 0)
    {
        //仅用于测试，查看矩阵收敛次数
        cout << "iteration = " << iteration << endl;
        //TODO 每一轮的每一阶段都重新启动一次kernel，这样会增加kernel启动和全局同步的开销
        //以后优化改进
        for(int i = 0; i < COLS; i++)
        {
            status = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&A_CL);
            if(status != CL_SUCCESS)
            {
                cout << "Error: Setting kernel argument, A_CL, status = " << status << endl;
                return EXIT_FAILURE;
            }

            status = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&V_CL);
            if(status != CL_SUCCESS)
            {
                cout << "error: setting kernel argument, V_cl, status = " << status << endl;
                return EXIT_FAILURE;
            }

            status = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&rorate_col_index_CL);
            if(status != CL_SUCCESS)
            {
                cout << "error: setting kernel argument, rorate_col_index_CL, status = " << status << endl;
                return EXIT_FAILURE;
            }

            status = clSetKernelArg(kernel, 3, sizeof(cl_mem), (void *)&is_convergence);
            if(status != CL_SUCCESS)
            {
                cout << "error: setting kernel argument, is_convergence, status = " << status << endl;
                return EXIT_FAILURE;
            }

            //判断是奇数阶段还是偶数阶段，如果是偶数阶段，从第0个索引开始, 否则，从第一个索引开始
            int start_index = (i % 2 == 0) ? 0 : 1;
            status = clSetKernelArg(kernel, 4, sizeof(cl_int), (void *)&start_index);
            if(status != CL_SUCCESS)
            {
                cout << "error: setting kernel argument, start_index, status = " << status << endl;
                return EXIT_FAILURE;
            }

            //在GPU端是否初始化pass
            int init_pass = (i == 0) ? 1 : 0; 
            status = clSetKernelArg(kernel, 5, sizeof(cl_int), (void *)&init_pass);
            if(status != CL_SUCCESS)
            {
                cout << "error: setting kernel argument, init_pass, status = " << status << endl;
                return EXIT_FAILURE;
            }

            //将kernel放入command queue.
            status = clEnqueueNDRangeKernel(commandQueue, kernel, 3, NULL, global_threads, local_threads, 0, NULL, NULL);
            if(status != CL_SUCCESS)
            {
                cout << "Error: Enqueueing kernel, status = " << status << endl;
                return EXIT_FAILURE;
            }

            //TODO 在这里，可以优化掉clFinish，因为所有的kernel、数据读写都放在同一命令队列中，命令队列是按序执行的，
            //因此可以优化掉该clFinish
                      // status = clFinish(commandQueue);
                     // if(status != CL_SUCCESS)
                     //{
                      //  cout << "Error: Finish command queue, status = " << status << endl;
                      // return EXIT_FAILURE; 
                  //}
        }

        //取回判断是否收敛的条件
        status = clEnqueueReadBuffer(commandQueue, is_convergence, CL_TRUE, 0, sizeof(int), pass, 0, NULL, NULL);
        if(status != CL_SUCCESS)
        {
            cout << "Error: read buffer, is_convergence, status = " << status << endl;
            return EXIT_FAILURE; 
        }

        iteration--;

        if(pass[0] == 1)
            break;
    }

    //计算S
    size_t local_threads1[]  = {ROWS, 1, 1};
    size_t global_threads1[] = {COLS * local_threads[0], 1, 1};

    cl_kernel kernel1 = clCreateKernel(program, "s_comp", &status);
    if(status != CL_SUCCESS)
    {
        cout << "Error: Creating Kernel1 from program,(clCreateKernel), status = " << status << endl;
        return EXIT_FAILURE;
    }

    status = clSetKernelArg(kernel1, 0, sizeof(cl_mem), (void *)&A_CL);
    if(status != CL_SUCCESS)
    {
        cout << "Error: Setting kernel argument, A_CL, status = " << status << endl;
        return EXIT_FAILURE;
    }

    status = clSetKernelArg(kernel1, 1, sizeof(cl_mem), (void *)&S_CL);
    if(status != CL_SUCCESS)
    {
        cout << "Error: Setting kernel argument, A_CL, status = " << status << endl;
        return EXIT_FAILURE;
    }

    status = clEnqueueNDRangeKernel(commandQueue, kernel1, 3, NULL, global_threads1, local_threads1, 0, NULL, NULL);
    if(status != CL_SUCCESS)
    {
        cout << "Error: Enqueueing kernel, status = " << status << endl;
        return EXIT_FAILURE;
    }

    //该clFinish也可去掉，放在这里的原因是计时
    clFinish(commandQueue);

    gettimeofday(&end, NULL);

    cout << "The execute time is" << (end.tv_sec - begin.tv_sec) * 1000 + (end.tv_usec - begin.tv_usec)/1000 << "ms" << endl; 

    /******************取回运算结果****************************************************/

    status = clEnqueueReadBuffer(commandQueue, A_CL, CL_TRUE, 0, ROWS*COLS*2*sizeof(TYPE), A_H, 0, NULL, NULL);
    if(status != CL_SUCCESS)
    {
        cout << "Error: read buffer, A_CL, status = " << status << endl;
        return EXIT_FAILURE; 
    }

    status = clEnqueueReadBuffer(commandQueue, V_CL, CL_TRUE, 0, ROWS*COLS*2*sizeof(TYPE), V_H, 0, NULL, NULL);
    if(status != CL_SUCCESS)
    {
        cout << "Error: read buffer, V_CL, status = " << status << endl;
        return EXIT_FAILURE; 
    }

    status = clEnqueueReadBuffer(commandQueue, S_CL, CL_TRUE, 0, COLS*sizeof(TYPE), S, 0, NULL, NULL);
    if(status != CL_SUCCESS)
    {
        cout << "Error: read buffer, S_CL, status = " << status << endl;
        return EXIT_FAILURE; 
    }

    //将矩阵转置回来
    //矩阵A的转置
    for(int i = 0; i < ROWS; i++) 
        for(int j = 0; j < COLS; j++)
            A[i * ROWS + j] = A_H[j * ROWS + i];

    for(int i = 0; i < ROWS; i++) 
        for(int j = 0; j < COLS; j++)
            A[COLS * ROWS + i * ROWS + j] = A_H[COLS * ROWS + j * ROWS + i];

    //矩阵V的转置
    for(int i = 0; i < ROWS; i++) 
        for(int j = 0; j < COLS; j++)
            V[i * ROWS + j] = V_H[j * ROWS + i];

    for(int i = 0; i < ROWS; i++) 
        for(int j = 0; j < COLS; j++)
            V[COLS * ROWS + i * ROWS + j] = V_H[COLS * ROWS + j * ROWS + i];

    //释放资源
    delete A_H;
    delete V_H;
    clReleaseKernel(kernel);
    clReleaseKernel(kernel1);
    clReleaseProgram(program);
    clReleaseCommandQueue(commandQueue);
    clReleaseMemObject(A_CL);
    clReleaseMemObject(V_CL);
    clReleaseMemObject(S_CL);
    clReleaseMemObject(is_convergence);
    clReleaseMemObject(rorate_col_index_CL);
    clReleaseContext(context);

    return 0;
}

int main()
{
    TYPE *A = new TYPE[ROWS * COLS * 2];   //复数矩阵，前ROWS*COLS为实部矩阵，后ROWS*COLS为虚部矩阵
    TYPE *B = new TYPE[ROWS * COLS * 2];   //左奇异向量矩阵,存储格式如A
    TYPE *S = new TYPE[COLS];             //奇异值,为实数矩阵
    TYPE *V = new TYPE[ROWS * COLS * 2];   //右奇异向量矩阵,存储格式如A


    //从外部文件中读取原始矩阵A
    fstream f("./data/Matrix_input_A256.txt", ios::in);
    if(!f)
    {
        cout << "matrix input A is not found" << endl;
        return 1;
    }
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
            f >>setprecision(6) >>  A[i * COLS + j];

        for(int j = 0; j < COLS; j++)
            f >>setprecision(6) >>  A[ROWS * COLS + i * COLS + j];
    }

    f.close();

    //将S初始化为0
    memset(S, 0, COLS * sizeof(TYPE));

    //进行SVD计算
    svd_compute(A, B, S, V);

    /*****************************测试运算结果************************************/
    TYPE *A1 = new TYPE[ROWS * COLS * 2];   
    TYPE *V1 = new TYPE[ROWS * COLS * 2];  
    TYPE *S1 = new TYPE[COLS];            

    //测试A的正确性
    fstream f1("./data/Matrix_out_A256.txt", ios::in);
    if(!f1)
    {
        cout << "matrix output A is not found" << endl;
        return 1;
    }
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
            f1 >>setprecision(6) >>  A1[i * COLS + j];

        for(int j = 0; j < COLS; j++)
            f1 >>setprecision(6) >>  A1[ROWS * COLS + i * COLS + j];
    }

    f1.close();

    cout << "compare A" << endl;

    bool result = is_matrix_equal(A, A1, 0.1);
    if(result ==1)
        cout << "success" << endl;


    //测试V的正确性
    fstream f2("./data/Matrix_out_V256.txt", ios::in);
    if(!f2)
    {
        cout << "matrix output V is not found" << endl;
        return 1;
    }
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
            f2 >>setprecision(6) >>  V1[i * COLS + j];

        for(int j = 0; j < COLS; j++)
            f2 >>setprecision(6) >>  V1[ROWS * COLS + i * COLS + j];
    }

    f2.close();

    cout << "compare V" << endl;

    result = is_matrix_equal(V, V1, 0.1);
    if(result ==1)
        cout << "success" << endl;

    //测试矩阵S的正确性
    fstream f3("./data/Matrix_out_S256.txt", ios::in);
    if(!f3)
    {
        cout << "matrix output S is not found" << endl;
        return 1;
    }

    for(int i = 0; i < COLS; i++)
        f3 >>setprecision(6) >>  S1[i];

    f3.close();

    cout << "compare S" << endl;

    result = is_vector_equal(S, S1, 0.1);
    if(result ==1)
        cout << "success" << endl;

    //释放内存
    delete A;
    delete B;
    delete S;
    delete V;

    delete A1;
    delete S1;
    delete V1;

    return 0;
}
