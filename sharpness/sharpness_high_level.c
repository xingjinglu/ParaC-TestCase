/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

#include"CL/cl.h"
#include"ClHost.h"
#include<stdlib.h>

#define ROWS 1024
#define COLS 1024
#define M 1024
#define N 1024

struct __MMC_CSE_PARAMETER_PUBLIC {
  float peak;
  float cutoffCoef;
  float cutoff2;
  float cutoff3Coef;
};
typedef struct __MMC_CSE_PARAMETER_PUBLIC MMC_CSE_PARAMETER_PUBLIC;


//M is height, N is width
int DownScaleNewX16(unsigned char (*pImageSrc)[1024][1024], unsigned char (*pImageDst)[1024 / 4][1024 / 4]) {
  
  {
    size_t global_work_size[2];
    size_t transe;
    cl_event event_kernel;
    cl_kernel kernel_1 = clCreateKernel(g_program, "kernel_1", &status);
    checkErr(status, "clCreateKernel for kernel_1");
    global_work_size[0] = 256;
    global_work_size[1] = 256;
    size_t pImageSrcSrcWidth = 1024;
    size_t pImageSrcSrcHeight = 1024;
    size_t pImageSrc_srcsz = sizeof(unsigned char);
    size_t pImageSrcSrcStep = pImageSrcSrcWidth * pImageSrc_srcsz;
    pImageSrcSrcStep = (pImageSrcSrcStep % PADDING < 16) ? ((pImageSrcSrcStep / PADDING+1) * PADDING) : ((pImageSrcSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t pImageSrcSrcShift = pImageSrcSrcStep * PADDING_LINE;
    size_t pImageSrc_srcsz0Pad = pImageSrcSrcStep * (pImageSrcSrcHeight + (PADDING_LINE<<1));
    cl_mem pImageSrcsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, pImageSrc_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    unsigned char *pImageSrcSrcBufH = (unsigned char*)malloc(pImageSrc_srcsz0Pad); 
    for(int i = 0; i < pImageSrcSrcHeight; i++){
  memcpy( (char*)pImageSrcSrcBufH+ (i + PADDING_LINE) * pImageSrcSrcStep, (char*)pImageSrc+ i * pImageSrcSrcWidth* sizeof(unsigned char), pImageSrcSrcWidth * sizeof(unsigned char) );
  }
    status = clEnqueueWriteBuffer(g_queue, pImageSrcsrcBuf, CL_TRUE, 0,pImageSrc_srcsz0Pad,pImageSrcSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_1, 0, sizeof(cl_mem), (void *)&pImageSrcsrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 1, sizeof(int), (void *)&pImageSrcSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 2, sizeof(int), (void *)&pImageSrcSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 3, sizeof(int), (void *)&pImageSrcSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 4, sizeof(int), (void *)&pImageSrcSrcShift);
    checkErr(status, "clSetKernelArg");
    size_t pImageDstDstWidth = 256;
    size_t pImageDstDstHeight = 256;
    size_t pImageDst_dstsz = sizeof(unsigned char);
    size_t pImageDstDstStep = pImageDstDstWidth * pImageDst_dstsz;
    pImageDstDstStep = (pImageDstDstStep % PADDING < 16) ? ((pImageDstDstStep / PADDING+1) * PADDING) : ((pImageDstDstStep + PADDING) / PADDING+1) * PADDING;
    size_t pImageDstDstShift = pImageDstDstStep * PADDING_LINE;
    size_t pImageDst_dstsz0Pad = pImageDstDstStep * (pImageDstDstHeight + (PADDING_LINE<<1));
    cl_mem pImageDstdstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, pImageDst_dstsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    unsigned char *pImageDstDstBufH = (unsigned char*)malloc(pImageDst_dstsz0Pad); 
    for(int i = 0; i < pImageDstDstHeight; i++){
  memcpy( (char*)pImageDstDstBufH+ (i + PADDING_LINE) * pImageDstDstStep,(char*)pImageDst + i * pImageDstDstWidth* sizeof(unsigned char),pImageDstDstWidth* sizeof(unsigned char) );
  }
    status = clSetKernelArg(kernel_1, 5, sizeof(cl_mem), (void *)&pImageDstdstBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 6, sizeof(int), (void *)&pImageDstDstWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 7, sizeof(int), (void *)&pImageDstDstHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 8, sizeof(int), (void *)&pImageDstDstStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 9, sizeof(int), (void *)&pImageDstDstShift);
    checkErr(status, "clSetKernelArg");
    status = clEnqueueNDRangeKernel(g_queue, kernel_1, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
    checkErr(status, "clEnqueueNDRangeKernel");
    status = clFinish(g_queue);
    checkErr(status,"clFinish of kernel_1");
      status = clEnqueueReadBuffer(g_queue, pImageDstdstBuf, CL_TRUE, 0,pImageDst_dstsz0Pad,pImageDstDstBufH, 0, NULL, NULL);
    for(int i = 0; i < pImageDstDstHeight; i++){
  memcpy( (char*)pImageDst+ i *pImageDstDstWidth* sizeof(unsigned char), (char*) pImageDstDstBufH+ (i + PADDING_LINE)* pImageDstDstStep, pImageDstDstWidth* sizeof(unsigned char) );
  }
  
  }
}



int UpScaleNewX16(unsigned char (*srcImage)[1024 / 4][1024 / 4], unsigned char (*dstImage)[1024][1024]) {
  float border_mp_0[4][1] = { 1., 3 / 4.F, 2 / 4.F, 1 / 4.F };
  float border_mp_1[4][1] = { 0., 1 / 4.F, 2 / 4.F, 3 / 4.F };
  
  {
    size_t global_work_size[2];
    size_t transe;
    cl_event event_kernel;
    cl_kernel kernel_2 = clCreateKernel(g_program, "kernel_2", &status);
    checkErr(status, "clCreateKernel for kernel_2");
    global_work_size[0] = 256;
    global_work_size[1] = 1;
    size_t srcImageSrcWidth = 256;
    size_t srcImageSrcHeight = 256;
    size_t srcImage_srcsz = sizeof(unsigned char);
    size_t srcImageSrcStep = srcImageSrcWidth * srcImage_srcsz;
    srcImageSrcStep = (srcImageSrcStep % PADDING < 16) ? ((srcImageSrcStep / PADDING+1) * PADDING) : ((srcImageSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t srcImageSrcShift = srcImageSrcStep * PADDING_LINE;
    size_t srcImage_srcsz0Pad = srcImageSrcStep * (srcImageSrcHeight + (PADDING_LINE<<1));
    cl_mem srcImagesrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, srcImage_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    unsigned char *srcImageSrcBufH = (unsigned char*)malloc(srcImage_srcsz0Pad); 
    for(int i = 0; i < srcImageSrcHeight; i++){
  memcpy( (char*)srcImageSrcBufH+ (i + PADDING_LINE) * srcImageSrcStep, (char*)srcImage+ i * srcImageSrcWidth* sizeof(unsigned char), srcImageSrcWidth * sizeof(unsigned char) );
  }
    status = clEnqueueWriteBuffer(g_queue, srcImagesrcBuf, CL_TRUE, 0,srcImage_srcsz0Pad,srcImageSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_2, 0, sizeof(cl_mem), (void *)&srcImagesrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 1, sizeof(int), (void *)&srcImageSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 2, sizeof(int), (void *)&srcImageSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 3, sizeof(int), (void *)&srcImageSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 4, sizeof(int), (void *)&srcImageSrcShift);
    checkErr(status, "clSetKernelArg");
    size_t border_mp_0SrcWidth = 1;
    size_t border_mp_0SrcHeight = 4;
    size_t border_mp_0_srcsz = sizeof(float);
    size_t border_mp_0SrcStep = border_mp_0SrcWidth * border_mp_0_srcsz;
    border_mp_0SrcStep = (border_mp_0SrcStep % PADDING < 16) ? ((border_mp_0SrcStep / PADDING+1) * PADDING) : ((border_mp_0SrcStep + PADDING) / PADDING+1) * PADDING;
    size_t border_mp_0SrcShift = border_mp_0SrcStep * PADDING_LINE;
    size_t border_mp_0_srcsz0Pad = border_mp_0SrcStep * (border_mp_0SrcHeight + (PADDING_LINE<<1));
    cl_mem border_mp_0srcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, border_mp_0_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    float *border_mp_0SrcBufH = (float*)malloc(border_mp_0_srcsz0Pad); 
    for(int i = 0; i < border_mp_0SrcHeight; i++){
  memcpy( (char*)border_mp_0SrcBufH+ (i + PADDING_LINE) * border_mp_0SrcStep, (char*)border_mp_0+ i * border_mp_0SrcWidth* sizeof(float), border_mp_0SrcWidth * sizeof(float) );
  }
    status = clEnqueueWriteBuffer(g_queue, border_mp_0srcBuf, CL_TRUE, 0,border_mp_0_srcsz0Pad,border_mp_0SrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_2, 5, sizeof(cl_mem), (void *)&border_mp_0srcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 6, sizeof(int), (void *)&border_mp_0SrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 7, sizeof(int), (void *)&border_mp_0SrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 8, sizeof(int), (void *)&border_mp_0SrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 9, sizeof(int), (void *)&border_mp_0SrcShift);
    checkErr(status, "clSetKernelArg");
    size_t border_mp_1SrcWidth = 1;
    size_t border_mp_1SrcHeight = 4;
    size_t border_mp_1_srcsz = sizeof(float);
    size_t border_mp_1SrcStep = border_mp_1SrcWidth * border_mp_1_srcsz;
    border_mp_1SrcStep = (border_mp_1SrcStep % PADDING < 16) ? ((border_mp_1SrcStep / PADDING+1) * PADDING) : ((border_mp_1SrcStep + PADDING) / PADDING+1) * PADDING;
    size_t border_mp_1SrcShift = border_mp_1SrcStep * PADDING_LINE;
    size_t border_mp_1_srcsz0Pad = border_mp_1SrcStep * (border_mp_1SrcHeight + (PADDING_LINE<<1));
    cl_mem border_mp_1srcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, border_mp_1_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    float *border_mp_1SrcBufH = (float*)malloc(border_mp_1_srcsz0Pad); 
    for(int i = 0; i < border_mp_1SrcHeight; i++){
  memcpy( (char*)border_mp_1SrcBufH+ (i + PADDING_LINE) * border_mp_1SrcStep, (char*)border_mp_1+ i * border_mp_1SrcWidth* sizeof(float), border_mp_1SrcWidth * sizeof(float) );
  }
    status = clEnqueueWriteBuffer(g_queue, border_mp_1srcBuf, CL_TRUE, 0,border_mp_1_srcsz0Pad,border_mp_1SrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_2, 10, sizeof(cl_mem), (void *)&border_mp_1srcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 11, sizeof(int), (void *)&border_mp_1SrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 12, sizeof(int), (void *)&border_mp_1SrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 13, sizeof(int), (void *)&border_mp_1SrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 14, sizeof(int), (void *)&border_mp_1SrcShift);
    checkErr(status, "clSetKernelArg");
    size_t dstImageDSWidth = 1024;
    size_t dstImageDSHeight = 1024;
    size_t dstImage_dssz = sizeof(unsigned char);
    size_t dstImageDSStep = dstImageDSWidth * dstImage_dssz;
    dstImageDSStep = (dstImageDSStep % PADDING < 16) ? ((dstImageDSStep / PADDING+1) * PADDING) : ((dstImageDSStep + PADDING) / PADDING+1) * PADDING;
    size_t dstImageDSShift = dstImageDSStep * PADDING_LINE;
    size_t dstImage_dssz0Pad = dstImageDSStep * (dstImageDSHeight + (PADDING_LINE<<1));
    cl_mem dstImagedsBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, dstImage_dssz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    unsigned char *dstImageDsBufH = (unsigned char*)malloc (dstImage_dssz0Pad); 
    for(int i = 0; i < dstImageDSHeight; i++){
  memcpy((char*)dstImageDsBufH + (i + PADDING_LINE) * dstImageDSStep, (char*)dstImage+ i * dstImageDSWidth * sizeof(unsigned char), dstImageDSWidth* sizeof(unsigned char) );
  }
    status = clEnqueueWriteBuffer(g_queue, dstImagedsBuf, CL_TRUE, 0,dstImage_dssz0Pad, dstImageDsBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_2, 15, sizeof(cl_mem), (void *)&dstImagedsBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 16, sizeof(int), (void *)&dstImageDSWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 17, sizeof(int), (void *)&dstImageDSHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 18, sizeof(int), (void *)&dstImageDSStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 19, sizeof(int), (void *)&dstImageDSShift);
    checkErr(status, "clSetKernelArg");
    status = clEnqueueNDRangeKernel(g_queue, kernel_2, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
    checkErr(status, "clEnqueueNDRangeKernel");
    status = clFinish(g_queue);
    checkErr(status,"clFinish of kernel_2");
      status = clEnqueueReadBuffer(g_queue, dstImagedsBuf, CL_TRUE, 0,dstImage_dssz0Pad,dstImageDsBufH, 0, NULL, NULL);
    for(int i = 0; i < dstImageDSHeight; i++){
  memcpy( (char*)dstImage+ i *dstImageDSWidth* sizeof(unsigned char), (char*) dstImageDsBufH+ (i + PADDING_LINE)* dstImageDSStep, dstImageDSWidth* sizeof(unsigned char) );
  }
  
  }
  
  {
    size_t global_work_size[2];
    size_t transe;
    cl_event event_kernel;
    cl_kernel kernel_3 = clCreateKernel(g_program, "kernel_3", &status);
    checkErr(status, "clCreateKernel for kernel_3");
    global_work_size[0] = 1;
    global_work_size[1] = 256;
    size_t srcImageSrcWidth = 256;
    size_t srcImageSrcHeight = 256;
    size_t srcImage_srcsz = sizeof(unsigned char);
    size_t srcImageSrcStep = srcImageSrcWidth * srcImage_srcsz;
    srcImageSrcStep = (srcImageSrcStep % PADDING < 16) ? ((srcImageSrcStep / PADDING+1) * PADDING) : ((srcImageSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t srcImageSrcShift = srcImageSrcStep * PADDING_LINE;
    size_t srcImage_srcsz0Pad = srcImageSrcStep * (srcImageSrcHeight + (PADDING_LINE<<1));
    cl_mem srcImagesrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, srcImage_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    unsigned char *srcImageSrcBufH = (unsigned char*)malloc(srcImage_srcsz0Pad); 
    for(int i = 0; i < srcImageSrcHeight; i++){
  memcpy( (char*)srcImageSrcBufH+ (i + PADDING_LINE) * srcImageSrcStep, (char*)srcImage+ i * srcImageSrcWidth* sizeof(unsigned char), srcImageSrcWidth * sizeof(unsigned char) );
  }
    status = clEnqueueWriteBuffer(g_queue, srcImagesrcBuf, CL_TRUE, 0,srcImage_srcsz0Pad,srcImageSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_3, 0, sizeof(cl_mem), (void *)&srcImagesrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 1, sizeof(int), (void *)&srcImageSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 2, sizeof(int), (void *)&srcImageSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 3, sizeof(int), (void *)&srcImageSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 4, sizeof(int), (void *)&srcImageSrcShift);
    checkErr(status, "clSetKernelArg");
    size_t border_mp_0SrcWidth = 1;
    size_t border_mp_0SrcHeight = 4;
    transe = border_mp_0SrcWidth;
    border_mp_0SrcWidth = border_mp_0SrcHeight;
    border_mp_0SrcHeight = transe;
    size_t border_mp_0_srcsz = sizeof(float);
    size_t border_mp_0SrcStep = border_mp_0SrcWidth * border_mp_0_srcsz;
    border_mp_0SrcStep = (border_mp_0SrcStep % PADDING < 16) ? ((border_mp_0SrcStep / PADDING+1) * PADDING) : ((border_mp_0SrcStep + PADDING) / PADDING+1) * PADDING;
    size_t border_mp_0SrcShift = border_mp_0SrcStep * PADDING_LINE;
    size_t border_mp_0_srcsz0Pad = border_mp_0SrcStep * (border_mp_0SrcHeight + (PADDING_LINE<<1));
    cl_mem border_mp_0srcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, border_mp_0_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    float *border_mp_0SrcBufH = (float*)malloc(border_mp_0_srcsz0Pad); 
    for(int i = 0; i < border_mp_0SrcHeight; i++){
  memcpy( (char*)border_mp_0SrcBufH+ (i + PADDING_LINE) * border_mp_0SrcStep, (char*)border_mp_0+ i * border_mp_0SrcWidth* sizeof(float), border_mp_0SrcWidth * sizeof(float) );
  }
    status = clEnqueueWriteBuffer(g_queue, border_mp_0srcBuf, CL_TRUE, 0,border_mp_0_srcsz0Pad,border_mp_0SrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_3, 5, sizeof(cl_mem), (void *)&border_mp_0srcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 6, sizeof(int), (void *)&border_mp_0SrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 7, sizeof(int), (void *)&border_mp_0SrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 8, sizeof(int), (void *)&border_mp_0SrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 9, sizeof(int), (void *)&border_mp_0SrcShift);
    checkErr(status, "clSetKernelArg");
    size_t border_mp_1SrcWidth = 1;
    size_t border_mp_1SrcHeight = 4;
    transe = border_mp_1SrcWidth;
    border_mp_1SrcWidth = border_mp_1SrcHeight;
    border_mp_1SrcHeight = transe;
    size_t border_mp_1_srcsz = sizeof(float);
    size_t border_mp_1SrcStep = border_mp_1SrcWidth * border_mp_1_srcsz;
    border_mp_1SrcStep = (border_mp_1SrcStep % PADDING < 16) ? ((border_mp_1SrcStep / PADDING+1) * PADDING) : ((border_mp_1SrcStep + PADDING) / PADDING+1) * PADDING;
    size_t border_mp_1SrcShift = border_mp_1SrcStep * PADDING_LINE;
    size_t border_mp_1_srcsz0Pad = border_mp_1SrcStep * (border_mp_1SrcHeight + (PADDING_LINE<<1));
    cl_mem border_mp_1srcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, border_mp_1_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    float *border_mp_1SrcBufH = (float*)malloc(border_mp_1_srcsz0Pad); 
    for(int i = 0; i < border_mp_1SrcHeight; i++){
  memcpy( (char*)border_mp_1SrcBufH+ (i + PADDING_LINE) * border_mp_1SrcStep, (char*)border_mp_1+ i * border_mp_1SrcWidth* sizeof(float), border_mp_1SrcWidth * sizeof(float) );
  }
    status = clEnqueueWriteBuffer(g_queue, border_mp_1srcBuf, CL_TRUE, 0,border_mp_1_srcsz0Pad,border_mp_1SrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_3, 10, sizeof(cl_mem), (void *)&border_mp_1srcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 11, sizeof(int), (void *)&border_mp_1SrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 12, sizeof(int), (void *)&border_mp_1SrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 13, sizeof(int), (void *)&border_mp_1SrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 14, sizeof(int), (void *)&border_mp_1SrcShift);
    checkErr(status, "clSetKernelArg");
    size_t dstImageDSWidth = 1024;
    size_t dstImageDSHeight = 1024;
    size_t dstImage_dssz = sizeof(unsigned char);
    size_t dstImageDSStep = dstImageDSWidth * dstImage_dssz;
    dstImageDSStep = (dstImageDSStep % PADDING < 16) ? ((dstImageDSStep / PADDING+1) * PADDING) : ((dstImageDSStep + PADDING) / PADDING+1) * PADDING;
    size_t dstImageDSShift = dstImageDSStep * PADDING_LINE;
    size_t dstImage_dssz0Pad = dstImageDSStep * (dstImageDSHeight + (PADDING_LINE<<1));
    cl_mem dstImagedsBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, dstImage_dssz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    unsigned char *dstImageDsBufH = (unsigned char*)malloc (dstImage_dssz0Pad); 
    for(int i = 0; i < dstImageDSHeight; i++){
  memcpy((char*)dstImageDsBufH + (i + PADDING_LINE) * dstImageDSStep, (char*)dstImage+ i * dstImageDSWidth * sizeof(unsigned char), dstImageDSWidth* sizeof(unsigned char) );
  }
    status = clEnqueueWriteBuffer(g_queue, dstImagedsBuf, CL_TRUE, 0,dstImage_dssz0Pad, dstImageDsBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_3, 15, sizeof(cl_mem), (void *)&dstImagedsBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 16, sizeof(int), (void *)&dstImageDSWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 17, sizeof(int), (void *)&dstImageDSHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 18, sizeof(int), (void *)&dstImageDSStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_3, 19, sizeof(int), (void *)&dstImageDSShift);
    checkErr(status, "clSetKernelArg");
    status = clEnqueueNDRangeKernel(g_queue, kernel_3, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
    checkErr(status, "clEnqueueNDRangeKernel");
    status = clFinish(g_queue);
    checkErr(status,"clFinish of kernel_3");
      status = clEnqueueReadBuffer(g_queue, dstImagedsBuf, CL_TRUE, 0,dstImage_dssz0Pad,dstImageDsBufH, 0, NULL, NULL);
    for(int i = 0; i < dstImageDSHeight; i++){
  memcpy( (char*)dstImage+ i *dstImageDSWidth* sizeof(unsigned char), (char*) dstImageDsBufH+ (i + PADDING_LINE)* dstImageDSStep, dstImageDSWidth* sizeof(unsigned char) );
  }
  
  }
  float mp[4][2] = { 7 / 8.F, 1 / 8.F, 5 / 8.F, 3 / 8.F, 3 / 8.F, 5 / 8.F, 1 / 8.F, 7 / 8.F };
  
  {
    size_t global_work_size[2];
    size_t transe;
    cl_event event_kernel;
    cl_kernel kernel_4 = clCreateKernel(g_program, "kernel_4", &status);
    checkErr(status, "clCreateKernel for kernel_4");
    global_work_size[0] = 255;
    global_work_size[1] = 255;
    size_t srcImageSrcWidth = 256;
    size_t srcImageSrcHeight = 256;
    size_t srcImage_srcsz = sizeof(unsigned char);
    size_t srcImageSrcStep = srcImageSrcWidth * srcImage_srcsz;
    srcImageSrcStep = (srcImageSrcStep % PADDING < 16) ? ((srcImageSrcStep / PADDING+1) * PADDING) : ((srcImageSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t srcImageSrcShift = srcImageSrcStep * PADDING_LINE;
    size_t srcImage_srcsz0Pad = srcImageSrcStep * (srcImageSrcHeight + (PADDING_LINE<<1));
    cl_mem srcImagesrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, srcImage_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    unsigned char *srcImageSrcBufH = (unsigned char*)malloc(srcImage_srcsz0Pad); 
    for(int i = 0; i < srcImageSrcHeight; i++){
  memcpy( (char*)srcImageSrcBufH+ (i + PADDING_LINE) * srcImageSrcStep, (char*)srcImage+ i * srcImageSrcWidth* sizeof(unsigned char), srcImageSrcWidth * sizeof(unsigned char) );
  }
    status = clEnqueueWriteBuffer(g_queue, srcImagesrcBuf, CL_TRUE, 0,srcImage_srcsz0Pad,srcImageSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_4, 0, sizeof(cl_mem), (void *)&srcImagesrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_4, 1, sizeof(int), (void *)&srcImageSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_4, 2, sizeof(int), (void *)&srcImageSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_4, 3, sizeof(int), (void *)&srcImageSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_4, 4, sizeof(int), (void *)&srcImageSrcShift);
    checkErr(status, "clSetKernelArg");
    size_t mpSrcWidth = 2;
    size_t mpSrcHeight = 4;
    size_t mp_srcsz = sizeof(float);
    size_t mpSrcStep = mpSrcWidth * mp_srcsz;
    mpSrcStep = (mpSrcStep % PADDING < 16) ? ((mpSrcStep / PADDING+1) * PADDING) : ((mpSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t mpSrcShift = mpSrcStep * PADDING_LINE;
    size_t mp_srcsz0Pad = mpSrcStep * (mpSrcHeight + (PADDING_LINE<<1));
    cl_mem mpsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, mp_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    float *mpSrcBufH = (float*)malloc(mp_srcsz0Pad); 
    for(int i = 0; i < mpSrcHeight; i++){
  memcpy( (char*)mpSrcBufH+ (i + PADDING_LINE) * mpSrcStep, (char*)mp+ i * mpSrcWidth* sizeof(float), mpSrcWidth * sizeof(float) );
  }
    status = clEnqueueWriteBuffer(g_queue, mpsrcBuf, CL_TRUE, 0,mp_srcsz0Pad,mpSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_4, 5, sizeof(cl_mem), (void *)&mpsrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_4, 6, sizeof(int), (void *)&mpSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_4, 7, sizeof(int), (void *)&mpSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_4, 8, sizeof(int), (void *)&mpSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_4, 9, sizeof(int), (void *)&mpSrcShift);
    checkErr(status, "clSetKernelArg");
    size_t dstImageDstWidth = 1024;
    size_t dstImageDstHeight = 1024;
    size_t dstImage_dstsz = sizeof(unsigned char);
    size_t dstImageDstStep = dstImageDstWidth * dstImage_dstsz;
    dstImageDstStep = (dstImageDstStep % PADDING < 16) ? ((dstImageDstStep / PADDING+1) * PADDING) : ((dstImageDstStep + PADDING) / PADDING+1) * PADDING;
    size_t dstImageDstShift = dstImageDstStep * PADDING_LINE;
    size_t dstImage_dstsz0Pad = dstImageDstStep * (dstImageDstHeight + (PADDING_LINE<<1));
    cl_mem dstImagedstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, dstImage_dstsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    unsigned char *dstImageDstBufH = (unsigned char*)malloc(dstImage_dstsz0Pad); 
    for(int i = 0; i < dstImageDstHeight; i++){
  memcpy( (char*)dstImageDstBufH+ (i + PADDING_LINE) * dstImageDstStep,(char*)dstImage + i * dstImageDstWidth* sizeof(unsigned char),dstImageDstWidth* sizeof(unsigned char) );
  }
    status = clEnqueueWriteBuffer(g_queue, dstImagedstBuf, CL_TRUE, 0,dstImage_dstsz0Pad,dstImageDstBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_4, 10, sizeof(cl_mem), (void *)&dstImagedstBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_4, 11, sizeof(int), (void *)&dstImageDstWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_4, 12, sizeof(int), (void *)&dstImageDstHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_4, 13, sizeof(int), (void *)&dstImageDstStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_4, 14, sizeof(int), (void *)&dstImageDstShift);
    checkErr(status, "clSetKernelArg");
    status = clEnqueueNDRangeKernel(g_queue, kernel_4, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
    checkErr(status, "clEnqueueNDRangeKernel");
    status = clFinish(g_queue);
    checkErr(status,"clFinish of kernel_4");
      status = clEnqueueReadBuffer(g_queue, dstImagedstBuf, CL_TRUE, 0,dstImage_dstsz0Pad,dstImageDstBufH, 0, NULL, NULL);
    for(int i = 0; i < dstImageDstHeight; i++){
  memcpy( (char*)dstImage+ i *dstImageDstWidth* sizeof(unsigned char), (char*) dstImageDstBufH+ (i + PADDING_LINE)* dstImageDstStep, dstImageDstWidth* sizeof(unsigned char) );
  }
  
  }
}



void Sharpness(unsigned char (*yPlane)[1024][1024], unsigned char (*yPlaneCSER)[1024][1024], unsigned char (*dst)[1024][1024], MMC_CSE_PARAMETER_PUBLIC &cseParamPublic) {
  unsigned short pEdge[1024][1024];
  char gx[3][3] = { -1, 0, 1, -2, 0, 2, -1, 0, 1 };
  char gy[3][3] = { 1, 2, 1, 0, 0, 0, -1, -2, -1 };
  
  {
    size_t global_work_size[2];
    size_t transe;
    cl_event event_kernel;
    cl_kernel kernel_5 = clCreateKernel(g_program, "kernel_5", &status);
    checkErr(status, "clCreateKernel for kernel_5");
    global_work_size[0] = 1024;
    global_work_size[1] = 1024;
    size_t yPlaneSrcWidth = 1024;
    size_t yPlaneSrcHeight = 1024;
    size_t yPlane_srcsz = sizeof(unsigned char);
    size_t yPlaneSrcStep = yPlaneSrcWidth * yPlane_srcsz;
    yPlaneSrcStep = (yPlaneSrcStep % PADDING < 16) ? ((yPlaneSrcStep / PADDING+1) * PADDING) : ((yPlaneSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t yPlaneSrcShift = yPlaneSrcStep * PADDING_LINE;
    size_t yPlane_srcsz0Pad = yPlaneSrcStep * (yPlaneSrcHeight + (PADDING_LINE<<1));
    cl_mem yPlanesrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, yPlane_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    unsigned char *yPlaneSrcBufH = (unsigned char*)malloc(yPlane_srcsz0Pad); 
    for(int i = 0; i < yPlaneSrcHeight; i++){
  memcpy( (char*)yPlaneSrcBufH+ (i + PADDING_LINE) * yPlaneSrcStep, (char*)yPlane+ i * yPlaneSrcWidth* sizeof(unsigned char), yPlaneSrcWidth * sizeof(unsigned char) );
  }
    status = clEnqueueWriteBuffer(g_queue, yPlanesrcBuf, CL_TRUE, 0,yPlane_srcsz0Pad,yPlaneSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_5, 0, sizeof(cl_mem), (void *)&yPlanesrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_5, 1, sizeof(int), (void *)&yPlaneSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_5, 2, sizeof(int), (void *)&yPlaneSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_5, 3, sizeof(int), (void *)&yPlaneSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_5, 4, sizeof(int), (void *)&yPlaneSrcShift);
    checkErr(status, "clSetKernelArg");
    size_t gxSrcWidth = 3;
    size_t gxSrcHeight = 3;
    size_t gx_srcsz = sizeof(char);
    size_t gxSrcStep = gxSrcWidth * gx_srcsz;
    gxSrcStep = (gxSrcStep % PADDING < 16) ? ((gxSrcStep / PADDING+1) * PADDING) : ((gxSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t gxSrcShift = gxSrcStep * PADDING_LINE;
    size_t gx_srcsz0Pad = gxSrcStep * (gxSrcHeight + (PADDING_LINE<<1));
    cl_mem gxsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, gx_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    char *gxSrcBufH = (char*)malloc(gx_srcsz0Pad); 
    for(int i = 0; i < gxSrcHeight; i++){
  memcpy( (char*)gxSrcBufH+ (i + PADDING_LINE) * gxSrcStep, (char*)gx+ i * gxSrcWidth* sizeof(char), gxSrcWidth * sizeof(char) );
  }
    status = clEnqueueWriteBuffer(g_queue, gxsrcBuf, CL_TRUE, 0,gx_srcsz0Pad,gxSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_5, 5, sizeof(cl_mem), (void *)&gxsrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_5, 6, sizeof(int), (void *)&gxSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_5, 7, sizeof(int), (void *)&gxSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_5, 8, sizeof(int), (void *)&gxSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_5, 9, sizeof(int), (void *)&gxSrcShift);
    checkErr(status, "clSetKernelArg");
    size_t gySrcWidth = 3;
    size_t gySrcHeight = 3;
    size_t gy_srcsz = sizeof(char);
    size_t gySrcStep = gySrcWidth * gy_srcsz;
    gySrcStep = (gySrcStep % PADDING < 16) ? ((gySrcStep / PADDING+1) * PADDING) : ((gySrcStep + PADDING) / PADDING+1) * PADDING;
    size_t gySrcShift = gySrcStep * PADDING_LINE;
    size_t gy_srcsz0Pad = gySrcStep * (gySrcHeight + (PADDING_LINE<<1));
    cl_mem gysrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, gy_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    char *gySrcBufH = (char*)malloc(gy_srcsz0Pad); 
    for(int i = 0; i < gySrcHeight; i++){
  memcpy( (char*)gySrcBufH+ (i + PADDING_LINE) * gySrcStep, (char*)gy+ i * gySrcWidth* sizeof(char), gySrcWidth * sizeof(char) );
  }
    status = clEnqueueWriteBuffer(g_queue, gysrcBuf, CL_TRUE, 0,gy_srcsz0Pad,gySrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_5, 10, sizeof(cl_mem), (void *)&gysrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_5, 11, sizeof(int), (void *)&gySrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_5, 12, sizeof(int), (void *)&gySrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_5, 13, sizeof(int), (void *)&gySrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_5, 14, sizeof(int), (void *)&gySrcShift);
    checkErr(status, "clSetKernelArg");
    size_t pEdgeDstWidth = 1024;
    size_t pEdgeDstHeight = 1024;
    size_t pEdge_dstsz = sizeof(unsigned short);
    size_t pEdgeDstStep = pEdgeDstWidth * pEdge_dstsz;
    pEdgeDstStep = (pEdgeDstStep % PADDING < 16) ? ((pEdgeDstStep / PADDING+1) * PADDING) : ((pEdgeDstStep + PADDING) / PADDING+1) * PADDING;
    size_t pEdgeDstShift = pEdgeDstStep * PADDING_LINE;
    size_t pEdge_dstsz0Pad = pEdgeDstStep * (pEdgeDstHeight + (PADDING_LINE<<1));
    cl_mem pEdgedstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, pEdge_dstsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    unsigned short *pEdgeDstBufH = (unsigned short*)malloc(pEdge_dstsz0Pad); 
    for(int i = 0; i < pEdgeDstHeight; i++){
  memcpy( (char*)pEdgeDstBufH+ (i + PADDING_LINE) * pEdgeDstStep,(char*)pEdge + i * pEdgeDstWidth* sizeof(unsigned short),pEdgeDstWidth* sizeof(unsigned short) );
  }
    status = clSetKernelArg(kernel_5, 15, sizeof(cl_mem), (void *)&pEdgedstBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_5, 16, sizeof(int), (void *)&pEdgeDstWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_5, 17, sizeof(int), (void *)&pEdgeDstHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_5, 18, sizeof(int), (void *)&pEdgeDstStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_5, 19, sizeof(int), (void *)&pEdgeDstShift);
    checkErr(status, "clSetKernelArg");
    status = clEnqueueNDRangeKernel(g_queue, kernel_5, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
    checkErr(status, "clEnqueueNDRangeKernel");
    status = clFinish(g_queue);
    checkErr(status,"clFinish of kernel_5");
      status = clEnqueueReadBuffer(g_queue, pEdgedstBuf, CL_TRUE, 0,pEdge_dstsz0Pad,pEdgeDstBufH, 0, NULL, NULL);
    for(int i = 0; i < pEdgeDstHeight; i++){
  memcpy( (char*)pEdge+ i *pEdgeDstWidth* sizeof(unsigned short), (char*) pEdgeDstBufH+ (i + PADDING_LINE)* pEdgeDstStep, pEdgeDstWidth* sizeof(unsigned short) );
  }
  
  }
  
  int item = 0;
  
  {
    size_t global_work_size[2];
    size_t transe;
    cl_event event_kernel;
    cl_kernel kernel_6 = clCreateKernel(g_program, "kernel_6", &status);
    checkErr(status, "clCreateKernel for kernel_6");
    size_t pEdgeSrcWidth = 1024;
    size_t pEdgeSrcHeight = 1024;
    global_work_size[0] = 256;
    global_work_size[1] = 1024;
    size_t local_work_size[2];
    local_work_size[0] = 256;
    local_work_size[1] = 1;
    size_t pEdge_srcsz = sizeof(unsigned short);
    size_t pEdgeSrcStep = pEdgeSrcWidth * pEdge_srcsz;
    pEdgeSrcStep = (pEdgeSrcStep % PADDING < 16) ? ((pEdgeSrcStep / PADDING+1) * PADDING) : ((pEdgeSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t pEdgeSrcShift = pEdgeSrcStep * PADDING_LINE;
    size_t pEdge_srcsz0Pad = pEdgeSrcStep * (pEdgeSrcHeight + (PADDING_LINE<<1));
    cl_mem pEdgesrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, pEdge_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    unsigned short *pEdgeSrcBufH = (unsigned short*)malloc(pEdge_srcsz0Pad); 
    for(int i = 0; i < pEdgeSrcHeight; i++){
  memcpy( (char*)pEdgeSrcBufH+ (i + PADDING_LINE) * pEdgeSrcStep, (char*)pEdge+ i * pEdgeSrcWidth* sizeof(unsigned short), pEdgeSrcWidth * sizeof(unsigned short) );
  }
    status = clEnqueueWriteBuffer(g_queue, pEdgesrcBuf, CL_TRUE, 0,pEdge_srcsz0Pad,pEdgeSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_6, 0, sizeof(cl_mem), (void *)&pEdgesrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_6, 1, sizeof(int), (void *)&pEdgeSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_6, 2, sizeof(int), (void *)&pEdgeSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_6, 3, sizeof(int), (void *)&pEdgeSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_6, 4, sizeof(int), (void *)&pEdgeSrcShift);
    checkErr(status, "clSetKernelArg");
    cl_mem outputBuffer2 = clCreateBuffer(g_context, CL_MEM_READ_WRITE, sizeof(int), NULL, &status);
    checkErr(status,"clCreateBuffer");
    status = clEnqueueWriteBuffer(g_queue, outputBuffer2, CL_TRUE, 0, sizeof(int), &item, 0, NULL, NULL);
    checkErr(status,"clEnqueueWrite");
    status = clSetKernelArg(kernel_6, 5, sizeof(cl_mem), (void *)&outputBuffer2);
    checkErr(status,"clSetKernelArg");
    status = clSetKernelArg(kernel_6, 6, sizeof(unsigned int) * local_work_size[0] * local_work_size[1], NULL);
    checkErr(status,"clSetKernelArg");
    status = clEnqueueNDRangeKernel(g_queue, kernel_6, 2, NULL, global_work_size, local_work_size, 0, NULL, &event_kernel);
    checkErr(status, "clEnqueueNDRangeKernel");
    status = clFinish(g_queue);
    checkErr(status,"clFinish of kernel_6");
    status = clEnqueueReadBuffer(g_queue, outputBuffer2, CL_TRUE, 0, sizeof(int), &item, 0, NULL, NULL);
    checkErr(status,"clEnqueueReadBuffer");
  
  }
  short mean = item / (1024 * 1024) + 1 / 2;
  cseParamPublic.cutoff2 = 256.F;
  cseParamPublic.cutoff3Coef = 1.F;
  cseParamPublic.cutoffCoef = 1.F;
  cseParamPublic.peak = 2.F;
  float weight_tmp = (1 / cseParamPublic.cutoff2);
  float strength_tmp = 1 / cseParamPublic.cutoffCoef * mean;
  float tmp2 = cseParamPublic.peak - 1.;
  float cutoff2Order = pow(cseParamPublic.cutoff3Coef * mean, 4);
  
  float m1 = 1. / mean;
  m1 = m1 * m1 * m1 * m1;
  float m2 = 1. / 256;
  m2 = m2 * m2 * m2 * m2;
  
  {
    size_t global_work_size[2];
    size_t transe;
    cl_event event_kernel;
    cl_kernel kernel_7 = clCreateKernel(g_program, "kernel_7", &status);
    checkErr(status, "clCreateKernel for kernel_7");
    global_work_size[0] = 256;
    global_work_size[1] = 1024;
    size_t yPlaneSrcWidth = 1024;
    size_t yPlaneSrcHeight = 1024;
    size_t yPlane_srcsz = sizeof(unsigned char);
    size_t yPlaneSrcStep = yPlaneSrcWidth * yPlane_srcsz;
    yPlaneSrcStep = (yPlaneSrcStep % PADDING < 16) ? ((yPlaneSrcStep / PADDING+1) * PADDING) : ((yPlaneSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t yPlaneSrcShift = yPlaneSrcStep * PADDING_LINE;
    size_t yPlane_srcsz0Pad = yPlaneSrcStep * (yPlaneSrcHeight + (PADDING_LINE<<1));
    cl_mem yPlanesrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, yPlane_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    unsigned char *yPlaneSrcBufH = (unsigned char*)malloc(yPlane_srcsz0Pad); 
    for(int i = 0; i < yPlaneSrcHeight; i++){
  memcpy( (char*)yPlaneSrcBufH+ (i + PADDING_LINE) * yPlaneSrcStep, (char*)yPlane+ i * yPlaneSrcWidth* sizeof(unsigned char), yPlaneSrcWidth * sizeof(unsigned char) );
  }
    status = clEnqueueWriteBuffer(g_queue, yPlanesrcBuf, CL_TRUE, 0,yPlane_srcsz0Pad,yPlaneSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_7, 0, sizeof(cl_mem), (void *)&yPlanesrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_7, 1, sizeof(int), (void *)&yPlaneSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_7, 2, sizeof(int), (void *)&yPlaneSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_7, 3, sizeof(int), (void *)&yPlaneSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_7, 4, sizeof(int), (void *)&yPlaneSrcShift);
    checkErr(status, "clSetKernelArg");
    size_t yPlaneCSERSrcWidth = 1024;
    size_t yPlaneCSERSrcHeight = 1024;
    size_t yPlaneCSER_srcsz = sizeof(unsigned char);
    size_t yPlaneCSERSrcStep = yPlaneCSERSrcWidth * yPlaneCSER_srcsz;
    yPlaneCSERSrcStep = (yPlaneCSERSrcStep % PADDING < 16) ? ((yPlaneCSERSrcStep / PADDING+1) * PADDING) : ((yPlaneCSERSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t yPlaneCSERSrcShift = yPlaneCSERSrcStep * PADDING_LINE;
    size_t yPlaneCSER_srcsz0Pad = yPlaneCSERSrcStep * (yPlaneCSERSrcHeight + (PADDING_LINE<<1));
    cl_mem yPlaneCSERsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, yPlaneCSER_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    unsigned char *yPlaneCSERSrcBufH = (unsigned char*)malloc(yPlaneCSER_srcsz0Pad); 
    for(int i = 0; i < yPlaneCSERSrcHeight; i++){
  memcpy( (char*)yPlaneCSERSrcBufH+ (i + PADDING_LINE) * yPlaneCSERSrcStep, (char*)yPlaneCSER+ i * yPlaneCSERSrcWidth* sizeof(unsigned char), yPlaneCSERSrcWidth * sizeof(unsigned char) );
  }
    status = clEnqueueWriteBuffer(g_queue, yPlaneCSERsrcBuf, CL_TRUE, 0,yPlaneCSER_srcsz0Pad,yPlaneCSERSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_7, 5, sizeof(cl_mem), (void *)&yPlaneCSERsrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_7, 6, sizeof(int), (void *)&yPlaneCSERSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_7, 7, sizeof(int), (void *)&yPlaneCSERSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_7, 8, sizeof(int), (void *)&yPlaneCSERSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_7, 9, sizeof(int), (void *)&yPlaneCSERSrcShift);
    checkErr(status, "clSetKernelArg");
    size_t pEdgeSrcWidth = 1024;
    size_t pEdgeSrcHeight = 1024;
    size_t pEdge_srcsz = sizeof(unsigned short);
    size_t pEdgeSrcStep = pEdgeSrcWidth * pEdge_srcsz;
    pEdgeSrcStep = (pEdgeSrcStep % PADDING < 16) ? ((pEdgeSrcStep / PADDING+1) * PADDING) : ((pEdgeSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t pEdgeSrcShift = pEdgeSrcStep * PADDING_LINE;
    size_t pEdge_srcsz0Pad = pEdgeSrcStep * (pEdgeSrcHeight + (PADDING_LINE<<1));
    cl_mem pEdgesrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, pEdge_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    unsigned short *pEdgeSrcBufH = (unsigned short*)malloc(pEdge_srcsz0Pad); 
    for(int i = 0; i < pEdgeSrcHeight; i++){
  memcpy( (char*)pEdgeSrcBufH+ (i + PADDING_LINE) * pEdgeSrcStep, (char*)pEdge+ i * pEdgeSrcWidth* sizeof(unsigned short), pEdgeSrcWidth * sizeof(unsigned short) );
  }
    status = clEnqueueWriteBuffer(g_queue, pEdgesrcBuf, CL_TRUE, 0,pEdge_srcsz0Pad,pEdgeSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_7, 10, sizeof(cl_mem), (void *)&pEdgesrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_7, 11, sizeof(int), (void *)&pEdgeSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_7, 12, sizeof(int), (void *)&pEdgeSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_7, 13, sizeof(int), (void *)&pEdgeSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_7, 14, sizeof(int), (void *)&pEdgeSrcShift);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_7, 15, sizeof(float), (void *)&cutoff2Order);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_7, 16, sizeof(float), (void *)&m1);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_7, 17, sizeof(float), (void *)&m2);
    checkErr(status, "clSetKernelArg");
    size_t dstDstWidth = 1024;
    size_t dstDstHeight = 1024;
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
    status = clSetKernelArg(kernel_7, 18, sizeof(cl_mem), (void *)&dstdstBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_7, 19, sizeof(int), (void *)&dstDstWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_7, 20, sizeof(int), (void *)&dstDstHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_7, 21, sizeof(int), (void *)&dstDstStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_7, 22, sizeof(int), (void *)&dstDstShift);
    checkErr(status, "clSetKernelArg");
    status = clEnqueueNDRangeKernel(g_queue, kernel_7, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
    checkErr(status, "clEnqueueNDRangeKernel");
    status = clFinish(g_queue);
    checkErr(status,"clFinish of kernel_7");
      status = clEnqueueReadBuffer(g_queue, dstdstBuf, CL_TRUE, 0,dst_dstsz0Pad,dstDstBufH, 0, NULL, NULL);
    for(int i = 0; i < dstDstHeight; i++){
  memcpy( (char*)dst+ i *dstDstWidth* sizeof(unsigned char), (char*) dstDstBufH+ (i + PADDING_LINE)* dstDstStep, dstDstWidth* sizeof(unsigned char) );
  }
  
  }
}



void sharpness_total(unsigned char (*yPlane)[1024][1024], unsigned char (*dst)[1024][1024]) {
  MMC_CSE_PARAMETER_PUBLIC cseParamPublic;
  cseParamPublic.cutoff2 = 256.F;
  cseParamPublic.cutoff3Coef = 1.F;
  cseParamPublic.cutoffCoef = 1.F;
  cseParamPublic.peak = 2.F;
  unsigned char yPlaneCSER[1024][1024];
  unsigned char yPlaneDown[1024 / 4][1024 / 4];
  DownScaleNewX16(yPlane, &yPlaneDown);
  UpScaleNewX16(&yPlaneDown, &yPlaneCSER);
  Sharpness(yPlane, &yPlaneCSER, dst, cseParamPublic);
}



int main() {
  char inputfile[] = "sharpness_high_level.cl";
  char *remain = NULL;
  if (-1 == openCLCreate(inputfile, remain)) {
    printf("openCL create fail !!!!!!");
    return 0;
  }
  unsigned char *src_data = (unsigned char *)malloc(sizeof(unsigned char) * 1024 * 1024);
  unsigned char *dst_data = (unsigned char *)malloc(sizeof(unsigned char) * 1024 * 1024);
  for (int i = 0; i < 1024 * 1024; i++) {
    src_data[i] = rand() % 100 + 1;
  }
  unsigned char (*yPlane)[1024][1024] = (unsigned char (*)[1024][1024])src_data;
  unsigned char (*dst)[1024][1024] = (unsigned char (*)[1024][1024])dst_data;
  sharpness_total(yPlane, dst);
  dst_data = (unsigned char *)dst;
  return 0;
}


