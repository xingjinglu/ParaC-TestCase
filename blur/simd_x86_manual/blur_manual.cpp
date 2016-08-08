#include"stdio.h"
#include"stdlib.h"
#include"emmintrin.h"
#include"xmmintrin.h"
#include"sys/time.h"
#include<pmmintrin.h>

struct timeval t11,t12;

#define ROW 6408
#define COL 4802
int input[ROW][COL];

double time;

void Normal_blur(int x, int y, int *temp, int *output){
  int i, j;

  gettimeofday(&t11,NULL);

  //temp result
  for(i = 1; i < x-1; i++){
    for(j = 1; j < y-1; j++){
      *(temp + i*y + j) = ( input[i][j-1] + input[i][j] + input[i][j+1] ) / 3;
    }
  }

  //final result
  for(i = 1; i < x-1; i++){
    for(j = 1; j < y-1; j++){
      *(output + i*y + j) = ( *(temp + (i-1)*y + j) + *(temp + i*y + j) + *(temp + (i+1)*y + j) ) / 3;
    }
  }
  for(j = 0; j < y; j++){
    *(output + j) = *(temp + j);
    *(output + y*(x-1) + j) = *(output + y*(x-1) + j);
  }
  for(i = 1; i < x-1; i++){
    *(output + i*y) = *(temp + i*y);
    *(output + i*y + y-1) = *(temp + i*y + y-1);
  }
 
  gettimeofday(&t12,NULL);
  time = (double)(t12.tv_usec-t11.tv_usec)*0.001+(t12.tv_sec-t11.tv_sec)*1000;
  printf("Normal_blur,  total time : %f ms\n", time);

}


void sse_1(int x, int y, int *temp, int *output){
  int Slen = 4;
  int Tail = (y - 2) % Slen;
  int Time = (y - 2) / Slen;
  int Chunk= (y - 2) - Tail;

  int i, j, k;

  gettimeofday(&t11, NULL);

  //temp result
  for(i = 1; i < x-1; i++){
    for(j = 1; j < Chunk; j += Slen){
      __m128i opr1 = _mm_loadu_si128( (__m128i const*)&input[i][j] );
      __m128i opr2 = _mm_loadu_si128( (__m128i const*)&input[i][j-1] );
      __m128i opr3 = _mm_loadu_si128( (__m128i const*)&input[i][j+1] );

      int32_t *val1 = (int32_t *)&opr1;
      int32_t *val2 = (int32_t *)&opr2;
      int32_t *val3 = (int32_t *)&opr3;

      *(temp + i*y + j) = (val1[0] + val2[0] + val3[0]) / 3;
      *(temp + i*y + j + 1) = (val1[1] + val2[1] + val3[1]) / 3;
      *(temp + i*y + j + 2) = (val1[2] + val2[2] + val3[2]) / 3;
      *(temp + i*y + j + 3) = (val1[3] + val2[3] + val3[3]) / 3;
    }

    for(k = Chunk; k < y-1; k++)
      *(temp + i*y + k) = ( input[i][k] + input[i][k-1] + input[i][k+1] ) / 3;
  }

  //final result
  for(i = 1; i < x-1; i++){
    for(j = 1; j < Chunk; j += Slen){
      __m128i opr1 = _mm_loadu_si128( (__m128i const*)&(*(temp + i*y + j)) );
      __m128i opr2 = _mm_loadu_si128( (__m128i const*)&(*(temp + (i-1)*y + j)) );
      __m128i opr3 = _mm_loadu_si128( (__m128i const*)&(*(temp + (i+1)*y + j)) );

      int32_t *val1 = (int32_t *)&opr1;
      int32_t *val2 = (int32_t *)&opr2;
      int32_t *val3 = (int32_t *)&opr3;

      *(output + i*y + j) = (val1[0] + val2[0] + val3[0]) / 3;
      *(output + i*y + j + 1) = (val1[1] + val2[1] + val3[1]) / 3;
      *(output + i*y + j + 2) = (val1[2] + val2[2] + val3[2]) / 3;
      *(output + i*y + j + 3) = (val1[3] + val2[3] + val3[3]) / 3;
    }

    for(k = Chunk; k < y-1; k++) 
      *(output + i*y + k) = ( *(temp + (i-1)*y + k) + *(temp + i*y + k) + *(temp + (i+1)*y + k) ) / 3;
  }
  for(j = 0; j < y; j++){
    *(output + j) = *(temp + j);
    *(output + y*(x-1) + j) = *(output + y*(x-1) + j);
  }
  for(i = 1; i < x-1; i++){
    *(output + i*y) = *(temp + i*y);
    *(output + i*y + y-1) = *(temp + i*y + y-1);
  }

  gettimeofday(&t12,NULL);
  time = (double)(t12.tv_usec-t11.tv_usec)*0.001+(t12.tv_sec-t11.tv_sec)*1000;
  printf("SSE use load only, total time : %f ms\n", time);

}


