/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

#include"CL/cl.h"
#include"ClHost.h"
/*
  Copyright (c) 2016.
  All rights reserved.

  Written and provided by: 
  Xingjing Lu, ICT, CAS.

  Based the unsharp_mask_polymage_native.cpp, which is written by
  Ravi Teja Mullapudi, Vinay Vasisa, Uday Bondhugula.
  
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include<math.h>
#include<sys/time.h>

#define M 2048
#define N 2048
#define O 3
#define PADM 2052
#define PADN 2052


#ifdef TIME_PROF
 double KernelTime1, KernelTime2, KernelTime3;
 unsigned long startTime, endTime;
 double tem1, tem2, tem3;
 struct timeval  tstart[3], tend[3];
 double ttotal[3];
#define RUNS 10
#endif

  void pipeline_mask(int R, int C, float threshold, float weight, float (*img)[2052][2052], float (*mask)[2048][2048], float (*blurx)[2048][2052], float (*blury)[2048][2048], float (*sharpen)[2048][2048]) {
  float filterx[5][1] = { 0.0625F, 0.25F, 0.375F, 0.25F, 0.0625F };
  float filtery[1][5] = { 0.0625F, 0.25F, 0.375F, 0.25F, 0.0625F };

#ifdef TIME_PROF
     tem1 = tem2 = tem3 = 0; ttotal[0] = 0;  ttotal[1] =  0; ttotal[2]  = 0;
#endif

  
     {
       for( int q = 0; q < RUNS; q++){
         size_t global_work_size[2];
         size_t local_work_size[2];
         size_t transe;
         cl_event event_kernel;
         cl_kernel kernel_1 = clCreateKernel(g_program, "kernel_1", &status);
         checkErr(status, "clCreateKernel for kernel_1");
         global_work_size[0] = 257; // 2051
         global_work_size[1] = 2047;
         local_work_size[0] = 8;
         local_work_size[1] = 8;
         size_t imgSrcWidth = 2052;
         size_t imgSrcHeight = 2052;
         size_t img_srcsz = sizeof(float);
         size_t imgSrcStep = imgSrcWidth * img_srcsz;
         imgSrcStep = (imgSrcStep % PADDING < 16) ? ((imgSrcStep / PADDING+1) * PADDING) : ((imgSrcStep + PADDING) / PADDING+1) * PADDING;
         size_t imgSrcShift = imgSrcStep * PADDING_LINE;
         size_t img_srcsz0Pad = imgSrcStep * (imgSrcHeight + (PADDING_LINE<<1));
         cl_mem imgsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, img_srcsz0Pad, NULL, &status);
         checkErr(status, "clCreateBuffer");
         float *imgSrcBufH = (float*)malloc(img_srcsz0Pad); 
         for(int i = 0; i < imgSrcHeight; i++){
           memcpy( (char*)imgSrcBufH+ (i + PADDING_LINE) * imgSrcStep, (char*)img+ i * imgSrcWidth* sizeof(float), imgSrcWidth * sizeof(float) );
         }
         status = clEnqueueWriteBuffer(g_queue, imgsrcBuf, CL_TRUE, 0,img_srcsz0Pad,imgSrcBufH, 0, NULL, NULL);
         checkErr(status, "clWriteBuffer");
         status = clSetKernelArg(kernel_1, 0, sizeof(cl_mem), (void *)&imgsrcBuf);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_1, 1, sizeof(int), (void *)&imgSrcWidth);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_1, 2, sizeof(int), (void *)&imgSrcHeight);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_1, 3, sizeof(int), (void *)&imgSrcStep);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_1, 4, sizeof(int), (void *)&imgSrcShift);
         checkErr(status, "clSetKernelArg");
         size_t filterxSrcWidth = 1;
         size_t filterxSrcHeight = 5;
         size_t filterx_srcsz = sizeof(float);
         size_t filterxSrcStep = filterxSrcWidth * filterx_srcsz;
         filterxSrcStep = (filterxSrcStep % PADDING < 16) ? ((filterxSrcStep / PADDING+1) * PADDING) : ((filterxSrcStep + PADDING) / PADDING+1) * PADDING;
         size_t filterxSrcShift = filterxSrcStep * PADDING_LINE;
         size_t filterx_srcsz0Pad = filterxSrcStep * (filterxSrcHeight + (PADDING_LINE<<1));
         cl_mem filterxsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, filterx_srcsz0Pad, NULL, &status);
         checkErr(status, "clCreateBuffer");
         float *filterxSrcBufH = (float*)malloc(filterx_srcsz0Pad); 
         for(int i = 0; i < filterxSrcHeight; i++){
           memcpy( (char*)filterxSrcBufH+ (i + PADDING_LINE) * filterxSrcStep, (char*)filterx+ i * filterxSrcWidth* sizeof(float), filterxSrcWidth * sizeof(float) );
         }
         status = clEnqueueWriteBuffer(g_queue, filterxsrcBuf, CL_TRUE, 0,filterx_srcsz0Pad,filterxSrcBufH, 0, NULL, NULL);
         checkErr(status, "clWriteBuffer");
         status = clSetKernelArg(kernel_1, 5, sizeof(cl_mem), (void *)&filterxsrcBuf);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_1, 6, sizeof(int), (void *)&filterxSrcWidth);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_1, 7, sizeof(int), (void *)&filterxSrcHeight);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_1, 8, sizeof(int), (void *)&filterxSrcStep);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_1, 9, sizeof(int), (void *)&filterxSrcShift);
         checkErr(status, "clSetKernelArg");
         size_t blurxDstWidth = 2052;
         size_t blurxDstHeight = 2048;
         size_t blurx_dstsz = sizeof(float);
         size_t blurxDstStep = blurxDstWidth * blurx_dstsz;
         blurxDstStep = (blurxDstStep % PADDING < 16) ? ((blurxDstStep / PADDING+1) * PADDING) : ((blurxDstStep + PADDING) / PADDING+1) * PADDING;
         size_t blurxDstShift = blurxDstStep * PADDING_LINE;
         size_t blurx_dstsz0Pad = blurxDstStep * (blurxDstHeight + (PADDING_LINE<<1));
         cl_mem blurxdstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, blurx_dstsz0Pad, NULL, &status);
         checkErr(status, "clCreateBuffer");
         float *blurxDstBufH = (float*)malloc(blurx_dstsz0Pad); 
         for(int i = 0; i < blurxDstHeight; i++){
           memcpy( (char*)blurxDstBufH+ (i + PADDING_LINE) * blurxDstStep,(char*)blurx + i * blurxDstWidth* sizeof(float),blurxDstWidth* sizeof(float) );
         }
         status = clEnqueueWriteBuffer(g_queue, blurxdstBuf, CL_TRUE, 0,blurx_dstsz0Pad,blurxDstBufH, 0, NULL, NULL);
         checkErr(status, "clWriteBuffer");
         status = clSetKernelArg(kernel_1, 10, sizeof(cl_mem), (void *)&blurxdstBuf);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_1, 11, sizeof(int), (void *)&blurxDstWidth);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_1, 12, sizeof(int), (void *)&blurxDstHeight);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_1, 13, sizeof(int), (void *)&blurxDstStep);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_1, 14, sizeof(int), (void *)&blurxDstShift);
         checkErr(status, "clSetKernelArg");
#ifdef TIME_PROF
         gettimeofday(&tstart[0], NULL);
#endif

         //status = clEnqueueNDRangeKernel(g_queue, kernel_1, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
         status = clEnqueueNDRangeKernel(g_queue, kernel_1, 2, NULL, global_work_size, local_work_size, 0, NULL, &event_kernel);
         checkErr(status, "clEnqueueNDRangeKernel");
         status = clFinish(g_queue);
         checkErr(status,"clFinish of kernel_1");
#ifdef TIME_PROF
         gettimeofday(&tend[0], NULL);
         if( q )
           ttotal[0] += 1000.0*(tend[0].tv_sec - tstart[0].tv_sec) + (tend[0].tv_usec - tstart[0].tv_usec)/1000.0;
#endif

#ifdef TIME_PROF
         clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_START, sizeof(cl_ulong), &startTime, NULL);
         clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_END, sizeof(cl_ulong), &endTime, NULL);
         tem1 += ((double)(endTime - startTime))/1000.0;
#endif




         status = clEnqueueReadBuffer(g_queue, blurxdstBuf, CL_TRUE, 0,blurx_dstsz0Pad,blurxDstBufH, 0, NULL, NULL);
         for(int i = 0; i < blurxDstHeight; i++){
           memcpy( (char*)blurx+ i *blurxDstWidth* sizeof(float), (char*) blurxDstBufH+ (i + PADDING_LINE)* blurxDstStep, blurxDstWidth* sizeof(float) );
         }
       }

     }
  
     {
       for( int q = 0; q < RUNS; q++){
         size_t global_work_size[2];
         size_t local_work_size[2];
         size_t transe;
         cl_event event_kernel;
         cl_kernel kernel_2 = clCreateKernel(g_program, "kernel_2", &status);
         checkErr(status, "clCreateKernel for kernel_2");
         global_work_size[0] = 256; //512;
         global_work_size[1] = 2047;
         local_work_size[0] = 8;
         local_work_size[1] = 8;
         size_t blurxSrcWidth = 2052;
         size_t blurxSrcHeight = 2048;
         size_t blurx_srcsz = sizeof(float);
         size_t blurxSrcStep = blurxSrcWidth * blurx_srcsz;
         blurxSrcStep = (blurxSrcStep % PADDING < 16) ? ((blurxSrcStep / PADDING+1) * PADDING) : ((blurxSrcStep + PADDING) / PADDING+1) * PADDING;
         size_t blurxSrcShift = blurxSrcStep * PADDING_LINE;
         size_t blurx_srcsz0Pad = blurxSrcStep * (blurxSrcHeight + (PADDING_LINE<<1));
         cl_mem blurxsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, blurx_srcsz0Pad, NULL, &status);
         checkErr(status, "clCreateBuffer");
         float *blurxSrcBufH = (float*)malloc(blurx_srcsz0Pad); 
         for(int i = 0; i < blurxSrcHeight; i++){
           memcpy( (char*)blurxSrcBufH+ (i + PADDING_LINE) * blurxSrcStep, (char*)blurx+ i * blurxSrcWidth* sizeof(float), blurxSrcWidth * sizeof(float) );
         }
         status = clEnqueueWriteBuffer(g_queue, blurxsrcBuf, CL_TRUE, 0,blurx_srcsz0Pad,blurxSrcBufH, 0, NULL, NULL);
         checkErr(status, "clWriteBuffer");
         status = clSetKernelArg(kernel_2, 0, sizeof(cl_mem), (void *)&blurxsrcBuf);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_2, 1, sizeof(int), (void *)&blurxSrcWidth);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_2, 2, sizeof(int), (void *)&blurxSrcHeight);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_2, 3, sizeof(int), (void *)&blurxSrcStep);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_2, 4, sizeof(int), (void *)&blurxSrcShift);
         checkErr(status, "clSetKernelArg");
         size_t filterySrcWidth = 5;
         size_t filterySrcHeight = 1;
         size_t filtery_srcsz = sizeof(float);
         size_t filterySrcStep = filterySrcWidth * filtery_srcsz;
         filterySrcStep = (filterySrcStep % PADDING < 16) ? ((filterySrcStep / PADDING+1) * PADDING) : ((filterySrcStep + PADDING) / PADDING+1) * PADDING;
         size_t filterySrcShift = filterySrcStep * PADDING_LINE;
         size_t filtery_srcsz0Pad = filterySrcStep * (filterySrcHeight + (PADDING_LINE<<1));
         cl_mem filterysrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, filtery_srcsz0Pad, NULL, &status);
         checkErr(status, "clCreateBuffer");
         float *filterySrcBufH = (float*)malloc(filtery_srcsz0Pad); 
         for(int i = 0; i < filterySrcHeight; i++){
           memcpy( (char*)filterySrcBufH+ (i + PADDING_LINE) * filterySrcStep, (char*)filtery+ i * filterySrcWidth* sizeof(float), filterySrcWidth * sizeof(float) );
         }
         status = clEnqueueWriteBuffer(g_queue, filterysrcBuf, CL_TRUE, 0,filtery_srcsz0Pad,filterySrcBufH, 0, NULL, NULL);
         checkErr(status, "clWriteBuffer");
         status = clSetKernelArg(kernel_2, 5, sizeof(cl_mem), (void *)&filterysrcBuf);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_2, 6, sizeof(int), (void *)&filterySrcWidth);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_2, 7, sizeof(int), (void *)&filterySrcHeight);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_2, 8, sizeof(int), (void *)&filterySrcStep);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_2, 9, sizeof(int), (void *)&filterySrcShift);
         checkErr(status, "clSetKernelArg");
         size_t bluryDstWidth = 2048;
         size_t bluryDstHeight = 2048;
         size_t blury_dstsz = sizeof(float);
         size_t bluryDstStep = bluryDstWidth * blury_dstsz;
         bluryDstStep = (bluryDstStep % PADDING < 16) ? ((bluryDstStep / PADDING+1) * PADDING) : ((bluryDstStep + PADDING) / PADDING+1) * PADDING;
         size_t bluryDstShift = bluryDstStep * PADDING_LINE;
         size_t blury_dstsz0Pad = bluryDstStep * (bluryDstHeight + (PADDING_LINE<<1));
         cl_mem blurydstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, blury_dstsz0Pad, NULL, &status);
         checkErr(status, "clCreateBuffer");
         float *bluryDstBufH = (float*)malloc(blury_dstsz0Pad); 
         for(int i = 0; i < bluryDstHeight; i++){
           memcpy( (char*)bluryDstBufH+ (i + PADDING_LINE) * bluryDstStep,(char*)blury + i * bluryDstWidth* sizeof(float),bluryDstWidth* sizeof(float) );
         }
         status = clEnqueueWriteBuffer(g_queue, blurydstBuf, CL_TRUE, 0,blury_dstsz0Pad,bluryDstBufH, 0, NULL, NULL);
         checkErr(status, "clWriteBuffer");
         status = clSetKernelArg(kernel_2, 10, sizeof(cl_mem), (void *)&blurydstBuf);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_2, 11, sizeof(int), (void *)&bluryDstWidth);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_2, 12, sizeof(int), (void *)&bluryDstHeight);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_2, 13, sizeof(int), (void *)&bluryDstStep);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_2, 14, sizeof(int), (void *)&bluryDstShift);
         checkErr(status, "clSetKernelArg");
#ifdef TIME_PROF
         gettimeofday(&tstart[1], NULL);
#endif
         status = clEnqueueNDRangeKernel(g_queue, kernel_2, 2, NULL, global_work_size, local_work_size, 0, NULL, &event_kernel);
         checkErr(status, "clEnqueueNDRangeKernel");
         status = clFinish(g_queue);
         checkErr(status,"clFinish of kernel_2");
#ifdef TIME_PROF
         gettimeofday(&tend[1], NULL);
         if( q )
         ttotal[1] += 1000.0*(tend[1].tv_sec - tstart[1].tv_sec) + (tend[1].tv_usec - tstart[1].tv_usec)/1000.0;
#endif

#ifdef TIME_PROF
         clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_START, sizeof(cl_ulong), &startTime, NULL);
         clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_END, sizeof(cl_ulong), &endTime, NULL);
         tem2 += (double)(endTime - startTime)/1000.0;
#endif




         status = clEnqueueReadBuffer(g_queue, blurydstBuf, CL_TRUE, 0,blury_dstsz0Pad,bluryDstBufH, 0, NULL, NULL);
         for(int i = 0; i < bluryDstHeight; i++){
           memcpy( (char*)blury+ i *bluryDstWidth* sizeof(float), (char*) bluryDstBufH+ (i + PADDING_LINE)* bluryDstStep, bluryDstWidth* sizeof(float) );
         }

       }
     }
  
     {
       for( int q = 0; q < RUNS; q++){
         size_t global_work_size[2];
         size_t local_work_size[2];
         size_t transe;
         cl_event event_kernel;
         cl_kernel kernel_3 = clCreateKernel(g_program, "kernel_3", &status);
         checkErr(status, "clCreateKernel for kernel_3");
         global_work_size[0] = 256; //512; // 2047
         global_work_size[1] = 2047;
         local_work_size[0] = 8;
         local_work_size[1] = 8;
         status = clSetKernelArg(kernel_3, 0, sizeof(float), (void *)&threshold);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_3, 1, sizeof(float), (void *)&weight);
         checkErr(status, "clSetKernelArg");
         size_t imgSrcWidth = 2052;
         size_t imgSrcHeight = 2052;
         size_t img_srcsz = sizeof(float);
         size_t imgSrcStep = imgSrcWidth * img_srcsz;
         imgSrcStep = (imgSrcStep % PADDING < 16) ? ((imgSrcStep / PADDING+1) * PADDING) : ((imgSrcStep + PADDING) / PADDING+1) * PADDING;
         size_t imgSrcShift = imgSrcStep * PADDING_LINE;
         size_t img_srcsz0Pad = imgSrcStep * (imgSrcHeight + (PADDING_LINE<<1));
         cl_mem imgsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, img_srcsz0Pad, NULL, &status);
         checkErr(status, "clCreateBuffer");
         float *imgSrcBufH = (float*)malloc(img_srcsz0Pad); 
         for(int i = 0; i < imgSrcHeight; i++){
           memcpy( (char*)imgSrcBufH+ (i + PADDING_LINE) * imgSrcStep, (char*)img+ i * imgSrcWidth* sizeof(float), imgSrcWidth * sizeof(float) );
         }
         status = clEnqueueWriteBuffer(g_queue, imgsrcBuf, CL_TRUE, 0,img_srcsz0Pad,imgSrcBufH, 0, NULL, NULL);
         checkErr(status, "clWriteBuffer");
         status = clSetKernelArg(kernel_3, 2, sizeof(cl_mem), (void *)&imgsrcBuf);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_3, 3, sizeof(int), (void *)&imgSrcWidth);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_3, 4, sizeof(int), (void *)&imgSrcHeight);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_3, 5, sizeof(int), (void *)&imgSrcStep);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_3, 6, sizeof(int), (void *)&imgSrcShift);
         checkErr(status, "clSetKernelArg");
         size_t blurySrcWidth = 2048;
         size_t blurySrcHeight = 2048;
         size_t blury_srcsz = sizeof(float);
         size_t blurySrcStep = blurySrcWidth * blury_srcsz;
         blurySrcStep = (blurySrcStep % PADDING < 16) ? ((blurySrcStep / PADDING+1) * PADDING) : ((blurySrcStep + PADDING) / PADDING+1) * PADDING;
         size_t blurySrcShift = blurySrcStep * PADDING_LINE;
         size_t blury_srcsz0Pad = blurySrcStep * (blurySrcHeight + (PADDING_LINE<<1));
         cl_mem blurysrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, blury_srcsz0Pad, NULL, &status);
         checkErr(status, "clCreateBuffer");
         float *blurySrcBufH = (float*)malloc(blury_srcsz0Pad); 
         for(int i = 0; i < blurySrcHeight; i++){
           memcpy( (char*)blurySrcBufH+ (i + PADDING_LINE) * blurySrcStep, (char*)blury+ i * blurySrcWidth* sizeof(float), blurySrcWidth * sizeof(float) );
         }
         status = clEnqueueWriteBuffer(g_queue, blurysrcBuf, CL_TRUE, 0,blury_srcsz0Pad,blurySrcBufH, 0, NULL, NULL);
         checkErr(status, "clWriteBuffer");
         status = clSetKernelArg(kernel_3, 7, sizeof(cl_mem), (void *)&blurysrcBuf);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_3, 8, sizeof(int), (void *)&blurySrcWidth);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_3, 9, sizeof(int), (void *)&blurySrcHeight);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_3, 10, sizeof(int), (void *)&blurySrcStep);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_3, 11, sizeof(int), (void *)&blurySrcShift);
         checkErr(status, "clSetKernelArg");
         size_t maskDstWidth = 2048;
         size_t maskDstHeight = 2048;
         size_t mask_dstsz = sizeof(float);
         size_t maskDstStep = maskDstWidth * mask_dstsz;
         maskDstStep = (maskDstStep % PADDING < 16) ? ((maskDstStep / PADDING+1) * PADDING) : ((maskDstStep + PADDING) / PADDING+1) * PADDING;
         size_t maskDstShift = maskDstStep * PADDING_LINE;
         size_t mask_dstsz0Pad = maskDstStep * (maskDstHeight + (PADDING_LINE<<1));
         cl_mem maskdstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, mask_dstsz0Pad, NULL, &status);
         checkErr(status, "clCreateBuffer");
         float *maskDstBufH = (float*)malloc(mask_dstsz0Pad); 
         for(int i = 0; i < maskDstHeight; i++){
           memcpy( (char*)maskDstBufH+ (i + PADDING_LINE) * maskDstStep,(char*)mask + i * maskDstWidth* sizeof(float),maskDstWidth* sizeof(float) );
         }
         status = clEnqueueWriteBuffer(g_queue, maskdstBuf, CL_TRUE, 0,mask_dstsz0Pad,maskDstBufH, 0, NULL, NULL);
         checkErr(status, "clWriteBuffer");
         status = clSetKernelArg(kernel_3, 12, sizeof(cl_mem), (void *)&maskdstBuf);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_3, 13, sizeof(int), (void *)&maskDstWidth);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_3, 14, sizeof(int), (void *)&maskDstHeight);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_3, 15, sizeof(int), (void *)&maskDstStep);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_3, 16, sizeof(int), (void *)&maskDstShift);
         checkErr(status, "clSetKernelArg");
         size_t sharpenDSWidth = 2048;
         size_t sharpenDSHeight = 2048;
         size_t sharpen_dssz = sizeof(float);
         size_t sharpenDSStep = sharpenDSWidth * sharpen_dssz;
         sharpenDSStep = (sharpenDSStep % PADDING < 16) ? ((sharpenDSStep / PADDING+1) * PADDING) : ((sharpenDSStep + PADDING) / PADDING+1) * PADDING;
         size_t sharpenDSShift = sharpenDSStep * PADDING_LINE;
         size_t sharpen_dssz0Pad = sharpenDSStep * (sharpenDSHeight + (PADDING_LINE<<1));
         cl_mem sharpendsBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, sharpen_dssz0Pad, NULL, &status);
         checkErr(status, "clCreateBuffer");
         float *sharpenDsBufH = (float*)malloc (sharpen_dssz0Pad); 
         for(int i = 0; i < sharpenDSHeight; i++){
           memcpy((char*)sharpenDsBufH + (i + PADDING_LINE) * sharpenDSStep, (char*)sharpen+ i * sharpenDSWidth * sizeof(float), sharpenDSWidth* sizeof(float) );
         }
         status = clEnqueueWriteBuffer(g_queue, sharpendsBuf, CL_TRUE, 0,sharpen_dssz0Pad, sharpenDsBufH, 0, NULL, NULL);
         checkErr(status, "clWriteBuffer");
         status = clSetKernelArg(kernel_3, 17, sizeof(cl_mem), (void *)&sharpendsBuf);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_3, 18, sizeof(int), (void *)&sharpenDSWidth);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_3, 19, sizeof(int), (void *)&sharpenDSHeight);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_3, 20, sizeof(int), (void *)&sharpenDSStep);
         checkErr(status, "clSetKernelArg");
         status = clSetKernelArg(kernel_3, 21, sizeof(int), (void *)&sharpenDSShift);
         checkErr(status, "clSetKernelArg");
#ifdef TIME_PROF
         gettimeofday(&tstart[2], NULL);
#endif
         status = clEnqueueNDRangeKernel(g_queue, kernel_3, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
         //status = clEnqueueNDRangeKernel(g_queue, kernel_3, 2, NULL, global_work_size, local_work_size, 0, NULL, &event_kernel);
         checkErr(status, "clEnqueueNDRangeKernel");
         status = clFinish(g_queue);
         checkErr(status,"clFinish of kernel_3");
#ifdef TIME_PROF
         gettimeofday(&tend[2], NULL);
         if( q )
           ttotal[2] += 1000.0*(tend[2].tv_sec - tstart[2].tv_sec) + (tend[2].tv_usec - tstart[2].tv_usec)/1000.0;
#endif

#ifdef TIME_PROF
         clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_START, sizeof(cl_ulong), &startTime, NULL);
         clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_END, sizeof(cl_ulong), &endTime, NULL);
         tem3 += (double)(endTime - startTime)/1000.0;
#endif




         status = clEnqueueReadBuffer(g_queue, sharpendsBuf, CL_TRUE, 0,sharpen_dssz0Pad,sharpenDsBufH, 0, NULL, NULL);
         for(int i = 0; i < sharpenDSHeight; i++){
           memcpy( (char*)sharpen+ i *sharpenDSWidth* sizeof(float), (char*) sharpenDsBufH+ (i + PADDING_LINE)* sharpenDSStep, sharpenDSWidth* sizeof(float) );
         }
         status = clEnqueueReadBuffer(g_queue, maskdstBuf, CL_TRUE, 0,mask_dstsz0Pad,maskDstBufH, 0, NULL, NULL);
         for(int i = 0; i < maskDstHeight; i++){
           memcpy( (char*)mask+ i *maskDstWidth* sizeof(float), (char*) maskDstBufH+ (i + PADDING_LINE)* maskDstStep, maskDstWidth* sizeof(float) );
         }
       }

     }
#ifdef TIME_PROF
     KernelTime1 = tem1 / RUNS;
     KernelTime2 = tem2 / RUNS;
     KernelTime3 = tem3 / RUNS;
  printf("QueueTime Kernel1 = %f, Kernel2 = %f, Kernel3 = %f \n", ttotal[0]/(RUNS-1), ttotal[1]/(RUNS-1), ttotal[2]/(RUNS-1));
  printf("KernelTime1 = %f, KernelTime2 = %f, KernelTime3 = %f \n", KernelTime1*0.001, KernelTime2*0.001, KernelTime3*0.001);
#endif



}




int main() {
  char inputfile[] = "unsharpmask_native_opt.cl";
  char *remain = NULL;
  if (-1 == openCLCreate(inputfile, remain)) {
    printf("openCL create fail !!!!!!");
    return 0;
  }
  int nruns = 6, rows = 0, cols = 0, c = 0, channel = 3;
  int row_base, col_base;
  float *image_src, *image_ghost_src, *res_src;
  float *blurx_src, *blury_src, *mask_src, *sharpen_src;
  float threshold = 9.9999999999999995E-7;
  int weight = 4;
  image_src = (float *)malloc(sizeof(float) * 2048 * 2048);
  res_src = (float *)malloc(sizeof(float) * 2048 * 2048);
  blurx_src = (float *)malloc(sizeof(float) * 2048 * 2052);
  blury_src = (float *)malloc(sizeof(float) * 2048 * 2048);
  sharpen_src = (float *)malloc(sizeof(float) * 2048 * 2048);
  rows = 2048;
  cols = 2048;
  channel = 3;
  row_base = (2048 - rows) / 2;
  col_base = (2048 - cols) / 2;
  int total_pad = 4;
  image_ghost_src = (float *)malloc(sizeof(float) * (rows + 4) * (cols + 4));
  for (int i = 0; i < 2048; i++) {
    memcpy(image_ghost_src + (i + 2) * (cols + 4) + 2, image_src + i * cols, cols);
  }
  for (int i = 0; i < 2048; i++) 
    for (int j = 0; j < 2048; j++) {
      image_src[i * cols + j] = (float)(rand() % 255);
      image_ghost_src[i * (cols + 4) + j + 2] = image_src[i * cols + j];
    }
  float (*image_ghost)[2052][2052] = (float (*)[2052][2052])image_ghost_src;
  float (*res)[2048][2048] = (float (*)[2048][2048])res_src;
  float (*blurx)[2048][2052] = (float (*)[2048][2052])blurx_src;
  float (*blury)[2048][2048] = (float (*)[2048][2048])blury_src;
  float (*sharpen)[2048][2048] = (float (*)[2048][2048])sharpen_src;
  pipeline_mask(cols, rows, threshold, weight, image_ghost, res, blurx, blury, sharpen);
  return 0;
}


