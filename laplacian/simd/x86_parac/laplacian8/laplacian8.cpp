#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<sys/time.h>
#include<stdint.h>
#include<smmintrin.h>
#include<emmintrin.h>
#include<malloc.h>

#define ROWS 1024
#define COLS 1024
#define M 1024
#define N 1024

struct timeval t1, t2, t11, t12, t13, t14, t15, t16, t21, t22, t23, t24, t25, t26;

#if 1
int Laplacian_serial(unsigned char (*Src)[M][N], unsigned char (*layer)[M][N])
{
  unsigned char filter_horizon[1][5] = {1,4,6,4,1};
  unsigned char filter_vertical[5][1] = {1,4,6,4,1};
  unsigned char dst_horizon[M][N];    
  unsigned char dst_vertical[M][N];    
  unsigned char dst_ds[(M+1)/2][(N+1)/2];            

  FILE *write1;
  write1 = fopen("dst_horizon1.txt", "w");

  gettimeofday(&t11, NULL); 

  int16_t res1 = 0;

  int16_t SrcPre2, SrcPre1, SrcLat1, SrcLat2;

  for(int i = 0; i < 1024; i++){

    SrcPre2 = (int16_t) ((*Src)[i][3] * 4 - (*Src)[i][1] * 4 + (*Src)[i][0] * 2 - (*Src)[i][2]);
    SrcPre1 = (int16_t) ((*Src)[i][1] * 2 - (*Src)[i][3]);
    SrcLat1 = (int16_t) ((*Src)[i][1024 - 2] * 2 - (*Src)[i][1024 - 4]);
    SrcLat2 = (int16_t) ((*Src)[i][1024 - 4] * 4 - (*Src)[i][1024 - 2] * 4 + (*Src)[i][1024 - 1] * 2 - (*Src)[i][1024 - 3]);

    res1 = (int16_t)(filter_horizon[0][0]) * SrcPre2;
    res1 += (int16_t)(filter_horizon[0][1]) * SrcPre1;
    res1 += (int16_t) (filter_horizon[0][2] * (*Src)[i][0]);
    res1 += (int16_t) (filter_horizon[0][3] * (*Src)[i][1]);
    res1 += (int16_t) (filter_horizon[0][4] * (*Src)[i][2]);
    dst_horizon[i][0] = (unsigned char) ( (res1 + 8) / 16 );

    res1 = (int16_t)(filter_horizon[0][0]) * SrcPre1;
    res1 += (int16_t) (filter_horizon[0][1] * (*Src)[i][0]);
    res1 += (int16_t) (filter_horizon[0][2] * (*Src)[i][1]);
    res1 += (int16_t) (filter_horizon[0][3] * (*Src)[i][2]);
    res1 += (int16_t) (filter_horizon[0][4] * (*Src)[i][3]); 
    dst_horizon[i][1] = (unsigned char) ( (res1 + 8) / 16 );

    res1 = (int16_t) (filter_horizon[0][0] * (*Src)[i][1020]);
    res1 += (int16_t) (filter_horizon[0][1] * (*Src)[i][1021]);
    res1 += (int16_t) (filter_horizon[0][2] * (*Src)[i][1022]);
    res1 += (int16_t) (filter_horizon[0][3] * (*Src)[i][1023]);
    res1 += (int16_t)(filter_horizon[0][4]) * SrcLat1; 
    dst_horizon[i][1022] = (unsigned char) ( (res1 + 8) / 16 );

    res1 = (int16_t) (filter_horizon[0][0] * (*Src)[i][1021]);
    res1 += (int16_t) (filter_horizon[0][1] * (*Src)[i][1022]);
    res1 += (int16_t) (filter_horizon[0][2] * (*Src)[i][1023]);
    res1 += (int16_t)(filter_horizon[0][3]) * SrcLat1;
    res1 += (int16_t)(filter_horizon[0][4]) * SrcLat2;  
    dst_horizon[i][1023] = (unsigned char) ( (res1 + 8) / 16 );

    for(int j = 2; j < 1022; j++){
      res1  = (int16_t) (filter_horizon[0][0] * (*Src)[i][j - 2]);
      res1 += (int16_t) (filter_horizon[0][1] * (*Src)[i][j - 1]);
      res1 += (int16_t) (filter_horizon[0][2] * (*Src)[i][j]);
      res1 += (int16_t) (filter_horizon[0][3] * (*Src)[i][j + 1]);
      res1 += (int16_t) (filter_horizon[0][4] * (*Src)[i][j + 2]);

      dst_horizon[i][j] = (unsigned char) ( (res1 + 8) / 16 );
    }
  }

  gettimeofday(&t12, NULL);
  double  time = (double)(t12.tv_usec - t11.tv_usec) * 0.001 + (t12.tv_sec - t11.tv_sec) * 1000;
  std::cout << "Normal_laplacian, 1st iterator,  total time : " << time << "ms" << std::endl;

  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      fprintf(write1, "%d ", dst_horizon[i][j]);
    }
    fprintf(write1, "\n");
  }
  fclose(write1);


  FILE *write2;
  write2 = fopen("dst_ds1.txt", "w");

  gettimeofday(&t13, NULL);

  int16_t dst_horizonPre2, dst_horizonPre1, dst_horizonLat1, dst_horizonLat2;

  for(int j = 0; j < 512; j++){
    dst_horizonPre2 = (int16_t) (dst_horizon[3][j * 2] * 4 - dst_horizon[1][j * 2] * 4 + dst_horizon[0][j * 2] * 2 - dst_horizon[2][j * 2]);
    dst_horizonPre1 = (int16_t) (dst_horizon[1][j * 2] * 2 - dst_horizon[3][j * 2]);
    dst_horizonLat1 = (int16_t) (dst_horizon[1022][j * 2] * 2 - dst_horizon[1020][j * 2]);
    dst_horizonLat2 = (int16_t) (dst_horizon[1020][j * 2] * 4 - dst_horizon[1022][j * 2] * 4 + dst_horizon[1023][j * 2] * 2 - dst_horizon[1021][j * 2]);

    res1 = (int16_t)filter_vertical[0][0] * dst_horizonPre2;
    res1 += (int16_t)filter_vertical[1][0] * dst_horizonPre1;
    res1 += (int16_t) (filter_vertical[2][0] * dst_horizon[0][j * 2]);
    res1 += (int16_t) (filter_vertical[3][0] * dst_horizon[1][j * 2]);
    res1 += (int16_t) (filter_vertical[4][0] * dst_horizon[2][j * 2]);
    dst_ds[0][j] = (unsigned char) ( (res1 + 8) / 16);

    res1 = (int16_t) (filter_vertical[0][0] * dst_horizon[1020][j * 2]);
    res1 += (int16_t) (filter_vertical[1][0] * dst_horizon[1021][j * 2]);
    res1 += (int16_t) (filter_vertical[2][0] * dst_horizon[1022][j * 2]);
    res1 += (int16_t) (filter_vertical[3][0] * dst_horizon[1023][j * 2]);
    res1 += (int16_t)filter_vertical[4][0] * dst_horizonLat1;
    dst_ds[511][j] = (unsigned char) ( (res1 + 8) / 16);

    for(int i = 1; i < 511; i++){
      res1 = (int16_t) (filter_vertical[0][0] * dst_horizon[i * 2 - 2][j * 2]);
      res1 += (int16_t) (filter_vertical[1][0] * dst_horizon[i * 2 - 1][j * 2]);
      res1 += (int16_t) (filter_vertical[2][0] * dst_horizon[i * 2][j * 2]);
      res1 += (int16_t) (filter_vertical[3][0] * dst_horizon[i * 2 + 1][j * 2]);
      res1 += (int16_t) (filter_vertical[4][0] * dst_horizon[i * 2 + 2][j * 2]);
      dst_ds[i][j] = (unsigned char) ( (res1 + 8) / 16);

    }
  }



  gettimeofday(&t14, NULL);
  double time1 = (double)(t14.tv_usec - t13.tv_usec) * 0.001 + (t14.tv_sec - t13.tv_sec) * 1000;
  std::cout << "Normal_laplacian, 2nd iterator,  total time : " << time1 << "ms" << std::endl;


  for(int i = 0; i < (M+1)/2; i++){
    for(int j = 0; j < (N+1)/2; j++){
      fprintf(write2, "%d ", dst_ds[i][j]);
    }
    fprintf(write2, "\n");
  }
  fclose(write2);


  int halfWidth = 1024 / 2;
  int halfHeight = 1024 / 2;
  int widthOdd = 1024 - (halfWidth * 2);
  int heightOdd = 1024 - (halfHeight * 2);


  FILE *write3;
  write3 = fopen("layer1.txt", "w");

  gettimeofday(&t15, NULL);

  for(int i = 0; i < 512; i++){
    for(int j = 0; j < 512; j++){
      if( i == 0 ){
        (*layer)[0][j * 2] = (*Src)[0][j * 2] - dst_ds[0][j];
        if( j != (N+1)/2 - 1 )
          (*layer)[0][j * 2 + 1] = (*Src)[0][j * 2 + 1]-(dst_ds[0][j] + dst_ds[0][j + 1] + 1) / 2;
        if(j == (N+1)/2 - 1 && widthOdd ==0)
          (*layer)[0][j * 2 + 1] = (*Src)[0][j * 2 + 1] - dst_ds[0][j];
      }
      if(heightOdd == 0 && i == (1024 + 1) / 2 - 1){
        (*layer)[M-1][j*2] = (*Src)[M-1][j*2] - dst_ds[(M+1)/2-1][j];
        if(j != (N+1)/2 -1)
          (*layer)[M-1][j*2+1] = (*Src)[M-1][j*2+1] - (dst_ds[(M+1)/2-1][j]+dst_ds[(M+1)/2-1][j+1]+1)/2;
        if(j == (N+1)/2 -1 && widthOdd ==0)
          (*layer)[M-1][j*2 + 1] = (*Src)[M-1][j*2 + 1] - dst_ds[M-1][j];
      }
      if(i != 0 )
      {
        (*layer)[2*i-1][2*j] = (*Src)[2*i-1][2*j] - (dst_ds[i-1][j] + dst_ds[i][j]+1)/2;
        (*layer)[2*i][2*j] = (*Src)[2*i][2*j] - dst_ds[i][j];

        if(j != (N+1)/2 -1)
        {  
          (*layer)[2*i-1][2*j+1] = (*Src)[2*i-1][2*j+1]-(dst_ds[i-1][j]+dst_ds[i-1][j+1]+dst_ds[i][j]+dst_ds[i][j+1]+2)/4;
          (*layer)[2*i][2*j+1] = (*Src)[2*i][2*j+1]-(dst_ds[i][j]+dst_ds[i][j+1]+1)/2;
        }

        if(widthOdd == 0 && j == (N+1)/2 -1)
        {
          (*layer)[2*i-1][2*j+1] = (*Src)[2*i-1][2*j]-(dst_ds[i-1][j]+dst_ds[i][j]+1)/2;
          (*layer)[2*i][2*j+1] = (*Src)[2*i][2*j]-dst_ds[i][j];
        }
      } 
    }
  }

  gettimeofday(&t16, NULL);
  double time2 = (double)(t16.tv_usec - t15.tv_usec) * 0.001 + (t16.tv_sec - t15.tv_sec) * 1000;
  std::cout << "Normal_laplacian, 3th iterator,  total time : " << time2 << "ms" << std::endl;


  for(int i = 0; i < 1024; i++){
    for(int j = 0; j < 1024; j++){
      fprintf(write3, "%d ", (*layer)[i][j]);
    }
    fprintf(write3, "\n");
  }
  fclose(write3);


  std::cout << "Normal_laplacian, serial version,  total time : " << time + time1 + time2 << "ms\n" << std::endl;

  return 0;

}
#endif

