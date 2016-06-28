/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

#include "ClHost.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

struct timeval start_cpu[10];
struct timeval end_cpu[10];

int host_main(int argc, char **argv) {
  if (argc < 2) {
    printf("Please enter matrix size.\nThe format is: ./Laplacian height width.\nWidth should be a multiple of 64.\n");
    return 0;
  }
  int height = atoi(argv[1]);
  int width = atoi(argv[2]);
  int halfWidth = (width + 1) >> 1;
  int halfHeight = (height + 1) >> 1;
  unsigned char *Source = (unsigned char *)malloc(sizeof(unsigned char) * width * height);
  srand(0);
  for (int i = 0; i < height; i++) 
    for (int j = 0; j < width; j++) {
      Source[i * width + j] = rand() % 255;
    }
  unsigned char *FilterDst = (unsigned char *)malloc(sizeof(unsigned char) * width * height);
  unsigned char *DownsampleDst = (unsigned char *)malloc(sizeof(unsigned char) * halfWidth * halfHeight);
  short *LaplacianLayer_CPU = (short *)malloc(sizeof(short) * width * height);
  short *LaplacianLayer = (short *)malloc(sizeof(short) * width * height);
  int *pSrc_padding = (int *)malloc(sizeof(int) * (width + 4) * (height + 4));
  int *pSrc_padding2 = (int *)malloc(sizeof(int) * (width + 4) * (height + 4));
  unsigned char *UpsampleDst = (unsigned char *)malloc(sizeof(unsigned char) * width * height);
  unsigned char *pBufL_cp = (unsigned char *)malloc(sizeof(unsigned char) * width * height);
  for (int ii = 0; ii < 10; ii++) {
    gettimeofday(&start_cpu[0], __null);
        //create buffers on GPU according to data pragma
    int Source0Size = sizeof(unsigned char) * width * height;
    cl_mem Source0Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, Source0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for Source");
    int FilterDst0Size = sizeof(unsigned char) * width * height;
    cl_mem FilterDst0Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, FilterDst0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for FilterDst");
    int LaplacianLayer0Size = sizeof(short) * width * height;
    cl_mem LaplacianLayer0Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, LaplacianLayer0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for LaplacianLayer");
    int pSrc_padding0Size = sizeof(int) * (width + 4) * (height + 4);
    cl_mem pSrc_padding0Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, pSrc_padding0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for pSrc_padding");
    int pSrc_padding20Size = sizeof(int) * (width + 4) * (height + 4);
    cl_mem pSrc_padding20Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, pSrc_padding20Size, NULL, &status);
    checkErr(status, "clCreateBuffer for pSrc_padding2");
    int pBufL_cp0Size = sizeof(unsigned char) * width * height;
    cl_mem pBufL_cp0Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, pBufL_cp0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for pBufL_cp");

    //copyin buffers to GPU according to data pragma
    status = clEnqueueWriteBuffer(queue, Source0Buffer, CL_TRUE, 0, Source0Size, Source, 0, NULL, NULL);
    checkErr(status, "clEnqueueWriteBuffer for Source");

    #pragma cap data copyin(Source[0:width * height]) create(FilterDst[0:width * height], pSrc_padding[0:(width + 4) * (height + 4)], pSrc_padding2[0:(width + 4) * (height + 4)], pBufL_cp[0:width * height]) copyout(LaplacianLayer[0:width * height]) 
      {
        gettimeofday(&start_cpu[1], __null);
                //create the kernel
        cl_kernel kernel_1 = clCreateKernel(program, "kernel_1", &status);
        checkErr(status, "clCreateKernel for kernel_1");

        //set thread/thread-block size
        size_t localWorkSize1[3]= {1, 1, 1};
        size_t blockWorkSize1[3]= {1, 1, 1};
        size_t globalWorkSize1[3]= {1, 1, 1};
        blockWorkSize1[0] = height + 2 - (2);
        localWorkSize1[0] = 256;
        globalWorkSize1[0] = blockWorkSize1[0] * localWorkSize1[0];
        //set kernel parameters
        status = clSetKernelArg(kernel_1, 0, sizeof(cl_mem), (void *)&pSrc_padding0Buffer);
        checkErr(status, "clSetKernelArg for 0");
        status = clSetKernelArg(kernel_1, 1, sizeof(int), (void *)&height);
        checkErr(status, "clSetKernelArg for 1");
        status = clSetKernelArg(kernel_1, 2, sizeof(int), (void *)&width);
        checkErr(status, "clSetKernelArg for 2");
        status = clSetKernelArg(kernel_1, 3, sizeof(cl_mem), (void *)&Source0Buffer);
        checkErr(status, "clSetKernelArg for 3");

        //launch a kernel
        status = clEnqueueNDRangeKernel(queue, kernel_1, 1, NULL, globalWorkSize1, localWorkSize1, 0, NULL, NULL);
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
        localWorkSize2[1] = 8;
        blockWorkSize2[1] = upMultiple( height, 8 );
        localWorkSize2[0] = 32;
        blockWorkSize2[0] = upMultiple( width, 32 );
        globalWorkSize2[0] = blockWorkSize2[0] * localWorkSize2[0];
        globalWorkSize2[1] = blockWorkSize2[1] * localWorkSize2[1];
        //set kernel parameters
        status = clSetKernelArg(kernel_2, 0, sizeof(cl_mem), (void *)&pBufL_cp0Buffer);
        checkErr(status, "clSetKernelArg for 0");
        status = clSetKernelArg(kernel_2, 1, sizeof(int), (void *)&height);
        checkErr(status, "clSetKernelArg for 1");
        status = clSetKernelArg(kernel_2, 2, sizeof(int), (void *)&width);
        checkErr(status, "clSetKernelArg for 2");
        status = clSetKernelArg(kernel_2, 3, sizeof(cl_mem), (void *)&pSrc_padding0Buffer);
        checkErr(status, "clSetKernelArg for 3");

        //launch a kernel
        status = clEnqueueNDRangeKernel(queue, kernel_2, 2, NULL, globalWorkSize2, localWorkSize2, 0, NULL, NULL);
        checkErr(status, "clEnqueueNDRangeKernel for kernel_2");

        //wait until kernel finish
        status = clFinish(queue);
        checkErr(status, "clFinish for kernel_2");

        //release kernel
        clReleaseKernel(kernel_2);
        gettimeofday(&end_cpu[2], __null);
        gettimeofday(&start_cpu[3], __null);
                //create the kernel
        cl_kernel kernel_3 = clCreateKernel(program, "kernel_3", &status);
        checkErr(status, "clCreateKernel for kernel_3");

        //set thread/thread-block size
        size_t localWorkSize3[3]= {1, 1, 1};
        size_t blockWorkSize3[3]= {1, 1, 1};
        size_t globalWorkSize3[3]= {1, 1, 1};
        localWorkSize3[1] = 8;
        blockWorkSize3[1] = upMultiple( height + 2 - (2), 8 );
        localWorkSize3[0] = 32;
        blockWorkSize3[0] = upMultiple( width, 32 );
        globalWorkSize3[0] = blockWorkSize3[0] * localWorkSize3[0];
        globalWorkSize3[1] = blockWorkSize3[1] * localWorkSize3[1];
        //set kernel parameters
        status = clSetKernelArg(kernel_3, 0, sizeof(cl_mem), (void *)&pSrc_padding20Buffer);
        checkErr(status, "clSetKernelArg for 0");
        status = clSetKernelArg(kernel_3, 1, sizeof(int), (void *)&height);
        checkErr(status, "clSetKernelArg for 1");
        status = clSetKernelArg(kernel_3, 2, sizeof(int), (void *)&width);
        checkErr(status, "clSetKernelArg for 2");
        status = clSetKernelArg(kernel_3, 3, sizeof(cl_mem), (void *)&pBufL_cp0Buffer);
        checkErr(status, "clSetKernelArg for 3");

        //launch a kernel
        status = clEnqueueNDRangeKernel(queue, kernel_3, 2, NULL, globalWorkSize3, localWorkSize3, 0, NULL, NULL);
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
        blockWorkSize4[0] = upMultiple( (width + 2) - (2), 256 );
        globalWorkSize4[0] = blockWorkSize4[0] * localWorkSize4[0];
        //set kernel parameters
        status = clSetKernelArg(kernel_4, 0, sizeof(cl_mem), (void *)&pSrc_padding20Buffer);
        checkErr(status, "clSetKernelArg for 0");
        status = clSetKernelArg(kernel_4, 1, sizeof(int), (void *)&height);
        checkErr(status, "clSetKernelArg for 1");
        status = clSetKernelArg(kernel_4, 2, sizeof(int), (void *)&width);
        checkErr(status, "clSetKernelArg for 2");
        status = clSetKernelArg(kernel_4, 3, sizeof(cl_mem), (void *)&pBufL_cp0Buffer);
        checkErr(status, "clSetKernelArg for 3");

        //launch a kernel
        status = clEnqueueNDRangeKernel(queue, kernel_4, 1, NULL, globalWorkSize4, localWorkSize4, 0, NULL, NULL);
        checkErr(status, "clEnqueueNDRangeKernel for kernel_4");

        //wait until kernel finish
        status = clFinish(queue);
        checkErr(status, "clFinish for kernel_4");

        //release kernel
        clReleaseKernel(kernel_4);
        gettimeofday(&end_cpu[3], __null);
        gettimeofday(&start_cpu[4], __null);
                //create the kernel
        cl_kernel kernel_5 = clCreateKernel(program, "kernel_5", &status);
        checkErr(status, "clCreateKernel for kernel_5");

        //set thread/thread-block size
        size_t localWorkSize5[3]= {1, 1, 1};
        size_t blockWorkSize5[3]= {1, 1, 1};
        size_t globalWorkSize5[3]= {1, 1, 1};
        localWorkSize5[0] = 32;
        blockWorkSize5[0] = upMultiple( width, 32 );
        localWorkSize5[1] = 8;
        blockWorkSize5[1] = upMultiple( height, 8 );
        globalWorkSize5[0] = blockWorkSize5[0] * localWorkSize5[0];
        globalWorkSize5[1] = blockWorkSize5[1] * localWorkSize5[1];
        //set kernel parameters
        status = clSetKernelArg(kernel_5, 0, sizeof(cl_mem), (void *)&FilterDst0Buffer);
        checkErr(status, "clSetKernelArg for 0");
        status = clSetKernelArg(kernel_5, 1, sizeof(int), (void *)&height);
        checkErr(status, "clSetKernelArg for 1");
        status = clSetKernelArg(kernel_5, 2, sizeof(int), (void *)&width);
        checkErr(status, "clSetKernelArg for 2");
        status = clSetKernelArg(kernel_5, 3, sizeof(cl_mem), (void *)&pSrc_padding20Buffer);
        checkErr(status, "clSetKernelArg for 3");

        //launch a kernel
        status = clEnqueueNDRangeKernel(queue, kernel_5, 2, NULL, globalWorkSize5, localWorkSize5, 0, NULL, NULL);
        checkErr(status, "clEnqueueNDRangeKernel for kernel_5");

        //wait until kernel finish
        status = clFinish(queue);
        checkErr(status, "clFinish for kernel_5");

        //release kernel
        clReleaseKernel(kernel_5);
        gettimeofday(&end_cpu[4], __null);
        gettimeofday(&start_cpu[5], __null);
                //create buffers on GPU according to data pragma
        int DownsampleDst1Size = sizeof(unsigned char) * halfHeight * halfWidth;
        cl_mem DownsampleDst1Buffer = clCreateBuffer(context, CL_MEM_WRITE_ONLY, DownsampleDst1Size, NULL, &status);
        checkErr(status, "clCreateBuffer for DownsampleDst");

        //copyin buffers to GPU according to data pragma

        #pragma cap data copyout(DownsampleDst[0:halfHeight * halfWidth]) 
          {
                        //create the kernel
            cl_kernel kernel_6 = clCreateKernel(program, "kernel_6", &status);
            checkErr(status, "clCreateKernel for kernel_6");

            //set thread/thread-block size
            size_t localWorkSize6[3]= {1, 1, 1};
            size_t blockWorkSize6[3]= {1, 1, 1};
            size_t globalWorkSize6[3]= {1, 1, 1};
            localWorkSize6[1] = 8;
            blockWorkSize6[1] = upMultiple( halfHeight, 8 );
            localWorkSize6[0] = 32;
            blockWorkSize6[0] = upMultiple( halfWidth, 32 );
            globalWorkSize6[0] = blockWorkSize6[0] * localWorkSize6[0];
            globalWorkSize6[1] = blockWorkSize6[1] * localWorkSize6[1];
            //set kernel parameters
            status = clSetKernelArg(kernel_6, 0, sizeof(cl_mem), (void *)&DownsampleDst1Buffer);
            checkErr(status, "clSetKernelArg for 0");
            status = clSetKernelArg(kernel_6, 1, sizeof(int), (void *)&width);
            checkErr(status, "clSetKernelArg for 1");
            status = clSetKernelArg(kernel_6, 2, sizeof(int), (void *)&halfWidth);
            checkErr(status, "clSetKernelArg for 2");
            status = clSetKernelArg(kernel_6, 3, sizeof(int), (void *)&halfHeight);
            checkErr(status, "clSetKernelArg for 3");
            status = clSetKernelArg(kernel_6, 4, sizeof(cl_mem), (void *)&FilterDst0Buffer);
            checkErr(status, "clSetKernelArg for 4");

            //launch a kernel
            status = clEnqueueNDRangeKernel(queue, kernel_6, 2, NULL, globalWorkSize6, localWorkSize6, 0, NULL, NULL);
            checkErr(status, "clEnqueueNDRangeKernel for kernel_6");

            //wait until kernel finish
            status = clFinish(queue);
            checkErr(status, "clFinish for kernel_6");

            //release kernel
            clReleaseKernel(kernel_6);
          }
        //copyout buffers to CPU acccording to data pragma
        status = clEnqueueReadBuffer(queue, DownsampleDst1Buffer, CL_TRUE, 0, DownsampleDst1Size, DownsampleDst, 0, NULL, NULL);
        checkErr(status, "clEnqueueReadBuffer for DownsampleDst");

        //release buffers
        clReleaseMemObject(DownsampleDst1Buffer);

        gettimeofday(&end_cpu[5], __null);
        gettimeofday(&start_cpu[6], __null);
        UpsampleDst[(height - 1) * width + 0] = DownsampleDst[(halfHeight - 1) * halfWidth + 0];
        UpsampleDst[(height - 1) * width + width - 1] = DownsampleDst[(halfHeight - 1) * halfWidth + halfWidth - 1];
        UpsampleDst[(0) * width + width - 1] = DownsampleDst[(0) * halfWidth + halfWidth - 1];
        UpsampleDst[(0) * width + 0] = DownsampleDst[(0) * halfWidth + 0];
                //create buffers on GPU according to data pragma
        int DownsampleDst2Size = sizeof(unsigned char) * halfHeight * halfWidth;
        cl_mem DownsampleDst2Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, DownsampleDst2Size, NULL, &status);
        checkErr(status, "clCreateBuffer for DownsampleDst");
        int UpsampleDst2Size = sizeof(unsigned char) * width * height;
        cl_mem UpsampleDst2Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, UpsampleDst2Size, NULL, &status);
        checkErr(status, "clCreateBuffer for UpsampleDst");

        //copyin buffers to GPU according to data pragma
        status = clEnqueueWriteBuffer(queue, DownsampleDst2Buffer, CL_TRUE, 0, DownsampleDst2Size, DownsampleDst, 0, NULL, NULL);
        checkErr(status, "clEnqueueWriteBuffer for DownsampleDst");
        status = clEnqueueWriteBuffer(queue, UpsampleDst2Buffer, CL_TRUE, 0, UpsampleDst2Size, UpsampleDst, 0, NULL, NULL);
        checkErr(status, "clEnqueueWriteBuffer for UpsampleDst");

        #pragma cap data copyin(DownsampleDst[0:halfHeight * halfWidth], UpsampleDst[0:width * height]) 
          {
                        //create the kernel
            cl_kernel kernel_7 = clCreateKernel(program, "kernel_7", &status);
            checkErr(status, "clCreateKernel for kernel_7");

            //set thread/thread-block size
            size_t localWorkSize7[3]= {1, 1, 1};
            size_t blockWorkSize7[3]= {1, 1, 1};
            size_t globalWorkSize7[3]= {1, 1, 1};
            localWorkSize7[0] = 256;
            blockWorkSize7[0] = upMultiple( halfWidth - (1), 256 );
            globalWorkSize7[0] = blockWorkSize7[0] * localWorkSize7[0];
            //set kernel parameters
            status = clSetKernelArg(kernel_7, 0, sizeof(cl_mem), (void *)&UpsampleDst2Buffer);
            checkErr(status, "clSetKernelArg for 0");
            status = clSetKernelArg(kernel_7, 1, sizeof(int), (void *)&height);
            checkErr(status, "clSetKernelArg for 1");
            status = clSetKernelArg(kernel_7, 2, sizeof(int), (void *)&width);
            checkErr(status, "clSetKernelArg for 2");
            status = clSetKernelArg(kernel_7, 3, sizeof(int), (void *)&halfWidth);
            checkErr(status, "clSetKernelArg for 3");
            status = clSetKernelArg(kernel_7, 4, sizeof(int), (void *)&halfHeight);
            checkErr(status, "clSetKernelArg for 4");
            status = clSetKernelArg(kernel_7, 5, sizeof(cl_mem), (void *)&DownsampleDst2Buffer);
            checkErr(status, "clSetKernelArg for 5");

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
            localWorkSize8[1] = 8;
            blockWorkSize8[1] = upMultiple( (0 - (halfHeight - 1)) * -1, 8 );
            localWorkSize8[0] = 32;
            blockWorkSize8[0] = upMultiple( halfWidth - (1), 32 );
            globalWorkSize8[0] = blockWorkSize8[0] * localWorkSize8[0];
            globalWorkSize8[1] = blockWorkSize8[1] * localWorkSize8[1];
            //set kernel parameters
            status = clSetKernelArg(kernel_8, 0, sizeof(cl_mem), (void *)&UpsampleDst2Buffer);
            checkErr(status, "clSetKernelArg for 0");
            status = clSetKernelArg(kernel_8, 1, sizeof(int), (void *)&width);
            checkErr(status, "clSetKernelArg for 1");
            status = clSetKernelArg(kernel_8, 2, sizeof(int), (void *)&halfWidth);
            checkErr(status, "clSetKernelArg for 2");
            status = clSetKernelArg(kernel_8, 3, sizeof(int), (void *)&halfHeight);
            checkErr(status, "clSetKernelArg for 3");
            status = clSetKernelArg(kernel_8, 4, sizeof(cl_mem), (void *)&DownsampleDst2Buffer);
            checkErr(status, "clSetKernelArg for 4");

            //launch a kernel
            status = clEnqueueNDRangeKernel(queue, kernel_8, 2, NULL, globalWorkSize8, localWorkSize8, 0, NULL, NULL);
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
            blockWorkSize9[0] = upMultiple( (0 - (halfWidth - 1)) * -1, 256 );
            globalWorkSize9[0] = blockWorkSize9[0] * localWorkSize9[0];
            //set kernel parameters
            status = clSetKernelArg(kernel_9, 0, sizeof(cl_mem), (void *)&UpsampleDst2Buffer);
            checkErr(status, "clSetKernelArg for 0");
            status = clSetKernelArg(kernel_9, 1, sizeof(int), (void *)&width);
            checkErr(status, "clSetKernelArg for 1");
            status = clSetKernelArg(kernel_9, 2, sizeof(int), (void *)&halfWidth);
            checkErr(status, "clSetKernelArg for 2");
            status = clSetKernelArg(kernel_9, 3, sizeof(cl_mem), (void *)&DownsampleDst2Buffer);
            checkErr(status, "clSetKernelArg for 3");

            //launch a kernel
            status = clEnqueueNDRangeKernel(queue, kernel_9, 1, NULL, globalWorkSize9, localWorkSize9, 0, NULL, NULL);
            checkErr(status, "clEnqueueNDRangeKernel for kernel_9");

            //wait until kernel finish
            status = clFinish(queue);
            checkErr(status, "clFinish for kernel_9");

            //release kernel
            clReleaseKernel(kernel_9);
            gettimeofday(&end_cpu[6], __null);
            gettimeofday(&start_cpu[7], __null);
                        //create the kernel
            cl_kernel kernel_10 = clCreateKernel(program, "kernel_10", &status);
            checkErr(status, "clCreateKernel for kernel_10");

            //set thread/thread-block size
            size_t localWorkSize10[3]= {1, 1, 1};
            size_t blockWorkSize10[3]= {1, 1, 1};
            size_t globalWorkSize10[3]= {1, 1, 1};
            localWorkSize10[1] = 8;
            blockWorkSize10[1] = upMultiple( height, 8 );
            localWorkSize10[0] = 32;
            blockWorkSize10[0] = upMultiple( width, 32 );
            globalWorkSize10[0] = blockWorkSize10[0] * localWorkSize10[0];
            globalWorkSize10[1] = blockWorkSize10[1] * localWorkSize10[1];
            //set kernel parameters
            status = clSetKernelArg(kernel_10, 0, sizeof(cl_mem), (void *)&LaplacianLayer0Buffer);
            checkErr(status, "clSetKernelArg for 0");
            status = clSetKernelArg(kernel_10, 1, sizeof(int), (void *)&height);
            checkErr(status, "clSetKernelArg for 1");
            status = clSetKernelArg(kernel_10, 2, sizeof(int), (void *)&width);
            checkErr(status, "clSetKernelArg for 2");
            status = clSetKernelArg(kernel_10, 3, sizeof(cl_mem), (void *)&Source0Buffer);
            checkErr(status, "clSetKernelArg for 3");
            status = clSetKernelArg(kernel_10, 4, sizeof(cl_mem), (void *)&UpsampleDst2Buffer);
            checkErr(status, "clSetKernelArg for 4");

            //launch a kernel
            status = clEnqueueNDRangeKernel(queue, kernel_10, 2, NULL, globalWorkSize10, localWorkSize10, 0, NULL, NULL);
            checkErr(status, "clEnqueueNDRangeKernel for kernel_10");

            //wait until kernel finish
            status = clFinish(queue);
            checkErr(status, "clFinish for kernel_10");

            //release kernel
            clReleaseKernel(kernel_10);
          }
        //copyout buffers to CPU acccording to data pragma

        //release buffers
        clReleaseMemObject(DownsampleDst2Buffer);
        clReleaseMemObject(UpsampleDst2Buffer);

        gettimeofday(&end_cpu[7], __null);
      }
    //copyout buffers to CPU acccording to data pragma
    status = clEnqueueReadBuffer(queue, LaplacianLayer0Buffer, CL_TRUE, 0, LaplacianLayer0Size, LaplacianLayer, 0, NULL, NULL);
    checkErr(status, "clEnqueueReadBuffer for LaplacianLayer");

    //release buffers
    clReleaseMemObject(Source0Buffer);
    clReleaseMemObject(FilterDst0Buffer);
    clReleaseMemObject(LaplacianLayer0Buffer);
    clReleaseMemObject(pSrc_padding0Buffer);
    clReleaseMemObject(pSrc_padding20Buffer);
    clReleaseMemObject(pBufL_cp0Buffer);

    gettimeofday(&end_cpu[0], __null);
    printf("%d\n", LaplacianLayer[10 * width + 100]);
    printf("laplacian: %dx%d\n", height, width);
    for (int i = 0; i < 8; i++) {
      double duration_cpu = 1000 * ((end_cpu[i]).tv_sec - (start_cpu[i]).tv_sec) + ((end_cpu[i]).tv_usec - (start_cpu[i]).tv_usec) / 1000.;
      if (i == 0)
        printf("Total: ");
      else if (i == 1)
        printf("Row_padding: ");
      else if (i == 2)
        printf("Row_filter: ");
      else if (i == 3)
        printf("Column_padding: ");
      else if (i == 4)
        printf("Column_filter: ");
      else if (i == 5)
        printf("DownSample: ");
      else if (i == 6)
        printf("UpSample: ");
      else if (i == 7)
        printf("Cut: ");
      printf("%.2f ms\n", duration_cpu);
    }
    printf("\n");
  }
  for (int h = 2; h < height + 2; h++) {
    pSrc_padding[h * (width + 4) + 1] = 2 * Source[(h - 2) * width + 1] - 1 * Source[(h - 2) * width + 3];
    pSrc_padding[h * (width + 4) + 0] = 4 * Source[(h - 2) * width + 3] - 4 * Source[(h - 2) * width + 1] + 2 * Source[(h - 2) * width + 0] - 1 * Source[(h - 2) * width + 2];
    pSrc_padding[h * (width + 4) + width + 2] = 2 * Source[(h - 2) * width + width - 2] - 1 * Source[(h - 2) * width + width - 4];
    pSrc_padding[h * (width + 4) + width + 3] = 4 * Source[(h - 2) * width + width - 4] - 4 * Source[(h - 2) * width + width - 2] + 2 * Source[(h - 2) * width + width - 1] - 1 * Source[(h - 2) * width + width - 3];
    for (int w = 0; w < width; w++) 
      pSrc_padding[h * (width + 4) + w + 2] = Source[(h - 2) * width + w];
  }
  for (int h = 0; h < height; h++) 
    for (int w = 0; w < width; w++) 
      pBufL_cp[h * width + w] = (pSrc_padding[(h + 2) * (width + 4) + w] + (pSrc_padding[(h + 2) * (width + 4) + w + 1] << 2) + 6 * pSrc_padding[(h + 2) * (width + 4) + (w + 2)] + (pSrc_padding[(h + 2) * (width + 4) + (w + 3)] << 2) + pSrc_padding[(h + 2) * (width + 4) + (w + 4)] + 8) >> 4;
  for (int h = 2; h < height + 2; h++) {
    for (int w = 0; w < width; w++) 
      pSrc_padding[h * (width + 4) + w + 2] = pBufL_cp[(h - 2) * width + w];
  }
  for (int w = 2; w < (width + 2); w++) {
    pSrc_padding[1 * (width + 4) + w] = 2 * pBufL_cp[1 * width + w - 2] - 1 * pBufL_cp[3 * width + w - 2];
    pSrc_padding[0 * (width + 4) + w] = 4 * pBufL_cp[3 * width + w - 2] - 4 * pBufL_cp[1 * width + w - 2] + 2 * pBufL_cp[0 * width + w - 2] - 1 * pBufL_cp[2 * width + w - 2];
    pSrc_padding[(height + 2) * (width + 4) + w] = 2 * pBufL_cp[(height - 2) * width + w - 2] - 1 * pBufL_cp[(height - 4) * width + w - 2];
    pSrc_padding[(height + 3) * (width + 4) + w] = 4 * pBufL_cp[(height - 4) * width + w - 2] - 4 * pBufL_cp[(height - 2) * width + w - 2] + 2 * pBufL_cp[(height - 1) * width + w - 2] - 1 * pBufL_cp[(height - 3) * width + w - 2];
  }
  for (int w = 0; w < width; w++) 
    for (int h = 0; h < height; h++) {
      FilterDst[h * width + w] = (pSrc_padding[(h) * (width + 4) + (w + 2)] + (pSrc_padding[(h + 1) * (width + 4) + (w + 2)] << 2) + 6 * pSrc_padding[(h + 2) * (width + 4) + (w + 2)] + (pSrc_padding[(h + 3) * (width + 4) + (w + 2)] << 2) + pSrc_padding[(h + 4) * (width + 4) + (w + 2)] + 8) >> 4;
    }
  for (int y = 0; y < halfHeight; y++) {
    for (int x = 0; x < halfWidth; x++) {
      DownsampleDst[y * halfWidth + x] = FilterDst[(y << 1) * width + (x << 1)];
    }
  }
  UpsampleDst[(height - 1) * width + 0] = DownsampleDst[(halfHeight - 1) * halfWidth + 0];
  UpsampleDst[(height - 1) * width + width - 1] = DownsampleDst[(halfHeight - 1) * halfWidth + halfWidth - 1];
  UpsampleDst[(0) * width + width - 1] = DownsampleDst[(0) * halfWidth + halfWidth - 1];
  UpsampleDst[(0) * width + 0] = DownsampleDst[(0) * halfWidth + 0];
  for (int x = 1; x < halfWidth; x++) {
    UpsampleDst[(height - 1) * width + 2 * x - 1] = (DownsampleDst[(halfHeight - 1) * halfWidth + x - 1] + DownsampleDst[(halfHeight - 1) * halfWidth + x] + 1) >> 1;
    UpsampleDst[(height - 1) * width + 2 * x] = DownsampleDst[(halfHeight - 1) * halfWidth + x];
  }
  for (int y = halfHeight - 1; y > 0; y--) {
    for (int x = 1; x < halfWidth; x++) {
      UpsampleDst[(2 * y - 1) * width + 2 * x - 1] = (DownsampleDst[(y) * halfWidth + x - 1] + DownsampleDst[(y) * halfWidth + x] + DownsampleDst[(y - 1) * halfWidth + x - 1] + DownsampleDst[(y - 1) * halfWidth + x] + 2) >> 2;
      UpsampleDst[(2 * y - 1) * width + 2 * x] = (DownsampleDst[(y) * halfWidth + x] + DownsampleDst[(y - 1) * halfWidth + x] + 1) >> 1;
      UpsampleDst[(2 * y) * width + 2 * x - 1] = (DownsampleDst[(y) * halfWidth + x - 1] + DownsampleDst[(y) * halfWidth + x] + 1) >> 1;
      UpsampleDst[(2 * y) * width + 2 * x] = DownsampleDst[(y) * halfWidth + x];
    }
    UpsampleDst[(2 * y - 1) * width + width - 1] = (DownsampleDst[(y) * halfWidth + halfWidth - 1] + DownsampleDst[(y - 1) * halfWidth + halfWidth - 1] + 1) >> 1;
    UpsampleDst[(2 * y) * width + width - 1] = DownsampleDst[(y) * halfWidth + halfWidth - 1];
    UpsampleDst[(2 * y - 1) * width + 0] = (DownsampleDst[(y) * halfWidth + 0] + DownsampleDst[(y - 1) * halfWidth + 0] + 1) >> 1;
    UpsampleDst[(2 * y) * width + 0] = DownsampleDst[(y) * halfWidth + 0];
  }
  for (int x = halfWidth - 1; x > 0; x--) {
    UpsampleDst[(0) * width + 2 * x] = DownsampleDst[(0) * halfWidth + x];
    UpsampleDst[(0) * width + 2 * x - 1] = ((int)DownsampleDst[(0) * halfWidth + x - 1] + DownsampleDst[(0) * halfWidth + x] + 1) / 2;
  }
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      LaplacianLayer_CPU[y * width + x] = (short)(Source[y * width + x]) - (short)(UpsampleDst[y * width + x]);
    }
  }
  bool error = false;
  for (int h = 0; h < height; h++) {
    for (int w = 0; w < width; w++) {
      if (abs(LaplacianLayer_CPU[h * width + w] - LaplacianLayer[h * width + w]) > 1) {
        error = true;
        printf("CPU:%d GPU:%d\n", LaplacianLayer_CPU[h * width + w], LaplacianLayer[h * width + w]);
      }
    }
  }
  if (error)
    printf("Error\n");
  else
    printf("OK\n");
  free(Source);
  free(FilterDst);
  free(DownsampleDst);
  free(LaplacianLayer_CPU);
  free(LaplacianLayer);
  free(pSrc_padding);
  free(UpsampleDst);
  free(pBufL_cp);
  return 0;
}

int main(int argc, char **argv) {
  // Create environment variables before the first data transfer.
  const char *inputFile = "laplacian-cap.cl";

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



