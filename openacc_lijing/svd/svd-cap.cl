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
  double tmpreal110 = 0;
  __local double * localreal110 = ( __local double* )(localBuffer + (0 * tsz));
  double tmpimag110 = 0;
  __local double * localimag110 = ( __local double* )(localBuffer + (8 * tsz));
  double tmpresult111 = 0;
  __local double * localresult111 = ( __local double* )(localBuffer + (0 * tsz));
  double tmpresult212 = 0;
  __local double * localresult212 = ( __local double* )(localBuffer + (0 * tsz));
  double tmpresult313 = 0;
  __local double * localresult313 = ( __local double* )(localBuffer + (0 * tsz));
  double tmpresult414 = 0;
  __local double * localresult414 = ( __local double* )(localBuffer + (0 * tsz));
  double tmpresult515 = 0;
  __local double * localresult515 = ( __local double* )(localBuffer + (0 * tsz));
  double tmpresult616 = 0;
  __local double * localresult616 = ( __local double* )(localBuffer + (0 * tsz));
  double tmpresult717 = 0;
  __local double * localresult717 = ( __local double* )(localBuffer + (0 * tsz));
  double tmpresult818 = 0;
  __local double * localresult818 = ( __local double* )(localBuffer + (0 * tsz));

  /* kernel operation */
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
                (ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] = A_H[col_p * 256 + k];
                (ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[256 + k] = A_H[256 * 256 + col_p * 256 + k];
              }
            barrier(CLK_LOCAL_MEM_FENCE);
            barrier(CLK_LOCAL_MEM_FENCE);
            #pragma cap loop id(7) 
              for (int k = tidx; k < 256; k += tszx) {
                (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] = A_H[col_q * 256 + k];
                (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[256 + k] = A_H[256 * 256 + col_q * 256 + k];
              }
            barrier(CLK_LOCAL_MEM_FENCE);
            barrier(CLK_LOCAL_MEM_FENCE);
            #pragma cap loop id(8) 
              for (int k = tidx; k < 256; k += tszx) {
                (vi + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] = V_H[col_p * 256 + k];
                (vi + (j * (2) + start_index + 1) / 2 * 256 * 2)[256 + k] = V_H[256 * 256 + col_p * 256 + k];
              }
            barrier(CLK_LOCAL_MEM_FENCE);
            barrier(CLK_LOCAL_MEM_FENCE);
            #pragma cap loop id(9) 
              for (int k = tidx; k < 256; k += tszx) {
                (vj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] = V_H[col_q * 256 + k];
                (vj + (j * (2) + start_index + 1) / 2 * 256 * 2)[256 + k] = V_H[256 * 256 + col_q * 256 + k];
              }
            barrier(CLK_LOCAL_MEM_FENCE);
            int skip_trans = 0;
            barrier(CLK_LOCAL_MEM_FENCE);
            #pragma cap loop id(10) reduction(+: real1,imag1) 
              for (int k = tidx; k < 256; k += tszx) {
                tmpreal110 += (double)(ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] + (ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[256 + k] * (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[256 + k];
                tmpimag110 += (double)(ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[256 + k] - (ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[256 + k] * (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k];
              }
                        localreal110[tid] = tmpreal110;
            localimag110[tid] = tmpimag110;
            barrier(CLK_LOCAL_MEM_FENCE);

            if(tsz >= 1024)
            {
                        if(tid < 512)
                        {
                                    localreal110[tid] = localreal110[tid] + localreal110[tid + 512];
                                    localimag110[tid] = localimag110[tid] + localimag110[tid + 512];
                        }
                        barrier(CLK_LOCAL_MEM_FENCE);
            }

            if(tsz >= 512)
            {
                        if(tid < 256)
                        {
                                    localreal110[tid] = localreal110[tid] + localreal110[tid + 256];
                                    localimag110[tid] = localimag110[tid] + localimag110[tid + 256];
                        }
                        barrier(CLK_LOCAL_MEM_FENCE);
            }

            if(tsz >= 256)
            {
                        if(tid < 128)
                        {
                                    localreal110[tid] = localreal110[tid] + localreal110[tid + 128];
                                    localimag110[tid] = localimag110[tid] + localimag110[tid + 128];
                        }
                        barrier(CLK_LOCAL_MEM_FENCE);
            }

            if(tsz >= 128)
            {
                        if(tid < 64)
                        {
                                    localreal110[tid] = localreal110[tid] + localreal110[tid + 64];
                                    localimag110[tid] = localimag110[tid] + localimag110[tid + 64];
                        }
                        barrier(CLK_LOCAL_MEM_FENCE);
            }

            if(tid < 32)
            {
                        if(tsz >= 64)
                        {
                                    localreal110[tid] = localreal110[tid] + localreal110[tid + 32];
                                    localimag110[tid] = localimag110[tid] + localimag110[tid + 32];
                        }
                        if(tsz >= 32)
                        {
                                    localreal110[tid] = localreal110[tid] + localreal110[tid + 16];
                                    localimag110[tid] = localimag110[tid] + localimag110[tid + 16];
                        }
                        if(tsz >= 16)
                        {
                                    localreal110[tid] = localreal110[tid] + localreal110[tid + 8];
                                    localimag110[tid] = localimag110[tid] + localimag110[tid + 8];
                        }
                        if(tsz >= 8)
                        {
                                    localreal110[tid] = localreal110[tid] + localreal110[tid + 4];
                                    localimag110[tid] = localimag110[tid] + localimag110[tid + 4];
                        }
                        if(tsz >= 4)
                        {
                                    localreal110[tid] = localreal110[tid] + localreal110[tid + 2];
                                    localimag110[tid] = localimag110[tid] + localimag110[tid + 2];
                        }
                        if(tsz >= 2)
                        {
                                    localreal110[tid] = localreal110[tid] + localreal110[tid + 1];
                                    localimag110[tid] = localimag110[tid] + localimag110[tid + 1];
                        }
            }
            barrier(CLK_LOCAL_MEM_FENCE);

            real1 = real1 + localreal110[0];
            imag1 = imag1 + localimag110[0];            barrier(CLK_LOCAL_MEM_FENCE);
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
                for (int k = tidx; k < 256; k += tszx) 
                  tmpresult111 += (double)(ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256];
                            localresult111[tid] = tmpresult111;
              barrier(CLK_LOCAL_MEM_FENCE);

              if(tsz >= 1024)
              {
                            if(tid < 512)
                            {
                                          localresult111[tid] = localresult111[tid] + localresult111[tid + 512];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 512)
              {
                            if(tid < 256)
                            {
                                          localresult111[tid] = localresult111[tid] + localresult111[tid + 256];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 256)
              {
                            if(tid < 128)
                            {
                                          localresult111[tid] = localresult111[tid] + localresult111[tid + 128];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 128)
              {
                            if(tid < 64)
                            {
                                          localresult111[tid] = localresult111[tid] + localresult111[tid + 64];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tid < 32)
              {
                            if(tsz >= 64)
                            {
                                          localresult111[tid] = localresult111[tid] + localresult111[tid + 32];
                            }
                            if(tsz >= 32)
                            {
                                          localresult111[tid] = localresult111[tid] + localresult111[tid + 16];
                            }
                            if(tsz >= 16)
                            {
                                          localresult111[tid] = localresult111[tid] + localresult111[tid + 8];
                            }
                            if(tsz >= 8)
                            {
                                          localresult111[tid] = localresult111[tid] + localresult111[tid + 4];
                            }
                            if(tsz >= 4)
                            {
                                          localresult111[tid] = localresult111[tid] + localresult111[tid + 2];
                            }
                            if(tsz >= 2)
                            {
                                          localresult111[tid] = localresult111[tid] + localresult111[tid + 1];
                            }
              }
              barrier(CLK_LOCAL_MEM_FENCE);

              result1 = result1 + localresult111[0];              barrier(CLK_LOCAL_MEM_FENCE);
              double inner_ri = result1;
              barrier(CLK_LOCAL_MEM_FENCE);
              #pragma cap loop id(12) reduction(+: result2) 
                for (int k = tidx; k < 256; k += tszx) 
                  tmpresult212 += (double)(ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k];
                            localresult212[tid] = tmpresult212;
              barrier(CLK_LOCAL_MEM_FENCE);

              if(tsz >= 1024)
              {
                            if(tid < 512)
                            {
                                          localresult212[tid] = localresult212[tid] + localresult212[tid + 512];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 512)
              {
                            if(tid < 256)
                            {
                                          localresult212[tid] = localresult212[tid] + localresult212[tid + 256];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 256)
              {
                            if(tid < 128)
                            {
                                          localresult212[tid] = localresult212[tid] + localresult212[tid + 128];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 128)
              {
                            if(tid < 64)
                            {
                                          localresult212[tid] = localresult212[tid] + localresult212[tid + 64];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tid < 32)
              {
                            if(tsz >= 64)
                            {
                                          localresult212[tid] = localresult212[tid] + localresult212[tid + 32];
                            }
                            if(tsz >= 32)
                            {
                                          localresult212[tid] = localresult212[tid] + localresult212[tid + 16];
                            }
                            if(tsz >= 16)
                            {
                                          localresult212[tid] = localresult212[tid] + localresult212[tid + 8];
                            }
                            if(tsz >= 8)
                            {
                                          localresult212[tid] = localresult212[tid] + localresult212[tid + 4];
                            }
                            if(tsz >= 4)
                            {
                                          localresult212[tid] = localresult212[tid] + localresult212[tid + 2];
                            }
                            if(tsz >= 2)
                            {
                                          localresult212[tid] = localresult212[tid] + localresult212[tid + 1];
                            }
              }
              barrier(CLK_LOCAL_MEM_FENCE);

              result2 = result2 + localresult212[0];              barrier(CLK_LOCAL_MEM_FENCE);
              double inner_ir = result2;
              barrier(CLK_LOCAL_MEM_FENCE);
              #pragma cap loop id(13) reduction(+: result3) 
                for (int k = tidx; k < 256; k += tszx) 
                  tmpresult313 += (double)(ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k];
                            localresult313[tid] = tmpresult313;
              barrier(CLK_LOCAL_MEM_FENCE);

              if(tsz >= 1024)
              {
                            if(tid < 512)
                            {
                                          localresult313[tid] = localresult313[tid] + localresult313[tid + 512];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 512)
              {
                            if(tid < 256)
                            {
                                          localresult313[tid] = localresult313[tid] + localresult313[tid + 256];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 256)
              {
                            if(tid < 128)
                            {
                                          localresult313[tid] = localresult313[tid] + localresult313[tid + 128];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 128)
              {
                            if(tid < 64)
                            {
                                          localresult313[tid] = localresult313[tid] + localresult313[tid + 64];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tid < 32)
              {
                            if(tsz >= 64)
                            {
                                          localresult313[tid] = localresult313[tid] + localresult313[tid + 32];
                            }
                            if(tsz >= 32)
                            {
                                          localresult313[tid] = localresult313[tid] + localresult313[tid + 16];
                            }
                            if(tsz >= 16)
                            {
                                          localresult313[tid] = localresult313[tid] + localresult313[tid + 8];
                            }
                            if(tsz >= 8)
                            {
                                          localresult313[tid] = localresult313[tid] + localresult313[tid + 4];
                            }
                            if(tsz >= 4)
                            {
                                          localresult313[tid] = localresult313[tid] + localresult313[tid + 2];
                            }
                            if(tsz >= 2)
                            {
                                          localresult313[tid] = localresult313[tid] + localresult313[tid + 1];
                            }
              }
              barrier(CLK_LOCAL_MEM_FENCE);

              result3 = result3 + localresult313[0];              barrier(CLK_LOCAL_MEM_FENCE);
              double inner_rr = result3;
              barrier(CLK_LOCAL_MEM_FENCE);
              #pragma cap loop id(14) reduction(+: result4) 
                for (int k = tidx; k < 256; k += tszx) 
                  tmpresult414 += (double)(ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256];
                            localresult414[tid] = tmpresult414;
              barrier(CLK_LOCAL_MEM_FENCE);

              if(tsz >= 1024)
              {
                            if(tid < 512)
                            {
                                          localresult414[tid] = localresult414[tid] + localresult414[tid + 512];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 512)
              {
                            if(tid < 256)
                            {
                                          localresult414[tid] = localresult414[tid] + localresult414[tid + 256];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 256)
              {
                            if(tid < 128)
                            {
                                          localresult414[tid] = localresult414[tid] + localresult414[tid + 128];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 128)
              {
                            if(tid < 64)
                            {
                                          localresult414[tid] = localresult414[tid] + localresult414[tid + 64];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tid < 32)
              {
                            if(tsz >= 64)
                            {
                                          localresult414[tid] = localresult414[tid] + localresult414[tid + 32];
                            }
                            if(tsz >= 32)
                            {
                                          localresult414[tid] = localresult414[tid] + localresult414[tid + 16];
                            }
                            if(tsz >= 16)
                            {
                                          localresult414[tid] = localresult414[tid] + localresult414[tid + 8];
                            }
                            if(tsz >= 8)
                            {
                                          localresult414[tid] = localresult414[tid] + localresult414[tid + 4];
                            }
                            if(tsz >= 4)
                            {
                                          localresult414[tid] = localresult414[tid] + localresult414[tid + 2];
                            }
                            if(tsz >= 2)
                            {
                                          localresult414[tid] = localresult414[tid] + localresult414[tid + 1];
                            }
              }
              barrier(CLK_LOCAL_MEM_FENCE);

              result4 = result4 + localresult414[0];              barrier(CLK_LOCAL_MEM_FENCE);
              double inner_ii = result4;
              double a = (double)inner_ri - (double)inner_ir;
              double b = (double)inner_rr + (double)inner_ii;
              double s_a2b2 = (double)sign(b) * sqrt(a * a + b * b);
              double sin_alpha = a / s_a2b2;
              double cos_alpha = b / s_a2b2;
              double m = -1 * (b * cos_alpha + a * sin_alpha);
              barrier(CLK_LOCAL_MEM_FENCE);
              #pragma cap loop id(15) reduction(+: result5) 
                for (int k = tidx; k < 256; k += tszx) 
                  tmpresult515 += (double)(cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k];
                            localresult515[tid] = tmpresult515;
              barrier(CLK_LOCAL_MEM_FENCE);

              if(tsz >= 1024)
              {
                            if(tid < 512)
                            {
                                          localresult515[tid] = localresult515[tid] + localresult515[tid + 512];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 512)
              {
                            if(tid < 256)
                            {
                                          localresult515[tid] = localresult515[tid] + localresult515[tid + 256];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 256)
              {
                            if(tid < 128)
                            {
                                          localresult515[tid] = localresult515[tid] + localresult515[tid + 128];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 128)
              {
                            if(tid < 64)
                            {
                                          localresult515[tid] = localresult515[tid] + localresult515[tid + 64];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tid < 32)
              {
                            if(tsz >= 64)
                            {
                                          localresult515[tid] = localresult515[tid] + localresult515[tid + 32];
                            }
                            if(tsz >= 32)
                            {
                                          localresult515[tid] = localresult515[tid] + localresult515[tid + 16];
                            }
                            if(tsz >= 16)
                            {
                                          localresult515[tid] = localresult515[tid] + localresult515[tid + 8];
                            }
                            if(tsz >= 8)
                            {
                                          localresult515[tid] = localresult515[tid] + localresult515[tid + 4];
                            }
                            if(tsz >= 4)
                            {
                                          localresult515[tid] = localresult515[tid] + localresult515[tid + 2];
                            }
                            if(tsz >= 2)
                            {
                                          localresult515[tid] = localresult515[tid] + localresult515[tid + 1];
                            }
              }
              barrier(CLK_LOCAL_MEM_FENCE);

              result5 = result5 + localresult515[0];              barrier(CLK_LOCAL_MEM_FENCE);
              double inner_rrj = result5;
              barrier(CLK_LOCAL_MEM_FENCE);
              #pragma cap loop id(16) reduction(+: result6) 
                for (int k = tidx; k < 256; k += tszx) 
                  tmpresult616 += (double)(cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256];
                            localresult616[tid] = tmpresult616;
              barrier(CLK_LOCAL_MEM_FENCE);

              if(tsz >= 1024)
              {
                            if(tid < 512)
                            {
                                          localresult616[tid] = localresult616[tid] + localresult616[tid + 512];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 512)
              {
                            if(tid < 256)
                            {
                                          localresult616[tid] = localresult616[tid] + localresult616[tid + 256];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 256)
              {
                            if(tid < 128)
                            {
                                          localresult616[tid] = localresult616[tid] + localresult616[tid + 128];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 128)
              {
                            if(tid < 64)
                            {
                                          localresult616[tid] = localresult616[tid] + localresult616[tid + 64];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tid < 32)
              {
                            if(tsz >= 64)
                            {
                                          localresult616[tid] = localresult616[tid] + localresult616[tid + 32];
                            }
                            if(tsz >= 32)
                            {
                                          localresult616[tid] = localresult616[tid] + localresult616[tid + 16];
                            }
                            if(tsz >= 16)
                            {
                                          localresult616[tid] = localresult616[tid] + localresult616[tid + 8];
                            }
                            if(tsz >= 8)
                            {
                                          localresult616[tid] = localresult616[tid] + localresult616[tid + 4];
                            }
                            if(tsz >= 4)
                            {
                                          localresult616[tid] = localresult616[tid] + localresult616[tid + 2];
                            }
                            if(tsz >= 2)
                            {
                                          localresult616[tid] = localresult616[tid] + localresult616[tid + 1];
                            }
              }
              barrier(CLK_LOCAL_MEM_FENCE);

              result6 = result6 + localresult616[0];              barrier(CLK_LOCAL_MEM_FENCE);
              double inner_iij = result6;
              barrier(CLK_LOCAL_MEM_FENCE);
              #pragma cap loop id(17) reduction(+: result7) 
                for (int k = tidx; k < 256; k += tszx) 
                  tmpresult717 += (double)(ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * (ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k];
                            localresult717[tid] = tmpresult717;
              barrier(CLK_LOCAL_MEM_FENCE);

              if(tsz >= 1024)
              {
                            if(tid < 512)
                            {
                                          localresult717[tid] = localresult717[tid] + localresult717[tid + 512];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 512)
              {
                            if(tid < 256)
                            {
                                          localresult717[tid] = localresult717[tid] + localresult717[tid + 256];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 256)
              {
                            if(tid < 128)
                            {
                                          localresult717[tid] = localresult717[tid] + localresult717[tid + 128];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 128)
              {
                            if(tid < 64)
                            {
                                          localresult717[tid] = localresult717[tid] + localresult717[tid + 64];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tid < 32)
              {
                            if(tsz >= 64)
                            {
                                          localresult717[tid] = localresult717[tid] + localresult717[tid + 32];
                            }
                            if(tsz >= 32)
                            {
                                          localresult717[tid] = localresult717[tid] + localresult717[tid + 16];
                            }
                            if(tsz >= 16)
                            {
                                          localresult717[tid] = localresult717[tid] + localresult717[tid + 8];
                            }
                            if(tsz >= 8)
                            {
                                          localresult717[tid] = localresult717[tid] + localresult717[tid + 4];
                            }
                            if(tsz >= 4)
                            {
                                          localresult717[tid] = localresult717[tid] + localresult717[tid + 2];
                            }
                            if(tsz >= 2)
                            {
                                          localresult717[tid] = localresult717[tid] + localresult717[tid + 1];
                            }
              }
              barrier(CLK_LOCAL_MEM_FENCE);

              result7 = result7 + localresult717[0];              barrier(CLK_LOCAL_MEM_FENCE);
              double inner_rri = result7;
              barrier(CLK_LOCAL_MEM_FENCE);
              #pragma cap loop id(18) reduction(+: result8) 
                for (int k = tidx; k < 256; k += tszx) 
                  tmpresult818 += (double)(ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * (ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256];
                            localresult818[tid] = tmpresult818;
              barrier(CLK_LOCAL_MEM_FENCE);

              if(tsz >= 1024)
              {
                            if(tid < 512)
                            {
                                          localresult818[tid] = localresult818[tid] + localresult818[tid + 512];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 512)
              {
                            if(tid < 256)
                            {
                                          localresult818[tid] = localresult818[tid] + localresult818[tid + 256];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 256)
              {
                            if(tid < 128)
                            {
                                          localresult818[tid] = localresult818[tid] + localresult818[tid + 128];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tsz >= 128)
              {
                            if(tid < 64)
                            {
                                          localresult818[tid] = localresult818[tid] + localresult818[tid + 64];
                            }
                            barrier(CLK_LOCAL_MEM_FENCE);
              }

              if(tid < 32)
              {
                            if(tsz >= 64)
                            {
                                          localresult818[tid] = localresult818[tid] + localresult818[tid + 32];
                            }
                            if(tsz >= 32)
                            {
                                          localresult818[tid] = localresult818[tid] + localresult818[tid + 16];
                            }
                            if(tsz >= 16)
                            {
                                          localresult818[tid] = localresult818[tid] + localresult818[tid + 8];
                            }
                            if(tsz >= 8)
                            {
                                          localresult818[tid] = localresult818[tid] + localresult818[tid + 4];
                            }
                            if(tsz >= 4)
                            {
                                          localresult818[tid] = localresult818[tid] + localresult818[tid + 2];
                            }
                            if(tsz >= 2)
                            {
                                          localresult818[tid] = localresult818[tid] + localresult818[tid + 1];
                            }
              }
              barrier(CLK_LOCAL_MEM_FENCE);

              result8 = result8 + localresult818[0];              barrier(CLK_LOCAL_MEM_FENCE);
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
                  real2 = (ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * cos_x + 1 * (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * cos_alpha * sin_x + (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * sin_alpha * sin_x;
                  imag2 = (ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * cos_x + 1 * (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * cos_alpha * sin_x - (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * sin_alpha * sin_x;
                  A_H[col_p * 256 + k] = real2;
                  A_H[256 * 256 + col_p * 256 + k] = imag2;
                }
              barrier(CLK_LOCAL_MEM_FENCE);
              barrier(CLK_LOCAL_MEM_FENCE);
              #pragma cap loop id(20) 
                for (int k = tidx; k < 256; k += tszx) {
                  real3 = (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * cos_x + (-1) * (ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * cos_alpha * sin_x + (ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * sin_alpha * sin_x;
                  imag3 = (cj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * cos_x + (-1) * (ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * cos_alpha * sin_x - (ci + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * sin_alpha * sin_x;
                  A_H[col_q * 256 + k] = real3;
                  A_H[256 * 256 + col_q * 256 + k] = imag3;
                }
              barrier(CLK_LOCAL_MEM_FENCE);
              barrier(CLK_LOCAL_MEM_FENCE);
              #pragma cap loop id(21) 
                for (int k = tidx; k < 256; k += tszx) {
                  real4 = (vi + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * cos_x + 1 * (vj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * cos_alpha * sin_x + (vj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * sin_alpha * sin_x;
                  imag4 = (vi + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * cos_x + 1 * (vj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * cos_alpha * sin_x - (vj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * sin_alpha * sin_x;
                  V_H[col_p * 256 + k] = real4;
                  V_H[256 * 256 + col_p * 256 + k] = imag4;
                }
              barrier(CLK_LOCAL_MEM_FENCE);
              barrier(CLK_LOCAL_MEM_FENCE);
              #pragma cap loop id(22) 
                for (int k = tidx; k < 256; k += tszx) {
                  real5 = (vj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * cos_x + (-1) * (vi + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * cos_alpha * sin_x + (vi + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * sin_alpha * sin_x;
                  imag5 = (vj + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * cos_x + (-1) * (vi + (j * (2) + start_index + 1) / 2 * 256 * 2)[k + 256] * cos_alpha * sin_x - (vi + (j * (2) + start_index + 1) / 2 * 256 * 2)[k] * sin_alpha * sin_x;
                  V_H[col_q * 256 + k] = real5;
                  V_H[256 * 256 + col_q * 256 + k] = imag5;
                }
              barrier(CLK_LOCAL_MEM_FENCE);
            }
            rotate_col_idx[(j * (2) + start_index + 1) - 1] = col_q;
            rotate_col_idx[(j * (2) + start_index + 1)] = col_p;
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
  double tmpreal4 = 0;
  __local double * localreal4 = ( __local double* )(localBuffer + (0 * tsz));
  double tmpimag4 = 0;
  __local double * localimag4 = ( __local double* )(localBuffer + (8 * tsz));

  /* kernel operation */
    {
      #pragma cap map threadblock([0:2]) thread([0:3][0:4]) 
        #pragma cap loop id(2) 
          for (int i = bidx; i < 256; i += bszx) {
            double real = 0.F;
            double imag = 0.F;
            barrier(CLK_LOCAL_MEM_FENCE);
            #pragma cap loop id(3) 
              for (int k = tidx; k < 256; k += tszx) {
                (ci + i * 256 * 2)[k] = A_H[i * 256 + k];
                (ci + i * 256 * 2)[256 + k] = A_H[256 * 256 + i * 256 + k];
              }
            barrier(CLK_LOCAL_MEM_FENCE);
            barrier(CLK_LOCAL_MEM_FENCE);
            #pragma cap loop id(4) reduction(+: real,imag) 
              for (int l = tidx; l < 256; l += tszx) {
                tmpreal4 += (double)(ci + i * 256 * 2)[l] * (ci + i * 256 * 2)[l] + (ci + i * 256 * 2)[256 + l] * (ci + i * 256 * 2)[256 + l];
                tmpimag4 += (double)(ci + i * 256 * 2)[l] * (ci + i * 256 * 2)[256 + l] - (ci + i * 256 * 2)[256 + l] * (ci + i * 256 * 2)[l];
              }
                        localreal4[tid] = tmpreal4;
            localimag4[tid] = tmpimag4;
            barrier(CLK_LOCAL_MEM_FENCE);

            if(tsz >= 1024)
            {
                        if(tid < 512)
                        {
                                    localreal4[tid] = localreal4[tid] + localreal4[tid + 512];
                                    localimag4[tid] = localimag4[tid] + localimag4[tid + 512];
                        }
                        barrier(CLK_LOCAL_MEM_FENCE);
            }

            if(tsz >= 512)
            {
                        if(tid < 256)
                        {
                                    localreal4[tid] = localreal4[tid] + localreal4[tid + 256];
                                    localimag4[tid] = localimag4[tid] + localimag4[tid + 256];
                        }
                        barrier(CLK_LOCAL_MEM_FENCE);
            }

            if(tsz >= 256)
            {
                        if(tid < 128)
                        {
                                    localreal4[tid] = localreal4[tid] + localreal4[tid + 128];
                                    localimag4[tid] = localimag4[tid] + localimag4[tid + 128];
                        }
                        barrier(CLK_LOCAL_MEM_FENCE);
            }

            if(tsz >= 128)
            {
                        if(tid < 64)
                        {
                                    localreal4[tid] = localreal4[tid] + localreal4[tid + 64];
                                    localimag4[tid] = localimag4[tid] + localimag4[tid + 64];
                        }
                        barrier(CLK_LOCAL_MEM_FENCE);
            }

            if(tid < 32)
            {
                        if(tsz >= 64)
                        {
                                    localreal4[tid] = localreal4[tid] + localreal4[tid + 32];
                                    localimag4[tid] = localimag4[tid] + localimag4[tid + 32];
                        }
                        if(tsz >= 32)
                        {
                                    localreal4[tid] = localreal4[tid] + localreal4[tid + 16];
                                    localimag4[tid] = localimag4[tid] + localimag4[tid + 16];
                        }
                        if(tsz >= 16)
                        {
                                    localreal4[tid] = localreal4[tid] + localreal4[tid + 8];
                                    localimag4[tid] = localimag4[tid] + localimag4[tid + 8];
                        }
                        if(tsz >= 8)
                        {
                                    localreal4[tid] = localreal4[tid] + localreal4[tid + 4];
                                    localimag4[tid] = localimag4[tid] + localimag4[tid + 4];
                        }
                        if(tsz >= 4)
                        {
                                    localreal4[tid] = localreal4[tid] + localreal4[tid + 2];
                                    localimag4[tid] = localimag4[tid] + localimag4[tid + 2];
                        }
                        if(tsz >= 2)
                        {
                                    localreal4[tid] = localreal4[tid] + localreal4[tid + 1];
                                    localimag4[tid] = localimag4[tid] + localimag4[tid + 1];
                        }
            }
            barrier(CLK_LOCAL_MEM_FENCE);

            real = real + localreal4[0];
            imag = imag + localimag4[0];            barrier(CLK_LOCAL_MEM_FENCE);
            double norm_A = sqrt((double)sqrt((double)real * (double)real + (double)imag * (double)imag));
            S_H[i] = norm_A;
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