int Laplacian_simd(unsigned char (*Src)[1024][1024], unsigned char (*layer)[1024][1024]) {
  unsigned char filter_horizon[1][5] = { 1, 4, 6, 4, 1};
  unsigned char filter_vertical[5][1]= { 1, 4, 6, 4, 1};
  unsigned char dst_horizon[1024][1024];
  unsigned char dst_vertical[1024][1024];
  unsigned char dst_ds[(1024 + 1) / 2][(1024 + 1) / 2];
#if 1
  FILE *write1;
  write1 = fopen("dst_horizon2.txt", "w");

  double time = 0;

  //handle 1st iterator.
  __m128i filter_horizon_Src1 = _mm_set1_epi16((int16_t)*(*(filter_horizon) + 0));
  __m128i filter_horizon_Src2 = _mm_set1_epi16((int16_t)*(*(filter_horizon) + 1));
  __m128i filter_horizon_Src3 = _mm_set1_epi16((int16_t)*(*(filter_horizon) + 2));
  __m128i filter_horizon_Src4 = _mm_set1_epi16((int16_t)*(*(filter_horizon) + 3));
  __m128i filter_horizon_Src5 = _mm_set1_epi16((int16_t)*(*(filter_horizon) + 4));


  __m128i Src_Src, Src_Src1, Src_Src2, Src_Src3, Src_Src4, Src_Src5, Src_Src6, Src_Src7, Src_Src8;
  __m128i mul1, mul2, mul3, mul4, mul5;
  __m128i add;
  __m128i Norm = _mm_set1_epi16(8);
  __m128i Mask1 = _mm_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 14, 12, 10, 8 ,6, 4 ,2, 0);
  __m128i Mask4 = _mm_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,64, 64 ,64, 64);

  int16_t res1 = 0;
  int16_t SrcPre2, SrcPre1, SrcLat1, SrcLat2;

  gettimeofday(&t21, NULL);

  for(int i = 0; i < 1024; i++){
    int index = 0;
    SrcPre2 = (int16_t) ((*Src)[i][3] * 4 - (*Src)[i][1] * 4 + (*Src)[i][0] * 2 - (*Src)[i][2]);
    SrcPre1 = (int16_t) ((*Src)[i][1] * 2 - (*Src)[i][3]);
    SrcLat1 = (int16_t) ((*Src)[i][1024 - 2] * 2 - (*Src)[i][1024 - 4]);
    SrcLat2 = (int16_t) ((*Src)[i][1024 - 4] * 4 - (*Src)[i][1024 - 2] * 4 + (*Src)[i][1024 - 1] * 2 - (*Src)[i][1024 - 3]);

    res1 =  (int16_t)filter_horizon[0][0] * SrcPre2;
    res1 += (int16_t)filter_horizon[0][1] * SrcPre1;
    res1 += (int16_t)(filter_horizon[0][2] * (*Src)[i][0]);
    res1 += (int16_t)(filter_horizon[0][3] * (*Src)[i][1]);
    res1 += (int16_t)(filter_horizon[0][4] * (*Src)[i][2]);
    dst_horizon[i][0] = (unsigned char) ((res1 + 8) / 16);

    res1 =  (int16_t)filter_horizon[0][0] * SrcPre1;
    res1 += (int16_t) (filter_horizon[0][1] * (*Src)[i][0]);
    res1 += (int16_t) (filter_horizon[0][2] * (*Src)[i][1]);
    res1 += (int16_t) (filter_horizon[0][3] * (*Src)[i][2]);
    res1 += (int16_t) (filter_horizon[0][4] * (*Src)[i][3]);
    dst_horizon[i][1] = (unsigned char) ((res1 + 8) / 16);

    for(int j = 2; j < 1022; j += 8){
      Src_Src1 = _mm_loadl_epi64( (__m128i const*)&(*Src)[i][j - 2] );
      Src_Src1 = _mm_cvtepu8_epi16(Src_Src1);
      Src_Src2 = _mm_loadl_epi64( (__m128i const*)&(*Src)[i][j - 1] );
      Src_Src2 = _mm_cvtepu8_epi16(Src_Src2);
      Src_Src3 = _mm_loadl_epi64( (__m128i const*)&(*Src)[i][j] );
      Src_Src3 = _mm_cvtepu8_epi16(Src_Src3);
      Src_Src4 = _mm_loadl_epi64( (__m128i const*)&(*Src)[i][j + 1] );
      Src_Src4 = _mm_cvtepu8_epi16(Src_Src4);
      Src_Src5 = _mm_loadl_epi64( (__m128i const*)&(*Src)[i][j + 2] );
      Src_Src5 = _mm_cvtepu8_epi16(Src_Src5);

      mul1 = _mm_mullo_epi16(filter_horizon_Src1, Src_Src1);
      mul2 = _mm_mullo_epi16(filter_horizon_Src2, Src_Src2);
      mul3 = _mm_mullo_epi16(filter_horizon_Src3, Src_Src3);
      mul4 = _mm_mullo_epi16(filter_horizon_Src4, Src_Src4);
      mul5 = _mm_mullo_epi16(filter_horizon_Src5, Src_Src5);

      add = _mm_add_epi16(mul1, mul2);
      add = _mm_add_epi16(add, mul3);
      add = _mm_add_epi16(add, mul4);
      add = _mm_add_epi16(add, mul5);

      add = _mm_add_epi16(add, Norm);
      add = _mm_srli_epi16(add, 4);
      add = _mm_shuffle_epi8(add, Mask1);
      _mm_storeu_si128((__m128i *)&dst_horizon[i][j], add);
      index++;
    }
    //std::cout << "while break for-loop, index j is " << index << "\n";
    res1 =  (int16_t) (filter_horizon[0][0] * (*Src)[i][1020]);
    res1 += (int16_t) (filter_horizon[0][1] * (*Src)[i][1021]);
    res1 += (int16_t) (filter_horizon[0][2] * (*Src)[i][1022]);
    res1 += (int16_t) (filter_horizon[0][3] * (*Src)[i][1023]);
    res1 += (int16_t)filter_horizon[0][4] * SrcLat1;
    dst_horizon[i][1022] = (unsigned char) ((res1 + 8) / 16);

    res1 =  (int16_t) (filter_horizon[0][0] * (*Src)[i][1021]);
    res1 += (int16_t) (filter_horizon[0][1] * (*Src)[i][1022]);
    res1 += (int16_t) (filter_horizon[0][2] * (*Src)[i][1023]);
    res1 += (int16_t)filter_horizon[0][3] * SrcLat1;
    res1 += (int16_t)filter_horizon[0][4] * SrcLat2;
    dst_horizon[i][1023] = (unsigned char) ((res1 + 8) / 16);

  }

  gettimeofday(&t22, NULL);
  time = (double)(t22.tv_usec - t21.tv_usec) * 0.001 + (t22.tv_sec - t21.tv_sec) * 1000;
  std::cout << "Parallel_laplacian, 1st iterator,  total time : " << time << "ms" << std::endl;
