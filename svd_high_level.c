/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

#include"CL/cl.h"
#include"ClHost.h"
#define M 256
#define N 256
#define ROWS 256
#define COLS 256

#define TYPE double

#define MAX_ITERATIONS 40
#define THRESHOLD 0.00001

#define FLAG 1
#define IN_PRODUCT 0

#include <stdlib.h>
#include <stdio.h>

//仅用于测试新语言，仅更新A
void svd(double (*A)[2][256][256], double (*S)[256], double (*V)[2][256][256]) {
  int pass;
  int iterations_passed = 0;
  double A_H[2][256][256];
  double V_H[2][256][256];
  int rotate_col_idx[256];
  for (int i = 0; i < 256; i++) 
    rotate_col_idx[i] = i;
  int iteration = 40;
  int start_index, skip_trans;
    size_t A_HDSWidth = 256;
    size_t A_HDSHeight = 256;
    size_t A_H_dssz = sizeof(double);
    size_t A_HDSStep = A_HDSWidth * A_H_dssz;
    A_HDSStep = (A_HDSStep % PADDING < 16) ? ((A_HDSStep / PADDING+1) * PADDING) : ((A_HDSStep + PADDING) / PADDING+1) * PADDING;
    size_t A_HDSShift = A_HDSStep * PADDING_LINE;
    size_t A_H_dssz0Pad = A_HDSStep * (A_HDSHeight + (PADDING_LINE<<1)) * 2;
    cl_mem A_HdsBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, A_H_dssz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    double *A_HDsBufH = (double*)malloc (A_H_dssz0Pad); 
    for(int i = 0; i < A_HDSHeight*2; i++){
  memcpy((char*)A_HDsBufH + (i + PADDING_LINE) * A_HDSStep, (char*)A_H+ i * A_HDSWidth * sizeof(double), A_HDSWidth* sizeof(double) );
  }
    status = clEnqueueWriteBuffer(g_queue, A_HdsBuf, CL_TRUE, 0,A_H_dssz0Pad, A_HDsBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    size_t V_HDSWidth = 256;
    size_t V_HDSHeight = 256;
    size_t V_H_dssz = sizeof(double);
    size_t V_HDSStep = V_HDSWidth * V_H_dssz;
    V_HDSStep = (V_HDSStep % PADDING < 16) ? ((V_HDSStep / PADDING+1) * PADDING) : ((V_HDSStep + PADDING) / PADDING+1) * PADDING;
    size_t V_HDSShift = V_HDSStep * PADDING_LINE;
    size_t V_H_dssz0Pad = V_HDSStep * (V_HDSHeight + (PADDING_LINE<<1)) * 2;
    cl_mem V_HdsBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, V_H_dssz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    double *V_HDsBufH = (double*)malloc (V_H_dssz0Pad); 
    for(int i = 0; i < V_HDSHeight*2; i++){
  memcpy((char*)V_HDsBufH + (i + PADDING_LINE) * V_HDSStep, (char*)V_H+ i * V_HDSWidth * sizeof(double), V_HDSWidth* sizeof(double) );
  }
    status = clEnqueueWriteBuffer(g_queue, V_HdsBuf, CL_TRUE, 0,V_H_dssz0Pad, V_HDsBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    size_t rotate_col_idxDSWidth = 256;
    size_t rotate_col_idx_dssz = sizeof(int);
    size_t rotate_col_idxDSStep = rotate_col_idxDSWidth * rotate_col_idx_dssz;
    rotate_col_idxDSStep = (rotate_col_idxDSStep % PADDING < 16) ? ((rotate_col_idxDSStep / PADDING+1) * PADDING) : ((rotate_col_idxDSStep + PADDING) / PADDING+1) * PADDING;
    size_t rotate_col_idxDSShift = rotate_col_idxDSStep * PADDING_LINE;
    size_t rotate_col_idx_dssz0Pad = rotate_col_idxDSStep * (1 + (PADDING_LINE<<1));
    cl_mem rotate_col_idxdsBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, rotate_col_idx_dssz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    int *rotate_col_idxDsBufH = (int*)malloc (rotate_col_idx_dssz0Pad); 
    memcpy( (char*)rotate_col_idxDsBufH + (PADDING_LINE) * rotate_col_idxDSStep, (char*)rotate_col_idx, rotate_col_idxDSWidth * sizeof(int) );
    status = clEnqueueWriteBuffer(g_queue, rotate_col_idxdsBuf, CL_TRUE, 0,rotate_col_idx_dssz0Pad, rotate_col_idxDsBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
  while (iteration > 0)
    {
            cl_mem passBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, sizeof(int), NULL, &status);
            checkErr(status,"clCreateBuffer");
            status = clEnqueueWriteBuffer(g_queue, passBuf, CL_TRUE, 0, sizeof(int), &pass, 0, NULL, NULL);
            checkErr(status,"clEnqueueWrite");
      for (int i = 0; i < 256; i++) {
        start_index = (i % 2 == 0) ? 0 : 1;
        
        {
                size_t global_work_size[2];
                size_t transe;
                cl_event event_kernel;
                cl_kernel kernel_1 = clCreateKernel(g_program, "kernel_1", &status);
                checkErr(status, "clCreateKernel for kernel_1");
                global_work_size[0] = (256 - start_index )/ 2;
                global_work_size[1] = 1;
                size_t local_work_size[2];
                local_work_size[0] = 256;
                local_work_size[1] = 1;
                global_work_size[0] = global_work_size[0] * local_work_size[0];
                status = clSetKernelArg(kernel_1, 0, sizeof(int), (void *)&start_index);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 1, sizeof(int), (void *)&i);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 2, sizeof(cl_mem), (void *)&passBuf);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 3, sizeof(cl_mem), (void *)&A_HdsBuf);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 4, sizeof(int), (void *)&A_HDSWidth);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 5, sizeof(int), (void *)&A_HDSHeight);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 6, sizeof(int), (void *)&A_HDSStep);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 7, sizeof(int), (void *)&A_HDSShift);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 8, sizeof(cl_mem), (void *)&V_HdsBuf);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 9, sizeof(int), (void *)&V_HDSWidth);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 10, sizeof(int), (void *)&V_HDSHeight);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 11, sizeof(int), (void *)&V_HDSStep);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 12, sizeof(int), (void *)&V_HDSShift);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 13, sizeof(cl_mem), (void *)&rotate_col_idxdsBuf);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 14, sizeof(int), (void *)&rotate_col_idxDSWidth);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 15, sizeof(int), (void *)&rotate_col_idxDSStep);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 16, sizeof(int), (void *)&rotate_col_idxDSShift);
                checkErr(status, "clSetKernelArg");
                status = clEnqueueNDRangeKernel(g_queue, kernel_1, 2, NULL, global_work_size, local_work_size, 0, NULL, &event_kernel);
                checkErr(status, "clEnqueueNDRangeKernel");
                status = clFinish(g_queue);
                checkErr(status,"clFinish of kernel_1");
                
        }
      }
            status = clEnqueueReadBuffer(g_queue, passBuf, CL_TRUE, 0, sizeof(int), &pass, 0, NULL, NULL);
            checkErr(status,"clEnqueueReadBuffer");
      iteration--;
      if (pass == 1)
        break;
    }
    status = clEnqueueReadBuffer(g_queue, rotate_col_idxdsBuf, CL_TRUE, 0,rotate_col_idx_dssz0Pad,rotate_col_idxDsBufH, 0, NULL, NULL);
    memcpy( (char*)rotate_col_idx, (char*)rotate_col_idxDsBufH + PADDING_LINE * rotate_col_idxDSStep, rotate_col_idxDSWidth * sizeof(int) );
    status = clEnqueueReadBuffer(g_queue, V_HdsBuf, CL_TRUE, 0,V_H_dssz0Pad,V_HDsBufH, 0, NULL, NULL);
    for(int i = 0; i < V_HDSHeight*2; i++){
  memcpy( (char*)V_H+ i *V_HDSWidth* sizeof(double), (char*) V_HDsBufH+ (i + PADDING_LINE)* V_HDSStep, V_HDSWidth* sizeof(double) );
  }
    status = clEnqueueReadBuffer(g_queue, A_HdsBuf, CL_TRUE, 0,A_H_dssz0Pad,A_HDsBufH, 0, NULL, NULL);
    for(int i = 0; i < A_HDSHeight*2; i++){
  memcpy( (char*)A_H+ i *A_HDSWidth* sizeof(double), (char*) A_HDsBufH+ (i + PADDING_LINE)* A_HDSStep, A_HDSWidth* sizeof(double) );
  }
  
  {
    size_t global_work_size[2];
    size_t transe;
    cl_event event_kernel;
    cl_kernel kernel_2 = clCreateKernel(g_program, "kernel_2", &status);
    checkErr(status, "clCreateKernel for kernel_2");
    global_work_size[0] = 256;
    global_work_size[1] = 1;
    size_t local_work_size[2];
    local_work_size[0] = 256;
    local_work_size[1] = 1;
    global_work_size[0] = global_work_size[0] * local_work_size[0];
    size_t SDstWidth = 256;
    size_t S_dstsz = sizeof(double);
    size_t SDstStep = SDstWidth * S_dstsz;
    SDstStep = (SDstStep % PADDING < 16) ? ((SDstStep / PADDING+1) * PADDING) : ((SDstStep + PADDING) / PADDING+1) * PADDING;
    size_t SDstShift = SDstStep * PADDING_LINE;
    size_t S_dstsz0Pad = SDstStep * (1 + (PADDING_LINE<<1));
    cl_mem SdstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, S_dstsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    double *SDstBufH = (double*)malloc(S_dstsz0Pad); 
    memcpy( (char*)SDstBufH + (PADDING_LINE) * SDstStep, (char*)S, SDstWidth * sizeof(double) );
    status = clSetKernelArg(kernel_2, 0, sizeof(cl_mem), (void *)&SdstBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 1, sizeof(int), (void *)&SDstWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 2, sizeof(int), (void *)&SDstStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 3, sizeof(int), (void *)&SDstShift);
    checkErr(status, "clSetKernelArg");
    size_t A_HDSWidth = 256;
    size_t A_HDSHeight = 256;
    size_t A_H_dssz = sizeof(double);
    size_t A_HDSStep = A_HDSWidth * A_H_dssz;
    A_HDSStep = (A_HDSStep % PADDING < 16) ? ((A_HDSStep / PADDING+1) * PADDING) : ((A_HDSStep + PADDING) / PADDING+1) * PADDING;
    size_t A_HDSShift = A_HDSStep * PADDING_LINE;
    size_t A_H_dssz0Pad = A_HDSStep * (A_HDSHeight + (PADDING_LINE<<1)) * 2;
    cl_mem A_HdsBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, A_H_dssz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    double *A_HDsBufH = (double*)malloc (A_H_dssz0Pad); 
    for(int i = 0; i < A_HDSHeight*2; i++){
  memcpy((char*)A_HDsBufH + (i + PADDING_LINE) * A_HDSStep, (char*)A_H+ i * A_HDSWidth * sizeof(double), A_HDSWidth* sizeof(double) );
  }
    status = clEnqueueWriteBuffer(g_queue, A_HdsBuf, CL_TRUE, 0,A_H_dssz0Pad, A_HDsBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_2, 4, sizeof(cl_mem), (void *)&A_HdsBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 5, sizeof(int), (void *)&A_HDSWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 6, sizeof(int), (void *)&A_HDSHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 7, sizeof(int), (void *)&A_HDSStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 8, sizeof(int), (void *)&A_HDSShift);
    checkErr(status, "clSetKernelArg");
    status = clEnqueueNDRangeKernel(g_queue, kernel_2, 2, NULL, global_work_size, local_work_size, 0, NULL, &event_kernel);
    checkErr(status, "clEnqueueNDRangeKernel");
    status = clFinish(g_queue);
    checkErr(status,"clFinish of kernel_2");
      status = clEnqueueReadBuffer(g_queue, SdstBuf, CL_TRUE, 0,S_dstsz0Pad,SDstBufH, 0, NULL, NULL);
    memcpy( (char*)S, (char*)SDstBufH + PADDING_LINE * SDstStep, SDstWidth * sizeof(double) );
  
  }
}



