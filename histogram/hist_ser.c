#include<stdio.h>
#include<stdlib.h>

#define M 256 
#define N 256


int main()
{
  int i, j;
  unsigned char *input = (char*) malloc ( sizeof(unsigned char) * M * N );
  short hist[256];

  for( i = 0; i < M; i++)
    for( j = 0; j < N; j++){
      input[i*M + j] = rand()%256;
    }
 
  // Do computing.
  for( i = 0; i < M; i++)
    for( j = 0; j < N; j++){
      hist[ input[i*M+j] ]++;
    }

  return 0;
}
