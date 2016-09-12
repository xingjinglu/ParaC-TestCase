/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

#include"CL/cl.h"
#include"ClHost.h"
#include<stdlib.h>
#define ROWS 256
#define COLS 256
#define RATE 0.8
#define M 256
#define N 256
#define SIZE 3
//M is height, N is width

#define MRATE 205
#define NRATE 205 
#
#define MIN(a,b) ((a)<(b) ? (a):(b))

#ifdef _VERIFY
void rgb2grey_cpu(char oimage[256][768], char mimage[256][256]) {
  float arg[1][3] = { 0.29899999999999999, 0.58699999999999997, 0.114 };
  for (int i = 0; i < 256; i++) {
    for (int j = 0; j < 256; j++) {
      mimage[i][j] = oimage[i][j * 3] * arg[0][0] + oimage[i][j * 3 + 1] * arg[0][1] + oimage[i][j * 3 + 2] * arg[0][2];
    }
  }
}



void resizeImage_cpu(char mimage[256][256], char dimage[205][205]) {
  double rotate = 1 / 0.80000000000000004;
  for (int i = 0; i < 256 * 0.80000000000000004; i++) {
    for (int j = 0; j < 256 * 0.80000000000000004; j++) {
      int r1 = (int)(i * rotate);
      int r2 = ((256 - 1) < (r1 + 1) ? (256 - 1) : (r1 + 1));
      double p = i * rotate - r1;
      int c1 = (int)(j * rotate);
      int c2 = ((256 - 1) < (c1 + 1) ? (256 - 1) : (c1 + 1));
      double q = j * rotate - c1;
      dimage[i][j] = (1 - p) * (1 - q) * mimage[r1][c1] + (1 - p) * q * mimage[r1][c2] + p * (1 - q) * mimage[r2][c1] + p * q * mimage[r2][c2];
    }
  }
}


