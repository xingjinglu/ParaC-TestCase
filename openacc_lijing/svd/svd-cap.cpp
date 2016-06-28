/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

#include "ClHost.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <memory.h>
#include <sys/time.h>

#define COLS  256 
#define ROWS  256 
#define TYPE  double 
#define MAX_ITERATIONS 40 
#define THRESHOLD  0.00001

bool is_matrix_equal(double *A, double *B) {
  for (int i = 0; i < 256; i++) 
    for (int j = 0; j < 256 * 2; j++) {
      if (fabs(A[i * 256 * 2 + j] - B[i * 256 * 2 + j]) > 0.001) {
        printf("i = %d j = %d\n", i, j);
        printf("A = %.6f\n", A[i * 256 * 2 + j]);
        printf("B = %.6f\n", B[i * 256 * 2 + j]);
        return 0;
      }
    }
  return 1;
}



bool is_vector_equal(double *A, double *B) {
  for (int j = 0; j < 256; j++) {
    if (fabs(A[j] - B[j]) > 1.0000000000000001E-5) {
      printf("j = %d\n", j);
      printf("A = %.6f\n", A[j]);
      printf("B = %.6f\n", B[j]);
      return 0;
    }
  }
  return 1;
}



#pragma acc routine
int sign(double a) {
  if (a > 0)
    return 1;
  if (a == 0)
    return 0;
  return -1;
}



