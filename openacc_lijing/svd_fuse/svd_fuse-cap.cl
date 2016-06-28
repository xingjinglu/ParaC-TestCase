/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

#pragma OPENCL EXTENSION cl_khr_fp64: enable

/* kernel function */
__kernel void kernel_1(
  __global int * pass,
  __global double * A_H,
  __global double * V_H,
  __global int * rotate_col_idx,
  __global double * ci,
  __global double * cj,
  __global double * vi,
  __global double * vj,
  __global double * value,
  int start_index,
  __local char * localBuffer)
{
  /* kernel thread ID */
  const int bszx = get_num_groups(0);
  const int bidx = get_group_id(0);
  const int tszx = get_local_size(0);
  const int tidx = get_local_id(0);
  const int tszy = get_local_size(1);
  const int tszz = get_local_size(2);
  const int tsz = tszx * tszy * tszz;
  const int tidy = get_local_id(1);
  const int tidz = get_local_id(2);
  const int tid = tidz * tszx * tszy + tidy * tszx + tidx;

  /* Local vars */
  double tmpreal16 = 0;
  __local double * localreal16 = ( __local double* )(localBuffer + (0 * tsz));
  double tmpimag16 = 0;
  __local double * localimag16 = ( __local double* )(localBuffer + (8 * tsz));
  double tmpresult111 = 0;
  __local double * localresult111 = ( __local double* )(localBuffer + (0 * tsz));
  double tmpresult211 = 0;
  __local double * localresult211 = ( __local double* )(localBuffer + (8 * tsz));
  double tmpresult311 = 0;
  __local double * localresult311 = ( __local double* )(localBuffer + (16 * tsz));
  double tmpresult411 = 0;
  __local double * localresult411 = ( __local double* )(localBuffer + (24 * tsz));
  double tmpresult515 = 0;
  __local double * localresult515 = ( __local double* )(localBuffer + (0 * tsz));
  double tmpresult615 = 0;
  __local double * localresult615 = ( __local double* )(localBuffer + (8 * tsz));
  double tmpresult715 = 0;
  __local double * localresult715 = ( __local double* )(localBuffer + (16 * tsz));
  double tmpresult815 = 0;
  __local double * localresult815 = ( __local double* )(localBuffer + (24 * tsz));

  /* kernel operation */
  {
    #pragma cap fuse loop(6,7,8,9,10) depth(1) 
      #pragma cap fuse loop(19,20,21,22) depth(1) 
        #pragma cap fuse loop(11,12,13,14) depth(1) 
          #pragma cap fuse loop(15,16,17,18) depth(1) 
            {
              #pragma cap map threadblock([0:5]) thread([0:6][0:7][0:8][0:9][0:10][0:11][0:12][0:13][0:14][0:15][0:16][0:17][0:18][0:19][0:20][0:21][0:22]) 
                #pragma cap loop id(5) 
                  for (int j = bidx; j < (256 - (start_index + 1) + 2 - 1) / (2); j += bszx) {
                    int col_p = rotate_col_idx[(j * (2) + start_index + 1) - 1];
                    int col_q = rotate_col_idx[(j * (2) + start_index + 1)];
                    double real1 = 0.F;
                    double imag1 = 0.F;
                    barrier(CLK_LOCAL_MEM_FENCE);
                    #pragma cap loop id(6) 
                      for (int k = tidx; k < 256; k += tszx) {
                        {
                          {
                            {
                              {
                                (ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] = A_H[col_p * 256 + k];
                                (ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[256 + k] = A_H[256 * 256 + col_p * 256 + k];
                              }
                              {
                                (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] = A_H[col_q * 256 + k];
                                (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[256 + k] = A_H[256 * 256 + col_q * 256 + k];
                              }
                            }
                            {
                              (vi + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] = V_H[col_p * 256 + k];
                              (vi + (j * (2) + start_index + 1) / 2 * 256 * 2)[256 + k] = V_H[256 * 256 + col_p * 256 + k];
                            }
                          }
                          {
                            (vj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] = V_H[col_q * 256 + k];
                            (vj + (j * (2) + start_index + 1) / 2 * 256 * 2)[256 + k] = V_H[256 * 256 + col_q * 256 + k];
                          }
                        }
                        {
                          tmpreal16 += (double)(ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] + (ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[256 + k] * (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[256 + k];
                          tmpimag16 += (double)(ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[256 + k] - (ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[256 + k] * (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k];
                        }
                      }
                                        localreal16[tid] = tmpreal16;
                    localimag16[tid] = tmpimag16;
                    barrier(CLK_LOCAL_MEM_FENCE);

                    if(tsz >= 1024)
                    {
                                        if(tid < 512)
                                        {
                                                            localreal16[tid] = localreal16[tid] + localreal16[tid + 512];
                                                            localimag16[tid] = localimag16[tid] + localimag16[tid + 512];
                                        }
                                        barrier(CLK_LOCAL_MEM_FENCE);
                    }

                    if(tsz >= 512)
                    {
                                        if(tid < 256)
                                        {
                                                            localreal16[tid] = localreal16[tid] + localreal16[tid + 256];
                                                            localimag16[tid] = localimag16[tid] + localimag16[tid + 256];
                                        }
                                        barrier(CLK_LOCAL_MEM_FENCE);
                    }

                    if(tsz >= 256)
                    {
                                        if(tid < 128)
                                        {
                                                            localreal16[tid] = localreal16[tid] + localreal16[tid + 128];
                                                            localimag16[tid] = localimag16[tid] + localimag16[tid + 128];
                                        }
                                        barrier(CLK_LOCAL_MEM_FENCE);
                    }

                    if(tsz >= 128)
                    {
                                        if(tid < 64)
                                        {
                                                            localreal16[tid] = localreal16[tid] + localreal16[tid + 64];
                                                            localimag16[tid] = localimag16[tid] + localimag16[tid + 64];
                                        }
                                        barrier(CLK_LOCAL_MEM_FENCE);
                    }

                    if(tid < 32)
                    {
                                        if(tsz >= 64)
                                        {
                                                            localreal16[tid] = localreal16[tid] + localreal16[tid + 32];
                                                            localimag16[tid] = localimag16[tid] + localimag16[tid + 32];
                                        }
                                        if(tsz >= 32)
                                        {
                                                            localreal16[tid] = localreal16[tid] + localreal16[tid + 16];
                                                            localimag16[tid] = localimag16[tid] + localimag16[tid + 16];
                                        }
                                        if(tsz >= 16)
                                        {
                                                            localreal16[tid] = localreal16[tid] + localreal16[tid + 8];
                                                            localimag16[tid] = localimag16[tid] + localimag16[tid + 8];
                                        }
                                        if(tsz >= 8)
                                        {
                                                            localreal16[tid] = localreal16[tid] + localreal16[tid + 4];
                                                            localimag16[tid] = localimag16[tid] + localimag16[tid + 4];
                                        }
                                        if(tsz >= 4)
                                        {
                                                            localreal16[tid] = localreal16[tid] + localreal16[tid + 2];
                                                            localimag16[tid] = localimag16[tid] + localimag16[tid + 2];
                                        }
                                        if(tsz >= 2)
                                        {
                                                            localreal16[tid] = localreal16[tid] + localreal16[tid + 1];
                                                            localimag16[tid] = localimag16[tid] + localimag16[tid + 1];
                                        }
                    }
                    barrier(CLK_LOCAL_MEM_FENCE);

                    real1 = real1 + localreal16[0];
                    imag1 = imag1 + localimag16[0];                    barrier(CLK_LOCAL_MEM_FENCE);
                    ;
                    ;
                    ;
                    int skip_trans = 0;
                    ;
                    value[(j * (2) + start_index + 1) / 2] = (double)sqrt((double)real1 * (double)real1 + (double)imag1 * (double)imag1);
                    if (value[(j * (2) + start_index + 1) / 2] < 1.0000000000000001E-5)
                      skip_trans = 1;
                    if (skip_trans == 0) {
                      pass[0] = 0;
                      double result1 = 0.F;
                      double result2 = 0.F;
                      double result3 = 0.F;
                      double result4 = 0.F;
                      double result5 = 0.F;
                      double result6 = 0.F;
                      double result7 = 0.F;
                      double result8 = 0.F;
                      barrier(CLK_LOCAL_MEM_FENCE);
                      #pragma cap loop id(11) reduction(+: result1) 
                        for (int k = tidx; k < 256; k += tszx) {
                          {
                            {
                              tmpresult111 += (double)(ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256];
                              tmpresult211 += (double)(ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k];
                            }
                            tmpresult311 += (double)(ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k];
                          }
                          tmpresult411 += (double)(ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256];
                        }
                                            localresult111[tid] = tmpresult111;
                      localresult211[tid] = tmpresult211;
                      localresult311[tid] = tmpresult311;
                      localresult411[tid] = tmpresult411;
                      barrier(CLK_LOCAL_MEM_FENCE);

                      if(tsz >= 1024)
                      {
                                            if(tid < 512)
                                            {
                                                                  localresult111[tid] = localresult111[tid] + localresult111[tid + 512];
                                                                  localresult211[tid] = localresult211[tid] + localresult211[tid + 512];
                                                                  localresult311[tid] = localresult311[tid] + localresult311[tid + 512];
                                                                  localresult411[tid] = localresult411[tid] + localresult411[tid + 512];
                                            }
                                            barrier(CLK_LOCAL_MEM_FENCE);
                      }

                      if(tsz >= 512)
                      {
                                            if(tid < 256)
                                            {
                                                                  localresult111[tid] = localresult111[tid] + localresult111[tid + 256];
                                                                  localresult211[tid] = localresult211[tid] + localresult211[tid + 256];
                                                                  localresult311[tid] = localresult311[tid] + localresult311[tid + 256];
                                                                  localresult411[tid] = localresult411[tid] + localresult411[tid + 256];
                                            }
                                            barrier(CLK_LOCAL_MEM_FENCE);
                      }

                      if(tsz >= 256)
                      {
                                            if(tid < 128)
                                            {
                                                                  localresult111[tid] = localresult111[tid] + localresult111[tid + 128];
                                                                  localresult211[tid] = localresult211[tid] + localresult211[tid + 128];
                                                                  localresult311[tid] = localresult311[tid] + localresult311[tid + 128];
                                                                  localresult411[tid] = localresult411[tid] + localresult411[tid + 128];
                                            }
                                            barrier(CLK_LOCAL_MEM_FENCE);
                      }

                      if(tsz >= 128)
                      {
                                            if(tid < 64)
                                            {
                                                                  localresult111[tid] = localresult111[tid] + localresult111[tid + 64];
                                                                  localresult211[tid] = localresult211[tid] + localresult211[tid + 64];
                                                                  localresult311[tid] = localresult311[tid] + localresult311[tid + 64];
                                                                  localresult411[tid] = localresult411[tid] + localresult411[tid + 64];
                                            }
                                            barrier(CLK_LOCAL_MEM_FENCE);
                      }

                      if(tid < 32)
                      {
                                            if(tsz >= 64)
                                            {
                                                                  localresult111[tid] = localresult111[tid] + localresult111[tid + 32];
                                                                  localresult211[tid] = localresult211[tid] + localresult211[tid + 32];
                                                                  localresult311[tid] = localresult311[tid] + localresult311[tid + 32];
                                                                  localresult411[tid] = localresult411[tid] + localresult411[tid + 32];
                                            }
                                            if(tsz >= 32)
                                            {
                                                                  localresult111[tid] = localresult111[tid] + localresult111[tid + 16];
                                                                  localresult211[tid] = localresult211[tid] + localresult211[tid + 16];
                                                                  localresult311[tid] = localresult311[tid] + localresult311[tid + 16];
                                                                  localresult411[tid] = localresult411[tid] + localresult411[tid + 16];
                                            }
                                            if(tsz >= 16)
                                            {
                                                                  localresult111[tid] = localresult111[tid] + localresult111[tid + 8];
                                                                  localresult211[tid] = localresult211[tid] + localresult211[tid + 8];
                                                                  localresult311[tid] = localresult311[tid] + localresult311[tid + 8];
                                                                  localresult411[tid] = localresult411[tid] + localresult411[tid + 8];
                                            }
                                            if(tsz >= 8)
                                            {
                                                                  localresult111[tid] = localresult111[tid] + localresult111[tid + 4];
                                                                  localresult211[tid] = localresult211[tid] + localresult211[tid + 4];
                                                                  localresult311[tid] = localresult311[tid] + localresult311[tid + 4];
                                                                  localresult411[tid] = localresult411[tid] + localresult411[tid + 4];
                                            }
                                            if(tsz >= 4)
                                            {
                                                                  localresult111[tid] = localresult111[tid] + localresult111[tid + 2];
                                                                  localresult211[tid] = localresult211[tid] + localresult211[tid + 2];
                                                                  localresult311[tid] = localresult311[tid] + localresult311[tid + 2];
                                                                  localresult411[tid] = localresult411[tid] + localresult411[tid + 2];
                                            }
                                            if(tsz >= 2)
                                            {
                                                                  localresult111[tid] = localresult111[tid] + localresult111[tid + 1];
                                                                  localresult211[tid] = localresult211[tid] + localresult211[tid + 1];
                                                                  localresult311[tid] = localresult311[tid] + localresult311[tid + 1];
                                                                  localresult411[tid] = localresult411[tid] + localresult411[tid + 1];
                                            }
                      }
                      barrier(CLK_LOCAL_MEM_FENCE);

                      result1 = result1 + localresult111[0];
                      result2 = result2 + localresult211[0];
                      result3 = result3 + localresult311[0];
                      result4 = result4 + localresult411[0];                      barrier(CLK_LOCAL_MEM_FENCE);
                      double inner_ri = result1;
                      ;
                      double inner_ir = result2;
                      ;
                      double inner_rr = result3;
                      ;
                      double inner_ii = result4;
                      double a = (double)inner_ri - (double)inner_ir;
                      double b = (double)inner_rr + (double)inner_ii;
                      double s_a2b2 = (double)sign(b) * sqrt(a * a + b * b);
                      double sin_alpha = a / s_a2b2;
                      double cos_alpha = b / s_a2b2;
                      double m = -1 * (b * cos_alpha + a * sin_alpha);
                      barrier(CLK_LOCAL_MEM_FENCE);
                      #pragma cap loop id(15) reduction(+: result5) 
                        for (int k = tidx; k < 256; k += tszx) {
                          {
                            {
                              tmpresult515 += (double)(cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k];
                              tmpresult615 += (double)(cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256];
                            }
                            tmpresult715 += (double)(ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * (ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k];
                          }
                          tmpresult815 += (double)(ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * (ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256];
                        }
                                            localresult515[tid] = tmpresult515;
                      localresult615[tid] = tmpresult615;
                      localresult715[tid] = tmpresult715;
                      localresult815[tid] = tmpresult815;
                      barrier(CLK_LOCAL_MEM_FENCE);

                      if(tsz >= 1024)
                      {
                                            if(tid < 512)
                                            {
                                                                  localresult515[tid] = localresult515[tid] + localresult515[tid + 512];
                                                                  localresult615[tid] = localresult615[tid] + localresult615[tid + 512];
                                                                  localresult715[tid] = localresult715[tid] + localresult715[tid + 512];
                                                                  localresult815[tid] = localresult815[tid] + localresult815[tid + 512];
                                            }
                                            barrier(CLK_LOCAL_MEM_FENCE);
                      }

                      if(tsz >= 512)
                      {
                                            if(tid < 256)
                                            {
                                                                  localresult515[tid] = localresult515[tid] + localresult515[tid + 256];
                                                                  localresult615[tid] = localresult615[tid] + localresult615[tid + 256];
                                                                  localresult715[tid] = localresult715[tid] + localresult715[tid + 256];
                                                                  localresult815[tid] = localresult815[tid] + localresult815[tid + 256];
                                            }
                                            barrier(CLK_LOCAL_MEM_FENCE);
                      }

                      if(tsz >= 256)
                      {
                                            if(tid < 128)
                                            {
                                                                  localresult515[tid] = localresult515[tid] + localresult515[tid + 128];
                                                                  localresult615[tid] = localresult615[tid] + localresult615[tid + 128];
                                                                  localresult715[tid] = localresult715[tid] + localresult715[tid + 128];
                                                                  localresult815[tid] = localresult815[tid] + localresult815[tid + 128];
                                            }
                                            barrier(CLK_LOCAL_MEM_FENCE);
                      }

                      if(tsz >= 128)
                      {
                                            if(tid < 64)
                                            {
                                                                  localresult515[tid] = localresult515[tid] + localresult515[tid + 64];
                                                                  localresult615[tid] = localresult615[tid] + localresult615[tid + 64];
                                                                  localresult715[tid] = localresult715[tid] + localresult715[tid + 64];
                                                                  localresult815[tid] = localresult815[tid] + localresult815[tid + 64];
                                            }
                                            barrier(CLK_LOCAL_MEM_FENCE);
                      }

                      if(tid < 32)
                      {
                                            if(tsz >= 64)
                                            {
                                                                  localresult515[tid] = localresult515[tid] + localresult515[tid + 32];
                                                                  localresult615[tid] = localresult615[tid] + localresult615[tid + 32];
                                                                  localresult715[tid] = localresult715[tid] + localresult715[tid + 32];
                                                                  localresult815[tid] = localresult815[tid] + localresult815[tid + 32];
                                            }
                                            if(tsz >= 32)
                                            {
                                                                  localresult515[tid] = localresult515[tid] + localresult515[tid + 16];
                                                                  localresult615[tid] = localresult615[tid] + localresult615[tid + 16];
                                                                  localresult715[tid] = localresult715[tid] + localresult715[tid + 16];
                                                                  localresult815[tid] = localresult815[tid] + localresult815[tid + 16];
                                            }
                                            if(tsz >= 16)
                                            {
                                                                  localresult515[tid] = localresult515[tid] + localresult515[tid + 8];
                                                                  localresult615[tid] = localresult615[tid] + localresult615[tid + 8];
                                                                  localresult715[tid] = localresult715[tid] + localresult715[tid + 8];
                                                                  localresult815[tid] = localresult815[tid] + localresult815[tid + 8];
                                            }
                                            if(tsz >= 8)
                                            {
                                                                  localresult515[tid] = localresult515[tid] + localresult515[tid + 4];
                                                                  localresult615[tid] = localresult615[tid] + localresult615[tid + 4];
                                                                  localresult715[tid] = localresult715[tid] + localresult715[tid + 4];
                                                                  localresult815[tid] = localresult815[tid] + localresult815[tid + 4];
                                            }
                                            if(tsz >= 4)
                                            {
                                                                  localresult515[tid] = localresult515[tid] + localresult515[tid + 2];
                                                                  localresult615[tid] = localresult615[tid] + localresult615[tid + 2];
                                                                  localresult715[tid] = localresult715[tid] + localresult715[tid + 2];
                                                                  localresult815[tid] = localresult815[tid] + localresult815[tid + 2];
                                            }
                                            if(tsz >= 2)
                                            {
                                                                  localresult515[tid] = localresult515[tid] + localresult515[tid + 1];
                                                                  localresult615[tid] = localresult615[tid] + localresult615[tid + 1];
                                                                  localresult715[tid] = localresult715[tid] + localresult715[tid + 1];
                                                                  localresult815[tid] = localresult815[tid] + localresult815[tid + 1];
                                            }
                      }
                      barrier(CLK_LOCAL_MEM_FENCE);

                      result5 = result5 + localresult515[0];
                      result6 = result6 + localresult615[0];
                      result7 = result7 + localresult715[0];
                      result8 = result8 + localresult815[0];                      barrier(CLK_LOCAL_MEM_FENCE);
                      double inner_rrj = result5;
                      ;
                      double inner_iij = result6;
                      ;
                      double inner_rri = result7;
                      ;
                      double inner_iii = result8;
                      double n = (double)0.5 * (inner_rrj + inner_iij - inner_rri - inner_iii);
                      double w = (double)sign(n) * m / sqrt(m * m + n * n);
                      double sin_x = w / sqrt(2 * (1 + sqrt(1 - w * w)));
                      double cos_x = sqrt(1 - sin_x * sin_x);
                      double real2 = 0.F;
                      double imag2 = 0.F;
                      double real3 = 0.F;
                      double imag3 = 0.F;
                      double real4 = 0.F;
                      double imag4 = 0.F;
                      double real5 = 0.F;
                      double imag5 = 0.F;
                      barrier(CLK_LOCAL_MEM_FENCE);
                      #pragma cap loop id(19) 
                        for (int k = tidx; k < 256; k += tszx) {
                          {
                            {
                              {
                                real2 = (ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * cos_x + 1 * (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * cos_alpha * sin_x + (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * sin_alpha * sin_x;
                                imag2 = (ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * cos_x + 1 * (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * cos_alpha * sin_x - (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * sin_alpha * sin_x;
                                A_H[col_p * 256 + k] = real2;
                                A_H[256 * 256 + col_p * 256 + k] = imag2;
                              }
                              {
                                real3 = (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * cos_x + (-1) * (ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * cos_alpha * sin_x + (ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * sin_alpha * sin_x;
                                imag3 = (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * cos_x + (-1) * (ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * cos_alpha * sin_x - (ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * sin_alpha * sin_x;
                                A_H[col_q * 256 + k] = real3;
                                A_H[256 * 256 + col_q * 256 + k] = imag3;
                              }
                            }
                            {
                              real4 = (vi + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * cos_x + 1 * (vj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * cos_alpha * sin_x + (vj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * sin_alpha * sin_x;
                              imag4 = (vi + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * cos_x + 1 * (vj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * cos_alpha * sin_x - (vj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * sin_alpha * sin_x;
                              V_H[col_p * 256 + k] = real4;
                              V_H[256 * 256 + col_p * 256 + k] = imag4;
                            }
                          }
                          {
                            real5 = (vj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * cos_x + (-1) * (vi + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * cos_alpha * sin_x + (vi + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * sin_alpha * sin_x;
                            imag5 = (vj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * cos_x + (-1) * (vi + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * cos_alpha * sin_x - (vi + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * sin_alpha * sin_x;
                            V_H[col_q * 256 + k] = real5;
                            V_H[256 * 256 + col_q * 256 + k] = imag5;
                          }
                        }
                      barrier(CLK_LOCAL_MEM_FENCE);
                      ;
                      ;
                      ;
                    }
                    rotate_col_idx[(j * (2) + start_index + 1) - 1] = col_q;
                    rotate_col_idx[(j * (2) + start_index + 1)] = col_p;
                  }
            }
  }

}

/* kernel function */
__kernel void kernel_2(
  __global double * S_H,
  __global double * const A_H,
  __global double * ci,
  __local char * localBuffer)
{
  /* kernel thread ID */
  const int bszx = get_num_groups(0);
  const int bidx = get_group_id(0);
  const int tszx = get_local_size(0);
  const int tidx = get_local_id(0);
  const int tszy = get_local_size(1);
  const int tszz = get_local_size(2);
  const int tsz = tszx * tszy * tszz;
  const int tidy = get_local_id(1);
  const int tidz = get_local_id(2);
  const int tid = tidz * tszx * tszy + tidy * tszx + tidx;

  /* Local vars */
  double tmpreal3 = 0;
  __local double * localreal3 = ( __local double* )(localBuffer + (0 * tsz));
  double tmpimag3 = 0;
  __local double * localimag3 = ( __local double* )(localBuffer + (8 * tsz));

  /* kernel operation */
  {
    #pragma cap fuse loop(3,4) depth(1) 
      {
        #pragma cap map threadblock([0:2]) thread([0:3][0:4]) 
          #pragma cap loop id(2) 
            for (int i = bidx; i < 256; i += bszx) {
              double real = 0.F;
              double imag = 0.F;
              barrier(CLK_LOCAL_MEM_FENCE);
              #pragma cap loop id(3) 
                for (int k = tidx; k < 256; k += tszx) {
                  {
                    (ci + i * 256 * 2)[k] = A_H[i * 256 + k];
                    (ci + i * 256 * 2)[256 + k] = A_H[256 * 256 + i * 256 + k];
                  }
                  {
                    tmpreal3 += (double)(ci + i * 256 * 2)[k] * (ci + i * 256 * 2)[k] + (ci + i * 256 * 2)[256 + k] * (ci + i * 256 * 2)[256 + k];
                    tmpimag3 += (double)(ci + i * 256 * 2)[k] * (ci + i * 256 * 2)[256 + k] - (ci + i * 256 * 2)[256 + k] * (ci + i * 256 * 2)[k];
                  }
                }
                            localreal3[tid] = tmpreal3;
              localimag3[tid] = tmpimag3;
              barrier(CLK_LOCAL_MEM_FENCE);

              if(tsz >= 1024)
              {
                            if(tid < 512)
                            {
                                          localreal3[tid] = localreal3[tid] + localreal3[tid + 512];
                                          localimag3[tid] = localimag3[tid] + localimag3[tid + 512];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 512)
              {
                            if(tid < 256)
                            {
                                          localreal3[tid] = localreal3[tid] + localreal3[tid + 256];
                                          localimag3[tid] = localimag3[tid] + localimag3[tid + 256];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 256)
              {
                            if(tid < 128)
                            {
                                          localreal3[tid] = localreal3[tid] + localreal3[tid + 128];
                                          localimag3[tid] = localimag3[tid] + localimag3[tid + 128];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 128)
              {
                            if(tid < 64)
                            {
                                          localreal3[tid] = localreal3[tid] + localreal3[tid + 64];
                                          localimag3[tid] = localimag3[tid] + localimag3[tid + 64];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tid < 32)
              {
                            if(tsz >= 64)
                            {
                                          localreal3[tid] = localreal3[tid] + localreal3[tid + 32];
                                          localimag3[tid] = localimag3[tid] + localimag3[tid + 32];
                            }
                            if(tsz >= 32)
                            {
                                          localreal3[tid] = localreal3[tid] + localreal3[tid + 16];
                                          localimag3[tid] = localimag3[tid] + localimag3[tid + 16];
                            }
                            if(tsz >= 16)
                            {
                                          localreal3[tid] = localreal3[tid] + localreal3[tid + 8];
                                          localimag3[tid] = localimag3[tid] + localimag3[tid + 8];
                            }
                            if(tsz >= 8)
                            {
                                          localreal3[tid] = localreal3[tid] + localreal3[tid + 4];
                                          localimag3[tid] = localimag3[tid] + localimag3[tid + 4];
                            }
                            if(tsz >= 4)
                            {
                                          localreal3[tid] = localreal3[tid] + localreal3[tid + 2];
                                          localimag3[tid] = localimag3[tid] + localimag3[tid + 2];
                            }
                            if(tsz >= 2)
                            {
                                          localreal3[tid] = localreal3[tid] + localreal3[tid + 1];
                                          localimag3[tid] = localimag3[tid] + localimag3[tid + 1];
                            }
              }
              barrier(CLK_LOCAL_MEM_FENCE);

              real = real + localreal3[0];
              imag = imag + localimag3[0];              barrier(CLK_LOCAL_MEM_FENCE);
              ;
              double norm_A = sqrt((double)sqrt((double)real * (double)real + (double)imag * (double)imag));
              S_H[i] = norm_A;
            }
      }
  }

}

/* kernel function */
__kernel void kernel_3(
  __global double * B_H,
  __global double * const A_H,
  __global double * const S_H)
{
  /* kernel thread ID */
  const int tszy = get_local_size(1);
  const int tidy = get_local_id(1);
  const int bszy = get_num_groups(1);
  const int bidy = get_group_id(1);
  const int tszx = get_local_size(0);
  const int tidx = get_local_id(0);
  const int bszx = get_num_groups(0);
  const int bidx = get_group_id(0);

  /* Local vars */

  /* kernel operation */
    {
      #pragma cap map threadblock([0:1][1:0]) thread([0:1][1:0]) 
        #pragma cap loop id(0) 
          for (int j = tszy * bidy + ( tidy ) ; j < 256; j += tszy * bszy) 
            #pragma cap loop id(1) 
              for (int i = tszx * bidx + ( tidx ) ; i < 256; i += tszx * bszx) {
                B_H[j * 256 + i] = A_H[j * 256 + i] / S_H[j];
                B_H[256 * 256 + j * 256 + i] = A_H[256 * 256 + j * 256 + i] / S_H[j];
              }
    }

}