void convolutionImage_cpu(char dimage[205][205], char dsmage[205][205], float kernel[3][3]) {
  float sum1 = 1.;
  float sum = 0.;
  for (int i = 0; i < 256 * 0.80000000000000004; i++) {
    for (int j = 0; j < 256 * 0.80000000000000004; j++) {
      if (i == 0 || i == 256 * 0.80000000000000004 - 1)
        sum1 -= (1 / 9) * 3;
      if (j == 0 || j == 256 * 0.80000000000000004 - 1) {
        sum1 -= (1 / 9) * 3;
        if (i == 0 || i == 256 * 0.80000000000000004 - 1)
          sum1 += 1 / 9;
      }
      if (i == 0) {
        if (j == 0) {
          sum = kernel[0][0] * 0 + kernel[0][1] * 0 + kernel[0][2] * 0;
          sum += kernel[1][0] * 0 + kernel[1][1] * dimage[0][0] + kernel[1][2] * dimage[0][1];
          sum += kernel[2][0] * 0 + kernel[2][1] * dimage[1][0] + kernel[2][2] * dimage[1][1];
        } else if (j == 205 - 1) {
          sum = kernel[0][0] * 0 + kernel[0][1] * 0 + kernel[0][2] * 0;
          sum += kernel[1][0] * dimage[0][205 - 2] + kernel[1][1] * dimage[0][205 - 1] + kernel[1][2] * 0;
          sum += kernel[2][0] * dimage[1][205 - 2] + kernel[2][1] * dimage[1][205 - 2] + kernel[2][2] * 0;
        } else {
          sum = kernel[0][0] * 0 + kernel[0][1] * 0 + kernel[0][2] * 0;
          sum += kernel[1][0] * dimage[i][j - 1] + kernel[1][1] * dimage[i][j] + kernel[1][2] * dimage[i][j + 1];
          sum += kernel[2][0] * dimage[i + 1][j - 1] + kernel[2][1] * dimage[i + 1][j] + kernel[2][2] * dimage[i + 1][j + 1];
        }
      } else if (i == 205 - 1) {
        if (j == 0) {
          sum = kernel[0][0] * 0 + kernel[0][1] * dimage[205 - 2][0] + kernel[0][2] * dimage[205 - 2][1];
          sum += kernel[1][0] * 0 + kernel[1][1] * dimage[205 - 1][0] + kernel[1][2] * dimage[205 - 1][1];
          sum += kernel[2][0] * 0 + kernel[2][1] * 0 + kernel[2][2] * 0;
        } else if (j == 205 - 1) {
          sum = kernel[0][0] * dimage[205 - 2][205 - 2] + kernel[0][1] * dimage[205 - 2][205 - 1] + kernel[0][2] * 0;
          sum += kernel[1][0] * dimage[205 - 1][205 - 2] + kernel[1][1] * dimage[205 - 1][205 - 1] + kernel[1][2] * 0;
          sum += kernel[2][0] * 0 + kernel[2][1] * 0 + kernel[2][2] * 0;
        } else {
          sum = kernel[0][0] * dimage[i - 1][j - 1] + kernel[0][1] * dimage[i - 1][j] + kernel[0][2] * dimage[i - 1][j + 1];
          sum += kernel[1][0] * dimage[i][j - 1] + kernel[1][1] * dimage[i][j] + kernel[1][2] * dimage[i][j + 1];
          sum += kernel[2][0] * 0 + kernel[2][1] * 0 + kernel[2][2] * 0;
        }
      } else if (i > 0 && i < 205 - 1) {
        if (j == 0) {
          sum = kernel[0][0] * 0 + kernel[0][1] * dimage[i - 1][0] + kernel[0][2] * dimage[i - 1][1];
          sum += kernel[1][0] * 0 + kernel[1][1] * dimage[i][0] + kernel[1][2] * dimage[i][1];
          sum += kernel[2][0] * 0 + kernel[2][1] * dimage[i + 1][0] + kernel[2][2] * dimage[i + 1][1];
        } else if (j == 205 - 1) {
          sum = kernel[0][0] * dimage[i - 1][205 - 2] + kernel[0][1] * dimage[i - 1][205 - 1] + kernel[0][2] * 0;
          sum += kernel[1][0] * dimage[i][205 - 2] + kernel[1][1] * dimage[i][205 - 1] + kernel[1][2] * 0;
          sum += kernel[2][0] * dimage[i + 1][205 - 2] + kernel[2][1] * dimage[i + 1][205 - 1] + kernel[2][2] * 0;
        }
      } else {
        sum = kernel[0][0] * dimage[i - 1][j - 1] + kernel[0][1] * dimage[i - 1][j] + kernel[0][2] * dimage[i - 1][j + 1];
        sum += kernel[1][0] * dimage[i][j - 1] + kernel[1][1] * dimage[i][j] + kernel[1][2] * dimage[i][j + 1];
        sum += kernel[2][0] * dimage[i + 1][j - 1] + kernel[2][1] * dimage[i + 1][j] + kernel[2][2] * dimage[i + 1][j + 1];
      }
      dsmage[i][j] = sum1 == 1 ? sum : sum / sum1;
    }
  }
}


#endif


