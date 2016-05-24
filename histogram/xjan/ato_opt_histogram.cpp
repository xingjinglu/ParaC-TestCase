/******************
 * 本程序对比优化前和优化后的性能
 */
#include <iostream>
#include <fstream>
#include <string.h>   
#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif

#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


#define kERNEL(...)#__VA_ARGS__
#define R 100
#define AHEAD_OF_TEST_EXE_NUM 30
#define IMAGE_LENGTH 8192*8192
#define LOCAL_LENGTH 256
#define PROCESS_NUM_PER_THREAD 256 
#define WORKGROUP_NUM (div_up(IMAGE_LENGTH, LOCAL_LENGTH*PROCESS_NUM_PER_THREAD))
#define BANK_NUM (32)
char * getCodeFromFile(const char * fileName,size_t * len)
{
    std::ifstream in(fileName,std::ios_base::binary);
    if(!in.good()) 
        return NULL;
    in.seekg(0,std::ios_base::end);
    * len = in.tellg();
    char * code = (char *)malloc(*len +1);
    in.seekg(0,std::ios_base::beg);
    in.read(code,*len);
    code[*len] = 0;
    return code;
}
int div_up(size_t value, size_t granu)
{
    return (value + granu -1) / granu;
}
long long int getTime(struct timeval f,struct timeval e)
{
    return (e.tv_sec - f.tv_sec)*1000000 + (e.tv_usec - f.tv_usec);
}
int main(int argc, char * argv[])
{
    printf("**************Histogram*******************\n");

    cl_int status = 0;
    size_t deviceListSize;

    int * img = (int *)malloc(sizeof(int)*IMAGE_LENGTH);
    int * dis_res =(int *)malloc(sizeof(int)*WORKGROUP_NUM*256);

    srand((unsigned)time(NULL));
    for(int i=0;i<IMAGE_LENGTH;i++)
        img[i]=rand();

    struct timeval time1,time2;
    long long int gpu_build_time, gpu_exe_time, gpu_read_time;
    long long int exe_time, statistics_time, reduce_time;

    gettimeofday(&time1,NULL);
    /*
     *得到可用平台,并且选出AMD平台或其他可用平台
     */
    cl_uint numPlatforms;
    cl_platform_id platform = NULL;
    status = clGetPlatformIDs(0,NULL,&numPlatforms);
    if(status != CL_SUCCESS)
    {
        printf("Error: Getting Platfroms.\
                (clGetPlatfroms)\n");
        return EXIT_FAILURE;
    }

    if(numPlatforms > 0)
    {
        cl_platform_id * platforms = 
            (cl_platform_id * )malloc(numPlatforms * sizeof(cl_platform_id));
        status = clGetPlatformIDs(numPlatforms,platforms,NULL);
        if(status!=CL_SUCCESS)
        {
            printf("Error: Getting Platfrom Ids.\
                    (clGetPlatformIDs)\n");
            return -1;
        }
        for(unsigned int i=0;i < numPlatforms; ++i)
        {
            char pbuff[100];
            status = clGetPlatformInfo(
                    platforms[i],
                    CL_PLATFORM_VENDOR,
                    sizeof(pbuff),
                    pbuff,
                    NULL);
            platform = platforms[i];
            if(!strcmp(pbuff,"Advanced Micro Devices, Inc."))
                //******test the string********
            {
                break;
            }
        }
        free(platforms);
    }
    /*
     *如果我们能找到相应平台，就能使用它，否则返回NULL。
     *
     */
    cl_context_properties cps[3] = {
        CL_CONTEXT_PLATFORM,
        (cl_context_properties) platform, 0};
    cl_context_properties * cprops = 
        (NULL == platform) ? NULL :cps;
    /////////////////////////////////////////////////////
    //  生成上下文	
    /////////////////////////////////////////////////////
    cl_context context = clCreateContextFromType(
            cprops,
            CL_DEVICE_TYPE_GPU,
            NULL,
            NULL,
            &status);
    if(status != CL_SUCCESS)
    {
        //std::cout << "status = " << status << std::endl;
        printf("Error: Creating Context.\
                (clCreateContextFromType)\n");
        return EXIT_FAILURE;
    }

    /////////////////////////////////////////////////////
    // 寻找OpenCL设备
    /////////////////////////////////////////////////////	
    /*首先得到设备列表长度*/
    status = clGetContextInfo(context,
            CL_CONTEXT_DEVICES,
            0,
            NULL,
            &deviceListSize);
    if (status != CL_SUCCESS)
    {
        printf("Error: Getting Context Info\
                (device list size ,clGetContextInfo)\n");
        return EXIT_FAILURE;
    }
    cl_device_id * devices = (cl_device_id *)malloc(deviceListSize);

    if(devices == 0)
    {
        printf("Error: No devices found.\n");
        return EXIT_FAILURE;
    }
    /*现在得到设备列表*/
    status = clGetContextInfo(
            context,
            CL_CONTEXT_DEVICES,
            deviceListSize,
            devices,
            NULL);
    if ( status != CL_SUCCESS)
    {
        printf("Error: Getting Context Info\
                (device list,clGetContextInfo)\n");
        return EXIT_FAILURE;
    }
    ////////////////////////////////////////////////////
    // 装载内核程序，编译CL program，生成CL内核实例
    ////////////////////////////////////////////////////
    size_t sourceSize[1];
    char *  kernelSourceCode = getCodeFromFile("ato_opt_histogram.cl",sourceSize);
    cl_program program = clCreateProgramWithSource(
            context,
            1,
            (const char **)&kernelSourceCode,
            sourceSize,
            &status);
    if(status != CL_SUCCESS)
    {
        printf("Error:Loading Binary into cl_program\
                (clCreateProgramWithBinary)\n");
        return EXIT_FAILURE;
    }
    free(kernelSourceCode);

    /* 为所有指定的设备生成CL program。*/
    status = clBuildProgram(program,1,devices,NULL,NULL,NULL);
    if(status != CL_SUCCESS)
    {
        size_t len;
        char buf[2048];

        printf("Error: Building Program \
                (clBuildProgram)\n");
        clGetProgramBuildInfo(program,*devices,CL_PROGRAM_BUILD_LOG,sizeof(buf),buf,&len);
        printf("%s\n",buf);

        return EXIT_FAILURE;
    }
    gettimeofday(&time2,NULL);
    printf("GPU Build program:%lldus\n\n",getTime(time1,time2));
    ////////////////////////////////////////////////////
    // 创建一个OpenCL command queue
    ////////////////////////////////////////////////////
    cl_command_queue commandQueue = 
        clCreateCommandQueue(context,
                devices[0],
                CL_QUEUE_PROFILING_ENABLE,
                &status);
    if(status != CL_SUCCESS)
    {
        printf("Create Command Queue.\
                (clCreateCommandQueue)\n");
        return EXIT_FAILURE;
    }

    ////////////////////////////////////////////////////
    // 创建 OpenCL buffer 对象
    ////////////////////////////////////////////////////
    cl_mem image = clCreateBuffer(
            context,
            CL_MEM_READ_ONLY,
            IMAGE_LENGTH*sizeof(int),
            NULL,
            &status);
    if(status != CL_SUCCESS)
    {
        printf("Error: clCreateBuffer\
                (image buffer\n");
        return EXIT_FAILURE;
    }

    cl_mem dispersed_result = clCreateBuffer(
            context,
            CL_MEM_WRITE_ONLY,
            WORKGROUP_NUM*256*sizeof(int),
            NULL,
            &status);
    if(status != CL_SUCCESS)
    {
        printf("Error: clCreateBuffer\
                (goal buffer\n");
        return EXIT_FAILURE;
    }

    status = clEnqueueWriteBuffer(commandQueue,image,CL_FALSE,0,IMAGE_LENGTH*sizeof(int),img,0,NULL,NULL);
    if(status != CL_SUCCESS)
    {
        printf("Error: writeBuffer\
                (former buffer\n");
        return EXIT_FAILURE;
    }
    gettimeofday(&time2,NULL);
    gpu_build_time = getTime(time1,time2); 

    size_t globalThreads[3],localThreads[3];
    localThreads[0]= LOCAL_LENGTH;
    localThreads[1]= 1;
    localThreads[2]= 1;
    globalThreads[1]= 1;
    globalThreads[2]= 1;

    int k=256*256;
    for(int i=0;i<5 && k<IMAGE_LENGTH;i++, k=k*2)
    { 
        printf("-------------------IMG LEN %d--------------------\n", k);
        int temp_workgroup_num = div_up(k, localThreads[0]*PROCESS_NUM_PER_THREAD);

        globalThreads[0]= temp_workgroup_num * localThreads[0];
        cl_kernel statistics_kernel,reduce_kernel,ato_kernel;
        char statistics_kernelName[50],reduce_kernelName[50],ato_kernelName[50],no_atomi_statisticName[50];

        statistics_kernel = clCreateKernel(program,"statistics",&status);
        reduce_kernel = clCreateKernel(program,"reduce_ALL",&status);
        ato_kernel = clCreateKernel(program,"ato_statistics",&status);
        if(status != CL_SUCCESS)
        {
            printf("Error: Creating Kernel from program.\
                    (clCreateKernel) %s\n",statistics_kernelName);
            return EXIT_FAILURE;
        }

        strcpy(statistics_kernelName,"statistics"); 
        strcpy(reduce_kernelName,"reduce_ALL");  
        strcpy(ato_kernelName,"ato_statistics"); 

        status = clSetKernelArg(statistics_kernel,0,sizeof(cl_mem),(void *)&image);
        status = clSetKernelArg(statistics_kernel,1,256*(BANK_NUM)*sizeof(cl_int),NULL);
        status = clSetKernelArg(statistics_kernel,2,sizeof(cl_mem),(void *)&dispersed_result);
        status = clSetKernelArg(statistics_kernel,3,sizeof(cl_int),(void *)&k);

        int stride = LOCAL_LENGTH;
        if(LOCAL_LENGTH > temp_workgroup_num)
        {
            if(temp_workgroup_num & (temp_workgroup_num - 1) == 0)
                stride = temp_workgroup_num >> 1;
            else{
                stride = 1;
                while(stride < temp_workgroup_num)
                    stride <<= 1;
                stride >> 1;
            }
        } 

        status = clSetKernelArg(reduce_kernel,0,sizeof(cl_mem),(void *)&dispersed_result);
        status = clSetKernelArg(reduce_kernel,1,256*sizeof(cl_int),NULL);
        status = clSetKernelArg(reduce_kernel,2,sizeof(cl_int),(void *)&temp_workgroup_num);
        status = clSetKernelArg(reduce_kernel,3,sizeof(cl_int),(void *)&stride);

        status = clSetKernelArg(ato_kernel,0,sizeof(cl_mem),(void *)&image);
        status = clSetKernelArg(ato_kernel,1,sizeof(cl_mem),(void *)&dispersed_result);
        status = clSetKernelArg(ato_kernel,2,sizeof(cl_int),(void *)&k);
        if(status != CL_SUCCESS)
        {
            printf("Error: Setting kernel argument.\
                    (all)\n");
            return EXIT_FAILURE;
        }
        /*
         * 将一个kernel放入command queue.
         */
        cl_event staticEvent, reduceEvent;
        cl_ulong startTime,endTime;
        long long int sum_time=0,sum_time_1=0,sum_time_2=0;

        long long int sum =0 ;

        printf("CPU begin to compute\n");
        gettimeofday(&time1,NULL);
        int * cpu_dis_res =(int *)malloc(sizeof(int)*256);
        memset(cpu_dis_res,0,sizeof(int)*256);
        for(int i=0;i<k;i++)
        {
            int temp = img[i];
            cpu_dis_res[temp & 255] ++;
            temp = temp >> 8;
            cpu_dis_res[temp & 255] ++;
            temp = temp >> 8;
            cpu_dis_res[temp & 255] ++;
            temp = temp >> 8;
            cpu_dis_res[temp & 255] ++;

        }
        gettimeofday(&time2,NULL);
        printf("CPU exe time:%lldus\n",getTime(time1,time2));

        for(int j=0;j<R+30;j++) 
        {
            memset(dis_res,0,256*sizeof(int));
            gettimeofday(&time1,NULL);
            status = clEnqueueWriteBuffer(commandQueue,dispersed_result,CL_FALSE,0,256*sizeof(int),dis_res,0,NULL,NULL);
            if(status != CL_SUCCESS)
            {
                printf("Error: writeBuffer\
                        (former buffer\n");
                return EXIT_FAILURE;
            }
            status = clEnqueueNDRangeKernel(
                    commandQueue,
                    ato_kernel,
                    3,
                    NULL,
                    globalThreads,
                    localThreads,
                    0,
                    NULL,
                    NULL);
            if(status != CL_SUCCESS)
            {
                printf("Error: Enqueueing kernel\n");
                printf("%d\n",status);
                return EXIT_FAILURE;
            }

            status = clFinish(commandQueue);
            if(status != CL_SUCCESS)
            {
                printf("Error: Finish command queue\n");
                return EXIT_FAILURE; 
            }
            gettimeofday(&time2,NULL);
            if(j>=30)
                sum+=getTime(time1,time2);
        }
        gpu_exe_time = sum/R;

        gettimeofday(&time1,NULL);
        status = clEnqueueReadBuffer(
                commandQueue,
                dispersed_result,
                CL_TRUE,
                0,
                256*sizeof(int),
                dis_res,
                0,NULL,NULL);
        if(status != CL_SUCCESS)
        {
            printf("Error: read buffer %d\n",status);
            return EXIT_FAILURE; 
        }
        gettimeofday(&time2,NULL);
        gpu_read_time = getTime(time1,time2);

        int i;
        for(i=0;i<256;i++)
            if(dis_res[i] != cpu_dis_res[i])
            {
                printf("Wrong! %d GPU:%d CPU:%d\n",i,dis_res[i],cpu_dis_res[i]);
                break; 
            }

        if(i==256)
            printf("ATO Bingo~\n");
        printf("ATO exe time:%lldus\n", gpu_exe_time);

        for(int i=0;i<R+30;i++)
        {
            memset(dis_res,0,256*temp_workgroup_num*sizeof(int));
            globalThreads[0]= temp_workgroup_num * localThreads[0]; 
            gettimeofday(&time1,NULL);
            status = clEnqueueWriteBuffer(commandQueue,dispersed_result,CL_FALSE,0,256*temp_workgroup_num*sizeof(int),dis_res,0,NULL,NULL);
            if(status != CL_SUCCESS)
            {
                printf("Error: writeBuffer\
                        (former buffer\n");
                return EXIT_FAILURE;
            }
            status = clEnqueueNDRangeKernel( commandQueue,
                    statistics_kernel,
                    3,
                    NULL,
                    globalThreads,
                    localThreads,
                    0,
                    NULL,
                    &staticEvent);
            if(status != CL_SUCCESS)
            {
                printf("Error: Enqueueing kernel\n");
                printf("%d\n",status);
                return EXIT_FAILURE;
            }

            status = clFinish(commandQueue);
            if(status != CL_SUCCESS)
            {
                printf("Error: Finish command queue\n");
                return EXIT_FAILURE; 
            }

            globalThreads[0]= 256*256; 
            status = clEnqueueNDRangeKernel(
                    commandQueue,
                    reduce_kernel,
                    3,
                    NULL,
                    globalThreads,
                    localThreads,
                    0,
                    NULL,
                    &reduceEvent);
            if(status != CL_SUCCESS)
            {
                printf("Error: Enqueueing kernel\n");
                printf("%d\n",status);
                return EXIT_FAILURE;
            }

            status = clFinish(commandQueue);
            if(status != CL_SUCCESS)
            {
                printf("Error: Finish command queue\n");
                return EXIT_FAILURE; 
            }
            gettimeofday(&time2,NULL);

            if(i>=30)
            {
                clGetEventProfilingInfo(staticEvent,CL_PROFILING_COMMAND_START,sizeof(cl_ulong),&startTime,NULL);
                clGetEventProfilingInfo(staticEvent,CL_PROFILING_COMMAND_END,sizeof(cl_ulong),&endTime,NULL);
                sum_time_1 += endTime - startTime;
            }

            if(i>=30)
            {
                clGetEventProfilingInfo(reduceEvent,CL_PROFILING_COMMAND_START,sizeof(cl_ulong),&startTime,NULL);
                clGetEventProfilingInfo(reduceEvent,CL_PROFILING_COMMAND_END,sizeof(cl_ulong),&endTime,NULL);
                sum_time_2 += endTime - startTime;
            }
            if(i>=30)
                sum_time += getTime(time1,time2);
        }
        statistics_time = sum_time_1/R/1000; 
        reduce_time = sum_time_2/R/1000; 
        exe_time = sum_time/R;

        gettimeofday(&time1,NULL);
        status = clEnqueueReadBuffer(
                commandQueue,
                dispersed_result,
                CL_TRUE,
                0,
                256*sizeof(int),
                dis_res,
                0,NULL,NULL);
        if(status != CL_SUCCESS)
        {
            printf("Error: read buffer %d\n",status);
            return EXIT_FAILURE; 
        }
        gettimeofday(&time2,NULL);
        gpu_read_time = getTime(time1,time2);

        for(i=0;i<256;i++)
            if(dis_res[i] != cpu_dis_res[i])
            {
                printf("Wrong! %d GPU:%d CPU:%d\n",i,dis_res[i],cpu_dis_res[i]);
                break; 
            }
        if(i==256)
            printf("OPT Bingo~\n");

        printf("OPT exe time:%lldus \t", exe_time);
        printf("statistic:%lldus \treduce:%lldus\n",statistics_time,reduce_time);
        float statistics_bandwidth = 1e9*(k + 256*temp_workgroup_num)*sizeof(int)/1024/1024/1024/statistics_time/1000;
        float reduce_bandwidth = 1e9*(256*temp_workgroup_num+ 256)*sizeof(int)/1024/1024/1024/reduce_time/1000;
        printf("statistic's bandwidth: %10.2f GB/s \treduce's bandwidth:  %10.2f GB/s \n",statistics_bandwidth,reduce_bandwidth);

        printf("-------------------IMG LEN --------------------\n\n");
    }

    status = clReleaseProgram(program);
    status = clReleaseMemObject(image);
    status = clReleaseMemObject(dispersed_result);
    status = clReleaseCommandQueue(commandQueue);
    status = clReleaseContext(context);

    free(devices);
    free(img);
    free(dis_res);
    printf("**************Histogram*******************\n");

    return 0;
}