void svd(double *A, double *B, double *S, double *V) {
  int *pass = (int *)malloc(sizeof(int));
  double *A_H = new double [256 * 256 * 2];
  double *B_H = new double [256 * 256 * 2];
  double *V_H = new double [256 * 256 * 2];
  double *S_H = new double [256];
  int *rotate_col_idx = new int [256];
  double *ci = new double [256 * 256 * 2];
  double *cj = new double [256 / 2 * 256 * 2];
  double *vi = new double [256 / 2 * 256 * 2];
  double *vj = new double [256 / 2 * 256 * 2];
  double value[128];
  for (int i = 0; i < 256; i++) 
    rotate_col_idx[i] = i;
  int iteration = 40;
  int start_index, col_p, col_q, skip_trans;
  struct timeval begin_total, end_total;
  struct timeval begin_calc, end_calc;
  struct timeval mid1, mid2;
  for (int ii = 0; ii < 10; ii++) {
    for (int i = 0; i < 256; i++) 
      for (int j = 0; j < 256; j++) 
        A_H[i * 256 + j] = A[j * 256 + i];
    for (int i = 0; i < 256; i++) 
      for (int j = 0; j < 256; j++) 
        A_H[256 * 256 + i * 256 + j] = A[256 * 256 + j * 256 + i];
    memset(V_H, 0, 256 * 256 * 2 * sizeof(double));
    for (int i = 0; i < 256; i++) 
      V_H[i * 256 + i] = 1.F;
    for (int j = 0; j < 256; j++) 
      S_H[j] = 0;
    for (int i = 0; i < 256; i++) 
      rotate_col_idx[i] = i;
    iteration = 40;
    gettimeofday(&begin_total, __null);
        //create buffers on GPU according to data pragma
    int A_H0Size = sizeof(double) * 256 * 256 * 2;
    cl_mem A_H0Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, A_H0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for A_H");
    int B_H0Size = sizeof(double) * 256 * 256 * 2;
    cl_mem B_H0Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, B_H0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for B_H");
    int V_H0Size = sizeof(double) * 256 * 256 * 2;
    cl_mem V_H0Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, V_H0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for V_H");
    int S_H0Size = sizeof(double) * 256;
    cl_mem S_H0Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, S_H0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for S_H");
    int rotate_col_idx0Size = sizeof(int) * 256;
    cl_mem rotate_col_idx0Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, rotate_col_idx0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for rotate_col_idx");
    int ci0Size = sizeof(double) * 256 * 256 * 2;
    cl_mem ci0Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, ci0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for ci");
    int cj0Size = sizeof(double) * 256 / 2 * 256 * 2;
    cl_mem cj0Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, cj0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for cj");
    int vi0Size = sizeof(double) * 256 / 2 * 256 * 2;
    cl_mem vi0Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, vi0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for vi");
    int vj0Size = sizeof(double) * 256 / 2 * 256 * 2;
    cl_mem vj0Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, vj0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for vj");
    int value0Size = sizeof(double) * 256 / 2;
    cl_mem value0Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, value0Size, NULL, &status);
    checkErr(status, "clCreateBuffer for value");

    //copyin buffers to GPU according to data pragma
    status = clEnqueueWriteBuffer(queue, A_H0Buffer, CL_TRUE, 0, A_H0Size, A_H, 0, NULL, NULL);
    checkErr(status, "clEnqueueWriteBuffer for A_H");
    status = clEnqueueWriteBuffer(queue, V_H0Buffer, CL_TRUE, 0, V_H0Size, V_H, 0, NULL, NULL);
    checkErr(status, "clEnqueueWriteBuffer for V_H");
    status = clEnqueueWriteBuffer(queue, rotate_col_idx0Buffer, CL_TRUE, 0, rotate_col_idx0Size, rotate_col_idx, 0, NULL, NULL);
    checkErr(status, "clEnqueueWriteBuffer for rotate_col_idx");

    #pragma cap data copy(A_H[0:256 * 256 * 2], V_H[0:256 * 256 * 2]) copyin(rotate_col_idx[0:256]) create(ci[0:256 * 256 * 2], cj[0:256 / 2 * 256 * 2], vi[0:256 / 2 * 256 * 2], vj[0:256 / 2 * 256 * 2], value[0:256 / 2]) copyout(B_H[0:256 * 256 * 2], S_H[0:256]) 
      {
        gettimeofday(&begin_calc, __null);
        while (iteration > 0)
          {
            pass[0] = 1;
                        //create buffers on GPU according to data pragma
            int pass1Size = sizeof(int) * 1;
            cl_mem pass1Buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, pass1Size, NULL, &status);
            checkErr(status, "clCreateBuffer for pass");

            //copyin buffers to GPU according to data pragma
            status = clEnqueueWriteBuffer(queue, pass1Buffer, CL_TRUE, 0, pass1Size, pass, 0, NULL, NULL);
            checkErr(status, "clEnqueueWriteBuffer for pass");

            #pragma cap data copy(pass[0:1]) 
              {
                for (int i = 0; i < 256; i++) {
                  start_index = (i % 2 == 0) ? 0 : 1;
                                    //create the kernel
                  cl_kernel kernel_1 = clCreateKernel(program, "kernel_1", &status);
                  checkErr(status, "clCreateKernel for kernel_1");

                  //set thread/thread-block size
                  size_t localWorkSize1[3]= {1, 1, 1};
                  size_t blockWorkSize1[3]= {1, 1, 1};
                  size_t globalWorkSize1[3]= {1, 1, 1};
                  blockWorkSize1[0] = (256 - (start_index + 1) + 2 - 1) / (2);
                  localWorkSize1[0] = 256;
                  globalWorkSize1[0] = blockWorkSize1[0] * localWorkSize1[0];
                  //set kernel parameters
                  status = clSetKernelArg(kernel_1, 0, sizeof(cl_mem), (void *)&pass1Buffer);
                  checkErr(status, "clSetKernelArg for 0");
                  status = clSetKernelArg(kernel_1, 1, sizeof(cl_mem), (void *)&A_H0Buffer);
                  checkErr(status, "clSetKernelArg for 1");
                  status = clSetKernelArg(kernel_1, 2, sizeof(cl_mem), (void *)&V_H0Buffer);
                  checkErr(status, "clSetKernelArg for 2");
                  status = clSetKernelArg(kernel_1, 3, sizeof(cl_mem), (void *)&rotate_col_idx0Buffer);
                  checkErr(status, "clSetKernelArg for 3");
                  status = clSetKernelArg(kernel_1, 4, sizeof(cl_mem), (void *)&ci0Buffer);
                  checkErr(status, "clSetKernelArg for 4");
                  status = clSetKernelArg(kernel_1, 5, sizeof(cl_mem), (void *)&cj0Buffer);
                  checkErr(status, "clSetKernelArg for 5");
                  status = clSetKernelArg(kernel_1, 6, sizeof(cl_mem), (void *)&vi0Buffer);
                  checkErr(status, "clSetKernelArg for 6");
                  status = clSetKernelArg(kernel_1, 7, sizeof(cl_mem), (void *)&vj0Buffer);
                  checkErr(status, "clSetKernelArg for 7");
                  status = clSetKernelArg(kernel_1, 8, sizeof(cl_mem), (void *)&value0Buffer);
                  checkErr(status, "clSetKernelArg for 8");
                  status = clSetKernelArg(kernel_1, 9, sizeof(int), (void *)&start_index);
                  checkErr(status, "clSetKernelArg for 9");
                  status = clSetKernelArg(kernel_1, 10, 16 * localWorkSize1[0] * localWorkSize1[1] * localWorkSize1[2] , NULL);
                  checkErr(status, "clSetKernelArg for 10");

                  //launch a kernel
                  status = clEnqueueNDRangeKernel(queue, kernel_1, 1, NULL, globalWorkSize1, localWorkSize1, 0, NULL, NULL);
                  checkErr(status, "clEnqueueNDRangeKernel for kernel_1");

                  //wait until kernel finish
                  status = clFinish(queue);
                  checkErr(status, "clFinish for kernel_1");

                  //release kernel
                  clReleaseKernel(kernel_1);
                }
              }
            //copyout buffers to CPU acccording to data pragma
            status = clEnqueueReadBuffer(queue, pass1Buffer, CL_TRUE, 0, pass1Size, pass, 0, NULL, NULL);
            checkErr(status, "clEnqueueReadBuffer for pass");

            //release buffers
            clReleaseMemObject(pass1Buffer);

            iteration--;
            if (pass[0] == 1)
              break;
          }
        gettimeofday(&mid1, __null);
                //create the kernel
        cl_kernel kernel_2 = clCreateKernel(program, "kernel_2", &status);
        checkErr(status, "clCreateKernel for kernel_2");

        //set thread/thread-block size
        size_t localWorkSize2[3]= {1, 1, 1};
        size_t blockWorkSize2[3]= {1, 1, 1};
        size_t globalWorkSize2[3]= {1, 1, 1};
        blockWorkSize2[0] = 256;
        localWorkSize2[0] = 256;
        globalWorkSize2[0] = blockWorkSize2[0] * localWorkSize2[0];
        //set kernel parameters
        status = clSetKernelArg(kernel_2, 0, sizeof(cl_mem), (void *)&S_H0Buffer);
        checkErr(status, "clSetKernelArg for 0");
        status = clSetKernelArg(kernel_2, 1, sizeof(cl_mem), (void *)&A_H0Buffer);
        checkErr(status, "clSetKernelArg for 1");
        status = clSetKernelArg(kernel_2, 2, sizeof(cl_mem), (void *)&ci0Buffer);
        checkErr(status, "clSetKernelArg for 2");
        status = clSetKernelArg(kernel_2, 3, 16 * localWorkSize2[0] * localWorkSize2[1] * localWorkSize2[2] , NULL);
        checkErr(status, "clSetKernelArg for 3");

        //launch a kernel
        status = clEnqueueNDRangeKernel(queue, kernel_2, 1, NULL, globalWorkSize2, localWorkSize2, 0, NULL, NULL);
        checkErr(status, "clEnqueueNDRangeKernel for kernel_2");

        //wait until kernel finish
        status = clFinish(queue);
        checkErr(status, "clFinish for kernel_2");

        //release kernel
        clReleaseKernel(kernel_2);
        gettimeofday(&mid2, __null);
                //create the kernel
        cl_kernel kernel_3 = clCreateKernel(program, "kernel_3", &status);
        checkErr(status, "clCreateKernel for kernel_3");

        //set thread/thread-block size
        size_t localWorkSize3[3]= {1, 1, 1};
        size_t blockWorkSize3[3]= {1, 1, 1};
        size_t globalWorkSize3[3]= {1, 1, 1};
        localWorkSize3[1] = 8;
        blockWorkSize3[1] = upMultiple( 256, 8 );
        localWorkSize3[0] = 32;
        blockWorkSize3[0] = upMultiple( 256, 32 );
        globalWorkSize3[0] = blockWorkSize3[0] * localWorkSize3[0];
        globalWorkSize3[1] = blockWorkSize3[1] * localWorkSize3[1];
        //set kernel parameters
        status = clSetKernelArg(kernel_3, 0, sizeof(cl_mem), (void *)&B_H0Buffer);
        checkErr(status, "clSetKernelArg for 0");
        status = clSetKernelArg(kernel_3, 1, sizeof(cl_mem), (void *)&A_H0Buffer);
        checkErr(status, "clSetKernelArg for 1");
        status = clSetKernelArg(kernel_3, 2, sizeof(cl_mem), (void *)&S_H0Buffer);
        checkErr(status, "clSetKernelArg for 2");

        //launch a kernel
        status = clEnqueueNDRangeKernel(queue, kernel_3, 2, NULL, globalWorkSize3, localWorkSize3, 0, NULL, NULL);
        checkErr(status, "clEnqueueNDRangeKernel for kernel_3");

        //wait until kernel finish
        status = clFinish(queue);
        checkErr(status, "clFinish for kernel_3");

        //release kernel
        clReleaseKernel(kernel_3);
        gettimeofday(&end_calc, __null);
      }
    //copyout buffers to CPU acccording to data pragma
    status = clEnqueueReadBuffer(queue, A_H0Buffer, CL_TRUE, 0, A_H0Size, A_H, 0, NULL, NULL);
    checkErr(status, "clEnqueueReadBuffer for A_H");
    status = clEnqueueReadBuffer(queue, B_H0Buffer, CL_TRUE, 0, B_H0Size, B_H, 0, NULL, NULL);
    checkErr(status, "clEnqueueReadBuffer for B_H");
    status = clEnqueueReadBuffer(queue, V_H0Buffer, CL_TRUE, 0, V_H0Size, V_H, 0, NULL, NULL);
    checkErr(status, "clEnqueueReadBuffer for V_H");
    status = clEnqueueReadBuffer(queue, S_H0Buffer, CL_TRUE, 0, S_H0Size, S_H, 0, NULL, NULL);
    checkErr(status, "clEnqueueReadBuffer for S_H");

    //release buffers
    clReleaseMemObject(A_H0Buffer);
    clReleaseMemObject(B_H0Buffer);
    clReleaseMemObject(V_H0Buffer);
    clReleaseMemObject(S_H0Buffer);
    clReleaseMemObject(rotate_col_idx0Buffer);
    clReleaseMemObject(ci0Buffer);
    clReleaseMemObject(cj0Buffer);
    clReleaseMemObject(vi0Buffer);
    clReleaseMemObject(vj0Buffer);
    clReleaseMemObject(value0Buffer);

    gettimeofday(&end_total, __null);
    printf("%lf %lf %lf %lf\n", A_H[0], B_H[0], V_H[0], S[0]);
    printf("Used %d iters\n", 40 - iteration);
    printf("Total: %ld ms\n", (end_total.tv_sec - begin_total.tv_sec) * 1000 + (end_total.tv_usec - begin_total.tv_usec) / 1000);
    printf("V: %ld ms\n", (mid1.tv_sec - begin_calc.tv_sec) * 1000 + (mid1.tv_usec - begin_calc.tv_usec) / 1000);
    printf("S: %ld ms\n", (mid2.tv_sec - mid1.tv_sec) * 1000 + (mid2.tv_usec - mid1.tv_usec) / 1000);
    printf("B: %ld ms\n", (end_calc.tv_sec - mid2.tv_sec) * 1000 + (end_calc.tv_usec - mid2.tv_usec) / 1000);
    printf("Env1: %ld ms\n", (end_total.tv_sec - end_calc.tv_sec) * 1000 + (end_total.tv_usec - end_calc.tv_usec) / 1000);
    printf("Env2: %ld ms\n", (begin_calc.tv_sec - begin_total.tv_sec) * 1000 + (begin_calc.tv_usec - begin_total.tv_usec) / 1000);
  }
  for (int i = 0; i < 256; i++) 
    for (int j = 0; j < 256; j++) {
      A[i * 256 * 2 + j * 2] = A_H[j * 256 + i];
      A[i * 256 * 2 + j * 2 + 1] = A_H[256 * 256 + j * 256 + i];
      B[i * 256 * 2 + j * 2] = B_H[j * 256 + i];
      B[i * 256 * 2 + j * 2 + 1] = B_H[256 * 256 + j * 256 + i];
      V[i * 256 * 2 + j * 2] = V_H[j * 256 + i];
      V[i * 256 * 2 + j * 2 + 1] = V_H[256 * 256 + j * 256 + i];
    }
  for (int i = 0; i < 256; i++) 
    S[i] = S_H[i];
  delete rotate_col_idx;
  delete A_H;
  delete B_H;
  delete V_H;
  delete S_H;
  delete ci;
  delete cj;
  delete vi;
  delete vj;
}



