#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<sys/time.h>
#include<stdint.h>
#include<smmintrin.h>


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

  for(int i = 0; i < 1024; i++){
    int16_t SrcPre2 = (int16_t) ((*Src)[i][3] * 4 - (*Src)[i][1] * 4 + (*Src)[i][0] * 2 - (*Src)[i][2]);
    int16_t SrcPre1 = (int16_t) ((*Src)[i][1] * 2 - (*Src)[i][3]);
    int16_t SrcLat1 = (int16_t) ((*Src)[i][1024 - 2] * 2 - (*Src)[i][1024 - 4]);
    int16_t SrcLat2 = (int16_t) ((*Src)[i][1024 - 4] * 4 - (*Src)[i][1024 - 2] * 4 + (*Src)[i][1024 - 1] * 2 - (*Src)[i][1024 - 3]);

    for(int j = 0; j < 1024; j++){
      int16_t res = 0;

      if( j == 0 ){
        res += (int16_t)(filter_horizon[0][0]) * SrcPre2;
        res += (int16_t)(filter_horizon[0][1]) * SrcPre1;
        res += (int16_t) (filter_horizon[0][2] * (*Src)[i][0]);
        res += (int16_t) (filter_horizon[0][3] * (*Src)[i][1]);
        res += (int16_t) (filter_horizon[0][4] * (*Src)[i][2]);
      }
      else if( j == 1 ){
        res += (int16_t)(filter_horizon[0][0]) * SrcPre1;
        res += (int16_t) (filter_horizon[0][1] * (*Src)[i][0]);
        res += (int16_t) (filter_horizon[0][2] * (*Src)[i][1]);
        res += (int16_t) (filter_horizon[0][3] * (*Src)[i][2]);
        res += (int16_t) (filter_horizon[0][4] * (*Src)[i][3]); 
      }
      else if( j == 1022 ){
        res += (int16_t) (filter_horizon[0][0] * (*Src)[i][1020]);
        res += (int16_t) (filter_horizon[0][1] * (*Src)[i][1021]);
        res += (int16_t) (filter_horizon[0][2] * (*Src)[i][1022]);
        res += (int16_t) (filter_horizon[0][3] * (*Src)[i][1023]);
        res += (int16_t)(filter_horizon[0][4]) * SrcLat1; 
      }
      else if( j == 1023 ){
        res += (int16_t) (filter_horizon[0][0] * (*Src)[i][1021]);
        res += (int16_t) (filter_horizon[0][1] * (*Src)[i][1022]);
        res += (int16_t) (filter_horizon[0][2] * (*Src)[i][1023]);
        res += (int16_t)(filter_horizon[0][3]) * SrcLat1;
        res += (int16_t)(filter_horizon[0][4]) * SrcLat2;  
      }
      else{
        res += (int16_t) (filter_horizon[0][0] * (*Src)[i][j - 2]);
        res += (int16_t) (filter_horizon[0][1] * (*Src)[i][j - 1]);
        res += (int16_t) (filter_horizon[0][2] * (*Src)[i][j]);
        res += (int16_t) (filter_horizon[0][3] * (*Src)[i][j + 1]);
        res += (int16_t) (filter_horizon[0][4] * (*Src)[i][j + 2]);
      }

      dst_horizon[i][j] = (unsigned char) ( (res + 8) / 16 );

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

  for(int i = 0; i < M; i++){
    for(int j = i + 1; j < N; j++){
      unsigned char temp = dst_horizon[i][j];
      dst_horizon[i][j] = dst_horizon[j][i];
      dst_horizon[j][i] = temp;
    }
  }

  for(int i = 0; i < 512; i++){
    int16_t dst_horizonPre2 = (int16_t) (dst_horizon[i * 2][3] * 4 - dst_horizon[i * 2][1] * 4 + dst_horizon[i * 2][0] * 2 - dst_horizon[i * 2][2]);
    int16_t dst_horizonPre1 = (int16_t) (dst_horizon[i * 2][1] * 2 - dst_horizon[i * 2][3]);
    int16_t dst_horizonLat1 = (int16_t) (dst_horizon[i * 2][1022] * 2 - dst_horizon[i * 2][1020]);
    int16_t dst_horizonLat2 = (int16_t) (dst_horizon[i * 2][1020] * 4 - dst_horizon[i * 2][1022] * 4 + dst_horizon[i * 2][1023] * 2 - dst_horizon[i * 2][1021]);

    for(int j = 0; j < 512; j++){
      int16_t res = 0;
      if( j == 0 ){
        res += (int16_t)filter_vertical[0][0] * dst_horizonPre2;
        res += (int16_t)filter_vertical[1][0] * dst_horizonPre1;
        res += (int16_t) (filter_vertical[2][0] * dst_horizon[i * 2][0]);
        res += (int16_t) (filter_vertical[3][0] * dst_horizon[i * 2][1]);
        res += (int16_t) (filter_vertical[4][0] * dst_horizon[i * 2][2]);
      }
      else if( j == 511 ){
        res = res + (int16_t) (filter_vertical[0][0] * dst_horizon[i * 2][1020]);
        res = res + (int16_t) (filter_vertical[1][0] * dst_horizon[i * 2][1021]);
        res = res + (int16_t) (filter_vertical[2][0] * dst_horizon[i * 2][1022]);
        res = res + (int16_t) (filter_vertical[3][0] * dst_horizon[i * 2][1023]);
        res = res + (int16_t)filter_vertical[4][0] * dst_horizonLat1;

        if( i == 1 )
          std::cout << "res = " << res << std::endl;
        if( i == 1 ){
          std::cout << "dst_horizonLat1 = " << (int16_t)dst_horizon[i * 2][1022] << " * 2 - " << (int16_t)dst_horizon[i * 2][1020] << " = " << dst_horizonLat1 << std::endl;
          std::cout << (int16_t)filter_vertical[0][0] << " * " << (int16_t)dst_horizon[i * 2][1020] << std::endl;
          std::cout << (int16_t)filter_vertical[1][0] << " * " << (int16_t)dst_horizon[i * 2][1021] << std::endl;
          std::cout << (int16_t)filter_vertical[2][0] << " * " << (int16_t)dst_horizon[i * 2][1022] << std::endl;
          std::cout << (int16_t)filter_vertical[3][0] << " * " << (int16_t)dst_horizon[i * 2][1023] << std::endl;
          std::cout << (int16_t)filter_vertical[4][0] << " * " << dst_horizonLat1 << std::endl;
          std::cout << " Serial dst_ds  : " << res << std::endl;
        }
      }
      else{
        res += (int16_t) (filter_vertical[0][0] * dst_horizon[i * 2][j * 2 - 2]);
        res += (int16_t) (filter_vertical[1][0] * dst_horizon[i * 2][j * 2 - 2 + 1]);
        res += (int16_t) (filter_vertical[2][0] * dst_horizon[i * 2][j * 2 - 2 + 2]);
        res += (int16_t) (filter_vertical[3][0] * dst_horizon[i * 2][j * 2 - 2 + 3]);
        res += (int16_t) (filter_vertical[4][0] * dst_horizon[i * 2][j * 2 - 2 + 4]);
      }

      dst_ds[i][j] = (unsigned char) ( (res + 8) / 16);

    }
  }


  for(int i = 0; i < (M+1)/2; i++){
    for(int j = i + 1; j < (N+1)/2; j++){
      unsigned char temp = dst_ds[i][j];
      dst_ds[i][j] = dst_ds[j][i];
      dst_ds[j][i] = temp;
    }
  }

  for(int i = 0; i < M; i++){
    for(int j = i + 1; j < N; j++){
      unsigned char temp = dst_horizon[i][j];
      dst_horizon[i][j] = dst_horizon[j][i];
      dst_horizon[j][i] = temp;
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

  std::cout << "convert filter_horizon from unsigned char to unsigned int:\n";

  gettimeofday(&t21, NULL);
  //handle 1st iterator.
  __m128i filter_horizon_Src = _mm_lddqu_si128( (__m128i const*)&filter_horizon[0][0] ); 
  __m128i cv1 = _mm_cvtepu8_epi16(filter_horizon_Src);
  int16_t *valcv1 = (int16_t *)&cv1;

  //for(int i = 0; i < 8; i++)
  //  printf("%d\t", valcv1[i]);
  // std::cout << std::endl;

  int16_t res = 0;

  for(int i = 0; i < 1024; i++){
    int16_t SrcPre2 = (int16_t) ((*Src)[i][3] * 4 - (*Src)[i][1] * 4 + (*Src)[i][0] * 2 - (*Src)[i][2]);
    int16_t SrcPre1 = (int16_t) ((*Src)[i][1] * 2 - (*Src)[i][3]);
    int16_t SrcLat1 = (int16_t) ((*Src)[i][1024 - 2] * 2 - (*Src)[i][1024 - 4]);
    int16_t SrcLat2 = (int16_t) ((*Src)[i][1024 - 4] * 4 - (*Src)[i][1024 - 2] * 4 + (*Src)[i][1024 - 1] * 2 - (*Src)[i][1024 - 3]);



    res = (int16_t)filter_horizon[0][0] * SrcPre2;
    res += (int16_t)filter_horizon[0][1] * SrcPre1;
    res += (int16_t)(filter_horizon[0][2] * (*Src)[i][0]);
    res += (int16_t)(filter_horizon[0][3] * (*Src)[i][1]);
    res += (int16_t)(filter_horizon[0][4] * (*Src)[i][2]);
    dst_horizon[i][0] = (unsigned char) ((res + 8) / 16);

    res = (int16_t)filter_horizon[0][0] * SrcPre1;
    res += (int16_t) (filter_horizon[0][1] * (*Src)[i][0]);
    res += (int16_t) (filter_horizon[0][2] * (*Src)[i][1]);
    res += (int16_t) (filter_horizon[0][3] * (*Src)[i][2]);
    res += (int16_t) (filter_horizon[0][4] * (*Src)[i][3]);
    dst_horizon[i][1] = (unsigned char) ((res + 8) / 16);

    res = (int16_t) (filter_horizon[0][0] * (*Src)[i][1020]);
    res += (int16_t) (filter_horizon[0][1] * (*Src)[i][1021]);
    res += (int16_t) (filter_horizon[0][2] * (*Src)[i][1022]);
    res += (int16_t) (filter_horizon[0][3] * (*Src)[i][1023]);
    res += (int16_t)filter_horizon[0][4] * SrcLat1;
    dst_horizon[i][1022] = (unsigned char) ((res + 8) / 16);


    res = (int16_t) (filter_horizon[0][0] * (*Src)[i][1021]);
    res += (int16_t) (filter_horizon[0][1] * (*Src)[i][1022]);
    res += (int16_t) (filter_horizon[0][2] * (*Src)[i][1023]);
    res += (int16_t)filter_horizon[0][3] * SrcLat1;
    res += (int16_t)filter_horizon[0][4] * SrcLat2;
    dst_horizon[i][1023] = (unsigned char) ((res + 8) / 16);





    for(int j = 2; j < 1022; j++){
      res = 0;
      __m128i Src_Src = _mm_lddqu_si128( (__m128i const*)&(*Src)[i][j - 2] );
      __m128i cv2 = _mm_cvtepu8_epi16(Src_Src);
      __m128i mul1 = _mm_mullo_epi16(cv1, cv2);

      int16_t *val1 = (int16_t *)&mul1;
      res += val1[0];
      res += val1[1];
      res += val1[2];
      res += val1[3];
      res += val1[4];

      dst_horizon[i][j] = (unsigned char) ((res + 8) / 16);

    }

  }

  gettimeofday(&t22, NULL);
  double time = (double)(t22.tv_usec - t21.tv_usec) * 0.001 + (t22.tv_sec - t21.tv_sec) * 1000;
  std::cout << "Parallel_laplacian, 1st iterator,  total time : " << time << "ms" << std::endl;
#endif

  for(int i = 0; i < 1024; i++){
    for(int j = 0; j < 1024; j++){
      fprintf(write1, "%d ", dst_horizon[i][j]);
    }
    fprintf(write1, "\n");
  }
  fclose(write1);

#if 0
  FILE *write2;
  write2 = fopen("dst_ds2.txt", "w");

  gettimeofday(&t23, NULL);

  for(int i = 0; i < M; i++){
    for(int j = i + 1; j < N; j++){
      unsigned char temp = dst_horizon[i][j];
      dst_horizon[i][j] = dst_horizon[j][i];
      dst_horizon[j][i] = temp;
    }
  }


  __m128i filter_vertical_Src = _mm_lddqu_si128( (__m128i const*)&filter_vertical[0][0] );
  __m128i cv3 = _mm_cvtepu8_epi16(filter_vertical_Src);
  int16_t *valcv3 = (int16_t *)&cv3;

  //std::cout << "convert filter_vertical from unsigned char to unsigned short :\n";
  //for(int i = 0; i < 8; i++)
  //  printf("%d\t", valcv3[i]);
 // std::cout << std::endl;

  for(int i = 0; i < 512; i++){
    int16_t dst_horizonPre2 = (int16_t) (dst_horizon[i * 2][3] * 4 - dst_horizon[i * 2][1] * 4 + dst_horizon[i * 2][0] * 2 - dst_horizon[i * 2][2]);
    int16_t dst_horizonPre1 = (int16_t) (dst_horizon[i * 2][1] * 2 - dst_horizon[i * 2][3]);
    int16_t dst_horizonLat1 = (int16_t) (dst_horizon[i * 2][1022] * 2 - dst_horizon[i * 2][1020]);
    int16_t dst_horizonLat2 = (int16_t) (dst_horizon[i * 2][1020] * 4 - dst_horizon[i * 2][1022] * 4 + dst_horizon[i * 2][1023] * 2 - dst_horizon[i][1021]);

    for(int j = 0; j < 512; j++){
      int16_t res = 0;
      if( j == 0 ){
        res += (int16_t)filter_vertical[0][0] * dst_horizonPre2;
        res += (int16_t)filter_vertical[1][0] * dst_horizonPre1;
        res += (int16_t) (filter_vertical[2][0] * dst_horizon[i * 2][0]);
        res += (int16_t) (filter_vertical[3][0] * dst_horizon[i * 2][1]);
        res += (int16_t) (filter_vertical[4][0] * dst_horizon[i * 2][2]);
      }
      else if( j == 511 ){
        res += (int16_t) (filter_vertical[0][0] * dst_horizon[i * 2][1020]);
        res += (int16_t) (filter_vertical[1][0] * dst_horizon[i * 2][1021]);
        res += (int16_t) (filter_vertical[2][0] * dst_horizon[i * 2][1022]);
        res += (int16_t) (filter_vertical[3][0] * dst_horizon[i * 2][1023]);
        res += (int16_t)filter_vertical[4][0] * dst_horizonLat1;

#if 0
        if( i == 1 ){
          std::cout << "dst_horizonLat1 = " << (int16_t)dst_horizon[i * 2][1022] << " * 2 - " << (int16_t)dst_horizon[i * 2][1020] << " = " << dst_horizonLat1 <<std::endl;
          std::cout << (int16_t)filter_vertical[0][0] << " * " << (int16_t)dst_horizon[i * 2][1020] << std::endl;
          std::cout << (int16_t)filter_vertical[1][0] << " * " << (int16_t)dst_horizon[i * 2][1021] << std::endl;
          std::cout << (int16_t)filter_vertical[2][0] << " * " << (int16_t)dst_horizon[i * 2][1022] << std::endl;
          std::cout << (int16_t)filter_vertical[3][0] << " * " << (int16_t)dst_horizon[i * 2][1023] << std::endl;
          std::cout << (int16_t)filter_vertical[4][0] << " * " << dst_horizonLat1 << std::endl;
          std::cout << "Parallel dst_ds  : " << res << std::endl;
        }
#endif
      }
      else{
        __m128i dst_horizon_Src = _mm_lddqu_si128( (__m128i const*)&dst_horizon[i * 2][j * 2 - 2] );
        __m128i cv4 = _mm_cvtepu8_epi16(dst_horizon_Src);
        __m128i mul2 = _mm_mullo_epi16(cv3, cv4);

        int16_t *val2 = (int16_t *)&mul2;
        for(int k = 0; k < 5; k++)       
          res += val2[k];
      }

      dst_ds[i][j] = (unsigned char) ( (res + 8) / 16);

    }
  }

  for(int i = 0; i < (M+1)/2; i++){
    for(int j = i + 1; j < (N+1)/2; j++){
      unsigned char temp = dst_ds[i][j];
      dst_ds[i][j] = dst_ds[j][i];
      dst_ds[j][i] = temp;
    }
  }

  for(int i = 0; i < M; i++){
    for(int j = i + 1; j < N; j++){
      unsigned char temp = dst_horizon[i][j];
      dst_horizon[i][j] = dst_horizon[j][i];
      dst_horizon[j][i] = temp;
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
  unsigned char *src_data = (unsigned char *)malloc(sizeof(unsigned char) * ROWS * COLS);
  unsigned char *dst_data = (unsigned char *)malloc(sizeof(unsigned char) * ROWS * COLS);


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

