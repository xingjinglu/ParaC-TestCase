#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
using namespace std;

#include <x86intrin.h>
#include <pmmintrin.h>
#include <smmintrin.h>
#include <xmmintrin.h>
#include <tmmintrin.h>


#define PRINT_TIME 1
#define CPU 1

struct timeval start_cpu[10];
struct timeval end_cpu[10];


static int PyramidFilterh_simd(unsigned char *pSrc,unsigned char *pDst,int width ,int height)
{
    int h,w;

    __m128i shuffle = _mm_set_epi8(0,0,0,0,0,0,0,0,14,12,10,8,6,4,2,0);
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


        for(w=2;w <= width-2-8; w+=8)
        {
            int addr = h*width+w-2;
            __m128i pre_2  = _mm_loadl_epi64((__m128i *)(pSrc+addr));
            __m128i pre_1  = _mm_loadl_epi64((__m128i *)(pSrc+addr + 1));
            __m128i mid    = _mm_loadl_epi64((__m128i *)(pSrc+addr + 2));
            __m128i last_1 = _mm_loadl_epi64((__m128i *)(pSrc+addr + 3));
            __m128i last_2 = _mm_loadl_epi64((__m128i *)(pSrc+addr + 4));

            pre_2  = _mm_cvtepu8_epi16(pre_2);
            pre_1  = _mm_cvtepu8_epi16(pre_1);
            mid    = _mm_cvtepu8_epi16(mid);
            last_1 = _mm_cvtepu8_epi16(last_1);
            last_2 = _mm_cvtepu8_epi16(last_2);

            __m128i pre_1_data  = _mm_slli_epi16(pre_1, 2);
            __m128i mid_data    = _mm_slli_epi16(mid, 1) + _mm_slli_epi16(mid, 2);
            __m128i last_1_data = _mm_slli_epi16(last_1, 2);

            __m128i p = _mm_set1_epi16(8);

            p = _mm_add_epi16(p, pre_2);
            p = _mm_add_epi16(p, pre_1_data);
            p = _mm_add_epi16(p, mid_data);
            p = _mm_add_epi16(p, last_1_data);
            p = _mm_add_epi16(p, last_2);
            p = _mm_srli_epi16(p, 4);

            __m128i result = _mm_shuffle_epi8(p, shuffle);

            _mm_storel_epi64((__m128i *)(pDst + addr +2), result);
        }

        for(;w<width-2;w++)
        {
            *(pDst+h*width+w) = ((short)pSrc[h*width+w-2] + pSrc[h*width+w-1]*4 + pSrc[h*width+w]*6 + pSrc[h*width+w+1]*4 + pSrc[h*width+w+2] + 8)>>4;
        }
    }

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

}

