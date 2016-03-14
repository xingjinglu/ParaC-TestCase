#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
using namespace std;

#include "openacc.h"


#define PRINT_TIME 1
#define CPU 1

struct timeval start_cpu[10];
struct timeval end_cpu[10];

static int PyramidFilterh_acc(unsigned char  *pSrc,unsigned char *restrict pDst,int width ,int height)
{
    int h,w;

#pragma acc parallel loop present(pSrc, pDst)  
    for(h=0;h<height;h++)
    {
        *(pDst+h*width)=((short)pSrc[h*width]*2-pSrc[h*width+1]*4-pSrc[h*width+2]+pSrc[h*width+3]*4 
                + (pSrc[h*width+1]*2-pSrc[h*width+3])*4 
                + pSrc[h*width]*6 
                + pSrc[h*width+1]*4
                + pSrc[h*width+2] + 8)>>4;
        *(pDst+h*width+1)=((short)pSrc[h*width+1]*2-pSrc[h*width+3] 
                + pSrc[h*width]*4
                + pSrc[h*width+1]*6
                + pSrc[h*width+2]*4
                + pSrc[h*width+3] + 8)>>4;
        *(pDst+(h+1)*width-2)=((short)pSrc[(h+1)*width-4]
                + pSrc[(h+1)*width-3]*4
                + pSrc[(h+1)*width-2]*6
                + pSrc[(h+1)*width-1]*4
                + pSrc[(h+1)*width-2]*2-pSrc[(h+1)*width-4] + 8)>>4;
        *(pDst+(h+1)*width-1)=((short)pSrc[(h+1)*width-3]
                + pSrc[(h+1)*width-2]*4
                + pSrc[(h+1)*width-1]*6
                + (pSrc[(h+1)*width-2]*2-pSrc[(h+1)*width-4])*4
                + pSrc[(h+1)*width-1]*2-pSrc[(h+1)*width-2]*4-pSrc[(h+1)*width-3]+pSrc[(h+1)*width-4]*4 + 8)>>4;

#pragma acc loop cache(pSrc)
        for(w=2;w<width-2;w++)
        {
            *(pDst+h*width+w) = ((short)pSrc[h*width+w-2] + pSrc[h*width+w-1]*4 + pSrc[h*width+w]*6 + pSrc[h*width+w+1]*4 + pSrc[h*width+w+2] + 8)>>4;
        }
    }
    return 0;
}


static int PyramidFilterh(unsigned char *pSrc,unsigned char *pDst,int width ,int height)
{
    int h,w;

    for(h=0;h<height;h++)
    {
        *(pDst+h*width)=((short)pSrc[h*width]*2-pSrc[h*width+1]*4-pSrc[h*width+2]+pSrc[h*width+3]*4 
                + (pSrc[h*width+1]*2-pSrc[h*width+3])*4 
                + pSrc[h*width]*6 
                + pSrc[h*width+1]*4
                + pSrc[h*width+2] + 8)>>4;
        *(pDst+h*width+1)=((short)pSrc[h*width+1]*2-pSrc[h*width+3] 
                + pSrc[h*width]*4
                + pSrc[h*width+1]*6
                + pSrc[h*width+2]*4
                + pSrc[h*width+3] + 8)>>4;
        *(pDst+(h+1)*width-2)=((short)pSrc[(h+1)*width-4]
                + pSrc[(h+1)*width-3]*4
                + pSrc[(h+1)*width-2]*6
                + pSrc[(h+1)*width-1]*4
                + pSrc[(h+1)*width-2]*2-pSrc[(h+1)*width-4] + 8)>>4;
        *(pDst+(h+1)*width-1)=((short)pSrc[(h+1)*width-3]
                + pSrc[(h+1)*width-2]*4
                + pSrc[(h+1)*width-1]*6
                + (pSrc[(h+1)*width-2]*2-pSrc[(h+1)*width-4])*4
                + pSrc[(h+1)*width-1]*2-pSrc[(h+1)*width-2]*4-pSrc[(h+1)*width-3]+pSrc[(h+1)*width-4]*4 + 8)>>4;
        for(w=2;w<width-2;w++)
        {
            *(pDst+h*width+w) = ((short)pSrc[h*width+w-2] + pSrc[h*width+w-1]*4 + pSrc[h*width+w]*6 + pSrc[h*width+w+1]*4 + pSrc[h*width+w+2] + 8)>>4;
        }
    }
    return 0;

}

