/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

#include "ClHost.h"
//sharpness.cpp
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<sys/time.h>

#define MIN2(a,b)  ((a)<(b) ? (a):(b))
#define MAX2(a,b)  ((a)>(b) ? (a):(b))
#define MAX3(a,b,c)   (MAX2((a),MAX2((b),(c))))
#define MIN3(a,b,c)   (MIN2((a),MIN2((b),(c))))

struct timeval start_cpu[10];
struct timeval end_cpu[10];

void usage() {
  printf("usage:sharpness width height\n");
}



int host_main(int argc, char *argv[]) {
  int width = 0, height = 0;
  if (3 != argc) {
    usage();
    return -1;
  }
  width = atoi(argv[1]);
  height = atoi(argv[2]);
  int quarterWidth = width / 4;
  int quarterHeight = height / 4;
  unsigned char *yuvfile = (unsigned char *)malloc(sizeof(unsigned char) * width * height);
  memset(yuvfile, 0, width * height * sizeof(char));
  srand(0);
  for (int i = 0; i < height * width; i++) {
    yuvfile[i] = rand() % 100 + 1;
  }
  unsigned char *yPlane = (unsigned char *)malloc(sizeof(unsigned char) * height * width);
  unsigned char *yPlane_cpu = (unsigned char *)malloc(sizeof(unsigned char) * height * width);
  unsigned char *yPlaneCSER = (unsigned char *)malloc(sizeof(unsigned char) * height * width);
  unsigned char *yPlaneDown = (unsigned char *)malloc(sizeof(unsigned char) * quarterHeight * quarterWidth);
  short *pError = (short *)malloc(sizeof(short) * height * width);
  short *pEdge = (short *)malloc(sizeof(short) * height * width);
  short *pSharpness = (short *)malloc(sizeof(short) * height * width);
  long sum = 0;
  short mean = 0;
  double oldpeak = 2.F;
  double oldcutoffCoef = 1.F;
  double oldcutoff2 = 256.F;
  double oldcutoff3Coef = 1.F;
  for (int ii = 0; ii < 10; ii++) {
    for (int i = 0; i < height * width; i++) {
      yPlane[i] = yuvfile[i];
    }
    gettimeofday(&start_cpu[0], __null);
        //create buffers on GPU according to data pragma
    int yPlane0Size = sizeof(unsigned char) * width * height;
    cl_mem yPlane0Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, yPlane0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for yPlane");
    int yPlaneCSER0Size = sizeof(unsigned char) * width * height;
    cl_mem yPlaneCSER0Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, yPlaneCSER0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for yPlaneCSER");
    int yPlaneDown0Size = sizeof(unsigned char) * quarterHeight * quarterWidth;
    cl_mem yPlaneDown0Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, yPlaneDown0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for yPlaneDown");
    int pError0Size = sizeof(short) * width * height;
    cl_mem pError0Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, pError0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for pError");
    int pEdge0Size = sizeof(short) * width * height;
    cl_mem pEdge0Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, pEdge0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for pEdge");
    int pSharpness0Size = sizeof(short) * width * height;
    cl_mem pSharpness0Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, pSharpness0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for pSharpness");

    //copyin buffers to GPU according to data pragma
    status = clEnqueueWriteBuffer(queue, yPlane0Buffer, CL_TRUE, 0, yPlane0Size, yPlane, 0, NULL, NULL);
    checkErr(status, "clEnqueueWriteBuffer for yPlane");

    #pragma cap data copy(yPlane[0:width * height]) create(yPlaneCSER[0:width * height], yPlaneDown[0:quarterHeight * quarterWidth], pError[0:width * height], pEdge[0:width * height], pSharpness[0:width * height]) 
      {
        gettimeofday(&start_cpu[1], __null);
                //create the kernel
        cl_kernel kernel_1 = clCreateKernel(program, "kernel_1", &status);
        checkErr(status, "clCreateKernel for kernel_1");

        //set thread/thread-block size
        size_t localWorkSize1[3]= {1, 1, 1};
        size_t blockWorkSize1[3]= {1, 1, 1};
        size_t globalWorkSize1[3]= {1, 1, 1};
        localWorkSize1[1] = 8;
        blockWorkSize1[1] = upMultiple( (height + 4 - 1) / (4), 8 );
        localWorkSize1[0] = 32;
        blockWorkSize1[0] = upMultiple( (width + 4 - 1) / (4), 32 );
        globalWorkSize1[0] = blockWorkSize1[0] * localWorkSize1[0];
        globalWorkSize1[1] = blockWorkSize1[1] * localWorkSize1[1];
        //set kernel parameters
        status = clSetKernelArg(kernel_1, 0, sizeof(cl_mem), (void *)&yPlaneDown0Buffer);
        checkErr(status, "clSetKernelArg for 0");
        status = clSetKernelArg(kernel_1, 1, sizeof(int), (void *)&width);
        checkErr(status, "clSetKernelArg for 1");
        status = clSetKernelArg(kernel_1, 2, sizeof(int), (void *)&height);
        checkErr(status, "clSetKernelArg for 2");
        status = clSetKernelArg(kernel_1, 3, sizeof(int), (void *)&quarterWidth);
        checkErr(status, "clSetKernelArg for 3");
        status = clSetKernelArg(kernel_1, 4, sizeof(cl_mem), (void *)&yPlane0Buffer);
        checkErr(status, "clSetKernelArg for 4");

        //launch a kernel
        status = clEnqueueNDRangeKernel(queue, kernel_1, 2, NULL, globalWorkSize1, localWorkSize1, 0, NULL, NULL);
        checkErr(status, "clEnqueueNDRangeKernel for kernel_1");

        //wait until kernel finish
        status = clFinish(queue);
        checkErr(status, "clFinish for kernel_1");

        //release kernel
        clReleaseKernel(kernel_1);
        gettimeofday(&end_cpu[1], __null);
        gettimeofday(&start_cpu[2], __null);
                //create the kernel
        cl_kernel kernel_2 = clCreateKernel(program, "kernel_2", &status);
        checkErr(status, "clCreateKernel for kernel_2");

        //set thread/thread-block size
        size_t localWorkSize2[3]= {1, 1, 1};
        size_t blockWorkSize2[3]= {1, 1, 1};
        size_t globalWorkSize2[3]= {1, 1, 1};
        localWorkSize2[0] = 256;
        blockWorkSize2[0] = upMultiple( quarterHeight, 256 );
        globalWorkSize2[0] = blockWorkSize2[0] * localWorkSize2[0];
        //set kernel parameters
        status = clSetKernelArg(kernel_2, 0, sizeof(cl_mem), (void *)&yPlaneCSER0Buffer);
        checkErr(status, "clSetKernelArg for 0");
        status = clSetKernelArg(kernel_2, 1, sizeof(int), (void *)&width);
        checkErr(status, "clSetKernelArg for 1");
        status = clSetKernelArg(kernel_2, 2, sizeof(int), (void *)&quarterWidth);
        checkErr(status, "clSetKernelArg for 2");
        status = clSetKernelArg(kernel_2, 3, sizeof(int), (void *)&quarterHeight);
        checkErr(status, "clSetKernelArg for 3");
        status = clSetKernelArg(kernel_2, 4, sizeof(cl_mem), (void *)&yPlaneDown0Buffer);
        checkErr(status, "clSetKernelArg for 4");

        //launch a kernel
        status = clEnqueueNDRangeKernel(queue, kernel_2, 1, NULL, globalWorkSize2, localWorkSize2, 0, NULL, NULL);
        checkErr(status, "clEnqueueNDRangeKernel for kernel_2");

        //wait until kernel finish
        status = clFinish(queue);
        checkErr(status, "clFinish for kernel_2");

        //release kernel
        clReleaseKernel(kernel_2);
                //create the kernel
        cl_kernel kernel_3 = clCreateKernel(program, "kernel_3", &status);
        checkErr(status, "clCreateKernel for kernel_3");

        //set thread/thread-block size
        size_t localWorkSize3[3]= {1, 1, 1};
        size_t blockWorkSize3[3]= {1, 1, 1};
        size_t globalWorkSize3[3]= {1, 1, 1};
        localWorkSize3[0] = 256;
        blockWorkSize3[0] = upMultiple( quarterHeight, 256 );
        globalWorkSize3[0] = blockWorkSize3[0] * localWorkSize3[0];
        //set kernel parameters
        status = clSetKernelArg(kernel_3, 0, sizeof(int), (void *)&width);
        checkErr(status, "clSetKernelArg for 0");
        status = clSetKernelArg(kernel_3, 1, sizeof(int), (void *)&quarterHeight);
        checkErr(status, "clSetKernelArg for 1");
        status = clSetKernelArg(kernel_3, 2, sizeof(cl_mem), (void *)&yPlaneCSER0Buffer);
        checkErr(status, "clSetKernelArg for 2");

        //launch a kernel
        status = clEnqueueNDRangeKernel(queue, kernel_3, 1, NULL, globalWorkSize3, localWorkSize3, 0, NULL, NULL);
        checkErr(status, "clEnqueueNDRangeKernel for kernel_3");

        //wait until kernel finish
        status = clFinish(queue);
        checkErr(status, "clFinish for kernel_3");

        //release kernel
        clReleaseKernel(kernel_3);
                //create the kernel
        cl_kernel kernel_4 = clCreateKernel(program, "kernel_4", &status);
        checkErr(status, "clCreateKernel for kernel_4");

        //set thread/thread-block size
        size_t localWorkSize4[3]= {1, 1, 1};
        size_t blockWorkSize4[3]= {1, 1, 1};
        size_t globalWorkSize4[3]= {1, 1, 1};
        localWorkSize4[0] = 256;
        blockWorkSize4[0] = upMultiple( height, 256 );
        globalWorkSize4[0] = blockWorkSize4[0] * localWorkSize4[0];
        //set kernel parameters
        status = clSetKernelArg(kernel_4, 0, sizeof(int), (void *)&width);
        checkErr(status, "clSetKernelArg for 0");
        status = clSetKernelArg(kernel_4, 1, sizeof(int), (void *)&height);
        checkErr(status, "clSetKernelArg for 1");
        status = clSetKernelArg(kernel_4, 2, sizeof(cl_mem), (void *)&yPlaneCSER0Buffer);
        checkErr(status, "clSetKernelArg for 2");

        //launch a kernel
        status = clEnqueueNDRangeKernel(queue, kernel_4, 1, NULL, globalWorkSize4, localWorkSize4, 0, NULL, NULL);
        checkErr(status, "clEnqueueNDRangeKernel for kernel_4");

        //wait until kernel finish
        status = clFinish(queue);
        checkErr(status, "clFinish for kernel_4");

        //release kernel
        clReleaseKernel(kernel_4);
                //create the kernel
        cl_kernel kernel_5 = clCreateKernel(program, "kernel_5", &status);
        checkErr(status, "clCreateKernel for kernel_5");

        //set thread/thread-block size
        size_t localWorkSize5[3]= {1, 1, 1};
        size_t blockWorkSize5[3]= {1, 1, 1};
        size_t globalWorkSize5[3]= {1, 1, 1};
        localWorkSize5[0] = 256;
        blockWorkSize5[0] = upMultiple( quarterWidth, 256 );
        globalWorkSize5[0] = blockWorkSize5[0] * localWorkSize5[0];
        //set kernel parameters
        status = clSetKernelArg(kernel_5, 0, sizeof(cl_mem), (void *)&yPlaneCSER0Buffer);
        checkErr(status, "clSetKernelArg for 0");
        status = clSetKernelArg(kernel_5, 1, sizeof(int), (void *)&width);
        checkErr(status, "clSetKernelArg for 1");
        status = clSetKernelArg(kernel_5, 2, sizeof(int), (void *)&height);
        checkErr(status, "clSetKernelArg for 2");
        status = clSetKernelArg(kernel_5, 3, sizeof(int), (void *)&quarterWidth);
        checkErr(status, "clSetKernelArg for 3");
        status = clSetKernelArg(kernel_5, 4, sizeof(int), (void *)&quarterHeight);
        checkErr(status, "clSetKernelArg for 4");
        status = clSetKernelArg(kernel_5, 5, sizeof(cl_mem), (void *)&yPlaneDown0Buffer);
        checkErr(status, "clSetKernelArg for 5");

        //launch a kernel
        status = clEnqueueNDRangeKernel(queue, kernel_5, 1, NULL, globalWorkSize5, localWorkSize5, 0, NULL, NULL);
        checkErr(status, "clEnqueueNDRangeKernel for kernel_5");

        //wait until kernel finish
        status = clFinish(queue);
        checkErr(status, "clFinish for kernel_5");

        //release kernel
        clReleaseKernel(kernel_5);
                //create the kernel
        cl_kernel kernel_6 = clCreateKernel(program, "kernel_6", &status);
        checkErr(status, "clCreateKernel for kernel_6");

        //set thread/thread-block size
        size_t localWorkSize6[3]= {1, 1, 1};
        size_t blockWorkSize6[3]= {1, 1, 1};
        size_t globalWorkSize6[3]= {1, 1, 1};
        localWorkSize6[0] = 256;
        blockWorkSize6[0] = upMultiple( quarterWidth, 256 );
        globalWorkSize6[0] = blockWorkSize6[0] * localWorkSize6[0];
        //set kernel parameters
        status = clSetKernelArg(kernel_6, 0, sizeof(int), (void *)&width);
        checkErr(status, "clSetKernelArg for 0");
        status = clSetKernelArg(kernel_6, 1, sizeof(int), (void *)&height);
        checkErr(status, "clSetKernelArg for 1");
        status = clSetKernelArg(kernel_6, 2, sizeof(int), (void *)&quarterWidth);
        checkErr(status, "clSetKernelArg for 2");
        status = clSetKernelArg(kernel_6, 3, sizeof(cl_mem), (void *)&yPlaneCSER0Buffer);
        checkErr(status, "clSetKernelArg for 3");

        //launch a kernel
        status = clEnqueueNDRangeKernel(queue, kernel_6, 1, NULL, globalWorkSize6, localWorkSize6, 0, NULL, NULL);
        checkErr(status, "clEnqueueNDRangeKernel for kernel_6");

        //wait until kernel finish
        status = clFinish(queue);
        checkErr(status, "clFinish for kernel_6");

        //release kernel
        clReleaseKernel(kernel_6);
                //create the kernel
        cl_kernel kernel_7 = clCreateKernel(program, "kernel_7", &status);
        checkErr(status, "clCreateKernel for kernel_7");

        //set thread/thread-block size
        size_t localWorkSize7[3]= {1, 1, 1};
        size_t blockWorkSize7[3]= {1, 1, 1};
        size_t globalWorkSize7[3]= {1, 1, 1};
        localWorkSize7[0] = 256;
        blockWorkSize7[0] = upMultiple( width, 256 );
        globalWorkSize7[0] = blockWorkSize7[0] * localWorkSize7[0];
        //set kernel parameters
        status = clSetKernelArg(kernel_7, 0, sizeof(int), (void *)&width);
        checkErr(status, "clSetKernelArg for 0");
        status = clSetKernelArg(kernel_7, 1, sizeof(int), (void *)&height);
        checkErr(status, "clSetKernelArg for 1");
        status = clSetKernelArg(kernel_7, 2, sizeof(cl_mem), (void *)&yPlaneCSER0Buffer);
        checkErr(status, "clSetKernelArg for 2");

        //launch a kernel
        status = clEnqueueNDRangeKernel(queue, kernel_7, 1, NULL, globalWorkSize7, localWorkSize7, 0, NULL, NULL);
        checkErr(status, "clEnqueueNDRangeKernel for kernel_7");

        //wait until kernel finish
        status = clFinish(queue);
        checkErr(status, "clFinish for kernel_7");

        //release kernel
        clReleaseKernel(kernel_7);
                //create the kernel
        cl_kernel kernel_8 = clCreateKernel(program, "kernel_8", &status);
        checkErr(status, "clCreateKernel for kernel_8");

        //set thread/thread-block size
        size_t localWorkSize8[3]= {1, 1, 1};
        size_t blockWorkSize8[3]= {1, 1, 1};
        size_t globalWorkSize8[3]= {1, 1, 1};
        localWorkSize8[0] = 256;
        blockWorkSize8[0] = upMultiple( quarterHeight, 256 );
        globalWorkSize8[0] = blockWorkSize8[0] * localWorkSize8[0];
        //set kernel parameters
        status = clSetKernelArg(kernel_8, 0, sizeof(cl_mem), (void *)&yPlaneCSER0Buffer);
        checkErr(status, "clSetKernelArg for 0");
        status = clSetKernelArg(kernel_8, 1, sizeof(int), (void *)&width);
        checkErr(status, "clSetKernelArg for 1");
        status = clSetKernelArg(kernel_8, 2, sizeof(int), (void *)&quarterWidth);
        checkErr(status, "clSetKernelArg for 2");
        status = clSetKernelArg(kernel_8, 3, sizeof(int), (void *)&quarterHeight);
        checkErr(status, "clSetKernelArg for 3");
        status = clSetKernelArg(kernel_8, 4, sizeof(cl_mem), (void *)&yPlaneDown0Buffer);
        checkErr(status, "clSetKernelArg for 4");

        //launch a kernel
        status = clEnqueueNDRangeKernel(queue, kernel_8, 1, NULL, globalWorkSize8, localWorkSize8, 0, NULL, NULL);
        checkErr(status, "clEnqueueNDRangeKernel for kernel_8");

        //wait until kernel finish
        status = clFinish(queue);
        checkErr(status, "clFinish for kernel_8");

        //release kernel
        clReleaseKernel(kernel_8);
                //create the kernel
        cl_kernel kernel_9 = clCreateKernel(program, "kernel_9", &status);
        checkErr(status, "clCreateKernel for kernel_9");

        //set thread/thread-block size
        size_t localWorkSize9[3]= {1, 1, 1};
        size_t blockWorkSize9[3]= {1, 1, 1};
        size_t globalWorkSize9[3]= {1, 1, 1};
        localWorkSize9[0] = 256;
        blockWorkSize9[0] = upMultiple( quarterHeight, 256 );
        globalWorkSize9[0] = blockWorkSize9[0] * localWorkSize9[0];
        //set kernel parameters
        status = clSetKernelArg(kernel_9, 0, sizeof(int), (void *)&width);
        checkErr(status, "clSetKernelArg for 0");
        status = clSetKernelArg(kernel_9, 1, sizeof(int), (void *)&quarterHeight);
        checkErr(status, "clSetKernelArg for 1");
        status = clSetKernelArg(kernel_9, 2, sizeof(cl_mem), (void *)&yPlaneCSER0Buffer);
        checkErr(status, "clSetKernelArg for 2");

        //launch a kernel
        status = clEnqueueNDRangeKernel(queue, kernel_9, 1, NULL, globalWorkSize9, localWorkSize9, 0, NULL, NULL);
        checkErr(status, "clEnqueueNDRangeKernel for kernel_9");

        //wait until kernel finish
        status = clFinish(queue);
        checkErr(status, "clFinish for kernel_9");

        //release kernel
        clReleaseKernel(kernel_9);
                //create the kernel
        cl_kernel kernel_10 = clCreateKernel(program, "kernel_10", &status);
        checkErr(status, "clCreateKernel for kernel_10");

        //set thread/thread-block size
        size_t localWorkSize10[3]= {1, 1, 1};
        size_t blockWorkSize10[3]= {1, 1, 1};
        size_t globalWorkSize10[3]= {1, 1, 1};
        localWorkSize10[0] = 256;
        blockWorkSize10[0] = upMultiple( height, 256 );
        globalWorkSize10[0] = blockWorkSize10[0] * localWorkSize10[0];
        //set kernel parameters
        status = clSetKernelArg(kernel_10, 0, sizeof(int), (void *)&width);
        checkErr(status, "clSetKernelArg for 0");
        status = clSetKernelArg(kernel_10, 1, sizeof(int), (void *)&height);
        checkErr(status, "clSetKernelArg for 1");
        status = clSetKernelArg(kernel_10, 2, sizeof(cl_mem), (void *)&yPlaneCSER0Buffer);
        checkErr(status, "clSetKernelArg for 2");

        //launch a kernel
        status = clEnqueueNDRangeKernel(queue, kernel_10, 1, NULL, globalWorkSize10, localWorkSize10, 0, NULL, NULL);
        checkErr(status, "clEnqueueNDRangeKernel for kernel_10");

        //wait until kernel finish
        status = clFinish(queue);
        checkErr(status, "clFinish for kernel_10");

        //release kernel
        clReleaseKernel(kernel_10);
                //create the kernel
        cl_kernel kernel_11 = clCreateKernel(program, "kernel_11", &status);
        checkErr(status, "clCreateKernel for kernel_11");

        //set thread/thread-block size
        size_t localWorkSize11[3]= {1, 1, 1};
        size_t blockWorkSize11[3]= {1, 1, 1};
        size_t globalWorkSize11[3]= {1, 1, 1};
        localWorkSize11[1] = 8;
        blockWorkSize11[1] = upMultiple( quarterHeight - 1, 8 );
        localWorkSize11[0] = 32;
        blockWorkSize11[0] = upMultiple( quarterWidth - 1, 32 );
        globalWorkSize11[0] = blockWorkSize11[0] * localWorkSize11[0];
        globalWorkSize11[1] = blockWorkSize11[1] * localWorkSize11[1];
        //set kernel parameters
        status = clSetKernelArg(kernel_11, 0, sizeof(cl_mem), (void *)&yPlaneCSER0Buffer);
        checkErr(status, "clSetKernelArg for 0");
        status = clSetKernelArg(kernel_11, 1, sizeof(int), (void *)&width);
        checkErr(status, "clSetKernelArg for 1");
        status = clSetKernelArg(kernel_11, 2, sizeof(int), (void *)&quarterWidth);
        checkErr(status, "clSetKernelArg for 2");
        status = clSetKernelArg(kernel_11, 3, sizeof(int), (void *)&quarterHeight);
        checkErr(status, "clSetKernelArg for 3");
        status = clSetKernelArg(kernel_11, 4, sizeof(cl_mem), (void *)&yPlaneDown0Buffer);
        checkErr(status, "clSetKernelArg for 4");

        //launch a kernel
        status = clEnqueueNDRangeKernel(queue, kernel_11, 2, NULL, globalWorkSize11, localWorkSize11, 0, NULL, NULL);
        checkErr(status, "clEnqueueNDRangeKernel for kernel_11");

        //wait until kernel finish
        status = clFinish(queue);
        checkErr(status, "clFinish for kernel_11");

        //release kernel
        clReleaseKernel(kernel_11);
        gettimeofday(&end_cpu[2], __null);
        gettimeofday(&start_cpu[3], __null);
                //create reduction buffers on GPU 
        cl_mem sum18Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(long), NULL, &status);
        checkErr(status, "clCreateBuffer for sum");

        //copyin reduction buffers to GPU 
        status = clEnqueueWriteBuffer(queue, sum18Buffer, CL_TRUE, 0, sizeof(long), &sum, 0, NULL, NULL);
        checkErr(status, "clEnqueueWriteBuffer for sum");

        //create the kernel
        cl_kernel kernel_12 = clCreateKernel(program, "kernel_12", &status);
        checkErr(status, "clCreateKernel for kernel_12");

        //set thread/thread-block size
        size_t localWorkSize12[3]= {1, 1, 1};
        size_t blockWorkSize12[3]= {1, 1, 1};
        size_t globalWorkSize12[3]= {1, 1, 1};
        localWorkSize12[1] = 8;
        blockWorkSize12[1] = upMultiple( height, 8 );
        localWorkSize12[0] = 32;
        blockWorkSize12[0] = upMultiple( width, 32 );
        globalWorkSize12[0] = blockWorkSize12[0] * localWorkSize12[0];
        globalWorkSize12[1] = blockWorkSize12[1] * localWorkSize12[1];
        //set kernel parameters
        status = clSetKernelArg(kernel_12, 0, sizeof(int), (void *)&width);
        checkErr(status, "clSetKernelArg for 0");
        status = clSetKernelArg(kernel_12, 1, sizeof(int), (void *)&height);
        checkErr(status, "clSetKernelArg for 1");
        status = clSetKernelArg(kernel_12, 2, sizeof(cl_mem), (void *)&yPlane0Buffer);
        checkErr(status, "clSetKernelArg for 2");
        status = clSetKernelArg(kernel_12, 3, sizeof(cl_mem), (void *)&pEdge0Buffer);
        checkErr(status, "clSetKernelArg for 3");
        status = clSetKernelArg(kernel_12, 4, sizeof(cl_mem), (void *)&sum18Buffer);
        checkErr(status, "clSetKernelArg for 4");
        status = clSetKernelArg(kernel_12, 5, 8 * localWorkSize12[0] * localWorkSize12[1] * localWorkSize12[2] , NULL);
        checkErr(status, "clSetKernelArg for 5");

        //launch a kernel
        status = clEnqueueNDRangeKernel(queue, kernel_12, 2, NULL, globalWorkSize12, localWorkSize12, 0, NULL, NULL);
        checkErr(status, "clEnqueueNDRangeKernel for kernel_12");

        //wait until kernel finish
        status = clFinish(queue);
        checkErr(status, "clFinish for kernel_12");

        //release kernel
        clReleaseKernel(kernel_12);
//copyout reduction buffers to CPU 
        status = clEnqueueReadBuffer(queue, sum18Buffer, CL_TRUE, 0, sizeof(long), &sum, 0, NULL, NULL);
        checkErr(status, "clEnqueueReadBuffer for sum");

        //release reduction buffers on GPU
        clReleaseMemObject(sum18Buffer);

        mean = (sum + (height * width) / 2) / (height * width);
        double cutoff = oldcutoffCoef * mean;
        double peak = oldpeak;
        double cutoff2 = oldcutoff2;
        double order = 2;
        double order2 = 2;
        double low = 1.;
        float cutoff3 = oldcutoff3Coef * mean;
        float order3 = 2;
        float peak3 = 1;
        float low3 = 0.0500000007F;
        gettimeofday(&end_cpu[3], __null);
        gettimeofday(&start_cpu[4], __null);
                //create the kernel
        cl_kernel kernel_13 = clCreateKernel(program, "kernel_13", &status);
        checkErr(status, "clCreateKernel for kernel_13");

        //set thread/thread-block size
        size_t localWorkSize13[3]= {1, 1, 1};
        size_t blockWorkSize13[3]= {1, 1, 1};
        size_t globalWorkSize13[3]= {1, 1, 1};
        localWorkSize13[1] = 8;
        blockWorkSize13[1] = upMultiple( height, 8 );
        localWorkSize13[0] = 32;
        blockWorkSize13[0] = upMultiple( width, 32 );
        globalWorkSize13[0] = blockWorkSize13[0] * localWorkSize13[0];
        globalWorkSize13[1] = blockWorkSize13[1] * localWorkSize13[1];
        //set kernel parameters
        status = clSetKernelArg(kernel_13, 0, sizeof(int), (void *)&width);
        checkErr(status, "clSetKernelArg for 0");
        status = clSetKernelArg(kernel_13, 1, sizeof(int), (void *)&height);
        checkErr(status, "clSetKernelArg for 1");
        status = clSetKernelArg(kernel_13, 2, sizeof(cl_mem), (void *)&yPlane0Buffer);
        checkErr(status, "clSetKernelArg for 2");
        status = clSetKernelArg(kernel_13, 3, sizeof(cl_mem), (void *)&yPlaneCSER0Buffer);
        checkErr(status, "clSetKernelArg for 3");
        status = clSetKernelArg(kernel_13, 4, sizeof(cl_mem), (void *)&pEdge0Buffer);
        checkErr(status, "clSetKernelArg for 4");
        status = clSetKernelArg(kernel_13, 5, sizeof(double), (void *)&cutoff);
        checkErr(status, "clSetKernelArg for 5");
        status = clSetKernelArg(kernel_13, 6, sizeof(double), (void *)&peak);
        checkErr(status, "clSetKernelArg for 6");
        status = clSetKernelArg(kernel_13, 7, sizeof(double), (void *)&cutoff2);
        checkErr(status, "clSetKernelArg for 7");
        status = clSetKernelArg(kernel_13, 8, sizeof(double), (void *)&order);
        checkErr(status, "clSetKernelArg for 8");
        status = clSetKernelArg(kernel_13, 9, sizeof(double), (void *)&order2);
        checkErr(status, "clSetKernelArg for 9");
        status = clSetKernelArg(kernel_13, 10, sizeof(double), (void *)&low);
        checkErr(status, "clSetKernelArg for 10");
        status = clSetKernelArg(kernel_13, 11, sizeof(float), (void *)&cutoff3);
        checkErr(status, "clSetKernelArg for 11");
        status = clSetKernelArg(kernel_13, 12, sizeof(float), (void *)&order3);
        checkErr(status, "clSetKernelArg for 12");
        status = clSetKernelArg(kernel_13, 13, sizeof(float), (void *)&peak3);
        checkErr(status, "clSetKernelArg for 13");
        status = clSetKernelArg(kernel_13, 14, sizeof(float), (void *)&low3);
        checkErr(status, "clSetKernelArg for 14");
        status = clSetKernelArg(kernel_13, 15, sizeof(cl_mem), (void *)&pError0Buffer);
        checkErr(status, "clSetKernelArg for 15");
        status = clSetKernelArg(kernel_13, 16, sizeof(cl_mem), (void *)&pSharpness0Buffer);
        checkErr(status, "clSetKernelArg for 16");

        //launch a kernel
        status = clEnqueueNDRangeKernel(queue, kernel_13, 2, NULL, globalWorkSize13, localWorkSize13, 0, NULL, NULL);
        checkErr(status, "clEnqueueNDRangeKernel for kernel_13");

        //wait until kernel finish
        status = clFinish(queue);
        checkErr(status, "clFinish for kernel_13");

        //release kernel
        clReleaseKernel(kernel_13);
        gettimeofday(&end_cpu[4], __null);
        gettimeofday(&start_cpu[5], __null);
                //create the kernel
        cl_kernel kernel_14 = clCreateKernel(program, "kernel_14", &status);
        checkErr(status, "clCreateKernel for kernel_14");

        //set thread/thread-block size
        size_t localWorkSize14[3]= {1, 1, 1};
        size_t blockWorkSize14[3]= {1, 1, 1};
        size_t globalWorkSize14[3]= {1, 1, 1};
        localWorkSize14[1] = 8;
        blockWorkSize14[1] = upMultiple( height, 8 );
        localWorkSize14[0] = 32;
        blockWorkSize14[0] = upMultiple( width, 32 );
        globalWorkSize14[0] = blockWorkSize14[0] * localWorkSize14[0];
        globalWorkSize14[1] = blockWorkSize14[1] * localWorkSize14[1];
        //set kernel parameters
        status = clSetKernelArg(kernel_14, 0, sizeof(cl_mem), (void *)&yPlane0Buffer);
        checkErr(status, "clSetKernelArg for 0");
        status = clSetKernelArg(kernel_14, 1, sizeof(int), (void *)&width);
        checkErr(status, "clSetKernelArg for 1");
        status = clSetKernelArg(kernel_14, 2, sizeof(int), (void *)&height);
        checkErr(status, "clSetKernelArg for 2");
        status = clSetKernelArg(kernel_14, 3, sizeof(cl_mem), (void *)&pSharpness0Buffer);
        checkErr(status, "clSetKernelArg for 3");

        //launch a kernel
        status = clEnqueueNDRangeKernel(queue, kernel_14, 2, NULL, globalWorkSize14, localWorkSize14, 0, NULL, NULL);
        checkErr(status, "clEnqueueNDRangeKernel for kernel_14");

        //wait until kernel finish
        status = clFinish(queue);
        checkErr(status, "clFinish for kernel_14");

        //release kernel
        clReleaseKernel(kernel_14);
        gettimeofday(&end_cpu[5], __null);
      }
    //copyout buffers to CPU acccording to data pragma
    status = clEnqueueReadBuffer(queue, yPlane0Buffer, CL_TRUE, 0, yPlane0Size, yPlane, 0, NULL, NULL);
    checkErr(status, "clEnqueueReadBuffer for yPlane");

    //release buffers
    clReleaseMemObject(yPlane0Buffer);
    clReleaseMemObject(yPlaneCSER0Buffer);
    clReleaseMemObject(yPlaneDown0Buffer);
    clReleaseMemObject(pError0Buffer);
    clReleaseMemObject(pEdge0Buffer);
    clReleaseMemObject(pSharpness0Buffer);

    gettimeofday(&end_cpu[0], __null);
    printf("%d\n", yPlane[10 * width + 110]);
    double duration_cpu = 0.;
    printf("sharpness cpu(inline) Size: %dx%d\n", height, width);
    for (int i = 0; i < 6; i++) {
      duration_cpu = 1000 * ((end_cpu[i]).tv_sec - (start_cpu[i]).tv_sec) + ((end_cpu[i]).tv_usec - (start_cpu[i]).tv_usec) / 1000.;
      if (i == 0)
        printf("Total: ");
      else if (i == 1)
        printf("DownScale: ");
      else if (i == 2)
        printf("UpScale: ");
      else if (i == 3)
        printf("Sobel+Mean: ");
      else if (i == 4)
        printf("Error+Sharp_Strength+OverShoot: ");
      else if (i == 5)
        printf("Sharp_Cut: ");
      printf("%.2f ms\n", duration_cpu);
    }
    printf("\n");
  }
  for (int i = 0; i < height * width; i++) {
    yPlane_cpu[i] = yuvfile[i];
  }
  for (int i = 0; i < height; i += 4) {
    for (int j = 0; j < width; j += 4) {
      yPlaneDown[(i / 4) * quarterWidth + j / 4] = (yPlane_cpu[i * width + j] + yPlane_cpu[i * width + j + 1] + yPlane_cpu[i * width + j + 2] + yPlane_cpu[i * width + j + 3] + yPlane_cpu[(i + 1) * width + j] + yPlane_cpu[(i + 1) * width + j + 1] + yPlane_cpu[(i + 1) * width + j + 2] + yPlane_cpu[(i + 1) * width + j + 3] + yPlane_cpu[(i + 2) * width + j] + yPlane_cpu[(i + 2) * width + j + 1] + yPlane_cpu[(i + 2) * width + j + 2] + yPlane_cpu[(i + 2) * width + j + 3] + yPlane_cpu[(i + 3) * width + j] + yPlane_cpu[(i + 3) * width + j + 1] + yPlane_cpu[(i + 3) * width + j + 2] + yPlane_cpu[(i + 3) * width + j + 3] + 8) >> 4;
    }
  }
  for (int h = 0; h < quarterHeight; h++) {
    yPlaneCSER[h * 4 * width + 0] = yPlaneDown[h * quarterWidth + 0];
  }
  for (int h = 0; h < quarterHeight; h++) {
    if (h < quarterHeight - 1) {
      yPlaneCSER[(h * 4 + 1) * width + 0] = (yPlaneCSER[(h * 4) * width + 0] * 3 + yPlaneCSER[(h * 4 + 4) * width + 0] * 1) / 4;
      yPlaneCSER[(h * 4 + 2) * width + 0] = (yPlaneCSER[(h * 4) * width + 0] * 2 + yPlaneCSER[(h * 4 + 4) * width + 0] * 2) / 4;
      yPlaneCSER[(h * 4 + 3) * width + 0] = (yPlaneCSER[(h * 4) * width + 0] * 1 + yPlaneCSER[(h * 4 + 4) * width + 0] * 3) / 4;
    } else {
      yPlaneCSER[(h * 4 + 1) * width + 0] = yPlaneCSER[(h * 4) * width + 0];
    }
  }
  for (int h = 0; h < height; h++) {
    yPlaneCSER[(h) * width + 1] = yPlaneCSER[(h) * width + 0];
  }
  for (int w = 0; w < quarterWidth; w++) {
    yPlaneCSER[0 * width + w * 4] = yPlaneDown[0 * quarterWidth + w];
  }
  for (int w = 0; w < quarterWidth; w++) {
    if (w < quarterWidth - 1) {
      yPlaneCSER[(0) * width + w * 4 + 1] = (yPlaneCSER[(0) * width + w * 4] * 3 + yPlaneCSER[(0) * width + w * 4 + 4] * 1) / 4;
      yPlaneCSER[(0) * width + w * 4 + 2] = (yPlaneCSER[(0) * width + w * 4] * 2 + yPlaneCSER[(0) * width + w * 4 + 4] * 2) / 4;
      yPlaneCSER[(0) * width + w * 4 + 3] = (yPlaneCSER[(0) * width + w * 4] * 1 + yPlaneCSER[(0) * width + w * 4 + 4] * 3) / 4;
    } else {
      yPlaneCSER[(0) * width + w * 4 + 1] = yPlaneCSER[(0) * width + w * 4];
    }
  }
  for (int w = 0; w < width; w++) {
    yPlaneCSER[1 * width + w] = yPlaneCSER[0 * width + w];
  }
  for (int w = 0; w < quarterWidth; w++) {
    yPlaneCSER[(height - 2) * width + w * 4] = yPlaneDown[(quarterHeight - 1) * quarterWidth + w];
  }
  for (int w = 0; w < quarterWidth; w++) {
    if (w < quarterWidth - 1) {
      yPlaneCSER[(height - 2) * width + w * 4 + 1] = (yPlaneCSER[(height - 2) * width + w * 4] * 3 + yPlaneCSER[(height - 2) * width + w * 4 + 4] * 1) / 4;
      yPlaneCSER[(height - 2) * width + w * 4 + 2] = (yPlaneCSER[(height - 2) * width + w * 4] * 2 + yPlaneCSER[(height - 2) * width + w * 4 + 4] * 2) / 4;
      yPlaneCSER[(height - 2) * width + w * 4 + 3] = (yPlaneCSER[(height - 2) * width + w * 4] * 1 + yPlaneCSER[(height - 2) * width + w * 4 + 4] * 3) / 4;
    } else {
      yPlaneCSER[(height - 2) * width + w * 4 + 1] = yPlaneCSER[(height - 2) * width + w * 4];
    }
  }
  for (int w = 0; w < width; w++) {
    yPlaneCSER[(height - 1) * width + w] = yPlaneCSER[(height - 2) * width + w];
  }
  for (int h = 0; h < quarterHeight; h++) {
    yPlaneCSER[(h * 4) * width + width - 2] = yPlaneDown[h * quarterWidth + quarterWidth - 1];
  }
  for (int h = 0; h < quarterHeight; h++) {
    if (h < quarterHeight - 1) {
      yPlaneCSER[(h * 4 + 1) * width + width - 2] = (yPlaneCSER[(h * 4) * width + width - 2] * 3 + yPlaneCSER[(h * 4 + 4) * width + width - 2] * 1) / 4;
      yPlaneCSER[(h * 4 + 2) * width + width - 2] = (yPlaneCSER[(h * 4) * width + width - 2] * 2 + yPlaneCSER[(h * 4 + 4) * width + width - 2] * 2) / 4;
      yPlaneCSER[(h * 4 + 3) * width + width - 2] = (yPlaneCSER[(h * 4) * width + width - 2] * 1 + yPlaneCSER[(h * 4 + 4) * width + width - 2] * 3) / 4;
    } else {
      yPlaneCSER[(h * 4 + 1) * width + width - 2] = yPlaneCSER[(h * 4) * width + width - 2];
      yPlaneCSER[(h * 4 + 2) * width + width - 2] = yPlaneCSER[(h * 4) * width + width - 2];
      yPlaneCSER[(h * 4 + 3) * width + width - 2] = yPlaneCSER[(h * 4) * width + width - 2];
    }
  }
  for (int h = 0; h < height; h++) {
    yPlaneCSER[(h) * width + width - 1] = yPlaneCSER[(h) * width + width - 2];
  }
  for (int h = 0; h < quarterHeight - 1; h++) {
    for (int w = 0; w < quarterWidth - 1; w++) {
      yPlaneCSER[(h * 4 + 2) * width + w * 4 + 2] = (yPlaneDown[(h) * quarterWidth + w] * 7 + yPlaneDown[(h) * quarterWidth + w + 1] * 1) * 7 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 7 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 1) / 8 / 8;
      yPlaneCSER[(h * 4 + 2) * width + w * 4 + 2 + 1] = (yPlaneDown[(h) * quarterWidth + w] * 5 + yPlaneDown[(h) * quarterWidth + w + 1] * 3) * 7 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 5 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 3) / 8 / 8;
      yPlaneCSER[(h * 4 + 2) * width + w * 4 + 2 + 2] = (yPlaneDown[(h) * quarterWidth + w] * 3 + yPlaneDown[(h) * quarterWidth + w + 1] * 5) * 7 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 3 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 5) / 8 / 8;
      yPlaneCSER[(h * 4 + 2) * width + w * 4 + 2 + 3] = (yPlaneDown[(h) * quarterWidth + w] * 1 + yPlaneDown[(h) * quarterWidth + w + 1] * 7) * 7 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 1 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 7) / 8 / 8;
      yPlaneCSER[(h * 4 + 3) * width + w * 4 + 2] = (yPlaneDown[(h) * quarterWidth + w] * 7 + yPlaneDown[(h) * quarterWidth + w + 1] * 1) * 5 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 7 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 1) * 3 / 8 / 8;
      yPlaneCSER[(h * 4 + 3) * width + w * 4 + 2 + 1] = (yPlaneDown[(h) * quarterWidth + w] * 5 + yPlaneDown[(h) * quarterWidth + w + 1] * 3) * 5 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 5 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 3) * 3 / 8 / 8;
      yPlaneCSER[(h * 4 + 3) * width + w * 4 + 2 + 2] = (yPlaneDown[(h) * quarterWidth + w] * 3 + yPlaneDown[(h) * quarterWidth + w + 1] * 5) * 5 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 3 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 5) * 3 / 8 / 8;
      yPlaneCSER[(h * 4 + 3) * width + w * 4 + 2 + 3] = (yPlaneDown[(h) * quarterWidth + w] * 1 + yPlaneDown[(h) * quarterWidth + w + 1] * 7) * 5 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 1 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 7) * 3 / 8 / 8;
      yPlaneCSER[(h * 4 + 4) * width + w * 4 + 2] = (yPlaneDown[(h) * quarterWidth + w] * 7 + yPlaneDown[(h) * quarterWidth + w + 1] * 1) * 3 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 7 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 1) * 5 / 8 / 8;
      yPlaneCSER[(h * 4 + 4) * width + w * 4 + 2 + 1] = (yPlaneDown[(h) * quarterWidth + w] * 5 + yPlaneDown[(h) * quarterWidth + w + 1] * 3) * 3 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 5 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 3) * 5 / 8 / 8;
      yPlaneCSER[(h * 4 + 4) * width + w * 4 + 2 + 2] = (yPlaneDown[(h) * quarterWidth + w] * 3 + yPlaneDown[(h) * quarterWidth + w + 1] * 5) * 3 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 3 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 5) * 5 / 8 / 8;
      yPlaneCSER[(h * 4 + 4) * width + w * 4 + 2 + 3] = (yPlaneDown[(h) * quarterWidth + w] * 1 + yPlaneDown[(h) * quarterWidth + w + 1] * 7) * 3 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 1 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 7) * 5 / 8 / 8;
      yPlaneCSER[(h * 4 + 5) * width + w * 4 + 2] = (yPlaneDown[(h) * quarterWidth + w] * 7 + yPlaneDown[(h) * quarterWidth + w + 1] * 1) * 1 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 7 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 1) * 7 / 8 / 8;
      yPlaneCSER[(h * 4 + 5) * width + w * 4 + 2 + 1] = (yPlaneDown[(h) * quarterWidth + w] * 5 + yPlaneDown[(h) * quarterWidth + w + 1] * 3) * 1 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 5 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 3) * 7 / 8 / 8;
      yPlaneCSER[(h * 4 + 5) * width + w * 4 + 2 + 2] = (yPlaneDown[(h) * quarterWidth + w] * 3 + yPlaneDown[(h) * quarterWidth + w + 1] * 5) * 1 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 3 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 5) * 7 / 8 / 8;
      yPlaneCSER[(h * 4 + 5) * width + w * 4 + 2 + 3] = (yPlaneDown[(h) * quarterWidth + w] * 1 + yPlaneDown[(h) * quarterWidth + w + 1] * 7) * 1 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 1 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 7) * 7 / 8 / 8;
    }
  }
  for (int h = 0; h < height; h++) {
    for (int w = 0; w < width; w++) {
      pError[h * width + w] = yPlane_cpu[h * width + w] - yPlaneCSER[h * width + w];
    }
  }
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (y == 0 || y == height - 1 || x == 0 || x == width - 1) {
        pEdge[y * width + x] = 0;
      } else {
        int gx = (yPlane_cpu[(y - 1) * width + x + 1] + ((int)yPlane_cpu[(y) * width + x + 1] << 1) + yPlane_cpu[(y + 1) * width + x + 1]) - (yPlane_cpu[(y - 1) * width + x - 1] + ((int)yPlane_cpu[(y) * width + x - 1] << 1) + yPlane_cpu[(y + 1) * width + x - 1]);
        int gy = (yPlane_cpu[(y - 1) * width + x - 1] + ((int)yPlane_cpu[(y - 1) * width + x] << 1) + yPlane_cpu[(y - 1) * width + x + 1]) - (yPlane_cpu[(y + 1) * width + x - 1] + ((int)yPlane_cpu[(y + 1) * width + x] << 1) + yPlane_cpu[(y + 1) * width + x + 1]);
        int edgeV = (abs(gx) + abs(gy));
        pEdge[y * width + x] = edgeV;
      }
    }
  }
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      sum += pEdge[i * width + j];
    }
  }
  mean = (sum + (height * width) / 2) / (height * width);
  double cutoff = oldcutoffCoef * mean;
  double peak = oldpeak;
  double cutoff2 = oldcutoff2;
  double order = 2;
  double order2 = 2;
  double low = 1.;
  float cutoff3 = oldcutoff3Coef * mean;
  float order3 = 2;
  float peak3 = 1;
  float low3 = 0.0500000007F;
  for (int h = 0; h < height; h++) {
    for (int w = 0; w < width; w++) {
      short edge = pEdge[h * width + w];
      double weight = 1 / (1 + pow(edge / cutoff2, 2 * order2));
      double strength = (peak - low) * (1 - 1 / (1 + pow(edge / cutoff, 2 * order)));
      strength = strength * weight + low;
      pSharpness[h * width + w] = (yPlaneCSER[h * width + w]);
      pSharpness[h * width + w] += (double)(pError[h * width + w]) * strength;
    }
  }
  for (int h = 0; h < height; h++) {
    for (int w = 0; w < width; w++) {
      if (!(h == 0 || h == height - 1 || w == 0 || w == width - 1)) {
        int enhanced, maxValue, minValue;
        double oscStrength;
        enhanced = pSharpness[h * width + w];
        maxValue = ((((yPlane_cpu[(h - 1) * width + w - 1]) > (yPlane_cpu[(h - 1) * width + w]) ? (yPlane_cpu[(h - 1) * width + w - 1]) : (yPlane_cpu[(h - 1) * width + w]))) > (yPlane_cpu[(h - 1) * width + w + 1]) ? (((yPlane_cpu[(h - 1) * width + w - 1]) > (yPlane_cpu[(h - 1) * width + w]) ? (yPlane_cpu[(h - 1) * width + w - 1]) : (yPlane_cpu[(h - 1) * width + w]))) : (yPlane_cpu[(h - 1) * width + w + 1]));
        maxValue = ((maxValue) > (((((yPlane_cpu[(h) * width + w - 1]) > (yPlane_cpu[(h) * width + w]) ? (yPlane_cpu[(h) * width + w - 1]) : (yPlane_cpu[(h) * width + w]))) > (yPlane_cpu[(h) * width + w + 1]) ? (((yPlane_cpu[(h) * width + w - 1]) > (yPlane_cpu[(h) * width + w]) ? (yPlane_cpu[(h) * width + w - 1]) : (yPlane_cpu[(h) * width + w]))) : (yPlane_cpu[(h) * width + w + 1]))) ? (maxValue) : (((((yPlane_cpu[(h) * width + w - 1]) > (yPlane_cpu[(h) * width + w]) ? (yPlane_cpu[(h) * width + w - 1]) : (yPlane_cpu[(h) * width + w]))) > (yPlane_cpu[(h) * width + w + 1]) ? (((yPlane_cpu[(h) * width + w - 1]) > (yPlane_cpu[(h) * width + w]) ? (yPlane_cpu[(h) * width + w - 1]) : (yPlane_cpu[(h) * width + w]))) : (yPlane_cpu[(h) * width + w + 1]))));
        maxValue = ((maxValue) > (((((yPlane_cpu[(h + 1) * width + w - 1]) > (yPlane_cpu[(h + 1) * width + w]) ? (yPlane_cpu[(h + 1) * width + w - 1]) : (yPlane_cpu[(h + 1) * width + w]))) > (yPlane_cpu[(h + 1) * width + w + 1]) ? (((yPlane_cpu[(h + 1) * width + w - 1]) > (yPlane_cpu[(h + 1) * width + w]) ? (yPlane_cpu[(h + 1) * width + w - 1]) : (yPlane_cpu[(h + 1) * width + w]))) : (yPlane_cpu[(h + 1) * width + w + 1]))) ? (maxValue) : (((((yPlane_cpu[(h + 1) * width + w - 1]) > (yPlane_cpu[(h + 1) * width + w]) ? (yPlane_cpu[(h + 1) * width + w - 1]) : (yPlane_cpu[(h + 1) * width + w]))) > (yPlane_cpu[(h + 1) * width + w + 1]) ? (((yPlane_cpu[(h + 1) * width + w - 1]) > (yPlane_cpu[(h + 1) * width + w]) ? (yPlane_cpu[(h + 1) * width + w - 1]) : (yPlane_cpu[(h + 1) * width + w]))) : (yPlane_cpu[(h + 1) * width + w + 1]))));
        minValue = ((((yPlane_cpu[(h - 1) * width + w - 1])) < ((((yPlane_cpu[(h - 1) * width + w])) < ((yPlane_cpu[(h - 1) * width + w + 1])) ? ((yPlane_cpu[(h - 1) * width + w])) : ((yPlane_cpu[(h - 1) * width + w + 1])))) ? ((yPlane_cpu[(h - 1) * width + w - 1])) : ((((yPlane_cpu[(h - 1) * width + w])) < ((yPlane_cpu[(h - 1) * width + w + 1])) ? ((yPlane_cpu[(h - 1) * width + w])) : ((yPlane_cpu[(h - 1) * width + w + 1]))))));
        minValue = ((minValue) < (((((yPlane_cpu[(h) * width + w - 1])) < ((((yPlane_cpu[(h) * width + w])) < ((yPlane_cpu[(h) * width + w + 1])) ? ((yPlane_cpu[(h) * width + w])) : ((yPlane_cpu[(h) * width + w + 1])))) ? ((yPlane_cpu[(h) * width + w - 1])) : ((((yPlane_cpu[(h) * width + w])) < ((yPlane_cpu[(h) * width + w + 1])) ? ((yPlane_cpu[(h) * width + w])) : ((yPlane_cpu[(h) * width + w + 1]))))))) ? (minValue) : (((((yPlane_cpu[(h) * width + w - 1])) < ((((yPlane_cpu[(h) * width + w])) < ((yPlane_cpu[(h) * width + w + 1])) ? ((yPlane_cpu[(h) * width + w])) : ((yPlane_cpu[(h) * width + w + 1])))) ? ((yPlane_cpu[(h) * width + w - 1])) : ((((yPlane_cpu[(h) * width + w])) < ((yPlane_cpu[(h) * width + w + 1])) ? ((yPlane_cpu[(h) * width + w])) : ((yPlane_cpu[(h) * width + w + 1]))))))));
        minValue = ((minValue) < (((((yPlane_cpu[(h + 1) * width + w - 1])) < ((((yPlane_cpu[(h + 1) * width + w])) < ((yPlane_cpu[(h + 1) * width + w + 1])) ? ((yPlane_cpu[(h + 1) * width + w])) : ((yPlane_cpu[(h + 1) * width + w + 1])))) ? ((yPlane_cpu[(h + 1) * width + w - 1])) : ((((yPlane_cpu[(h + 1) * width + w])) < ((yPlane_cpu[(h + 1) * width + w + 1])) ? ((yPlane_cpu[(h + 1) * width + w])) : ((yPlane_cpu[(h + 1) * width + w + 1]))))))) ? (minValue) : (((((yPlane_cpu[(h + 1) * width + w - 1])) < ((((yPlane_cpu[(h + 1) * width + w])) < ((yPlane_cpu[(h + 1) * width + w + 1])) ? ((yPlane_cpu[(h + 1) * width + w])) : ((yPlane_cpu[(h + 1) * width + w + 1])))) ? ((yPlane_cpu[(h + 1) * width + w - 1])) : ((((yPlane_cpu[(h + 1) * width + w])) < ((yPlane_cpu[(h + 1) * width + w + 1])) ? ((yPlane_cpu[(h + 1) * width + w])) : ((yPlane_cpu[(h + 1) * width + w + 1]))))))));
        {
          double cutoff2Order = pow(cutoff3, 2 * order3);
          double edge2Order = pow((double)(pEdge[h * width + w]), (double)2 * order3);
          oscStrength = (peak3 * cutoff2Order + low3 * edge2Order) / (cutoff2Order + edge2Order);
        }
        if (enhanced > maxValue) {
          pSharpness[h * width + w] = ((maxValue + oscStrength * (enhanced - maxValue)) < (255) ? (maxValue + oscStrength * (enhanced - maxValue)) : (255));
        } else if (enhanced < minValue) {
          pSharpness[h * width + w] = ((0) > (minValue - oscStrength * (minValue - enhanced)) ? (0) : (minValue - oscStrength * (minValue - enhanced)));
        } else {
          pSharpness[h * width + w] = ((((enhanced) > (0) ? (enhanced) : (0))) < (255) ? (((enhanced) > (0) ? (enhanced) : (0))) : (255));
        }
      }
    }
  }
  for (int h = 0; h < height; h++) {
    for (int w = 0; w < width; w++) {
      yPlane_cpu[h * width + w] = pSharpness[h * width + w] > 255 ? 255 : pSharpness[h * width + w] < 0 ? 0 : pSharpness[h * width + w];
    }
  }
  bool error = false;
  for (int h = 0; h < height; h++) {
    for (int w = 0; w < width; w++) {
      if (abs(yPlane[h * width + w] - yPlane_cpu[h * width + w]) > 1) {
        error = true;
        printf("CPU:%d GPU:%d\n", yPlane_cpu[h * width + w], yPlane[h * width + w]);
      }
    }
  }
  if (error)
    printf("Error\n");
  else
    printf("OK\n");
  free(yPlane);
  free(yPlane_cpu);
  free(yPlaneCSER);
  free(yPlaneDown);
  free(pError);
  free(pSharpness);
  free(pEdge);
  return 0;
}

int main(int argc, char *argv[]) {
  // Create environment variables before the first data transfer.
  const char *inputFile = "sharpness_fuse-cap.cl";

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



