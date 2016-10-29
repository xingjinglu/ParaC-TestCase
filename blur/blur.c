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

#if 1
int blur_ser(short *input, short *resultx, short *resulty) {
  int i, j;
  for (i = 1; i < (6408 - 1); i++) 
    for (j = 1; j < 4802 - 1; j++) {
      resultx[i * 4802 + j] = (input[(i - 1) * 4802 + j] + input[i * 4802 + j] + input[(i + 1) * 4802 + j]) / 3;
    }
  for (i = 1; i < 6408 - 1; i++) 
    for (j = 1; j < 4802 - 1; j++) {
      resulty[i * 4802 + j] = (resultx[i * 4802 + j - 1] + resultx[i * 4802 + j] + resultx[i * 4802 + j + 1]) / 3;
    }
}


#endif

#if 0
void blur(parac_matrix short &in[HEIGHT][WIDTH], 
    parac_matrix short &intermediate[HEIGHT][WIDTH], 
    parac_matrix short &out[HEIGHT][WIDTH] )
{
  parac_iterator it(iter_element; 0:HEIGHT:1; 1:WIDTH-1:1 ){
    intermediate[itx][ity] = (in[itx-1][ity] + in[itx][ity] + in[itx+1][ity])/3;
  }

  parac_iterator it1(iter_element; 1:HEIGHT-1:1; 0:WIDTH:1 ){
    out[it1x][it1y] = (in[it1x-1][it1y] + in[it1x][it1y] + in[it1x][it1y+1])/3;
  }

}
#endif

