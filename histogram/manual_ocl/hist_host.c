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

void hist(unsigned char (*in)[256][256], int (*out)[256]) {
  
  
    size_t global_work_size[2];
    cl_event event_kernel;
    cl_kernel kernel_1 = clCreateKernel(g_program, "hist_atomic", &status);
    checkErr(status, "clCreateKernel for kernel_1");
    global_work_size[0] = 256;
    global_work_size[1] = 256;

    // Copy data from host to GPGPU.
   size_t Width = 256;
   size_t Height = 256;
   size_t SrcEleSize = sizeof( unsigned char );
   size_t Step = Width * SrcEleSize;
   Step = (Step % PADDING < 16)? ( (Step/PADDING+1)*PADDING):((Step+PADDING)/PADDING+1)*PADDING;
   size_t Shift = Step * PADDING_LINE;
   size_t SrcPad = Step *( Height + (PADDING_LINE<<1) );

   cl_mem  SrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, SrcPad, NULL, &status);
   checkErr(status, "clCreateBuffer");

   unsigned char *SrcBufPad = (unsigned char*) malloc (SrcPad);
   for( int i = 0; i < Height; ++i)
     memcpy( (char*)SrcBufPad + (i+PADDING_LINE)*Step, (char*)in +i*Width*SrcEleSize, Width*SrcEleSize );

  status = clEnqueueWriteBuffer(g_queue, SrcBuf, CL_TRUE, 0, SrcPad, SrcBufPad, 0, NULL, NULL);
   checkErr(status, "clEnqueueWriteBuffer");

   status = clSetKernelArg(kernel_1, 0, sizeof(cl_mem), (void*)&SrcBuf);
   checkErr(status, "clSetKernelArg");
   status = clSetKernelArg(kernel_1, 1, sizeof(int), (void*)&Width);
   checkErr(status, "clSetKernelArg");
   status = clSetKernelArg(kernel_1, 2, sizeof(int), (void*)&Height);
   checkErr(status, "clSetKernelArg");
   status = clSetKernelArg(kernel_1, 3, sizeof(int), (void*)&Step);
   checkErr(status, "clSetKernelArg");
   status = clSetKernelArg(kernel_1, 4, sizeof(int), (void*)&Shift);
   checkErr(status, "clSetKernelArg");

   printf("Finish parameter 1 \n");

   size_t DstWidth = 256;
   size_t DstHeight = 1;
   size_t DstEleSize = sizeof(int);
   size_t DstStep = DstWidth * DstEleSize;
   DstStep = (DstStep % PADDING < 16) ? ( (DstStep+PADDING / PADDING + 1) * PADDING) : ((DstStep+PADDING)/PADDING+1)*PADDING;

   size_t DstShift = DstStep * PADDING_LINE;
   size_t DstPadSize = DstStep * (DstHeight + (PADDING_LINE<<1));

   cl_mem DstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, DstPadSize, NULL, &status);
   checkErr(status, "clCreateBuffer");

  int *DstBufPad = (int*) malloc( DstPadSize);

 status = clSetKernelArg(kernel_1, 5, sizeof(cl_mem), (void*)&DstBuf);
   checkErr(status, "clSetKernelArg");
   status = clSetKernelArg(kernel_1, 6, sizeof(int), (void*)&DstWidth);
   checkErr(status, "clSetKernelArg");
   status = clSetKernelArg(kernel_1, 7, sizeof(int), (void*)&DstHeight);
   checkErr(status, "clSetKernelArg");
   status = clSetKernelArg(kernel_1, 8, sizeof(int), (void*)&DstStep);
   checkErr(status, "clSetKernelArg");
   status = clSetKernelArg(kernel_1, 9, sizeof(int), (void*)&DstShift);
   checkErr(status, "clSetKernelArg");


    //
    status = clEnqueueNDRangeKernel(g_queue, kernel_1, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
    checkErr(status, "clEnqueueNDRangeKernel");
    status = clFinish(g_queue);
    checkErr(status,"clFinish of kernel_1");

   printf("Finish kernel execution \n");

    status = clEnqueueReadBuffer(g_queue, DstBuf, CL_TRUE, 0, DstPadSize, (char*)DstBufPad, 0, NULL, NULL);    
    checkErr(status, "clEnqueueReadBuffer");
   printf("Finish ReadBuffer \n");

#if 1
   for( int i = 0; i < DstHeight; i++){
     memcpy((char*)out + i*DstWidth*DstEleSize, (char*)DstBufPad+(i*PADDING_LINE)*DstStep, DstWidth*DstEleSize);
   }
#endif

   printf("Finish copy data from device to host \n");
  
  return;
}




int main() {
  char inputfile[] = "hist_kernel.cl";
  char *remain = NULL;
  if (-1 == openCLCreate(inputfile, remain)) {
    printf("openCL create fail !!!!!!");
    return 0;
  }
  int i, j;
  unsigned char *input = (unsigned char *)malloc(sizeof(unsigned char) * 256 * 256);
  int *output = (int *)malloc(sizeof(int) * 256);
  for (i = 0; i < 256; i++) 
    for (j = 0; j < 256; j++) {
      input[i * 256 + j] = rand() % 256;
    }
  unsigned char (*inputMat)[256][256] = (unsigned char (*)[256][256])input;
  int (*outputVec)[256] = (int (*)[256])output;
  hist(inputMat, outputVec);
  return 0;
}


