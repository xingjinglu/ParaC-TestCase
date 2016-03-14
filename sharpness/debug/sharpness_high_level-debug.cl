/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

/* kernel function */
__kernel void kernel_1(
  __global unsigned char* const pImageSrcSrc,
  int pImageSrcSrcWidth,
  int pImageSrcSrcHeight,
  int pImageSrcSrcStep,
  int pImageSrcSrcShift,
  __global unsigned char *pImageDstDst,
  int pImageDstDstWidth,
  int pImageDstDstHeight,
  int pImageDstDstStep,
  int pImageDstDstShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if (gidx >= 256 || gidy >= 256)
   return;

  /* kernel index calculation */
  int pImageSrcSrcIdx1 = pImageSrcSrcShift + ((float)gidy * 4) *pImageSrcSrcStep + ((float)gidx * 4) *sizeof(unsigned char);
  int pImageDstDstIdx1 = pImageDstDstShift + ((float)gidy * 1/4 * 4) *pImageDstDstStep + ((float)gidx * 1/4 * 4) *sizeof(unsigned char);

  /* kernel operands */
  __global unsigned char *pImageSrcSrcDt1 = pImageSrcSrc + pImageSrcSrcIdx1;
  __global unsigned char *pImageDstDstDt1 = pImageDstDst + pImageDstDstIdx1;

  /* kernel operation */
  {
        short _sum = 0;
        uchar4 _rtemp0;
    __global uchar *_base = pImageSrcSrcDt1;
    _rtemp0 = vload4(0, _base);
    _sum  +=     _rtemp0.s0     +     _rtemp0.s1     +     _rtemp0.s2     +     _rtemp0.s3     ;
    _base = pImageSrcSrcDt1 + 1 * pImageSrcSrcStep;
    _rtemp0 = vload4(0, _base);
    _sum  +=     _rtemp0.s0     +     _rtemp0.s1     +     _rtemp0.s2     +     _rtemp0.s3     ;
    _base = pImageSrcSrcDt1 + 2 * pImageSrcSrcStep;
    _rtemp0 = vload4(0, _base);
    _sum  +=     _rtemp0.s0     +     _rtemp0.s1     +     _rtemp0.s2     +     _rtemp0.s3     ;
    _base = pImageSrcSrcDt1 + 3 * pImageSrcSrcStep;
    _rtemp0 = vload4(0, _base);
    _sum  +=     _rtemp0.s0     +     _rtemp0.s1     +     _rtemp0.s2     +     _rtemp0.s3     ;
    *pImageDstDstDt1 = (_sum + 8) >> 4;
  }

}

/* kernel function */
__kernel void kernel_2(
  __global unsigned char* const srcImageSrc,
  int srcImageSrcWidth,
  int srcImageSrcHeight,
  int srcImageSrcStep,
  int srcImageSrcShift,
  __global float* const border_mp_0Src,
  int border_mp_0SrcWidth,
  int border_mp_0SrcHeight,
  int border_mp_0SrcStep,
  int border_mp_0SrcShift,
  __global float* const border_mp_1Src,
  int border_mp_1SrcWidth,
  int border_mp_1SrcHeight,
  int border_mp_1SrcStep,
  int border_mp_1SrcShift,
  __global unsigned char *dstImageDS,
  int dstImageDSWidth,
  int dstImageDSHeight,
  int dstImageDSStep,
  int dstImageDSShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if (gidx >= 1 || gidy >= 256)
   return;

  /* kernel index calculation */
  int srcImageSrcIdx3 = srcImageSrcShift + ((float)gidy) *srcImageSrcStep;
  int srcImageSrcIdx4 = srcImageSrcShift + ((float)gidy) *srcImageSrcStep + (1024 / 4 - 1) *sizeof(unsigned char);
  int srcImageSrcIdx5 = srcImageSrcShift + ((float)gidy + 1) *srcImageSrcStep;
  int srcImageSrcIdx6 = srcImageSrcShift + ((float)gidy + 1) *srcImageSrcStep + (1024 / 4 - 1) *sizeof(unsigned char);
  int dstImageDSIdx1 = dstImageDSShift + ((float)gidy * 4) *dstImageDSStep;
  int dstImageDSIdx2 = dstImageDSShift + ((float)gidy * 4) *dstImageDSStep + (1) *sizeof(unsigned char);
  int dstImageDSIdx3 = dstImageDSShift + ((float)gidy * 4) *dstImageDSStep + (1024 - 1) *sizeof(unsigned char);
  int dstImageDSIdx4 = dstImageDSShift + ((float)gidy * 4) *dstImageDSStep + (1024 - 2) *sizeof(unsigned char);
  int dstImageDSIdx5 = dstImageDSShift + ((float)gidy * 4 + 1) *dstImageDSStep;
  int dstImageDSIdx6 = dstImageDSShift + ((float)gidy * 4 + 1) *dstImageDSStep + (1) *sizeof(unsigned char);
  int dstImageDSIdx7 = dstImageDSShift + ((float)gidy * 4 + 1) *dstImageDSStep + (1024 - 1) *sizeof(unsigned char);
  int dstImageDSIdx8 = dstImageDSShift + ((float)gidy * 4 + 1) *dstImageDSStep + (1024 - 2) *sizeof(unsigned char);
  int dstImageDSIdx9 = dstImageDSShift + ((float)gidy * 4 + 2) *dstImageDSStep + (1024 - 1) *sizeof(unsigned char);
  int dstImageDSIdx10 = dstImageDSShift + ((float)gidy * 4 + 2) *dstImageDSStep + (1024 - 2) *sizeof(unsigned char);
  int dstImageDSIdx11 = dstImageDSShift + ((float)gidy * 4 + 3) *dstImageDSStep + (1024 - 1) *sizeof(unsigned char);
  int dstImageDSIdx12 = dstImageDSShift + ((float)gidy * 4 + 3) *dstImageDSStep + (1024 - 2) *sizeof(unsigned char);

  /* kernel operands */
  __global float *border_mp_0SrcDt1 = (__global char *)border_mp_0Src + border_mp_0SrcShift;
  __global float *border_mp_1SrcDt2 = (__global char *)border_mp_1Src + border_mp_1SrcShift;
  __global unsigned char *srcImageSrcDt3 = srcImageSrc + srcImageSrcIdx3;
  __global unsigned char *srcImageSrcDt4 = srcImageSrc + srcImageSrcIdx4;
  __global unsigned char *srcImageSrcDt5 = srcImageSrc + srcImageSrcIdx5;
  __global unsigned char *srcImageSrcDt6 = srcImageSrc + srcImageSrcIdx6;
  __global unsigned char *dstImageDSDt1 = dstImageDS + dstImageDSIdx1;
  __global unsigned char *dstImageDSDt2 = dstImageDS + dstImageDSIdx2;
  __global unsigned char *dstImageDSDt3 = dstImageDS + dstImageDSIdx3;
  __global unsigned char *dstImageDSDt4 = dstImageDS + dstImageDSIdx4;
  __global unsigned char *dstImageDSDt5 = dstImageDS + dstImageDSIdx5;
  __global unsigned char *dstImageDSDt6 = dstImageDS + dstImageDSIdx6;
  __global unsigned char *dstImageDSDt7 = dstImageDS + dstImageDSIdx7;
  __global unsigned char *dstImageDSDt8 = dstImageDS + dstImageDSIdx8;
  __global unsigned char *dstImageDSDt9 = dstImageDS + dstImageDSIdx9;
  __global unsigned char *dstImageDSDt10 = dstImageDS + dstImageDSIdx10;
  __global unsigned char *dstImageDSDt11 = dstImageDS + dstImageDSIdx11;
  __global unsigned char *dstImageDSDt12 = dstImageDS + dstImageDSIdx12;

  /* kernel operation */
  {
    if (gidy == (1024 / 4)-1) {
                   *dstImageDSDt1 = *srcImageSrcDt3;
                   *dstImageDSDt5 = *srcImageSrcDt3;
                   *dstImageDSDt2 = *srcImageSrcDt3;
                   *dstImageDSDt6 = *srcImageSrcDt3;
                   *dstImageDSDt4 = *srcImageSrcDt4;
                   *dstImageDSDt8 = *srcImageSrcDt4;
                   *dstImageDSDt10 = *srcImageSrcDt4;
                   *dstImageDSDt12 = *srcImageSrcDt4;
                   *dstImageDSDt3 = *srcImageSrcDt4;
                   *dstImageDSDt7 = *srcImageSrcDt4;
                   *dstImageDSDt9 = *srcImageSrcDt4;
                   *dstImageDSDt11 = *srcImageSrcDt4;
          } else {
      
      float Result1 [4][1] ;
      for(int i = 0; i < 4 ; i++ ) 
      for(int j = 0; j < 1 ; j++ ){ 
      *( (float*)Result1 + i*1+j) = *( (__global float*)((__global char*)border_mp_1SrcDt2+ i*border_mp_1SrcStep+j*sizeof(float)) ) * *(srcImageSrcDt5); 
      }
      
      float Result2 [4][1] ;
      for(int i = 0; i < 4 ; i++ ) 
      for(int j = 0; j < 1 ; j++ ){ 
      *( (float*)Result2 + i*1+j) = *( (__global float*)((__global char*)border_mp_0SrcDt1+ i*border_mp_0SrcStep+j*sizeof(float)) ) * *(srcImageSrcDt3); 
      }
      
      float Result3[4][1];
      *( (float*)Result3 + 0) = *( (float*)Result2 + 0) + *( (float*) Result1 + 0);
      *( (float*)Result3 + 1) = *( (float*)Result2 + 1) + *( (float*) Result1 + 1);
      *( (float*)Result3 + 2) = *( (float*)Result2 + 2) + *( (float*) Result1 + 2);
      *( (float*)Result3 + 3) = *( (float*)Result2 + 3) + *( (float*) Result1 + 3);
      
      for(int j=0;j<4;j++)
      *(dstImageDSDt2 + j *dstImageDSStep ) = *( ( float*)Result3 + j);
      
      for(int i=0;i<4;i++)
      *(dstImageDSDt1 + i * dstImageDSStep) = *(  dstImageDSDt2 + i * dstImageDSStep );
             
      float Result4 [4][1] ;
      for(int i = 0; i < 4 ; i++ ) 
      for(int j = 0; j < 1 ; j++ ){ 
      *( (float*)Result4 + i*1+j) = *( (__global float*)((__global char*)border_mp_1SrcDt2+ i*border_mp_1SrcStep+j*sizeof(float)) ) * *(srcImageSrcDt6); 
      }
      
      float Result5 [4][1] ;
      for(int i = 0; i < 4 ; i++ ) 
      for(int j = 0; j < 1 ; j++ ){ 
      *( (float*)Result5 + i*1+j) = *( (__global float*)((__global char*)border_mp_0SrcDt1+ i*border_mp_0SrcStep+j*sizeof(float)) ) * *(srcImageSrcDt4); 
      }
      
      float Result6[4][1];
      *( (float*)Result6 + 0) = *( (float*)Result5 + 0) + *( (float*) Result4 + 0);
      *( (float*)Result6 + 1) = *( (float*)Result5 + 1) + *( (float*) Result4 + 1);
      *( (float*)Result6 + 2) = *( (float*)Result5 + 2) + *( (float*) Result4 + 2);
      *( (float*)Result6 + 3) = *( (float*)Result5 + 3) + *( (float*) Result4 + 3);
      
      for(int j=0;j<4;j++)
      *(dstImageDSDt3 + j * dstImageDSStep) = *( ( float*)Result6 + j);
      
      for(int i=0;i<4;i++)
      *(dstImageDSDt4 + i * dstImageDSStep) = *(  dstImageDSDt3 + i * dstImageDSStep);
           }
  }

}

