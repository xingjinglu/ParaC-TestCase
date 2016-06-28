/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

/* kernel function */
__kernel void kernel_1(
  __global int * pSrc_padding,
  int const height,
  int const width,
  __global unsigned char * const Source)
{
  /* kernel thread ID */
  const int bszx = get_num_groups(0);
  const int bidx = get_group_id(0);
  const int tszx = get_local_size(0);
  const int tidx = get_local_id(0);

  /* Local vars */

  /* kernel operation */
    {
      #pragma cap map threadblock([0:0]) thread([0:1]) 
        #pragma cap loop id(0) 
          for (int h = bidx; h < height + 2 - (2); h += bszx) {
            pSrc_padding[(h + 2) * (width + 4) + 1] = 2 * Source[((h + 2) - 2) * width + 1] - 1 * Source[((h + 2) - 2) * width + 3];
            pSrc_padding[(h + 2) * (width + 4) + 0] = 4 * Source[((h + 2) - 2) * width + 3] - 4 * Source[((h + 2) - 2) * width + 1] + 2 * Source[((h + 2) - 2) * width + 0] - 1 * Source[((h + 2) - 2) * width + 2];
            pSrc_padding[(h + 2) * (width + 4) + width + 2] = 2 * Source[((h + 2) - 2) * width + width - 2] - 1 * Source[((h + 2) - 2) * width + width - 4];
            pSrc_padding[(h + 2) * (width + 4) + width + 3] = 4 * Source[((h + 2) - 2) * width + width - 4] - 4 * Source[((h + 2) - 2) * width + width - 2] + 2 * Source[((h + 2) - 2) * width + width - 1] - 1 * Source[((h + 2) - 2) * width + width - 3];
            barrier(CLK_LOCAL_MEM_FENCE);
            #pragma cap loop id(1) 
              for (int w = tidx; w < width; w += tszx) 
                pSrc_padding[(h + 2) * (width + 4) + w + 2] = Source[((h + 2) - 2) * width + w];
            barrier(CLK_LOCAL_MEM_FENCE);
          }
    }

}

/* kernel function */
__kernel void kernel_2(
  __global unsigned char * pBufL_cp,
  int const height,
  int const width,
  __global int * const pSrc_padding)
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
      #pragma cap map threadblock([0:3][1:2]) thread([0:3][1:2]) 
        #pragma cap loop id(2) 
          for (int h = tszy * bidy + ( tidy ) ; h < height; h += tszy * bszy) 
            #pragma cap loop id(3) 
              for (int w = tszx * bidx + ( tidx ) ; w < width; w += tszx * bszx) {
                pBufL_cp[h * width + w] = (pSrc_padding[(h + 2) * (width + 4) + w] + (pSrc_padding[(h + 2) * (width + 4) + w + 1] << 2) + 6 * pSrc_padding[(h + 2) * (width + 4) + (w + 2)] + (pSrc_padding[(h + 2) * (width + 4) + (w + 3)] << 2) + pSrc_padding[(h + 2) * (width + 4) + (w + 4)] + 8) >> 4;
              }
    }

}

/* kernel function */
__kernel void kernel_3(
  __global int * pSrc_padding2,
  int const height,
  int const width,
  __global unsigned char * const pBufL_cp)
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
      #pragma cap map threadblock([0:5][1:4]) thread([0:5][1:4]) 
        #pragma cap loop id(4) 
          for (int h = tszy * bidy + ( tidy ) ; h < height + 2 - (2); h += tszy * bszy) {
            #pragma cap loop id(5) 
              for (int w = tszx * bidx + ( tidx ) ; w < width; w += tszx * bszx) 
                pSrc_padding2[(h + 2) * (width + 4) + w + 2] = pBufL_cp[((h + 2) - 2) * width + w];
          }
    }

}

