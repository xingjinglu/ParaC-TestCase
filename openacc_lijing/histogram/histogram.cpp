#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<sys/time.h>
#include<iostream>
#include<fstream>
#define BYTE int
#define Niter 10
struct timeval start_cpu[Niter];
struct timeval end_cpu[Niter];

int main()
{
	int w = 8192;
	int h = 8192;
	BYTE * dstData = (BYTE*) malloc(sizeof(BYTE) * w * h);
	BYTE * dstData_CPU = (BYTE*) malloc(sizeof(BYTE) * w * h);
	double * srcArray = (double*) malloc(sizeof(double) * 256);

	printf("----Hist(%d*%d)----\n", w, h);
	for(int ii = 0 ; ii < Niter ; ii ++)
	{
		srand(0);
		for(int i=0;i<h*w;i++)
		{
			dstData[i]=rand()%256;
		}
		for(int i=0;i<256;i++)
		{
			srcArray[i]=rand()%256;
		}

		double dstHist[256];
		memset(dstHist,0,256 * sizeof(double));

		double dstArray[256];
		memset(dstArray,0,256 * sizeof(double));

		//#pragma acc data copyin(dstData[0:w*h]) copy(dstHist[0:256])
		{
			//#pragma acc parallel loop collapse(2)
			for (int i = 0;i < h;i++)
			{
				for (int j = 0;j < w;j++)
				{
					int k = dstData[i * w + j];
					//#pragma acc atomic update
					dstHist[k]++;
				}
			}
		}

		double m_Bytes = w * h;
		dstArray[0] = dstHist[0];
		for (int i = 1;i < 256;i++)
		{
			dstArray[i] = dstArray[i - 1] + dstHist[i];
		}

		for (int i = 0;i < 256;i++)
		{
			dstArray[i] /= m_Bytes;
		}

		double m_diffA,m_diffB;
		int k = 0;
		BYTE mapPixel[256];
		memset(mapPixel,0,256 * sizeof(BYTE));
		for (int i = 0;i < 256;i++)
		{
			m_diffB = 1;
			for (int j = k; j < 256;j++)
			{
				m_diffA = fabs(dstArray[i] - srcArray[j]);
				if (m_diffA - m_diffB < 1.0E-5)
				{
					m_diffB = m_diffA;
					k = j;
				}
				else
				{
					k = j - 1;
					break;
				}
			}
			if (k == 255)
			{
				for (int l = i;l < 256;l++)
				{
					mapPixel[l] = (BYTE) k;
				}
				break;
			}
			mapPixel[i] = (BYTE) k;
		}

		gettimeofday(&start_cpu[ii], NULL);
#pragma acc data copy(dstData[0:w*h]) copyin(mapPixel[0:256]) 
#pragma cap data copy(dstData[0:w*h]) copyin(mapPixel[0:256]) 
		{
#pragma acc parallel loop 
#pragma cap parallel
#pragma cap map thread([0:1][1:0]) threadblock([0:1][1:0])
#pragma cap loop id(0)
			for (int i = 0;i < h;i++)
			{
#pragma cap loop id(1)
#pragma acc loop 
				for (int j = 0;j < w;j++)
				{
					dstData[i * w + j] = mapPixel[dstData[i * w + j]];
				}
			}
		}
		gettimeofday(&end_cpu[ii], NULL);

		printf("%d\n", dstData[0]);

	}
	for(int i = 0 ; i < Niter ; i ++)
	{
		double duration_cpu = 1000 * ((end_cpu[i]).tv_sec - (start_cpu[i]).tv_sec) + ((end_cpu[i]).tv_usec - (start_cpu[i]).tv_usec)/1000.0;
		printf("Hist exe time OPENACC:\t%f ms\n", duration_cpu);
	}

#ifdef DEBUG
	srand(0);
	for(int i=0;i<h*w;i++)
	{
		dstData_CPU[i]=rand()%256;
	}
	for(int i=0;i<256;i++)
	{
		srcArray[i]=rand()%256;
	}

	double dstHist[256];
	memset(dstHist,0,256 * sizeof(double));

	double dstArray[256];
	memset(dstArray,0,256 * sizeof(double));

	for (int i = 0;i < h;i++)
	{
		for (int j = 0;j < w;j++)
		{
			int k = dstData_CPU[i * w + j];
			//#pragma acc atomic update
			dstHist[k]++;
		}
	}

	double m_Bytes = w * h;
	dstArray[0] = dstHist[0];
	for (int i = 1;i < 256;i++)
	{
		dstArray[i] = dstArray[i - 1] + dstHist[i];
	}

	for (int i = 0;i < 256;i++)
	{
		dstArray[i] /= m_Bytes;
	}

	double m_diffA,m_diffB;
	int k = 0;
	BYTE mapPixel[256];
	memset(mapPixel,0,256 * sizeof(BYTE));
	for (int i = 0;i < 256;i++)
	{
		m_diffB = 1;
		for (int j = k; j < 256;j++)
		{
			m_diffA = fabs(dstArray[i] - srcArray[j]);
			if (m_diffA - m_diffB < 1.0E-5)
			{
				m_diffB = m_diffA;
				k = j;
			}
			else
			{
				k = j - 1;
				break;
			}
		}
		if (k == 255)
		{
			for (int l = i;l < 256;l++)
			{
				mapPixel[l] = (BYTE) k;
			}
			break;
		}
		mapPixel[i] = (BYTE) k;
	}

	for (int i = 0;i < h;i++)
	{
		for (int j = 0;j < w;j++)
		{
			dstData_CPU[i * w + j] = mapPixel[dstData_CPU[i * w + j]];
		}
	}

	bool correct = true;
	for (int i = 0;i < h;i++)
	{
		for (int j = 0;j < w;j++)
		{
			if(dstData_CPU[i * w + j] != dstData[i * w + j])
				correct = false;
		}
	}
	if(correct == false)
		printf("Error\n");
	else
		printf("OK\n");
	
#endif

	return 0;
}