/* kernel function */
__kernel void kernel_3(
  __global unsigned char* const srcImageSrc,
  int srcImageSrcWidth,
  int srcImageSrcHeight,
  int srcImageSrcStep,
  int srcImageSrcShift,
  __global float* const border_mp_0Src,
  int border_mp_0SrcWidth,
  int border_mp_0SrcHeight,
  int border_mp_0SrcStep,
  int border_mp_0SrcShift,
  __global float* const border_mp_1Src,
  int border_mp_1SrcWidth,
  int border_mp_1SrcHeight,
  int border_mp_1SrcStep,
  int border_mp_1SrcShift,
  __global unsigned char *dstImageDS,
  int dstImageDSWidth,
  int dstImageDSHeight,
  int dstImageDSStep,
  int dstImageDSShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if (gidx >= 256 || gidy >= 1)
   return;

  /* kernel index calculation */
  int srcImageSrcIdx3 = srcImageSrcShift + ((float)gidx) *sizeof(unsigned char);
  int srcImageSrcIdx4 = srcImageSrcShift + ((float)gidx + 1) *sizeof(unsigned char);
  int srcImageSrcIdx5 = srcImageSrcShift + (1024 / 4 - 1) *srcImageSrcStep + ((float)gidx) *sizeof(unsigned char);
  int srcImageSrcIdx6 = srcImageSrcShift + (1024 / 4 - 1) *srcImageSrcStep + ((float)gidx + 1) *sizeof(unsigned char);
  int dstImageDSIdx1 = dstImageDSShift + ((float)gidx * 4) *sizeof(unsigned char);
  int dstImageDSIdx2 = dstImageDSShift + ((float)gidx * 4 + 1) *sizeof(unsigned char);
  int dstImageDSIdx3 = dstImageDSShift + (1) *dstImageDSStep + ((float)gidx * 4) *sizeof(unsigned char);
  int dstImageDSIdx4 = dstImageDSShift + (1) *dstImageDSStep + ((float)gidx * 4 + 1) *sizeof(unsigned char);
  int dstImageDSIdx5 = dstImageDSShift + (1024 - 1) *dstImageDSStep + ((float)gidx * 4) *sizeof(unsigned char);
  int dstImageDSIdx6 = dstImageDSShift + (1024 - 1) *dstImageDSStep + ((float)gidx * 4 + 1) *sizeof(unsigned char);
  int dstImageDSIdx7 = dstImageDSShift + (1024 - 2) *dstImageDSStep + ((float)gidx * 4) *sizeof(unsigned char);
  int dstImageDSIdx8 = dstImageDSShift + (1024 - 2) *dstImageDSStep + ((float)gidx * 4 + 1) *sizeof(unsigned char);

  /* kernel operands */
  __global float *border_mp_0SrcDt1 = (__global char *)border_mp_0Src + border_mp_0SrcShift;
  __global float *border_mp_1SrcDt2 = (__global char *)border_mp_1Src + border_mp_1SrcShift;
  __global unsigned char *srcImageSrcDt3 = srcImageSrc + srcImageSrcIdx3;
  __global unsigned char *srcImageSrcDt4 = srcImageSrc + srcImageSrcIdx4;
  __global unsigned char *srcImageSrcDt5 = srcImageSrc + srcImageSrcIdx5;
  __global unsigned char *srcImageSrcDt6 = srcImageSrc + srcImageSrcIdx6;
  __global unsigned char *dstImageDSDt1 = dstImageDS + dstImageDSIdx1;
  __global unsigned char *dstImageDSDt2 = dstImageDS + dstImageDSIdx2;
  __global unsigned char *dstImageDSDt3 = dstImageDS + dstImageDSIdx3;
  __global unsigned char *dstImageDSDt4 = dstImageDS + dstImageDSIdx4;
  __global unsigned char *dstImageDSDt5 = dstImageDS + dstImageDSIdx5;
  __global unsigned char *dstImageDSDt6 = dstImageDS + dstImageDSIdx6;
  __global unsigned char *dstImageDSDt7 = dstImageDS + dstImageDSIdx7;
  __global unsigned char *dstImageDSDt8 = dstImageDS + dstImageDSIdx8;

  /* kernel operation */
  {

if (gidx == 1024 / 4 - 1) {
             *dstImageDSDt3 = *srcImageSrcDt3;
                   *dstImageDSDt1 = *srcImageSrcDt3;
                   *dstImageDSDt2 = *srcImageSrcDt3;
                   *dstImageDSDt4 = *srcImageSrcDt3;
                   *dstImageDSDt7 = *srcImageSrcDt5;
                   *dstImageDSDt5 = *srcImageSrcDt5;
                   *dstImageDSDt8 = *srcImageSrcDt5;
                   *dstImageDSDt6 = *srcImageSrcDt5;
          } 

else {
#if 1
      
      float Result1 [1][4] ;
      for(int i = 0; i < 1 ; i++ ) 
      for(int j = 0; j < 4 ; j++ ){ 
      *( (float*)Result1 + i*4+j) = *( (__global float*)((__global char*)border_mp_1SrcDt2+ i*border_mp_1SrcStep+j * sizeof(float) )) * *(srcImageSrcDt4); 
      }
      
      float Result2 [1][4] ;
      for(int i = 0; i < 1 ; i++ ) 
      for(int j = 0; j < 4 ; j++ ){ 
      *( (float*)Result2 + i*4+j) = *( (__global float*)((__global char*)border_mp_0SrcDt1+ i*border_mp_0SrcStep+j * sizeof(float) )) * *(srcImageSrcDt3); 
      }
      
      float Result3[1][4];
      *( (float*)Result3 + 0) = *( (float*)Result2 + 0) + *( (float*) Result1 + 0);
      *( (float*)Result3 + 1) = *( (float*)Result2 + 1) + *( (float*) Result1 + 1);
      *( (float*)Result3 + 2) = *( (float*)Result2 + 2) + *( (float*) Result1 + 2);
      *( (float*)Result3 + 3) = *( (float*)Result2 + 3) + *( (float*) Result1 + 3);
      
      for(int j=0;j<4;j++)
      *(dstImageDSDt3 + j + 0 * dstImageDSStep) = *(( float*)Result3 + j+ 0 * sizeof(float));
      //*( (__global unsigned char*)((__global char*)dstImageDSDt3 + j * sizeof(unsigned char)) ) = *( ( float*)( ( char*)(Result3 + j * sizeof(float)) ));
      
      for(int j=0;j<4;j++)
      *(dstImageDSDt1 + j) = *( ( __global unsigned char*)dstImageDSDt3 + j);
      //*( (__global unsigned char*)((__global char*)dstImageDSDt1 + j * sizeof(unsigned char)) ) = *( (__global unsigned char*)( (__global char*)(dstImageDSDt3 + j * sizeof(unsigned char)) ));
            
      float Result4 [1][4] ;
      for(int i = 0; i < 1 ; i++ ) 
      for(int j = 0; j < 4 ; j++ ){ 
      *( (float*)Result4 + i*4+j) = *( (__global float*)((__global char*)border_mp_1SrcDt2+ i*border_mp_1SrcStep+j * sizeof(float) )) * *(srcImageSrcDt6); 
      }
      
      float Result5 [1][4] ;
      for(int i = 0; i < 1 ; i++ ) 
      for(int j = 0; j < 4 ; j++ ){ 
      *( (float*)Result5 + i*4+j) = *( (__global float*)((__global char*)border_mp_0SrcDt1+ i*border_mp_0SrcStep+j * sizeof(float) )) * *(srcImageSrcDt5); 
      }
      
      float Result6[1][4];
      *( (float*)Result6 + 0) = *( (float*)Result5 + 0) + *( (float*) Result4 + 0);
      *( (float*)Result6 + 1) = *( (float*)Result5 + 1) + *( (float*) Result4 + 1);
      *( (float*)Result6 + 2) = *( (float*)Result5 + 2) + *( (float*) Result4 + 2);
      *( (float*)Result6 + 3) = *( (float*)Result5 + 3) + *( (float*) Result4 + 3);
      
      for(int j=0;j<4;j++)
      *(dstImageDSDt5 + j + 0 * dstImageDSStep) = *(( float*)Result6 + j + 0 *  sizeof(float));;
      //*( (__global unsigned char*)((__global char*)dstImageDSDt5 + j * sizeof(unsigned char)) ) = *( ( float*)( ( char*)(Result6 + j * sizeof(float)) ));
      
      for(int j=0;j<4;j++)
      *(dstImageDSDt7 + j) = *( ( __global unsigned char*)dstImageDSDt5 + j);;
      //*( (__global unsigned char*)((__global char*)dstImageDSDt7 + j * sizeof(unsigned char)) ) = *( (__global unsigned char*)( (__global char*)(dstImageDSDt5 + j * sizeof(unsigned char)) ));
#endif




          }

  }

}



