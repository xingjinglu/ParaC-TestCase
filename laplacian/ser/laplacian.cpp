#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
using namespace std;

struct timeval start_cpu[10];
struct timeval end_cpu[10];
double time_prof[10];

static int PyramidFilter(unsigned char *pSrc,unsigned char *pDst,int width ,int height)
{
  int h,w;
  short * pSrc_padding = new short[(width +4)*(height+4)];
  memset(pSrc_padding, 0,(width +4) * (height+4)*sizeof(short));
  int test=0;
  gettimeofday(&start_cpu[0], NULL);

  // step 1.1: Padding new buf: pSrc_padding.

  for (h=2;h<height+2;h++)
  {
    *(pSrc_padding + h*(width+4) + 1) = (pSrc[(h-2)*width +1] * 2) - (pSrc[(h-2) * width + 3]);
    *(pSrc_padding + h*(width+4)    ) = ((pSrc[(h-2)*width +3] )* 4) - ((pSrc[(h-2) * width + 1])*4)
      +((pSrc[(h-2)*width ]) * 2) - ((pSrc[(h-2)*width + 2]));

    *(pSrc_padding +(h+1)*(width +4) -2 ) = ((pSrc[(h-1)*width -2]) *2) - (pSrc[(h-1) *width -4]);
    *(pSrc_padding + (h+1)*(width+4) -1) =((pSrc[(h-1)*width -4]) * 4) -((pSrc[(h-1)*width-2]) *4)
      +((pSrc[(h-1)*width -1]) *2) -((pSrc[(h-1)*width-3]));
    for(w=0;w<width;w++)
      *(pSrc_padding +h*(width +4) +w + 2 ) = pSrc[(h-2)*width +w];
  }

  // step 1.2: Horizontal filter.  
  unsigned char * pBufL_cp = new unsigned char[width * height];
  for(h=0;h<height;h++)
    for(w=0;w<width;w++)
    {
      *(pBufL_cp+h*width+w) = (  pSrc_padding[(w) + (h +2) * (width +4)] + 
          (pSrc_padding[(w + 1) +  (h +2) * (width + 4)]<<2) +
          6*pSrc_padding[(w+2) + (h+2) * (width + 4)] + 
          (pSrc_padding[(w+3) + (h+2) * (width + 4)]<<2) + 
          pSrc_padding[(w+4) + (h +2) * (width + 4)]+8)>>4  ;
    }
  gettimeofday(&end_cpu[0], NULL);	


  // step 1.3. Padding new buf: pBufL_padding (alias to pSrc_padding).

  //------ Vertical Filter ------	
  gettimeofday(&start_cpu[1], NULL);
  short*pBufL_padding = pSrc_padding;//use pSrc_padding again
  memset(pBufL_padding, 0,(width  +4)*(height+4) * sizeof(short));

  for(h=2;h<height +2;h++)
  {
    for(w=0;w<width;w++)
      *(pBufL_padding+h*(width+4) + w+2)= pBufL_cp[(h-2)*width +w];
  }
  for(w =2;w<(width +2);w++)
  {
    *(pBufL_padding+w+width+4)=(pBufL_cp[1*(width) + w -2] *2) -(pBufL_cp[3*(width)+w -2]);
    *(pBufL_padding+ w)= ((pBufL_cp[3*(width)+w -2]) * 4) -((pBufL_cp[1*(width) + w -2 ]) *4)
      +((pBufL_cp[w -2]) * 2) -((pBufL_cp[2*(width) + w - 2]));

    *(pBufL_padding+ w + (height+2)*(width +4)) = (pBufL_cp[(height -2)*(width) + w -2 ] *2 )-(pBufL_cp[(height-4)*(width) + w -2]);
    *(pBufL_padding+ w + (height+3)*(width +4)) = ((pBufL_cp[(height -4)*(width) + w -2 ]) *4 )-((pBufL_cp[(height-2)*(width) + w -2]) *4)
      +((pBufL_cp[(height -1 )*(width) + w -2 ]) *2 ) -((pBufL_cp[(height - 3  )*(width)+w -2 ]));
  }

  // step 1.4. Vertical filter.
  for(w=0;w<width;w++)
    for(h=0;h<height;h++)
    {
      *(pDst+h*width+w) =  (pBufL_padding[(w +2) + (width +4)* (h)]+
          (pBufL_padding[(w +2) +(width +4)*(h + 1)]<<2) +
          6 * pBufL_padding[(w+2) + (width+4)*(h+2)] + 
          (pBufL_padding[(w + 2) + (width+4) * (h + 3)]<<2) + 
          pBufL_padding[(w+2)+(width+4)*(h+4)]+8)>>4; 
    }
  gettimeofday(&end_cpu[1], NULL);
}

