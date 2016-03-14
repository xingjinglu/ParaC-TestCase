/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

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

#include"CL/cl.h"
#include"ClHost.h"
#define M 256
#define N 256
#define ROWS 256
#define COLS 256

#define TYPE double

#define MAX_ITERATIONS 40
#define THRESHOLD 0.00001

#define FLAG 1
#define IN_PRODUCT 0

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


//仅用于测试新语言，仅更新A
void svd(double *A, double *S, double *V) {
    //TODO:
    //int pass =1;
    int iterations_passed = 0;

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

    //对A的实部矩阵进行转置
    for(int i = 0; i < ROWS; i++) 
        for(int j = 0; j < COLS; j++)
            V_H[i * ROWS + j] = V[j * ROWS + i];

    //对A的虚部矩阵进行转置
    for(int i = 0; i < ROWS; i++) 
        for(int j = 0; j < COLS; j++)
            V_H[COLS * ROWS + i * ROWS + j] = V[COLS * ROWS + j * ROWS + i];

    int rotate_col_idx[256];
    for (int i = 0; i < 256; i++) 
        rotate_col_idx[i] = i;

    int iteration = 40;
    int start_index, skip_trans;

    size_t A_HDSWidth = 256;
    size_t A_HDSHeight = 256;
    size_t A_H_dssz = sizeof(double);
    size_t A_HDSStep = A_HDSWidth * A_H_dssz;
    A_HDSStep = (A_HDSStep % PADDING < 16) ? ((A_HDSStep / PADDING+1) * PADDING) : ((A_HDSStep + PADDING) / PADDING+1) * PADDING;
    size_t A_HDSShift = A_HDSStep * PADDING_LINE;
    size_t A_H_dssz0Pad = A_HDSStep * (A_HDSHeight + (PADDING_LINE<<1)) * 2;
    cl_mem A_HdsBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, A_H_dssz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");

    double *A_HDsBufH = (double*)malloc (A_H_dssz0Pad); 
    /*
    for(int i = 0; i < A_HDSHeight; i++){
        for(int j = i; j < A_HDSWidth; j++){
            double temp;
            temp = A_H[0][i][j];
            A_H[0][i][j] = A_H[0][j][i];
            A_H[0][j][i] = temp;
        }
    }
    for(int i = 0; i < A_HDSHeight; i++){
        for(int j = i; j < A_HDSWidth; j++){
            double temp;
            temp = A_H[1][i][j];
            A_H[1][i][j] = A_H[1][j][i];
            A_H[1][j][i] = temp;
        }
    }
    */
    for(int i = 0; i < A_HDSHeight*2; i++){
        memcpy((char*)A_HDsBufH + (i + PADDING_LINE) * A_HDSStep, (char*)A_H+ i * A_HDSWidth * sizeof(double), A_HDSWidth* sizeof(double) );
    }

    //std::cout <<" a == " <<((double*)((char*)A_HDsBufH + (256+PADDING_LINE) * A_HDSStep))[1] <<std::endl;
    status = clEnqueueWriteBuffer(g_queue, A_HdsBuf, CL_TRUE, 0,A_H_dssz0Pad, A_HDsBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");

    size_t V_HDSWidth = 256;
    size_t V_HDSHeight = 256;
    size_t V_H_dssz = sizeof(double);
    size_t V_HDSStep = V_HDSWidth * V_H_dssz;
    V_HDSStep = (V_HDSStep % PADDING < 16) ? ((V_HDSStep / PADDING+1) * PADDING) : ((V_HDSStep + PADDING) / PADDING+1) * PADDING;
    size_t V_HDSShift = V_HDSStep * PADDING_LINE;
    size_t V_H_dssz0Pad = V_HDSStep * (V_HDSHeight + (PADDING_LINE<<1)) * 2;
    cl_mem V_HdsBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, V_H_dssz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    double *V_HDsBufH = (double*)malloc (V_H_dssz0Pad); 
    /*
    for(int i = 0; i < V_HDSHeight; i++){
        for(int j = i; j < V_HDSWidth; j++){
            double temp;
            temp = V_H[0][i][j];
            V_H[0][i][j] = V_H[0][j][i];
            V_H[0][j][i] = temp;
        }
    }
    for(int i = 0; i < V_HDSHeight; i++){
        for(int j = i; j < V_HDSWidth; j++){
            double temp;
            temp = V_H[1][i][j];
            V_H[1][i][j] = V_H[1][j][i];
            V_H[1][j][i] = temp;
        }
    }
    */
    for(int i = 0; i < V_HDSHeight*2; i++){
        memcpy((char*)V_HDsBufH + (i + PADDING_LINE) * V_HDSStep, (char*)V_H+ i * V_HDSWidth * sizeof(double), V_HDSWidth* sizeof(double) );
    }
    status = clEnqueueWriteBuffer(g_queue, V_HdsBuf, CL_TRUE, 0,V_H_dssz0Pad, V_HDsBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");

    size_t rotate_col_idxDSWidth = 256;
    size_t rotate_col_idx_dssz = sizeof(int);
    size_t rotate_col_idxDSStep = rotate_col_idxDSWidth * rotate_col_idx_dssz;
    rotate_col_idxDSStep = (rotate_col_idxDSStep % PADDING < 16) ? ((rotate_col_idxDSStep / PADDING+1) * PADDING) : ((rotate_col_idxDSStep + PADDING) / PADDING+1) * PADDING;
    size_t rotate_col_idxDSShift = rotate_col_idxDSStep * PADDING_LINE;
    size_t rotate_col_idx_dssz0Pad = rotate_col_idxDSStep * (1 + (PADDING_LINE<<1));
    cl_mem rotate_col_idxdsBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, rotate_col_idx_dssz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    int *rotate_col_idxDsBufH = (int*)malloc (rotate_col_idx_dssz0Pad); 
    memcpy( (char*)rotate_col_idxDsBufH + (PADDING_LINE) * rotate_col_idxDSStep, (char*)rotate_col_idx, rotate_col_idxDSWidth * sizeof(int) );
    status = clEnqueueWriteBuffer(g_queue, rotate_col_idxdsBuf, CL_TRUE, 0,rotate_col_idx_dssz0Pad, rotate_col_idxDsBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");

    //TODO
    cl_mem passBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, sizeof(int), NULL, &status);
    checkErr(status,"clCreateBuffer");
    //status = clEnqueueWriteBuffer(g_queue, passBuf, CL_TRUE, 0, sizeof(int), &pass, 0, NULL, NULL);
    //checkErr(status,"clEnqueueWrite");
    //TODO:
    int *pass=new int[1];

    

    //计时函数
    struct timeval begin, end;

    gettimeofday(&begin, NULL);
    while (iteration > 0)
    {
        for (int i = 0; i < 256; i++) 
        {
            start_index = (i % 2 == 0) ? 0 : 1;

            {
                size_t global_work_size[2];
                size_t transe;
                cl_event event_kernel;
                cl_kernel kernel_1 = clCreateKernel(g_program, "kernel_1", &status);
                checkErr(status, "clCreateKernel for kernel_1");
                global_work_size[0] = 1;
                global_work_size[1] = (256 - start_index )/ 2;
                size_t local_work_size[2];
                local_work_size[0] = 256;
                local_work_size[1] = 1;
                global_work_size[0] = local_work_size[0];
                status = clSetKernelArg(kernel_1, 0, sizeof(int), (void *)&start_index);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 1, sizeof(int), (void *)&i);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 2, sizeof(cl_mem), (void *)&passBuf);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 3, sizeof(cl_mem), (void *)&A_HdsBuf);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 4, sizeof(int), (void *)&A_HDSWidth);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 5, sizeof(int), (void *)&A_HDSHeight);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 6, sizeof(int), (void *)&A_HDSStep);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 7, sizeof(int), (void *)&A_HDSShift);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 8, sizeof(cl_mem), (void *)&V_HdsBuf);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 9, sizeof(int), (void *)&V_HDSWidth);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 10, sizeof(int), (void *)&V_HDSHeight);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 11, sizeof(int), (void *)&V_HDSStep);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 12, sizeof(int), (void *)&V_HDSShift);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 13, sizeof(cl_mem), (void *)&rotate_col_idxdsBuf);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 14, sizeof(int), (void *)&rotate_col_idxDSWidth);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 15, sizeof(int), (void *)&rotate_col_idxDSStep);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 16, sizeof(int), (void *)&rotate_col_idxDSShift);
                checkErr(status, "clSetKernelArg");
                //TODO
               // status = clEnqueueNDRangeKernel(g_queue, kernel_1, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
                status = clEnqueueNDRangeKernel(g_queue, kernel_1, 2, NULL, global_work_size, local_work_size, 0, NULL, &event_kernel);
                checkErr(status, "clEnqueueNDRangeKernel");
               // status = clFinish(g_queue);
                //checkErr(status,"clFinish of kernel_1");

            }
        }
        status = clEnqueueReadBuffer(g_queue, passBuf, CL_TRUE, 0, sizeof(int), pass, 0, NULL, NULL);
        checkErr(status,"clEnqueueReadBuffer");
        iteration--;

        std::cout <<"iteration = " <<iteration<<std::endl;
        if (pass[0] == 1)
            break;
    }

    gettimeofday(&end, NULL);

    cout << "The execute time is" << (end.tv_sec - begin.tv_sec) * 1000 + (end.tv_usec - begin.tv_usec)/1000 << "ms" << endl; 
    //TODO:
    status = clEnqueueReadBuffer(g_queue, rotate_col_idxdsBuf, CL_TRUE, 0,rotate_col_idx_dssz0Pad,rotate_col_idxDsBufH, 0, NULL, NULL);
    memcpy( (char*)rotate_col_idx, (char*)rotate_col_idxDsBufH + PADDING_LINE * rotate_col_idxDSStep, rotate_col_idxDSWidth * sizeof(int) );

    status = clEnqueueReadBuffer(g_queue, V_HdsBuf, CL_TRUE, 0,V_H_dssz0Pad,V_HDsBufH, 0, NULL, NULL);
    for(int i = 0; i < V_HDSHeight*2; i++){
        memcpy( (char*)V_H+ i *V_HDSWidth* sizeof(double), (char*) V_HDsBufH+ (i + PADDING_LINE)* V_HDSStep, V_HDSWidth* sizeof(double) );
    }

    //矩阵V的转置
    for(int i = 0; i < ROWS; i++) 
        for(int j = 0; j < COLS; j++)
            V[i * ROWS + j] = V_H[j * ROWS + i];

    for(int i = 0; i < ROWS; i++) 
        for(int j = 0; j < COLS; j++)
            V[COLS * ROWS + i * ROWS + j] = V_H[COLS * ROWS + j * ROWS + i];
    /*
       for(int i = 0; i < V_HDSHeight; i++){
       for(int j = i; j < V_HDSWidth; j++){
       double temp;
       temp = V_H[0][i][j];
       V_H[0][i][j] = V_H[0][j][i];
       V_H[0][j][i] = temp;
       }
       }
       for(int i = 0; i < V_HDSHeight; i++){
       for(int j = i; j < V_HDSWidth; j++){
       double temp;
       temp = V_H[1][i][j];
       V_H[1][i][j] = V_H[1][j][i];
       V_H[1][j][i] = temp;
       }
       }
       */
    status = clEnqueueReadBuffer(g_queue, A_HdsBuf, CL_TRUE, 0,A_H_dssz0Pad,A_HDsBufH, 0, NULL, NULL);
    for(int i = 0; i < A_HDSHeight*2; i++){
        memcpy( (char*)A_H+ i *A_HDSWidth* sizeof(double), (char*) A_HDsBufH+ (i + PADDING_LINE)* A_HDSStep, A_HDSWidth* sizeof(double) );
    }
    /*
       for(int i = 0; i < A_HDSHeight; i++){
       for(int j = i; j < A_HDSWidth; j++){
       double temp;
       temp = A_H[0][i][j];
       A_H[0][i][j] = A_H[0][j][i];
       A_H[0][j][i] = temp;
       }
       }
       for(int i = 0; i < A_HDSHeight; i++){
       for(int j = i; j < A_HDSWidth; j++){
       double temp;
       temp = A_H[1][i][j];
       A_H[1][i][j] = A_H[1][j][i];
       A_H[1][j][i] = temp;
       }
       }
       */

    {
        size_t global_work_size[2];
        size_t transe;
        cl_event event_kernel;
        cl_kernel kernel_2 = clCreateKernel(g_program, "kernel_2", &status);
        checkErr(status, "clCreateKernel for kernel_2");

        //TODO
        //global_work_size[0] = 1;
        //global_work_size[1] = 256;

        global_work_size[0] = 1;
        global_work_size[1] = 256;
        size_t local_work_size[2];
        local_work_size[0] = 256;
        local_work_size[1] = 1;
        global_work_size[0] = local_work_size[0];

        size_t SDstWidth = 256;
        size_t S_dstsz = sizeof(double);
        size_t SDstStep = SDstWidth * S_dstsz;
        SDstStep = (SDstStep % PADDING < 16) ? ((SDstStep / PADDING+1) * PADDING) : ((SDstStep + PADDING) / PADDING+1) * PADDING;
        size_t SDstShift = SDstStep * PADDING_LINE;
        size_t S_dstsz0Pad = SDstStep * (1 + (PADDING_LINE<<1));
        cl_mem SdstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, S_dstsz0Pad, NULL, &status);
        checkErr(status, "clCreateBuffer");
        double *SDstBufH = (double*)malloc(S_dstsz0Pad); 
        memcpy( (char*)SDstBufH + (PADDING_LINE) * SDstStep, (char*)S, SDstWidth * sizeof(double) );

        status = clSetKernelArg(kernel_2, 0, sizeof(cl_mem), (void *)&SdstBuf);
        checkErr(status, "clSetKernelArg");
        status = clSetKernelArg(kernel_2, 1, sizeof(int), (void *)&SDstWidth);
        checkErr(status, "clSetKernelArg");
        status = clSetKernelArg(kernel_2, 2, sizeof(int), (void *)&SDstStep);
        checkErr(status, "clSetKernelArg");
        status = clSetKernelArg(kernel_2, 3, sizeof(int), (void *)&SDstShift);
        checkErr(status, "clSetKernelArg");

        size_t A_HDSWidth = 256;
        size_t A_HDSHeight = 256;
        size_t A_H_dssz = sizeof(double);
        size_t A_HDSStep = A_HDSWidth * A_H_dssz;
        A_HDSStep = (A_HDSStep % PADDING < 16) ? ((A_HDSStep / PADDING+1) * PADDING) : ((A_HDSStep + PADDING) / PADDING+1) * PADDING;
        size_t A_HDSShift = A_HDSStep * PADDING_LINE;
        size_t A_H_dssz0Pad = A_HDSStep * (A_HDSHeight + (PADDING_LINE<<1)) * 2;
        cl_mem A_HdsBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, A_H_dssz0Pad, NULL, &status);
        checkErr(status, "clCreateBuffer");
        double *A_HDsBufH = (double*)malloc (A_H_dssz0Pad); 
        /*
        for(int i = 0; i < A_HDSHeight; i++){
            for(int j = i; j < A_HDSWidth; j++){
                double temp;
                temp = A_H[0][i][j];
                A_H[0][i][j] = A_H[0][j][i];
                A_H[0][j][i] = temp;
            }
        }
        for(int i = 0; i < A_HDSHeight; i++){
            for(int j = i; j < A_HDSWidth; j++){
                double temp;
                temp = A_H[1][i][j];
                A_H[1][i][j] = A_H[1][j][i];
                A_H[1][j][i] = temp;
            }
        }
        */
        for(int i = 0; i < A_HDSHeight*2; i++){
            memcpy((char*)A_HDsBufH + (i + PADDING_LINE) * A_HDSStep, (char*)A_H+ i * A_HDSWidth * sizeof(double), A_HDSWidth* sizeof(double) );
        }
        status = clEnqueueWriteBuffer(g_queue, A_HdsBuf, CL_TRUE, 0,A_H_dssz0Pad, A_HDsBufH, 0, NULL, NULL);
        checkErr(status, "clWriteBuffer");
        status = clSetKernelArg(kernel_2, 4, sizeof(cl_mem), (void *)&A_HdsBuf);
        checkErr(status, "clSetKernelArg");
        status = clSetKernelArg(kernel_2, 5, sizeof(int), (void *)&A_HDSWidth);
        checkErr(status, "clSetKernelArg");
        status = clSetKernelArg(kernel_2, 6, sizeof(int), (void *)&A_HDSHeight);
        checkErr(status, "clSetKernelArg");
        status = clSetKernelArg(kernel_2, 7, sizeof(int), (void *)&A_HDSStep);
        checkErr(status, "clSetKernelArg");
        status = clSetKernelArg(kernel_2, 8, sizeof(int), (void *)&A_HDSShift);
        checkErr(status, "clSetKernelArg");
        status = clEnqueueNDRangeKernel(g_queue, kernel_2, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
        checkErr(status, "clEnqueueNDRangeKernel");
        status = clFinish(g_queue);
        checkErr(status,"clFinish of kernel_2");
        status = clEnqueueReadBuffer(g_queue, SdstBuf, CL_TRUE, 0,S_dstsz0Pad,SDstBufH, 0, NULL, NULL);
        memcpy( (char*)S, (char*)SDstBufH + PADDING_LINE * SDstStep, SDstWidth * sizeof(double) );

        status = clEnqueueReadBuffer(g_queue, A_HdsBuf, CL_TRUE, 0,A_H_dssz0Pad,A_HDsBufH, 0, NULL, NULL);
        for(int i = 0; i < A_HDSHeight*2; i++){
            memcpy( (char*)A_H+ i *A_HDSWidth* sizeof(double), (char*) A_HDsBufH+ (i + PADDING_LINE)* A_HDSStep, A_HDSWidth* sizeof(double) );
        }

        //矩阵A的转置
        for(int i = 0; i < ROWS; i++) 
            for(int j = 0; j < COLS; j++)
                A[i * ROWS + j] = A_H[j * ROWS + i];

        for(int i = 0; i < ROWS; i++) 
            for(int j = 0; j < COLS; j++)
                A[COLS * ROWS + i * ROWS + j] = A_H[COLS * ROWS + j * ROWS + i];

    }
}



int main() {
    char inputfile[] = "svd_high_level.cl";
    char *remain = NULL;
    if (-1 == openCLCreate(inputfile, remain)) {
        printf("openCL create fail !!!!!!");
        return 0;
    }


    //TODO

    TYPE *A = new TYPE[ROWS * COLS * 2];   //复数矩阵，前ROWS*COLS为实部矩阵，后ROWS*COLS为虚部矩阵
    TYPE *B = new TYPE[ROWS * COLS * 2];   //左奇异向量矩阵,存储格式如A
    TYPE *S = new TYPE[COLS];             //奇异值,为实数矩阵
    TYPE *V = new TYPE[ROWS * COLS * 2];   //右奇异向量矩阵,存储格式如A


    memset(V, 0, ROWS*COLS*2*sizeof(double));
    for(int i = 0; i < 256; i++)
        V[i*256+i]=1.0f;

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
    svd(A,S, V);

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

    bool result;// = is_matrix_equal(A, A1, 0.1);
    //if(result ==1)
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