void rgb2grey(char (*oimage)[256][256 * 3], char (*mimage)[256][256]) {
  float arg[1][3] = { 0.29899999999999999, 0.58699999999999997, 0.114 };
  
  {
    size_t global_work_size[2];
    size_t transe;
    cl_event event_kernel;
    cl_kernel kernel_1 = clCreateKernel(g_program, "kernel_1", &status);
    checkErr(status, "clCreateKernel for kernel_1");
    global_work_size[0] = 256;
    global_work_size[1] = 256;
    size_t oimageSrcWidth = 768;
    size_t oimageSrcHeight = 256;
    size_t oimage_srcsz = sizeof(char);
    size_t oimageSrcStep = oimageSrcWidth * oimage_srcsz;
    oimageSrcStep = (oimageSrcStep % PADDING < 16) ? ((oimageSrcStep / PADDING+1) * PADDING) : ((oimageSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t oimageSrcShift = oimageSrcStep * PADDING_LINE;
    size_t oimage_srcsz0Pad = oimageSrcStep * (oimageSrcHeight + (PADDING_LINE<<1));
    cl_mem oimagesrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, oimage_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    char *oimageSrcBufH = (char*)malloc(oimage_srcsz0Pad); 
    for(int i = 0; i < oimageSrcHeight; i++){
  memcpy( (char*)oimageSrcBufH+ (i + PADDING_LINE) * oimageSrcStep, (char*)oimage+ i * oimageSrcWidth* sizeof(char), oimageSrcWidth * sizeof(char) );
  }
    status = clEnqueueWriteBuffer(g_queue, oimagesrcBuf, CL_TRUE, 0,oimage_srcsz0Pad,oimageSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_1, 0, sizeof(cl_mem), (void *)&oimagesrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 1, sizeof(int), (void *)&oimageSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 2, sizeof(int), (void *)&oimageSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 3, sizeof(int), (void *)&oimageSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 4, sizeof(int), (void *)&oimageSrcShift);
    checkErr(status, "clSetKernelArg");
    size_t argSrcWidth = 3;
    size_t argSrcHeight = 1;
    size_t arg_srcsz = sizeof(float);
    size_t argSrcStep = argSrcWidth * arg_srcsz;
    argSrcStep = (argSrcStep % PADDING < 16) ? ((argSrcStep / PADDING+1) * PADDING) : ((argSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t argSrcShift = argSrcStep * PADDING_LINE;
    size_t arg_srcsz0Pad = argSrcStep * (argSrcHeight + (PADDING_LINE<<1));
    cl_mem argsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, arg_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    float *argSrcBufH = (float*)malloc(arg_srcsz0Pad); 
    for(int i = 0; i < argSrcHeight; i++){
  memcpy( (char*)argSrcBufH+ (i + PADDING_LINE) * argSrcStep, (char*)arg+ i * argSrcWidth* sizeof(float), argSrcWidth * sizeof(float) );
  }
    status = clEnqueueWriteBuffer(g_queue, argsrcBuf, CL_TRUE, 0,arg_srcsz0Pad,argSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_1, 5, sizeof(cl_mem), (void *)&argsrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 6, sizeof(int), (void *)&argSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 7, sizeof(int), (void *)&argSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 8, sizeof(int), (void *)&argSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 9, sizeof(int), (void *)&argSrcShift);
    checkErr(status, "clSetKernelArg");
    size_t mimageDstWidth = 256;
    size_t mimageDstHeight = 256;
    size_t mimage_dstsz = sizeof(char);
    size_t mimageDstStep = mimageDstWidth * mimage_dstsz;
    mimageDstStep = (mimageDstStep % PADDING < 16) ? ((mimageDstStep / PADDING+1) * PADDING) : ((mimageDstStep + PADDING) / PADDING+1) * PADDING;
    size_t mimageDstShift = mimageDstStep * PADDING_LINE;
    size_t mimage_dstsz0Pad = mimageDstStep * (mimageDstHeight + (PADDING_LINE<<1));
    cl_mem mimagedstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, mimage_dstsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    char *mimageDstBufH = (char*)malloc(mimage_dstsz0Pad); 
    for(int i = 0; i < mimageDstHeight; i++){
  memcpy( (char*)mimageDstBufH+ (i + PADDING_LINE) * mimageDstStep,(char*)mimage + i * mimageDstWidth* sizeof(char),mimageDstWidth* sizeof(char) );
  }
    status = clSetKernelArg(kernel_1, 10, sizeof(cl_mem), (void *)&mimagedstBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 11, sizeof(int), (void *)&mimageDstWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 12, sizeof(int), (void *)&mimageDstHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 13, sizeof(int), (void *)&mimageDstStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 14, sizeof(int), (void *)&mimageDstShift);
    checkErr(status, "clSetKernelArg");
    status = clEnqueueNDRangeKernel(g_queue, kernel_1, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
    checkErr(status, "clEnqueueNDRangeKernel");
    status = clFinish(g_queue);
    checkErr(status,"clFinish of kernel_1");
      status = clEnqueueReadBuffer(g_queue, mimagedstBuf, CL_TRUE, 0,mimage_dstsz0Pad,mimageDstBufH, 0, NULL, NULL);
    for(int i = 0; i < mimageDstHeight; i++){
  memcpy( (char*)mimage+ i *mimageDstWidth* sizeof(char), (char*) mimageDstBufH+ (i + PADDING_LINE)* mimageDstStep, mimageDstWidth* sizeof(char) );
  }
  
  }
}



//void resizeImage(parac_matrix char& mimage[M][N],parac_matrix char& dimage[M*RATE][N*RATE])
void resizeImage(char (*mimage)[256][256], char (*dimage)[205][205]) {
  double rotate = 1 / 0.80000000000000004;
  
  {
    size_t global_work_size[2];
    size_t transe;
    cl_event event_kernel;
    cl_kernel kernel_2 = clCreateKernel(g_program, "kernel_2", &status);
    checkErr(status, "clCreateKernel for kernel_2");
    global_work_size[0] = 205;
    global_work_size[1] = 205;
    size_t mimageSrcWidth = 256;
    size_t mimageSrcHeight = 256;
    size_t mimage_srcsz = sizeof(char);
    size_t mimageSrcStep = mimageSrcWidth * mimage_srcsz;
    mimageSrcStep = (mimageSrcStep % PADDING < 16) ? ((mimageSrcStep / PADDING+1) * PADDING) : ((mimageSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t mimageSrcShift = mimageSrcStep * PADDING_LINE;
    size_t mimage_srcsz0Pad = mimageSrcStep * (mimageSrcHeight + (PADDING_LINE<<1));
    cl_mem mimagesrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, mimage_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    char *mimageSrcBufH = (char*)malloc(mimage_srcsz0Pad); 
    for(int i = 0; i < mimageSrcHeight; i++){
  memcpy( (char*)mimageSrcBufH+ (i + PADDING_LINE) * mimageSrcStep, (char*)mimage+ i * mimageSrcWidth* sizeof(char), mimageSrcWidth * sizeof(char) );
  }
    status = clEnqueueWriteBuffer(g_queue, mimagesrcBuf, CL_TRUE, 0,mimage_srcsz0Pad,mimageSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_2, 0, sizeof(cl_mem), (void *)&mimagesrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 1, sizeof(int), (void *)&mimageSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 2, sizeof(int), (void *)&mimageSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 3, sizeof(int), (void *)&mimageSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 4, sizeof(int), (void *)&mimageSrcShift);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 5, sizeof(double), (void *)&rotate);
    checkErr(status, "clSetKernelArg");
    size_t dimageDstWidth = 205;
    size_t dimageDstHeight = 205;
    size_t dimage_dstsz = sizeof(char);
    size_t dimageDstStep = dimageDstWidth * dimage_dstsz;
    dimageDstStep = (dimageDstStep % PADDING < 16) ? ((dimageDstStep / PADDING+1) * PADDING) : ((dimageDstStep + PADDING) / PADDING+1) * PADDING;
    size_t dimageDstShift = dimageDstStep * PADDING_LINE;
    size_t dimage_dstsz0Pad = dimageDstStep * (dimageDstHeight + (PADDING_LINE<<1));
    cl_mem dimagedstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, dimage_dstsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    char *dimageDstBufH = (char*)malloc(dimage_dstsz0Pad); 
    for(int i = 0; i < dimageDstHeight; i++){
  memcpy( (char*)dimageDstBufH+ (i + PADDING_LINE) * dimageDstStep,(char*)dimage + i * dimageDstWidth* sizeof(char),dimageDstWidth* sizeof(char) );
  }
    status = clSetKernelArg(kernel_2, 6, sizeof(cl_mem), (void *)&dimagedstBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 7, sizeof(int), (void *)&dimageDstWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 8, sizeof(int), (void *)&dimageDstHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 9, sizeof(int), (void *)&dimageDstStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 10, sizeof(int), (void *)&dimageDstShift);
    checkErr(status, "clSetKernelArg");
    status = clEnqueueNDRangeKernel(g_queue, kernel_2, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
    checkErr(status, "clEnqueueNDRangeKernel");
    status = clFinish(g_queue);
    checkErr(status,"clFinish of kernel_2");
      status = clEnqueueReadBuffer(g_queue, dimagedstBuf, CL_TRUE, 0,dimage_dstsz0Pad,dimageDstBufH, 0, NULL, NULL);
    for(int i = 0; i < dimageDstHeight; i++){
  memcpy( (char*)dimage+ i *dimageDstWidth* sizeof(char), (char*) dimageDstBufH+ (i + PADDING_LINE)* dimageDstStep, dimageDstWidth* sizeof(char) );
  }
  
  }
}



//void convolutionImage(parac_matrix char& dimage[M*RATE][N*RATE],parac_matrix char& dsmage[M*RATE][N*RATE],parac_matrix float& kernel[SIZE][SIZE])
#if 0
void convolutionImage(parac_matrix char& dimage[MRATE][NRATE],parac_matrix char& dsmage[MRATE][NRATE],parac_matrix float& kernel[SIZE][SIZE])
{
  float sum1= 1.0;
  float sum = 0.0;

  parac_border_rule br
  {
    dimage[*][-1] = 0;
    dimage[*][+1] = 0;
    dimage[-1][*] = 0;
    dimage[+1][*] = 0;
  }

  parac_iterator it(iter_element; 0:M*RATE:1; 0:N*RATE:1) parac_border_rule(br)
  {
    if(itx == 0 || itx == M*RATE-1)
      sum1 -= (1/9)*3;

    if(ity == 0 ||ity == M*RATE-1)
    {
      sum1 -= (1/9) * 3;
      if(itx == 0 || itx == M*RATE-1)
        sum1+=1/9;
    }

    //sum=convolution(kernel,dimage[itx-1:3:1][ity-1:3:1]);
    sum = dsmage[itx][ity] =convolution(kernel,dimage[itx-1:3:1][ity-1:3:1]);
    dsmage[itx][ity]= sum1 == 1? sum : sum/sum1;			
  }
}
#endif

void convolutionImage(char dimage[205][205], char dsmage[205][205], float kernel[3][3]) {
  float sum1 = 1.;
  float sum = 0.;
  for (int i = 0; i < 256 * 0.80000000000000004; i++) {
    for (int j = 0; j < 256 * 0.80000000000000004; j++) {
      if (i == 0 || i == 256 * 0.80000000000000004 - 1)
        sum1 -= (1 / 9) * 3;
      if (j == 0 || j == 256 * 0.80000000000000004 - 1) {
        sum1 -= (1 / 9) * 3;
        if (i == 0 || i == 256 * 0.80000000000000004 - 1)
          sum1 += 1 / 9;
      }
      if (i == 0) {
        if (j == 0) {
          sum = kernel[0][0] * 0 + kernel[0][1] * 0 + kernel[0][2] * 0;
          sum += kernel[1][0] * 0 + kernel[1][1] * dimage[0][0] + kernel[1][2] * dimage[0][1];
          sum += kernel[2][0] * 0 + kernel[2][1] * dimage[1][0] + kernel[2][2] * dimage[1][1];
        } else if (j == 205 - 1) {
          sum = kernel[0][0] * 0 + kernel[0][1] * 0 + kernel[0][2] * 0;
          sum += kernel[1][0] * dimage[0][205 - 2] + kernel[1][1] * dimage[0][205 - 1] + kernel[1][2] * 0;
          sum += kernel[2][0] * dimage[1][205 - 2] + kernel[2][1] * dimage[1][205 - 2] + kernel[2][2] * 0;
        } else {
          sum = kernel[0][0] * 0 + kernel[0][1] * 0 + kernel[0][2] * 0;
          sum += kernel[1][0] * dimage[i][j - 1] + kernel[1][1] * dimage[i][j] + kernel[1][2] * dimage[i][j + 1];
          sum += kernel[2][0] * dimage[i + 1][j - 1] + kernel[2][1] * dimage[i + 1][j] + kernel[2][2] * dimage[i + 1][j + 1];
        }
      } else if (i == 205 - 1) {
        if (j == 0) {
          sum = kernel[0][0] * 0 + kernel[0][1] * dimage[205 - 2][0] + kernel[0][2] * dimage[205 - 2][1];
          sum += kernel[1][0] * 0 + kernel[1][1] * dimage[205 - 1][0] + kernel[1][2] * dimage[205 - 1][1];
          sum += kernel[2][0] * 0 + kernel[2][1] * 0 + kernel[2][2] * 0;
        } else if (j == 205 - 1) {
          sum = kernel[0][0] * dimage[205 - 2][205 - 2] + kernel[0][1] * dimage[205 - 2][205 - 1] + kernel[0][2] * 0;
          sum += kernel[1][0] * dimage[205 - 1][205 - 2] + kernel[1][1] * dimage[205 - 1][205 - 1] + kernel[1][2] * 0;
          sum += kernel[2][0] * 0 + kernel[2][1] * 0 + kernel[2][2] * 0;
        } else {
          sum = kernel[0][0] * dimage[i - 1][j - 1] + kernel[0][1] * dimage[i - 1][j] + kernel[0][2] * dimage[i - 1][j + 1];
          sum += kernel[1][0] * dimage[i][j - 1] + kernel[1][1] * dimage[i][j] + kernel[1][2] * dimage[i][j + 1];
          sum += kernel[2][0] * 0 + kernel[2][1] * 0 + kernel[2][2] * 0;
        }
      } else if (i > 0 && i < 205 - 1) {
        if (j == 0) {
          sum = kernel[0][0] * 0 + kernel[0][1] * dimage[i - 1][0] + kernel[0][2] * dimage[i - 1][1];
          sum += kernel[1][0] * 0 + kernel[1][1] * dimage[i][0] + kernel[1][2] * dimage[i][1];
          sum += kernel[2][0] * 0 + kernel[2][1] * dimage[i + 1][0] + kernel[2][2] * dimage[i + 1][1];
        } else if (j == 205 - 1) {
          sum = kernel[0][0] * dimage[i - 1][205 - 2] + kernel[0][1] * dimage[i - 1][205 - 1] + kernel[0][2] * 0;
          sum += kernel[1][0] * dimage[i][205 - 2] + kernel[1][1] * dimage[i][205 - 1] + kernel[1][2] * 0;
          sum += kernel[2][0] * dimage[i + 1][205 - 2] + kernel[2][1] * dimage[i + 1][205 - 1] + kernel[2][2] * 0;
        }
      } else {
        sum = kernel[0][0] * dimage[i - 1][j - 1] + kernel[0][1] * dimage[i - 1][j] + kernel[0][2] * dimage[i - 1][j + 1];
        sum += kernel[1][0] * dimage[i][j - 1] + kernel[1][1] * dimage[i][j] + kernel[1][2] * dimage[i][j + 1];
        sum += kernel[2][0] * dimage[i + 1][j - 1] + kernel[2][1] * dimage[i + 1][j] + kernel[2][2] * dimage[i + 1][j + 1];
      }
      dsmage[i][j] = sum1 == 1 ? sum : sum / sum1;
    }
  }
}




int main() {
  char inputfile[] = "imagecase_verify.cl";
  char *remain = NULL;
  if (-1 == openCLCreate(inputfile, remain)) {
    printf("openCL create fail !!!!!!");
    return 0;
  }
  char *src = (char *)malloc(sizeof(char) * 256 * 256 * 3);
  char *mid = (char *)malloc(sizeof(char) * 256 * 256);
  char *dst = (char *)malloc(sizeof(char) * 205 * 205);
  char *ddt = (char *)malloc(sizeof(char) * 205 * 205);
  char *mimage_cpu = (char *)malloc(sizeof(char) * 256 * 256);
  char *dimage_cpu = (char *)malloc(sizeof(char) * 205 * 205);
  char *dsmage_cpu = (char *)malloc(sizeof(char) * 205 * 205);
  char *p = src;
  for (int i = 0; i < 256 * 256 * 3; i++) 
    *p++ = rand() % 100 + 1;
  char (*oimage)[256][256 * 3] = (char (*)[256][256 * 3])src;
  char (*mimage)[256][256] = (char (*)[256][256])mid;
  char (*dimage)[205][205] = (char (*)[205][205])dst;
  char (*dsmage)[205][205] = (char (*)[205][205])ddt;
  float kernel[3][3] = { 1, 2, 1, 2, 4, 2, 1, 2, 1 };
  float kernel_cpu[3][3] = { 1, 2, 1, 2, 4, 2, 1, 2, 1 };
  for (int i = 0; i < 3; i++) 
    for (int j = 0; j < 3; j++) 
      kernel[i][j] = kernel[i][j] / 16;
  rgb2grey(oimage, mimage);
  resizeImage(mimage, dimage);
  convolutionImage((char (*)[205])dst, (char (*)[205])ddt, (float (*)[3])kernel_cpu);
  rgb2grey_cpu((char (*)[768])src, (char (*)[256])mimage_cpu);
  resizeImage_cpu((char (*)[256])mimage_cpu, (char (*)[205])dimage_cpu);
  convolutionImage_cpu((char (*)[205])dimage_cpu, (char (*)[205])dsmage_cpu, (float (*)[3])kernel_cpu);
  int i, j;
  for (i = 0; i < 256; i++) 
    for (j = 0; j < 256; j++) {
      if (mid[i * 256 + j] != mimage_cpu[i * 256 + j]) {
        printf("kernel_1: %d %d ocl=%d ser=%d \n", i, j, mid[i * 256 + j], mimage_cpu[i * 256 + j]);
        abort();
      }
    }
  printf("kernel_1 scuccess \n");
  for (i = 0; i < 205; i++) 
    for (j = 0; j < 205; j++) {
      if (dst[i * 205 + j] != dimage_cpu[i * 205 + j]) {
        printf("kernel_2: %d %d ocl=%d ser=%d \n", i, j, dst[i * 205 + j], mimage_cpu[i * 205 + j]);
        abort();
      }
    }
  printf("kernel_2 scuccess \n");
  return 0;
}



