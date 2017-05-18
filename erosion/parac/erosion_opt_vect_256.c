/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

#include"CL/cl.h"
#include"ClHost.h"
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/time.h>

struct timeval ts1; struct timeval te1;
#define H 256
#define W 256

double totalTime;
ulong startTime, endTime;

void erosion(int height, int width, unsigned char (*src)[H][W], unsigned char (*dst)[H][W], int structWidth, int structHeight) {
  int mid = (structWidth + 1) / 2 - 1;
  unsigned char val = 255;

  {
    totalTime = 0.0;

    for( int k = 0; k < 10; k++){
    size_t global_work_size[2];
    size_t local_work_size[2];
    size_t transe;
    cl_event event_kernel;
    cl_kernel kernel_1 = clCreateKernel(g_program, "kernel_1", &status);
    checkErr(status, "clCreateKernel for kernel_1");
    global_work_size[0] = (width/4 - mid - 1 - mid )/ 1;
    global_work_size[1] = (height - mid - 1 - mid )/ 1;
    local_work_size[0] = 16;
    local_work_size[1] = 16;
    status = clSetKernelArg(kernel_1, 0, sizeof(int), (void *)&height);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 1, sizeof(int), (void *)&width);
    checkErr(status, "clSetKernelArg");
    size_t srcSrcWidth = W;
    size_t srcSrcHeight = H;
    size_t src_srcsz = sizeof(unsigned char);
    size_t srcSrcStep = srcSrcWidth * src_srcsz;
    srcSrcStep = (srcSrcStep % PADDING < 16) ? ((srcSrcStep / PADDING+1) * PADDING) : ((srcSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t srcSrcShift = srcSrcStep * PADDING_LINE;
    size_t src_srcsz0Pad = srcSrcStep * (srcSrcHeight + (PADDING_LINE<<1));
    cl_mem srcsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, src_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    unsigned char *srcSrcBufH = (unsigned char*)malloc(src_srcsz0Pad); 
    for(int i = 0; i < srcSrcHeight; i++){
      memcpy( (char*)srcSrcBufH+ (i + PADDING_LINE) * srcSrcStep, (char*)src+ i * srcSrcWidth* sizeof(unsigned char), srcSrcWidth * sizeof(unsigned char) );
    }
    status = clEnqueueWriteBuffer(g_queue, srcsrcBuf, CL_TRUE, 0,src_srcsz0Pad,srcSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_1, 2, sizeof(cl_mem), (void *)&srcsrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 3, sizeof(int), (void *)&srcSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 4, sizeof(int), (void *)&srcSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 5, sizeof(int), (void *)&srcSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 6, sizeof(int), (void *)&srcSrcShift);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 7, sizeof(int), (void *)&mid);
    checkErr(status, "clSetKernelArg");
    size_t dstDstWidth = W;
    size_t dstDstHeight = H;
    size_t dst_dstsz = sizeof(unsigned char);
    size_t dstDstStep = dstDstWidth * dst_dstsz;
    dstDstStep = (dstDstStep % PADDING < 16) ? ((dstDstStep / PADDING+1) * PADDING) : ((dstDstStep + PADDING) / PADDING+1) * PADDING;
    size_t dstDstShift = dstDstStep * PADDING_LINE;
    size_t dst_dstsz0Pad = dstDstStep * (dstDstHeight + (PADDING_LINE<<1));
    cl_mem dstdstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, dst_dstsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    unsigned char *dstDstBufH = (unsigned char*)malloc(dst_dstsz0Pad); 
    for(int i = 0; i < dstDstHeight; i++){
      memcpy( (char*)dstDstBufH+ (i + PADDING_LINE) * dstDstStep,(char*)dst + i * dstDstWidth* sizeof(unsigned char),dstDstWidth* sizeof(unsigned char) );
    }
    status = clEnqueueWriteBuffer(g_queue, dstdstBuf, CL_TRUE, 0,dst_dstsz0Pad,dstDstBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_1, 8, sizeof(cl_mem), (void *)&dstdstBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 9, sizeof(int), (void *)&dstDstWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 10, sizeof(int), (void *)&dstDstHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 11, sizeof(int), (void *)&dstDstStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 12, sizeof(int), (void *)&dstDstShift);
    checkErr(status, "clSetKernelArg");
    cl_mem valBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, sizeof(unsigned char), NULL, &status);
    checkErr(status,"clCreateBuffer");
    status = clEnqueueWriteBuffer(g_queue, valBuf, CL_TRUE, 0, sizeof(unsigned char), &val, 0, NULL, NULL);
    checkErr(status,"clEnqueueWrite");
    status = clSetKernelArg(kernel_1, 13, sizeof(cl_mem), (void *)&valBuf);
    checkErr(status, "clSetKernelArg");
    //status = clEnqueueNDRangeKernel(g_queue, kernel_1, 2, NULL, global_work_size, local_work_size, 0, NULL, &event_kernel);
    status = clEnqueueNDRangeKernel(g_queue, kernel_1, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
    checkErr(status, "clEnqueueNDRangeKernel");
    status = clFinish(g_queue);
    checkErr(status,"clFinish of kernel_1");

    // Time profiling.
    clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_START, sizeof(cl_ulong), &startTime, NULL);
    clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_END, sizeof(cl_ulong), &endTime, NULL);
    totalTime += (endTime - startTime)/1000000.0;


    status = clEnqueueReadBuffer(g_queue, valBuf, CL_TRUE, 0, sizeof(unsigned char), &val, 0, NULL, NULL);
    checkErr(status,"clEnqueueReadBuffer");
    status = clEnqueueReadBuffer(g_queue, dstdstBuf, CL_TRUE, 0,dst_dstsz0Pad,dstDstBufH, 0, NULL, NULL);
    for(int i = 0; i < dstDstHeight; i++){
      memcpy( (char*)dst+ i *dstDstWidth* sizeof(unsigned char), (char*) dstDstBufH+ (i + PADDING_LINE)* dstDstStep, dstDstWidth* sizeof(unsigned char) );
    }

    }
  }
}





int main(int argc, char *argv[]) {
  char inputfile[] = "erosion_opt_vect.cl";
  char *remain = NULL;
  if (-1 == openCLCreate(inputfile, remain)) {
    printf("openCL create fail !!!!!!");
    return 0;
  }
  if (argc < 3) {
    printf("Please input Height and Width \n");
    return 0;
  }
  int Height = atoi(argv[1]);
  int Width = atoi(argv[2]);
  Height = H;
  Width = W;
  unsigned char *src = (unsigned char *)malloc(sizeof(unsigned char) * Width * Height);
  unsigned char *dst = (unsigned char *)malloc(sizeof(unsigned char) * Width * Height);
  for (int i = 0; i < Height; i++) 
    for (int j = 0; j < Width; j++) {
      src[i * Width + j] = rand() % 255;
    }
  unsigned char (*parac_src)[H][W] = (unsigned char (*)[H][W])src;
  unsigned char (*parac_dst)[H][W] = (unsigned char (*)[H][W])dst;
  // warm up.
  erosion(Height, Width, parac_src, parac_dst, 3, 3);

  erosion(Height, Width, parac_src, parac_dst, 3, 3);

  printf("time = %f ms\n", totalTime/10);
  return 0;
}


