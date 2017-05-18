/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

/* kernel function */
__kernel void kernel_1(
  int width,
  __global unsigned char* const srcSrc,
  int srcSrcWidth,
  int srcSrcHeight,
  int srcSrcStep,
  int srcSrcShift,
  int mid,
  unsigned char val,
  __global unsigned char *dstDst,
  int dstDstWidth,
  int dstDstHeight,
  int dstDstStep,
  int dstDstShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if ( gidx >= (width - mid - 1 - mid )/ 1 || gidy >= (height - mid - 1 - mid )/ 1 )
    return;

  /* kernel index calculation */
  int srcSrcIdx2 = srcSrcShift + (int)(((float)gidy + mid) *srcSrcStep) + (int)(((float)gidx + mid) *sizeof(unsigned char));
  int dstDstIdx1 = dstDstShift + (int)(((float)gidy + mid) *dstDstStep) + (int)(((float)gidx + mid) *sizeof(unsigned char));

  /* kernel operands */
  __global unsigned char *srcSrcDt2 = srcSrc + srcSrcIdx2;
  __global unsigned char *dstDstDt1 = dstDst + dstDstIdx1;

  /* kernel operation */
  {
    if (gidy < mid || gidy > width - mid - 1) {
             *dstDstDt1 = *srcSrcDt2;
          } else if (gidx < mid || gidx > width - mid - 1) {
             *dstDstDt1 = *srcSrcDt2;
          } else {
      val |= (*src)[itx][ity];
      val |= (*src)[itx][ity + 1];
      val |= (*src)[itx][ity + 2];
      val |= (*src)[itx + 1][ity];
      val |= (*src)[itx + 1][ity + 1];
      val |= (*src)[itx + 1][ity + 2];
      val |= (*src)[itx + 2][ity];
      val |= (*src)[itx + 2][ity + 1];
      val |= (*src)[itx + 2][ity + 2];
            *dstDstDt1 = val;
    }
  }

}

