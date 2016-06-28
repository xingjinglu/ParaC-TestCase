/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

#pragma OPENCL EXTENSION cl_khr_fp64: enable

#pragma OPENCL EXTENSION cl_khr_int64_base_atomics: enable

#pragma OPENCL EXTENSION cl_khr_int64_extended_atomics: enable

/* kernel function */
__kernel void kernel_1(
  __global unsigned char * yPlaneDown,
  int const width,
  int const height,
  int const quarterWidth,
  __global unsigned char * const yPlane)
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
          for (int i = tszy * bidy + ( tidy ) ; i < (height + 4 - 1) / (4); i += tszy * bszy) {
            #pragma cap loop id(1) 
              for (int j = tszx * bidx + ( tidx ) ; j < (width + 4 - 1) / (4); j += tszx * bszx) {
                yPlaneDown[((i * (4)) / 4) * quarterWidth + (j * (4)) / 4] = (yPlane[(i * (4)) * width + (j * (4))] + yPlane[(i * (4)) * width + (j * (4)) + 1] + yPlane[(i * (4)) * width + (j * (4)) + 2] + yPlane[(i * (4)) * width + (j * (4)) + 3] + yPlane[((i * (4)) + 1) * width + (j * (4))] + yPlane[((i * (4)) + 1) * width + (j * (4)) + 1] + yPlane[((i * (4)) + 1) * width + (j * (4)) + 2] + yPlane[((i * (4)) + 1) * width + (j * (4)) + 3] + yPlane[((i * (4)) + 2) * width + (j * (4))] + yPlane[((i * (4)) + 2) * width + (j * (4)) + 1] + yPlane[((i * (4)) + 2) * width + (j * (4)) + 2] + yPlane[((i * (4)) + 2) * width + (j * (4)) + 3] + yPlane[((i * (4)) + 3) * width + (j * (4))] + yPlane[((i * (4)) + 3) * width + (j * (4)) + 1] + yPlane[((i * (4)) + 3) * width + (j * (4)) + 2] + yPlane[((i * (4)) + 3) * width + (j * (4)) + 3] + 8) >> 4;
              }
          }
    }

}

/* kernel function */
__kernel void kernel_2(
  __global unsigned char * yPlaneCSER,
  int const width,
  int const quarterWidth,
  int const quarterHeight,
  __global unsigned char * const yPlaneDown)
{
  /* kernel thread ID */
  const int tszx = get_local_size(0);
  const int tidx = get_local_id(0);
  const int bszx = get_num_groups(0);
  const int bidx = get_group_id(0);

  /* Local vars */

  /* kernel operation */
    {
      #pragma cap map threadblock([0:2]) thread([0:2]) 
        #pragma cap loop id(2) 
          for (int h = tszx * bidx + ( tidx ) ; h < quarterHeight; h += tszx * bszx) {
            yPlaneCSER[h * 4 * width + 0] = yPlaneDown[h * quarterWidth + 0];
          }
    }

}

/* kernel function */
__kernel void kernel_3(
  int const width,
  int const quarterHeight,
  __global unsigned char * yPlaneCSER)
{
  /* kernel thread ID */
  const int tszx = get_local_size(0);
  const int tidx = get_local_id(0);
  const int bszx = get_num_groups(0);
  const int bidx = get_group_id(0);

  /* Local vars */

  /* kernel operation */
    {
      #pragma cap map threadblock([0:3]) thread([0:3]) 
        #pragma cap loop id(3) 
          for (int h = tszx * bidx + ( tidx ) ; h < quarterHeight; h += tszx * bszx) {
            if (h < quarterHeight - 1) {
              yPlaneCSER[(h * 4 + 1) * width + 0] = (yPlaneCSER[(h * 4) * width + 0] * 3 + yPlaneCSER[(h * 4 + 4) * width + 0] * 1) / 4;
              yPlaneCSER[(h * 4 + 2) * width + 0] = (yPlaneCSER[(h * 4) * width + 0] * 2 + yPlaneCSER[(h * 4 + 4) * width + 0] * 2) / 4;
              yPlaneCSER[(h * 4 + 3) * width + 0] = (yPlaneCSER[(h * 4) * width + 0] * 1 + yPlaneCSER[(h * 4 + 4) * width + 0] * 3) / 4;
            } else {
              yPlaneCSER[(h * 4 + 1) * width + 0] = yPlaneCSER[(h * 4) * width + 0];
            }
          }
    }

}

