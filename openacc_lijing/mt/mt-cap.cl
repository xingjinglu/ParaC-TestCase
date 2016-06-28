/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

/* kernel function */
__kernel void kernel_1(
  __global float * B,
  int const n,
  __global float * const A)
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
    #pragma cap map thread([0:1][1:0]) threadblock([0:1][1:0]) 
      #pragma cap loop id(0) 
        for (int i = tszy * bidy + ( tidy ) ; i < n; i += tszy * bszy) {
          #pragma cap loop id(1) 
            for (int j = tszx * bidx + ( tidx ) ; j < n; j += tszx * bszx) {
              B[j * n + i] = A[i * n + j];
            }
        }
  }

}

