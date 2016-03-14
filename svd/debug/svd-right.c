/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

#include"CL/cl.h"
#include"ClHost.h"
#define M 256
#define N 256
#define ROWS 256
#define COLS 256
#
#define TYPE double

#define MAX_ITERATIONS 40
#define THRESHOLD 0.00001

#define FLAG 1
#define IN_PRODUCT 0

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
  while (iteration > 0)
    {
      for (int i = 0; i < 256; i++) {
        start_index = (i % 2 == 0) ? 0 : 1;
        
        {
                size_t global_work_size[2];
                size_t transe;
                size_t Readsize;
                cl_event event_kernel;
                cl_kernel kernel_1 = clCreateKernel(g_program, "kernel_1", &status);
                checkErr(status, "clCreateKernel for kernel_1");
                global_work_size[0] = 1;
                global_work_size[1] = 18446744073709551615;
                status = clSetKernelArg(kernel_1, 0, sizeof(int), (void *)&i);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 1, sizeof(int), (void *)&pass);
                checkErr(status, "clSetKernelArg");
                size_t A_HDSWidth = 256;
                size_t A_HDSHeight = 256;
                size_t A_H_dssz = sizeof( double) * 2;
                Readsize = A_HDSWidth * A_HDSHeight * A_H_dssz;
                size_t A_HDSStep = A_HDSWidth * A_H_dssz;
                A_HDSStep = (A_HDSStep % PADDING < 16) ? ((A_HDSStep / PADDING+1) * PADDING) : ((A_HDSStep + PADDING) / PADDING+1) * PADDING;
                size_t A_HDSShift = A_HDSStep * PADDING_LINE;
                size_t A_H_dssz0Pad = A_HDSStep * (A_HDSHeight + (PADDING_LINE<<1));
                cl_mem A_HdsBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, A_H_dssz0Pad, NULL, &status);
                checkErr(status, "clCreateBuffer");
                 double *A_HDsBufH = ( double*)malloc (A_H_dssz0Pad); 
                for(int i = 0; i < A_HDSHeight; i++){
        memcpy((char*)A_HDsBufH + (i + PADDING_LINE) * A_HDSStep, (char*)A_H+ i * A_HDSWidth * sizeof( double) * 2, A_HDSWidth* sizeof( double) * 2 );
        }
                status = clEnqueueWriteBuffer(g_queue, A_HdsBuf, CL_TRUE, 0,A_H_dssz0Pad, A_HDsBufH, 0, NULL, NULL);
                checkErr(status, "clWriteBuffer");
                status = clSetKernelArg(kernel_1, 2, sizeof(cl_mem), (void *)&A_HdsBuf);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 3, sizeof(int), (void *)&A_HDSWidth);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 4, sizeof(int), (void *)&A_HDSHeight);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 5, sizeof(int), (void *)&A_HDSStep);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 6, sizeof(int), (void *)&A_HDSShift);
                checkErr(status, "clSetKernelArg");
                size_t V_HDSWidth = 256;
                size_t V_HDSHeight = 256;
                size_t V_H_dssz = sizeof( double) * 2;
                Readsize = V_HDSWidth * V_HDSHeight * V_H_dssz;
                size_t V_HDSStep = V_HDSWidth * V_H_dssz;
                V_HDSStep = (V_HDSStep % PADDING < 16) ? ((V_HDSStep / PADDING+1) * PADDING) : ((V_HDSStep + PADDING) / PADDING+1) * PADDING;
                size_t V_HDSShift = V_HDSStep * PADDING_LINE;
                size_t V_H_dssz0Pad = V_HDSStep * (V_HDSHeight + (PADDING_LINE<<1));
                cl_mem V_HdsBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, V_H_dssz0Pad, NULL, &status);
                checkErr(status, "clCreateBuffer");
                 double *V_HDsBufH = ( double*)malloc (V_H_dssz0Pad); 
                for(int i = 0; i < V_HDSHeight; i++){
        memcpy((char*)V_HDsBufH + (i + PADDING_LINE) * V_HDSStep, (char*)V_H+ i * V_HDSWidth * sizeof( double) * 2, V_HDSWidth* sizeof( double) * 2 );
        }
                status = clEnqueueWriteBuffer(g_queue, V_HdsBuf, CL_TRUE, 0,V_H_dssz0Pad, V_HDsBufH, 0, NULL, NULL);
                checkErr(status, "clWriteBuffer");
                status = clSetKernelArg(kernel_1, 7, sizeof(cl_mem), (void *)&V_HdsBuf);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 8, sizeof(int), (void *)&V_HDSWidth);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 9, sizeof(int), (void *)&V_HDSHeight);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 10, sizeof(int), (void *)&V_HDSStep);
                checkErr(status, "clSetKernelArg");
                status = clSetKernelArg(kernel_1, 11, sizeof(int), (void *)&V_HDSShift);
                checkErr(status, "clSetKernelArg");
                status = clEnqueueNDRangeKernel(g_queue, kernel_1, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
                checkErr(status, "clEnqueueNDRangeKernel");
                status = clFinish(g_queue);
                checkErr(status,"clFinish of kernel_1");
                status = clEnqueueReadBuffer(g_queue, A_HdsBuf, CL_TRUE, 0,A_H_dssz0Pad,A_HDsBufH, 0, NULL, NULL);
        status = clEnqueueReadBuffer(g_queue, V_HdsBuf, CL_TRUE, 0,V_H_dssz0Pad,V_HDsBufH, 0, NULL, NULL);
                checkErr(status,"clEnqueueReadBuffer");
                for(int i = 0; i < A_HDSHeight; i++){
        memcpy( (char*)A_H+ i *A_HDSWidth* sizeof( double),(char*) A_HDsBufH+ (i + PADDING_LINE)* A_HDSStep,A_HDSWidth* sizeof( double) );
        }
        for(int i = 0; i < V_HDSHeight; i++){
        memcpy( (char*)V_H+ i *V_HDSWidth* sizeof( double),(char*) V_HDsBufH+ (i + PADDING_LINE)* V_HDSStep,V_HDSWidth* sizeof( double) );
        }
        
        }
              }
      iteration--;
      if (pass == 1)
        break;
    }
  
  {
    size_t global_work_size[2];
    size_t transe;
    size_t Readsize;
    cl_event event_kernel;
    cl_kernel kernel_2 = clCreateKernel(g_program, "kernel_2", &status);
    checkErr(status, "clCreateKernel for kernel_2");
    global_work_size[0] = 1;
    global_work_size[1] = 256;
    size_t A_HSrcWidth = 256;
    size_t A_HSrcHeight = 256;
    size_t A_H_srcsz = sizeof( double) * 2;
    size_t A_HSrcStep = A_HSrcWidth * A_H_srcsz;
    A_HSrcStep = (A_HSrcStep % PADDING < 16) ? ((A_HSrcStep / PADDING+1) * PADDING) : ((A_HSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t A_HSrcShift = A_HSrcStep * PADDING_LINE;
    size_t A_H_srcsz0Pad = A_HSrcStep * (A_HSrcHeight + (PADDING_LINE<<1));
    cl_mem A_HsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, A_H_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
     double *A_HSrcBufH = ( double*)malloc(A_H_srcsz0Pad); 
    for(int i = 0; i < A_HSrcHeight; i++){
  memcpy( (char*)A_HSrcBufH+ (i + PADDING_LINE) * A_HSrcStep, (char*)A_H+ i * A_HSrcWidth* sizeof( double) * 2, A_HSrcWidth * sizeof( double) * 2 );
  }
    status = clEnqueueWriteBuffer(g_queue, A_HsrcBuf, CL_TRUE, 0,A_H_srcsz0Pad,A_HSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_2, 0, sizeof(cl_mem), (void *)&A_HsrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 1, sizeof(int), (void *)&A_HSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 2, sizeof(int), (void *)&A_HSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 3, sizeof(int), (void *)&A_HSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 4, sizeof(int), (void *)&A_HSrcShift);
    checkErr(status, "clSetKernelArg");
    status = clEnqueueNDRangeKernel(g_queue, kernel_2, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
    checkErr(status, "clEnqueueNDRangeKernel");
    status = clFinish(g_queue);
    checkErr(status,"clFinish of kernel_2");
    checkErr(status,"clEnqueueReadBuffer");
  
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
  double A[2][256][256];
  double V[2][256][256];
  double S[256];
  svd(&A, &S, &V);
}