#endif

  for(int i = 0; i < 1024; i++){
    for(int j = 0; j < 1024; j++){
      fprintf(write1, "%d ", dst_horizon[i][j]);
    }
    fprintf(write1, "\n");
  }
  fclose(write1);

#if 1
  FILE *write2;
  write2 = fopen("dst_ds2.txt", "w");

  __m128i filter_vertical_Src1 = _mm_set1_epi16((int16_t)*(*(filter_vertical) + 0));
  __m128i filter_vertical_Src2 = _mm_set1_epi16((int16_t)*(*(filter_vertical) + 1));
  __m128i filter_vertical_Src3 = _mm_set1_epi16((int16_t)*(*(filter_vertical) + 2));
  __m128i filter_vertical_Src4 = _mm_set1_epi16((int16_t)*(*(filter_vertical) + 3));
  __m128i filter_vertical_Src5 = _mm_set1_epi16((int16_t)*(*(filter_vertical) + 4));

  __m128i dst_horizonPre2;
  __m128i dst_horizonPre1;
  __m128i dst_horizonLat1;
  __m128i dst_horizonLat2;

  int16_t dst_horizonPre21, dst_horizonPre11, dst_horizonLat11, dst_horizonLat21;
  int16_t dst_horizonPre22, dst_horizonPre12, dst_horizonLat12, dst_horizonLat22;
  int16_t dst_horizonPre23, dst_horizonPre13, dst_horizonLat13, dst_horizonLat23;
  int16_t dst_horizonPre24, dst_horizonPre14, dst_horizonLat14, dst_horizonLat24;
  int16_t dst_horizonPre25, dst_horizonPre15, dst_horizonLat15, dst_horizonLat25;
  int16_t dst_horizonPre26, dst_horizonPre16, dst_horizonLat16, dst_horizonLat26;
  int16_t dst_horizonPre27, dst_horizonPre17, dst_horizonLat17, dst_horizonLat27;
  int16_t dst_horizonPre28, dst_horizonPre18, dst_horizonLat18, dst_horizonLat28;

  __m128i dst_horizon_Pre1, dst_horizon_Pre2, dst_horizon_Pre3, dst_horizon_Pre4, dst_horizon_Pre5;
  __m128i dst_horizon_Lat1, dst_horizon_Lat2, dst_horizon_Lat3, dst_horizon_Lat4;
  __m128i MulRes1, MulRes2, MulRes3, MulRes4, MulRes5;
  __m128i AddRes;
  __m128i Mask2 = _mm_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 8 ,4, 0);
  __m128i Mask3 = _mm_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 64, 64, 64, 64, 64, 64, 64, 64);
  int16_t *Val;
  gettimeofday(&t23, NULL);

  for(int j = 0; j < 512; j += 8){
    dst_horizonPre21 = (int16_t) (dst_horizon[3][j * 2] * 4 - dst_horizon[1][j * 2] * 4 + dst_horizon[0][j * 2] * 2 - dst_horizon[2][j * 2]);
    dst_horizonPre11 = (int16_t) (dst_horizon[1][j * 2] * 2 - dst_horizon[3][j * 2]);
    dst_horizonLat11 = (int16_t) (dst_horizon[1022][j * 2] * 2 - dst_horizon[1020][j * 2]);
    dst_horizonLat21 = (int16_t) (dst_horizon[1020][j * 2] * 4 - dst_horizon[1022][j * 2] * 4 + dst_horizon[1023][j * 2] * 2 - dst_horizon[1021][j * 2]);

    dst_horizonPre22 = (int16_t) (dst_horizon[3][j * 2 + 2] * 4 - dst_horizon[1][j * 2 + 2] * 4 + dst_horizon[0][j * 2 + 2] * 2 - dst_horizon[2][j * 2 + 2]);
    dst_horizonPre12 = (int16_t) (dst_horizon[1][j * 2 + 2] * 2 - dst_horizon[3][j * 2 + 2]);
    dst_horizonLat12 = (int16_t) (dst_horizon[1022][j * 2 + 2] * 2 - dst_horizon[1020][j * 2 + 2]);
    dst_horizonLat22 = (int16_t) (dst_horizon[1020][j * 2 + 2] * 4 - dst_horizon[1022][j * 2 + 2] * 4 + dst_horizon[1023][j * 2 + 2] * 2 - dst_horizon[1021][j * 2 + 2]);

    dst_horizonPre23 = (int16_t) (dst_horizon[3][j * 2 + 4] * 4 - dst_horizon[1][j * 2 + 4] * 4 + dst_horizon[0][j * 2 + 4] * 2 - dst_horizon[2][j * 2 + 4]);
    dst_horizonPre13 = (int16_t) (dst_horizon[1][j * 2 + 4] * 2 - dst_horizon[3][j * 2 + 4]);
    dst_horizonLat13 = (int16_t) (dst_horizon[1022][j * 2 + 4] * 2 - dst_horizon[1020][j * 2 + 4]);
    dst_horizonLat23 = (int16_t) (dst_horizon[1020][j * 2 + 4] * 4 - dst_horizon[1022][j * 2 + 4] * 4 + dst_horizon[1023][j * 2 + 4] * 2 - dst_horizon[1021][j * 2 + 4]);

    dst_horizonPre24 = (int16_t) (dst_horizon[3][j * 2 + 6] * 4 - dst_horizon[1][j * 2 + 6] * 4 + dst_horizon[0][j * 2 + 6] * 2 - dst_horizon[2][j * 2 + 6]);
    dst_horizonPre14 = (int16_t) (dst_horizon[1][j * 2 + 6] * 2 - dst_horizon[3][j * 2 + 6]);
    dst_horizonLat14 = (int16_t) (dst_horizon[1022][j * 2 + 6] * 2 - dst_horizon[1020][j * 2 + 6]);
    dst_horizonLat24 = (int16_t) (dst_horizon[1020][j * 2 + 6] * 4 - dst_horizon[1022][j * 2 + 6] * 4 + dst_horizon[1023][j * 2 + 6] * 2 - dst_horizon[1021][j * 2 + 6]);

    dst_horizonPre25 = (int16_t) (dst_horizon[3][j * 2 + 8] * 4 - dst_horizon[1][j * 2 + 8] * 4 + dst_horizon[0][j * 2 + 8] * 2 - dst_horizon[2][j * 2 + 8]);
    dst_horizonPre15 = (int16_t) (dst_horizon[1][j * 2 + 8] * 2 - dst_horizon[3][j * 2 + 8]);
    dst_horizonLat15 = (int16_t) (dst_horizon[1022][j * 2 + 8] * 2 - dst_horizon[1020][j * 2 + 8]);
    dst_horizonLat25 = (int16_t) (dst_horizon[1020][j * 2 + 8] * 4 - dst_horizon[1022][j * 2 + 8] * 4 + dst_horizon[1023][j * 2 + 8] * 2 - dst_horizon[1021][j * 2 + 8]);

    dst_horizonPre26 = (int16_t) (dst_horizon[3][j * 2 + 10] * 4 - dst_horizon[1][j * 2 + 10] * 4 + dst_horizon[0][j * 2 + 10] * 2 - dst_horizon[2][j * 2 + 10]);
    dst_horizonPre16 = (int16_t) (dst_horizon[1][j * 2 + 10] * 2 - dst_horizon[3][j * 2 + 10]);
    dst_horizonLat16 = (int16_t) (dst_horizon[1022][j * 2 + 10] * 2 - dst_horizon[1020][j * 2 + 10]);
    dst_horizonLat26 = (int16_t) (dst_horizon[1020][j * 2 + 10] * 4 - dst_horizon[1022][j * 2 + 10] * 4 + dst_horizon[1023][j * 2 + 10] * 2 - dst_horizon[1021][j * 2 + 10]);

    dst_horizonPre27 = (int16_t) (dst_horizon[3][j * 2 + 12] * 4 - dst_horizon[1][j * 2 + 12] * 4 + dst_horizon[0][j * 2 + 12] * 2 - dst_horizon[2][j * 2 + 12]);
    dst_horizonPre17 = (int16_t) (dst_horizon[1][j * 2 + 12] * 2 - dst_horizon[3][j * 2 + 12]);
    dst_horizonLat17 = (int16_t) (dst_horizon[1022][j * 2 + 12] * 2 - dst_horizon[1020][j * 2 + 12]);
    dst_horizonLat27 = (int16_t) (dst_horizon[1020][j * 2 + 12] * 4 - dst_horizon[1022][j * 2 + 12] * 4 + dst_horizon[1023][j * 2 + 12] * 2 - dst_horizon[1021][j * 2 + 12]);

    dst_horizonPre28 = (int16_t) (dst_horizon[3][j * 2 + 14] * 4 - dst_horizon[1][j * 2 + 14] * 4 + dst_horizon[0][j * 2 + 14] * 2 - dst_horizon[2][j * 2 + 14]);
    dst_horizonPre18 = (int16_t) (dst_horizon[1][j * 2 + 14] * 2 - dst_horizon[3][j * 2 + 14]);
    dst_horizonLat18 = (int16_t) (dst_horizon[1022][j * 2 + 14] * 2 - dst_horizon[1020][j * 2 + 14]);
    dst_horizonLat28 = (int16_t) (dst_horizon[1020][j * 2 + 14] * 4 - dst_horizon[1022][j * 2 + 14] * 4 + dst_horizon[1023][j * 2 + 14] * 2 - dst_horizon[1021][j * 2 + 14]);

    dst_horizonPre2 =  _mm_setr_epi16(dst_horizonPre21, dst_horizonPre22, dst_horizonPre23, dst_horizonPre24, dst_horizonPre25, dst_horizonPre26, dst_horizonPre27, dst_horizonPre28);
    dst_horizonPre1 =  _mm_setr_epi16(dst_horizonPre11, dst_horizonPre12, dst_horizonPre13, dst_horizonPre14, dst_horizonPre15, dst_horizonPre16, dst_horizonPre17, dst_horizonPre18);
    dst_horizonLat1 =  _mm_setr_epi16(dst_horizonLat11, dst_horizonLat12, dst_horizonLat13, dst_horizonLat14, dst_horizonLat15, dst_horizonLat16, dst_horizonLat17, dst_horizonLat18);
    dst_horizonLat2 =  _mm_setr_epi16(dst_horizonLat21, dst_horizonLat22, dst_horizonLat23, dst_horizonLat24, dst_horizonLat25, dst_horizonLat26, dst_horizonLat27, dst_horizonLat28);


    dst_horizon_Pre1 = _mm_lddqu_si128( (__m128i const*)&dst_horizon[0][j * 2] );
    dst_horizon_Pre1 = _mm_shuffle_epi8(dst_horizon_Pre1, Mask1);
    dst_horizon_Pre1 = _mm_cvtepu8_epi16(dst_horizon_Pre1);

    dst_horizon_Pre2 = _mm_lddqu_si128( (__m128i const*)&dst_horizon[1][j * 2] );
    dst_horizon_Pre2 = _mm_shuffle_epi8(dst_horizon_Pre2, Mask1);
    dst_horizon_Pre2 = _mm_cvtepu8_epi16(dst_horizon_Pre2);

    dst_horizon_Pre3 = _mm_lddqu_si128( (__m128i const*)&dst_horizon[2][j * 2] );
    dst_horizon_Pre3 = _mm_shuffle_epi8(dst_horizon_Pre3, Mask1);
    dst_horizon_Pre3 = _mm_cvtepu8_epi16(dst_horizon_Pre3);

    dst_horizon_Lat1 = _mm_lddqu_si128( (__m128i const*)&dst_horizon[1020][j * 2] );
    dst_horizon_Lat1 = _mm_shuffle_epi8(dst_horizon_Lat1, Mask1);
    dst_horizon_Lat1 = _mm_cvtepu8_epi16(dst_horizon_Lat1);

    dst_horizon_Lat2 = _mm_lddqu_si128( (__m128i const*)&dst_horizon[1021][j * 2] );
    dst_horizon_Lat2 = _mm_shuffle_epi8(dst_horizon_Lat2, Mask1);
    dst_horizon_Lat2 = _mm_cvtepu8_epi16(dst_horizon_Lat2);

    dst_horizon_Lat3 = _mm_lddqu_si128( (__m128i const*)&dst_horizon[1022][j * 2] );
    dst_horizon_Lat3 = _mm_shuffle_epi8(dst_horizon_Lat3, Mask1);
    dst_horizon_Lat3 = _mm_cvtepu8_epi16(dst_horizon_Lat3);

    dst_horizon_Lat4 = _mm_lddqu_si128( (__m128i const*)&dst_horizon[1023][j * 2] );
    dst_horizon_Lat4 = _mm_shuffle_epi8(dst_horizon_Lat4, Mask1);
    dst_horizon_Lat4 = _mm_cvtepu8_epi16(dst_horizon_Lat4);

    MulRes1 = _mm_mullo_epi16(filter_vertical_Src1, dst_horizonPre2);
    MulRes2 = _mm_mullo_epi16(filter_vertical_Src2, dst_horizonPre1);
    MulRes3 = _mm_mullo_epi16(filter_vertical_Src3, dst_horizon_Pre1);
    MulRes4 = _mm_mullo_epi16(filter_vertical_Src4, dst_horizon_Pre2);
    MulRes5 = _mm_mullo_epi16(filter_vertical_Src5, dst_horizon_Pre3);
    
    AddRes = _mm_add_epi16(MulRes1, MulRes2);
    AddRes = _mm_add_epi16(AddRes, MulRes3);
    AddRes = _mm_add_epi16(AddRes, MulRes4);
    AddRes = _mm_add_epi16(AddRes, MulRes5);

    AddRes = _mm_add_epi16(AddRes, Norm);
    AddRes = _mm_srli_epi16(AddRes, 4);
    AddRes = _mm_shuffle_epi8(AddRes, Mask1);
    _mm_maskmoveu_si128 (AddRes, Mask3, (char *)&dst_ds[0][j]);

    MulRes1 = _mm_mullo_epi16(filter_vertical_Src1, dst_horizon_Lat1);
    MulRes2 = _mm_mullo_epi16(filter_vertical_Src2, dst_horizon_Lat2);
    MulRes3 = _mm_mullo_epi16(filter_vertical_Src3, dst_horizon_Lat3);
    MulRes4 = _mm_mullo_epi16(filter_vertical_Src4, dst_horizon_Lat4);
    MulRes5 = _mm_mullo_epi16(filter_vertical_Src5, dst_horizonLat1);

    AddRes = _mm_add_epi16(MulRes1, MulRes2);
    AddRes = _mm_add_epi16(AddRes, MulRes3);
    AddRes = _mm_add_epi16(AddRes, MulRes4);
    AddRes = _mm_add_epi16(AddRes, MulRes5);

    AddRes = _mm_add_epi16(AddRes, Norm);
    AddRes = _mm_srli_epi16(AddRes, 4);
    AddRes = _mm_shuffle_epi8(AddRes, Mask1);
    _mm_maskmoveu_si128 (AddRes, Mask3, (char *)&dst_ds[0][j]);

    for(int i = 1; i < 511; i += 1){

      dst_horizon_Pre4 = _mm_loadl_epi64( (__m128i const*)&dst_horizon[i * 2 + 1][j * 2] );
      dst_horizon_Pre5 = _mm_loadl_epi64( (__m128i const*)&dst_horizon[i * 2 + 2][j * 2] );

      dst_horizon_Pre4 = _mm_shuffle_epi8(dst_horizon_Pre4, Mask1);
      dst_horizon_Pre4 = _mm_shuffle_epi8(dst_horizon_Pre4, Mask1);

      dst_horizon_Pre4 = _mm_cvtepu8_epi16(dst_horizon_Pre4);
      dst_horizon_Pre5 = _mm_cvtepu8_epi16(dst_horizon_Pre5);

      MulRes1 = _mm_mullo_epi16(filter_vertical_Src1, dst_horizon_Pre1);
      MulRes2 = _mm_mullo_epi16(filter_vertical_Src2, dst_horizon_Pre2);
      MulRes3 = _mm_mullo_epi16(filter_vertical_Src3, dst_horizon_Pre3);
      MulRes4 = _mm_mullo_epi16(filter_vertical_Src4, dst_horizon_Pre4);
      MulRes5 = _mm_mullo_epi16(filter_vertical_Src5, dst_horizon_Pre5);

      AddRes = _mm_add_epi16(MulRes1, MulRes2);
      AddRes = _mm_add_epi16(AddRes, MulRes3);
      AddRes = _mm_add_epi16(AddRes, MulRes4);
      AddRes = _mm_add_epi16(AddRes, MulRes5);

      AddRes = _mm_add_epi16(AddRes, Norm);
      AddRes = _mm_srli_epi16(AddRes, 4);
      AddRes = _mm_shuffle_epi8(AddRes, Mask1);
      _mm_maskmoveu_si128 (AddRes, Mask3, (char *)&dst_ds[i][j]);

      dst_horizon_Pre1 = dst_horizon_Pre3;
      dst_horizon_Pre2 = dst_horizon_Pre4;
      dst_horizon_Pre3 = dst_horizon_Pre5;
    }
  }

  gettimeofday(&t24, NULL);
  double time1 = (double)(t24.tv_usec - t23.tv_usec) * 0.001 + (t24.tv_sec - t23.tv_sec) * 1000;
  std::cout << "Parallel_laplacian, 2nd iterator,  total time : " << time1 << "ms" << std::endl;

  for(int i = 0; i < (M+1)/2; i++){
    for(int j = 0; j < (N+1)/2; j++){
      fprintf(write2, "%d ", dst_ds[i][j]);
    }
    fprintf(write2, "\n");
  }
  fclose(write2);


  int halfWidth = 1024 / 2;
  int halfHeight = 1024 / 2;
  int widthOdd = 1024 - (halfWidth * 2);
  int heightOdd = 1024 - (halfHeight * 2);


  FILE *write3;
  write3 = fopen("layer2.txt", "w");


  gettimeofday(&t25, NULL);

  for(int i = 0; i < 512; i++){
    for(int j = 0; j < 512; j++){
      if( i == 0 ){
        (*layer)[0][j * 2] = (*Src)[0][j * 2] - dst_ds[0][j];
        if( j != (N+1)/2 - 1 )
          (*layer)[0][j * 2 + 1] = (*Src)[0][j * 2 + 1]-(dst_ds[0][j] + dst_ds[0][j + 1] + 1) / 2;
        if(j == (N+1)/2 - 1 && widthOdd ==0)
          (*layer)[0][j * 2 + 1] = (*Src)[0][j * 2 + 1] - dst_ds[0][j];
      }
      if(heightOdd == 0 && i == (1024 + 1) / 2 - 1){
        (*layer)[M-1][j*2] = (*Src)[M-1][j*2] - dst_ds[(M+1)/2-1][j];
        if(j != (N+1)/2 -1)
          (*layer)[M-1][j*2+1] = (*Src)[M-1][j*2+1] - (dst_ds[(M+1)/2-1][j]+dst_ds[(M+1)/2-1][j+1]+1)/2;
        if(j == (N+1)/2 -1 && widthOdd ==0)
          (*layer)[M-1][j*2 + 1] = (*Src)[M-1][j*2 + 1] - dst_ds[M-1][j];
      }
      if(i != 0 )
      {
        (*layer)[2*i-1][2*j] = (*Src)[2*i-1][2*j] - (dst_ds[i-1][j] + dst_ds[i][j]+1)/2;
        (*layer)[2*i][2*j] = (*Src)[2*i][2*j] - dst_ds[i][j];

        if(j != (N+1)/2 -1)
        {  
          (*layer)[2*i-1][2*j+1] = (*Src)[2*i-1][2*j+1]-(dst_ds[i-1][j]+dst_ds[i-1][j+1]+dst_ds[i][j]+dst_ds[i][j+1]+2)/4;
          (*layer)[2*i][2*j+1] = (*Src)[2*i][2*j+1]-(dst_ds[i][j]+dst_ds[i][j+1]+1)/2;
        }

        if(widthOdd == 0 && j == (N+1)/2 -1)
        {
          (*layer)[2*i-1][2*j+1] = (*Src)[2*i-1][2*j]-(dst_ds[i-1][j]+dst_ds[i][j]+1)/2;
          (*layer)[2*i][2*j+1] = (*Src)[2*i][2*j]-dst_ds[i][j];
        }
      } 
    }
  }

  gettimeofday(&t26, NULL);
  double time2 = (double)(t26.tv_usec - t25.tv_usec) * 0.001 + (t26.tv_sec - t25.tv_sec) * 1000;
  std::cout << "Parallel_laplacian, 3th iterator,  total time : " << time2 << "ms" << std::endl;


  for(int i = 0; i < 1024; i++){
    for(int j = 0; j < 1024; j++){
      fprintf(write3, "%d ", (*layer)[i][j]);
    }
    fprintf(write3, "\n");
  }
  fclose(write3);


  std::cout << "Parallel_laplacian, serial version,  total time : " << time + time1 + time2<< "ms\n" << std::endl;