void sse_2(int x, int y, int *temp, int *output){
  int Slen = 4;
  int Tail = (y - 2) % Slen;
  int Time = (y - 2) / Slen;
  int Chunk= (y - 2) - Tail;

  int i, j, k, m;

  gettimeofday(&t11, NULL);

  //temp result
  for(i = 1; i < x-1; i++){
    for(j = 1; j < Chunk; j += Slen){
      __m128i opr1 = _mm_lddqu_si128( (__m128i const*)&input[i][j] );
      __m128i opr2 = _mm_lddqu_si128( (__m128i const*)&input[i][j-1] );
      __m128i opr3 = _mm_lddqu_si128( (__m128i const*)&input[i][j+1] );

      __m128i res1 = _mm_add_epi32(opr1, opr2);
      __m128i res2 = _mm_add_epi32(res1, opr3);

      int32_t *val = (int32_t *)&res2;
      for(m = 0; m < Slen; m++)
        *(temp + i*y + j + m) = val[m] / 3;

    }

    for(k = Chunk; k < y-1; k++)
      *(temp + i*y + k) = ( input[i][k] + input[i][k-1] + input[i][k+1] ) / 3;
  }

  //final result
  for(i = 1; i < x-1; i++){
    for(j = 1; j < Chunk; j += Slen){
      __m128i opr1 = _mm_lddqu_si128( (__m128i const*)&(*(temp + i*y + j)) );
      __m128i opr2 = _mm_lddqu_si128( (__m128i const*)&(*(temp + (i-1)*y + j)) );
      __m128i opr3 = _mm_lddqu_si128( (__m128i const*)&(*(temp + (i+1)*y + j)) );

      __m128i res1 = _mm_add_epi32(opr1, opr2);
      __m128i res2 = _mm_add_epi32(res1, opr3);

      int32_t *val = (int32_t *)&res2;
      for(m = 0; m < Slen; m++)
        *(output + i*y + j + m) = val[m] / 3;

    }

    for(k = Chunk; k < y-1; k++) 
      *(output + i*y + k) = ( *(temp + (i-1)*y + k) + *(temp + i*y + k) + *(temp + (i+1)*y + k) ) / 3;
  }
  for(j = 0; j < y; j++){
    *(output + j) = *(temp + j);
    *(output + y*(x-1) + j) = *(output + y*(x-1) + j);
  }
  for(i = 1; i < x-1; i++){
    *(output + i*y) = *(temp + i*y);
    *(output + i*y + y-1) = *(temp + i*y + y-1);
  }

  gettimeofday(&t12,NULL);
  time = (double)(t12.tv_usec-t11.tv_usec)*0.001+(t12.tv_sec-t11.tv_sec)*1000;
  printf("SSE use lddq & add, total time : %f ms\n", time);

}

int main(){
  int x, y;

  int *temp = (int*)malloc( sizeof(int) * ROW * COL );
  int *output = (int*)malloc( sizeof(int) * ROW * COL );
  for(x = 0; x < ROW; x++){
    for(y = 0; y < COL; y++){
      input[x][y] = rand() & 0xff;

      if( ( x == 0 ) || ( x == ROW-1 ) || ( y == 0 ) || ( y == COL-1 ) )
        *(temp + x*COL + y) = input[x][y];
    }
  }

  Normal_blur(ROW, COL, temp, output);
  sse_1(ROW, COL, temp, output);
  sse_2(ROW, COL, temp, output);

  return 1;
}
