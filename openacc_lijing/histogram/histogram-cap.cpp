/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

#include "ClHost.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<sys/time.h>
#include<iostream>
#include<fstream>
#define BYTE int
#define Niter 10
struct timeval start_cpu[10];
struct timeval end_cpu[10];

int host_main() {
  int w = 8192;
  int h = 8192;
  int *dstData = (int *)malloc(sizeof(int) * w * h);
  int *dstData_CPU = (int *)malloc(sizeof(int) * w * h);
  double *srcArray = (double *)malloc(sizeof(double) * 256);
  printf("----Hist(%d*%d)----\n", w, h);
  for (int ii = 0; ii < 10; ii++) {
    srand(0);
    for (int i = 0; i < h * w; i++) {
      dstData[i] = rand() % 256;
    }
    for (int i = 0; i < 256; i++) {
      srcArray[i] = rand() % 256;
    }
    double dstHist[256];
    memset(dstHist, 0, 256 * sizeof(double));
    double dstArray[256];
    memset(dstArray, 0, 256 * sizeof(double));
    {
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          int k = dstData[i * w + j];
          dstHist[k]++;
        }
      }
    }
    double m_Bytes = w * h;
    dstArray[0] = dstHist[0];
    for (int i = 1; i < 256; i++) {
      dstArray[i] = dstArray[i - 1] + dstHist[i];
    }
    for (int i = 0; i < 256; i++) {
      dstArray[i] /= m_Bytes;
    }
    double m_diffA, m_diffB;
    int k = 0;
    int mapPixel[256];
    memset(mapPixel, 0, 256 * sizeof(int));
    for (int i = 0; i < 256; i++) {
      m_diffB = 1;
      for (int j = k; j < 256; j++) {
        m_diffA = fabs(dstArray[i] - srcArray[j]);
        if (m_diffA - m_diffB < 1.0000000000000001E-5) {
          m_diffB = m_diffA;
          k = j;
        } else {
          k = j - 1;
          break;
        }
      }
      if (k == 255) {
        for (int l = i; l < 256; l++) {
          mapPixel[l] = (int)k;
        }
        break;
      }
      mapPixel[i] = (int)k;
    }
    gettimeofday(&start_cpu[ii], __null);
        //create buffers on GPU according to data pragma
    int dstData0Size = sizeof(int) * w * h;
    cl_mem dstData0Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, dstData0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for dstData");
    int mapPixel0Size = sizeof(int) * 256;
    cl_mem mapPixel0Buffer = clCreateBuffer(context, CL_MEM_READ_ONLY, mapPixel0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for mapPixel");

    //copyin buffers to GPU according to data pragma
    status = clEnqueueWriteBuffer(queue, dstData0Buffer, CL_TRUE, 0, dstData0Size, dstData, 0, NULL, NULL);
    checkErr(status, "clEnqueueWriteBuffer for dstData");
    status = clEnqueueWriteBuffer(queue, mapPixel0Buffer, CL_TRUE, 0, mapPixel0Size, mapPixel, 0, NULL, NULL);
    checkErr(status, "clEnqueueWriteBuffer for mapPixel");

    #pragma cap data copy(dstData[0:w * h]) copyin(mapPixel[0:256]) 
      {
                //create the kernel
        cl_kernel kernel_1 = clCreateKernel(program, "kernel_1", &status);
        checkErr(status, "clCreateKernel for kernel_1");

        //set thread/thread-block size
        size_t localWorkSize1[3]= {1, 1, 1};
        size_t blockWorkSize1[3]= {1, 1, 1};
        size_t globalWorkSize1[3]= {1, 1, 1};
        localWorkSize1[1] = 8;
        blockWorkSize1[1] = upMultiple( h, 8 );
        localWorkSize1[0] = 32;
        blockWorkSize1[0] = upMultiple( w, 32 );
        globalWorkSize1[0] = blockWorkSize1[0] * localWorkSize1[0];
        globalWorkSize1[1] = blockWorkSize1[1] * localWorkSize1[1];
        //set kernel parameters
        status = clSetKernelArg(kernel_1, 0, sizeof(int), (void *)&w);
        checkErr(status, "clSetKernelArg for 0");
        status = clSetKernelArg(kernel_1, 1, sizeof(int), (void *)&h);
        checkErr(status, "clSetKernelArg for 1");
        status = clSetKernelArg(kernel_1, 2, sizeof(cl_mem), (void *)&mapPixel0Buffer);
        checkErr(status, "clSetKernelArg for 2");
        status = clSetKernelArg(kernel_1, 3, sizeof(cl_mem), (void *)&dstData0Buffer);
        checkErr(status, "clSetKernelArg for 3");

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
    status = clEnqueueReadBuffer(queue, dstData0Buffer, CL_TRUE, 0, dstData0Size, dstData, 0, NULL, NULL);
    checkErr(status, "clEnqueueReadBuffer for dstData");

    //release buffers
    clReleaseMemObject(dstData0Buffer);
    clReleaseMemObject(mapPixel0Buffer);

    gettimeofday(&end_cpu[ii], __null);
    printf("%d\n", dstData[0]);
  }
  for (int i = 0; i < 10; i++) {
    double duration_cpu = 1000 * ((end_cpu[i]).tv_sec - (start_cpu[i]).tv_sec) + ((end_cpu[i]).tv_usec - (start_cpu[i]).tv_usec) / 1000.;
    printf("Hist exe time OPENACC:\t%f ms\n", duration_cpu);
  }
  srand(0);
  for (int i = 0; i < h * w; i++) {
    dstData_CPU[i] = rand() % 256;
  }
  for (int i = 0; i < 256; i++) {
    srcArray[i] = rand() % 256;
  }
  double dstHist[256];
  memset(dstHist, 0, 256 * sizeof(double));
  double dstArray[256];
  memset(dstArray, 0, 256 * sizeof(double));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int k = dstData_CPU[i * w + j];
      dstHist[k]++;
    }
  }
  double m_Bytes = w * h;
  dstArray[0] = dstHist[0];
  for (int i = 1; i < 256; i++) {
    dstArray[i] = dstArray[i - 1] + dstHist[i];
  }
  for (int i = 0; i < 256; i++) {
    dstArray[i] /= m_Bytes;
  }
  double m_diffA, m_diffB;
  int k = 0;
  int mapPixel[256];
  memset(mapPixel, 0, 256 * sizeof(int));
  for (int i = 0; i < 256; i++) {
    m_diffB = 1;
    for (int j = k; j < 256; j++) {
      m_diffA = fabs(dstArray[i] - srcArray[j]);
      if (m_diffA - m_diffB < 1.0000000000000001E-5) {
        m_diffB = m_diffA;
        k = j;
      } else {
        k = j - 1;
        break;
      }
    }
    if (k == 255) {
      for (int l = i; l < 256; l++) {
        mapPixel[l] = (int)k;
      }
      break;
    }
    mapPixel[i] = (int)k;
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      dstData_CPU[i * w + j] = mapPixel[dstData_CPU[i * w + j]];
    }
  }
  bool correct = true;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (dstData_CPU[i * w + j] != dstData[i * w + j])
        correct = false;
    }
  }
  if (correct == false)
    printf("Error\n");
  else
    printf("OK\n");
  return 0;
}

int main() {
  // Create environment variables before the first data transfer.
  const char *inputFile = "histogram-cap.cl";

  if (-1 == openCLCreate(&context, &queue, &program, inputFile)) {
    printf("OpenCL create fail!\n");
    exit(-1);
  }

  int ret =  host_main();
  
  // Release environment vars.
  clReleaseProgram(program);
  clReleaseCommandQueue(queue);
  clReleaseContext(context);

  return ret;
}



