/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/
#include"stdlib.h"
/* kernel function */
__kernel void kernel_1(
  int i,
  int pass,
  __global  double *A_HDS,
  int A_HDSWidth,
  int A_HDSHeight,
  int A_HDSStep,
  int A_HDSShift,
  __global  double *V_HDS,
  int V_HDSWidth,
  int V_HDSHeight,
  int V_HDSStep,
  int V_HDSShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);
  const int lidx = get_local_id(0);
  const int lidy = get_local_id(1);
  const int gridx = get_group_id(0);
  const int gridy = get_group_id(1);

  /* kernel boundary check */
  if (gidx >= 1 || gidy >= (256 - start_index )/ 2)
   return;

  /* kernel index calculation */

  /* kernel operands */
  __global  double *A_HDSDt1 = (__global char *)A_HDS + A_HDSShift;
  __global  double *V_HDSDt2 = (__global char *)V_HDS + V_HDSShift;

  /* kernel operation */
  {
    if (i == 0 && gidy == 0)
      pass = 1;
    int col_p = rotate_col_idx[itx];
    int col_q = rotate_col_idx[itx + 1];
    double (*ci[2])[256];
    ci[0] = &A_H[0][col_p];
    ci[1] = &A_H[1][col_p];
    double (*cj[2])[256];
    cj[0] = &A_H[0][col_q];
    cj[1] = &A_H[1][col_q];
    double (*Goal)[2] = &(double (*)[2]){0, 1.2};
    double (*Aim)[2] = (double (*)[2])malloc( sizeof(double) * 2 );
    __local double *ld1 ;
    __local double *ld2 ;
    double ci0R  = (*ci[0])[lidx];
    double ci0I  = ci[1][lidx];
    double cj0R  = cj[0][lidx];
    double cj0I  = cj[1][lidx];
    double (*value)[2] = (double(*)[2])inner_product(ci0R,ci0I,cj0R,cj0I,&ld1,&ld2,lidx );
;
    double value_abs = sqrt( (*value)[0] * (*value)[0] + (*value)[1] * (*value)[1] );
;
    if (value_abs >= 1.0000000000000001E-5) {
      pass = 0;
      double a = (*value)[1], b = (*value)[0];
      double s_a2b2 = sign(b) * sqrt(a * a + b * b);
      double sin_alpha = a / s_a2b2;
      double cos_alpha = b / s_a2b2;
      double m = -1 * (b * cos_alpha + a * sin_alpha);
      __local double *ld1 ;
      double ci1R  = ci[0][lidx];
      double ci1I  = ci[1][lidx];
      double cj1R  = cj[0][lidx];
      double cj1I  = cj[1][lidx];
      double part_value = part_product(ci1R,ci1I,cj1R,cj1I,&ld1,&ld2,lidx );
;
      double n = 0.5 * part_value;
      double w = sign(n) * m / sqrt(m * m + n * n);
      double sin_x = w / sqrt(2 * (1 + sqrt(1 - w * w)));
      double cos_x = sqrt(1 - sin_x * sin_x);
      double mid_result[2][256];
      double mid_result1[2][256];
      mid_result = ci * cos_x + cj * cos_alpha * sin_x - i * cj * sin_alpha * sin_x;
      mid_result1 = cj * cos_x - ci * cos_alpha * sin_x - i * ci * sin_alpha * sin_x;
                              double (*vi[2])[256];
      vi[0] = &V_H[0][col_p];
      vi[1] = &V_H[1][col_p];
      double (*vj[2])[256];
      vj[0] = &V_H[0][col_q];
      vj[1] = &V_H[1][col_q];
      mid_result = vi * cos_x + vj * cos_alpha * sin_x - i * vj * sin_alpha * sin_x;
      mid_result1 = vj * cos_x - vi * cos_alpha * sin_x - i * vi * sin_alpha * sin_x;
                            }
    rotate_col_idx[itx] = col_q;
    rotate_col_idx[itx + 1] = col_p;
  }

}

/* kernel function */
__kernel void kernel_2(
  __global  double* const A_HSrc,
  int A_HSrcWidth,
  int A_HSrcHeight,
  int A_HSrcStep,
  int A_HSrcShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);
  const int lidx = get_local_id(0);
  const int lidy = get_local_id(1);
  const int gridx = get_group_id(0);
  const int gridy = get_group_id(1);

  /* kernel boundary check */
  if (gidx >= 1 || gidy >= 256)
   return;

  /* kernel index calculation */

  /* kernel operands */
  __global  double *A_HSrcDt1 = (__global char *)A_HSrc + A_HSrcShift;

  /* kernel operation */
  {
    double (*ci[2])[256];
    ci[0] = &A_H[0][it2x];
    ci[1] = &A_H[1][it2x];
        __local double *TempVal1ld1 ;
    __local double *TempVal1ld2 ;
    double TempVal1R  = ci[0][lidx];
    double TempVal1I  = ci[1][lidx];
    double STempVal1R  = ci[0][lidx];
    double STempVal1I  = ci[1][lidx];
        double (*TempVal1)[2] = (double(*)[2])inner_product(TempVal1IIR, TempVal1III, TempVal1IJR, TempVal1IJI, &TempVal1ld1, &TempVal1ld2, TempVal1lidx);
    double norm_A = sqrt(sqrt( (*TempVal1)[0] * (*TempVal1)[0] + (*TempVal1)[1] * (*TempVal1)[1] );
);
    S[it2x] = norm_A;
    (ci) = (ci) / norm_A;
  }

}

