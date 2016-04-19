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
  unsigned char inputMat[256][256] = input;
  short outputVec[256] = output;
  hist(&inputMat, &outputVec);
  return 0;
}