static void Downsample_acc(unsigned char *pSrc ,unsigned  char *pDst ,int width ,int height)
{
    int h,w;
    int halfWidth = (width +1)>>1;
    int halfHeight = (height +1)>>1;
    h=height;

#pragma acc parallel loop present(pSrc, pDst)  
    for(w=0;w<halfWidth;w++)
    {
        pDst[w]=(pSrc[w*2]*2-pSrc[width+w*2]*4-pSrc[2*width+w*2]+pSrc[3*width+w*2]*4
                + (pSrc[width+w*2]*2-pSrc[3*width+w*2])*4
                + pSrc[w*2]*6
                + pSrc[width+w*2]*4
                + pSrc[2*width+w*2] + 8)>>4;

        if(height%2==0)
        {
            pDst[(halfHeight-1)*halfWidth+w]=(pSrc[(h-2)*width+w*2]*2-pSrc[(h-4)*width+w*2]
                    + pSrc[(h-1)*width+w*2]*4
                    + pSrc[(h-2)*width+w*2]*6
                    + pSrc[(h-3)*width+w*2]*4
                    + pSrc[(h-4)*width+w*2] + 8)>>4;
        }
        else
        {
            pDst[(halfHeight-1)*halfWidth+w]=(pSrc[(h-1)*width+w*2]*2-pSrc[(h-2)*width+w*2]*4-pSrc[(h-3)*width+w*2]+pSrc[(h-4)*width+w*2]*4
                    + (pSrc[(h-2)*width+w*2]*2-pSrc[(h-4)*width+w*2])*4
                    + pSrc[(h-1)*width+w*2]*6
                    + pSrc[(h-2)*width+w*2]*4
                    + pSrc[(h-3)*width+w*2] + 8)>>4;
        }
    }

#pragma acc parallel loop present(pSrc, pDst)  
    for(w=0;w<halfWidth;w++)
#pragma acc loop cache(pSrc)
        for(h=1;h<halfHeight-1;h++)
        {
            pDst[h*halfWidth+w]=((short)pSrc[(h*2-2)*width+w*2] + pSrc[(h*2-1)*width+w*2]*4 + pSrc[h*2*width+w*2]*6 + pSrc[(h*2+1)*width+w*2]*4 + pSrc[(h*2+2)*width+w*2] + 8)>>4;

        }

}

static void Downsample(unsigned char *pSrc ,unsigned  char *pDst ,int width ,int height)
{
    int h,w;
    int halfWidth = (width +1)>>1;
    int halfHeight = (height +1)>>1;
    h=height;
    for(w=0;w<halfWidth;w++)
    {
        pDst[w]=(pSrc[w*2]*2-pSrc[width+w*2]*4-pSrc[2*width+w*2]+pSrc[3*width+w*2]*4
                + (pSrc[width+w*2]*2-pSrc[3*width+w*2])*4
                + pSrc[w*2]*6
                + pSrc[width+w*2]*4
                + pSrc[2*width+w*2] + 8)>>4;

        if(height%2==0)
        {
            pDst[(halfHeight-1)*halfWidth+w]=(pSrc[(h-2)*width+w*2]*2-pSrc[(h-4)*width+w*2]
                    + pSrc[(h-1)*width+w*2]*4
                    + pSrc[(h-2)*width+w*2]*6
                    + pSrc[(h-3)*width+w*2]*4
                    + pSrc[(h-4)*width+w*2] + 8)>>4;
        }
        else
        {
            pDst[(halfHeight-1)*halfWidth+w]=(pSrc[(h-1)*width+w*2]*2-pSrc[(h-2)*width+w*2]*4-pSrc[(h-3)*width+w*2]+pSrc[(h-4)*width+w*2]*4
                    + (pSrc[(h-2)*width+w*2]*2-pSrc[(h-4)*width+w*2])*4
                    + pSrc[(h-1)*width+w*2]*6
                    + pSrc[(h-2)*width+w*2]*4
                    + pSrc[(h-3)*width+w*2] + 8)>>4;
        }
    }

    for(w=0;w<halfWidth;w++)
        for(h=1;h<halfHeight-1;h++)
        {
            pDst[h*halfWidth+w]=((short)pSrc[(h*2-2)*width+w*2] + pSrc[(h*2-1)*width+w*2]*4 + pSrc[h*2*width+w*2]*6 + pSrc[(h*2+1)*width+w*2]*4 + pSrc[(h*2+2)*width+w*2] + 8)>>4;

        }

}