static void Downsample(unsigned char *pSrc ,unsigned  char *pDst ,int width ,int height)
{
  int x,y;

  int halfWidth = (width +1)>>1;
  int halfHeight = (height +1)>>1;

  gettimeofday(&start_cpu[2], NULL);
  for(y=0;y<halfHeight;y++)
  {
    for(x=0;x<halfWidth;x++)
    {
      pDst[x] = pSrc[x<<1];
    }
    pDst +=halfWidth;
    pSrc +=(width <<1);
  }
  gettimeofday(&end_cpu[2], NULL);
}

static void UpsampleX4_reverse(unsigned char *pSrc ,unsigned char *pDst,int width ,int height)
{
  int x,y;
  int halfWidth = width>>1;
  int halfHeight = height>>1;
  int widthOdd = width - (halfWidth<<1);
  int heightOdd = height - (halfHeight<<1);

  unsigned char *pSrcL0;
  unsigned char *pSrcL1;
  unsigned char *pDstL0;
  unsigned char *pDstL1;

  gettimeofday(&start_cpu[3], NULL);	
  if(heightOdd ==0) // First row.
  {
    pSrcL0 = pSrc + (halfWidth + widthOdd )*(halfHeight -1);
    pDstL0 = pDst + width*(height -1);
    *(pDstL0 ++) =pSrcL0[0];
    for(x=1;x<halfWidth+widthOdd;x++)
    {
      *(pDstL0 ++) = (pSrcL0[x-1] + pSrcL0[x] +1)>>1;
      *(pDstL0 ++) = pSrcL0[x];
    }
    if(widthOdd ==0)
    {
      *(pDstL0 ++) = pSrcL0[halfWidth-1];
    }
  }


  if(heightOdd ==0)
  {
    pDstL1 = pDst  + width*(height  -2);
    pDstL0  =pDstL1 - width;
  }
  else
  {
    pDstL1 = pDst  + width*(height  -1);
    pDstL0  =pDstL1 - width;
  }
  pSrcL1 = pSrc  + (halfWidth + widthOdd) *(halfHeight + heightOdd -1);
  pSrcL0  =pSrcL1 - (halfWidth +widthOdd);

  for(y=halfHeight + heightOdd -1;y>0;y--)
  {
    pDstL0 ++;
    pDstL1 ++;
    for(x=1;x<halfWidth+widthOdd;x++)
    {

      *(pDstL0 ++) =(pSrcL0[x-1]  + pSrcL0[x]+pSrcL1[x-1] + pSrcL1[x] +2)>>2;
      *(pDstL0 ++) =(pSrcL0[x]  + pSrcL1[x]+1)>>1;


      *(pDstL1 ++) =(pSrcL1[x-1]  + pSrcL1[x] +1)>>1;
      *(pDstL1 ++) =pSrcL1[x];
    }

    if(widthOdd ==0)
    {
      *(pDstL0 ++) = (pSrcL0[halfWidth -1]  + pSrcL1[halfWidth- 1]+1)>>1;
      *(pDstL1 ++) = pSrcL1[halfWidth-1];	
    }


    *(pDstL0 -width) = (pSrcL0[0]  + pSrcL1[0]+1)>>1;
    *(pDstL1 -width) = pSrcL1[0];	

    pSrcL0 -=halfWidth +widthOdd;
    pSrcL1 -=halfWidth +widthOdd;
    pDstL0 -=width *3;
    pDstL1 -=width *3;
  }

  pSrcL0 = pSrc;
  pDstL0 = pDst +width -1;
  if(widthOdd ==0)
  {
    *(pDstL0 --) = pSrcL0[halfWidth-1];
  }

  for(x=halfWidth + widthOdd -1;x>0;x--)
  {
    *(pDstL0 --) = pSrcL0[x];
    *(pDstL0 --) = ((int)pSrcL0[x-1] +pSrcL0[x]+1)/2;
  }
  *(pDstL0 --) = pSrcL0[0];

  gettimeofday(&end_cpu[3], NULL);
}

