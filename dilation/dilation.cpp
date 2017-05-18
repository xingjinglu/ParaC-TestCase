#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/time.h>

struct timeval ts1, te1;
void dilation(unsigned char * src,
    unsigned char *dst, int width,
    int height, int structWidth, int structHeight)
{
  int mid = (structWidth+1)/2 -1; 
  unsigned char val = 255;

  gettimeofday(&ts1, NULL);

  for( int y = 0; y < mid; y++){
    for( int x = 0; x < mid; x++){
      dst[y*width+x] = src[y*width+x];
    }
    for(int x = width - mid -1; x < width; x++){
      dst[y*width+x] = src[y*width+x];
    }
  }

  for( int y = height-mid-1; y < height; y++){
    for( int x = 0; x < mid; x++){
      dst[y*width+x] = src[y*width+x];
    }
    for(int x = width - mid -1; x < width; x++){
      dst[y*width+x] = src[y*width+x];
    }
  }

   val = 0;
  for( int y = mid; y < height-mid-1; y++){
    for( int x = mid; x < width-mid-1; x++){

      for( int m = 0; m < structWidth; m++){
        for( int n = 0; n < structHeight; n++){
          val = val | src[(y+m)*width+x+n];
        }
      }
      dst[y*width+x] = val;

    }
  }

  gettimeofday(&te1, NULL);
}

struct timeval ts2, te2;
void dilation_opt(unsigned char * src,
    unsigned char *dst, int width,
    int height, int structWidth, int structHeight)
{

  int mid = (structWidth+1)/2 -1; // 3 or 4
  unsigned char val = 255;

  gettimeofday(&ts2, NULL);

#if 1
  for( int y = 0; y < mid; y++){

    for( int x = 0; x < mid; x++){
      dst[y*width+x] = src[y*width+x];
    }
    for(int x = width - mid -1; x < width; x++){
      dst[y*width+x] = src[y*width+x];
    }
  }


  for( int y = height-mid-1; y < height; y++){
    for( int x = 0; x < mid; x++){
      dst[y*width+x] = src[y*width+x];
    }
    for(int x = width - mid -1; x < width; x++){
      dst[y*width+x] = src[y*width+x];
    }
  }
#endif

  // OPT: To do tiling.
  for( int y = mid; y < height-mid-1; y++){
    for( int x = mid; x < width-mid-1; x++){
      val = 0;
      for( int m = 0; m < structWidth; m++){
        for( int n = 0; n < structHeight; n++){
          val |= src[(y+m)*width+x+n];
        }
      }
      dst[y*width+x] = val;
    }
  }
  gettimeofday(&te2, NULL);
}

int main(int argc, char *argv[])
{
  if( argc < 3 ){
    std::cout<<"Please input Height and Width \n";
    return 0;
  }

  int Height = atoi(argv[1]);
  int Width = atoi(argv[2]);

  unsigned char *src = (unsigned char*) malloc(sizeof(unsigned char)*Width*Height);
  unsigned char *dst = (unsigned char*) malloc(sizeof(unsigned char)*Width*Height);

  for(int i = 0; i < Height; i++)
    for( int j = 0; j < Width; j++){
      src[i*Width+j] = rand()%255;
      //dst[i*Width+j] = src[i*Width+j];
    }

  // warm up.
  //dilation(src, dst, Width, Height, 3, 3 );

  dilation(src, dst, Width, Height, 3, 3 );

  dilation_opt(src, dst, Width, Height, 3, 3 );

  double total = (double)(te1.tv_usec - ts1.tv_usec)*0.001 + (te1.tv_sec - ts1.tv_sec)*1000;
  double total2 = (double)(te2.tv_usec - ts2.tv_usec)*0.001 + (te2.tv_sec - ts2.tv_sec)*1000;

  printf("Total: %f ms\n", total);
  printf("Total2: %f ms\n", total2);

  return 0;
}