#if 0
/* kernel function */
__kernel void kernel_3(
  __global unsigned char* const srcImageSrc,
  int srcImageSrcWidth,
  int srcImageSrcHeight,
  int srcImageSrcStep,
  int srcImageSrcShift,
  __global float* const border_mp_0Src,
  int border_mp_0SrcWidth,
  int border_mp_0SrcHeight,
  int border_mp_0SrcStep,
  int border_mp_0SrcShift,
  __global float* const border_mp_1Src,
  int border_mp_1SrcWidth,
  int border_mp_1SrcHeight,
  int border_mp_1SrcStep,
  int border_mp_1SrcShift,
  __global unsigned char *dstImageDS,
  int dstImageDSWidth,
  int dstImageDSHeight,
  int dstImageDSStep,
  int dstImageDSShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if (gidx >= 256 || gidy >= 1)
   return;

  /* kernel index calculation */
  int srcImageSrcIdx3 = srcImageSrcShift + ((float)gidx) *sizeof(unsigned char);
  int srcImageSrcIdx4 = srcImageSrcShift + ((float)gidx + 1) *sizeof(unsigned char);
  int srcImageSrcIdx5 = srcImageSrcShift + (1024 / 4 - 1) *srcImageSrcStep + ((float)gidx) *sizeof(unsigned char);
  int srcImageSrcIdx6 = srcImageSrcShift + (1024 / 4 - 1) *srcImageSrcStep + ((float)gidx + 1) *sizeof(unsigned char);
  int dstImageDSIdx1 = dstImageDSShift + ((float)gidx * 4) *sizeof(unsigned char);
  int dstImageDSIdx2 = dstImageDSShift + ((float)gidx * 4 + 1) *sizeof(unsigned char);
  int dstImageDSIdx3 = dstImageDSShift + (1) *dstImageDSStep + ((float)gidx * 4) *sizeof(unsigned char);
  int dstImageDSIdx4 = dstImageDSShift + (1) *dstImageDSStep + ((float)gidx * 4 + 1) *sizeof(unsigned char);
  int dstImageDSIdx5 = dstImageDSShift + (1024 - 1) *dstImageDSStep + ((float)gidx * 4) *sizeof(unsigned char);
  int dstImageDSIdx6 = dstImageDSShift + (1024 - 1) *dstImageDSStep + ((float)gidx * 4 + 1) *sizeof(unsigned char);
  int dstImageDSIdx7 = dstImageDSShift + (1024 - 2) *dstImageDSStep + ((float)gidx * 4) *sizeof(unsigned char);
  int dstImageDSIdx8 = dstImageDSShift + (1024 - 2) *dstImageDSStep + ((float)gidx * 4 + 1) *sizeof(unsigned char);

  /* kernel operands */
  __global float *border_mp_0SrcDt1 = (__global char *)border_mp_0Src + border_mp_0SrcShift;
  __global float *border_mp_1SrcDt2 = (__global char *)border_mp_1Src + border_mp_1SrcShift;
  __global unsigned char *srcImageSrcDt3 = srcImageSrc + srcImageSrcIdx3;
  __global unsigned char *srcImageSrcDt4 = srcImageSrc + srcImageSrcIdx4;
  __global unsigned char *srcImageSrcDt5 = srcImageSrc + srcImageSrcIdx5;
  __global unsigned char *srcImageSrcDt6 = srcImageSrc + srcImageSrcIdx6;
  __global unsigned char *dstImageDSDt1 = dstImageDS + dstImageDSIdx1;
  __global unsigned char *dstImageDSDt2 = dstImageDS + dstImageDSIdx2;
  __global unsigned char *dstImageDSDt3 = dstImageDS + dstImageDSIdx3;
  __global unsigned char *dstImageDSDt4 = dstImageDS + dstImageDSIdx4;
  __global unsigned char *dstImageDSDt5 = dstImageDS + dstImageDSIdx5;
  __global unsigned char *dstImageDSDt6 = dstImageDS + dstImageDSIdx6;
  __global unsigned char *dstImageDSDt7 = dstImageDS + dstImageDSIdx7;
  __global unsigned char *dstImageDSDt8 = dstImageDS + dstImageDSIdx8;

  /* kernel operation */
  {
    if (gidx == 1024 / 4 - 1) {
             *dstImageDSDt3 = *srcImageSrcDt3;
                   *dstImageDSDt1 = *srcImageSrcDt3;
                   *dstImageDSDt2 = *srcImageSrcDt3;
                   *dstImageDSDt4 = *srcImageSrcDt3;
                   *dstImageDSDt7 = *srcImageSrcDt5;
                   *dstImageDSDt5 = *srcImageSrcDt5;
                   *dstImageDSDt8 = *srcImageSrcDt5;
                   *dstImageDSDt6 = *srcImageSrcDt5;
          } else {
      
      float Result1 [1][4] ;
      for(int i = 0; i < 1 ; i++ ) 
      for(int j = 0; j < 4 ; j++ ){ 
      *( (float*)Result1 + i*0+j) = *( (__global float*)((__global char*)border_mp_1SrcDt2+ i*border_mp_1SrcStep+j*sizeof(float)) ) * *(srcImageSrcDt4); 
      }

      
      float Result2 [1][4] ;
      for(int i = 0; i < 1 ; i++ ) 
      for(int j = 0; j < 4 ; j++ ){ 
      *( (float*)Result2 + i*0+j) = *( (__global float*)((__global char*)border_mp_0SrcDt1+ i*border_mp_0SrcStep+j*sizeof(float)) ) * *(srcImageSrcDt3); 
      }
      
      float Result3[1][4];
      *( (float*)Result3 + 0) = *( (float*)Result2 + 0) + *( (float*) Result1 + 0);
      *( (float*)Result3 + 1) = *( (float*)Result2 + 1) + *( (float*) Result1 + 1);
      *( (float*)Result3 + 2) = *( (float*)Result2 + 2) + *( (float*) Result1 + 2);
      *( (float*)Result3 + 3) = *( (float*)Result2 + 3) + *( (float*) Result1 + 3);
      
      for(int i=0;i<1;i++)
      for(int j=0;j<4;j++){
      *(dstImageDSDt3 + j + i * dstImageDSStep) = *(( float*)Result3 + j+i * sizeof(float));
      }      
      for(int j=0;j<4;j++)
      *(dstImageDSDt1 + j) = *( ( __global unsigned char*)dstImageDSDt3 + j);
             
      float Result4 [1][4] ;
      for(int i = 0; i < 1 ; i++ ) 
      for(int j = 0; j < 4 ; j++ ){ 
      *( (float*)Result4 + i*0+j) = *( (__global float*)((__global char*)border_mp_1SrcDt2+ i*border_mp_1SrcStep+j*sizeof(float)) ) * *(srcImageSrcDt6); 
      }
      
      float Result5 [1][4] ;
      for(int i = 0; i < 1 ; i++ ) 
      for(int j = 0; j < 4 ; j++ ){ 
      *( (float*)Result5 + i*0+j) = *( (__global float*)((__global char*)border_mp_0SrcDt1+ i*border_mp_0SrcStep+j*sizeof(float)) ) * *(srcImageSrcDt5); 
      }
      

      float Result6[1][4];
      *( (float*)Result6 + 0) = *( (float*)Result5 + 0) + *( (float*) Result4 + 0);
      *( (float*)Result6 + 1) = *( (float*)Result5 + 1) + *( (float*) Result4 + 1);
      *( (float*)Result6 + 2) = *( (float*)Result5 + 2) + *( (float*) Result4 + 2);
      *( (float*)Result6 + 3) = *( (float*)Result5 + 3) + *( (float*) Result4 + 3);
      
      for(int i=0;i<1;i++)
      for(int j=0;j<4;j++){
      *(dstImageDSDt5 + j + i * dstImageDSStep) = *(( float*)Result6 + j + i * i * sizeof(float));
      }      
      for(int j=0;j<4;j++)
      *(dstImageDSDt7 + j) = *( ( __global unsigned char*)dstImageDSDt5 + j);
           }
  }

}

#endif


#if 0
// auto-version 

/* kernel function */
__kernel void kernel_4(
  __global unsigned char* const srcImageSrc,
  int srcImageSrcWidth,
  int srcImageSrcHeight,
  int srcImageSrcStep,
  int srcImageSrcShift,
  __global float* const mpSrc,
  int mpSrcWidth,
  int mpSrcHeight,
  int mpSrcStep,
  int mpSrcShift,
  __global unsigned char *dstImageDst,
  int dstImageDstWidth,
  int dstImageDstHeight,
  int dstImageDstStep,
  int dstImageDstShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if (gidx >= 255 || gidy >= 255)
   return;

  /* kernel index calculation */
  int srcImageSrcIdx2 = srcImageSrcShift + ((float)gidy) *srcImageSrcStep + ((float)gidx) *sizeof(unsigned char);
  int dstImageDstIdx1 = dstImageDstShift + ((float)gidy * 4 + 2) *dstImageDstStep + ((float)gidx * 4 + 2) *sizeof(unsigned char);

  /* kernel operands */
  __global float *mpSrcDt1 = (__global char *)mpSrc + mpSrcShift;
  __global unsigned char *srcImageSrcDt2 = srcImageSrc + srcImageSrcIdx2;
  __global unsigned char *dstImageDstDt1 = dstImageDst + dstImageDstIdx1;

  /* kernel operation */
  {
        float result0[4][4];
    float *result0_0;
    float *result0_1;
    float *result0_2;
    float *result0_3;
       result0_0 = (float*)result0;
       result0_1 = result0_0 + sizeof(float) * 4;
       result0_2 = result0_1 + sizeof(float) * 4;
       result0_3 = result0_2 + sizeof(float) * 4;
       *(result0_0+0) = (float)(    (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+0*mpSrcStep)) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+0*mpSrcStep)) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+0*mpSrcStep)) +     (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+0*mpSrcStep)) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+0*mpSrcStep)) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+0*mpSrcStep)));
       *(result0_0+1) = (float)(    (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+0*mpSrcStep)) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+0*mpSrcStep)) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+1*mpSrcStep)) +     (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+0*mpSrcStep)) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+0*mpSrcStep)) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+1*mpSrcStep)));
       *(result0_0+2) = (float)(    (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+0*mpSrcStep)) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+0*mpSrcStep)) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+2*mpSrcStep)) +     (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+0*mpSrcStep)) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+0*mpSrcStep)) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+2*mpSrcStep)));
       *(result0_0+3) = (float)(    (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+0*mpSrcStep)) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+0*mpSrcStep)) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+3*mpSrcStep)) +     (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+0*mpSrcStep)) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+0*mpSrcStep)) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+3*mpSrcStep)));
       *(result0_1+0) = (float)(    (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+1*mpSrcStep)) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+1*mpSrcStep)) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+0*mpSrcStep)) +     (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+1*mpSrcStep)) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+1*mpSrcStep)) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+0*mpSrcStep)));
       *(result0_1+1) = (float)(    (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+1*mpSrcStep)) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+1*mpSrcStep)) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+1*mpSrcStep)) +     (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+1*mpSrcStep)) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+1*mpSrcStep)) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+1*mpSrcStep)));
       *(result0_1+2) = (float)(    (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+1*mpSrcStep)) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+1*mpSrcStep)) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+2*mpSrcStep)) +     (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+1*mpSrcStep)) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+1*mpSrcStep)) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+2*mpSrcStep)));
       *(result0_1+3) = (float)(    (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+1*mpSrcStep)) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+1*mpSrcStep)) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+3*mpSrcStep)) +     (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+1*mpSrcStep)) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+1*mpSrcStep)) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+3*mpSrcStep)));
       *(result0_2+0) = (float)(    (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+2*mpSrcStep)) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+2*mpSrcStep)) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+0*mpSrcStep)) +     (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+2*mpSrcStep)) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+2*mpSrcStep)) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+0*mpSrcStep)));
       *(result0_2+1) = (float)(    (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+2*mpSrcStep)) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+2*mpSrcStep)) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+1*mpSrcStep)) +     (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+2*mpSrcStep)) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+2*mpSrcStep)) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+1*mpSrcStep)));
       *(result0_2+2) = (float)(    (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+2*mpSrcStep)) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+2*mpSrcStep)) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+2*mpSrcStep)) +     (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+2*mpSrcStep)) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+2*mpSrcStep)) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+2*mpSrcStep)));
       *(result0_2+3) = (float)(    (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+2*mpSrcStep)) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+2*mpSrcStep)) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+3*mpSrcStep)) +     (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+2*mpSrcStep)) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+2*mpSrcStep)) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+3*mpSrcStep)));
       *(result0_3+0) = (float)(    (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+3*mpSrcStep)) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+3*mpSrcStep)) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+0*mpSrcStep)) +     (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+3*mpSrcStep)) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+3*mpSrcStep)) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+0*mpSrcStep)));
       *(result0_3+1) = (float)(    (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+3*mpSrcStep)) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+3*mpSrcStep)) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+1*mpSrcStep)) +     (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+3*mpSrcStep)) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+3*mpSrcStep)) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+1*mpSrcStep)));
       *(result0_3+2) = (float)(    (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+3*mpSrcStep)) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+3*mpSrcStep)) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+2*mpSrcStep)) +     (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+3*mpSrcStep)) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+3*mpSrcStep)) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+2*mpSrcStep)));
       *(result0_3+3) = (float)(    (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+3*mpSrcStep)) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+3*mpSrcStep)) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+3*mpSrcStep)) +     (*( (__global float*)( (__global char*)mpSrcDt1+0* sizeof(float)+3*mpSrcStep)) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+3*mpSrcStep)) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *( (__global float*)( (__global char*)mpSrcDt1+1* sizeof(float)+3*mpSrcStep)));
    
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++){
    *( (__global unsigned char*)( (__global char*)dstImageDstDt1 + i * dstImageDstStep + j) ) = *( ( float*)( ( char*) (result0 + j * sizeof(float)  + i * 4 * sizeof(float))));
    }      }

}