void blur_conv(short (*in)[6408][4802], short (*intermediate)[6408][4802], short (*out)[6408][4802]) {
  short filter_h[1][3] = { 1, 1, 1 };
  short filter_v[3][1] = { 1, 1, 1 };
  
  {
    size_t global_work_size[2];
    size_t transe;
    cl_event event_kernel;
    cl_kernel kernel_1 = clCreateKernel(g_program, "kernel_1", &status);
    checkErr(status, "clCreateKernel for kernel_1");
    global_work_size[0] = 6406;
    global_work_size[1] = 4800;
    size_t inSrcWidth = 4802;
    size_t inSrcHeight = 6408;
    size_t in_srcsz = sizeof(short);
    size_t inSrcStep = inSrcWidth * in_srcsz;
    inSrcStep = (inSrcStep % PADDING < 16) ? ((inSrcStep / PADDING+1) * PADDING) : ((inSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t inSrcShift = inSrcStep * PADDING_LINE;
    size_t in_srcsz0Pad = inSrcStep * (inSrcHeight + (PADDING_LINE<<1));
    cl_mem insrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, in_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    short *inSrcBufH = (short*)malloc(in_srcsz0Pad); 
    for(int i = 0; i < inSrcHeight; i++){
  memcpy( (char*)inSrcBufH+ (i + PADDING_LINE) * inSrcStep, (char*)in+ i * inSrcWidth* sizeof(short), inSrcWidth * sizeof(short) );
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
    size_t filter_vSrcWidth = 1;
    size_t filter_vSrcHeight = 3;
    size_t filter_v_srcsz = sizeof(short);
    size_t filter_vSrcStep = filter_vSrcWidth * filter_v_srcsz;
    filter_vSrcStep = (filter_vSrcStep % PADDING < 16) ? ((filter_vSrcStep / PADDING+1) * PADDING) : ((filter_vSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t filter_vSrcShift = filter_vSrcStep * PADDING_LINE;
    size_t filter_v_srcsz0Pad = filter_vSrcStep * (filter_vSrcHeight + (PADDING_LINE<<1));
    cl_mem filter_vsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, filter_v_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    short *filter_vSrcBufH = (short*)malloc(filter_v_srcsz0Pad); 
    for(int i = 0; i < filter_vSrcHeight; i++){
  memcpy( (char*)filter_vSrcBufH+ (i + PADDING_LINE) * filter_vSrcStep, (char*)filter_v+ i * filter_vSrcWidth* sizeof(short), filter_vSrcWidth * sizeof(short) );
  }
    status = clEnqueueWriteBuffer(g_queue, filter_vsrcBuf, CL_TRUE, 0,filter_v_srcsz0Pad,filter_vSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_1, 5, sizeof(cl_mem), (void *)&filter_vsrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 6, sizeof(int), (void *)&filter_vSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 7, sizeof(int), (void *)&filter_vSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 8, sizeof(int), (void *)&filter_vSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 9, sizeof(int), (void *)&filter_vSrcShift);
    checkErr(status, "clSetKernelArg");
    size_t intermediateDstWidth = 4802;
    size_t intermediateDstHeight = 6408;
    size_t intermediate_dstsz = sizeof(short);
    size_t intermediateDstStep = intermediateDstWidth * intermediate_dstsz;
    intermediateDstStep = (intermediateDstStep % PADDING < 16) ? ((intermediateDstStep / PADDING+1) * PADDING) : ((intermediateDstStep + PADDING) / PADDING+1) * PADDING;
    size_t intermediateDstShift = intermediateDstStep * PADDING_LINE;
    size_t intermediate_dstsz0Pad = intermediateDstStep * (intermediateDstHeight + (PADDING_LINE<<1));
    cl_mem intermediatedstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, intermediate_dstsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    short *intermediateDstBufH = (short*)malloc(intermediate_dstsz0Pad); 
    for(int i = 0; i < intermediateDstHeight; i++){
  memcpy( (char*)intermediateDstBufH+ (i + PADDING_LINE) * intermediateDstStep,(char*)intermediate + i * intermediateDstWidth* sizeof(short),intermediateDstWidth* sizeof(short) );
  }
    status = clEnqueueWriteBuffer(g_queue, intermediatedstBuf, CL_TRUE, 0,intermediate_dstsz0Pad,intermediateDstBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_1, 10, sizeof(cl_mem), (void *)&intermediatedstBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 11, sizeof(int), (void *)&intermediateDstWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 12, sizeof(int), (void *)&intermediateDstHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 13, sizeof(int), (void *)&intermediateDstStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_1, 14, sizeof(int), (void *)&intermediateDstShift);
    checkErr(status, "clSetKernelArg");
    status = clEnqueueNDRangeKernel(g_queue, kernel_1, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
    checkErr(status, "clEnqueueNDRangeKernel");
    status = clFinish(g_queue);
    checkErr(status,"clFinish of kernel_1");
      status = clEnqueueReadBuffer(g_queue, intermediatedstBuf, CL_TRUE, 0,intermediate_dstsz0Pad,intermediateDstBufH, 0, NULL, NULL);
    for(int i = 0; i < intermediateDstHeight; i++){
  memcpy( (char*)intermediate+ i *intermediateDstWidth* sizeof(short), (char*) intermediateDstBufH+ (i + PADDING_LINE)* intermediateDstStep, intermediateDstWidth* sizeof(short) );
  }
  
  }
  
  {
    size_t global_work_size[2];
    size_t transe;
    cl_event event_kernel;
    cl_kernel kernel_2 = clCreateKernel(g_program, "kernel_2", &status);
    checkErr(status, "clCreateKernel for kernel_2");
    global_work_size[0] = 1601;
    global_work_size[1] = 4800;
    size_t intermediateSrcWidth = 4802;
    size_t intermediateSrcHeight = 6408;
    size_t intermediate_srcsz = sizeof(short);
    size_t intermediateSrcStep = intermediateSrcWidth * intermediate_srcsz;
    intermediateSrcStep = (intermediateSrcStep % PADDING < 16) ? ((intermediateSrcStep / PADDING+1) * PADDING) : ((intermediateSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t intermediateSrcShift = intermediateSrcStep * PADDING_LINE;
    size_t intermediate_srcsz0Pad = intermediateSrcStep * (intermediateSrcHeight + (PADDING_LINE<<1));
    cl_mem intermediatesrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, intermediate_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    short *intermediateSrcBufH = (short*)malloc(intermediate_srcsz0Pad); 
    for(int i = 0; i < intermediateSrcHeight; i++){
  memcpy( (char*)intermediateSrcBufH+ (i + PADDING_LINE) * intermediateSrcStep, (char*)intermediate+ i * intermediateSrcWidth* sizeof(short), intermediateSrcWidth * sizeof(short) );
  }
    status = clEnqueueWriteBuffer(g_queue, intermediatesrcBuf, CL_TRUE, 0,intermediate_srcsz0Pad,intermediateSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_2, 0, sizeof(cl_mem), (void *)&intermediatesrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 1, sizeof(int), (void *)&intermediateSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 2, sizeof(int), (void *)&intermediateSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 3, sizeof(int), (void *)&intermediateSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 4, sizeof(int), (void *)&intermediateSrcShift);
    checkErr(status, "clSetKernelArg");
    size_t filter_hSrcWidth = 3;
    size_t filter_hSrcHeight = 1;
    size_t filter_h_srcsz = sizeof(short);
    size_t filter_hSrcStep = filter_hSrcWidth * filter_h_srcsz;
    filter_hSrcStep = (filter_hSrcStep % PADDING < 16) ? ((filter_hSrcStep / PADDING+1) * PADDING) : ((filter_hSrcStep + PADDING) / PADDING+1) * PADDING;
    size_t filter_hSrcShift = filter_hSrcStep * PADDING_LINE;
    size_t filter_h_srcsz0Pad = filter_hSrcStep * (filter_hSrcHeight + (PADDING_LINE<<1));
    cl_mem filter_hsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, filter_h_srcsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    short *filter_hSrcBufH = (short*)malloc(filter_h_srcsz0Pad); 
    for(int i = 0; i < filter_hSrcHeight; i++){
  memcpy( (char*)filter_hSrcBufH+ (i + PADDING_LINE) * filter_hSrcStep, (char*)filter_h+ i * filter_hSrcWidth* sizeof(short), filter_hSrcWidth * sizeof(short) );
  }
    status = clEnqueueWriteBuffer(g_queue, filter_hsrcBuf, CL_TRUE, 0,filter_h_srcsz0Pad,filter_hSrcBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_2, 5, sizeof(cl_mem), (void *)&filter_hsrcBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 6, sizeof(int), (void *)&filter_hSrcWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 7, sizeof(int), (void *)&filter_hSrcHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 8, sizeof(int), (void *)&filter_hSrcStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 9, sizeof(int), (void *)&filter_hSrcShift);
    checkErr(status, "clSetKernelArg");
    size_t outDstWidth = 4802;
    size_t outDstHeight = 6408;
    size_t out_dstsz = sizeof(short);
    size_t outDstStep = outDstWidth * out_dstsz;
    outDstStep = (outDstStep % PADDING < 16) ? ((outDstStep / PADDING+1) * PADDING) : ((outDstStep + PADDING) / PADDING+1) * PADDING;
    size_t outDstShift = outDstStep * PADDING_LINE;
    size_t out_dstsz0Pad = outDstStep * (outDstHeight + (PADDING_LINE<<1));
    cl_mem outdstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, out_dstsz0Pad, NULL, &status);
    checkErr(status, "clCreateBuffer");
    short *outDstBufH = (short*)malloc(out_dstsz0Pad); 
    for(int i = 0; i < outDstHeight; i++){
  memcpy( (char*)outDstBufH+ (i + PADDING_LINE) * outDstStep,(char*)out + i * outDstWidth* sizeof(short),outDstWidth* sizeof(short) );
  }
    status = clEnqueueWriteBuffer(g_queue, outdstBuf, CL_TRUE, 0,out_dstsz0Pad,outDstBufH, 0, NULL, NULL);
    checkErr(status, "clWriteBuffer");
    status = clSetKernelArg(kernel_2, 10, sizeof(cl_mem), (void *)&outdstBuf);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 11, sizeof(int), (void *)&outDstWidth);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 12, sizeof(int), (void *)&outDstHeight);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 13, sizeof(int), (void *)&outDstStep);
    checkErr(status, "clSetKernelArg");
    status = clSetKernelArg(kernel_2, 14, sizeof(int), (void *)&outDstShift);
    checkErr(status, "clSetKernelArg");
    status = clEnqueueNDRangeKernel(g_queue, kernel_2, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
    checkErr(status, "clEnqueueNDRangeKernel");
    status = clFinish(g_queue);
    checkErr(status,"clFinish of kernel_2");
      status = clEnqueueReadBuffer(g_queue, outdstBuf, CL_TRUE, 0,out_dstsz0Pad,outDstBufH, 0, NULL, NULL);
    for(int i = 0; i < outDstHeight; i++){
  memcpy( (char*)out+ i *outDstWidth* sizeof(short), (char*) outDstBufH+ (i + PADDING_LINE)* outDstStep, outDstWidth* sizeof(short) );
  }
  
  }
}





int main() {
  char inputfile[] = "blur.cl";
  char *remain = NULL;
  if (-1 == openCLCreate(inputfile, remain)) {
    printf("openCL create fail !!!!!!");
    return 0;
  }
  short *input = (short *)malloc(sizeof(short) * 4802 * 6408);
  short *meta = (short *)malloc(sizeof(short) * 4802 * 6408);
  short *output = (short *)malloc(sizeof(short) * 4802 * 6408);
  short *outputx_cpu = (short *)malloc(sizeof(short) * 4802 * 6408);
  short *outputy_cpu = (short *)malloc(sizeof(short) * 4802 * 6408);
  for (int i = 0; i < 6408; i++) 
    for (int j = 0; j < 4802; j++) 
      input[i * 4802 + j] = rand() % 256;
  short (*src)[6408][4802] = (short (*)[6408][4802])input;
  short (*intermediate)[6408][4802] = (short (*)[6408][4802])meta;
  short (*dst)[6408][4802] = (short (*)[6408][4802])output;
  blur_ser(input, outputx_cpu, outputy_cpu);
  blur_conv(src, intermediate, dst);
  for (int i = 1; i < 6408 - 1; i++) 
    for (int j = 1; j < 4802 - 1; j++) {
      if (abs(meta[i * 4802 + j] - outputx_cpu[i * 4802 + j]) > 1) {
        printf("kernel_1: %d, %d, %d, %d \n", i, j, meta[i * 4802 + j], outputy_cpu[i * 4802 + j]);
        abort();
      }
    }
  for (int i = 1; i < 6408 - 1; i++) 
    for (int j = 1; j < 4802 - 1; j++) {
      if (abs(output[i * 4802 + j] - outputy_cpu[i * 4802 + j]) > 1) {
        printf("kernel_2: %d, %d, %d, %d \n", i, j, output[i * 4802 + j], outputy_cpu[i * 4802 + j]);
        abort();
      }
    }
}


