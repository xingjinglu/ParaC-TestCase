/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

#include"CL/cl.h"
#include"ClHost.h"
#include <stdlib.h>

//#define ROWS 1024
//#define COLS 1024
//#define M 1024
//#define N 1024

#ifdef TIME_PROF
#define TIME_KERNEL
#define TIME_TOTAL
#endif

struct TEST_TIME{
  double exe_time;  
  double time_filter_h;
  double time_down;
  double time_up;
  double time_kernel_filter_h;
  double time_kernel_down;
  double time_kernel_up;
};


#ifdef TIME_PROF
TEST_TIME Laplacian(int Height, int Width, unsigned char *Src1, unsigned char *layer1) 
#else
int Laplacian(int Height, int Width, unsigned char *Src1, unsigned char *layer1) 
#endif
{

  unsigned char(*Src)[Height][Width] = (unsigned char(*)[Height][Width])(Src1);
  unsigned char(*layer)[Height][Width] = (unsigned char(*)[Height][Width])(layer1);


#ifdef TIME_PROF
  struct timeval timeH0, timeH1, timeD0, timeD1, timeUp0, timeUp1, time0, time1;
  cl_ulong startTime, endTime, kernelTimeH, kernelTimeD, kernelTimeUp;
  struct TEST_TIME t;
#endif

  unsigned char filter_horizon[1][5] = { 1, 4, 6, 4, 1 };
  unsigned char filter_vertical[5][1] = { 1, 4, 6, 4, 1 };
  unsigned char dst_horizon[Height][Width];
  unsigned char dst_vertical[Width][Width];
  unsigned char dst_ds[(Height + 1) / 2][(Width + 1) / 2];


  {
    size_t global_work_size[2];
    size_t transe;

    cl_event event_kernel;
    cl_kernel kernel_1 = clCreateKernel(g_program, "kernel_1", &status);
    checkErr(status, "clCreateKernel for kernel_1");

    global_work_size[0] = Width/4;
    global_work_size[1] = Height;

    size_t SrcSrcWidth = Width;
    size_t SrcSrcHeight = Height;

    size_t Src_srcsz = sizeof(unsigned char);
    size_t SrcSrcStep = SrcSrcWidth * Src_srcsz;
    SrcSrcStep = (SrcSrcStep % PADDING < 16) ? ((SrcSrcStep / PADDING+1) * PADDING) : ((SrcSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t SrcSrcShift = SrcSrcStep * PADDING_LINE;
    size_t Src_srcsz0Pad = SrcSrcStep * (SrcSrcHeight + (PADDING_LINE<<1));

    /*************Horizontal filter**********************************/
    unsigned char *SrcSrcBufH = (unsigned char*)malloc(Src_srcsz0Pad); 
    for(int i = 0; i < SrcSrcHeight; i++){
      memcpy( (char*)SrcSrcBufH+ (i + PADDING_LINE) * SrcSrcStep, (char*)Src+ i * SrcSrcWidth* sizeof(unsigned char), SrcSrcWidth * sizeof(unsigned char) );
    }

    size_t filter_horizonSrcWidth = 5;
    size_t filter_horizonSrcHeight = 1;
    size_t filter_horizon_srcsz = sizeof(unsigned char);
    size_t filter_horizonSrcStep = filter_horizonSrcWidth * filter_horizon_srcsz;
    filter_horizonSrcStep = (filter_horizonSrcStep % PADDING < 16) ? ((filter_horizonSrcStep / PADDING+1) * PADDING) : ((filter_horizonSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t filter_horizonSrcShift = filter_horizonSrcStep * PADDING_LINE;
    size_t filter_horizon_srcsz0Pad = filter_horizonSrcStep * (filter_horizonSrcHeight + (PADDING_LINE<<1));

    unsigned char *filter_horizonSrcBufH = (unsigned char*)malloc(filter_horizon_srcsz0Pad); 
    for(int i = 0; i < filter_horizonSrcHeight; i++){
      memcpy( (char*)filter_horizonSrcBufH+ (i + PADDING_LINE) * filter_horizonSrcStep, (char*)filter_horizon+ i * filter_horizonSrcWidth* sizeof(unsigned char), filter_horizonSrcWidth * sizeof(unsigned char) );
    }

    size_t dst_horizonDstWidth = Width;
    size_t dst_horizonDstHeight = Height;
    size_t dst_horizon_dstsz = sizeof(unsigned char);
    size_t dst_horizonDstStep = dst_horizonDstWidth * dst_horizon_dstsz;
    dst_horizonDstStep = (dst_horizonDstStep % PADDING < 16) ? ((dst_horizonDstStep / PADDING+1) * PADDING) : ((dst_horizonDstStep + PADDING) / PADDING+1) * PADDING;
    size_t dst_horizonDstShift = dst_horizonDstStep * PADDING_LINE;
    size_t dst_horizon_dstsz0Pad = dst_horizonDstStep * (dst_horizonDstHeight + (PADDING_LINE<<1));

    unsigned char *dst_horizonDstBufH = (unsigned char*)malloc(dst_horizon_dstsz0Pad); 
    for(int i = 0; i < dst_horizonDstHeight; i++){
      memcpy( (char*)dst_horizonDstBufH+ (i + PADDING_LINE) * dst_horizonDstStep,(char*)dst_horizon + i * dst_horizonDstWidth* sizeof(unsigned char),dst_horizonDstWidth* sizeof(unsigned char) );
    }


#ifdef TIME_TOTAL
    gettimeofday(&timeH0, NULL);
#endif

    cl_mem SrcsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, Src_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    status = clEnqueueWriteBuffer(g_queue, SrcsrcBuf, CL_TRUE, 0,Src_srcsz0Pad,SrcSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_1, 0, sizeof(cl_mem), (void *)&SrcsrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 1, sizeof(int), (void *)&SrcSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 2, sizeof(int), (void *)&SrcSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 3, sizeof(int), (void *)&SrcSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 4, sizeof(int), (void *)&SrcSrcShift);
    checkErr(status, "clSetKernelArg");

    cl_mem filter_horizonsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, filter_horizon_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    status = clEnqueueWriteBuffer(g_queue, filter_horizonsrcBuf, CL_TRUE, 0,filter_horizon_srcsz0Pad,filter_horizonSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_1, 5, sizeof(cl_mem), (void *)&filter_horizonsrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 6, sizeof(int), (void *)&filter_horizonSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 7, sizeof(int), (void *)&filter_horizonSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 8, sizeof(int), (void *)&filter_horizonSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 9, sizeof(int), (void *)&filter_horizonSrcShift);

    checkErr(status, "clSetKernelArg");
    cl_mem dst_horizondstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, dst_horizon_dstsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");

    status = clSetKernelArg(kernel_1, 10, sizeof(cl_mem), (void *)&dst_horizondstBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 11, sizeof(int), (void *)&dst_horizonDstWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 12, sizeof(int), (void *)&dst_horizonDstHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 13, sizeof(int), (void *)&dst_horizonDstStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 14, sizeof(int), (void *)&dst_horizonDstShift);
    checkErr(status, "clSetKernelArg");
    status = clEnqueueNDRangeKernel(g_queue, kernel_1, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
    checkErr(status, "clEnqueueNDRangeKernel");
    status = clFinish(g_queue);
    checkErr(status,"clFinish of kernel_1");

#ifdef TIME_TOTAL
    gettimeofday(&timeH1, NULL);
#endif

#ifdef TIME_KERNEL
    clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_START, sizeof(cl_ulong), &startTime, NULL);
    clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_END, sizeof(cl_ulong), &endTime, NULL);
    kernelTimeH = (endTime - startTime)/1000.0;
#endif

    // To be optimization.
    status = clEnqueueReadBuffer(g_queue, dst_horizondstBuf, CL_TRUE, 0,dst_horizon_dstsz0Pad,dst_horizonDstBufH, 0, NULL, NULL);
    for(int i = 0; i < dst_horizonDstHeight; i++){
      memcpy( (char*)dst_horizon+ i *dst_horizonDstWidth* sizeof(unsigned char), (char*) dst_horizonDstBufH+ (i + PADDING_LINE)* dst_horizonDstStep, dst_horizonDstWidth* sizeof(unsigned char) );
    }

#if 0
    clReleaseKernel(kernel_1);
    clReleaseMemObject(SrcsrcBuf);
    clReleaseMemObject(filter_horizonsrcBuf);
    clReleaseMemObject(dst_horizondstBuf);
#endif

  }

  /*********Column Filter + Downsample**********************/ 
  {
    size_t global_work_size[2];
    size_t transe;
    cl_event event_kernel;
    cl_kernel kernel_2 = clCreateKernel(g_program, "kernel_2", &status);
    checkErr(status, "clCreateKernel for kernel_2");
    global_work_size[0] = Height/2;
    global_work_size[1] = Width/2;
    size_t filter_verticalSrcWidth = 1;
    size_t filter_verticalSrcHeight = 5;
    size_t filter_vertical_srcsz = sizeof(unsigned char);
    size_t filter_verticalSrcStep = filter_verticalSrcWidth * filter_vertical_srcsz;
    filter_verticalSrcStep = (filter_verticalSrcStep % PADDING < 16) ? ((filter_verticalSrcStep / PADDING+1) * PADDING) : ((filter_verticalSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t filter_verticalSrcShift = filter_verticalSrcStep * PADDING_LINE;
    size_t filter_vertical_srcsz0Pad = filter_verticalSrcStep * (filter_verticalSrcHeight + (PADDING_LINE<<1));
    unsigned char *filter_verticalSrcBufH = (unsigned char*)malloc(filter_vertical_srcsz0Pad); 
    for(int i = 0; i < filter_verticalSrcHeight; i++){
      memcpy( (char*)filter_verticalSrcBufH+ (i + PADDING_LINE) * filter_verticalSrcStep, (char*)filter_vertical+ i * filter_verticalSrcWidth* sizeof(unsigned char), filter_verticalSrcWidth * sizeof(unsigned char) );
    }

    size_t dst_horizonSrcWidth = Width;
    size_t dst_horizonSrcHeight = Height;
    size_t dst_horizon_srcsz = sizeof(unsigned char);
    size_t dst_horizonSrcStep = dst_horizonSrcWidth * dst_horizon_srcsz;
    dst_horizonSrcStep = (dst_horizonSrcStep % PADDING < 16) ? ((dst_horizonSrcStep / PADDING+1) * PADDING) : ((dst_horizonSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t dst_horizonSrcShift = dst_horizonSrcStep * PADDING_LINE;
    size_t dst_horizon_srcsz0Pad = dst_horizonSrcStep * (dst_horizonSrcHeight + (PADDING_LINE<<1));
    unsigned char *dst_horizonSrcBufH = (unsigned char*)malloc(dst_horizon_srcsz0Pad); 
    for(int i = 0; i < dst_horizonSrcHeight; i++){
      memcpy( (char*)dst_horizonSrcBufH+ (i + PADDING_LINE) * dst_horizonSrcStep, (char*)dst_horizon+ i * dst_horizonSrcWidth* sizeof(unsigned char), dst_horizonSrcWidth * sizeof(unsigned char) );
    }

    size_t dst_dsDstWidth = Width/2;
    size_t dst_dsDstHeight = Height/2;
    size_t dst_ds_dstsz = sizeof(unsigned char);
    size_t dst_dsDstStep = dst_dsDstWidth * dst_ds_dstsz;
    dst_dsDstStep = (dst_dsDstStep % PADDING < 16) ? ((dst_dsDstStep / PADDING+1) * PADDING) : ((dst_dsDstStep + PADDING) / PADDING+1) * PADDING;
    size_t dst_dsDstShift = dst_dsDstStep * PADDING_LINE;
    size_t dst_ds_dstsz0Pad = dst_dsDstStep * (dst_dsDstHeight + (PADDING_LINE<<1));
    unsigned char *dst_dsDstBufH = (unsigned char*)malloc(dst_ds_dstsz0Pad); 
    for(int i = 0; i < dst_dsDstHeight; i++){
      memcpy( (char*)dst_dsDstBufH+ (i + PADDING_LINE) * dst_dsDstStep,(char*)dst_ds + i * dst_dsDstWidth* sizeof(unsigned char),dst_dsDstWidth* sizeof(unsigned char) );
    }

#ifdef TIME_PROF 
    gettimeofday(&timeD0, NULL);
#endif

    cl_mem filter_verticalsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, filter_vertical_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    status = clEnqueueWriteBuffer(g_queue, filter_verticalsrcBuf, CL_TRUE, 0,filter_vertical_srcsz0Pad,filter_verticalSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_2, 0, sizeof(cl_mem), (void *)&filter_verticalsrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 1, sizeof(int), (void *)&filter_verticalSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 2, sizeof(int), (void *)&filter_verticalSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 3, sizeof(int), (void *)&filter_verticalSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 4, sizeof(int), (void *)&filter_verticalSrcShift);
    checkErr(status, "clSetKernelArg");

    cl_mem dst_horizonsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, dst_horizon_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");

    status = clEnqueueWriteBuffer(g_queue, dst_horizonsrcBuf, CL_TRUE, 0,dst_horizon_srcsz0Pad,dst_horizonSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_2, 5, sizeof(cl_mem), (void *)&dst_horizonsrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 6, sizeof(int), (void *)&dst_horizonSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 7, sizeof(int), (void *)&dst_horizonSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 8, sizeof(int), (void *)&dst_horizonSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 9, sizeof(int), (void *)&dst_horizonSrcShift);
    checkErr(status, "clSetKernelArg");

    cl_mem dst_dsdstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, dst_ds_dstsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    status = clSetKernelArg(kernel_2, 10, sizeof(cl_mem), (void *)&dst_dsdstBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 11, sizeof(int), (void *)&dst_dsDstWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 12, sizeof(int), (void *)&dst_dsDstHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 13, sizeof(int), (void *)&dst_dsDstStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 14, sizeof(int), (void *)&dst_dsDstShift);
    checkErr(status, "clSetKernelArg");

    status = clEnqueueNDRangeKernel(g_queue, kernel_2, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
    checkErr(status, "clEnqueueNDRangeKernel");
    status = clFinish(g_queue);
    checkErr(status,"clFinish of kernel_2");
#ifdef TIME_PROF 
    gettimeofday(&timeD1, NULL);
#endif

#ifdef TIME_KERNEL
    clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_START, sizeof(cl_ulong), &startTime, NULL);
    clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_END, sizeof(cl_ulong), &endTime, NULL);
    kernelTimeD = (endTime-startTime)/1000.0;
#endif

    // To be optimized.
    status = clEnqueueReadBuffer(g_queue, dst_dsdstBuf, CL_TRUE, 0,dst_ds_dstsz0Pad,dst_dsDstBufH, 0, NULL, NULL);
    for(int i = 0; i < dst_dsDstHeight; i++){
      memcpy( (char*)dst_ds+ i *dst_dsDstWidth* sizeof(unsigned char), (char*) dst_dsDstBufH+ (i + PADDING_LINE)* dst_dsDstStep, dst_dsDstWidth* sizeof(unsigned char) );
    }
#if 0
    clReleaseKernel(kernel_2);
    clReleaseMemObject(dst_dsdstBuf);
    clReleaseMemObject(filter_verticalsrcBuf);
    clReleaseMemObject(dst_horizonsrcBuf);
#endif
  }
  int halfWidth = Width / 2;
  int halfHeight = Height / 2;
  int widthOdd = Width - (halfWidth * 2);
  int heightOdd = Height - (halfHeight * 2);


  /************Upsample + calculation******************************/
  {
    size_t global_work_size[2];
    size_t transe;
    cl_event event_kernel;
    cl_kernel kernel_3 = clCreateKernel(g_program, "kernel_3", &status);
    checkErr(status, "clCreateKernel for kernel_3");
    global_work_size[0] = halfWidth;
    global_work_size[1] = halfHeight;
    size_t SrcSrcWidth = Width;
    size_t SrcSrcHeight = Height;
    size_t Src_srcsz = sizeof(unsigned char);
    size_t SrcSrcStep = SrcSrcWidth * Src_srcsz;
    SrcSrcStep = (SrcSrcStep % PADDING < 16) ? ((SrcSrcStep / PADDING+1) * PADDING) : ((SrcSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t SrcSrcShift = SrcSrcStep * PADDING_LINE;
    size_t Src_srcsz0Pad = SrcSrcStep * (SrcSrcHeight + (PADDING_LINE<<1));
    unsigned char *SrcSrcBufH = (unsigned char*)malloc(Src_srcsz0Pad); 
    for(int i = 0; i < SrcSrcHeight; i++){
      memcpy( (char*)SrcSrcBufH+ (i + PADDING_LINE) * SrcSrcStep, (char*)Src+ i * SrcSrcWidth* sizeof(unsigned char), SrcSrcWidth * sizeof(unsigned char) );
    }


    size_t dst_dsSrcWidth = Width;
    size_t dst_dsSrcHeight = Height;
    size_t dst_ds_srcsz = sizeof(unsigned char);
    size_t dst_dsSrcStep = dst_dsSrcWidth * dst_ds_srcsz;
    dst_dsSrcStep = (dst_dsSrcStep % PADDING < 16) ? ((dst_dsSrcStep / PADDING+1) * PADDING) : ((dst_dsSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t dst_dsSrcShift = dst_dsSrcStep * PADDING_LINE;
    size_t dst_ds_srcsz0Pad = dst_dsSrcStep * (dst_dsSrcHeight + (PADDING_LINE<<1));
    unsigned char *dst_dsSrcBufH = (unsigned char*)malloc(dst_ds_srcsz0Pad); 
    for(int i = 0; i < dst_dsSrcHeight; i++){
      memcpy( (char*)dst_dsSrcBufH+ (i + PADDING_LINE) * dst_dsSrcStep, (char*)dst_ds+ i * dst_dsSrcWidth* sizeof(unsigned char), dst_dsSrcWidth * sizeof(unsigned char) );
    }

    size_t layerDstWidth = Width;
    size_t layerDstHeight = Height;
    size_t layer_dstsz = sizeof(unsigned char);
    size_t layerDstStep = layerDstWidth * layer_dstsz;
    layerDstStep = (layerDstStep % PADDING < 16) ? ((layerDstStep / PADDING+1) * PADDING) : ((layerDstStep + PADDING) / PADDING+1) * PADDING;
    size_t layerDstShift = layerDstStep * PADDING_LINE;
    size_t layer_dstsz0Pad = layerDstStep * (layerDstHeight + (PADDING_LINE<<1));
    unsigned char *layerDstBufH = (unsigned char*)malloc(layer_dstsz0Pad); 
    for(int i = 0; i < layerDstHeight; i++){
      memcpy( (char*)layerDstBufH+ (i + PADDING_LINE) * layerDstStep,(char*)layer + i * layerDstWidth* sizeof(unsigned char),layerDstWidth* sizeof(unsigned char) );
    }


#ifdef TIME_PROF
    gettimeofday(&timeUp0, NULL);
#endif

    cl_mem SrcsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, Src_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    status = clEnqueueWriteBuffer(g_queue, SrcsrcBuf, CL_TRUE, 0,Src_srcsz0Pad,SrcSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_3, 0, sizeof(cl_mem), (void *)&SrcsrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 1, sizeof(int), (void *)&SrcSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 2, sizeof(int), (void *)&SrcSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 3, sizeof(int), (void *)&SrcSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 4, sizeof(int), (void *)&SrcSrcShift);
    checkErr(status, "clSetKernelArg");

    cl_mem dst_dssrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, dst_ds_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    status = clEnqueueWriteBuffer(g_queue, dst_dssrcBuf, CL_TRUE, 0,dst_ds_srcsz0Pad,dst_dsSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_3, 5, sizeof(cl_mem), (void *)&dst_dssrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 6, sizeof(int), (void *)&dst_dsSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 7, sizeof(int), (void *)&dst_dsSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 8, sizeof(int), (void *)&dst_dsSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 9, sizeof(int), (void *)&dst_dsSrcShift);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 10, sizeof(int), (void *)&widthOdd);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 11, sizeof(int), (void *)&heightOdd);
    checkErr(status, "clSetKernelArg");

    cl_mem layerdstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, layer_dstsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    status = clEnqueueWriteBuffer(g_queue, layerdstBuf, CL_TRUE, 0,layer_dstsz0Pad,layerDstBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_3, 12, sizeof(cl_mem), (void *)&layerdstBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 13, sizeof(int), (void *)&layerDstWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 14, sizeof(int), (void *)&layerDstHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 15, sizeof(int), (void *)&layerDstStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 16, sizeof(int), (void *)&layerDstShift);
    checkErr(status, "clSetKernelArg");
    status = clEnqueueNDRangeKernel(g_queue, kernel_3, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
    checkErr(status, "clEnqueueNDRangeKernel");
    status = clFinish(g_queue);
    checkErr(status,"clFinish of kernel_3");

#ifdef TIME_PROF
    gettimeofday(&timeUp1, NULL);
#endif

#ifdef TIME_KERNEL
    clGetEventProfilingInfo(event_kernel,CL_PROFILING_COMMAND_START,sizeof(cl_ulong),&startTime,NULL);
    clGetEventProfilingInfo(event_kernel,CL_PROFILING_COMMAND_END,sizeof(cl_ulong),&endTime,NULL);
    kernelTimeUp = (endTime-startTime)/1000.0;
#endif


    status = clEnqueueReadBuffer(g_queue, layerdstBuf, CL_TRUE, 0,layer_dstsz0Pad,layerDstBufH, 0, NULL, NULL);
    for(int i = 0; i < layerDstHeight; i++){
      memcpy( (char*)layer+ i *layerDstWidth* sizeof(unsigned char), (char*) layerDstBufH+ (i + PADDING_LINE)* layerDstStep, layerDstWidth* sizeof(unsigned char) );
    }

#if 0
    clReleaseKernel(kernel_3);
    clReleaseMemObject(SrcsrcBuf);
    clReleaseMemObject(layerdstBuf);
    clReleaseMemObject(dst_dssrcBuf);
#endif

  }


#ifdef TIME_TOTAL
  t.time_filter_h=(double)(timeH1.tv_usec-timeH0.tv_usec)*0.001+(timeH1.tv_sec-timeH0.tv_sec)*1000;
  t.time_down=(double)(timeD1.tv_usec-timeD0.tv_usec)*0.001+(timeD1.tv_sec-timeD0.tv_sec)*1000;
  t.time_up=(double)(timeUp1.tv_usec-timeUp0.tv_usec)*0.001+(timeUp1.tv_sec-timeUp0.tv_sec)*1000;
#endif

#ifdef TIME_KERNEL
  t.time_kernel_filter_h = (double)(kernelTimeH*0.001);
  t.time_kernel_down = (double)(kernelTimeD*0.001);
  t.time_kernel_up = (double)(kernelTimeUp*0.001);
#endif

  // clean OpenCL resources 
  //clReleaseProgram(g_program);
  //clReleaseCommandQueue(g_queue);
  //clReleaseContext(g_context);





#ifdef TIME_PROF
  return t;
#else
  return 0;
#endif

}



int main() {
  char inputfile[] = "laplacian_opt_lxj_512.cl";
  char *remain = NULL;
  //int height = 256, width = 256;
  int height = 512, width = 512;

  //for( int count = 0; count < 3; count++)
  {

    if (-1 == openCLCreate(inputfile, remain)) {
      printf("openCL create fail !!!!!!");
      return 0;
    }


    unsigned char *src_data = (unsigned char *)malloc(sizeof(unsigned char) * height * width);
    unsigned char *dst_data = (unsigned char *)malloc(sizeof(unsigned char) * height * width);
    unsigned char (*src)[height][width] = (unsigned char (*)[height][width])src_data;
    unsigned char (*Layer)[height][width] = (unsigned char (*)[height][width])dst_data;
    for (int i = 0; i < width * height; i++) {
      src_data[i] = rand() % 100 + 1;
    }

    struct TEST_TIME sum = {0, 0, 0, 0, 0, 0, 0};
    struct TEST_TIME avg;
    int testNumber = 1;

    // Pre execute one time.
    Laplacian(height, width, (unsigned char*)src, (unsigned char*) Layer);

    // Re-init.
    for (int i = 0; i < width * height; i++) {
      src_data[i] = rand() % 100 + 1;
    }
#ifdef TIME_PROF
    struct TEST_TIME temp = Laplacian(height, width, (unsigned char*) src, (unsigned char*) Layer);
#endif

#ifdef TIME_TOTAL
    sum.time_filter_h += temp.time_filter_h;
    sum.time_down += temp.time_down;
    sum.time_up += temp.time_up;

#endif

#ifdef TIME_KERNEL
    sum.time_kernel_filter_h += temp.time_kernel_filter_h;
    sum.time_kernel_down += temp.time_kernel_down;
    sum.time_kernel_up += temp.time_kernel_up;
#endif


#ifdef  TIME_TOTAL
    avg.time_filter_h = sum.time_filter_h/testNumber;
    avg.time_down = sum.time_down/testNumber;
    avg.time_up = sum.time_up/testNumber;
#endif
#ifdef TIME_KERNEL
    avg.time_kernel_filter_h = sum.time_kernel_filter_h/testNumber;
    avg.time_kernel_down = sum.time_kernel_down/testNumber;
    avg.time_kernel_up = sum.time_kernel_up/testNumber;
#endif

#ifdef TIME_TOTAL
    printf("TIME_PROF: Height = %d, Width = %d \n", height, width);
    printf("TotalTime:\n filter_h=%f\ndown=%f\nup=%f\n",avg.time_filter_h,avg.time_down,avg.time_up);
#endif
#ifdef TIME_KERNEL
    printf("kerneltime:\n kernel_fitler_h = %f\nkernel_down = %f\nkernel_up = %f\n\n",avg.time_kernel_filter_h,avg.time_kernel_down,avg.time_kernel_up);
#endif

    // 
    //height *=2;
    //width *=2;
  }


  return 0;
}