int host_main() {
  double *A = new double [256 * 256 * 2];
  double *B = new double [256 * 256 * 2];
  double *S = new double [256];
  double *V = new double [256 * 256 * 2];
  FILE *fp = fopen("./data/Matrix_input_256A_m.txt", "r");
  if (fp == __null) {
    printf("matrix input A is not found\n");
    return 1;
  }
  double temp;
  for (int i = 0; i < 256; i++) {
    for (int j = 0; j < 256; j++) {
      fscanf(fp, "%lf", &temp);
      A[i * 256 + j] = temp;
    }
    for (int j = 0; j < 256; j++) {
      fscanf(fp, "%lf", &temp);
      A[256 * 256 + i * 256 + j] = temp;
    }
  }
  fclose(fp);
  for (int i = 0; i < 256; i++) 
    for (int j = 0; j < 256 * 2; j++) {
      if (j == 2 * i)
        V[i * 256 * 2 + j] = 1;
      else
        V[i * 256 * 2 + j] = 0;
    }
  for (int i = 0; i < 256; i++) 
    S[i] = 0;
  svd(A, B, S, V);
  printf("\n\n");
  double *A1 = new double [256 * 256 * 2];
  double *V1 = new double [256 * 256 * 2];
  double *S1 = new double [256];
  FILE *fp1 = fopen("./data/Matrix_out_A256.txt", "r");
  if (fp1 == __null) {
    printf("matrix output A is not found\n");
    return 1;
  }
  for (int i = 0; i < 256; i++) {
    for (int j = 0; j < 256; j++) {
      fscanf(fp1, "%lf", &temp);
      A1[i * 256 * 2 + j * 2] = temp;
    }
    for (int j = 0; j < 256; j++) {
      fscanf(fp1, "%lf", &temp);
      A1[i * 256 * 2 + j * 2 + 1] = temp;
    }
  }
  fclose(fp1);
  printf("compare A\n");
  bool result = is_matrix_equal(A, A1);
  if (result == 1)
    printf("success\n");
  FILE *fp2 = fopen("./data/Matrix_out_V256.txt", "r");
  if (fp2 == __null) {
    printf("matrix output V is not found\n");
    return 1;
  }
  for (int i = 0; i < 256; i++) {
    for (int j = 0; j < 256; j++) {
      fscanf(fp2, "%lf", &temp);
      V1[i * 256 * 2 + j * 2] = temp;
    }
    for (int j = 0; j < 256; j++) {
      fscanf(fp2, "%lf", &temp);
      V1[i * 256 * 2 + j * 2 + 1] = temp;
    }
  }
  fclose(fp2);
  printf("compare V\n");
  result = is_matrix_equal(V, V1);
  if (result == 1)
    printf("success\n");
  FILE *fp3 = fopen("./data/Matrix_out_S256.txt", "r");
  if (fp3 == __null) {
    printf("matrix output S is not found\n");
    return 1;
  }
  for (int j = 0; j < 256; j++) {
    fscanf(fp3, "%lf", &temp);
    S1[j] = temp;
  }
  fclose(fp3);
  printf("compare S\n");
  result = is_vector_equal(S, S1);
  if (result == 1)
    printf("success\n");
  delete A;
  delete B;
  delete S;
  delete V;
  return 0;
}

int main() {
  // Create environment variables before the first data transfer.
  const char *inputFile = "svd-cap.cl";

  if (-1 == openCLCreate(&context, &queue, &program, inputFile)) {
    printf("OpenCL create fail!\n");
    exit(-1);
  }

  int ret =  host_main();
  
  // Release environment vars.
  clReleaseProgram(program);
  clReleaseCommandQueue(queue);
  clReleaseContext(context);

  return ret;
}



