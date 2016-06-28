/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

#include "ClHost.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include<sys/time.h>
#include<time.h>
#include<math.h>
#define Niter 10
struct timeval start_cpu[10];
struct timeval end_cpu[10];

int host_main(int argc, char *argv[]) {
  int n = 8192;
  n = argc > 1 ? atoi(argv[1]) : n;
  int N = n * n;
  float *A, *B;
  A = (float *)malloc(N * sizeof(float));
  B = (float *)malloc(N * sizeof(float));
  int i = 0, j = 0;
  double t_calc_start = 0, t_calc_end = 0, t_ave, t_total_start = 0, t_total_end = 0;
  int check = 1;
  for (i = 0; i < n; i++) 
    for (j = 0; j < n; j++) {
      A[i * n + j] = i * n + j;
    }
  printf("----MT(%d*%d)----\n", n, n);
  for (int k = 0; k < 10; k++) {
    gettimeofday(&start_cpu[k], __null);
        //create buffers on GPU according to data pragma
    int A0Size = sizeof(float) * n * n;
    cl_mem A0Buffer = clCreateBuffer(context, CL_MEM_READ_ONLY, A0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for A");
    int B0Size = sizeof(float) * n * n;
    cl_mem B0Buffer = clCreateBuffer(context, CL_MEM_WRITE_ONLY, B0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for B");

    //copyin buffers to GPU according to data pragma
    status = clEnqueueWriteBuffer(queue, A0Buffer, CL_TRUE, 0, A0Size, A, 0, NULL, NULL);
    checkErr(status, "clEnqueueWriteBuffer for A");

    #pragma cap data copyin(A[0:n * n]) copyout(B[0:n * n]) 
      {
                //create the kernel
        cl_kernel kernel_1 = clCreateKernel(program, "kernel_1", &status);
        checkErr(status, "clCreateKernel for kernel_1");

        //set thread/thread-block size
        size_t localWorkSize1[3]= {1, 1, 1};
        size_t blockWorkSize1[3]= {1, 1, 1};
        size_t globalWorkSize1[3]= {1, 1, 1};
        localWorkSize1[1] = 8;
        blockWorkSize1[1] = upMultiple( n, 8 );
        localWorkSize1[0] = 32;
        blockWorkSize1[0] = upMultiple( n, 32 );
        globalWorkSize1[0] = blockWorkSize1[0] * localWorkSize1[0];
        globalWorkSize1[1] = blockWorkSize1[1] * localWorkSize1[1];
        //set kernel parameters
        status = clSetKernelArg(kernel_1, 0, sizeof(cl_mem), (void *)&B0Buffer);
        checkErr(status, "clSetKernelArg for 0");
        status = clSetKernelArg(kernel_1, 1, sizeof(int), (void *)&n);
        checkErr(status, "clSetKernelArg for 1");
        status = clSetKernelArg(kernel_1, 2, sizeof(cl_mem), (void *)&A0Buffer);
        checkErr(status, "clSetKernelArg for 2");

        //launch a kernel
        status = clEnqueueNDRangeKernel(queue, kernel_1, 2, NULL, globalWorkSize1, localWorkSize1, 0, NULL, NULL);
        checkErr(status, "clEnqueueNDRangeKernel for kernel_1");

        //wait until kernel finish
        status = clFinish(queue);
        checkErr(status, "clFinish for kernel_1");

        //release kernel
        clReleaseKernel(kernel_1);
      }
    //copyout buffers to CPU acccording to data pragma
    status = clEnqueueReadBuffer(queue, B0Buffer, CL_TRUE, 0, B0Size, B, 0, NULL, NULL);
    checkErr(status, "clEnqueueReadBuffer for B");

    //release buffers
    clReleaseMemObject(A0Buffer);
    clReleaseMemObject(B0Buffer);

    gettimeofday(&end_cpu[k], __null);
    printf("%lf\n", B[10]);
  }
  for (int i = 0; i < 10; i++) {
    double duration_cpu = 1000 * ((end_cpu[i]).tv_sec - (start_cpu[i]).tv_sec) + ((end_cpu[i]).tv_usec - (start_cpu[i]).tv_usec) / 1000.;
    printf("MT exe time OPENACC:\t%f ms\n", duration_cpu);
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (B[i * n + j] != A[j * n + i]) {
        check &= 0;
        break;
      }
    }
  }
  if (check)
    printf("OK\n\n");
  else
    printf("Error\n\n");
  free(A);
  free(B);
  return 0;
}

int main(int argc, char *argv[]) {
  // Create environment variables before the first data transfer.
  const char *inputFile = "mt-cap.cl";

  if (-1 == openCLCreate(&context, &queue, &program, inputFile)) {
    printf("OpenCL create fail!\n");
    exit(-1);
  }

  int ret =  host_main(argc, argv);
  
  // Release environment vars.
  clReleaseProgram(program);
  clReleaseCommandQueue(queue);
  clReleaseContext(context);

  return ret;
}