/* kernel function */
__kernel void kernel_4(
  int const width,
  int const height,
  __global unsigned char * yPlaneCSER)
{
  /* kernel thread ID */
  const int tszx = get_local_size(0);
  const int tidx = get_local_id(0);
  const int bszx = get_num_groups(0);
  const int bidx = get_group_id(0);

  /* Local vars */

  /* kernel operation */
    {
      #pragma cap map threadblock([0:4]) thread([0:4]) 
        #pragma cap loop id(4) 
          for (int h = tszx * bidx + ( tidx ) ; h < height; h += tszx * bszx) {
            yPlaneCSER[(h) * width + 1] = yPlaneCSER[(h) * width + 0];
          }
    }

}

/* kernel function */
__kernel void kernel_5(
  __global unsigned char * yPlaneCSER,
  int const width,
  int const quarterWidth,
  __global unsigned char * const yPlaneDown)
{
  /* kernel thread ID */
  const int tszx = get_local_size(0);
  const int tidx = get_local_id(0);
  const int bszx = get_num_groups(0);
  const int bidx = get_group_id(0);

  /* Local vars */

  /* kernel operation */
    {
      #pragma cap map threadblock([0:5]) thread([0:5]) 
        #pragma cap loop id(5) 
          for (int w = tszx * bidx + ( tidx ) ; w < quarterWidth; w += tszx * bszx) {
            yPlaneCSER[0 * width + w * 4] = yPlaneDown[0 * quarterWidth + w];
          }
    }

}

/* kernel function */
__kernel void kernel_6(
  int const width,
  int const quarterWidth,
  __global unsigned char * yPlaneCSER)
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
          for (int w = tszx * bidx + ( tidx ) ; w < quarterWidth; w += tszx * bszx) {
            if (w < quarterWidth - 1) {
              yPlaneCSER[(0) * width + w * 4 + 1] = (yPlaneCSER[(0) * width + w * 4] * 3 + yPlaneCSER[(0) * width + w * 4 + 4] * 1) / 4;
              yPlaneCSER[(0) * width + w * 4 + 2] = (yPlaneCSER[(0) * width + w * 4] * 2 + yPlaneCSER[(0) * width + w * 4 + 4] * 2) / 4;
              yPlaneCSER[(0) * width + w * 4 + 3] = (yPlaneCSER[(0) * width + w * 4] * 1 + yPlaneCSER[(0) * width + w * 4 + 4] * 3) / 4;
            } else {
              yPlaneCSER[(0) * width + w * 4 + 1] = yPlaneCSER[(0) * width + w * 4];
            }
          }
    }

}

/* kernel function */
__kernel void kernel_7(
  int const width,
  __global unsigned char * yPlaneCSER)
{
  /* kernel thread ID */
  const int tszx = get_local_size(0);
  const int tidx = get_local_id(0);
  const int bszx = get_num_groups(0);
  const int bidx = get_group_id(0);

  /* Local vars */

  /* kernel operation */
    {
      #pragma cap map threadblock([0:7]) thread([0:7]) 
        #pragma cap loop id(7) 
          for (int w = tszx * bidx + ( tidx ) ; w < width; w += tszx * bszx) {
            yPlaneCSER[1 * width + w] = yPlaneCSER[0 * width + w];
          }
    }

}

/* kernel function */
__kernel void kernel_8(
  __global unsigned char * yPlaneCSER,
  int const width,
  int const height,
  int const quarterWidth,
  int const quarterHeight,
  __global unsigned char * const yPlaneDown)
{
  /* kernel thread ID */
  const int tszx = get_local_size(0);
  const int tidx = get_local_id(0);
  const int bszx = get_num_groups(0);
  const int bidx = get_group_id(0);

  /* Local vars */

  /* kernel operation */
    {
      #pragma cap map threadblock([0:8]) thread([0:8]) 
        #pragma cap loop id(8) 
          for (int w = tszx * bidx + ( tidx ) ; w < quarterWidth; w += tszx * bszx) {
            yPlaneCSER[(height - 2) * width + w * 4] = yPlaneDown[(quarterHeight - 1) * quarterWidth + w];
          }
    }

}