static void UpsampleX4_reverse_acc(unsigned char *pSrc ,signed short*pDst,unsigned char *Source,int width ,int height)
{
    int h,w;
    int halfWidth=(width+1)>>1;
    int halfHeight=(height+1)>>1;
    int wodd=width%2;
    int hodd=height%2;

    //first row
#pragma acc parallel loop present(pSrc,Source, pDst)  
    for(w=0;w<halfWidth-1;w++)
    {
        pDst[w*2]=(signed short)(Source[w*2]-pSrc[w]);
        unsigned char temp = (pSrc[w]+pSrc[w+1]+1)>>1;
        pDst[w*2+1]=(signed short)(Source[w*2+1]-temp);
    }
    if(wodd==0)
    {
        pDst[width-2]=(signed short)(Source[width-2]-pSrc[halfWidth-1]);
        pDst[width-1]=(signed short)(Source[width-1]-pSrc[halfWidth-1]);
    }else
        pDst[width-1]=(signed short)(Source[width-1]-pSrc[halfWidth-1]);

    //last row
    h=halfHeight;
    if(hodd==0)
    {

#pragma acc parallel loop present(pSrc,Source, pDst)  
        for(w=0;w<halfWidth-1;w++)
        {
            pDst[(h*2-1)*width+w*2]=(signed short)(Source[(h*2-1)*width+w*2]-pSrc[(h-1)*halfWidth+w]);
            unsigned char temp = (pSrc[(h-1)*halfWidth+w]+pSrc[(h-1)*halfWidth+w+1]+1)>>1;
            pDst[(h*2-1)*width+w*2+1]=(signed short)(Source[(h*2-1)*width+w*2+1]-temp);
        }
        if(wodd==0)
        {
            pDst[h*2*width-2]=(signed short)(Source[h*2*width-2]-pSrc[h*halfWidth-1]);
            pDst[h*2*width-1]=(signed short)(Source[h*2*width-1]-pSrc[h*halfWidth-1]);
        }else
            pDst[h*2*width-1]=(signed short)(Source[h*2*width-1]-pSrc[h*halfWidth-1]);
    }

    unsigned char temp;
    //body
#pragma acc parallel loop present(pSrc,Source, pDst)  
    for(h=0;h<halfHeight-1;h++)
    {
#pragma acc loop
        for(w=0;w<halfWidth-1;w++)
        {

            temp = ((pSrc[h*halfWidth+w]+pSrc[(h+1)*halfWidth+w]+1)>>1);
            pDst[(h*2+1)*width+w*2]=(signed short)(Source[(h*2+1)*width+w*2]-temp);
            temp =((pSrc[h*halfWidth+w]+pSrc[h*halfWidth+w+1]+pSrc[(h+1)*halfWidth+w]+pSrc[(h+1)*halfWidth+w+1]+2)>>2); 
            pDst[(h*2+1)*width+w*2+1]=(signed short)(Source[(h*2+1)*width+w*2+1]-temp);

            pDst[(h*2+2)*width+w*2]=(signed short)(Source[(h*2+2)*width+w*2]-pSrc[(h+1)*halfWidth+w]);
            temp = ((pSrc[(h+1)*halfWidth+w]+pSrc[(h+1)*halfWidth+w+1]+1)>>1);
            pDst[(h*2+2)*width+w*2+1]=(signed short)(Source[(h*2+2)*width+w*2+1]- temp);
        }

        if(wodd==0)
        {
            temp = ((pSrc[(h+1)*halfWidth-1]+pSrc[(h+2)*halfWidth-1]+1)>>1);
            pDst[(h*2+2)*width-2]=(signed short)(Source[(h*2+2)*width-2]-temp);
            pDst[(h*2+2)*width-1]=(signed short)(Source[(h*2+2)*width-1]-temp);
            pDst[(h*2+3)*width-2]=(signed short)(Source[(h*2+3)*width-2]-pSrc[(h+2)*halfWidth-1]);
            pDst[(h*2+3)*width-1]=(signed short)(Source[(h*2+3)*width-1]-pSrc[(h+2)*halfWidth-1]);
        }else
        {
            temp = ((pSrc[(h+1)*halfWidth-1]+pSrc[(h+2)*halfWidth-1]+1)>>1);
            pDst[(h*2+2)*width-1]=(signed short)(Source[(h*2+2)*width-1]- temp);
            pDst[(h*2+3)*width-1]=(signed short)(Source[(h*2+3)*width-1]-pSrc[(h+2)*halfWidth-1]);
        }
    }
}