int main() {
  char inputfile[] = "svd_high_level.cl";
  char *remain = NULL;
  if (-1 == openCLCreate(inputfile, remain)) {
    printf("openCL create fail !!!!!!");
    return 0;
  }
  double *data;
  FILE *fin = fopen("./data/Matrix_input_A256.txt", "r");
  if (!fin) {
    printf("Matrix input A is not available\n");
    return 1;
  }
  double *A_data = (double *)malloc(sizeof(double) * 256 * 256 * 2);
  double *A_H_data = (double *)malloc(sizeof(double) * 256 * 256 * 2);
  double *V_data = (double *)malloc(sizeof(double) * 256 * 256 * 2);
  double *V_H_data = (double *)malloc(sizeof(double) * 256 * 256 * 2);
  memset(V_data, 0, 256 * 256 * 2 * sizeof(double));
  for (int i = 0; i < 256; i++) 
    V_data[i * 256 + i] = 1.F;
  for (int i = 0; i < 256; i++) {
    for (int j = 0; j < 256; j++) 
      fscanf(fin, "%lf", &A_data[i * 256 + j]);
    for (int j = 0; j < 256; j++) 
      fscanf(fin, "%lf", &A_data[256 * 256 + i * 256 + j]);
  }
  for (int i = 0; i < 256; i++) {
    for (int j = 0; j < 256; j++) {
      A_H_data[j * 256 + i] = A_data[i * 256 + j];
    }
  }
  for (int i = 256; i < 256; i++) {
    for (int j = 0; j < 256; j++) {
      A_H_data[(i + 256) * 256 + j] = A_data[(j + 256) * 256 + i];
    }
  }
  double (*A)[2][256][256] = (double (*)[2][256][256])A_H_data;
  double (*V)[2][256][256] = (double (*)[2][256][256])V_data;
  double S[256];
  svd(A, &S, V);
}