#endif
  return 0;
}


int main()
{
  unsigned char *src_data = (unsigned char *)memalign(16, sizeof(unsigned char) * ROWS * COLS);
  unsigned char *dst_data = (unsigned char *)memalign(16, sizeof(unsigned char) * ROWS * COLS);


  unsigned char (*src)[1024][1024] = (unsigned char (*)[1024][1024])src_data;
  unsigned char (*Layer)[1024][1024] = (unsigned char (*)[1024][1024])dst_data;


  for (int i = 0; i < ROWS*COLS; i++)
  {
    src_data[i] = rand()%100 + 1;
  }

  //  gettimeofday(&t1, NULL);
  Laplacian_serial(src, Layer);
  //  gettimeofday(&t2, NULL);
  //  double  time = (double)(t2.tv_usec - t1.tv_usec) * 0.001 + (t2.tv_sec - t1.tv_sec) * 1000;
  //  std::cout << "In main, Normal_laplacian, serial version,  total time : " << time << "ms" << std::endl;

  //  gettimeofday(&t1, NULL);
  Laplacian_simd(src, Layer);
  //  gettimeofday(&t2, NULL);
  //  time = (double)(t2.tv_usec - t1.tv_usec) * 0.001 + (t2.tv_sec - t1.tv_sec) * 1000;
  //  std::cout << "In main, Parallel_laplacian, simd version,  total time : " << time << "ms" << std::endl;

  return 0;
}