/* kernel function */
__kernel void kernel_9(
  int const width,
  int const height,
  int const quarterWidth,
  __global unsigned char * yPlaneCSER)
{
  /* kernel thread ID */
  const int tszx = get_local_size(0);
  const int tidx = get_local_id(0);
  const int bszx = get_num_groups(0);
  const int bidx = get_group_id(0);

  /* Local vars */

  /* kernel operation */
    {
      #pragma cap map threadblock([0:9]) thread([0:9]) 
        #pragma cap loop id(9) 
          for (int w = tszx * bidx + ( tidx ) ; w < quarterWidth; w += tszx * bszx) {
            if (w < quarterWidth - 1) {
              yPlaneCSER[(height - 2) * width + w * 4 + 1] = (yPlaneCSER[(height - 2) * width + w * 4] * 3 + yPlaneCSER[(height - 2) * width + w * 4 + 4] * 1) / 4;
              yPlaneCSER[(height - 2) * width + w * 4 + 2] = (yPlaneCSER[(height - 2) * width + w * 4] * 2 + yPlaneCSER[(height - 2) * width + w * 4 + 4] * 2) / 4;
              yPlaneCSER[(height - 2) * width + w * 4 + 3] = (yPlaneCSER[(height - 2) * width + w * 4] * 1 + yPlaneCSER[(height - 2) * width + w * 4 + 4] * 3) / 4;
            } else {
              yPlaneCSER[(height - 2) * width + w * 4 + 1] = yPlaneCSER[(height - 2) * width + w * 4];
            }
          }
    }

}

/* kernel function */
__kernel void kernel_10(
  int const width,
  int const height,
  __global unsigned char * yPlaneCSER)
{
  /* kernel thread ID */
  const int tszx = get_local_size(0);
  const int tidx = get_local_id(0);
  const int bszx = get_num_groups(0);
  const int bidx = get_group_id(0);

  /* Local vars */

  /* kernel operation */
    {
      #pragma cap map threadblock([0:10]) thread([0:10]) 
        #pragma cap loop id(10) 
          for (int w = tszx * bidx + ( tidx ) ; w < width; w += tszx * bszx) {
            yPlaneCSER[(height - 1) * width + w] = yPlaneCSER[(height - 2) * width + w];
          }
    }

}

/* kernel function */
__kernel void kernel_11(
  __global unsigned char * yPlaneCSER,
  int const width,
  int const quarterWidth,
  int const quarterHeight,
  __global unsigned char * const yPlaneDown)
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
          for (int h = tszx * bidx + ( tidx ) ; h < quarterHeight; h += tszx * bszx) {
            yPlaneCSER[(h * 4) * width + width - 2] = yPlaneDown[h * quarterWidth + quarterWidth - 1];
          }
    }

}

/* kernel function */
__kernel void kernel_12(
  int const width,
  int const quarterHeight,
  __global unsigned char * yPlaneCSER)
{
  /* kernel thread ID */
  const int tszx = get_local_size(0);
  const int tidx = get_local_id(0);
  const int bszx = get_num_groups(0);
  const int bidx = get_group_id(0);

  /* Local vars */

  /* kernel operation */
    {
      #pragma cap map threadblock([0:12]) thread([0:12]) 
        #pragma cap loop id(12) 
          for (int h = tszx * bidx + ( tidx ) ; h < quarterHeight; h += tszx * bszx) {
            if (h < quarterHeight - 1) {
              yPlaneCSER[(h * 4 + 1) * width + width - 2] = (yPlaneCSER[(h * 4) * width + width - 2] * 3 + yPlaneCSER[(h * 4 + 4) * width + width - 2] * 1) / 4;
              yPlaneCSER[(h * 4 + 2) * width + width - 2] = (yPlaneCSER[(h * 4) * width + width - 2] * 2 + yPlaneCSER[(h * 4 + 4) * width + width - 2] * 2) / 4;
              yPlaneCSER[(h * 4 + 3) * width + width - 2] = (yPlaneCSER[(h * 4) * width + width - 2] * 1 + yPlaneCSER[(h * 4 + 4) * width + width - 2] * 3) / 4;
            } else {
              yPlaneCSER[(h * 4 + 1) * width + width - 2] = yPlaneCSER[(h * 4) * width + width - 2];
              yPlaneCSER[(h * 4 + 2) * width + width - 2] = yPlaneCSER[(h * 4) * width + width - 2];
              yPlaneCSER[(h * 4 + 3) * width + width - 2] = yPlaneCSER[(h * 4) * width + width - 2];
            }
          }
    }

}

