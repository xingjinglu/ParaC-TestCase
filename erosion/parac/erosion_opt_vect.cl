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
  int vectlen = 4;
  int srcSrcIdx3 = srcSrcShift + (int)(((float)gidy + mid) *srcSrcStep) + (int)(((float)gidx*4 + mid) *sizeof(unsigned char));
  int srcSrcIdx6 = srcSrcShift + (int)(((float)gidy + 1 + mid) *srcSrcStep) + (int)(((float)gidx*4 + mid) *sizeof(unsigned char));
  int srcSrcIdx9 = srcSrcShift + (int)(((float)gidy + 2 + mid) *srcSrcStep) + (int)(((float)gidx*4 + mid) *sizeof(unsigned char));
  int dstDstIdx1 = dstDstShift + (int)(((float)gidy + mid) *dstDstStep) + (int)(((float)gidx*4 + mid) *sizeof(unsigned char));

  /* kernel operands */
  __global unsigned char *srcSrcDt3 = srcSrc + srcSrcIdx3;
  __global unsigned char *srcSrcDt6 = srcSrc + srcSrcIdx6;
  __global unsigned char *srcSrcDt9 = srcSrc + srcSrcIdx9;

  __global unsigned char *dstDstDt1 = dstDst + dstDstIdx1;

  /* kernel operation */
  {
    uchar tval = *val;
    unsigned char temp;
    uchar8 src1 = vload8(0, srcSrcDt3);
    uchar8 src2 = vload8(0, srcSrcDt6);
    uchar8 src3 = vload8(0, srcSrcDt9);
    uchar4 res;
    *dstDstDt1 = src1.s0;

#if 1

    
    //else 
#endif

    //if( gidy >= mid && gidy <= (height-mid-1) && gidx >= mid && gidx <= (width-mid-1) )

    {

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
      *dstDstDt1 = *val;
#endif
#if 1
      tval = tval & src1.s0; //*(srcSrcDt3);
      tval = tval & src1.s1; //*(srcSrcDt4);
      tval = tval & src1.s2; //*(srcSrcDt5);
      tval = tval & src2.s0; //*(srcSrcDt6);
      tval = tval & src2.s1; //*(srcSrcDt7);
      tval = tval & src2.s2; //*(srcSrcDt8);
      tval = tval & src3.s0; //*(srcSrcDt9);
      tval = tval & src3.s1; //*(srcSrcDt10);
      tval = tval & src3.s2; //*(srcSrcDt11);
      res.s0 = tval;

 tval = 255 & src1.s1; //*(srcSrcDt3);
      tval = tval & src1.s2; //*(srcSrcDt4);
      tval = tval & src1.s3; //*(srcSrcDt5);
      tval = tval & src2.s1; //*(srcSrcDt6);
      tval = tval & src2.s2; //*(srcSrcDt7);
      tval = tval & src2.s3; //*(srcSrcDt8);
      tval = tval & src3.s1; //*(srcSrcDt9);
      tval = tval & src3.s2; //*(srcSrcDt10);
      tval = tval & src3.s3; //*(srcSrcDt11);
      res.s1 = tval;

 tval = 255 & src1.s2; //*(srcSrcDt3);
      tval = tval & src1.s3; //*(srcSrcDt4);
      tval = tval & src1.s4; //*(srcSrcDt5);
      tval = tval & src2.s2; //*(srcSrcDt6);
      tval = tval & src2.s3; //*(srcSrcDt7);
      tval = tval & src2.s4; //*(srcSrcDt8);
      tval = tval & src3.s2; //*(srcSrcDt9);
      tval = tval & src3.s3; //*(srcSrcDt10);
      tval = tval & src3.s4; //*(srcSrcDt11);
      res.s2 = tval;

 tval = 255 & src1.s3; //*(srcSrcDt3);
      tval = tval & src1.s4; //*(srcSrcDt4);
      tval = tval & src1.s5; //*(srcSrcDt5);
      tval = tval & src2.s3; //*(srcSrcDt6);
      tval = tval & src2.s4; //*(srcSrcDt7);
      tval = tval & src2.s5; //*(srcSrcDt8);
      tval = tval & src3.s3; //*(srcSrcDt9);
      tval = tval & src3.s4; //*(srcSrcDt10);
      tval = tval & src3.s5; //*(srcSrcDt11);
      res.s3 = tval;


      //*dstDstDt1 = tval;
      vstore4(res, 0, dstDstDt1);
#endif
    }
    if (gidy < mid || gidy > height - mid - 1) {
    *dstDstDt1 = src1.s0; //*srcSrcDt3;
    } 
    else if (gidx < mid || gidx > width - mid - 1) {
    *dstDstDt1 = src1.s0; //*srcSrcDt3;
    } 
    else;


  }

}