static void UpsampleX4_reverse(unsigned char *pSrc ,signed short*pDst,unsigned char *Source,int width ,int height)
{
    int h,w;
    int halfWidth=(width+1)>>1;
    int halfHeight=(height+1)>>1;
    int wodd=width%2;
    int hodd=height%2;

    //first row
    for(w=0;w<halfWidth-1;w++)
    {
        pDst[w*2]=(signed short)(Source[w*2]-pSrc[w]);
        pDst[w*2+1]=(signed short)(Source[w*2+1]-((pSrc[w]+pSrc[w+1]+1)>>1));
    }
    if(wodd==0)
    {
        pDst[width-2]=(signed short)(Source[width-2]-pSrc[halfWidth-1]);
        pDst[width-1]=(signed short)(Source[width-1]-pSrc[halfWidth-1]);
    }else
        pDst[width-1]=(signed short)(Source[width-1]-pSrc[halfWidth-1]);

    //last row
    h=halfHeight;
    if(hodd==0)
    {
        for(w=0;w<halfWidth-1;w++)
        {
            pDst[(h*2-1)*width+w*2]=(signed short)(Source[(h*2-1)*width+w*2]-pSrc[(h-1)*halfWidth+w]);
            pDst[(h*2-1)*width+w*2+1]=(signed short)(Source[(h*2-1)*width+w*2+1]-((pSrc[(h-1)*halfWidth+w]+pSrc[(h-1)*halfWidth+w+1]+1)>>1));
        }
        if(wodd==0)
        {
            pDst[h*2*width-2]=(signed short)(Source[h*2*width-2]-pSrc[h*halfWidth-1]);
            pDst[h*2*width-1]=(signed short)(Source[h*2*width-1]-pSrc[h*halfWidth-1]);
        }else
            pDst[h*2*width-1]=(signed short)(Source[h*2*width-1]-pSrc[h*halfWidth-1]);
    }

    //body
    for(h=0;h<halfHeight-1;h++)
    {
        for(w=0;w<halfWidth-1;w++)
        {
            pDst[(h*2+1)*width+w*2]=(signed short)(Source[(h*2+1)*width+w*2]-((pSrc[h*halfWidth+w]+pSrc[(h+1)*halfWidth+w]+1)>>1));
            pDst[(h*2+1)*width+w*2+1]=(signed short)(Source[(h*2+1)*width+w*2+1]-((pSrc[h*halfWidth+w]+pSrc[h*halfWidth+w+1]+pSrc[(h+1)*halfWidth+w]+pSrc[(h+1)*halfWidth+w+1]+2)>>2));

            pDst[(h*2+2)*width+w*2]=(signed short)(Source[(h*2+2)*width+w*2]-pSrc[(h+1)*halfWidth+w]);
            pDst[(h*2+2)*width+w*2+1]=(signed short)(Source[(h*2+2)*width+w*2+1]-((pSrc[(h+1)*halfWidth+w]+pSrc[(h+1)*halfWidth+w+1]+1)>>1));
        }

        if(wodd==0)
        {
            pDst[(h*2+2)*width-2]=(signed short)(Source[(h*2+2)*width-2]-((pSrc[(h+1)*halfWidth-1]+pSrc[(h+2)*halfWidth-1]+1)>>1));
            pDst[(h*2+2)*width-1]=(signed short)(Source[(h*2+2)*width-1]-((pSrc[(h+1)*halfWidth-1]+pSrc[(h+2)*halfWidth-1]+1)>>1));
            pDst[(h*2+3)*width-2]=(signed short)(Source[(h*2+3)*width-2]-pSrc[(h+2)*halfWidth-1]);
            pDst[(h*2+3)*width-1]=(signed short)(Source[(h*2+3)*width-1]-pSrc[(h+2)*halfWidth-1]);
        }else
        {
            pDst[(h*2+2)*width-1]=(signed short)(Source[(h*2+2)*width-1]-((pSrc[(h+1)*halfWidth-1]+pSrc[(h+2)*halfWidth-1]+1)>>1));
            pDst[(h*2+3)*width-1]=(signed short)(Source[(h*2+3)*width-1]-pSrc[(h+2)*halfWidth-1]);
        }
    }
}