/* kernel function */
__kernel void kernel_13(
  int const width,
  int const height,
  __global unsigned char * yPlaneCSER)
{
  /* kernel thread ID */
  const int tszx = get_local_size(0);
  const int tidx = get_local_id(0);
  const int bszx = get_num_groups(0);
  const int bidx = get_group_id(0);

  /* Local vars */

  /* kernel operation */
    {
      #pragma cap map threadblock([0:13]) thread([0:13]) 
        #pragma cap loop id(13) 
          for (int h = tszx * bidx + ( tidx ) ; h < height; h += tszx * bszx) {
            yPlaneCSER[(h) * width + width - 1] = yPlaneCSER[(h) * width + width - 2];
          }
    }

}

/* kernel function */
__kernel void kernel_14(
  __global unsigned char * yPlaneCSER,
  int const width,
  int const quarterWidth,
  int const quarterHeight,
  __global unsigned char * const yPlaneDown)
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
      #pragma cap map threadblock([0:15][1:14]) thread([0:15][1:14]) 
        #pragma cap loop id(14) 
          for (int h = tszy * bidy + ( tidy ) ; h < quarterHeight - 1; h += tszy * bszy) {
            #pragma cap loop id(15) 
              for (int w = tszx * bidx + ( tidx ) ; w < quarterWidth - 1; w += tszx * bszx) {
                yPlaneCSER[(h * 4 + 2) * width + w * 4 + 2] = (yPlaneDown[(h) * quarterWidth + w] * 7 + yPlaneDown[(h) * quarterWidth + w + 1] * 1) * 7 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 7 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 1) / 8 / 8;
                yPlaneCSER[(h * 4 + 2) * width + w * 4 + 2 + 1] = (yPlaneDown[(h) * quarterWidth + w] * 5 + yPlaneDown[(h) * quarterWidth + w + 1] * 3) * 7 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 5 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 3) / 8 / 8;
                yPlaneCSER[(h * 4 + 2) * width + w * 4 + 2 + 2] = (yPlaneDown[(h) * quarterWidth + w] * 3 + yPlaneDown[(h) * quarterWidth + w + 1] * 5) * 7 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 3 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 5) / 8 / 8;
                yPlaneCSER[(h * 4 + 2) * width + w * 4 + 2 + 3] = (yPlaneDown[(h) * quarterWidth + w] * 1 + yPlaneDown[(h) * quarterWidth + w + 1] * 7) * 7 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 1 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 7) / 8 / 8;
                yPlaneCSER[(h * 4 + 3) * width + w * 4 + 2] = (yPlaneDown[(h) * quarterWidth + w] * 7 + yPlaneDown[(h) * quarterWidth + w + 1] * 1) * 5 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 7 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 1) * 3 / 8 / 8;
                yPlaneCSER[(h * 4 + 3) * width + w * 4 + 2 + 1] = (yPlaneDown[(h) * quarterWidth + w] * 5 + yPlaneDown[(h) * quarterWidth + w + 1] * 3) * 5 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 5 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 3) * 3 / 8 / 8;
                yPlaneCSER[(h * 4 + 3) * width + w * 4 + 2 + 2] = (yPlaneDown[(h) * quarterWidth + w] * 3 + yPlaneDown[(h) * quarterWidth + w + 1] * 5) * 5 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 3 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 5) * 3 / 8 / 8;
                yPlaneCSER[(h * 4 + 3) * width + w * 4 + 2 + 3] = (yPlaneDown[(h) * quarterWidth + w] * 1 + yPlaneDown[(h) * quarterWidth + w + 1] * 7) * 5 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 1 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 7) * 3 / 8 / 8;
                yPlaneCSER[(h * 4 + 4) * width + w * 4 + 2] = (yPlaneDown[(h) * quarterWidth + w] * 7 + yPlaneDown[(h) * quarterWidth + w + 1] * 1) * 3 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 7 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 1) * 5 / 8 / 8;
                yPlaneCSER[(h * 4 + 4) * width + w * 4 + 2 + 1] = (yPlaneDown[(h) * quarterWidth + w] * 5 + yPlaneDown[(h) * quarterWidth + w + 1] * 3) * 3 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 5 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 3) * 5 / 8 / 8;
                yPlaneCSER[(h * 4 + 4) * width + w * 4 + 2 + 2] = (yPlaneDown[(h) * quarterWidth + w] * 3 + yPlaneDown[(h) * quarterWidth + w + 1] * 5) * 3 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 3 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 5) * 5 / 8 / 8;
                yPlaneCSER[(h * 4 + 4) * width + w * 4 + 2 + 3] = (yPlaneDown[(h) * quarterWidth + w] * 1 + yPlaneDown[(h) * quarterWidth + w + 1] * 7) * 3 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 1 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 7) * 5 / 8 / 8;
                yPlaneCSER[(h * 4 + 5) * width + w * 4 + 2] = (yPlaneDown[(h) * quarterWidth + w] * 7 + yPlaneDown[(h) * quarterWidth + w + 1] * 1) * 1 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 7 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 1) * 7 / 8 / 8;
                yPlaneCSER[(h * 4 + 5) * width + w * 4 + 2 + 1] = (yPlaneDown[(h) * quarterWidth + w] * 5 + yPlaneDown[(h) * quarterWidth + w + 1] * 3) * 1 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 5 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 3) * 7 / 8 / 8;
                yPlaneCSER[(h * 4 + 5) * width + w * 4 + 2 + 2] = (yPlaneDown[(h) * quarterWidth + w] * 3 + yPlaneDown[(h) * quarterWidth + w + 1] * 5) * 1 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 3 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 5) * 7 / 8 / 8;
                yPlaneCSER[(h * 4 + 5) * width + w * 4 + 2 + 3] = (yPlaneDown[(h) * quarterWidth + w] * 1 + yPlaneDown[(h) * quarterWidth + w + 1] * 7) * 1 / 8 / 8 + (yPlaneDown[(h + 1) * quarterWidth + w] * 1 + yPlaneDown[(h + 1) * quarterWidth + w + 1] * 7) * 7 / 8 / 8;
              }
          }
    }

}