static void Downsample_simd(unsigned char *pSrc ,unsigned  char *pDst ,int width ,int height)
{
    int h,w;
    int halfWidth = (width +1)>>1;
    int halfHeight = (height +1)>>1;
    h=height;
    for(w=0;w<halfWidth;w++)
    {
        pDst[w]=((short)pSrc[w*2]*2-pSrc[width+w*2]*4-pSrc[2*width+w*2]+pSrc[3*width+w*2]*4
                + (pSrc[width+w*2]*2-pSrc[3*width+w*2])*4
                + pSrc[w*2]*6
                + pSrc[width+w*2]*4
                + pSrc[2*width+w*2] + 8)>>4;

        if(height%2==0)
        {
            pDst[(halfHeight-1)*halfWidth+w]=((short)pSrc[(h-2)*width+w*2]*2-pSrc[(h-4)*width+w*2]
                    + pSrc[(h-1)*width+w*2]*4
                    + pSrc[(h-2)*width+w*2]*6
                    + pSrc[(h-3)*width+w*2]*4
                    + pSrc[(h-4)*width+w*2] + 8)>>4;
        }
        else
        {
            pDst[(halfHeight-1)*halfWidth+w]=((short)pSrc[(h-1)*width+w*2]*2-pSrc[(h-2)*width+w*2]*4-pSrc[(h-3)*width+w*2]+pSrc[(h-4)*width+w*2]*4
                    + (pSrc[(h-2)*width+w*2]*2-pSrc[(h-4)*width+w*2])*4
                    + pSrc[(h-1)*width+w*2]*6
                    + pSrc[(h-2)*width+w*2]*4
                    + pSrc[(h-3)*width+w*2] + 8)>>4;
        }
    }

    __m128i shuffle = _mm_set_epi8(0,0,0,0,0,0,0,0,14,12,10,8,6,4,2,0);
    for(w=0;w<=halfWidth-8; w+=8)
    {
        int addr = w * 2; 
        __m128i pre_2  = _mm_lddqu_si128((__m128i *)(pSrc + addr));  
        __m128i pre_1  = _mm_lddqu_si128((__m128i *)(pSrc + addr + 1 * width));  
        __m128i mid    = _mm_lddqu_si128((__m128i *)(pSrc + addr + 2 * width));  
        __m128i last_1 = _mm_lddqu_si128((__m128i *)(pSrc + addr + 3 * width));  
        __m128i last_2 = _mm_lddqu_si128((__m128i *)(pSrc + addr + 4 * width));  

        pre_2  = _mm_shuffle_epi8(pre_2,  shuffle);
        pre_1  = _mm_shuffle_epi8(pre_1,  shuffle);
        mid    = _mm_shuffle_epi8(mid,    shuffle);
        last_1 = _mm_shuffle_epi8(last_1, shuffle);
        last_2 = _mm_shuffle_epi8(last_2, shuffle);

        pre_2  = _mm_cvtepu8_epi16(pre_2);
        pre_1  = _mm_cvtepu8_epi16(pre_1);
        mid    = _mm_cvtepu8_epi16(mid);
        last_1 = _mm_cvtepu8_epi16(last_1);
        last_2 = _mm_cvtepu8_epi16(last_2);

        for(h=1;h<halfHeight-1; h++)
        {
            __m128i pre_1_data  = _mm_slli_epi16(pre_1, 2);
            __m128i mid_data    = _mm_slli_epi16(mid, 1) + _mm_slli_epi16(mid, 2);
            __m128i last_1_data = _mm_slli_epi16(last_1, 2);

            __m128i p = _mm_set1_epi16(8);

            p = _mm_add_epi16(p, pre_2);
            p = _mm_add_epi16(p, pre_1_data);
            p = _mm_add_epi16(p, mid_data);
            p = _mm_add_epi16(p, last_1_data);
            p = _mm_add_epi16(p, last_2);
            p = _mm_srli_epi16(p, 4);

            __m128i result = _mm_shuffle_epi8(p, shuffle);
            _mm_storel_epi64((__m128i *)(pDst + h*halfWidth + w), result);

            pre_2  = mid;
            pre_1  = last_1;
            mid    = last_2;

            int addr_1 = (h+1)*2; 
            last_1 = _mm_lddqu_si128((__m128i *)(pSrc + addr + (addr_1 + 1) * width));  
            last_2 = _mm_lddqu_si128((__m128i *)(pSrc + addr + (addr_1 + 2) * width));  

            last_1 = _mm_shuffle_epi8(last_1, shuffle);
            last_2 = _mm_shuffle_epi8(last_2, shuffle);

            last_1 = _mm_cvtepu8_epi16(last_1);
            last_2 = _mm_cvtepu8_epi16(last_2);
        }
    }

    for(;w<halfWidth;w++)
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
    int ssize=1024;
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
    unsigned char * FilterDst_simd = new unsigned char[width * height];

    int halfWidth = (width +1)>>1;
    int halfHeight = (height +1)>>1;
    unsigned char * DownsampleDst = new unsigned char[halfWidth * halfHeight];
    unsigned char * DownsampleDst_simd = new unsigned char[halfWidth * halfHeight];


    signed short * LaplacianLayer_CPU = new signed short[width * height];
    signed short * LaplacianLayer_CPU_simd = new signed short[width * height];

    PyramidFilterh(Source, FilterDst, width, height);
    Downsample(FilterDst,DownsampleDst,width,height);
    UpsampleX4_reverse(DownsampleDst,LaplacianLayer_CPU,Source,width, height);


    PyramidFilterh_simd(Source, FilterDst_simd, width, height);
    Downsample_simd(FilterDst_simd,DownsampleDst_simd,width,height);
    UpsampleX4_reverse(DownsampleDst_simd,LaplacianLayer_CPU_simd,Source,width, height);

    for(int i=0; i < height; i++) {
        for(int j=0; j < width; j++)
        {
            signed short pre  = LaplacianLayer_CPU[i*width+j];
            signed short last = LaplacianLayer_CPU_simd[i*width+j];

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
        PyramidFilterh_simd(Source, FilterDst, width, height);
        gettimeofday(&end_cpu[3], NULL);

        gettimeofday(&start_cpu[4], NULL);
        Downsample_simd(FilterDst,DownsampleDst,width,height);
        gettimeofday(&end_cpu[4], NULL);

        for (int i = 0; i < 5; i++) 
        {
            duration_cpu = 1000 * ((end_cpu[i]).tv_sec - (start_cpu[i]).tv_sec) + ((end_cpu[i]).tv_usec - (start_cpu[i]).tv_usec)/1000.0;
            if (i == 0)
                cout << "Row_filter: ";
            else if (i == 1)
                cout << "Column_filter + DownSample: ";
            else if (i == 2)
                cout << "UpSample+Calclaplacian: ";
            else if (i == 3)
                cout << "Row_filter simd: ";
            else if (i == 4)
                cout << "Column_filter+downSample simd: ";
            else if (i == 5)
                cout << "Total: ";
            printf("%.2f ms\n", duration_cpu);

        }    

        cout << std::endl;
    }

    return 0;
}
