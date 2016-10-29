/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

//TODO:这几个参数应从CPU端传过来
//#include<ClHost.h>
#define TYPE double
#define THRESHOLD 0.00001

//因为对矩阵进行了转置，所以，这里ROWS和COLS的值应该和在CPU端的值相互置换
#define ROWS 256
#define COLS 256

//计算两个复数向量的内积
//result 计算实部
//result1 计算虚部
//(a + bi)'* (c + di) = (a - bi)*(c+di) = ac + bd + (ad -bc)i 
void* inner_product(TYPE p_real, TYPE p_imag, TYPE q_real, TYPE q_imag,
                   __local TYPE *result, __local TYPE *result1, int l_idx) {    
    //初始化  
    TYPE middle_result;
     middle_result = p_real * q_real;
    middle_result = fma(p_imag, q_imag, middle_result); //ac + bd
    result[l_idx]  = middle_result; //ac + bd 


    middle_result = -(p_imag * q_real);
    middle_result = fma(p_real, q_imag, middle_result); //ad -bc 
    result1[l_idx]  = middle_result; //ad - bc 
    barrier(CLK_LOCAL_MEM_FENCE); 


    //进行规约计算, 
    //AMD GPU work-group(block,CUDA)最大为256 
    //目前，为性能测试，work-group大小为256  
    //前128个线程计算result（实部），后128个线程计算result1(虚部） 
    if(l_idx < 128) 
        result[l_idx] += result[l_idx + 128];
    if(l_idx >= 128) 
        result1[l_idx -128] += result1[l_idx - 128 + 128];

     barrier(CLK_LOCAL_MEM_FENCE);

    //AMD GPU wavefront(warp,CUDA)大小为64个线程, work-group 大小最小为64个线程 
    if(l_idx < 64) 
        result[l_idx] += result[l_idx + 64];
    if(l_idx < 32) 
        result[l_idx] += result[l_idx + 32];
    if(l_idx < 16) 
        result[l_idx] += result[l_idx + 16];
    if(l_idx < 8) 
        result[l_idx] += result[l_idx + 8];
    if(l_idx < 4) 
        result[l_idx] += result[l_idx + 4];
    if(l_idx < 2) 
        result[l_idx] += result[l_idx + 2]; 
    if(l_idx < 1) 
        result[l_idx] += result[l_idx + 1]; 


    if(l_idx >= 128) 
    { 
        if(l_idx < 192)  
            result1[l_idx - 128] += result1[l_idx - 128 + 64];
        if(l_idx < 160) 
            result1[l_idx - 128] += result1[l_idx - 128 + 32];
        if(l_idx < 144) 
            result1[l_idx - 128] += result1[l_idx - 128 + 16];
        if(l_idx < 136) 
            result1[l_idx - 128] += result1[l_idx - 128 + 8]; 
        if(l_idx < 132) 
            result1[l_idx - 128] += result1[l_idx - 128 + 4]; 
        if(l_idx < 130) 
            result1[l_idx - 128] += result1[l_idx - 128 + 2]; 
        if(l_idx < 129) 
            result1[l_idx - 128] += result1[l_idx - 128 + 1]; 
    } 

    barrier(CLK_LOCAL_MEM_FENCE); 
} 
 


#define TYPE double

TYPE part_product(TYPE p_real, TYPE p_imag, TYPE q_real, TYPE q_imag,
                  __local TYPE *result, int l_idx) {    
    //初始化  
    TYPE middle_result;

    middle_result = q_real * q_real;
    middle_result = fma(q_imag,  q_imag, middle_result);
    middle_result = fma(-p_real, p_real, middle_result);
    middle_result = fma(-p_imag, p_imag, middle_result);
    result[l_idx]  = middle_result; 

    barrier(CLK_LOCAL_MEM_FENCE); 

    //进行规约计算, 
    //AMD GPU work-group(block,CUDA)最大为256 
    //目前，为性能测试，work-group大小为256  
    //前128个线程计算result（实部），后128个线程计算result1(虚部） 
    if(l_idx < 128) 
        result[l_idx] += result[l_idx + 128];

     barrier(CLK_LOCAL_MEM_FENCE);

    //AMD GPU wavefront(warp,CUDA)大小为64个线程, work-group 大小最小为64个线程 
    if(l_idx < 64) 
        result[l_idx] += result[l_idx + 64];
    if(l_idx < 32) 
        result[l_idx] += result[l_idx + 32];
    if(l_idx < 16) 
        result[l_idx] += result[l_idx + 16];
    if(l_idx < 8) 
        result[l_idx] += result[l_idx + 8];
    if(l_idx < 4) 
        result[l_idx] += result[l_idx + 4];
    if(l_idx < 2) 
        result[l_idx] += result[l_idx + 2]; 
    if(l_idx < 1) 
        result[l_idx] += result[l_idx + 1]; 

    barrier(CLK_LOCAL_MEM_FENCE); 
     return result[0];
} 