/* kernel function */
__kernel void kernel_15(
  __global short * pError,
  int const width,
  int const height,
  __global unsigned char * const yPlane,
  __global unsigned char * const yPlaneCSER)
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
      #pragma cap map threadblock([0:17][1:16]) thread([0:17][1:16]) 
        #pragma cap loop id(16) 
          for (int h = tszy * bidy + ( tidy ) ; h < height; h += tszy * bszy) {
            #pragma cap loop id(17) 
              for (int w = tszx * bidx + ( tidx ) ; w < width; w += tszx * bszx) {
                pError[h * width + w] = yPlane[h * width + w] - yPlaneCSER[h * width + w];
              }
          }
    }

}

/* kernel function */
__kernel void kernel_16(
  __global short * pEdge,
  int const width,
  int const height,
  __global unsigned char * const yPlane)
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
      #pragma cap map threadblock([0:19][1:18]) thread([0:19][1:18]) 
        #pragma cap loop id(18) 
          for (int y = tszy * bidy + ( tidy ) ; y < height; y += tszy * bszy) {
            #pragma cap loop id(19) 
              for (int x = tszx * bidx + ( tidx ) ; x < width; x += tszx * bszx) {
                if (y == 0 || y == height - 1 || x == 0 || x == width - 1) {
                  pEdge[y * width + x] = 0;
                } else {
                  int gx = (yPlane[(y - 1) * width + x + 1] + ((int)yPlane[(y) * width + x + 1] << 1) + yPlane[(y + 1) * width + x + 1]) - (yPlane[(y - 1) * width + x - 1] + ((int)yPlane[(y) * width + x - 1] << 1) + yPlane[(y + 1) * width + x - 1]);
                  int gy = (yPlane[(y - 1) * width + x - 1] + ((int)yPlane[(y - 1) * width + x] << 1) + yPlane[(y - 1) * width + x + 1]) - (yPlane[(y + 1) * width + x - 1] + ((int)yPlane[(y + 1) * width + x] << 1) + yPlane[(y + 1) * width + x + 1]);
                  int edgeV = (abs(gx) + abs(gy));
                  pEdge[y * width + x] = edgeV;
                }
              }
          }
    }

}