#endif


// right-k4
#if 1
/* kernel function */
__kernel void kernel_4(
  __global unsigned char* const srcImageSrc,
  int srcImageSrcWidth,
  int srcImageSrcHeight,
  int srcImageSrcStep,
  int srcImageSrcShift,
  __global float* const mpSrc,
  int mpSrcWidth,
  int mpSrcHeight,
  int mpSrcStep,
  int mpSrcShift,
  __global unsigned char *dstImageDst,
  int dstImageDstWidth,
  int dstImageDstHeight,
  int dstImageDstStep,
  int dstImageDstShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if (gidx >= 256-1 || gidy >= 256-1)
   return;

  /* kernel index calculation */
  int srcImageSrcIdx2 = srcImageSrcShift + ((float)gidy) *srcImageSrcStep + ((float)gidx) *sizeof(unsigned char);
  int dstImageDstIdx1 = dstImageDstShift + ((float)gidy * 4 + 2) *dstImageDstStep + ((float)gidx * 4 + 2) *sizeof(unsigned char);

  /* kernel operands */
  __global float *mpSrcDt1 = (__global char*)mpSrc + mpSrcShift;
  __global unsigned char *srcImageSrcDt2 = srcImageSrc + srcImageSrcIdx2;
  __global unsigned char *dstImageDstDt1 = dstImageDst + dstImageDstIdx1;

  /* kernel operation */
  {
        char result0[4][4];
        char *result0_0;
        char *result0_1;
        char *result0_2;
        char *result0_3;

       result0_0 = (char*)result0;
       result0_1 = result0_0 + sizeof(char) * 4;
       result0_2 = result0_1 + sizeof(char) * 4;
       result0_3 = result0_2 + sizeof(char) * 4;

       mpSrcStep = mpSrcStep/4;

    //float mp[4][2] = { 7 / 8.0f, 1 / 8.0f, 5 / 8.0f, 3 / 8.0f, 3 / 8.0f, 5 / 8.0f, 1 / 8.0f, 7 / 8.0f };

       *(result0_0+0) = (char)(    (*(mpSrcDt1+0+0*mpSrcStep) * *(srcImageSrcDt2+0+0*srcImageSrcStep) 
                                +  (*(mpSrcDt1+1+0*mpSrcStep) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *(mpSrcDt1+0+0*mpSrcStep) 
                                +  (*(mpSrcDt1+0+0*mpSrcStep) * *(srcImageSrcDt2+1+0*srcImageSrcStep) 
                                +  (*(mpSrcDt1+1+0*mpSrcStep) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *(mpSrcDt1+1+0*mpSrcStep));

       *(result0_0+1) = (char)(    (*(mpSrcDt1+0+0*mpSrcStep) * *(srcImageSrcDt2+0+0*srcImageSrcStep) 
                                 + (*(mpSrcDt1+1+0*mpSrcStep) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *(mpSrcDt1+0+1*mpSrcStep) 
                                 + (*(mpSrcDt1+0+0*mpSrcStep) * *(srcImageSrcDt2+1+0*srcImageSrcStep) 
                                 + (*(mpSrcDt1+1+0*mpSrcStep) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *(mpSrcDt1+1+1*mpSrcStep));

       *(result0_0+2) = (char)(    (*(mpSrcDt1+0+0*mpSrcStep) * *(srcImageSrcDt2+0+0*srcImageSrcStep) 
                                 + (*(mpSrcDt1+1+0*mpSrcStep) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *(mpSrcDt1+0+2*mpSrcStep) 
                                 + (*(mpSrcDt1+0+0*mpSrcStep) * *(srcImageSrcDt2+1+0*srcImageSrcStep) 
                                 + (*(mpSrcDt1+1+0*mpSrcStep) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *(mpSrcDt1+1+2*mpSrcStep));

       *(result0_0+3) = (char)(    (*(mpSrcDt1+0+0*mpSrcStep) * *(srcImageSrcDt2+0+0*srcImageSrcStep) 
                             +     (*(mpSrcDt1+1+0*mpSrcStep) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *(mpSrcDt1+0+3*mpSrcStep) 
                             +     (*(mpSrcDt1+0+0*mpSrcStep) * *(srcImageSrcDt2+1+0*srcImageSrcStep) 
                             +     (*(mpSrcDt1+1+0*mpSrcStep) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *(mpSrcDt1+1+3*mpSrcStep));
       *(result0_1+0) = (char)(    (*(mpSrcDt1+0+1*mpSrcStep) * *(srcImageSrcDt2+0+0*srcImageSrcStep) 
                             +     (*(mpSrcDt1+1+1*mpSrcStep) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *(mpSrcDt1+0+0*mpSrcStep) 
                             +     (*(mpSrcDt1+0+1*mpSrcStep) * *(srcImageSrcDt2+1+0*srcImageSrcStep) 
                             +     (*(mpSrcDt1+1+1*mpSrcStep) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *(mpSrcDt1+1+0*mpSrcStep));

       *(result0_1+1) = (char)(    (*(mpSrcDt1+0+1*mpSrcStep) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*(mpSrcDt1+1+1*mpSrcStep) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *(mpSrcDt1+0+1*mpSrcStep) +     (*(mpSrcDt1+0+1*mpSrcStep) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*(mpSrcDt1+1+1*mpSrcStep) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *(mpSrcDt1+1+1*mpSrcStep));
       *(result0_1+2) = (char)(    (*(mpSrcDt1+0+1*mpSrcStep) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*(mpSrcDt1+1+1*mpSrcStep) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *(mpSrcDt1+0+2*mpSrcStep) +     (*(mpSrcDt1+0+1*mpSrcStep) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*(mpSrcDt1+1+1*mpSrcStep) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *(mpSrcDt1+1+2*mpSrcStep));
       *(result0_1+3) = (char)(    (*(mpSrcDt1+0+1*mpSrcStep) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*(mpSrcDt1+1+1*mpSrcStep) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *(mpSrcDt1+0+3*mpSrcStep) +     (*(mpSrcDt1+0+1*mpSrcStep) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*(mpSrcDt1+1+1*mpSrcStep) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *(mpSrcDt1+1+3*mpSrcStep));
       *(result0_2+0) = (char)(    (*(mpSrcDt1+0+2*mpSrcStep) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*(mpSrcDt1+1+2*mpSrcStep) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *(mpSrcDt1+0+0*mpSrcStep) +     (*(mpSrcDt1+0+2*mpSrcStep) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*(mpSrcDt1+1+2*mpSrcStep) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *(mpSrcDt1+1+0*mpSrcStep));
       *(result0_2+1) = (char)(    (*(mpSrcDt1+0+2*mpSrcStep) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*(mpSrcDt1+1+2*mpSrcStep) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *(mpSrcDt1+0+1*mpSrcStep) +     (*(mpSrcDt1+0+2*mpSrcStep) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*(mpSrcDt1+1+2*mpSrcStep) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *(mpSrcDt1+1+1*mpSrcStep));
       *(result0_2+2) = (char)(    (*(mpSrcDt1+0+2*mpSrcStep) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*(mpSrcDt1+1+2*mpSrcStep) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *(mpSrcDt1+0+2*mpSrcStep) +     (*(mpSrcDt1+0+2*mpSrcStep) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*(mpSrcDt1+1+2*mpSrcStep) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *(mpSrcDt1+1+2*mpSrcStep));
       *(result0_2+3) = (char)(    (*(mpSrcDt1+0+2*mpSrcStep) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*(mpSrcDt1+1+2*mpSrcStep) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *(mpSrcDt1+0+3*mpSrcStep) +     (*(mpSrcDt1+0+2*mpSrcStep) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*(mpSrcDt1+1+2*mpSrcStep) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *(mpSrcDt1+1+3*mpSrcStep));
       *(result0_3+0) = (char)(    (*(mpSrcDt1+0+3*mpSrcStep) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*(mpSrcDt1+1+3*mpSrcStep) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *(mpSrcDt1+0+0*mpSrcStep) +     (*(mpSrcDt1+0+3*mpSrcStep) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*(mpSrcDt1+1+3*mpSrcStep) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *(mpSrcDt1+1+0*mpSrcStep));
       *(result0_3+1) = (char)(    (*(mpSrcDt1+0+3*mpSrcStep) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*(mpSrcDt1+1+3*mpSrcStep) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *(mpSrcDt1+0+1*mpSrcStep) +     (*(mpSrcDt1+0+3*mpSrcStep) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*(mpSrcDt1+1+3*mpSrcStep) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *(mpSrcDt1+1+1*mpSrcStep));
       *(result0_3+2) = (char)(    (*(mpSrcDt1+0+3*mpSrcStep) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*(mpSrcDt1+1+3*mpSrcStep) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *(mpSrcDt1+0+2*mpSrcStep) +     (*(mpSrcDt1+0+3*mpSrcStep) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*(mpSrcDt1+1+3*mpSrcStep) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *(mpSrcDt1+1+2*mpSrcStep));
       *(result0_3+3) = (char)(    (*(mpSrcDt1+0+3*mpSrcStep) * *(srcImageSrcDt2+0+0*srcImageSrcStep) +     (*(mpSrcDt1+1+3*mpSrcStep) * *(srcImageSrcDt2+0+1*srcImageSrcStep) ))     * *(mpSrcDt1+0+3*mpSrcStep) +     (*(mpSrcDt1+0+3*mpSrcStep) * *(srcImageSrcDt2+1+0*srcImageSrcStep) +     (*(mpSrcDt1+1+3*mpSrcStep) * *(srcImageSrcDt2+1+1*srcImageSrcStep) ))     * *(mpSrcDt1+1+3*mpSrcStep));
    
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++){
    *(dstImageDstDt1 + j + i * dstImageDstStep) = *(( char*)result0 + j + i * 4 * sizeof(char));
    }       }

}
#endif

#if 1
// auto
/* kernel function */
__kernel void kernel_5(
  __global unsigned char* const yPlaneSrc,
  int yPlaneSrcWidth,
  int yPlaneSrcHeight,
  int yPlaneSrcStep,
  int yPlaneSrcShift,
  __global char* const gxSrc,
  int gxSrcWidth,
  int gxSrcHeight,
  int gxSrcStep,
  int gxSrcShift,
  __global char* const gySrc,
  int gySrcWidth,
  int gySrcHeight,
  int gySrcStep,
  int gySrcShift,
  __global unsigned short *pEdgeDst,
  int pEdgeDstWidth,
  int pEdgeDstHeight,
  int pEdgeDstStep,
  int pEdgeDstShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if ( gidx   >=  (1024/4) || gidy >= 1024)
   return;

  /* kernel index calculation */
  int yPlaneSrcIdx3 = yPlaneSrcShift + ((float)gidy  -1) *yPlaneSrcStep + ((float)gidx *4 -1) *sizeof(unsigned char);
  int pEdgeDstIdx1 = pEdgeDstShift + ((float)gidy) *pEdgeDstStep + ((float)gidx *4) *sizeof(unsigned short);

  /* kernel operands */
  __global char *gxSrcDt1 = gxSrc + gxSrcShift;
  __global char *gySrcDt2 = gySrc + gySrcShift;
  __global unsigned char *yPlaneSrcDt3 = yPlaneSrc + yPlaneSrcIdx3;
  __global unsigned short *pEdgeDstDt1 = (__global unsigned short *)((__global char *)pEdgeDst + pEdgeDstIdx1);


  if(gidy == 0 || gidy == 1023)
  {
      *((global short4*)(pEdgeDstDt1))= (short4)0;
      return;
  }


  /* kernel operation */
  {
        char gy[3];
    uchar4 yPlane;
   uchar  R2Next;
    short4 res1;
    {
      gy[0] = *(gySrcDt2 + 0 + gySrcStep * 0);
      gy[1] = *(gySrcDt2 + 1 + gySrcStep * 0);
      gy[2] = *(gySrcDt2 + 2 + gySrcStep * 0);

      yPlane = (vload4(0, yPlaneSrcDt3 + 0 * yPlaneSrcStep + 4 * 0));

      res1.s0 = gy[0] * yPlane.s0 + gy[1] * yPlane.s1 + gy[2] * yPlane.s2;
      res1.s1 = gy[0] * yPlane.s1 + gy[1] * yPlane.s2 + gy[2] * yPlane.s3;
      res1.s2 = gy[0] * yPlane.s2 + gy[1] * yPlane.s3;

      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 0);
      res1.s2 += gy[2] * R2Next; 

      res1.s3 = gy[0] * yPlane.s3;
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 0);
      res1.s3 += gy[1] * R2Next; 
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 1);
      res1.s3 += gy[2] * R2Next; 

      gy[0] = *(gySrcDt2 + 0 + gySrcStep * 1);
      gy[1] = *(gySrcDt2 + 1 + gySrcStep * 1);
      gy[2] = *(gySrcDt2 + 2 + gySrcStep * 1);
      yPlane = (vload4(0, yPlaneSrcDt3 + 1 * yPlaneSrcStep + 4 * 0));

      res1.s0 += gy[0] * yPlane.s0 + gy[1] * yPlane.s1 + gy[2] * yPlane.s2;
      res1.s1 += gy[0] * yPlane.s1 + gy[1] * yPlane.s2 + gy[2] * yPlane.s3;
      res1.s2 += gy[0] * yPlane.s2 + gy[1] * yPlane.s3;

      R2Next = *(yPlaneSrcDt3 + 4 * 1 +  1 * yPlaneSrcStep+ 0);
      res1.s2 += gy[2] * R2Next; 
      res1.s3 += gy[0] * yPlane.s3;
      R2Next = *(yPlaneSrcDt3 + 4 * 1 +  1 * yPlaneSrcStep+ 0);
      res1.s3 += gy[1] * R2Next; 
      R2Next = *(yPlaneSrcDt3 + 4 * 1 +  1 * yPlaneSrcStep+ 1);
      res1.s3 += gy[2] * R2Next; 

      gy[0] = *(gySrcDt2 + 0 + gySrcStep * 2);
      gy[1] = *(gySrcDt2 + 1 + gySrcStep * 2);
      gy[2] = *(gySrcDt2 + 2 + gySrcStep * 2);

      yPlane = (vload4(0, yPlaneSrcDt3 + 2 * yPlaneSrcStep + 4 * 0));
      res1.s0 += gy[0] * yPlane.s0 + gy[1] * yPlane.s1 + gy[2] * yPlane.s2;
      res1.s1 += gy[0] * yPlane.s1 + gy[1] * yPlane.s2 + gy[2] * yPlane.s3;
      res1.s2 += gy[0] * yPlane.s2 + gy[1] * yPlane.s3;

      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 2 * yPlaneSrcStep+ 0);
      res1.s2 += gy[2] * R2Next; 
      res1.s3 += gy[0] * yPlane.s3;
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 2 * yPlaneSrcStep+ 0);
      res1.s3 += gy[1] * R2Next; 
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 2 * yPlaneSrcStep+ 1);
      res1.s3 += gy[2] * R2Next; 
    }
        char gx[3];
    short4 res2;
    {
      gx[0] = *(gxSrcDt1 + 0 + gxSrcStep * 0);
      gx[1] = *(gxSrcDt1 + 1 + gxSrcStep * 0);
      gx[2] = *(gxSrcDt1 + 2 + gxSrcStep * 0);
      yPlane = (vload4(0, yPlaneSrcDt3 + 0 * yPlaneSrcStep + 4 * 0));
      res2.s0 = gx[0] * yPlane.s0 + gx[1] * yPlane.s1 + gx[2] * yPlane.s2;
      res2.s1 = gx[0] * yPlane.s1 + gx[1] * yPlane.s2 + gx[2] * yPlane.s3;
      res2.s2 = gx[0] * yPlane.s2 + gx[1] * yPlane.s3;
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 0);
      res2.s2 += gx[2] * R2Next; 
      res2.s3 = gx[0] * yPlane.s3;
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 0);
      res2.s3 += gx[1] * R2Next; 
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 1);
      res2.s3 += gx[2] * R2Next; 
      gx[0] = *(gxSrcDt1 + 0 + gxSrcStep * 1);
      gx[1] = *(gxSrcDt1 + 1 + gxSrcStep * 1);
      gx[2] = *(gxSrcDt1 + 2 + gxSrcStep * 1);
      yPlane = (vload4(0, yPlaneSrcDt3 + 1 * yPlaneSrcStep + 4 * 0));
      res2.s0 += gx[0] * yPlane.s0 + gx[1] * yPlane.s1 + gx[2] * yPlane.s2;
      res2.s1 += gx[0] * yPlane.s1 + gx[1] * yPlane.s2 + gx[2] * yPlane.s3;
      res2.s2 += gx[0] * yPlane.s2 + gx[1] * yPlane.s3;
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 1 * yPlaneSrcStep+ 0);
      res2.s2 += gx[2] * R2Next; 
      res2.s3 += gx[0] * yPlane.s3;
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 1 * yPlaneSrcStep+ 0);
      res2.s3 += gx[1] * R2Next; 
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 1 * yPlaneSrcStep+ 1);
      res2.s3 += gx[2] * R2Next; 
      gx[0] = *(gxSrcDt1 + 0 + gxSrcStep * 2);
      gx[1] = *(gxSrcDt1 + 1 + gxSrcStep * 2);
      gx[2] = *(gxSrcDt1 + 2 + gxSrcStep * 2);
      yPlane = (vload4(0, yPlaneSrcDt3 + 2 * yPlaneSrcStep + 4 * 0));
      res2.s0 += gx[0] * yPlane.s0 + gx[1] * yPlane.s1 + gx[2] * yPlane.s2;
      res2.s1 += gx[0] * yPlane.s1 + gx[1] * yPlane.s2 + gx[2] * yPlane.s3;
      res2.s2 += gx[0] * yPlane.s2 + gx[1] * yPlane.s3;
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 2 * yPlaneSrcStep + 0);
      res2.s2 += gx[2] * R2Next; 
      res2.s3 += gx[0] * yPlane.s3;
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 2 * yPlaneSrcStep + 0);
      res2.s3 += gx[1] * R2Next; 
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 2 * yPlaneSrcStep + 1);
      res2.s3 += gx[2] * R2Next; 
    }
    ushort4 temp0;
    ushort4 temp1;
temp0 = convert_ushort4(abs(res2) + abs(res1));
    if(gidx == 0)
        temp0.s0 = 0;

    if(gidx == 255)
        temp0.s3 = 0;


    /*
    *pEdgeDstDt1 = temp1.s0;
    *(pEdgeDstDt1 + 1) = temp1.s1;
    *(pEdgeDstDt1 + 2) = temp1.s2;
    *(pEdgeDstDt1 + 3) = temp1.s3;
    */
    *pEdgeDstDt1 = temp0.s0;
    *(pEdgeDstDt1 + 1) = temp0.s1;
    *(pEdgeDstDt1 + 2) = temp0.s2;
    *(pEdgeDstDt1 + 3) = temp0.s3;


/*
    if (gidx == 0 || gidy == 0 || gidx == 1024 - 1 || gidy == 1024 - 1)
      temp1 = 0;
    else
      temp0 = convert_ushort4(abs(res2) + abs(res1));
    *pEdgeDstDt1 = temp1.s0;
    *(pEdgeDstDt1 + 1) = temp1.s1;
    *(pEdgeDstDt1 + 2) = temp1.s2;
    *(pEdgeDstDt1 + 3) = temp1.s3;
    *pEdgeDstDt1 = temp0.s0;
    *(pEdgeDstDt1 + 1) = temp0.s1;
    *(pEdgeDstDt1 + 2) = temp0.s2;
    *(pEdgeDstDt1 + 3) = temp0.s3;
*/  }

}

#endif


#if 0
// right 
/* kernel function */
__kernel void kernel_5(
  __global unsigned char* const yPlaneSrc,
  int yPlaneSrcWidth,
  int yPlaneSrcHeight,
  int yPlaneSrcStep,
  int yPlaneSrcShift,
  __global char* const gxSrc,
  int gxSrcWidth,
  int gxSrcHeight,
  int gxSrcStep,
  int gxSrcShift,
  __global char* const gySrc,
  int gySrcWidth,
  int gySrcHeight,
  int gySrcStep,
  int gySrcShift,
  __global unsigned short *pEdgeDst,
  int pEdgeDstWidth,
  int pEdgeDstHeight,
  int pEdgeDstStep,
  int pEdgeDstShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if (gidx >= 256 || gidy >= 1024)
   return;

  /* kernel index calculation */
  //int yPlaneSrcIdx3 = yPlaneSrcShift + ((float)gidy -1) *yPlaneSrcStep + ((float)gidx -1) *sizeof(unsigned char);

  int yPlaneSrcIdx3 = yPlaneSrcShift + ((float)gidy -1) *yPlaneSrcStep + ((float)gidx*4 -1) *sizeof(unsigned char);

  int pEdgeDstIdx1 = pEdgeDstShift + ((float)gidy) *pEdgeDstStep + ((float)gidx*4) *sizeof(unsigned short);

  /* kernel operands */
  __global char *gxSrcDt1 = gxSrc + gxSrcShift;
  __global char *gySrcDt2 = gySrc + gySrcShift;

  __global unsigned char *yPlaneSrcDt3 = yPlaneSrc + yPlaneSrcIdx3;
  __global unsigned short *pEdgeDstDt1 = (__global unsigned short*)((__global char*)pEdgeDst + pEdgeDstIdx1);

  if(gidy == 0 || gidy == 1023)
  {
      *((global short4*)(pEdgeDstDt1))= (short4)0;
      return;
  }

  /* kernel operation */
  {
        char gy[3];
    uchar4 yPlane;
    uchar  R2Next;
    short4 res;
    {

      gy[0] = *(gySrcDt2 + 0 + gxSrcStep * 0);
      gy[1] = *(gySrcDt2 + 1 + gxSrcStep * 0);
      gy[2] = *(gySrcDt2 + 2 + gxSrcStep * 0);

      yPlane = vload4(0, yPlaneSrcDt3 + 4 * 0);

      res.s0 = gy[0] * yPlane.s0 + gy[1] * yPlane.s1 + gy[2] * yPlane.s2;
      res.s1 = gy[0] * yPlane.s1 + gy[1] * yPlane.s2 + gy[2] * yPlane.s3;
      res.s2 = gy[0] * yPlane.s2 + gy[1] * yPlane.s3;

      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 0);
      res.s2 += gy[2] * R2Next; 

      res.s3 = gy[0] * yPlane.s3;
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 0);
      res.s3 += gy[1] * R2Next; 
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 1);
      res.s3 += gy[2] * R2Next; 

      yPlaneSrcDt3 = yPlaneSrcDt3 + yPlaneSrcStep;
      gy[0] = *(gySrcDt2 + 0 + gxSrcStep * 1);
      gy[1] = *(gySrcDt2 + 1 + gxSrcStep * 1);
      gy[2] = *(gySrcDt2 + 2 + gxSrcStep * 1);
      yPlane = vload4(0, yPlaneSrcDt3 + 4 * 0);

      res.s0 += gy[0] * yPlane.s0 + gy[1] * yPlane.s1 + gy[2] * yPlane.s2;
      res.s1 += gy[0] * yPlane.s1 + gy[1] * yPlane.s2 + gy[2] * yPlane.s3;
      res.s2 += gy[0] * yPlane.s2 + gy[1] * yPlane.s3;

      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 0);
      res.s2 += gy[2] * R2Next; 
      res.s3 += gy[0] * yPlane.s3;
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 0);
      res.s3 += gy[1] * R2Next; 
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 1);
      res.s3 += gy[2] * R2Next; 

      yPlaneSrcDt3 = yPlaneSrcDt3 + yPlaneSrcStep;
      gy[0] = *(gySrcDt2 + 0 + gxSrcStep * 2);
      gy[1] = *(gySrcDt2 + 1 + gxSrcStep * 2);
      gy[2] = *(gySrcDt2 + 2 + gxSrcStep * 2);
      //yPlane = *(yPlaneSrcDt3 + 4 * 0);
      //yPlane = *((__global uchar4*)(yPlaneSrcDt3 + 4 * 0));
      yPlane = vload4(0, yPlaneSrcDt3 + 4 * 0);
      res.s0 += gy[0] * yPlane.s0 + gy[1] * yPlane.s1 + gy[2] * yPlane.s2;
      res.s1 += gy[0] * yPlane.s1 + gy[1] * yPlane.s2 + gy[2] * yPlane.s3;
      res.s2 += gy[0] * yPlane.s2 + gy[1] * yPlane.s3;

      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 0);
      res.s2 += gy[2] * R2Next; 
      res.s3 += gy[0] * yPlane.s3;
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 0);
      res.s3 += gy[1] * R2Next; 
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 1);
      res.s3 += gy[2] * R2Next; 
    }

    yPlaneSrcDt3 -= yPlaneSrcStep*2;

    ushort4 temp0= convert_ushort4(abs(res));
        char gx[3];
    {
      gx[0] = *(gxSrcDt1 + 0 + gxSrcStep * 0);
      gx[1] = *(gxSrcDt1 + 1 + gxSrcStep * 0);
      gx[2] = *(gxSrcDt1 + 2 + gxSrcStep * 0);
      yPlane = vload4(0, yPlaneSrcDt3 + 4 * 0);
      res.s0 = gx[0] * yPlane.s0 + gx[1] * yPlane.s1 + gx[2] * yPlane.s2;
      res.s1 = gx[0] * yPlane.s1 + gx[1] * yPlane.s2 + gx[2] * yPlane.s3;
      res.s2 = gx[0] * yPlane.s2 + gx[1] * yPlane.s3;

      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 0);
      res.s2 += gx[2] * R2Next; 
      res.s3 = gx[0] * yPlane.s3;
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 0);
      res.s3 += gx[1] * R2Next; 
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 1);
      res.s3 += gx[2] * R2Next; 
      yPlaneSrcDt3 = yPlaneSrcDt3 + yPlaneSrcStep;
      gx[0] = *(gxSrcDt1 + 0 + gxSrcStep * 1);
      gx[1] = *(gxSrcDt1 + 1 + gxSrcStep * 1);
      gx[2] = *(gxSrcDt1 + 2 + gxSrcStep * 1);
      yPlane = vload4(0, yPlaneSrcDt3 + 4 * 0);
      res.s0 += gx[0] * yPlane.s0 + gx[1] * yPlane.s1 + gx[2] * yPlane.s2;
      res.s1 += gx[0] * yPlane.s1 + gx[1] * yPlane.s2 + gx[2] * yPlane.s3;
      res.s2 += gx[0] * yPlane.s2 + gx[1] * yPlane.s3;

      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 0);
      res.s2 += gx[2] * R2Next; 
      res.s3 += gx[0] * yPlane.s3;
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 0);
      res.s3 += gx[1] * R2Next; 
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 1);
      res.s3 += gx[2] * R2Next; 
      yPlaneSrcDt3 = yPlaneSrcDt3 + yPlaneSrcStep;
      gx[0] = *(gxSrcDt1 + 0 + gxSrcStep * 2);
      gx[1] = *(gxSrcDt1 + 1 + gxSrcStep * 2);
      gx[2] = *(gxSrcDt1 + 2 + gxSrcStep * 2);
      yPlane = vload4(0, yPlaneSrcDt3 + 4 * 0);
      res.s0 += gx[0] * yPlane.s0 + gx[1] * yPlane.s1 + gx[2] * yPlane.s2;
      res.s1 += gx[0] * yPlane.s1 + gx[1] * yPlane.s2 + gx[2] * yPlane.s3;
      res.s2 += gx[0] * yPlane.s2 + gx[1] * yPlane.s3;

      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 0);
      res.s2 += gx[2] * R2Next; 
      res.s3 += gx[0] * yPlane.s3;
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 0);
      res.s3 += gx[1] * R2Next; 
      R2Next = *(yPlaneSrcDt3 + 4 * 1 + 1);
      res.s3 += gx[2] * R2Next; 
    }

    temp0 += convert_ushort4(abs(res));
    if(gidx == 0)
        temp0.s0 = 0;

    if(gidx == 255)
        temp0.s3 = 0;


    /*
    *pEdgeDstDt1 = temp1.s0;
    *(pEdgeDstDt1 + 1) = temp1.s1;
    *(pEdgeDstDt1 + 2) = temp1.s2;
    *(pEdgeDstDt1 + 3) = temp1.s3;
    */
    *pEdgeDstDt1 = temp0.s0;
    *(pEdgeDstDt1 + 1) = temp0.s1;
    *(pEdgeDstDt1 + 2) = temp0.s2;
    *(pEdgeDstDt1 + 3) = temp0.s3;
  }
}
#endif


#if 0
// auto
/* kernel function */
__kernel void kernel_6(
  __global unsigned short* const pEdgeSrc,
  int pEdgeSrcWidth,
  int pEdgeSrcHeight,
  int pEdgeSrcStep,
  int pEdgeSrcShift,
  __global unsigned short * _gtmpDst,
  __local unsigned int * _ltmp0)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);
  const int lidx = get_local_id(0);
  const int lidy = get_local_id(1);
  const int gridx = get_group_id(0);
  const int gridy = get_group_id(1);
  const int lsizex = get_local_size(0);
  const int lsize = lsizex * get_local_size(1);
  const int grsizex = get_num_groups(0);
  const int lid= mad24(lidy, lsizex, lidx);

  /* kernel boundary check */

  /* kernel index calculation */
  int pEdgeSrcIdx1 = pEdgeSrcShift+ ( gidx << 2 ) * sizeof(unsigned short)+ (float)gidy * pEdgeSrcStep;

  /* kernel operands */
  __global unsigned short *pEdgeSrcDt1 = (__global char *)pEdgeSrc + pEdgeSrcIdx1;

  /* kernel operation */
  ushort4 _rtmp0;
  if ((gidx << 2 ) < pEdgeSrcWidth && gidy < pEdgeSrcHeight)
  {
  _rtmp0 = *( ( __global ushort4* )pEdgeSrcDt1 );
  *( _ltmp0 + lid) =    _rtmp0.s0   +    _rtmp0.s1   +    _rtmp0.s2   +    _rtmp0.s3  ;
  }
  barrier(CLK_LOCAL_MEM_FENCE);

  if ((gidx << 2 ) < pEdgeSrcWidth && gidy < pEdgeSrcHeight)
  {
      if (lid < 128)
        *(_ltmp0 + lid) += *(_ltmp0 + lid + 128);
  }
  barrier(CLK_LOCAL_MEM_FENCE);

if ((gidx << 2 ) < pEdgeSrcWidth && gidy < pEdgeSrcHeight)
  {
  if (lid < 64)
  {
      *(_ltmp0 + lid) += *(_ltmp0 + lid + 64);
    *(_ltmp0 + lid) += *(_ltmp0 + lid + 32);
    *(_ltmp0 + lid) += *(_ltmp0 + lid + 16);
    *(_ltmp0 + lid) += *(_ltmp0 + lid + 8);
    *(_ltmp0 + lid) += *(_ltmp0 + lid + 4);
    *(_ltmp0 + lid) += *(_ltmp0 + lid + 2);
    *(_ltmp0 + lid) += *(_ltmp0 + lid + 1);
  if (lid < 1)
  atomic_add((__global int*) _gtmpDst, (int)_ltmp0[0]);
  }
  }

}

#endif

#if 1
// right

/* kernel function */
__kernel void kernel_6(
  __global unsigned short* const pEdgeSrc,
  int pEdgeSrcWidth,
  int pEdgeSrcHeight,
  int pEdgeSrcStep,
  int pEdgeSrcShift,
  __global int * _gtmpDst,
  __local  int * _ltmp0)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);
  const int lidx = get_local_id(0);
  const int lidy = get_local_id(1);
  const int gridx = get_group_id(0);
  const int gridy = get_group_id(1);
  const int lsizex = get_local_size(0);
  const int lsize = lsizex * get_local_size(1);
  const int grsizex = get_num_groups(0);
  const int lid= mad24(lidy, lsizex, lidx);

  /* kernel boundary check */

  /* kernel index calculation */
  int pEdgeSrcIdx1 = pEdgeSrcShift+ ( gidx << 2 ) * sizeof(unsigned short)+ (float)gidy * pEdgeSrcStep;

  /* kernel operands */

  /* kernel operation */
  //ushort4 _rtmp0;
  ushort4 _rtmp0=(0,0,0,0);

  if ((gidx << 2 ) < pEdgeSrcWidth && gidy < pEdgeSrcHeight)
  {
        _rtmp0 = *( ( __global ushort4* )((__global char *)pEdgeSrc + pEdgeSrcIdx1));
  }

 *( _ltmp0 + lid) = (int)( _rtmp0.s0   +    _rtmp0.s1   +    _rtmp0.s2   +    _rtmp0.s3)  ;
  barrier(CLK_LOCAL_MEM_FENCE);

  if ((gidx << 2 ) < pEdgeSrcWidth && gidy < pEdgeSrcHeight)
  {
      if (lid < 128)
        *(_ltmp0 + lid) += *(_ltmp0 + lid + 128);
  }
  barrier(CLK_LOCAL_MEM_FENCE);

if ((gidx << 2 ) < pEdgeSrcWidth && gidy < pEdgeSrcHeight)
  {
  if (lid < 64)
     *(_ltmp0 + lid) += *(_ltmp0 + lid + 64);
  }
  barrier(CLK_LOCAL_MEM_FENCE);

if ((gidx << 2 ) < pEdgeSrcWidth && gidy < pEdgeSrcHeight)
{
  if (lid < 32)
    *(_ltmp0 + lid) += *(_ltmp0 + lid + 32);
  if (lid < 16)
    *(_ltmp0 + lid) += *(_ltmp0 + lid + 16);
  if (lid < 8)
    *(_ltmp0 + lid) += *(_ltmp0 + lid + 8);
  if (lid < 4)
    *(_ltmp0 + lid) += *(_ltmp0 + lid + 4);
  if (lid < 2)
    *(_ltmp0 + lid) += *(_ltmp0 + lid + 2);
  if (lid < 1)
  {
    *(_ltmp0 + lid) += *(_ltmp0 + lid + 1);
    atomic_add((__global int*)_gtmpDst, (int)_ltmp0[0]);
  }
  }
}
#endif

#if 1
// auto
/* kernel function */
__kernel void kernel_7(
  __global unsigned char* const yPlaneSrc,
  int yPlaneSrcWidth,
  int yPlaneSrcHeight,
  int yPlaneSrcStep,
  int yPlaneSrcShift,
  __global unsigned char* const yPlaneCSERSrc,
  int yPlaneCSERSrcWidth,
  int yPlaneCSERSrcHeight,
  int yPlaneCSERSrcStep,
  int yPlaneCSERSrcShift,
  __global unsigned short* const pEdgeSrc,
  int pEdgeSrcWidth,
  int pEdgeSrcHeight,
  int pEdgeSrcStep,
  int pEdgeSrcShift,
  float cutoff2Order,
  float m1,
  float m2,
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
  if ( gidx   >=  (1024/4) || gidy >= 1024)
   return;

  /* kernel index calculation */
  int pEdgeSrcIdx4 = pEdgeSrcShift + ((float)gidy) *pEdgeSrcStep + ((float)gidx *4) *sizeof(unsigned short);
  int yPlaneSrcIdx5 = yPlaneSrcShift + ((float)gidy + -1) *yPlaneSrcStep + ((float)gidx *4 + -1) *sizeof(unsigned char);
  int yPlaneSrcIdx6 = yPlaneSrcShift + ((float)gidy) *yPlaneSrcStep + ((float)gidx *4) *sizeof(unsigned char);
  int yPlaneCSERSrcIdx7 = yPlaneCSERSrcShift + ((float)gidy) *yPlaneCSERSrcStep + ((float)gidx *4) *sizeof(unsigned char);
  int dstDstIdx1 = dstDstShift + ((float)gidy) *dstDstStep + ((float)gidx *4) *sizeof(unsigned char);

  /* kernel operands */
  __global unsigned short *pEdgeSrcDt4 = (__global unsigned short*)((__global char *)pEdgeSrc + pEdgeSrcIdx4);
  __global unsigned char *yPlaneSrcDt5 = yPlaneSrc + yPlaneSrcIdx5;
  __global unsigned char *yPlaneSrcDt6 = yPlaneSrc + yPlaneSrcIdx6;
  __global unsigned char *yPlaneCSERSrcDt7 = yPlaneCSERSrc + yPlaneCSERSrcIdx7;
  __global unsigned char *dstDstDt1 = dstDst + dstDstIdx1;

  /* kernel operation */
  {
        
  uchar4 tans;
    
  uchar4 pSrctemp;
    
  uchar pSrcnext;
    
  __global uchar *yPlaneSrcDt5Ptr = yPlaneSrcDt5; 
;
      tans = vload4(0, yPlaneSrcDt5Ptr);
      pSrctemp = vload4(0, yPlaneSrcDt5Ptr);

      pSrcnext = *(yPlaneSrcDt5Ptr +     4);
      pSrctemp = pSrctemp.s1230;
      pSrctemp.s3     = pSrcnext;
      tans = max(tans, pSrctemp);
    
      pSrcnext = *(yPlaneSrcDt5Ptr +     5);
      pSrctemp = pSrctemp.s1230;
      pSrctemp.s3     = pSrcnext;
      tans = max(tans, pSrctemp);
    
      yPlaneSrcDt5Ptr = yPlaneSrcDt5Ptr + yPlaneSrcStep * 1;
    
        pSrctemp = vload4(0, yPlaneSrcDt5Ptr);
    tans = max(tans, pSrctemp);

      //pSrctemp = vload4(0, yPlaneSrcDt5Ptr);
      pSrcnext = *(yPlaneSrcDt5Ptr +     4);
      pSrctemp = pSrctemp.s1230;
      pSrctemp.s3     = pSrcnext;
      tans = max(tans, pSrctemp);
    
      pSrcnext = *(yPlaneSrcDt5Ptr +     5);
      pSrctemp = pSrctemp.s1230;
      pSrctemp.s3     = pSrcnext;
      tans = max(tans, pSrctemp);
    
      yPlaneSrcDt5Ptr = yPlaneSrcDt5Ptr + yPlaneSrcStep * 1;
    
        pSrctemp = vload4(0, yPlaneSrcDt5Ptr);
    tans = max(tans, pSrctemp);

      //pSrctemp = vload4(0, yPlaneSrcDt5Ptr);
      pSrcnext = *(yPlaneSrcDt5Ptr +     4);
      pSrctemp = pSrctemp.s1230;
      pSrctemp.s3     = pSrcnext;
      tans = max(tans, pSrctemp);
    
      pSrcnext = *(yPlaneSrcDt5Ptr +     5);
      pSrctemp = pSrctemp.s1230;
      pSrctemp.s3     = pSrcnext;
      tans = max(tans, pSrctemp);
    
      uchar4 max_ans1 = tans;
    uchar4 maxValue;
maxValue = convert_uchar4( max_ans1 );
        
  //uchar4 tans Exist;
    
  //uchar4 pSrctemp Exist;
    
  //uchar pSrcnext Exist;
    
  yPlaneSrcDt5Ptr = yPlaneSrcDt5; 
;
      tans = vload4(0, yPlaneSrcDt5Ptr);
      pSrctemp = vload4(0, yPlaneSrcDt5Ptr);

      pSrcnext = *(yPlaneSrcDt5Ptr +     4);
      pSrctemp = pSrctemp.s1230;
      pSrctemp.s3     = pSrcnext;
      tans = min(tans, pSrctemp);
    
      pSrcnext = *(yPlaneSrcDt5Ptr +     5);
      pSrctemp = pSrctemp.s1230;
      pSrctemp.s3     = pSrcnext;
      tans = min(tans, pSrctemp);
    
      yPlaneSrcDt5Ptr = yPlaneSrcDt5Ptr + yPlaneSrcStep * 1;
    
        pSrctemp = vload4(0, yPlaneSrcDt5Ptr);
    tans = min(tans, pSrctemp);

      //pSrctemp = vload4(0, yPlaneSrcDt5Ptr);
      pSrcnext = *(yPlaneSrcDt5Ptr +     4);
      pSrctemp = pSrctemp.s1230;
      pSrctemp.s3     = pSrcnext;
      tans = min(tans, pSrctemp);
    
      pSrcnext = *(yPlaneSrcDt5Ptr +     5);
      pSrctemp = pSrctemp.s1230;
      pSrctemp.s3     = pSrcnext;
      tans = min(tans, pSrctemp);
    
      yPlaneSrcDt5Ptr = yPlaneSrcDt5Ptr + yPlaneSrcStep * 1;

      pSrctemp = vload4(0, yPlaneSrcDt5Ptr);
      tans = min(tans, pSrctemp);

      //pSrctemp = vload4(0, yPlaneSrcDt5Ptr);
      pSrcnext = *(yPlaneSrcDt5Ptr +     4);
      pSrctemp = pSrctemp.s1230;
      pSrctemp.s3     = pSrcnext;
      tans = min(tans, pSrctemp);
    
      pSrcnext = *(yPlaneSrcDt5Ptr +     5);
      pSrctemp = pSrctemp.s1230;
      pSrctemp.s3     = pSrcnext;
      tans = min(tans, pSrctemp);

      uchar4 min_ans1 = tans;
      uchar4 minValue;
      minValue = convert_uchar4( min_ans1 );

      float4 Op_ans1 = convert_float4( *((__global uchar4*) yPlaneSrcDt6)) -convert_float4( *((__global uchar4*)yPlaneCSERSrcDt7));
      float4 pError;
      pError = convert_float4( Op_ans1 );
  
      // bug? short or ushort of pEdgeSrcDt ???
      ushort4 Op_ans2 =  *((__global ushort4*) pEdgeSrcDt4) * *((__global ushort4*)pEdgeSrcDt4);
      ushort4 MatrixSub_ans1 = *((__global ushort4*)(pEdgeSrcDt4)); // bug?? TODO
      ushort4 MatrixSub_ans2 = *((__global ushort4*)(pEdgeSrcDt4));
      float4 edge2Order = convert_float4(convert_ushort4(Op_ans2) * MatrixSub_ans1 * MatrixSub_ans2);

      float4 enhancedF = convert_float4(edge2Order * m1 + 1);
      float4 strength = convert_float4(edge2Order * m2 + 1);
      strength = convert_float4((enhancedF - 1) / (convert_float4(enhancedF * strength)) + 1);

      float4 MatrixSub_ans3 =convert_float4( *((__global uchar4*)yPlaneCSERSrcDt7)); // TODO
      enhancedF = convert_float4(pError * strength + convert_float4(MatrixSub_ans3));

      strength = convert_float4((0.05f * edge2Order + cutoff2Order) / (cutoff2Order + edge2Order));

      float4 pSharpness_value = convert_float4(enhancedF > 255 ? 255 : (enhancedF < 0 ? 0 : enhancedF));

      edge2Order = convert_float4(convert_float4(minValue) - strength * (convert_float4(minValue) - enhancedF));

      strength = convert_float4(convert_float4(maxValue) + strength * (enhancedF - convert_float4(maxValue)));
      strength = convert_float4(strength < 255 ? strength : 255);

   // bug?
    edge2Order = convert_float4(enhancedF < convert_float4(minValue) ? (edge2Order > 0 ? edge2Order : 0) : pSharpness_value);

    uchar4 temp7;
    temp7 = convert_uchar4(enhancedF > convert_float4(maxValue) ? strength : edge2Order);

    *dstDstDt1 = temp7.s0;
    *(dstDstDt1 + 1) = temp7.s1;
    *(dstDstDt1 + 2) = temp7.s2;
    *(dstDstDt1 + 3) = temp7.s3;
  }

}

#endif

#if 0
// right
/* kernel function */
__kernel void kernel_7(
  __global unsigned char* const yPlaneSrc,
  int yPlaneSrcWidth,
  int yPlaneSrcHeight,
  int yPlaneSrcStep,
  int yPlaneSrcShift,
  __global unsigned char* const yPlaneCSERSrc,
  int yPlaneCSERSrcWidth,
  int yPlaneCSERSrcHeight,
  int yPlaneCSERSrcStep,
  int yPlaneCSERSrcShift,
  __global unsigned short* const pEdgeSrc,
  int pEdgeSrcWidth,
  int pEdgeSrcHeight,
  int pEdgeSrcStep,
  int pEdgeSrcShift,
  float cutoff2Order,
  float m1,
  float m2,
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
  if (gidx >= 256 || gidy >= 1024)
   return;

  /* kernel index calculation */

  int pEdgeSrcIdx4      = pEdgeSrcShift      + ((float)gidy)    *pEdgeSrcStep      + ((float)gidx*4)    *sizeof(unsigned short);
  int yPlaneSrcIdx5     = yPlaneSrcShift     + ((float)gidy -1) *yPlaneSrcStep     + ((float)gidx*4 -1) *sizeof(unsigned char);
  int yPlaneSrcIdx6     = yPlaneSrcShift     + ((float)gidy)    *yPlaneSrcStep     + ((float)gidx*4)    *sizeof(unsigned char);
  int yPlaneCSERSrcIdx7 = yPlaneCSERSrcShift + ((float)gidy)    *yPlaneCSERSrcStep + ((float)gidx*4)    *sizeof(unsigned char);
  int dstDstIdx1        = dstDstShift        + ((float)gidy)    *dstDstStep        + ((float)gidx*4)     *sizeof(unsigned char);

  /* kernel operands */
  __global unsigned short *pEdgeSrcDt4 = (__global unsigned short*)((__global char*)pEdgeSrc + pEdgeSrcIdx4);
  __global unsigned char *yPlaneSrcDt5 = yPlaneSrc + yPlaneSrcIdx5;
  __global unsigned char *yPlaneSrcDt6 = yPlaneSrc + yPlaneSrcIdx6;
  __global unsigned char *yPlaneCSERSrcDt7 = yPlaneCSERSrc + yPlaneCSERSrcIdx7;
  __global unsigned char *dstDstDt1 = dstDst + dstDstIdx1;

  /* kernel operation */
  {
        
  uchar4 tans;
    
  uchar4 pSrctemp;
    
  uchar pSrcnext;

      tans = vload4(0, yPlaneSrcDt5);
      pSrctemp = vload4(0, yPlaneSrcDt5);

      pSrcnext = *(yPlaneSrcDt5 +     4);
      pSrctemp = pSrctemp.s1230;
      pSrctemp.s3     = pSrcnext;
      tans = max(tans, pSrctemp);
    
      pSrcnext = *(yPlaneSrcDt5 +     5);
      pSrctemp = pSrctemp.s1230;
      pSrctemp.s3     = pSrcnext;
      tans = max(tans, pSrctemp);
    
    
      yPlaneSrcDt5 += yPlaneSrcStep * 1;


      pSrctemp = vload4(0, yPlaneSrcDt5);
      tans = max(tans, pSrctemp);

      pSrcnext = *(yPlaneSrcDt5 +     4);
      pSrctemp = pSrctemp.s1230;
      pSrctemp.s3     = pSrcnext;
      tans = max(tans, pSrctemp);
    
      pSrcnext = *(yPlaneSrcDt5 +     5);
      pSrctemp = pSrctemp.s1230;
      pSrctemp.s3     = pSrcnext;
      tans = max(tans, pSrctemp);
    
    
      yPlaneSrcDt5 += yPlaneSrcStep * 1;

      pSrctemp = vload4(0, yPlaneSrcDt5);
      tans = max(tans, pSrctemp);

      pSrcnext = *(yPlaneSrcDt5 +     4);
      pSrctemp = pSrctemp.s1230;
      pSrctemp.s3     = pSrcnext;
      tans = max(tans, pSrctemp);
    
      pSrcnext = *(yPlaneSrcDt5 +     5);
      pSrctemp = pSrctemp.s1230;
      pSrctemp.s3     = pSrcnext;
      tans = max(tans, pSrctemp);
    
    
      uchar4 max_ans1 = tans;
      uchar4 maxValue;
      maxValue = convert_uchar4( max_ans1 );
        
  //uchar4 tans Exist;
    
  //uchar4 pSrctemp Exist;
    
  //uchar pSrcnext Exist;

      yPlaneSrcDt5 -= yPlaneSrcStep * 2;

      tans = vload4(0, yPlaneSrcDt5);
      pSrctemp = vload4(0, yPlaneSrcDt5);

      pSrcnext = *(yPlaneSrcDt5 +     4);
      pSrctemp = pSrctemp.s1230;
      pSrctemp.s3     = pSrcnext;
      tans = min(tans, pSrctemp);
    
      pSrcnext = *(yPlaneSrcDt5 +     5);
      pSrctemp = pSrctemp.s1230;
      pSrctemp.s3     = pSrcnext;
      tans = min(tans, pSrctemp);
    
    
      yPlaneSrcDt5 += yPlaneSrcStep * 1;
      pSrctemp = vload4(0, yPlaneSrcDt5);
      tans = min(tans, pSrctemp);
      pSrcnext = *(yPlaneSrcDt5 +     4);
      pSrctemp = pSrctemp.s1230;
      pSrctemp.s3     = pSrcnext;
      tans = min(tans, pSrctemp);
    
      pSrcnext = *(yPlaneSrcDt5 +     5);
      pSrctemp = pSrctemp.s1230;
      pSrctemp.s3     = pSrcnext;
      tans = min(tans, pSrctemp);
    
    
      yPlaneSrcDt5 += yPlaneSrcStep * 1;
      pSrctemp = vload4(0, yPlaneSrcDt5);
      tans = min(tans, pSrctemp);
      pSrcnext = *(yPlaneSrcDt5 +     4);
      pSrctemp = pSrctemp.s1230;
      pSrctemp.s3     = pSrcnext;
      tans = min(tans, pSrctemp);
    
      pSrcnext = *(yPlaneSrcDt5 +     5);
      pSrctemp = pSrctemp.s1230;
      pSrctemp.s3     = pSrcnext;
      tans = min(tans, pSrctemp);
    
      uchar4 min_ans1 = tans;
      uchar4 minValue;
      minValue = convert_uchar4( min_ans1 );



    float4 pError = convert_float4(*((__global uchar4*)yPlaneSrcDt6)) - convert_float4(*((__global uchar4 *)yPlaneCSERSrcDt7));
    

    float4 Op = convert_float4(*((__global short4*)pEdgeSrcDt4));
    float4 edge2Order = Op * Op *Op *Op; 


    float4 enhancedF = convert_float4(edge2Order * m1 + 1);
    float4 strength = convert_float4(edge2Order * m2 + 1);
    strength = convert_float4((enhancedF - 1) / (convert_float4(enhancedF * strength)) + 1);

    //uchar4 MatrixSub_ans3 = *(yPlaneCSERSrcDt7);
    //enhancedF = convert_float4(convert_uchar4(pError * strength) + MatrixSub_ans3);

    float4 yPlaneCESR4 = convert_float4(*((__global uchar4 *)(yPlaneCSERSrcDt7)));
    enhancedF = convert_float4(convert_int4(pError * strength + yPlaneCESR4));//////////////////////


      strength = convert_float4((0.05f * edge2Order + cutoff2Order) / (cutoff2Order + edge2Order));

    float4 pSharpness_value = convert_float4(enhancedF > 255 ? 255 : (enhancedF < 0 ? 0 : enhancedF));

    edge2Order = convert_float4(minValue) +(- strength) * (convert_float4(minValue) - enhancedF);


    strength = convert_float4(maxValue)+ (strength * (enhancedF - convert_float4(maxValue)));
    strength = convert_float4(strength < 255 ? strength : 255);

    edge2Order = (enhancedF < convert_float4(minValue) ? (edge2Order > 0 ? edge2Order : 0) : pSharpness_value);

    uchar4 temp7;
    temp7 = convert_uchar4(enhancedF > convert_float4(maxValue) ? strength : edge2Order);

    *dstDstDt1 = temp7.s0;
    *(dstDstDt1 + 1) = temp7.s1;
    *(dstDstDt1 + 2) = temp7.s2;
    *(dstDstDt1 + 3) = temp7.s3;
  }

}
#endif