__inline double  sig(double v)
{                                                                                                                                                              
    if(v == 0) return 0;

    if(v > 0) return 1;

    return -1;
}

/* kernel function */
__kernel void kernel_1(
  int start_index,
  int i,
  __global int *pass,
  __global double *A_HDS,
  int A_HDSWidth,
  int A_HDSHeight,
  int A_HDSStep,
  int A_HDSShift,
  __global double *V_HDS,
  int V_HDSWidth,
  int V_HDSHeight,
  int V_HDSStep,
  int V_HDSShift,
  __global int *rotate_col_idxDS,
  int rotate_col_idxDSWidth,
  int rotate_col_idxDSStep,
  int rotate_col_idxDSShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);
  const int lidx = get_local_id(0);
  const int lidy = get_local_id(1);
  const int gridx = get_group_id(0);
  const int gridy = get_group_id(1);

  /* kernel boundary check */
  if ( gridy >= 1 )
    return;

  /* kernel index calculation */
  int A_HDSIdx1;
  int A_HDSIdx2;
  int V_HDSIdx3;
  int V_HDSIdx4;
  int rotate_col_idxDSIdx5 = rotate_col_idxDSShift + (int)(((float)gridx * 2 + start_index) *sizeof(int));
  int rotate_col_idxDSIdx6 = rotate_col_idxDSShift + (int)(((float)gridx * 2 + 1 + start_index) *sizeof(int));

  /* kernel operands */
  __global double *A_HDSDt1;
  __global double *A_HDSDt2;
  __global double *V_HDSDt3;
  __global double *V_HDSDt4;
  __global int *rotate_col_idxDSDt5 = (__global int *) ((__global char *)rotate_col_idxDS + rotate_col_idxDSIdx5);
  __global int *rotate_col_idxDSDt6 = (__global int *) ((__global char *)rotate_col_idxDS + rotate_col_idxDSIdx6);

  /* kernel operation */
  {
    if (i == 0 && gidy == 0)
      *pass = 1;
    int col_p = *(rotate_col_idxDSDt5);
    int col_q = *(rotate_col_idxDSDt6);
    A_HDSIdx1 = A_HDSShift + (col_p) *A_HDSStep;
    A_HDSDt1 = (__global double*)((__global char*)A_HDS + A_HDSIdx1);
    __global double(*ci[2])[256];
    ci[1] = (__global double(*)[256])( (__global char*)A_HDSDt1 + 1 * 256 * A_HDSStep);
    ci[0] = (__global double(*)[256])( (__global char*)A_HDSDt1 + 0 * 256 * A_HDSStep);
    A_HDSIdx2 = A_HDSShift + (col_q) *A_HDSStep;
    A_HDSDt2 = (__global double*)((__global char*)A_HDS + A_HDSIdx2);
    __global double(*cj[2])[256];
    cj[1] = (__global double(*)[256])( (__global char*)A_HDSDt2 + 1 * 256 * A_HDSStep);
    cj[0] = (__global double(*)[256])( (__global char*)A_HDSDt2 + 0 * 256 * A_HDSStep);
         __local double ld1[256] ;
    __local double ld2[256] ;
    double ci0R  = (*ci[0])[lidx];
    double ci0I  = (*ci[1])[lidx];
    double cj0R  = (*cj[0])[lidx];
    double cj0I  = (*cj[1])[lidx];
         inner_product(ci0R, ci0I, cj0R, cj0I, ld1,ld2,lidx );
    __local double (*value[2]) ;
    value[0] = &ld1[0]; 
    value[1] = &ld2[0]; 
    double value_abs = sqrt( (value[0])[0] * (value[0])[0] + (value[1])[0] * (value[1])[0] );
    if (value_abs >= 1.0000000000000001E-5) {
      *pass = 0;
      double a = value[1][0], b = value[0][0];
      double s_a2b2 = sig(b) * sqrt(a * a + b * b);
      double sin_alpha = a / s_a2b2;
      double cos_alpha = b / s_a2b2;
      double m = -1 * (b * cos_alpha + a * sin_alpha);
      __local double ld1[256] ;
      double ci1R  = (*ci[0])[lidx];
      double ci1I  = (*ci[1])[lidx];
      double cj1R  = (*cj[0])[lidx];
      double cj1I  = (*cj[1])[lidx];
      double part_value = part_product(ci1R,ci1I,cj1R,cj1I,ld1,lidx );
      double n = 0.5 * part_value;
      double w = sig(n) * m / sqrt(m * m + n * n);
      double sin_x = w / sqrt(2 * (1 + sqrt(1 - w * w)));
      double cos_x = sqrt(1 - sin_x * sin_x);
      double mid_result[2];
      double mid_result1[2];
      double (*d[2]) = { &(__private double){0}, &(__private double){1}}; 
      mid_result[1] = (*ci[1])[lidx] * cos_x + (*cj[1])[lidx] * cos_alpha * sin_x - (d[0][0] * (*cj[1])[lidx] + d[1][0] * (*cj[0])[lidx]) * sin_alpha * sin_x;
      mid_result[0] = (*ci[0])[lidx] * cos_x + (*cj[0])[lidx] * cos_alpha * sin_x - (d[0][0] * (*cj[0])[lidx] - d[1][0] * (*cj[1])[lidx]) * sin_alpha * sin_x;
      mid_result1[1] = (*cj[1])[lidx] * cos_x - (*ci[1])[lidx] * cos_alpha * sin_x - (d[0][0] * (*ci[1])[lidx] + d[1][0] * (*ci[0])[lidx]) * sin_alpha * sin_x;
      mid_result1[0] = (*cj[0])[lidx] * cos_x - (*ci[0])[lidx] * cos_alpha * sin_x - (d[0][0] * (*ci[0])[lidx] - d[1][0] * (*ci[1])[lidx]) * sin_alpha * sin_x;
      A_HDSIdx1 = A_HDSShift + (col_p) *A_HDSStep;
      A_HDSDt1 = (__global double*)((__global char*)A_HDS + A_HDSIdx1);
      A_HDSDt1[lidx] = mid_result[0];
       ( (__global double*) ((__global char*) A_HDSDt1 + A_HDSHeight * A_HDSStep))[lidx] = mid_result[1];
            A_HDSIdx2 = A_HDSShift + (col_q) *A_HDSStep;
      A_HDSDt2 = (__global double*)((__global char*)A_HDS + A_HDSIdx2);
      A_HDSDt2[lidx] = mid_result1[0];
       ( (__global double*) ((__global char*) A_HDSDt2 + A_HDSHeight * A_HDSStep))[lidx] = mid_result1[1];
            V_HDSIdx3 = V_HDSShift + (col_p) *V_HDSStep;
      V_HDSDt3 = (__global double*)((__global char*)V_HDS + V_HDSIdx3);
      __global double(*vi[2])[256];
      vi[1] = (__global double(*)[256])( (__global char*)V_HDSDt3 + 1 * 256 * V_HDSStep);
      vi[0] = (__global double(*)[256])( (__global char*)V_HDSDt3 + 0 * 256 * V_HDSStep);
      V_HDSIdx4 = V_HDSShift + (col_q) *V_HDSStep;
      V_HDSDt4 = (__global double*)((__global char*)V_HDS + V_HDSIdx4);
      __global double(*vj[2])[256];
      vj[1] = (__global double(*)[256])( (__global char*)V_HDSDt4 + 1 * 256 * V_HDSStep);
      vj[0] = (__global double(*)[256])( (__global char*)V_HDSDt4 + 0 * 256 * V_HDSStep);
      mid_result[1] = (*vi[1])[lidx] * cos_x + (*vj[1])[lidx] * cos_alpha * sin_x - (d[0][0] * (*vj[1])[lidx] + d[1][0] * (*vj[0])[lidx]) * sin_alpha * sin_x;
      mid_result[0] = (*vi[0])[lidx] * cos_x + (*vj[0])[lidx] * cos_alpha * sin_x - (d[0][0] * (*vj[0])[lidx] - d[1][0] * (*vj[1])[lidx]) * sin_alpha * sin_x;
      mid_result1[1] = (*vj[1])[lidx] * cos_x - (*vi[1])[lidx] * cos_alpha * sin_x - (d[0][0] * (*vi[1])[lidx] + d[1][0] * (*vi[0])[lidx]) * sin_alpha * sin_x;
      mid_result1[0] = (*vj[0])[lidx] * cos_x - (*vi[0])[lidx] * cos_alpha * sin_x - (d[0][0] * (*vi[0])[lidx] - d[1][0] * (*vi[1])[lidx]) * sin_alpha * sin_x;
      V_HDSIdx3 = V_HDSShift + (col_p) *V_HDSStep;
      V_HDSDt3 = (__global double*)((__global char*)V_HDS + V_HDSIdx3);
      V_HDSDt3[lidx] = mid_result[0];
       ( (__global double*) ((__global char*) V_HDSDt3 + V_HDSHeight * V_HDSStep))[lidx] = mid_result[1];
            V_HDSIdx4 = V_HDSShift + (col_q) *V_HDSStep;
      V_HDSDt4 = (__global double*)((__global char*)V_HDS + V_HDSIdx4);
      V_HDSDt4[lidx] = mid_result1[0];
       ( (__global double*) ((__global char*) V_HDSDt4 + V_HDSHeight * V_HDSStep))[lidx] = mid_result1[1];
          }
    *rotate_col_idxDSDt5 = col_q;
    *rotate_col_idxDSDt6 = col_p;
  }

}