static void CalcLaplacianLayer(signed short *pLaplacianLayer,unsigned char *pSrc,unsigned char *pUpsampleLowpass,int width ,int height)
{
	int x,y;
	gettimeofday(&start_cpu[4], NULL);
	for(y=0;y<height ;y++)
	{
		for(x=0;x<width;x++)
		{
			*pLaplacianLayer++ =(signed short)(*pSrc) - (signed short )(*pUpsampleLowpass);
			
			pSrc++;
			pUpsampleLowpass ++;
		}
	}	
        gettimeofday(&end_cpu[4], NULL);
}

int main(int argc, char** argv)
{   
#if 1
    if(argc < 2) {
      cout << "Please enter matrix size.\n"
           << "The format is: ./Laplacian height width.\n"
           << "Width should be a multiple of 64.\n";
      return 0;
    }

    int height = atoi(argv[1]);
    int width = atoi(argv[2]);
#endif
    //int height = 4096, width = 4096;
    double duration_cpu;
    unsigned char * Source = new unsigned char[width * height];
    for(int i=0; i<height; i++)
      for(int j=0; j<width; j++)
      {
        *(Source+i*width+j) = rand()%255;
      }

    unsigned char * FilterDst = new unsigned char[width * height];

    int halfWidth = (width +1)>>1;
    int halfHeight = (height +1)>>1;
    unsigned char * DownsampleDst = new unsigned char[halfWidth * halfHeight];
    signed short * LaplacianLayer_CPU = new signed short[width * height];

    int test_number = 20;
    for( int i = 0; i < 10; i++){
      time_prof[i] = 0.0;
    }

    for( int i = 0; i < test_number; i++){
      PyramidFilter(Source, FilterDst, width, height);
      Downsample(FilterDst, DownsampleDst, width, height);
      unsigned char * UpsampleDst = FilterDst;
      UpsampleX4_reverse(DownsampleDst, UpsampleDst, width, height);
      CalcLaplacianLayer(LaplacianLayer_CPU, Source, UpsampleDst, width, height);	

      for (int j = 0; j < 5; j++) {
        duration_cpu = 1000 * ((end_cpu[j]).tv_sec - (start_cpu[j]).tv_sec) + ((end_cpu[j]).tv_usec - (start_cpu[j]).tv_usec)/1000.0;
        time_prof[j] +=  duration_cpu;
      }
    }


    cout<< "Size: " << height << " x " << width << endl;
    for (int i = 0; i < 6; i++) {
      duration_cpu = 1000 * ((end_cpu[i]).tv_sec - (start_cpu[i]).tv_sec) + ((end_cpu[i]).tv_usec - (start_cpu[i]).tv_usec)/1000.0;
      if (i == 0)
        cout << "Row_filter: ";
      else if (i == 1)
        cout << "Column_filter: ";
      else if (i == 2)
        cout << "DownSample: ";
      else if (i == 3)
        cout << "UpSample: ";
      else if (i == 4)
        cout << "CalcLaplacian: ";
      else if (i == 5)
        cout << "Total: ";

      printf("%.2f ms\n", time_prof[i]/test_number);
    }
	return 0;
}
