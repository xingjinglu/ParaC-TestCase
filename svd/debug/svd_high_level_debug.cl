/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

/* kernel function */
__kernel void kernel_1(
  int start_index,
  int i,
  int pass,
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
  if (gidx >= (256 - start_index )/ 2 || gidy >= 1)
   return;

  /* kernel index calculation */
  // TODO gidx-->gridx, gridy.
  int rotate_col_idxDSIdx5 = rotate_col_idxDSShift + ((float)gidx * 2 + start_index) *rotate_col_idxDSStep;
  int rotate_col_idxDSIdx6 = rotate_col_idxDSShift + ((float)gidx * 2 + 1 + start_index) *rotate_col_idxDSStep;

  /* kernel operands */
 __global int *rotate_col_idxDSDt5 = (__global char *)rotate_col_idxDS + rotate_col_idxDSIdx5;
  __global int *rotate_col_idxDSDt6 = (__global char *)rotate_col_idxDS + rotate_col_idxDSIdx6;

  /* kernel operation */
  {
    if (i == 0 && gidy == 0)
      pass = 1;
    // TODO. change rotate_co_idx[gridy] -->
    //int col_p = rotate_col_idx[gridy];
    //int col_q = rotate_col_idx[gridy + 1];
    int col_p = rotate_col_idxDSDt5;
    int col_q = rotate_col_idxDSDt6;

  // Todo. To be moved here.
    int A_HDSIdx1 = A_HDSShift + (col_p + start_index) *A_HDSStep;
    int A_HDSIdx2 = A_HDSShift + (col_q + start_index) *A_HDSStep;
    int V_HDSIdx3 = V_HDSShift + (col_p + start_index) *V_HDSStep;
    int V_HDSIdx4 = V_HDSShift + (col_q + start_index) *V_HDSStep;

    __global double *A_HDSDt1 = (__global char *)A_HDS + A_HDSIdx1;
    __global double *A_HDSDt2 = (__global char *)A_HDS + A_HDSIdx2;
    __global double *V_HDSDt3 = (__global char *)V_HDS + V_HDSIdx3;
    __global double *V_HDSDt4 = (__global char *)V_HDS + V_HDSIdx4;

    double (*ci[2])[256];
    ci[1] = &A_HDS[1][col_p];
    ci[0] = &A_HDS[0][col_p];
    double (*cj[2])[256];
    cj[1] = &A_HDS[1][col_q];
    cj[0] = &A_HDS[0][col_q];
    __local double ld1[256] ;
    __local double ld2[256] ;
    double ci0R  = (*ci)[0][lidx];
    double ci0I  = (*ci)[1][lidx];
    double cj0R  = (*cj)[0][lidx];
    double cj0I  = (*cj)[1][lidx];
    double (*value)[2] = (double(*)[2])inner_product(ci0R,ci0I,cj0R,cj0I,ld1,ld2,lidx );
    double value_abs = sqrt( (*value)[0] * (*value)[0] + (*value)[1] * (*value)[1] );
    if (value_abs >= 1.0000000000000001E-5) {
      pass = 0;
      double a = (*value)[1], b = (*value)[0];
      double s_a2b2 = sign(b) * sqrt(a * a + b * b);
      double sin_alpha = a / s_a2b2;
      double cos_alpha = b / s_a2b2;
      double m = -1 * (b * cos_alpha + a * sin_alpha);
      __local double ld1[256] ;
      double ci1R  = (*ci)[0][lidx];
      double ci1I  = (*ci)[1][lidx];
      double cj1R  = (*cj)[0][lidx];
      double cj1I  = (*cj)[1][lidx];
      double part_value = part_product(ci1R,ci1I,cj1R,cj1I,ld1,lidx );
      double n = 0.5 * part_value;
      double w = sign(n) * m / sqrt(m * m + n * n);
      double sin_x = w / sqrt(2 * (1 + sqrt(1 - w * w)));
      double cos_x = sqrt(1 - sin_x * sin_x);
      double mid_result[2][256];
      double mid_result1[2][256];
      mid_result[1][lidx] = ci[1][lidx] * cos_x + cj[1][lidx] * cos_alpha * sin_x - i * cj[1][lidx] * sin_alpha * sin_x;
      mid_result[0][lidx] = ci[0][lidx] * cos_x + cj[0][lidx] * cos_alpha * sin_x - i * cj[0][lidx] * sin_alpha * sin_x;
      mid_result1[1][lidx] = cj[1][lidx] * cos_x - ci[1][lidx] * cos_alpha * sin_x - i * ci[1][lidx] * sin_alpha * sin_x;
      mid_result1[0][lidx] = cj[0][lidx] * cos_x - ci[0][lidx] * cos_alpha * sin_x - i * ci[0][lidx] * sin_alpha * sin_x;
                              double (*vi[2])[256];
      vi[1] = &V_HDS[1][col_p];
      vi[0] = &V_HDS[0][col_p];
      double (*vj[2])[256];
      vj[1] = &V_HDS[1][col_q];
      vj[0] = &V_HDS[0][col_q];
      mid_result[1][lidx] = vi[1][lidx] * cos_x + vj[1][lidx] * cos_alpha * sin_x - i * vj[1][lidx] * sin_alpha * sin_x;
      mid_result[0][lidx] = vi[0][lidx] * cos_x + vj[0][lidx] * cos_alpha * sin_x - i * vj[0][lidx] * sin_alpha * sin_x;
      mid_result1[1][lidx] = vj[1][lidx] * cos_x - vi[1][lidx] * cos_alpha * sin_x - i * vi[1][lidx] * sin_alpha * sin_x;
      mid_result1[0][lidx] = vj[0][lidx] * cos_x - vi[0][lidx] * cos_alpha * sin_x - i * vi[0][lidx] * sin_alpha * sin_x;
                            }
    rotate_col_idx[gidy] = col_q;
    rotate_col_idx[gidy + 1] = col_p;
  }

}

/* kernel function */
__kernel void kernel_2(
  __global double* const A_HSrc,
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
  if (gidx >= 256 || gidy >= 1)
   return;

  /* kernel index calculation */
  int A_HSrcIdx1 = A_HSrcShift + ((float)gidx) *A_HSrcStep;

  /* kernel operands */
  __global double *A_HSrcDt1 = (__global char *)A_HSrc + A_HSrcIdx1;

  /* kernel operation */
  {
    double (*ci[2])[256] = A_H[gridy][*];
    ci[1] = &A_HSrc[1][it2x];
    ci[0] = &A_HSrc[0][it2x];
        __local double TempVal1ld1[256] ;
    __local double TempVal1ld2[256] ;
    double TempVal1R  = (*ci)[0][lidx];
    double TempVal1I  = (*ci)[1][lidx];
    double STempVal1R  = (*ci)[0][lidx];
    double STempVal1I  = (*ci)[1][lidx];
        double (*TempVal1)[2] = (double(*)[2])inner_product(TempVal1R, TempVal1I, STempVal1R, STempVal1I, TempVal1ld1, TempVal1ld2, lidx);
    double norm_A = sqrt(sqrt( (*TempVal1)[0] * (*TempVal1)[0] + (*TempVal1)[1] * (*TempVal1)[1] ));
    S[gidy] = norm_A;
    (ci[1][lidx]) = (ci[1][lidx]) / norm_A;
    (ci[0][lidx]) = (ci[0][lidx]) / norm_A;
  }

}