/* kernel function */
__kernel void kernel_17(
  int const width,
  int const height,
  __global short * const pEdge,
  __global long * sum,
  __local char * localBuffer)
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
  const int tszz = get_local_size(2);
  const int tsz = tszx * tszy * tszz;
  const int tidz = get_local_id(2);
  const int tid = tidz * tszx * tszy + tidy * tszx + tidx;

  /* Local vars */
  long tmpsum20 = 0;
  __local long * localsum20 = ( __local long* )(localBuffer + (0 * tsz));

  /* kernel operation */
    {
      #pragma cap map threadblock([0:21][1:20]) thread([0:21][1:20]) 
        #pragma cap loop id(20) reduction(+: sum) 
          for (int i = tszy * bidy + ( tidy ) ; i < height; i += tszy * bszy) {
            #pragma cap loop id(21) 
              for (int j = tszx * bidx + ( tidx ) ; j < width; j += tszx * bszx) {
                tmpsum20 += pEdge[i * width + j];
              }
          }
            localsum20[tid] = tmpsum20;
      barrier(CLK_LOCAL_MEM_FENCE);

      if(tsz >= 1024)
      {
            if(tid < 512)
            {
                  localsum20[tid] = localsum20[tid] + localsum20[tid + 512];
            }
            barrier(CLK_LOCAL_MEM_FENCE);
      }

      if(tsz >= 512)
      {
            if(tid < 256)
            {
                  localsum20[tid] = localsum20[tid] + localsum20[tid + 256];
            }
            barrier(CLK_LOCAL_MEM_FENCE);
      }

      if(tsz >= 256)
      {
            if(tid < 128)
            {
                  localsum20[tid] = localsum20[tid] + localsum20[tid + 128];
            }
            barrier(CLK_LOCAL_MEM_FENCE);
      }

      if(tsz >= 128)
      {
            if(tid < 64)
            {
                  localsum20[tid] = localsum20[tid] + localsum20[tid + 64];
            }
            barrier(CLK_LOCAL_MEM_FENCE);
      }

      if(tid < 32)
      {
            if(tsz >= 64)
            {
                  localsum20[tid] = localsum20[tid] + localsum20[tid + 32];
            }
            if(tsz >= 32)
            {
                  localsum20[tid] = localsum20[tid] + localsum20[tid + 16];
            }
            if(tsz >= 16)
            {
                  localsum20[tid] = localsum20[tid] + localsum20[tid + 8];
            }
            if(tsz >= 8)
            {
                  localsum20[tid] = localsum20[tid] + localsum20[tid + 4];
            }
            if(tsz >= 4)
            {
                  localsum20[tid] = localsum20[tid] + localsum20[tid + 2];
            }
            if(tsz >= 2)
            {
                  localsum20[tid] = localsum20[tid] + localsum20[tid + 1];
            }

            if(tid == 0)
            {
                  atom_add(sum, localsum20[0]);
            }
      }
      barrier(CLK_LOCAL_MEM_FENCE);
    }

}

/* kernel function */
__kernel void kernel_18(
  int const width,
  int const height,
  __global unsigned char * const yPlaneCSER,
  __global short * const pError,
  __global short * const pEdge,
  double const cutoff,
  double const peak,
  double const cutoff2,
  double const order,
  double const order2,
  double const low,
  __global short * pSharpness)
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
      #pragma cap map threadblock([0:23][1:22]) thread([0:23][1:22]) 
        #pragma cap loop id(22) 
          for (int h = tszy * bidy + ( tidy ) ; h < height; h += tszy * bszy) {
            #pragma cap loop id(23) 
              for (int w = tszx * bidx + ( tidx ) ; w < width; w += tszx * bszx) {
                short edge = pEdge[h * width + w];
                double weight = 1 / (1 + native_powr((float)(edge / cutoff2), (float)(2 * order2)));
                double strength = (peak - low) * (1 - 1 / (1 + native_powr((float)(edge / cutoff), (float)(2 * order))));
                strength = strength * weight + low;
                pSharpness[h * width + w] = (yPlaneCSER[h * width + w]);
                pSharpness[h * width + w] += (double)(pError[h * width + w]) * strength;
              }
          }
    }

}

