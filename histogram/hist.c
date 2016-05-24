/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

#include"CL/cl.h"
#include"ClHost.h"
#include<stdio.h>
#include<stdlib.h>

#define M 256 
#define N 256

#define P 256 // # of bin for histogram.

void hist(unsigned char (*in)[256][256], short (*out)[256]) {
  
  {
    size_t global_work_size[2];
    size_t transe;
    cl_event event_kernel;
    cl_kernel kernel_1 = clCreateKernel(g_program, "kernel_1", &status);
    checkErr(status, "clCreateKernel for kernel_1");
    global_work_size[0] = 256;
    global_work_size[1] = 256;
    size_t inSrcWidth = 256;
    size_t inSrcHeight = 256;
    size_t in_srcsz = sizeof(unsigned char);
    size_t inSrcStep = inSrcWidth * in_srcsz;
    inSrcStep = (inSrcStep % PADDING < 16) ? ((inSrcStep / PADDING+1) * PADDING) : ((inSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t inSrcShift = inSrcStep * PADDING_LINE;
    size_t in_srcsz0Pad = inSrcStep * (inSrcHeight + (PADDING_LINE<<1));
    cl_mem insrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, in_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    unsigned char *inSrcBufH = (unsigned char*)malloc(in_srcsz0Pad); 
    for(int i = 0; i < inSrcHeight; i++){
  memcpy( (char*)inSrcBufH+ (i + PADDING_LINE) * inSrcStep, (char*)in+ i * inSrcWidth* sizeof(unsigned char), inSrcWidth * sizeof(unsigned char) );
  }
    status = clEnqueueWriteBuffer(g_queue, insrcBuf, CL_TRUE, 0,in_srcsz0Pad,inSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_1, 0, sizeof(cl_mem), (void *)&insrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 1, sizeof(int), (void *)&inSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 2, sizeof(int), (void *)&inSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 3, sizeof(int), (void *)&inSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 4, sizeof(int), (void *)&inSrcShift);
    checkErr(status, "clSetKernelArg");
    status = clEnqueueNDRangeKernel(g_queue, kernel_1, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
    checkErr(status, "clEnqueueNDRangeKernel");
    status = clFinish(g_queue);
    checkErr(status,"clFinish of kernel_1");
    
  }
  return;
}




int main() {
  char inputfile[] = "hist.cl";
  char *remain = NULL;
  if (-1 == openCLCreate(inputfile, remain)) {
    printf("openCL create fail !!!!!!");
    return 0;
  }
  int i, j;
  unsigned char *input = (unsigned char *)malloc(sizeof(unsigned char) * 256 * 256);
  short *output = (short *)malloc(sizeof(short) * 256);
  for (i = 0; i < 256; i++) 
    for (j = 0; j < 256; j++) {
      input[i * 256 + j] = rand() % 256;
    }
  unsigned char (*inputMat)[256][256] = (unsigned char (*)[256][256])input;
 // short (*outputVec)[P2] = (short(*)[P2])output;
  short (*outputVec)[256] = (short (*)[256]) output;
  hist(inputMat, outputVec);
  return 0;
}