/* kernel function */
__kernel void kernel_2(
  __global double *SDst,
  int SDstWidth,
  int SDstStep,
  int SDstShift,
  __global double *A_HDS,
  int A_HDSWidth,
  int A_HDSHeight,
  int A_HDSStep,
  int A_HDSShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);
  const int lidx = get_local_id(0);
  const int lidy = get_local_id(1);
  const int gridx = get_group_id(0);
  const int gridy = get_group_id(1);

  /* kernel boundary check */
  if ( gridy >= 1 )
    return;

  /* kernel index calculation */
  int SDstIdx1 = SDstShift + (int)(((float)gridx) *sizeof(double));
  int A_HDSIdx1 = A_HDSShift + (int)(((float)gridx) *A_HDSStep);

  /* kernel operands */
  __global double *SDstDt1 = (__global double*) ((__global char *)SDst + SDstIdx1);
  __global double *A_HDSDt1 = (__global double*) ((__global char *)A_HDS + A_HDSIdx1);

  /* kernel operation */
  {
    __global double(*ci[2])[256];
    ci[1] = (__global double(*)[256])( (__global char*)A_HDSDt1 + 1 * 256 * A_HDSStep);
    ci[0] = (__global double(*)[256])( (__global char*)A_HDSDt1 + 0 * 256 * A_HDSStep);
        __local double TempVar1Ld1[256] ;
    __local double TempVar1Ld2[256] ;
    double TempVar1R = (*ci[0])[lidx];
    double TempVar1I = (*ci[1])[lidx];
    double STempVar1R = (*ci[0])[lidx];
    double STempVar1I = (*ci[1])[lidx];
         inner_product(TempVar1R, TempVar1I, STempVar1R, STempVar1I, TempVar1Ld1, TempVar1Ld2, lidx);
;
    double norm_A = sqrt(sqrt( TempVar1Ld1[0] * TempVar1Ld1[0] + TempVar1Ld2[0] * TempVar1Ld2[0] ));
    *SDstDt1 = norm_A;
    (*ci[1])[lidx] = (*ci[1])[lidx] / norm_A;
    (*ci[0])[lidx] = (*ci[0])[lidx] / norm_A;
  }

}

