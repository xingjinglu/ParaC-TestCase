/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

/* kernel function */
__kernel void kernel_1(
  __global float* const imgSrc,
  int imgSrcWidth,
  int imgSrcHeight,
  int imgSrcStep,
  int imgSrcShift,
  __global float* const filterxSrc,
  int filterxSrcWidth,
  int filterxSrcHeight,
  int filterxSrcStep,
  int filterxSrcShift,
  __global float *blurxDst,
  int blurxDstWidth,
  int blurxDstHeight,
  int blurxDstStep,
  int blurxDstShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  //if ( gidx >= 2051 || gidy >= 2047 )
  if ( gidx >= 257 || gidy >= 2047 )
    return;

  /* kernel index calculation */
  int imgSrcIdx2 = imgSrcShift + (int)(((float)gidy + -2 + 2) *imgSrcStep) + (int)(((float)gidx)* 8 *sizeof(float));
  int blurxDstIdx1 = blurxDstShift + (int)(((float)gidy + -2 + 2) *blurxDstStep) + (int)(((float)gidx) * 8 *sizeof(float));

  /* kernel operands */
  __global float *imgSrcDt2 = (__global char *)imgSrc + imgSrcIdx2;
  __global float *blurxDstDt1 = (__global char *)blurxDst + blurxDstIdx1;

  /* kernel operation */
  {
    float8 img0, img1, img2, img3, img4;
    float8 res1;
    {
    img0 = (convert_float8)(*((__global float8*) ((__global char*) imgSrcDt2 )));
    img1 = (convert_float8)(*((__global float8*) ((__global char*) imgSrcDt2 + imgSrcStep*1  )));
    img2 = (convert_float8)(*((__global float8*) ((__global char*) imgSrcDt2 + imgSrcStep*2)));
    img3 = (convert_float8)(*((__global float8*) ((__global char*) imgSrcDt2 + imgSrcStep*3)));
    img4 = (convert_float8)(*((__global float8*) ((__global char*) imgSrcDt2 + imgSrcStep*4)));
    res1 = img0 * 0.0625 + img1 * 0.25 +  img2 * 0.375 + img3 * 0.25 + img4 * 0.0625; 
  }
    *((__global float8*)blurxDstDt1) = res1;
  }

}

/* kernel function */
__kernel void kernel_2(
  __global float* const blurxSrc,
  int blurxSrcWidth,
  int blurxSrcHeight,
  int blurxSrcStep,
  int blurxSrcShift,
  __global float* const filterySrc,
  int filterySrcWidth,
  int filterySrcHeight,
  int filterySrcStep,
  int filterySrcShift,
  __global float *bluryDst,
  int bluryDstWidth,
  int bluryDstHeight,
  int bluryDstStep,
  int bluryDstShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if ( gidx >= (2047/4) || gidy >= 2047 )
    return;

  /* kernel index calculation */
  int blurxSrcIdx1 = blurxSrcShift + (int)(((float)gidy + -2 + 2) *blurxSrcStep) + (int)(((float)gidx *4 + -2 + 2) *sizeof(float));
  int bluryDstIdx1 = bluryDstShift + (int)(((float)gidy + -2 + 2) *bluryDstStep) + (int)(((float)gidx *4 + -2 + 2) *sizeof(float));

  /* kernel operands */
  __global float *blurxSrcDt1 = (__global char *)blurxSrc + blurxSrcIdx1;
  //__global float *filterySrcDt2 = (__global char *)filterySrc + filterySrcShift;
  __global float *bluryDstDt1 = (__global char *)bluryDst + bluryDstIdx1;

  /* kernel operation */
  {
        float8 blurx;
    float blurxNext;
    //float filtery[5];
    float4 res1;
    {
      //blurx = vload4(0, (__global float*) ( (__global char*)(blurxSrcDt1) + 0 * blurxSrcStep + 4 * 0 * sizeof(float)));
      blurx = (convert_float8)(*((__global float8*) ( (__global char*)(blurxSrcDt1) + 0 * blurxSrcStep + 4 * 0 * sizeof(float))));
      res1.s0 = blurx.s0 * 0.0625 + blurx.s1 * 0.25 + blurx.s2 * 0.375 + blurx.s3 * 0.25 + blurx.s4 * 0.0625; 
      res1.s1 = blurx.s1 * 0.0625 + blurx.s2 * 0.25 + blurx.s3 * 0.375 + blurx.s4 * 0.25 + blurx.s5 * 0.0625; 
      res1.s2 = blurx.s2 * 0.0625 + blurx.s3 * 0.25 + blurx.s4 * 0.375 + blurx.s5 * 0.25  + blurx.s6 * 0.0625; 
      res1.s3 = blurx.s3 * 0.0625 + blurx.s4 * 0.25 + blurx.s5 * 0.375 + blurx.s6 * 0.25 +  blurx.s7 * 0.0625; 
    }
    *((__global float4*)bluryDstDt1) = res1;
  }

}

/* kernel function */
__kernel void kernel_3(
  float threshold,
  float weight,
  __global float* const imgSrc,
  int imgSrcWidth,
  int imgSrcHeight,
  int imgSrcStep,
  int imgSrcShift,
  __global float* const blurySrc,
  int blurySrcWidth,
  int blurySrcHeight,
  int blurySrcStep,
  int blurySrcShift,
  __global float *maskDst,
  int maskDstWidth,
  int maskDstHeight,
  int maskDstStep,
  int maskDstShift,
  __global float *sharpenDS,
  int sharpenDSWidth,
  int sharpenDSHeight,
  int sharpenDSStep,
  int sharpenDSShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  //if ( gidx >= 2047 || gidy >= 2047 )
  if ( gidx >= (512) || gidy >= 2047 )
    return;

  /* kernel index calculation */
  int blurySrcIdx1 = blurySrcShift + (int)(((float)gidy + -2 + 2) *blurySrcStep) + (int)(((float)gidx*4 + -2 + 2) *sizeof(float));
  int imgSrcIdx2 = imgSrcShift + (int)(((float)gidy + 2) *imgSrcStep) + (int)(((float)gidx*4 + 2) *sizeof(float));
  int maskDstIdx1 = maskDstShift + (int)(((float)gidy + -2 + 2) *maskDstStep) + (int)(((float)gidx*4 + -2 + 2) *sizeof(float));
  int sharpenDSIdx1 = sharpenDSShift + (int)(((float)gidy + -2 + 2) *sharpenDSStep) + (int)(((float)gidx*4 + -2 + 2) *sizeof(float));

  /* kernel operands */
  __global float *blurySrcDt1 = (__global char *)blurySrc + blurySrcIdx1;
  __global float *imgSrcDt2 = (__global char *)imgSrc + imgSrcIdx2;
  __global float *maskDstDt1 = (__global char *)maskDst + maskDstIdx1;
  __global float *sharpenDSDt1 = (__global float*) ((__global char *)sharpenDS + sharpenDSIdx1);

  /* kernel operation */
  {
    float4 img, blury, sharpen;
    img = (convert_float4)(*((__global float4*)imgSrcDt2));
    blury =(convert_float4)(*((__global float4*)blurySrcDt1));
    sharpen = img * (1 + weight) - blury * weight;
    *((__global float4*)sharpenDSDt1)  = sharpen;
    float4 _ct0 = img;
    float4 _ct1 = *(sharpenDSDt1);
    float4 Op_ans1 = ( img -  blury);
    float4 _ct2 = ((Op_ans1) < threshold) ? _ct0 : _ct1;
    *((__global float4*)maskDstDt1) = _ct2;
  }

}

