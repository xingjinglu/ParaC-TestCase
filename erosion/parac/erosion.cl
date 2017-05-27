/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

/* kernel function */
__kernel void kernel_1(
  int height,
  int width,
  __global unsigned char* const srcSrc,
  int srcSrcWidth,
  int srcSrcHeight,
  int srcSrcStep,
  int srcSrcShift,
  int mid,
  __global unsigned char *dstDst,
  int dstDstWidth,
  int dstDstHeight,
  int dstDstStep,
  int dstDstShift,
  __global unsigned char *val)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if ( gidx >= (width - mid - 1 - mid )/ 1 || gidy >= (height - mid - 1 - mid )/ 1 )
    return;

  /* kernel index calculation */
  int srcSrcIdx3 = srcSrcShift + (int)(((float)gidy + mid) *srcSrcStep) + (int)(((float)gidx + mid) *sizeof(unsigned char));
  int srcSrcIdx4 = srcSrcShift + (int)(((float)gidy + mid) *srcSrcStep) + (int)(((float)gidx + 1 + mid) *sizeof(unsigned char));
  int srcSrcIdx5 = srcSrcShift + (int)(((float)gidy + mid) *srcSrcStep) + (int)(((float)gidx + 2 + mid) *sizeof(unsigned char));
  int srcSrcIdx6 = srcSrcShift + (int)(((float)gidy + 1 + mid) *srcSrcStep) + (int)(((float)gidx + mid) *sizeof(unsigned char));
  int srcSrcIdx7 = srcSrcShift + (int)(((float)gidy + 1 + mid) *srcSrcStep) + (int)(((float)gidx + 1 + mid) *sizeof(unsigned char));
  int srcSrcIdx8 = srcSrcShift + (int)(((float)gidy + 1 + mid) *srcSrcStep) + (int)(((float)gidx + 2 + mid) *sizeof(unsigned char));
  int srcSrcIdx9 = srcSrcShift + (int)(((float)gidy + 2 + mid) *srcSrcStep) + (int)(((float)gidx + mid) *sizeof(unsigned char));
  int srcSrcIdx10 = srcSrcShift + (int)(((float)gidy + 2 + mid) *srcSrcStep) + (int)(((float)gidx + 1 + mid) *sizeof(unsigned char));
  int srcSrcIdx11 = srcSrcShift + (int)(((float)gidy + 2 + mid) *srcSrcStep) + (int)(((float)gidx + 2 + mid) *sizeof(unsigned char));
  int dstDstIdx1 = dstDstShift + (int)(((float)gidy + mid) *dstDstStep) + (int)(((float)gidx + mid) *sizeof(unsigned char));

  /* kernel operands */
  __global unsigned char *srcSrcDt3 = srcSrc + srcSrcIdx3;
  __global unsigned char *srcSrcDt4 = srcSrc + srcSrcIdx4;
  __global unsigned char *srcSrcDt5 = srcSrc + srcSrcIdx5;
  __global unsigned char *srcSrcDt6 = srcSrc + srcSrcIdx6;
  __global unsigned char *srcSrcDt7 = srcSrc + srcSrcIdx7;
  __global unsigned char *srcSrcDt8 = srcSrc + srcSrcIdx8;
  __global unsigned char *srcSrcDt9 = srcSrc + srcSrcIdx9;
  __global unsigned char *srcSrcDt10 = srcSrc + srcSrcIdx10;
  __global unsigned char *srcSrcDt11 = srcSrc + srcSrcIdx11;
  __global unsigned char *dstDstDt1 = dstDst + dstDstIdx1;

  /* kernel operation */
  {
    uchar tval; //= *val;
    uchar tDt3 = *srcSrcDt3;
    //*dstDstDt1 = tDt3;

#if 1
    if (gidy < mid || gidy > height - mid - 1) {
             //*dstDstDt1 = *srcSrcDt3;
                *dstDstDt1 = tDt3;
             return;
          } else if (gidx < mid || gidx > width - mid - 1) {
             //*dstDstDt1 = *srcSrcDt3;
             dstDstDt1 = tDt3;
             return;
          } else 
#endif
  //  if( gidy >= mid && gidy <= (height-mid-1) && gidx >= mid && gidx <= (width-mid-1) )
       {
       tval = *val;
      //tval = tval & (*(srcSrcDt3));
      tval = tval & tDt3; //(*(srcSrcDt3));
      //tval = tval &  *(srcSrcDt4);
      tval = tval & *(srcSrcDt5);
      tval = tval & *(srcSrcDt6);
      tval = tval & *(srcSrcDt7);
      tval = tval & *(srcSrcDt8);
      tval = tval & *(srcSrcDt9);
      tval = tval & *(srcSrcDt10);
      tval = tval & *(srcSrcDt11);
             *dstDstDt1 = tval;
#if 0
      *val = *val & (*(srcSrcDt3));
      *val = *val &  *(srcSrcDt4);
      *val = *val & *(srcSrcDt5);
      *val = *val & *(srcSrcDt6);
      *val = *val & *(srcSrcDt7);
      *val = *val & *(srcSrcDt8);
      *val = *val & *(srcSrcDt9);
      *val = *val & *(srcSrcDt10);
      *val = *val & *(srcSrcDt11);
             *dstDstDt1 = val;
#endif
    }
  }

}