/* kernel function */
__kernel void kernel_19(
  int const width,
  int const height,
  __global unsigned char * const yPlane,
  __global short * const pEdge,
  float const cutoff3,
  float const order3,
  float const peak3,
  float const low3,
  __global short * pSharpness)
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
      #pragma cap map threadblock([0:25][1:24]) thread([0:25][1:24]) 
        #pragma cap loop id(24) 
          for (int h = tszy * bidy + ( tidy ) ; h < height; h += tszy * bszy) {
            #pragma cap loop id(25) 
              for (int w = tszx * bidx + ( tidx ) ; w < width; w += tszx * bszx) {
                if (!(h == 0 || h == height - 1 || w == 0 || w == width - 1)) {
                  int enhanced, maxValue, minValue;
                  double oscStrength;
                  enhanced = pSharpness[h * width + w];
                  maxValue = ((((yPlane[(h - 1) * width + w - 1]) > (yPlane[(h - 1) * width + w]) ? (yPlane[(h - 1) * width + w - 1]) : (yPlane[(h - 1) * width + w]))) > (yPlane[(h - 1) * width + w + 1]) ? (((yPlane[(h - 1) * width + w - 1]) > (yPlane[(h - 1) * width + w]) ? (yPlane[(h - 1) * width + w - 1]) : (yPlane[(h - 1) * width + w]))) : (yPlane[(h - 1) * width + w + 1]));
                  maxValue = ((maxValue) > (((((yPlane[(h) * width + w - 1]) > (yPlane[(h) * width + w]) ? (yPlane[(h) * width + w - 1]) : (yPlane[(h) * width + w]))) > (yPlane[(h) * width + w + 1]) ? (((yPlane[(h) * width + w - 1]) > (yPlane[(h) * width + w]) ? (yPlane[(h) * width + w - 1]) : (yPlane[(h) * width + w]))) : (yPlane[(h) * width + w + 1]))) ? (maxValue) : (((((yPlane[(h) * width + w - 1]) > (yPlane[(h) * width + w]) ? (yPlane[(h) * width + w - 1]) : (yPlane[(h) * width + w]))) > (yPlane[(h) * width + w + 1]) ? (((yPlane[(h) * width + w - 1]) > (yPlane[(h) * width + w]) ? (yPlane[(h) * width + w - 1]) : (yPlane[(h) * width + w]))) : (yPlane[(h) * width + w + 1]))));
                  maxValue = ((maxValue) > (((((yPlane[(h + 1) * width + w - 1]) > (yPlane[(h + 1) * width + w]) ? (yPlane[(h + 1) * width + w - 1]) : (yPlane[(h + 1) * width + w]))) > (yPlane[(h + 1) * width + w + 1]) ? (((yPlane[(h + 1) * width + w - 1]) > (yPlane[(h + 1) * width + w]) ? (yPlane[(h + 1) * width + w - 1]) : (yPlane[(h + 1) * width + w]))) : (yPlane[(h + 1) * width + w + 1]))) ? (maxValue) : (((((yPlane[(h + 1) * width + w - 1]) > (yPlane[(h + 1) * width + w]) ? (yPlane[(h + 1) * width + w - 1]) : (yPlane[(h + 1) * width + w]))) > (yPlane[(h + 1) * width + w + 1]) ? (((yPlane[(h + 1) * width + w - 1]) > (yPlane[(h + 1) * width + w]) ? (yPlane[(h + 1) * width + w - 1]) : (yPlane[(h + 1) * width + w]))) : (yPlane[(h + 1) * width + w + 1]))));
                  minValue = ((((yPlane[(h - 1) * width + w - 1])) < ((((yPlane[(h - 1) * width + w])) < ((yPlane[(h - 1) * width + w + 1])) ? ((yPlane[(h - 1) * width + w])) : ((yPlane[(h - 1) * width + w + 1])))) ? ((yPlane[(h - 1) * width + w - 1])) : ((((yPlane[(h - 1) * width + w])) < ((yPlane[(h - 1) * width + w + 1])) ? ((yPlane[(h - 1) * width + w])) : ((yPlane[(h - 1) * width + w + 1]))))));
                  minValue = ((minValue) < (((((yPlane[(h) * width + w - 1])) < ((((yPlane[(h) * width + w])) < ((yPlane[(h) * width + w + 1])) ? ((yPlane[(h) * width + w])) : ((yPlane[(h) * width + w + 1])))) ? ((yPlane[(h) * width + w - 1])) : ((((yPlane[(h) * width + w])) < ((yPlane[(h) * width + w + 1])) ? ((yPlane[(h) * width + w])) : ((yPlane[(h) * width + w + 1]))))))) ? (minValue) : (((((yPlane[(h) * width + w - 1])) < ((((yPlane[(h) * width + w])) < ((yPlane[(h) * width + w + 1])) ? ((yPlane[(h) * width + w])) : ((yPlane[(h) * width + w + 1])))) ? ((yPlane[(h) * width + w - 1])) : ((((yPlane[(h) * width + w])) < ((yPlane[(h) * width + w + 1])) ? ((yPlane[(h) * width + w])) : ((yPlane[(h) * width + w + 1]))))))));
                  minValue = ((minValue) < (((((yPlane[(h + 1) * width + w - 1])) < ((((yPlane[(h + 1) * width + w])) < ((yPlane[(h + 1) * width + w + 1])) ? ((yPlane[(h + 1) * width + w])) : ((yPlane[(h + 1) * width + w + 1])))) ? ((yPlane[(h + 1) * width + w - 1])) : ((((yPlane[(h + 1) * width + w])) < ((yPlane[(h + 1) * width + w + 1])) ? ((yPlane[(h + 1) * width + w])) : ((yPlane[(h + 1) * width + w + 1]))))))) ? (minValue) : (((((yPlane[(h + 1) * width + w - 1])) < ((((yPlane[(h + 1) * width + w])) < ((yPlane[(h + 1) * width + w + 1])) ? ((yPlane[(h + 1) * width + w])) : ((yPlane[(h + 1) * width + w + 1])))) ? ((yPlane[(h + 1) * width + w - 1])) : ((((yPlane[(h + 1) * width + w])) < ((yPlane[(h + 1) * width + w + 1])) ? ((yPlane[(h + 1) * width + w])) : ((yPlane[(h + 1) * width + w + 1]))))))));
                  {
                    double cutoff2Order = native_powr(cutoff3, 2 * order3);
                    double edge2Order = native_powr((float)((double)(pEdge[h * width + w])), (float)((double)2 * order3));
                    oscStrength = (peak3 * cutoff2Order + low3 * edge2Order) / (cutoff2Order + edge2Order);
                  }
                  if (enhanced > maxValue) {
                    pSharpness[h * width + w] = ((maxValue + oscStrength * (enhanced - maxValue)) < (255) ? (maxValue + oscStrength * (enhanced - maxValue)) : (255));
                  } else if (enhanced < minValue) {
                    pSharpness[h * width + w] = ((0) > (minValue - oscStrength * (minValue - enhanced)) ? (0) : (minValue - oscStrength * (minValue - enhanced)));
                  } else {
                    pSharpness[h * width + w] = ((((enhanced) > (0) ? (enhanced) : (0))) < (255) ? (((enhanced) > (0) ? (enhanced) : (0))) : (255));
                  }
                }
              }
          }
    }

}

/* kernel function */
__kernel void kernel_20(
  __global unsigned char * yPlane,
  int const width,
  int const height,
  __global short * const pSharpness)
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
      #pragma cap map threadblock([0:27][1:26]) thread([0:27][1:26]) 
        #pragma cap loop id(26) 
          for (int h = tszy * bidy + ( tidy ) ; h < height; h += tszy * bszy) {
            #pragma cap loop id(27) 
              for (int w = tszx * bidx + ( tidx ) ; w < width; w += tszx * bszx) {
                yPlane[h * width + w] = pSharpness[h * width + w] > 255 ? 255 : pSharpness[h * width + w] < 0 ? 0 : pSharpness[h * width + w];
              }
          }
    }

}