/* kernel function */
__kernel void kernel_4(
  __global int * pSrc_padding2,
  int const height,
  int const width,
  __global unsigned char * const pBufL_cp)
{
  /* kernel thread ID */
  const int tszx = get_local_size(0);
  const int tidx = get_local_id(0);
  const int bszx = get_num_groups(0);
  const int bidx = get_group_id(0);

  /* Local vars */

  /* kernel operation */
    {
      #pragma cap map threadblock([0:6]) thread([0:6]) 
        #pragma cap loop id(6) 
          for (int w = tszx * bidx + ( tidx ) ; w < (width + 2) - (2); w += tszx * bszx) {
            pSrc_padding2[1 * (width + 4) + (w + 2)] = 2 * pBufL_cp[1 * width + (w + 2) - 2] - 1 * pBufL_cp[3 * width + (w + 2) - 2];
            pSrc_padding2[0 * (width + 4) + (w + 2)] = 4 * pBufL_cp[3 * width + (w + 2) - 2] - 4 * pBufL_cp[1 * width + (w + 2) - 2] + 2 * pBufL_cp[0 * width + (w + 2) - 2] - 1 * pBufL_cp[2 * width + (w + 2) - 2];
            pSrc_padding2[(height + 2) * (width + 4) + (w + 2)] = 2 * pBufL_cp[(height - 2) * width + (w + 2) - 2] - 1 * pBufL_cp[(height - 4) * width + (w + 2) - 2];
            pSrc_padding2[(height + 3) * (width + 4) + (w + 2)] = 4 * pBufL_cp[(height - 4) * width + (w + 2) - 2] - 4 * pBufL_cp[(height - 2) * width + (w + 2) - 2] + 2 * pBufL_cp[(height - 1) * width + (w + 2) - 2] - 1 * pBufL_cp[(height - 3) * width + (w + 2) - 2];
          }
    }

}

/* kernel function */
__kernel void kernel_5(
  __global unsigned char * FilterDst,
  int const height,
  int const width,
  __global int * const pSrc_padding2)
{
  /* kernel thread ID */
  const int tszx = get_local_size(0);
  const int tidx = get_local_id(0);
  const int bszx = get_num_groups(0);
  const int bidx = get_group_id(0);
  const int tszy = get_local_size(1);
  const int tidy = get_local_id(1);
  const int bszy = get_num_groups(1);
  const int bidy = get_group_id(1);

  /* Local vars */

  /* kernel operation */
    {
      #pragma cap map threadblock([0:7][1:8]) thread([0:7][1:8]) 
        #pragma cap loop id(7) 
          for (int w = tszx * bidx + ( tidx ) ; w < width; w += tszx * bszx) 
            #pragma cap loop id(8) 
              for (int h = tszy * bidy + ( tidy ) ; h < height; h += tszy * bszy) {
                FilterDst[h * width + w] = (pSrc_padding2[(h) * (width + 4) + (w + 2)] + (pSrc_padding2[(h + 1) * (width + 4) + (w + 2)] << 2) + 6 * pSrc_padding2[(h + 2) * (width + 4) + (w + 2)] + (pSrc_padding2[(h + 3) * (width + 4) + (w + 2)] << 2) + pSrc_padding2[(h + 4) * (width + 4) + (w + 2)] + 8) >> 4;
              }
    }

}

/* kernel function */
__kernel void kernel_6(
  __global unsigned char * DownsampleDst,
  int const width,
  int const halfWidth,
  int const halfHeight,
  __global unsigned char * const FilterDst)
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
      #pragma cap map threadblock([0:10][1:9]) thread([0:10][1:9]) 
        #pragma cap loop id(9) 
          for (int y = tszy * bidy + ( tidy ) ; y < halfHeight; y += tszy * bszy) {
            #pragma cap loop id(10) 
              for (int x = tszx * bidx + ( tidx ) ; x < halfWidth; x += tszx * bszx) {
                DownsampleDst[y * halfWidth + x] = FilterDst[(y << 1) * width + (x << 1)];
              }
          }
    }

}

/* kernel function */
__kernel void kernel_7(
  __global unsigned char * UpsampleDst,
  int const height,
  int const width,
  int const halfWidth,
  int const halfHeight,
  __global unsigned char * const DownsampleDst)
{
  /* kernel thread ID */
  const int tszx = get_local_size(0);
  const int tidx = get_local_id(0);
  const int bszx = get_num_groups(0);
  const int bidx = get_group_id(0);

  /* Local vars */

  /* kernel operation */
    {
      #pragma cap map threadblock([0:11]) thread([0:11]) 
        #pragma cap loop id(11) 
          for (int x = tszx * bidx + ( tidx ) ; x < halfWidth - (1); x += tszx * bszx) {
            UpsampleDst[(height - 1) * width + 2 * (x + 1) - 1] = (DownsampleDst[(halfHeight - 1) * halfWidth + (x + 1) - 1] + DownsampleDst[(halfHeight - 1) * halfWidth + (x + 1)] + 1) >> 1;
            UpsampleDst[(height - 1) * width + 2 * (x + 1)] = DownsampleDst[(halfHeight - 1) * halfWidth + (x + 1)];
          }
    }

}

