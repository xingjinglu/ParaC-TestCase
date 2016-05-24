/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

#include"CL/cl.h"
#include"ClHost.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define WIDTH 4802 
#define HEIGHT  6408

void blur(uint16_t (*in)[6408][4802], uint16_t (*intermediate)[6408][4802], uint16_t (*out)[6408][4802]) {
  
  {
    size_t global_work_size[2];
    size_t transe;
    cl_event event_kernel;
    cl_kernel kernel_1 = clCreateKernel(g_program, "kernel_1", &status);
    checkErr(status, "clCreateKernel for kernel_1");
    global_work_size[0] = 6408;
    global_work_size[1] = 4800;
    size_t inSrcWidth = 4802;
    size_t inSrcHeight = 6408;
    size_t in_srcsz = sizeof(uint16_t);
    size_t inSrcStep = inSrcWidth * in_srcsz;
    inSrcStep = (inSrcStep % PADDING < 16) ? ((inSrcStep / PADDING+1) * PADDING) : ((inSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t inSrcShift = inSrcStep * PADDING_LINE;
    size_t in_srcsz0Pad = inSrcStep * (inSrcHeight + (PADDING_LINE<<1));
    cl_mem insrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, in_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    uint16_t *inSrcBufH = (uint16_t*)malloc(in_srcsz0Pad); 
    for(int i = 0; i < inSrcHeight; i++){
  memcpy( (char*)inSrcBufH+ (i + PADDING_LINE) * inSrcStep, (char*)in+ i * inSrcWidth* sizeof(uint16_t), inSrcWidth * sizeof(uint16_t) );
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
    size_t intermediateDstWidth = 4802;
    size_t intermediateDstHeight = 6408;
    size_t intermediate_dstsz = sizeof(uint16_t);
    size_t intermediateDstStep = intermediateDstWidth * intermediate_dstsz;
    intermediateDstStep = (intermediateDstStep % PADDING < 16) ? ((intermediateDstStep / PADDING+1) * PADDING) : ((intermediateDstStep + PADDING) / PADDING+1) * PADDING;
    size_t intermediateDstShift = intermediateDstStep * PADDING_LINE;
    size_t intermediate_dstsz0Pad = intermediateDstStep * (intermediateDstHeight + (PADDING_LINE<<1));
    cl_mem intermediatedstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, intermediate_dstsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    uint16_t *intermediateDstBufH = (uint16_t*)malloc(intermediate_dstsz0Pad); 
    for(int i = 0; i < intermediateDstHeight; i++){
  memcpy( (char*)intermediateDstBufH+ (i + PADDING_LINE) * intermediateDstStep,(char*)intermediate + i * intermediateDstWidth* sizeof(uint16_t),intermediateDstWidth* sizeof(uint16_t) );
  }
    status = clEnqueueWriteBuffer(g_queue, intermediatedstBuf, CL_TRUE, 0,intermediate_dstsz0Pad,intermediateDstBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_1, 5, sizeof(cl_mem), (void *)&intermediatedstBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 6, sizeof(int), (void *)&intermediateDstWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 7, sizeof(int), (void *)&intermediateDstHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 8, sizeof(int), (void *)&intermediateDstStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 9, sizeof(int), (void *)&intermediateDstShift);
    checkErr(status, "clSetKernelArg");
    status = clEnqueueNDRangeKernel(g_queue, kernel_1, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
    checkErr(status, "clEnqueueNDRangeKernel");
    status = clFinish(g_queue);
    checkErr(status,"clFinish of kernel_1");
      status = clEnqueueReadBuffer(g_queue, intermediatedstBuf, CL_TRUE, 0,intermediate_dstsz0Pad,intermediateDstBufH, 0, NULL, NULL);
    for(int i = 0; i < intermediateDstHeight; i++){
  memcpy( (char*)intermediate+ i *intermediateDstWidth* sizeof(uint16_t), (char*) intermediateDstBufH+ (i + PADDING_LINE)* intermediateDstStep, intermediateDstWidth* sizeof(uint16_t) );
  }
  
  }
  
  {
    size_t global_work_size[2];
    size_t transe;
    cl_event event_kernel;
    cl_kernel kernel_2 = clCreateKernel(g_program, "kernel_2", &status);
    checkErr(status, "clCreateKernel for kernel_2");
    global_work_size[0] = 6406;
    global_work_size[1] = 4802;
    size_t inSrcWidth = 4802;
    size_t inSrcHeight = 6408;
    size_t in_srcsz = sizeof(uint16_t);
    size_t inSrcStep = inSrcWidth * in_srcsz;
    inSrcStep = (inSrcStep % PADDING < 16) ? ((inSrcStep / PADDING+1) * PADDING) : ((inSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t inSrcShift = inSrcStep * PADDING_LINE;
    size_t in_srcsz0Pad = inSrcStep * (inSrcHeight + (PADDING_LINE<<1));
    cl_mem insrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, in_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    uint16_t *inSrcBufH = (uint16_t*)malloc(in_srcsz0Pad); 
    for(int i = 0; i < inSrcHeight; i++){
  memcpy( (char*)inSrcBufH+ (i + PADDING_LINE) * inSrcStep, (char*)in+ i * inSrcWidth* sizeof(uint16_t), inSrcWidth * sizeof(uint16_t) );
  }
    status = clEnqueueWriteBuffer(g_queue, insrcBuf, CL_TRUE, 0,in_srcsz0Pad,inSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_2, 0, sizeof(cl_mem), (void *)&insrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 1, sizeof(int), (void *)&inSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 2, sizeof(int), (void *)&inSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 3, sizeof(int), (void *)&inSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 4, sizeof(int), (void *)&inSrcShift);
    checkErr(status, "clSetKernelArg");
    size_t outDstWidth = 4802;
    size_t outDstHeight = 6408;
    size_t out_dstsz = sizeof(uint16_t);
    size_t outDstStep = outDstWidth * out_dstsz;
    outDstStep = (outDstStep % PADDING < 16) ? ((outDstStep / PADDING+1) * PADDING) : ((outDstStep + PADDING) / PADDING+1) * PADDING;
    size_t outDstShift = outDstStep * PADDING_LINE;
    size_t out_dstsz0Pad = outDstStep * (outDstHeight + (PADDING_LINE<<1));
    cl_mem outdstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, out_dstsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    uint16_t *outDstBufH = (uint16_t*)malloc(out_dstsz0Pad); 
    for(int i = 0; i < outDstHeight; i++){
  memcpy( (char*)outDstBufH+ (i + PADDING_LINE) * outDstStep,(char*)out + i * outDstWidth* sizeof(uint16_t),outDstWidth* sizeof(uint16_t) );
  }
    status = clEnqueueWriteBuffer(g_queue, outdstBuf, CL_TRUE, 0,out_dstsz0Pad,outDstBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_2, 5, sizeof(cl_mem), (void *)&outdstBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 6, sizeof(int), (void *)&outDstWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 7, sizeof(int), (void *)&outDstHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 8, sizeof(int), (void *)&outDstStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 9, sizeof(int), (void *)&outDstShift);
    checkErr(status, "clSetKernelArg");
    status = clEnqueueNDRangeKernel(g_queue, kernel_2, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
    checkErr(status, "clEnqueueNDRangeKernel");
    status = clFinish(g_queue);
    checkErr(status,"clFinish of kernel_2");
      status = clEnqueueReadBuffer(g_queue, outdstBuf, CL_TRUE, 0,out_dstsz0Pad,outDstBufH, 0, NULL, NULL);
    for(int i = 0; i < outDstHeight; i++){
  memcpy( (char*)out+ i *outDstWidth* sizeof(uint16_t), (char*) outDstBufH+ (i + PADDING_LINE)* outDstStep, outDstWidth* sizeof(uint16_t) );
  }
  
  }
}





int main() {
  char inputfile[] = "blur.cl";
  char remain[] = "-I ./";
  if (-1 == openCLCreate(inputfile, remain)) {
    printf("openCL create fail !!!!!!");
    return 0;
  }
  uint16_t *input = (uint16_t *)malloc(sizeof(uint16_t) * 4802 * 6408);
  uint16_t *meta = (uint16_t *)malloc(sizeof(uint16_t) * 4802 * 6408);
  uint16_t *output = (uint16_t *)malloc(sizeof(uint16_t) * 4802 * 6408);
  for (int i = 0; i < 6408; i++) 
    for (int j = 0; j < 4802; j++) 
      input[i * 4802 + j] = rand() % 4095;
  uint16_t (*src)[6408][4802] = (uint16_t (*)[6408][4802])input;
  uint16_t (*intermediate)[6408][4802] = (uint16_t (*)[6408][4802])meta;
  uint16_t (*dst)[6408][4802] = (uint16_t (*)[6408][4802])output;
  blur(src, intermediate, dst);
}


