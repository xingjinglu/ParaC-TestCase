//sharpness.cpp
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<sys/time.h>

#define MIN2(a,b)  ((a)<(b) ? (a):(b))
#define MAX2(a,b)  ((a)>(b) ? (a):(b))
#define MAX3(a,b,c)   (MAX2((a),MAX2((b),(c))))
#define MIN3(a,b,c)   (MIN2((a),MIN2((b),(c))))

struct timeval start_cpu[10];
struct timeval end_cpu[10];

void usage()
{
	printf("usage:sharpness width height\n");
}

int main(int argc,char* argv[])
{
	//1. read in problem size
	int width=0,height=0;
	if(3 !=argc)
	{
		usage();
		return -1;
	}
	width=atoi(argv[1]);
	height=atoi(argv[2]);
	int quarterWidth = width / 4;
	int quarterHeight = height / 4;


	//2. generate a source image
	unsigned char *yuvfile=(unsigned char*)malloc(sizeof(unsigned char)*width*height);
	memset(yuvfile,0,width*height*sizeof(char));
	srand(0);
	for(int i=0;i<height*width;i++)
	{
		yuvfile[i]=rand()%100+1;
	}
        	
	//3. arrays to work on
	unsigned char * yPlane = (unsigned char*) malloc(sizeof(unsigned char) * height * width);
	unsigned char * yPlane_cpu = (unsigned char*) malloc(sizeof(unsigned char) * height * width);
	unsigned char * yPlaneCSER = (unsigned char*) malloc(sizeof(unsigned char) * height * width);
	unsigned char * yPlaneDown = (unsigned char*) malloc(sizeof(unsigned char) * quarterHeight * quarterWidth);
	short * pError = (short*) malloc(sizeof(short) * height * width);
	short * pEdge = (short*) malloc(sizeof(short) * height * width);
	short * pSharpness = (short*) malloc(sizeof(short) * height * width);
	
	//4. parameters
	long sum = 0;
	short mean = 0;
	double oldpeak = 2.0f;
	double oldcutoffCoef = 1.0f;
	double oldcutoff2 = 256.0f;
	double oldcutoff3Coef = 1.0f;
	
	//5. use 10 iterations to compromise cold start cost
	for(int ii = 0 ; ii < 10 ; ii++)
	{
		//6. init yPlane[i] every time
		for(int i=0;i<height*width;i++)
		{
			yPlane[i] = yuvfile[i];
		}

		gettimeofday(&start_cpu[0], NULL);

#pragma acc data copyin(sum) copy(yPlane[0:width*height]), create(yPlaneCSER[0:width*height], yPlaneDown[0:quarterHeight*quarterWidth], pError[0:width*height], pEdge[0:width*height], pSharpness[0:width*height])
#pragma cap data copy(yPlane[0:width*height]), create(yPlaneCSER[0:width*height], yPlaneDown[0:quarterHeight*quarterWidth], pError[0:width*height], pEdge[0:width*height], pSharpness[0:width*height])
		{
			gettimeofday(&start_cpu[1], NULL);

			//loop 1: Downsample
#pragma cap parallel 
{
#pragma acc parallel loop collapse(2)
#pragma cap map threadblock([0:1][1:0]) thread([0:1][1:0])
#pragma cap loop id(0)
			for(int i=0;i<height;i +=4)
			{
#pragma cap loop id(1)
				for(int j=0;j<width;j +=4)
				{
					yPlaneDown[(i/4)*quarterWidth+j/4] = (yPlane[i*width+j] + yPlane[i*width+j+1] + yPlane[i*width+j+2] + yPlane[i*width+j+3]
							+ yPlane[(i+1)*width+j] + yPlane[(i+1)*width+j+1] + yPlane[(i+1)*width+j+2] + yPlane[(i+1)*width+j+3]
							+ yPlane[(i+2)*width+j] + yPlane[(i+2)*width+j+1] + yPlane[(i+2)*width+j+2] + yPlane[(i+2)*width+j+3]
							+ yPlane[(i+3)*width+j] + yPlane[(i+3)*width+j+1] + yPlane[(i+3)*width+j+2] + yPlane[(i+3)*width+j+3] + 8) >> 4;
				}
			}
}

			gettimeofday(&end_cpu[1], NULL);

			gettimeofday(&start_cpu[2], NULL);

			//loop 2: Upsample, column 1
#pragma cap parallel 
{
#pragma acc parallel loop 
#pragma cap map threadblock([0:2]) thread([0:2])
#pragma cap loop id(2)
			for(int h=0;h<quarterHeight;h++)
			{
				yPlaneCSER[h*4*width+0] = yPlaneDown[h*quarterWidth+0];
			}
}

			//loop 3: Upsample, column 1
#pragma cap parallel
{
#pragma acc parallel loop 
#pragma cap map threadblock([0:3]) thread([0:3])
#pragma cap loop id(3)
			for(int h=0;h<quarterHeight;h++)
			{
				if (h < quarterHeight - 1)
				{
					yPlaneCSER[(h*4+1)*width+0] = (yPlaneCSER[(h*4)*width+0] * 3 + yPlaneCSER[(h*4+4)*width+0] * 1)/4;
					yPlaneCSER[(h*4+2)*width+0] = (yPlaneCSER[(h*4)*width+0] * 2 + yPlaneCSER[(h*4+4)*width+0] * 2)/4;
					yPlaneCSER[(h*4+3)*width+0] = (yPlaneCSER[(h*4)*width+0] * 1 + yPlaneCSER[(h*4+4)*width+0] * 3)/4;
				}
				else
				{
					yPlaneCSER[(h*4+1)*width+0] = yPlaneCSER[(h*4)*width+0];
				}
			}
}

			//loop 4: Upsample, column 2 
#pragma cap parallel
{
#pragma acc kernels loop independent
#pragma cap map threadblock([0:4]) thread([0:4])
#pragma cap loop id(4)
			for(int h=0;h<height;h++)
			{
				yPlaneCSER[(h)*width+1] = yPlaneCSER[(h)*width+0];
			}
}

			//loop 5: Upsample, row 1
#pragma cap parallel //
#pragma cap fuse loop(5,8) depth(1)
{
#pragma acc kernels loop independent
#pragma cap map threadblock([0:5]) thread([0:5])
#pragma cap loop id(5)
			for(int w=0;w<quarterWidth;w++)
			{
				yPlaneCSER[0*width+w*4] = yPlaneDown[0*quarterWidth+w];
			}
			//loop 8: Upsample, row - 2
#pragma acc kernels loop independent 
#pragma cap map threadblock([0:8]) thread([0:8])
#pragma cap loop id(8)
			for(int w=0;w<quarterWidth;w++)
			{
				yPlaneCSER[(height-2)*width+w*4] = yPlaneDown[(quarterHeight-1)*quarterWidth+w];
			}
}

			//loop 6: Upsample, row 1 
#pragma cap parallel
#pragma cap fuse loop(6,9) depth(1)
{
#pragma acc kernels loop independent 
#pragma cap map threadblock([0:6]) thread([0:6])
#pragma cap loop id(6)
			for(int w=0;w<quarterWidth;w++)
			{
				if(w < quarterWidth - 1)
				{
					yPlaneCSER[(0)*width+w*4+1] = (yPlaneCSER[(0)*width+w*4] * 3 + yPlaneCSER[(0)*width+w*4+4] * 1)/4;
					yPlaneCSER[(0)*width+w*4+2] = (yPlaneCSER[(0)*width+w*4] * 2 + yPlaneCSER[(0)*width+w*4+4] * 2)/4;
					yPlaneCSER[(0)*width+w*4+3] = (yPlaneCSER[(0)*width+w*4] * 1 + yPlaneCSER[(0)*width+w*4+4] * 3)/4;
				}
				else
				{
					yPlaneCSER[(0)*width+w*4+1] = yPlaneCSER[(0)*width+w*4];
				}
			}
			//loop 9: Upsample, row - 2
#pragma acc kernels  loop independent 
#pragma cap map threadblock([0:9]) thread([0:9])
#pragma cap loop id(9)
			for(int w=0;w<quarterWidth;w++)
			{
				if(w < quarterWidth -1)
				{
					yPlaneCSER[(height-2)*width+w*4+1] = (yPlaneCSER[(height-2)*width+w*4] * 3 + yPlaneCSER[(height-2)*width+w*4+4] * 1)/4;
					yPlaneCSER[(height-2)*width+w*4+2] = (yPlaneCSER[(height-2)*width+w*4] * 2 + yPlaneCSER[(height-2)*width+w*4+4] * 2)/4;
					yPlaneCSER[(height-2)*width+w*4+3] = (yPlaneCSER[(height-2)*width+w*4] * 1 + yPlaneCSER[(height-2)*width+w*4+4] * 3)/4;
				}
				else
				{
					yPlaneCSER[(height-2)*width+w*4+1] = yPlaneCSER[(height-2)*width+w*4];
				}
			}
}

			//loop 7: Upsample, row 2
#pragma cap parallel
#pragma cap fuse loop(7,10) depth(1)
{
#pragma acc kernels loop independent 
#pragma cap map threadblock([0:7]) thread([0:7])
#pragma cap loop id(7)
	for(int w=0;w<width;w++)
	{
		yPlaneCSER[1*width+w] = yPlaneCSER[0*width+w];
	}

	//loop 10: Upsample, row - 1
#pragma acc kernels  loop independent 
#pragma cap map threadblock([0:10]) thread([0:10])
#pragma cap loop id(10)
	for(int w=0;w<width;w++)
	{
		yPlaneCSER[(height-1)*width+w] = yPlaneCSER[(height-2)*width+w];
	}
}

			//loop 11: Upsample, col - 2
#pragma cap parallel 
{
#pragma acc kernels  loop independent
#pragma cap map threadblock([0:11]) thread([0:11])
#pragma cap loop id(11)
			for(int h=0;h<quarterHeight;h++)
			{
				yPlaneCSER[(h*4)*width+width-2] = yPlaneDown[h*quarterWidth+quarterWidth-1];
			}
}

			//loop 12: Upsample, col - 2
#pragma cap parallel 
{
#pragma acc kernels  loop independent 
#pragma cap map threadblock([0:12]) thread([0:12])
#pragma cap loop id(12)
			for(int h=0;h<quarterHeight;h++)
			{
				if(h < quarterHeight - 1)
				{
					yPlaneCSER[(h*4+1)*width+width-2] = (yPlaneCSER[(h*4)*width+width-2] * 3 + yPlaneCSER[(h*4+4)*width+width-2] * 1)/4;
					yPlaneCSER[(h*4+2)*width+width-2] = (yPlaneCSER[(h*4)*width+width-2] * 2 + yPlaneCSER[(h*4+4)*width+width-2] * 2)/4;
					yPlaneCSER[(h*4+3)*width+width-2] = (yPlaneCSER[(h*4)*width+width-2] * 1 + yPlaneCSER[(h*4+4)*width+width-2] * 3)/4;
				}
				else
				{
					yPlaneCSER[(h*4+1)*width+width-2] = yPlaneCSER[(h*4)*width+width-2];
					yPlaneCSER[(h*4+2)*width+width-2] = yPlaneCSER[(h*4)*width+width-2];
					yPlaneCSER[(h*4+3)*width+width-2] = yPlaneCSER[(h*4)*width+width-2];
				}
			}
}

			//loop 13: Upsample, col - 1
#pragma cap parallel 
{
#pragma acc kernels  loop independent
#pragma cap map threadblock([0:13]) thread([0:13])
#pragma cap loop id(13)
			for(int h=0;h<height;h++)
			{	
				yPlaneCSER[(h)*width+width-1] = yPlaneCSER[(h)*width+width-2];
			}
}

			//loop 14: Upsample, main body
#pragma cap parallel 
{
#pragma acc kernels loop collapse(2) independent 
#pragma cap map threadblock([0:15][1:14]) thread([0:15][1:14])
#pragma cap loop id(14)
			for(int h=0;h<quarterHeight-1;h++)
			{
#pragma cap loop id(15)
				for(int w=0;w<quarterWidth-1;w++)
				{
					yPlaneCSER[(h*4+2)*width+w*4+2] = (yPlaneDown[(h)*quarterWidth+w] * 7 + yPlaneDown[(h)*quarterWidth+w+1] * 1) * 7 /8 / 8 + (yPlaneDown[(h+1)*quarterWidth+w] * 7 + yPlaneDown[(h+1)*quarterWidth+w+1] * 1) / 8 / 8;
					yPlaneCSER[(h*4+2)*width+w*4+2+1] = (yPlaneDown[(h)*quarterWidth+w] * 5 + yPlaneDown[(h)*quarterWidth+w+1] * 3) * 7/8 /8 + (yPlaneDown[(h+1)*quarterWidth+w] * 5 + yPlaneDown[(h+1)*quarterWidth+w+1] * 3)/8 /8;
					yPlaneCSER[(h*4+2)*width+w*4+2+2] = (yPlaneDown[(h)*quarterWidth+w] * 3 + yPlaneDown[(h)*quarterWidth+w+1] * 5) * 7/8 /8 + (yPlaneDown[(h+1)*quarterWidth+w] * 3 + yPlaneDown[(h+1)*quarterWidth+w+1] * 5)/8 /8;
					yPlaneCSER[(h*4+2)*width+w*4+2+3] = (yPlaneDown[(h)*quarterWidth+w] * 1 + yPlaneDown[(h)*quarterWidth+w+1] * 7) * 7/8 /8 + (yPlaneDown[(h+1)*quarterWidth+w] * 1 + yPlaneDown[(h+1)*quarterWidth+w+1] * 7)/8 /8;

					yPlaneCSER[(h*4+3)*width+w*4+2  ] = (yPlaneDown[(h)*quarterWidth+w] * 7+ yPlaneDown[(h)*quarterWidth+w+1] * 1)* 5/8 /8 + (yPlaneDown[(h+1)*quarterWidth+w] * 7 + yPlaneDown[(h+1)*quarterWidth+w+1] * 1) * 3/8/8;
					yPlaneCSER[(h*4+3)*width+w*4+2+1] = (yPlaneDown[(h)*quarterWidth+w] * 5+ yPlaneDown[(h)*quarterWidth+w+1] * 3)* 5/8 /8 + (yPlaneDown[(h+1)*quarterWidth+w] * 5 + yPlaneDown[(h+1)*quarterWidth+w+1] * 3) * 3/8/8;
					yPlaneCSER[(h*4+3)*width+w*4+2+2] = (yPlaneDown[(h)*quarterWidth+w] * 3+ yPlaneDown[(h)*quarterWidth+w+1] * 5)* 5/8 /8 + (yPlaneDown[(h+1)*quarterWidth+w] * 3 + yPlaneDown[(h+1)*quarterWidth+w+1] * 5) * 3/8/8;
					yPlaneCSER[(h*4+3)*width+w*4+2+3] = (yPlaneDown[(h)*quarterWidth+w] * 1+ yPlaneDown[(h)*quarterWidth+w+1] * 7)* 5/8 /8 + (yPlaneDown[(h+1)*quarterWidth+w] * 1 + yPlaneDown[(h+1)*quarterWidth+w+1] * 7) * 3/8/8;

					yPlaneCSER[(h*4+4)*width+w*4+2  ] = (yPlaneDown[(h)*quarterWidth+w] * 7 + yPlaneDown[(h)*quarterWidth+w+1] * 1) * 3/8/8 + (yPlaneDown[(h+1)*quarterWidth+w] * 7 + yPlaneDown[(h+1)*quarterWidth+w+1] * 1) * 5/8/8;
					yPlaneCSER[(h*4+4)*width+w*4+2+1] = (yPlaneDown[(h)*quarterWidth+w] * 5 + yPlaneDown[(h)*quarterWidth+w+1] * 3) * 3/8/8 + (yPlaneDown[(h+1)*quarterWidth+w] * 5 + yPlaneDown[(h+1)*quarterWidth+w+1] * 3) * 5/8/8;
					yPlaneCSER[(h*4+4)*width+w*4+2+2] = (yPlaneDown[(h)*quarterWidth+w] * 3 + yPlaneDown[(h)*quarterWidth+w+1] * 5) * 3/8/8 + (yPlaneDown[(h+1)*quarterWidth+w] * 3 + yPlaneDown[(h+1)*quarterWidth+w+1] * 5) * 5/8/8;
					yPlaneCSER[(h*4+4)*width+w*4+2+3] = (yPlaneDown[(h)*quarterWidth+w] * 1 + yPlaneDown[(h)*quarterWidth+w+1] * 7) * 3/8/8 + (yPlaneDown[(h+1)*quarterWidth+w] * 1 + yPlaneDown[(h+1)*quarterWidth+w+1] * 7) * 5/8/8;

					yPlaneCSER[(h*4+5)*width+w*4+2  ] = (yPlaneDown[(h)*quarterWidth+w] * 7 + yPlaneDown[(h)*quarterWidth+w+1] * 1) * 1/8/8 + (yPlaneDown[(h+1)*quarterWidth+w] * 7 + yPlaneDown[(h+1)*quarterWidth+w+1] * 1) * 7/8/8;
					yPlaneCSER[(h*4+5)*width+w*4+2+1] = (yPlaneDown[(h)*quarterWidth+w] * 5 + yPlaneDown[(h)*quarterWidth+w+1] * 3) * 1/8/8 + (yPlaneDown[(h+1)*quarterWidth+w] * 5 + yPlaneDown[(h+1)*quarterWidth+w+1] * 3) * 7/8/8;
					yPlaneCSER[(h*4+5)*width+w*4+2+2] = (yPlaneDown[(h)*quarterWidth+w] * 3 + yPlaneDown[(h)*quarterWidth+w+1] * 5) * 1/8/8 + (yPlaneDown[(h+1)*quarterWidth+w] * 3 + yPlaneDown[(h+1)*quarterWidth+w+1] * 5) * 7/8/8;
					yPlaneCSER[(h*4+5)*width+w*4+2+3] = (yPlaneDown[(h)*quarterWidth+w] * 1 + yPlaneDown[(h)*quarterWidth+w+1] * 7) * 1/8/8 + (yPlaneDown[(h+1)*quarterWidth+w] * 1 + yPlaneDown[(h+1)*quarterWidth+w+1] * 7) * 7/8/8;
				}
			}
}
			gettimeofday(&end_cpu[2], NULL);

			gettimeofday(&start_cpu[3], NULL);
#pragma cap parallel 
#pragma cap fuse loop(18,20) depth(2)
{
			//loop 16: Sobel
#pragma acc parallel loop collapse(2)
#pragma cap map threadblock([0:19][1:18]) thread([0:19][1:18])
#pragma cap loop id(18)
			for(int y = 0; y < height; y++)
			{
#pragma cap loop id(19)
				for(int x = 0; x < width; x++)
				{
					if(y == 0 || y == height - 1 || x == 0 || x==width - 1)
					{
						pEdge[y*width+x] = 0;
					}
					else
					{
						int gx = (yPlane[(y-1)*width+x+1] + ((int)yPlane[(y)*width+x+1]<<1) + yPlane[(y+1)*width+x+1]) - (yPlane[(y-1)*width+x-1] + ((int)yPlane[(y)*width+x-1]<<1) + yPlane[(y+1)*width+x-1]);
						int gy = (yPlane[(y-1)*width+x-1] + ((int)yPlane[(y-1)*width+x]<<1) + yPlane[(y-1)*width+x+1]) - (yPlane[(y+1)*width+x-1] + ((int)yPlane[(y+1)*width+x]<<1) + yPlane[(y+1)*width+x+1]);
						int edgeV=(abs(gx)+abs(gy));
						pEdge[y*width+x] = edgeV;
					}
				}
			}

			//loop 17: Mean
#pragma acc parallel loop reduction(+:sum) collapse(2) 
#pragma cap map threadblock([0:21][1:20]) thread([0:21][1:20])
#pragma cap loop id(20) reduction(+:sum)
			for(int i=0;i<height;i++)
			{
#pragma cap loop id(21)
				for(int j=0;j<width;j++)
				{
					sum += pEdge[i*width+j];
				}
			}
}

#pragma acc update host(sum[0:1])
			mean=(sum+(height*width)/2)/(height*width);

			double cutoff=oldcutoffCoef*mean;
			double peak=oldpeak;
			double cutoff2=oldcutoff2;

			double order=2;
			double order2=2;
			double low = 1.0;

			float cutoff3=oldcutoff3Coef*mean;
			float order3=2;
			float peak3=1;
			float low3=0.05f;

			gettimeofday(&end_cpu[3], NULL);

			gettimeofday(&start_cpu[4], NULL);

			//loop 15: Error
#pragma cap parallel 
#pragma cap fuse loop(16,22,24) depth(2)
{
#pragma acc parallel loop  collapse(2)
#pragma cap map threadblock([0:17][1:16]) thread([0:17][1:16])
#pragma cap loop id(16)
			for(int h=0;h<height;h++)
			{
#pragma cap loop id(17)
				for(int w=0;w<width;w++)
				{
					pError[h*width+w]=yPlane[h*width+w]-yPlaneCSER[h*width+w];
				}		
			}

			//loop 18: Strength
#pragma acc parallel loop  collapse(2)
#pragma cap map threadblock([0:23][1:22]) thread([0:23][1:22])
#pragma cap loop id(22)
			for(int h=0;h<height;h++)
			{
#pragma cap loop id(23)
				for(int w=0;w<width;w++)
				{
					short edge = pEdge[h*width+w];
					double weight=1/(1+pow(edge/cutoff2,2*order2));
					double strength=(peak-low)*(1-1/(1+pow(edge/cutoff,2*order)));
					strength=strength*weight+low;

					pSharpness[h*width+w]=(yPlaneCSER[h*width+w]);
					pSharpness[h*width+w]+=(double)(pError[h*width+w])*strength;
				}
			}

			//loop 19: Overshoot
#pragma acc parallel loop  collapse(2) 
#pragma cap map threadblock([0:25][1:24]) thread([0:25][1:24])
#pragma cap loop id(24)
			for(int h=0;h<height;h++)
			{
#pragma cap loop id(25)
				for(int w=0;w<width;w++)
				{
					if(!(h == 0 || h == height - 1 || w == 0 || w == width - 1))
					{
						int enhanced,maxValue,minValue;
						double oscStrength;
						enhanced = pSharpness[h*width+w];

						maxValue = MAX2(MAX2(yPlane[(h-1)*width+w-1], yPlane[(h-1)*width+w]), yPlane[(h-1)*width+w+1]);
						maxValue = MAX2(maxValue, MAX2(MAX2(yPlane[(h)*width+w-1], yPlane[(h)*width+w]), yPlane[(h)*width+w+1]));
						maxValue = MAX2(maxValue, MAX2(MAX2(yPlane[(h+1)*width+w-1], yPlane[(h+1)*width+w]), yPlane[(h+1)*width+w+1]));

						minValue = MIN3(yPlane[(h-1)*width+w-1], yPlane[(h-1)*width+w], yPlane[(h-1)*width+w+1]);
						minValue = MIN2(minValue, MIN3(yPlane[(h)*width+w-1], yPlane[(h)*width+w], yPlane[(h)*width+w+1]));
						minValue = MIN2(minValue, MIN3(yPlane[(h+1)*width+w-1], yPlane[(h+1)*width+w], yPlane[(h+1)*width+w+1]));

						//oscStrength=GetOSCX16(*pEdge,cutoff,order,peak,low);
						{
							double cutoff2Order=pow(cutoff3,2*order3);
							double edge2Order=pow((double)(pEdge[h*width+w]),(double)2*order3);
							oscStrength=(peak3*cutoff2Order+low3*edge2Order)/(cutoff2Order+edge2Order);
						}	

						//过冲控制
						if(enhanced>maxValue)
						{
							pSharpness[h*width+w] = MIN2(maxValue + oscStrength * (enhanced - maxValue), 255);
						}
						else if(enhanced<minValue)
						{
							pSharpness[h*width+w] = MAX2(0, minValue - oscStrength * (minValue - enhanced));
						}
						else
						{
							pSharpness[h*width+w] = MIN2(MAX2(enhanced, 0), 255);
						}
					}
				}
			}
}

			gettimeofday(&end_cpu[4], NULL);

			gettimeofday(&start_cpu[5], NULL);

			//loop 20
#pragma cap parallel 
{
#pragma acc parallel loop  collapse(2)
#pragma cap map threadblock([0:27][1:26]) thread([0:27][1:26])
#pragma cap loop id(26)
			for(int h =0;h<height;h++)
			{
#pragma cap loop id(27)
				for(int w=0;w<width;w++)
				{
					yPlane[h*width+w] = pSharpness[h*width+w] > 255 ? 255 : pSharpness[h*width+w] < 0 ? 0 : pSharpness[h*width+w]; 
				}
			}
}
			gettimeofday(&end_cpu[5], NULL);

		}
		gettimeofday(&end_cpu[0], NULL);

		printf("%d\n", yPlane[10*width+110]);


		//print time
		double duration_cpu = 0.0;
		printf( "sharpness cpu(inline) Size: %dx%d\n", height, width);
		for (int i = 0; i < 6; i++) {
			duration_cpu = 1000 * ((end_cpu[i]).tv_sec - (start_cpu[i]).tv_sec) + ((end_cpu[i]).tv_usec - (start_cpu[i]).tv_usec)/1000.0;
			if (i == 0)
				printf( "Total: ");
			else if (i == 1)
				printf( "DownScale: ");
			else if (i == 2)
				printf( "UpScale: ");
			else if (i == 3)
				printf( "Sobel+Mean: ");
			else if (i == 4)
				printf( "Error+Sharp_Strength+OverShoot: ");
			else if (i == 5)
				printf( "Sharp_Cut: ");

			printf("%.2f ms\n", duration_cpu);
		}
		printf("\n");
	}
	
#ifdef DEBUG
	//compute in cpu
	for(int i=0;i<height*width;i++)
	{
		yPlane_cpu[i] = yuvfile[i];
	}

	//loop 1: Downsample
	for(int i=0;i<height;i +=4)
	{
		for(int j=0;j<width;j +=4)
		{
			yPlaneDown[(i/4)*quarterWidth+j/4] = (yPlane_cpu[i*width+j] + yPlane_cpu[i*width+j+1] + yPlane_cpu[i*width+j+2] + yPlane_cpu[i*width+j+3]
					+ yPlane_cpu[(i+1)*width+j] + yPlane_cpu[(i+1)*width+j+1] + yPlane_cpu[(i+1)*width+j+2] + yPlane_cpu[(i+1)*width+j+3]
					+ yPlane_cpu[(i+2)*width+j] + yPlane_cpu[(i+2)*width+j+1] + yPlane_cpu[(i+2)*width+j+2] + yPlane_cpu[(i+2)*width+j+3]
					+ yPlane_cpu[(i+3)*width+j] + yPlane_cpu[(i+3)*width+j+1] + yPlane_cpu[(i+3)*width+j+2] + yPlane_cpu[(i+3)*width+j+3] + 8) >> 4;
		}
	}

	//loop 2: Upsample, column 1
	for(int h=0;h<quarterHeight;h++)
	{
		yPlaneCSER[h*4*width+0] = yPlaneDown[h*quarterWidth+0];
	}

	//loop 3: Upsample, column 1
	for(int h=0;h<quarterHeight;h++)
	{
		if (h < quarterHeight - 1)
		{
			yPlaneCSER[(h*4+1)*width+0] = (yPlaneCSER[(h*4)*width+0] * 3 + yPlaneCSER[(h*4+4)*width+0] * 1)/4;
			yPlaneCSER[(h*4+2)*width+0] = (yPlaneCSER[(h*4)*width+0] * 2 + yPlaneCSER[(h*4+4)*width+0] * 2)/4;
			yPlaneCSER[(h*4+3)*width+0] = (yPlaneCSER[(h*4)*width+0] * 1 + yPlaneCSER[(h*4+4)*width+0] * 3)/4;
		}
		else
		{
			yPlaneCSER[(h*4+1)*width+0] = yPlaneCSER[(h*4)*width+0];
		}
	}

	//loop 4: Upsample, column 2 
	for(int h=0;h<height;h++)
	{
		yPlaneCSER[(h)*width+1] = yPlaneCSER[(h)*width+0];
	}

	//loop 5: Upsample, row 1
	for(int w=0;w<quarterWidth;w++)
	{
		yPlaneCSER[0*width+w*4] = yPlaneDown[0*quarterWidth+w];
	}

	//loop 6: Upsample, row 1 
	for(int w=0;w<quarterWidth;w++)
	{
		if(w < quarterWidth - 1)
		{
			yPlaneCSER[(0)*width+w*4+1] = (yPlaneCSER[(0)*width+w*4] * 3 + yPlaneCSER[(0)*width+w*4+4] * 1)/4;
			yPlaneCSER[(0)*width+w*4+2] = (yPlaneCSER[(0)*width+w*4] * 2 + yPlaneCSER[(0)*width+w*4+4] * 2)/4;
			yPlaneCSER[(0)*width+w*4+3] = (yPlaneCSER[(0)*width+w*4] * 1 + yPlaneCSER[(0)*width+w*4+4] * 3)/4;
		}
		else
		{
			yPlaneCSER[(0)*width+w*4+1] = yPlaneCSER[(0)*width+w*4];
		}
	}

	//loop 7: Upsample, row 2
	for(int w=0;w<width;w++)
	{
		yPlaneCSER[1*width+w] = yPlaneCSER[0*width+w];
	}

	//loop 8: Upsample, row - 2
	for(int w=0;w<quarterWidth;w++)
	{
		yPlaneCSER[(height-2)*width+w*4] = yPlaneDown[(quarterHeight-1)*quarterWidth+w];
	}

	//loop 9: Upsample, row - 2
	for(int w=0;w<quarterWidth;w++)
	{
		if(w < quarterWidth -1)
		{
			yPlaneCSER[(height-2)*width+w*4+1] = (yPlaneCSER[(height-2)*width+w*4] * 3 + yPlaneCSER[(height-2)*width+w*4+4] * 1)/4;
			yPlaneCSER[(height-2)*width+w*4+2] = (yPlaneCSER[(height-2)*width+w*4] * 2 + yPlaneCSER[(height-2)*width+w*4+4] * 2)/4;
			yPlaneCSER[(height-2)*width+w*4+3] = (yPlaneCSER[(height-2)*width+w*4] * 1 + yPlaneCSER[(height-2)*width+w*4+4] * 3)/4;
		}
		else
		{
			yPlaneCSER[(height-2)*width+w*4+1] = yPlaneCSER[(height-2)*width+w*4];
		}
	}

	//loop 10: Upsample, row - 1
	for(int w=0;w<width;w++)
	{
		yPlaneCSER[(height-1)*width+w] = yPlaneCSER[(height-2)*width+w];
	}

	//loop 11: Upsample, col - 2
	for(int h=0;h<quarterHeight;h++)
	{
		yPlaneCSER[(h*4)*width+width-2] = yPlaneDown[h*quarterWidth+quarterWidth-1];
	}

	//loop 12: Upsample, col - 2
	for(int h=0;h<quarterHeight;h++)
	{
		if(h < quarterHeight - 1)
		{
			yPlaneCSER[(h*4+1)*width+width-2] = (yPlaneCSER[(h*4)*width+width-2] * 3 + yPlaneCSER[(h*4+4)*width+width-2] * 1)/4;
			yPlaneCSER[(h*4+2)*width+width-2] = (yPlaneCSER[(h*4)*width+width-2] * 2 + yPlaneCSER[(h*4+4)*width+width-2] * 2)/4;
			yPlaneCSER[(h*4+3)*width+width-2] = (yPlaneCSER[(h*4)*width+width-2] * 1 + yPlaneCSER[(h*4+4)*width+width-2] * 3)/4;
		}
		else
		{
			yPlaneCSER[(h*4+1)*width+width-2] = yPlaneCSER[(h*4)*width+width-2];
			yPlaneCSER[(h*4+2)*width+width-2] = yPlaneCSER[(h*4)*width+width-2];
			yPlaneCSER[(h*4+3)*width+width-2] = yPlaneCSER[(h*4)*width+width-2];
		}
	}

	//loop 13: Upsample, col - 1
	for(int h=0;h<height;h++)
	{	
		yPlaneCSER[(h)*width+width-1] = yPlaneCSER[(h)*width+width-2];
	}

	//loop 14: Upsample, main body
	for(int h=0;h<quarterHeight-1;h++)
	{
		for(int w=0;w<quarterWidth-1;w++)
		{
					yPlaneCSER[(h*4+2)*width+w*4+2] = (yPlaneDown[(h)*quarterWidth+w] * 7 + yPlaneDown[(h)*quarterWidth+w+1] * 1) * 7 /8 / 8 + (yPlaneDown[(h+1)*quarterWidth+w] * 7 + yPlaneDown[(h+1)*quarterWidth+w+1] * 1) / 8 / 8;
					yPlaneCSER[(h*4+2)*width+w*4+2+1] = (yPlaneDown[(h)*quarterWidth+w] * 5 + yPlaneDown[(h)*quarterWidth+w+1] * 3) * 7/8 /8 + (yPlaneDown[(h+1)*quarterWidth+w] * 5 + yPlaneDown[(h+1)*quarterWidth+w+1] * 3)/8 /8;
					yPlaneCSER[(h*4+2)*width+w*4+2+2] = (yPlaneDown[(h)*quarterWidth+w] * 3 + yPlaneDown[(h)*quarterWidth+w+1] * 5) * 7/8 /8 + (yPlaneDown[(h+1)*quarterWidth+w] * 3 + yPlaneDown[(h+1)*quarterWidth+w+1] * 5)/8 /8;
					yPlaneCSER[(h*4+2)*width+w*4+2+3] = (yPlaneDown[(h)*quarterWidth+w] * 1 + yPlaneDown[(h)*quarterWidth+w+1] * 7) * 7/8 /8 + (yPlaneDown[(h+1)*quarterWidth+w] * 1 + yPlaneDown[(h+1)*quarterWidth+w+1] * 7)/8 /8;

					yPlaneCSER[(h*4+3)*width+w*4+2  ] = (yPlaneDown[(h)*quarterWidth+w] * 7+ yPlaneDown[(h)*quarterWidth+w+1] * 1)* 5/8 /8 + (yPlaneDown[(h+1)*quarterWidth+w] * 7 + yPlaneDown[(h+1)*quarterWidth+w+1] * 1) * 3/8/8;
					yPlaneCSER[(h*4+3)*width+w*4+2+1] = (yPlaneDown[(h)*quarterWidth+w] * 5+ yPlaneDown[(h)*quarterWidth+w+1] * 3)* 5/8 /8 + (yPlaneDown[(h+1)*quarterWidth+w] * 5 + yPlaneDown[(h+1)*quarterWidth+w+1] * 3) * 3/8/8;
					yPlaneCSER[(h*4+3)*width+w*4+2+2] = (yPlaneDown[(h)*quarterWidth+w] * 3+ yPlaneDown[(h)*quarterWidth+w+1] * 5)* 5/8 /8 + (yPlaneDown[(h+1)*quarterWidth+w] * 3 + yPlaneDown[(h+1)*quarterWidth+w+1] * 5) * 3/8/8;
					yPlaneCSER[(h*4+3)*width+w*4+2+3] = (yPlaneDown[(h)*quarterWidth+w] * 1+ yPlaneDown[(h)*quarterWidth+w+1] * 7)* 5/8 /8 + (yPlaneDown[(h+1)*quarterWidth+w] * 1 + yPlaneDown[(h+1)*quarterWidth+w+1] * 7) * 3/8/8;

					yPlaneCSER[(h*4+4)*width+w*4+2  ] = (yPlaneDown[(h)*quarterWidth+w] * 7 + yPlaneDown[(h)*quarterWidth+w+1] * 1) * 3/8/8 + (yPlaneDown[(h+1)*quarterWidth+w] * 7 + yPlaneDown[(h+1)*quarterWidth+w+1] * 1) * 5/8/8;
					yPlaneCSER[(h*4+4)*width+w*4+2+1] = (yPlaneDown[(h)*quarterWidth+w] * 5 + yPlaneDown[(h)*quarterWidth+w+1] * 3) * 3/8/8 + (yPlaneDown[(h+1)*quarterWidth+w] * 5 + yPlaneDown[(h+1)*quarterWidth+w+1] * 3) * 5/8/8;
					yPlaneCSER[(h*4+4)*width+w*4+2+2] = (yPlaneDown[(h)*quarterWidth+w] * 3 + yPlaneDown[(h)*quarterWidth+w+1] * 5) * 3/8/8 + (yPlaneDown[(h+1)*quarterWidth+w] * 3 + yPlaneDown[(h+1)*quarterWidth+w+1] * 5) * 5/8/8;
					yPlaneCSER[(h*4+4)*width+w*4+2+3] = (yPlaneDown[(h)*quarterWidth+w] * 1 + yPlaneDown[(h)*quarterWidth+w+1] * 7) * 3/8/8 + (yPlaneDown[(h+1)*quarterWidth+w] * 1 + yPlaneDown[(h+1)*quarterWidth+w+1] * 7) * 5/8/8;

					yPlaneCSER[(h*4+5)*width+w*4+2  ] = (yPlaneDown[(h)*quarterWidth+w] * 7 + yPlaneDown[(h)*quarterWidth+w+1] * 1) * 1/8/8 + (yPlaneDown[(h+1)*quarterWidth+w] * 7 + yPlaneDown[(h+1)*quarterWidth+w+1] * 1) * 7/8/8;
					yPlaneCSER[(h*4+5)*width+w*4+2+1] = (yPlaneDown[(h)*quarterWidth+w] * 5 + yPlaneDown[(h)*quarterWidth+w+1] * 3) * 1/8/8 + (yPlaneDown[(h+1)*quarterWidth+w] * 5 + yPlaneDown[(h+1)*quarterWidth+w+1] * 3) * 7/8/8;
					yPlaneCSER[(h*4+5)*width+w*4+2+2] = (yPlaneDown[(h)*quarterWidth+w] * 3 + yPlaneDown[(h)*quarterWidth+w+1] * 5) * 1/8/8 + (yPlaneDown[(h+1)*quarterWidth+w] * 3 + yPlaneDown[(h+1)*quarterWidth+w+1] * 5) * 7/8/8;
					yPlaneCSER[(h*4+5)*width+w*4+2+3] = (yPlaneDown[(h)*quarterWidth+w] * 1 + yPlaneDown[(h)*quarterWidth+w+1] * 7) * 1/8/8 + (yPlaneDown[(h+1)*quarterWidth+w] * 1 + yPlaneDown[(h+1)*quarterWidth+w+1] * 7) * 7/8/8;
		}
	}

	//loop 15: Error
	for(int h=0;h<height;h++)
	{
		for(int w=0;w<width;w++)
		{
			pError[h*width+w]=yPlane_cpu[h*width+w]-yPlaneCSER[h*width+w];
		}		
	}

	//loop 16: Sobel
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			if(y == 0 || y == height - 1 || x == 0 || x==width - 1)
			{
				pEdge[y*width+x] = 0;
			}
			else
			{
				int gx = (yPlane_cpu[(y-1)*width+x+1] + ((int)yPlane_cpu[(y)*width+x+1]<<1) + yPlane_cpu[(y+1)*width+x+1]) - (yPlane_cpu[(y-1)*width+x-1] + ((int)yPlane_cpu[(y)*width+x-1]<<1) + yPlane_cpu[(y+1)*width+x-1]);
				int gy = (yPlane_cpu[(y-1)*width+x-1] + ((int)yPlane_cpu[(y-1)*width+x]<<1) + yPlane_cpu[(y-1)*width+x+1]) - (yPlane_cpu[(y+1)*width+x-1] + ((int)yPlane_cpu[(y+1)*width+x]<<1) + yPlane_cpu[(y+1)*width+x+1]);
				int edgeV=(abs(gx)+abs(gy));
				pEdge[y*width+x] = edgeV;
			}
		}
	}

	//loop 17: Mean
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			sum += pEdge[i*width+j];
		}
	}

	mean=(sum+(height*width)/2)/(height*width);

	double cutoff=oldcutoffCoef*mean;
	double peak=oldpeak;
	double cutoff2=oldcutoff2;

	double order=2;
	double order2=2;
	double low = 1.0;

	float cutoff3=oldcutoff3Coef*mean;
	float order3=2;
	float peak3=1;
	float low3=0.05f;

	//loop 18: Strength
	for(int h=0;h<height;h++)
	{
		for(int w=0;w<width;w++)
		{
			short edge = pEdge[h*width+w];
			double weight=1/(1+pow(edge/cutoff2,2*order2));
			double strength=(peak-low)*(1-1/(1+pow(edge/cutoff,2*order)));
			strength=strength*weight+low;

			pSharpness[h*width+w]=(yPlaneCSER[h*width+w]);
			pSharpness[h*width+w]+=(double)(pError[h*width+w])*strength;
		}
	}

	//loop 19: Overshoot
	for(int h=0;h<height;h++)
	{
		for(int w=0;w<width;w++)
		{
			if(!(h == 0 || h == height - 1 || w == 0 || w == width - 1))
			{
				int enhanced,maxValue,minValue;
				double oscStrength;
				enhanced = pSharpness[h*width+w];

				maxValue = MAX2(MAX2(yPlane_cpu[(h-1)*width+w-1], yPlane_cpu[(h-1)*width+w]), yPlane_cpu[(h-1)*width+w+1]);
				maxValue = MAX2(maxValue, MAX2(MAX2(yPlane_cpu[(h)*width+w-1], yPlane_cpu[(h)*width+w]), yPlane_cpu[(h)*width+w+1]));
				maxValue = MAX2(maxValue, MAX2(MAX2(yPlane_cpu[(h+1)*width+w-1], yPlane_cpu[(h+1)*width+w]), yPlane_cpu[(h+1)*width+w+1]));

				minValue = MIN3(yPlane_cpu[(h-1)*width+w-1], yPlane_cpu[(h-1)*width+w], yPlane_cpu[(h-1)*width+w+1]);
				minValue = MIN2(minValue, MIN3(yPlane_cpu[(h)*width+w-1], yPlane_cpu[(h)*width+w], yPlane_cpu[(h)*width+w+1]));
				minValue = MIN2(minValue, MIN3(yPlane_cpu[(h+1)*width+w-1], yPlane_cpu[(h+1)*width+w], yPlane_cpu[(h+1)*width+w+1]));

				{
					double cutoff2Order=pow(cutoff3,2*order3);
					double edge2Order=pow((double)(pEdge[h*width+w]),(double)2*order3);
					oscStrength=(peak3*cutoff2Order+low3*edge2Order)/(cutoff2Order+edge2Order);
				}	

				if(enhanced>maxValue)
				{
					pSharpness[h*width+w] = MIN2(maxValue + oscStrength * (enhanced - maxValue), 255);
				}
				else if(enhanced<minValue)
				{
					pSharpness[h*width+w] = MAX2(0, minValue - oscStrength * (minValue - enhanced));
				}
				else
				{
					pSharpness[h*width+w] = MIN2(MAX2(enhanced, 0), 255);
				}
			}
		}
	}

	//loop 20
	for(int h =0;h<height;h++)
	{
		for(int w=0;w<width;w++)
		{
			yPlane_cpu[h*width+w] = pSharpness[h*width+w] > 255 ? 255 : pSharpness[h*width+w] < 0 ? 0 : pSharpness[h*width+w]; 
		}
	}

	//compare
	bool error = false;
	for(int h =0;h<height;h++)
	{
		for(int w=0;w<width;w++)
		{
			if(abs(yPlane[h*width+w] - yPlane_cpu[h*width+w]) > 1)
			{
				error = true;
				printf("CPU:%d GPU:%d\n", yPlane_cpu[h*width+w], yPlane[h*width+w]);
			}
		}
	}

	if(error)
		printf("Error\n");
	else
		printf("OK\n");

#endif
	
	free(yPlane);
	free(yPlane_cpu);
	free(yPlaneCSER);
	free(yPlaneDown);
	free(pError);
	free(pSharpness);
	free(pEdge);
	
	return 0;
}