/* kernel function */
__kernel void kernel_8(
  __global unsigned char * UpsampleDst,
  int const width,
  int const halfWidth,
  int const halfHeight,
  __global unsigned char * const DownsampleDst)
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
      #pragma cap map threadblock([0:13][1:12]) thread([0:13][1:12]) 
        #pragma cap loop id(12) 
          for (int y = tszy * bidy + ( tidy ) ; y < (0 - (halfHeight - 1)) * -1; y += tszy * bszy) {
            #pragma cap loop id(13) 
              for (int x = tszx * bidx + ( tidx ) ; x < halfWidth - (1); x += tszx * bszx) {
                UpsampleDst[(2 * (y * -1 + halfHeight - 1) - 1) * width + 2 * (x + 1) - 1] = (DownsampleDst[((y * -1 + halfHeight - 1)) * halfWidth + (x + 1) - 1] + DownsampleDst[((y * -1 + halfHeight - 1)) * halfWidth + (x + 1)] + DownsampleDst[((y * -1 + halfHeight - 1) - 1) * halfWidth + (x + 1) - 1] + DownsampleDst[((y * -1 + halfHeight - 1) - 1) * halfWidth + (x + 1)] + 2) >> 2;
                UpsampleDst[(2 * (y * -1 + halfHeight - 1) - 1) * width + 2 * (x + 1)] = (DownsampleDst[((y * -1 + halfHeight - 1)) * halfWidth + (x + 1)] + DownsampleDst[((y * -1 + halfHeight - 1) - 1) * halfWidth + (x + 1)] + 1) >> 1;
                UpsampleDst[(2 * (y * -1 + halfHeight - 1)) * width + 2 * (x + 1) - 1] = (DownsampleDst[((y * -1 + halfHeight - 1)) * halfWidth + (x + 1) - 1] + DownsampleDst[((y * -1 + halfHeight - 1)) * halfWidth + (x + 1)] + 1) >> 1;
                UpsampleDst[(2 * (y * -1 + halfHeight - 1)) * width + 2 * (x + 1)] = DownsampleDst[((y * -1 + halfHeight - 1)) * halfWidth + (x + 1)];
              }
            UpsampleDst[(2 * (y * -1 + halfHeight - 1) - 1) * width + width - 1] = (DownsampleDst[((y * -1 + halfHeight - 1)) * halfWidth + halfWidth - 1] + DownsampleDst[((y * -1 + halfHeight - 1) - 1) * halfWidth + halfWidth - 1] + 1) >> 1;
            UpsampleDst[(2 * (y * -1 + halfHeight - 1)) * width + width - 1] = DownsampleDst[((y * -1 + halfHeight - 1)) * halfWidth + halfWidth - 1];
            UpsampleDst[(2 * (y * -1 + halfHeight - 1) - 1) * width + 0] = (DownsampleDst[((y * -1 + halfHeight - 1)) * halfWidth + 0] + DownsampleDst[((y * -1 + halfHeight - 1) - 1) * halfWidth + 0] + 1) >> 1;
            UpsampleDst[(2 * (y * -1 + halfHeight - 1)) * width + 0] = DownsampleDst[((y * -1 + halfHeight - 1)) * halfWidth + 0];
          }
    }

}

/* kernel function */
__kernel void kernel_9(
  __global unsigned char * UpsampleDst,
  int const width,
  int const halfWidth,
  __global unsigned char * const DownsampleDst)
{
  /* kernel thread ID */
  const int tszx = get_local_size(0);
  const int tidx = get_local_id(0);
  const int bszx = get_num_groups(0);
  const int bidx = get_group_id(0);

  /* Local vars */

  /* kernel operation */
    {
      #pragma cap map threadblock([0:14]) thread([0:14]) 
        #pragma cap loop id(14) 
          for (int x = tszx * bidx + ( tidx ) ; x < (0 - (halfWidth - 1)) * -1; x += tszx * bszx) {
            UpsampleDst[(0) * width + 2 * (x * -1 + halfWidth - 1)] = DownsampleDst[(0) * halfWidth + (x * -1 + halfWidth - 1)];
            UpsampleDst[(0) * width + 2 * (x * -1 + halfWidth - 1) - 1] = ((int)DownsampleDst[(0) * halfWidth + (x * -1 + halfWidth - 1) - 1] + DownsampleDst[(0) * halfWidth + (x * -1 + halfWidth - 1)] + 1) / 2;
          }
    }

}

/* kernel function */
__kernel void kernel_10(
  __global short * LaplacianLayer,
  int const height,
  int const width,
  __global unsigned char * const Source,
  __global unsigned char * const UpsampleDst)
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
      #pragma cap map threadblock([0:16][1:15]) thread([0:16][1:15]) 
        #pragma cap loop id(15) 
          for (int y = tszy * bidy + ( tidy ) ; y < height; y += tszy * bszy) {
            #pragma cap loop id(16) 
              for (int x = tszx * bidx + ( tidx ) ; x < width; x += tszx * bszx) {
                LaplacianLayer[y * width + x] = (short)(Source[y * width + x]) - (short)(UpsampleDst[y * width + x]);
              }
          }
    }

}

