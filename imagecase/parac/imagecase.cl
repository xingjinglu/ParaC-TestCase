/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

/* kernel function */
__kernel void kernel_1(
  __global char* const oimageSrc,
  int oimageSrcWidth,
  int oimageSrcHeight,
  int oimageSrcStep,
  int oimageSrcShift,
  __global float* const argSrc,
  int argSrcWidth,
  int argSrcHeight,
  int argSrcStep,
  int argSrcShift,
  __global char *mimageDst,
  int mimageDstWidth,
  int mimageDstHeight,
  int mimageDstStep,
  int mimageDstShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if ( gidx >= (256/4) || gidy >= 256 )
    return;

  /* kernel index calculation */
  int oimageSrcIdx2 = oimageSrcShift + ((float)gidy) *oimageSrcStep + ((float)gidx *4 * 3) *sizeof(char);
  int mimageDstIdx1 = mimageDstShift + ((float)gidy) *mimageDstStep + ((float)gidx *4) *sizeof(char);

  /* kernel operands */
  __global float *argSrcDt1 = (__global char *)argSrc + argSrcShift;
  __global char *oimageSrcDt2 = oimageSrc + oimageSrcIdx2;
  __global char *mimageDstDt1 = mimageDst + mimageDstIdx1;

  /* kernel operation */
  {
    float4 oimage;
     float R1Next;
     float arg[3];
    float4 res1;
    {
      oimage = convert_float4(vload4(0, oimageSrcDt2 + 0 * oimageSrcStep + 4 * 0));
      arg[0] = ( *((__global float*) ((__global char*) argSrcDt1 + 0 + argSrcStep * 0)));
      arg[1] = ( *((__global float*) ((__global char*) argSrcDt1 + 1 + argSrcStep * 0)));
      arg[2] = ( *((__global float*) ((__global char*) argSrcDt1 + 2 + argSrcStep * 0)));
      res1.s0 = oimage.s0 * arg[0] + oimage.s1 * arg[1] + oimage.s2 * arg[2];
      res1.s1 = oimage.s1 * arg[0] + oimage.s2 * arg[1] + oimage.s3 * arg[2];
      res1.s2 = oimage.s2 * arg[0] + oimage.s3 * arg[1];
      R1Next = *(oimageSrc + 4 * 1 + 0);
      res1.s2 += R1Next * arg[2]; 
      res1.s3 = oimage.s3 * arg[0];
      R1Next = *(oimageSrc + 4 * 1 + 0);
      res1.s3 += R1Next * arg[1]; 
      R1Next = *(oimageSrc + 4 * 1 + 1);
      res1.s3 += R1Next * arg[2]; 
    }
    char4 temp0;
    temp0 = convert_char4(res1);
    *mimageDstDt1 = temp0.s0;
    *(mimageDstDt1 + 1) = temp0.s1;
    *(mimageDstDt1 + 2) = temp0.s2;
    *(mimageDstDt1 + 3) = temp0.s3;
  }

}

/* kernel function */
__kernel void kernel_2(
  __global char* const mimageSrc,
  int mimageSrcWidth,
  int mimageSrcHeight,
  int mimageSrcStep,
  int mimageSrcShift,
  double rotate,
  __global char *dimageDst,
  int dimageDstWidth,
  int dimageDstHeight,
  int dimageDstStep,
  int dimageDstShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if ( gidx >= 204 || gidy >= 204 )
    return;

  /* kernel index calculation */
  int mimageSrcIdx1;
  int mimageSrcIdx2;
  int mimageSrcIdx3;
  int mimageSrcIdx4;
  int dimageDstIdx1 = dimageDstShift + ((float)gidy) *dimageDstStep + ((float)gidx) *sizeof(char);

  /* kernel operands */
  __global char *mimageSrcDt1;
  __global char *mimageSrcDt2;
  __global char *mimageSrcDt3;
  __global char *mimageSrcDt4;
  __global char *dimageDstDt1 = dimageDst + dimageDstIdx1;

  /* kernel operation */
  {
    int r1 = (int)(gidy * rotate);
    int r2 = min(256 - 1, r1 + 1);
    double p = gidy * rotate - r1;
    int c1 = (int)(gidx * rotate);
    int c2 = min(256 - 1, c1 + 1);
    double q = gidx * rotate - c1;
    mimageSrcIdx1 = mimageSrcShift + (r1) *mimageSrcStep + (c1) *sizeof(char);
    mimageSrcDt1 = mimageSrc + mimageSrcIdx1;
    mimageSrcIdx2 = mimageSrcShift + (r1) *mimageSrcStep + (c2) *sizeof(char);
    mimageSrcDt2 = mimageSrc + mimageSrcIdx2;
    mimageSrcIdx3 = mimageSrcShift + (r2) *mimageSrcStep + (c1) *sizeof(char);
    mimageSrcDt3 = mimageSrc + mimageSrcIdx3;
    mimageSrcIdx4 = mimageSrcShift + (r2) *mimageSrcStep + (c2) *sizeof(char);
    mimageSrcDt4 = mimageSrc + mimageSrcIdx4;
    *dimageDstDt1 = (1 - p) * (1 - q) * *(mimageSrcDt1) + (1 - p) * q * *(mimageSrcDt2) + p * (1 - q) * *(mimageSrcDt3) + p * q * *(mimageSrcDt4);
  }

}

