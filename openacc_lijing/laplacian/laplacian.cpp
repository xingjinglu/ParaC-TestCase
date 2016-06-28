#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

struct timeval start_cpu[10];
struct timeval end_cpu[10];

int main(int argc, char** argv)
{   
	if(argc < 2) {
		printf("Please enter matrix size.\nThe format is: ./Laplacian height width.\nWidth should be a multiple of 64.\n");
		return 0;
	}

	//1. problem size
	int height = atoi(argv[1]);
	int width = atoi(argv[2]);
	int halfWidth = (width +1)>>1;
	int halfHeight = (height +1)>>1;

	//2. generate input image
	unsigned char * Source = (unsigned char*)malloc(sizeof(unsigned char) * width * height);
	srand(0);
	for(int i=0; i<height; i++)
		for(int j=0; j<width; j++)
		{
			Source[i*width+j] = rand()%255;
		}

	//3. arrays to work on
	unsigned char * FilterDst = (unsigned char*)malloc(sizeof(unsigned char) * width*height);
	unsigned char * DownsampleDst = (unsigned char*)malloc(sizeof(unsigned char) * halfWidth* halfHeight);
	short * LaplacianLayer_CPU = (short*)malloc(sizeof(short) * width * height);
	short * LaplacianLayer= (short*)malloc(sizeof(short) * width * height);
	int * pSrc_padding = (int*)malloc(sizeof(int) * (width + 4) * (height + 4));
	int * pSrc_padding2 = (int*)malloc(sizeof(int) * (width + 4) * (height + 4));
	unsigned char * UpsampleDst = (unsigned char*)malloc(sizeof(unsigned char) * width * height);
	unsigned char * pBufL_cp = (unsigned char *)malloc(sizeof(unsigned char) * width * height);

//4. iterate 10 times 
for(int ii = 0 ; ii < 10 ; ii ++)
{
	gettimeofday(&start_cpu[0], NULL);
#pragma acc data copyin(Source[0:width*height]) create(FilterDst[0:width*height], DownsampleDst[0:halfWidth*halfHeight], UpsampleDst[0:width*height], pSrc_padding[0:(width+4)*(height+4)], pSrc_padding2[0:(width+4)*(height+4)], pBufL_cp[0:width*height]) copyout(LaplacianLayer[0:width*height])
#pragma cap data copyin(Source[0:width*height]) create(FilterDst[0:width*height], pSrc_padding[0:(width+4)*(height+4)], pSrc_padding2[0:(width+4)*(height+4)], pBufL_cp[0:width*height]) copyout(LaplacianLayer[0:width*height])
	{
		gettimeofday(&start_cpu[1], NULL);

		//loop1: row padding
#pragma cap parallel 
		{
#pragma acc parallel loop gang 
#pragma cap map threadblock([0:0]) thread([0:1])
#pragma cap loop id(0)
			for (int h=2;h<height+2;h++)
			{
				pSrc_padding[h*(width + 4)+1] = 2 * Source[(h-2)*width+1] - 1 * Source[(h-2)*width+3];
				pSrc_padding[h*(width + 4)+0] = 4 * Source[(h-2)*width+3] - 4 * Source[(h-2)*width+1] + 2 * Source[(h-2)*width+0] - 1 * Source[(h-2)*width+2];

				pSrc_padding[h*(width + 4)+width+2] = 2 * Source[(h-2)*width+width- 2] - 1 * Source[(h-2) *width+width - 4];
				pSrc_padding[h*(width + 4)+width+3] = 4 * Source[(h-2)*width+width - 4] - 4 * Source[(h-2)*width+width - 2] + 2 * Source[(h-2)*width+width -1] - 1 * Source[(h-2)*width+width-3];
#pragma acc loop worker 
#pragma cap loop id(1)
				for(int w=0;w<width;w++)
					pSrc_padding[h*(width + 4)+w + 2] = Source[(h-2)*width+w];
			}
		}

		gettimeofday(&end_cpu[1], NULL);  

		gettimeofday(&start_cpu[2], NULL);  	

		//loop2: row filtering
#pragma cap parallel 
		{
#pragma acc parallel loop collapse(2) 
#pragma cap map threadblock([0:3][1:2]) thread([0:3][1:2])
#pragma cap loop id(2)
			for(int h=0;h<height;h++)
#pragma cap loop id(3)
				for(int w=0;w<width;w++)
				{
					pBufL_cp[h*width+w] = (  pSrc_padding[(h +2)*(width + 4)+w] + 
							(pSrc_padding[(h +2)*(width + 4)+w+1]<<2) +
							6*pSrc_padding[(h+2)*(width + 4)+(w+2)] + 
							(pSrc_padding[(h+2)*(width + 4)+(w+3)]<<2) + 
							pSrc_padding[(h +2)*(width + 4)+(w+4)]+8)>>4  ;
				}
		}
		gettimeofday(&end_cpu[2], NULL);	

		gettimeofday(&start_cpu[3], NULL);

		//loop3: column padding
#pragma cap parallel 
		{
#pragma acc parallel loop collapse(2)
#pragma cap map threadblock([0:5][1:4]) thread([0:5][1:4])
#pragma cap loop id(4)
			for(int h=2;h<height +2;h++)
			{
#pragma cap loop id(5)
				for(int w=0;w<width;w++)
					pSrc_padding2[h*(width + 4)+w+2]= pBufL_cp[(h-2)*width+w];
			}
		}

		//loop4: column padding
#pragma cap parallel
		{
#pragma acc parallel loop 
#pragma cap map threadblock([0:6]) thread([0:6])
#pragma cap loop id(6)
			for(int w =2;w<(width +2);w++)
			{
				pSrc_padding2[1*(width + 4)+w]= 2 * pBufL_cp[1*width+w -2] - 1 * pBufL_cp[3*width+w -2];
				pSrc_padding2[0*(width + 4)+w]= 4 * pBufL_cp[3*width+w -2] - 4 * pBufL_cp[1*width+w -2 ] 
					+ 2 * pBufL_cp[0*width+w -2] - 1 * pBufL_cp[2*width+w - 2];

				pSrc_padding2[(height+2)*(width + 4)+w] = 2 * pBufL_cp[(height -2)*width+w -2 ] - 1 * pBufL_cp[(height-4)*width+w -2];
				pSrc_padding2[(height+3)*(width + 4)+w] = 4 * pBufL_cp[(height -4)*width+w -2 ] - 4 * pBufL_cp[(height-2)*width+w -2] 
					+ 2 * pBufL_cp[(height -1 )*width+w -2 ] - 1 * pBufL_cp[(height - 3  )*width+w -2 ];
			}
		}

		gettimeofday(&end_cpu[3], NULL);

		gettimeofday(&start_cpu[4], NULL);

		//loop5: column filtering
#pragma cap parallel
		{
#pragma acc parallel loop collapse(2)
#pragma cap map threadblock([0:7][1:8]) thread([0:7][1:8])
#pragma cap loop id(7)
			for(int w=0;w<width;w++)
#pragma cap loop id(8)
				for(int h=0;h<height;h++)
				{
					FilterDst[h*width+w] =  (pSrc_padding2[ (h)*(width + 4)+(w +2) ]+
							(pSrc_padding2[(h + 1)*(width + 4)+(w +2) ]<<2) +
							6 * pSrc_padding2[(h+2)*(width + 4)+(w+2) ] + 
							(pSrc_padding2[ (h + 3)*(width + 4)+(w + 2)]<<2) + 
							pSrc_padding2[(h+4)*(width + 4)+(w+2)]+8)>>4; 
				}
		}
		gettimeofday(&end_cpu[4], NULL);

		gettimeofday(&start_cpu[5], NULL);

		//loop6: Downsample
#pragma cap data copyout(DownsampleDst[0:halfHeight*halfWidth]) 
		{
#pragma cap parallel
			{
#pragma acc parallel loop collapse(2) 
#pragma cap map threadblock([0:10][1:9]) thread([0:10][1:9])
#pragma cap loop id(9)
				for(int y=0;y<halfHeight;y++)
				{
#pragma cap loop id(10)
					for(int x=0;x<halfWidth;x++)
					{
						DownsampleDst[y*halfWidth+x] = FilterDst[(y<<1)*width+(x<<1)];
					}
				}
			}
		}
		gettimeofday(&end_cpu[5], NULL);

		gettimeofday(&start_cpu[6], NULL);	

#pragma acc update host(DownsampleDst[0:halfWidth*halfHeight])
		UpsampleDst[(height-1)*width+0] = DownsampleDst[(halfHeight-1)*halfWidth+0];
		UpsampleDst[(height-1)*width+width - 1] = DownsampleDst[(halfHeight-1)*halfWidth+halfWidth-1];
		UpsampleDst[(0)*width+width-1] = DownsampleDst[(0)*halfWidth+halfWidth-1];
		UpsampleDst[(0)*width+0] = DownsampleDst[(0)*halfWidth+0];
#pragma acc update device(UpsampleDst[0:width*height])

		//loop7: Upsample
#pragma cap data copyin(DownsampleDst[0:halfHeight*halfWidth], UpsampleDst[0:width*height])
		{
#pragma cap parallel
			{
#pragma acc parallel loop
#pragma cap map threadblock([0:11]) thread([0:11])
#pragma cap loop id(11)
				for(int x=1;x<halfWidth;x++)
				{
					UpsampleDst[(height-1)*width+2 * x - 1] = (DownsampleDst[(halfHeight-1)*halfWidth+x-1] + DownsampleDst[(halfHeight-1)*halfWidth+x] + 1) >> 1;
					UpsampleDst[(height-1)*width+2 * x] = DownsampleDst[(halfHeight-1)*halfWidth+x];
				}
			}


		//loop8: Upsample
#pragma cap parallel
		{
#pragma acc parallel loop gang
#pragma cap map threadblock([0:13][1:12]) thread([0:13][1:12])
#pragma cap loop id(12)
			for(int y=halfHeight -1;y>0;y--)
			{
#pragma acc loop worker vector
#pragma cap loop id(13)
				for(int x=1;x<halfWidth;x++)
				{
					UpsampleDst[(2*y-1)*width+2 * x - 1] = (DownsampleDst[(y)*halfWidth+x-1] + DownsampleDst[(y)*halfWidth+x] + DownsampleDst[(y-1)*halfWidth+x-1] + DownsampleDst[(y-1)*halfWidth+x] + 2)>>2;
					UpsampleDst[(2*y-1)*width+2 * x] =  (DownsampleDst[(y)*halfWidth+x] + DownsampleDst[(y-1)*halfWidth+x] + 1)>>1;

					UpsampleDst[(2*y)*width+2 * x - 1] =  (DownsampleDst[(y)*halfWidth+x-1] + DownsampleDst[(y)*halfWidth+x] + 1)>>1;
					UpsampleDst[(2*y)*width+2 * x] =  DownsampleDst[(y)*halfWidth+x] ;
				}

				UpsampleDst[(2*y-1)*width+width-1] =  (DownsampleDst[(y)*halfWidth+halfWidth-1] + DownsampleDst[(y-1)*halfWidth+halfWidth-1] + 1)>>1;
				UpsampleDst[(2*y)*width+width-1] =  DownsampleDst[(y)*halfWidth+halfWidth-1] ;

				UpsampleDst[(2*y-1)*width+0] =  (DownsampleDst[(y)*halfWidth+0] + DownsampleDst[(y-1)*halfWidth+0] + 1)>>1;
				UpsampleDst[(2*y)*width+0] =  DownsampleDst[(y)*halfWidth+0] ;
			}
		}


		//loop9: Upsample
#pragma cap parallel //
		{
#pragma acc parallel loop
#pragma cap map threadblock([0:14]) thread([0:14])
#pragma cap loop id(14)
			for(int x=halfWidth -1;x>0;x--)
			{
				UpsampleDst[(0)*width+2 * x] = DownsampleDst[(0)*halfWidth+x];
				UpsampleDst[(0)*width+2 * x - 1] = ((int)DownsampleDst[(0)*halfWidth+x-1] + DownsampleDst[(0)*halfWidth+x] + 1)/2;
			}
		}

		gettimeofday(&end_cpu[6], NULL);

		gettimeofday(&start_cpu[7], NULL);

		//loop10: Cut
#pragma cap parallel 
		{
#pragma acc parallel loop collapse(2)
#pragma cap map threadblock([0:16][1:15]) thread([0:16][1:15])
#pragma cap loop id(15)
			for(int y=0;y<height ;y++)
			{
#pragma cap loop id(16)
				for(int x=0;x<width;x++)
				{
					LaplacianLayer[y*width+x] =(signed short)(Source[y*width+x]) - (signed short )(UpsampleDst[y*width+x]);
				}
			}	
		}
		}

		gettimeofday(&end_cpu[7], NULL);

	}
	gettimeofday(&end_cpu[0], NULL);

	printf("%d\n", LaplacianLayer[10*width+100]);

	printf( "laplacian: %dx%d\n", height, width );
	for (int i = 0; i < 8; i++) {
		double duration_cpu = 1000 * ((end_cpu[i]).tv_sec - (start_cpu[i]).tv_sec) + ((end_cpu[i]).tv_usec - (start_cpu[i]).tv_usec)/1000.0;
		if (i == 0)
			printf( "Total: ");
		else if (i == 1)
			printf( "Row_padding: ");
		else if (i == 2)
			printf( "Row_filter: ");
		else if (i == 3)
			printf( "Column_padding: ");
		else if (i == 4)
			printf( "Column_filter: ");
		else if (i == 5)
			printf( "DownSample: ");
		else if (i == 6)
			printf( "UpSample: ");
		else if (i == 7)
			printf( "Cut: ");

		printf("%.2f ms\n", duration_cpu);
	}
	printf("\n");
}

#ifdef DEBUG
//1. compute on cpu
//loop1: row padding
for (int h=2;h<height+2;h++)
{
	pSrc_padding[h*(width + 4)+1] = 2 * Source[(h-2)*width+1] - 1 * Source[(h-2)*width+3];
	pSrc_padding[h*(width + 4)+0] = 4 * Source[(h-2)*width+3] - 4 * Source[(h-2)*width+1] + 2 * Source[(h-2)*width+0] - 1 * Source[(h-2)*width+2];

	pSrc_padding[h*(width + 4)+width+2] = 2 * Source[(h-2)*width+width- 2] - 1 * Source[(h-2) *width+width - 4];
	pSrc_padding[h*(width + 4)+width+3] = 4 * Source[(h-2)*width+width - 4] - 4 * Source[(h-2)*width+width - 2] + 2 * Source[(h-2)*width+width -1] - 1 * Source[(h-2)*width+width-3];
	for(int w=0;w<width;w++)
		pSrc_padding[h*(width + 4)+w + 2] = Source[(h-2)*width+w];
}

//loop2: row filtering
for(int h=0;h<height;h++)
for(int w=0;w<width;w++)
pBufL_cp[h*width+w] = (  pSrc_padding[(h +2)*(width + 4)+w] + 
		(pSrc_padding[(h +2)*(width + 4)+w+1]<<2) +
		6*pSrc_padding[(h+2)*(width + 4)+(w+2)] + 
		(pSrc_padding[(h+2)*(width + 4)+(w+3)]<<2) + 
		pSrc_padding[(h +2)*(width + 4)+(w+4)]+8)>>4  ;

//loop3: column padding
for(int h=2;h<height +2;h++)
{
	for(int w=0;w<width;w++)
		pSrc_padding[h*(width + 4)+w+2]= pBufL_cp[(h-2)*width+w];
}

//loop4: column padding
for(int w =2;w<(width +2);w++)
{
	pSrc_padding[1*(width + 4)+w]= 2 * pBufL_cp[1*width+w -2] - 1 * pBufL_cp[3*width+w -2];
	pSrc_padding[0*(width + 4)+w]= 4 * pBufL_cp[3*width+w -2] - 4 * pBufL_cp[1*width+w -2 ] 
		+ 2 * pBufL_cp[0*width+w -2] - 1 * pBufL_cp[2*width+w - 2];

	pSrc_padding[(height+2)*(width + 4)+w] = 2 * pBufL_cp[(height -2)*width+w -2 ] - 1 * pBufL_cp[(height-4)*width+w -2];
	pSrc_padding[(height+3)*(width + 4)+w] = 4 * pBufL_cp[(height -4)*width+w -2 ] - 4 * pBufL_cp[(height-2)*width+w -2] 
		+ 2 * pBufL_cp[(height -1 )*width+w -2 ] - 1 * pBufL_cp[(height - 3  )*width+w -2 ];
}

//loop5: column filtering
for(int w=0;w<width;w++)
for(int h=0;h<height;h++)
{
	FilterDst[h*width+w] =  (pSrc_padding[ (h)*(width + 4)+(w +2) ]+
			(pSrc_padding[(h + 1)*(width + 4)+(w +2) ]<<2) +
			6 * pSrc_padding[(h+2)*(width + 4)+(w+2) ] + 
			(pSrc_padding[ (h + 3)*(width + 4)+(w + 2)]<<2) + 
			pSrc_padding[(h+4)*(width + 4)+(w+2)]+8)>>4; 
}

//loop6: Downsample
for(int y=0;y<halfHeight;y++)
{
	for(int x=0;x<halfWidth;x++)
	{
		DownsampleDst[y*halfWidth+x] = FilterDst[(y<<1)*width+(x<<1)];
	}
}

UpsampleDst[(height-1)*width+0] = DownsampleDst[(halfHeight-1)*halfWidth+0];
UpsampleDst[(height-1)*width+width - 1] = DownsampleDst[(halfHeight-1)*halfWidth+halfWidth-1];
UpsampleDst[(0)*width+width-1] = DownsampleDst[(0)*halfWidth+halfWidth-1];
UpsampleDst[(0)*width+0] = DownsampleDst[(0)*halfWidth+0];

//loop7: Upsample
for(int x=1;x<halfWidth;x++)
{
	UpsampleDst[(height-1)*width+2 * x - 1] = (DownsampleDst[(halfHeight-1)*halfWidth+x-1] + DownsampleDst[(halfHeight-1)*halfWidth+x] + 1) >> 1;
	UpsampleDst[(height-1)*width+2 * x] = DownsampleDst[(halfHeight-1)*halfWidth+x];
}


//loop8: Upsample
for(int y=halfHeight -1;y>0;y--)
{
	for(int x=1;x<halfWidth;x++)
	{
		UpsampleDst[(2*y-1)*width+2 * x - 1] = (DownsampleDst[(y)*halfWidth+x-1] + DownsampleDst[(y)*halfWidth+x] + DownsampleDst[(y-1)*halfWidth+x-1] + DownsampleDst[(y-1)*halfWidth+x] + 2)>>2;
		UpsampleDst[(2*y-1)*width+2 * x] =  (DownsampleDst[(y)*halfWidth+x] + DownsampleDst[(y-1)*halfWidth+x] + 1)>>1;

		UpsampleDst[(2*y)*width+2 * x - 1] =  (DownsampleDst[(y)*halfWidth+x-1] + DownsampleDst[(y)*halfWidth+x] + 1)>>1;
		UpsampleDst[(2*y)*width+2 * x] =  DownsampleDst[(y)*halfWidth+x] ;
	}

	UpsampleDst[(2*y-1)*width+width-1] =  (DownsampleDst[(y)*halfWidth+halfWidth-1] + DownsampleDst[(y-1)*halfWidth+halfWidth-1] + 1)>>1;
	UpsampleDst[(2*y)*width+width-1] =  DownsampleDst[(y)*halfWidth+halfWidth-1] ;

	UpsampleDst[(2*y-1)*width+0] =  (DownsampleDst[(y)*halfWidth+0] + DownsampleDst[(y-1)*halfWidth+0] + 1)>>1;
	UpsampleDst[(2*y)*width+0] =  DownsampleDst[(y)*halfWidth+0] ;
}


//loop9: Upsample
for(int x=halfWidth -1;x>0;x--)
{
	UpsampleDst[(0)*width+2 * x] = DownsampleDst[(0)*halfWidth+x];
	UpsampleDst[(0)*width+2 * x - 1] = ((int)DownsampleDst[(0)*halfWidth+x-1] + DownsampleDst[(0)*halfWidth+x] + 1)/2;
}


//loop10: Cut
for(int y=0;y<height ;y++)
{
	for(int x=0;x<width;x++)
	{
		LaplacianLayer_CPU[y*width+x] =(signed short)(Source[y*width+x]) - (signed short )(UpsampleDst[y*width+x]);
	}
}	

	//compare
	bool error = false;
	for(int h =0;h<height;h++)
	{
		for(int w=0;w<width;w++)
		{
			if(abs(LaplacianLayer_CPU[h*width+w] - LaplacianLayer[h*width+w]) > 1)
			{
				error = true;
				printf("CPU:%d GPU:%d\n", LaplacianLayer_CPU[h*width+w], LaplacianLayer[h*width+w]);
			}
		}
	}

	if(error)
		printf("Error\n");
	else
		printf("OK\n");

#endif

	free(Source);
	free(FilterDst); 
	free(DownsampleDst);
	free(LaplacianLayer_CPU); 
	free(LaplacianLayer);
	free(pSrc_padding);
	free(UpsampleDst);
	free(pBufL_cp);

	return 0;
}
