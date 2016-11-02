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
  if ( gidx >= 2051 || gidy >= 2047 )
    return;

  /* kernel index calculation */
  int imgSrcIdx2 = imgSrcShift + (int)(((float)gidy + -2 + 2) *imgSrcStep) + (int)(((float)gidx) *sizeof(float));
  int blurxDstIdx1 = blurxDstShift + (int)(((float)gidy + -2 + 2) *blurxDstStep) + (int)(((float)gidx) *sizeof(float));

  /* kernel operands */
  __global float *filterxSrcDt1 = (__global char *)filterxSrc + filterxSrcShift;
  __global float *imgSrcDt2 = (__global char *)imgSrc + imgSrcIdx2;
  __global float *blurxDstDt1 = (__global char *)blurxDst + blurxDstIdx1;

  /* kernel operation */
  {
        float img[5];
    float imgNext;
    float filterx[5];
    float res1;
    {
    img[0] = ( float) (*((__global float*) ((__global char*) imgSrcDt2 + 0 * sizeof(float) + imgSrcStep * 0)));
    filterx[0] = ( float) ( *((__global float*) ((__global char*) filterxSrcDt1 + 0 * sizeof(float) + filterxSrcStep * 0)));
    res1 = img[0] * filterx[0]; 
    img[0] = ( float) (*((__global float*) ((__global char*) imgSrcDt2 + 0 * sizeof(float) + imgSrcStep * 1)));
    filterx[0] = ( float) ( *((__global float*) ((__global char*) filterxSrcDt1 + 0 * sizeof(float) + filterxSrcStep * 1)));
    res1 += img[0] * filterx[0]; 
    img[0] = ( float) (*((__global float*) ((__global char*) imgSrcDt2 + 0 * sizeof(float) + imgSrcStep * 2)));
    filterx[0] = ( float) ( *((__global float*) ((__global char*) filterxSrcDt1 + 0 * sizeof(float) + filterxSrcStep * 2)));
    res1 += img[0] * filterx[0]; 
    img[0] = ( float) (*((__global float*) ((__global char*) imgSrcDt2 + 0 * sizeof(float) + imgSrcStep * 3)));
    filterx[0] = ( float) ( *((__global float*) ((__global char*) filterxSrcDt1 + 0 * sizeof(float) + filterxSrcStep * 3)));
    res1 += img[0] * filterx[0]; 
    img[0] = ( float) (*((__global float*) ((__global char*) imgSrcDt2 + 0 * sizeof(float) + imgSrcStep * 4)));
    filterx[0] = ( float) ( *((__global float*) ((__global char*) filterxSrcDt1 + 0 * sizeof(float) + filterxSrcStep * 4)));
    res1 += img[0] * filterx[0]; 
  }
    *blurxDstDt1 = res1;
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
  __global float *filterySrcDt2 = (__global char *)filterySrc + filterySrcShift;
  __global float *bluryDstDt1 = (__global char *)bluryDst + bluryDstIdx1;

  /* kernel operation */
  {
        float4 blurx;
    float blurxNext;
    float filtery[5];
    float4 res1;
    {
    blurx = vload4(0, (__global float*) ( (__global char*)(blurxSrcDt1) + 0 * blurxSrcStep + 4 * 0 * sizeof(float)));
    filtery[0] = ( float) ( *((__global float*) ((__global char*) filterySrcDt2 + 0 * sizeof(float) + filterySrcStep * 0)));
    filtery[1] = ( float) ( *((__global float*) ((__global char*) filterySrcDt2 + 1 * sizeof(float) + filterySrcStep * 0)));
    filtery[2] = ( float) ( *((__global float*) ((__global char*) filterySrcDt2 + 2 * sizeof(float) + filterySrcStep * 0)));
    filtery[3] = ( float) ( *((__global float*) ((__global char*) filterySrcDt2 + 3 * sizeof(float) + filterySrcStep * 0)));
    filtery[4] = ( float) ( *((__global float*) ((__global char*) filterySrcDt2 + 4 * sizeof(float) + filterySrcStep * 0)));
    res1.s0 = blurx.s0 * filtery[0] + blurx.s1 * filtery[1] + blurx.s2 * filtery[2] + blurx.s3 * filtery[3];
    blurxNext = ( float) ( *((__global float*) ((__global char*) blurxSrcDt1 + blurxSrcStep * 0 + 4 * 1 * sizeof( float) + 0 * sizeof(float))));
    res1.s0 += blurxNext * filtery[4]; 
    res1.s1 = blurx.s1 * filtery[0] + blurx.s2 * filtery[1] + blurx.s3 * filtery[2];
    blurxNext = ( float) ( *((__global float*) ((__global char*) blurxSrcDt1 + blurxSrcStep * 0 + 4 * 1 * sizeof( float) + 0 * sizeof(float))));
    res1.s1 += blurxNext * filtery[3]; 
    blurxNext = ( float) ( *((__global float*) ((__global char*) blurxSrcDt1 + blurxSrcStep * 0 + 4 * 1 * sizeof( float) + 1 * sizeof(float))));
    res1.s1 += blurxNext * filtery[4]; 
    res1.s2 = blurx.s2 * filtery[0] + blurx.s3 * filtery[1];
    blurxNext = ( float) ( *((__global float*) ((__global char*) blurxSrcDt1 + blurxSrcStep * 0 + 4 * 1 * sizeof( float) + 0 * sizeof(float))));
    res1.s2 += blurxNext * filtery[2]; 
    blurxNext = ( float) ( *((__global float*) ((__global char*) blurxSrcDt1 + blurxSrcStep * 0 + 4 * 1 * sizeof( float) + 1 * sizeof(float))));
    res1.s2 += blurxNext * filtery[3]; 
    blurxNext = ( float) ( *((__global float*) ((__global char*) blurxSrcDt1 + blurxSrcStep * 0 + 4 * 1 * sizeof( float) + 2 * sizeof(float))));
    res1.s2 += blurxNext * filtery[4]; 
    res1.s3 = blurx.s3 * filtery[0];
    blurxNext = ( float) ( *((__global float*) ((__global char*) blurxSrcDt1 + blurxSrcStep * 0 + 4 * 1 * sizeof( float) + 0 * sizeof(float))));
    res1.s3 += blurxNext * filtery[1]; 
    blurxNext = ( float) ( *((__global float*) ((__global char*) blurxSrcDt1 + blurxSrcStep * 0 + 4 * 1 * sizeof( float) + 1 * sizeof(float))));
    res1.s3 += blurxNext * filtery[2]; 
    blurxNext = ( float) ( *((__global float*) ((__global char*) blurxSrcDt1 + blurxSrcStep * 0 + 4 * 1 * sizeof( float) + 2 * sizeof(float))));
    res1.s3 += blurxNext * filtery[3]; 
    blurxNext = ( float) ( *((__global float*) ((__global char*) blurxSrcDt1 + blurxSrcStep * 0 + 4 * 1 * sizeof( float) + 3 * sizeof(float))));
    res1.s3 += blurxNext * filtery[4]; 
  }
    float4 temp0;
    temp0 = res1;
    *bluryDstDt1 = temp0.s0;
    *(bluryDstDt1 + 1) = temp0.s1;
    *(bluryDstDt1 + 2) = temp0.s2;
    *(bluryDstDt1 + 3) = temp0.s3;
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
  if ( gidx >= 2047 || gidy >= 2047 )
    return;

  /* kernel index calculation */
  int blurySrcIdx1 = blurySrcShift + (int)(((float)gidy + -2 + 2) *blurySrcStep) + (int)(((float)gidx + -2 + 2) *sizeof(float));
  int imgSrcIdx2 = imgSrcShift + (int)(((float)gidy + 2) *imgSrcStep) + (int)(((float)gidx + 2) *sizeof(float));
  int maskDstIdx1 = maskDstShift + (int)(((float)gidy + -2 + 2) *maskDstStep) + (int)(((float)gidx + -2 + 2) *sizeof(float));
  int sharpenDSIdx1 = sharpenDSShift + (int)(((float)gidy + -2 + 2) *sharpenDSStep) + (int)(((float)gidx + -2 + 2) *sizeof(float));

  /* kernel operands */
  __global float *blurySrcDt1 = (__global char *)blurySrc + blurySrcIdx1;
  __global float *imgSrcDt2 = (__global char *)imgSrc + imgSrcIdx2;
  __global float *maskDstDt1 = (__global char *)maskDst + maskDstIdx1;
  __global float *sharpenDSDt1 = (__global float*) ((__global char *)sharpenDS + sharpenDSIdx1);

  /* kernel operation */
  {
    *sharpenDSDt1 = *(imgSrcDt2) * (1 + weight) - *(blurySrcDt1) * weight;
    float _ct0 = *(imgSrcDt2);
    float _ct1 = *(sharpenDSDt1);
    float Op_ans1 = ( *((__global float*) imgSrcDt2)) - (*(((__global float*) blurySrcDt1)));
    float _ct2 = ((Op_ans1) < threshold) ? _ct0 : _ct1;
         *maskDstDt1 = _ct2;
  }

}