int main(int argc, char** argv)
{   
    int ssize=512;
    int height = ssize;
    int width = ssize;
    unsigned char * Source = new unsigned char[width * height];
    double duration_cpu; 
    for(int i=0; i < height; i++) {
        for(int j=0; j < width; j++)
        {
            *(Source+i*width+j) = rand()%255;
        }
    }

    unsigned char * FilterDst = new unsigned char[width * height];
    unsigned char * FilterDst_acc = new unsigned char[width * height];

    int halfWidth = (width +1)>>1;
    int halfHeight = (height +1)>>1;
    unsigned char * DownsampleDst = new unsigned char[halfWidth * halfHeight];
    unsigned char * DownsampleDst_acc = new unsigned char[halfWidth * halfHeight];


    signed short * LaplacianLayer_CPU = new signed short[width * height];
    signed short * LaplacianLayer_CPU_acc = new signed short[width * height];

    PyramidFilterh(Source, FilterDst, width, height);
    Downsample(FilterDst,DownsampleDst,width,height);
    UpsampleX4_reverse(DownsampleDst,LaplacianLayer_CPU,Source,width, height);



#pragma acc data copyin(Source[0:width*height]) copyout(FilterDst_acc[0:width*height]) 
    {
        PyramidFilterh_acc(Source, FilterDst_acc, width, height);
    }

#pragma acc data copyin(FilterDst_acc[0:width*height]) copyout(DownsampleDst_acc[0:width*height/4]) 
    {
    Downsample_acc(FilterDst_acc,DownsampleDst_acc,width,height);
    }

#pragma acc data copyin(DownsampleDst_acc[0:width*height/4], Source[0:width*height]) copyout(LaplacianLayer_CPU_acc[0:width*height]) 
    {
    UpsampleX4_reverse_acc(DownsampleDst_acc,LaplacianLayer_CPU_acc,Source,width, height);
    }

    for(int i=0; i < height; i++) {
        for(int j=0; j < width; j++)
        {
            signed short pre  = LaplacianLayer_CPU[i*width+j];
            signed short last = LaplacianLayer_CPU_acc[i*width+j];

            if(pre != last)
            {
                std::cout << "i = " << i << "j = " << j << std::endl;
                std::cout << "pre = " << pre << "last = " << last << std::endl;

                abort();
            }
        }
    }

    std::cout << "success" << std::endl;


    for(int j = 0; j < 10; j++)
    {

        gettimeofday(&start_cpu[0], NULL);
        PyramidFilterh(Source, FilterDst, width, height);
        gettimeofday(&end_cpu[0], NULL);

        gettimeofday(&start_cpu[1], NULL);
        Downsample(FilterDst,DownsampleDst,width,height);
        gettimeofday(&end_cpu[1], NULL);

        gettimeofday(&start_cpu[2], NULL);
        UpsampleX4_reverse(DownsampleDst,LaplacianLayer_CPU,Source,width, height);
        gettimeofday(&end_cpu[2], NULL);


        gettimeofday(&start_cpu[3], NULL);
        PyramidFilterh_acc(Source, FilterDst, width, height);
        gettimeofday(&end_cpu[3], NULL);

        gettimeofday(&start_cpu[4], NULL);
        Downsample_acc(FilterDst,DownsampleDst,width,height);
        gettimeofday(&end_cpu[4], NULL);

        gettimeofday(&start_cpu[5], NULL);
        UpsampleX4_reverse_acc(DownsampleDst,LaplacianLayer_CPU,Source,width, height);
        gettimeofday(&end_cpu[5], NULL);

        for (int i = 0; i < 6; i++) 
        {
            duration_cpu = 1000 * ((end_cpu[i]).tv_sec - (start_cpu[i]).tv_sec) + ((end_cpu[i]).tv_usec - (start_cpu[i]).tv_usec)/1000.0;
            if (i == 0)
                cout << "Row_filter: ";
            else if (i == 1)
                cout << "Column_filter + DownSample: ";
            else if (i == 2)
                cout << "UpSample+Calclaplacian: ";
            else if (i == 3)
                cout << "Row_filter acc: ";
            else if (i == 4)
                cout << "Column_filter+downSample acc: ";
            else if (i == 5)
                cout << "UpSample+Calclaplacian acc: ";
            else if (i == 6)
                cout << "Total: ";
            printf("%.2f ms\n", duration_cpu);

        }    

        cout << std::endl;
    }

    return 0;
}
