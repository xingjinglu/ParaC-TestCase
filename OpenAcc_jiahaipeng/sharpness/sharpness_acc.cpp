#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;

#include "openacc.h"

using namespace std;

struct timeval start_cpu[20];
struct timeval end_cpu[20];

#include "openacc.h"

#define MIN2(a,b)  ((a)<(b) ? (a):(b))
#define MAX2(a,b)  ((a)>(b) ? (a):(b))
#define MAX3(a,b,c)   (MAX2((a),MAX2((b),(c))))
#define MIN3(a,b,c)   (MIN2((a),MIN2((b),(c))))
#define DEF_PADDING 0 

typedef struct MMC_CSE_PARAMETER_PUBLIC
{
	float peak;
	float cutoffCoef;
	float cutoff2;
	float cutoff3Coef;
  float low;
}MMC_CSE_PARAMETER_PUBLIC;


inline unsigned char** allocu(int r,int c)
{
	unsigned char *a ,**p;
	int padding=DEF_PADDING;
	a=(unsigned char*)malloc(sizeof(unsigned char)*(r*c+padding));
	if(a==NULL)
		exit(0);
		
		p=(unsigned char**)malloc(sizeof(unsigned char*)*r);
		for(int i=0;i<r;i++)
			p[i]=&a[i*c];
			
			return(p);
}
inline void freeu(unsigned char **p)
{
	if(p!=NULL)
	{
		free(p[0]);
		free(p);
		p=NULL;
	}
}

inline short** allocs(int r,int c ,int padding=DEF_PADDING)
{
	short *a,**p;
	a=(short*)malloc(sizeof(short)*(r*c+padding));
	if(a==NULL)
	{
		printf("allocs() fail,Memory is too huge,fail.\n");
		getchar();
		exit(0);
	}
	
	p=(short**)malloc(sizeof(short*)*r);
	for(int i=0;i<r;i++)
	p[i]=&a[i*c];
	
	return(p);
}

inline void frees(short **p)
{
    /*
	if(p!=NULL)
	{
		free(p[0]);
		free(p);
		p=NULL;
	}
  */
}

void Sharpness_acc(unsigned char** yPlane,unsigned char** yPlaneCSER,int width,int height,MMC_CSE_PARAMETER_PUBLIC* cseParamPublic,unsigned char** dstImage)
{
    short** pEdge=allocs(height,width);
    short** pSharpness=allocs(height,width);

    short mean=0;

    gettimeofday(&start_cpu[9],NULL);

    memset(pEdge[0],0,width*sizeof(short));
    memset(pEdge[height-1],0,width*sizeof(short));
    int edgeV=0;

#pragma acc data copyin(pEdge[0:height][0:width])  
    {
#pragma acc parallel loop present(yPlane, pEdge)
        unsigned char *pSrcL0=yPlane[0],*pSrcL1=yPlane[1],*pSrcL2=yPlane[2];
        short *pEdgeL=pEdge[1];

        for(int y = 0; y < height-2; y++)
        {

            *pEdgeL++ =0;
#pragma acc loop cache(yPlane)
            for(int x = 0; x < width-2; x++)
            {
                int gx=(pSrcL0[2]+((int)pSrcL1[2]<<1) + pSrcL2[2]) - (pSrcL0[0] + ((int)pSrcL1[0]<<1) + pSrcL2[0]);
                int gy=(pSrcL0[0]+((int)pSrcL0[1]<<1) + pSrcL0[2]) - (pSrcL2[0] + ((int)pSrcL2[1]<<1) + pSrcL2[2]);

                edgeV=(abs(gx)+abs(gy));

                *pEdgeL++=edgeV;

                pSrcL0++;
                pSrcL1++;
                pSrcL2++;
            }

            *pEdgeL++=0;

            pSrcL0 +=2;
            pSrcL1 +=2;
            pSrcL2 +=2;
        }


        gettimeofday(&end_cpu[9],NULL);

        gettimeofday(&start_cpu[10],NULL);
        int sum=0;

        int size=width*height;
        short *p=pEdge[0];
#pragma acc parallel loop reduction(+:sum)
        for(int i=0;i<size;i++)
            sum +=*p++;
        mean=(sum+size/2)/size;

        gettimeofday(&end_cpu[10],NULL);
    }

    cseParamPublic->cutoff2=256.0f;
    cseParamPublic->cutoff3Coef=1.0f;
    cseParamPublic->cutoffCoef=1.0f;
    cseParamPublic->peak=2.0f;
    cseParamPublic->low=0.05f;

    float weight,strength;
    float weight_tmp=pow(1/cseParamPublic->cutoff2,4);
    float cutoff=cseParamPublic->cutoffCoef*mean;
    float tmp2=cseParamPublic->peak-1.0f;
    float cutoff2Order=pow(cseParamPublic->cutoff3Coef*mean,4);

    gettimeofday(&start_cpu[11],NULL);

    unsigned char *p0=yPlane[0],*p1=p0,*p2=p0;
    unsigned char b0[3],b1[3],b2[3];
    //#pragma acc parallel loop present(yPlane, yPlaneCSER, dstImage) 
    for(int i=0;i<height;i++)
    {

        if(i!=0)
            p0=yPlane[i-1];
        p1=yPlane[i];
        if(i==height-1)
            p2=yPlane[i];
        else
            p2=yPlane[i+1];

     //   #pragma acc loop cache(yPlane)
        for(int j=0;j<width;j++)
        {

            b0[0]=(i==0 || j==0) ? 0 : *(p0-1);
            b0[1]=(i==0)?0:p0[0];
            b0[2]=(i==0 || j==width-1)?0:p0[1];

            b1[0]=(j==0)?0:*(p1-1);
            b1[1]=p1[0];
            b1[2]=(j==width-1)?0:p1[1];

            b2[0]=(i==height-1 || j==0)?0:*(p2-1);
            b2[1]=(i==height-1)?0:p2[0];
            b2[2]=(i==height-1 || j==width-1)?0:p2[1];

            unsigned char maxValue,minValue;
            maxValue=minValue=yPlane[i][j];

            maxValue=MAX3(b0[0],b0[1],b0[2]);
            maxValue=MAX2(maxValue,MAX3(b1[0],b1[1],b1[2]));
            maxValue=MAX2(maxValue,MAX3(b2[0],b2[1],b2[2]));

            minValue=MIN3(b0[0],b0[1],b0[2]);
            minValue=MIN2(minValue,MIN3(b1[0],b1[1],b1[2]));
            minValue=MIN2(minValue,MIN3(b2[0],b2[1],b2[2]));

            p0++;
            p1++;
            p2++;

            float pError=yPlane[i][j]-yPlaneCSER[i][j];
            float edge2Order=pow(float(pEdge[i][j]),4);
            weight=1/(1+edge2Order*weight_tmp);
            strength=tmp2*(1-1/(1+edge2Order/(pow(cutoff,4))))*weight+1.0f;

            int enhancedF=pError*strength+yPlaneCSER[i][j];
            strength=(0.05f*edge2Order+cutoff2Order)/(cutoff2Order+edge2Order);

            float pSharpness_value=enhancedF>255 ? 255 : (enhancedF<0 ? 0 : enhancedF);

            edge2Order=minValue-strength*(minValue-enhancedF);
            strength=maxValue+strength*(enhancedF-maxValue);
            strength=strength<255 ? strength:255;
            edge2Order=enhancedF<minValue ? (edge2Order>0 ? edge2Order : 0) : pSharpness_value;
            dstImage[i][j]=enhancedF>maxValue ? strength : edge2Order;

        }
    }

    gettimeofday(&end_cpu[11],NULL);

    frees(pSharpness);
    frees(pEdge);
}


void Sharpness(unsigned char** yPlane,unsigned char** yPlaneCSER,int width,int height,MMC_CSE_PARAMETER_PUBLIC* cseParamPublic,unsigned char** dstImage)
{
    short** pEdge=allocs(height,width);
    short** pSharpness=allocs(height,width);

    gettimeofday(&start_cpu[3],NULL);

    short *pEdgeL=pEdge[1];
    memset(pEdge[0],0,width*sizeof(short));
    memset(pEdge[height-1],0,width*sizeof(short));
    int edgeV=0;
    unsigned char *pSrcL0=yPlane[0],*pSrcL1=yPlane[1],*pSrcL2=yPlane[2];
    for(int y = 0; y < height-2; y++)
    {

        *pEdgeL++ =0;
        for(int x = 0; x < width-2; x++)
        {
            int gx=(pSrcL0[2]+((int)pSrcL1[2]<<1) + pSrcL2[2]) - (pSrcL0[0] + ((int)pSrcL1[0]<<1) + pSrcL2[0]);
            int gy=(pSrcL0[0]+((int)pSrcL0[1]<<1) + pSrcL0[2]) - (pSrcL2[0] + ((int)pSrcL2[1]<<1) + pSrcL2[2]);

            edgeV=(abs(gx)+abs(gy));

            *pEdgeL++=edgeV;

            pSrcL0++;
            pSrcL1++;
            pSrcL2++;
        }

        *pEdgeL++=0;

        pSrcL0 +=2;
        pSrcL1 +=2;
        pSrcL2 +=2;
    }


    gettimeofday(&end_cpu[3],NULL);

    gettimeofday(&start_cpu[4],NULL);
    int sum=0;
    short mean=0;

    int size=width*height;
    short *p=pEdge[0];
    for(int i=0;i<size;i++)
        sum +=*p++;
    mean=(sum+size/2)/size;


    gettimeofday(&end_cpu[4],NULL);

    cseParamPublic->cutoff2=256.0f;
    cseParamPublic->cutoff3Coef=1.0f;
    cseParamPublic->cutoffCoef=1.0f;
    cseParamPublic->peak=2.0f;
    cseParamPublic->low=0.05f;

    float weight,strength;
    float weight_tmp=pow(1/cseParamPublic->cutoff2,4);
    float cutoff=cseParamPublic->cutoffCoef*mean;
    float tmp2=cseParamPublic->peak-1.0f;
    float cutoff2Order=pow(cseParamPublic->cutoff3Coef*mean,4);

    gettimeofday(&start_cpu[5],NULL);

    unsigned char *p0=yPlane[0],*p1=p0,*p2=p0;
    unsigned char b0[3],b1[3],b2[3];
    for(int i=0;i<height;i++)
    {

        if(i!=0)
            p0=yPlane[i-1];
        p1=yPlane[i];
        if(i==height-1)
            p2=yPlane[i];
        else
            p2=yPlane[i+1];

        for(int j=0;j<width;j++)
        {

            b0[0]=(i==0 || j==0) ? 0 : *(p0-1);
            b0[1]=(i==0)?0:p0[0];
            b0[2]=(i==0 || j==width-1)?0:p0[1];

            b1[0]=(j==0)?0:*(p1-1);
            b1[1]=p1[0];
            b1[2]=(j==width-1)?0:p1[1];

            b2[0]=(i==height-1 || j==0)?0:*(p2-1);
            b2[1]=(i==height-1)?0:p2[0];
            b2[2]=(i==height-1 || j==width-1)?0:p2[1];

            unsigned char maxValue,minValue;
            maxValue=minValue=yPlane[i][j];

            maxValue=MAX3(b0[0],b0[1],b0[2]);
            maxValue=MAX2(maxValue,MAX3(b1[0],b1[1],b1[2]));
            maxValue=MAX2(maxValue,MAX3(b2[0],b2[1],b2[2]));

            minValue=MIN3(b0[0],b0[1],b0[2]);
            minValue=MIN2(minValue,MIN3(b1[0],b1[1],b1[2]));
            minValue=MIN2(minValue,MIN3(b2[0],b2[1],b2[2]));

            p0++;
            p1++;
            p2++;

            float pError=yPlane[i][j]-yPlaneCSER[i][j];
            float edge2Order=pow(float(pEdge[i][j]),4);
            weight=1/(1+edge2Order*weight_tmp);
            strength=tmp2*(1-1/(1+edge2Order/(pow(cutoff,4))))*weight+1.0f;

            int enhancedF=pError*strength+yPlaneCSER[i][j];
            strength=(0.05f*edge2Order+cutoff2Order)/(cutoff2Order+edge2Order);

            float pSharpness_value=enhancedF>255 ? 255 : (enhancedF<0 ? 0 : enhancedF);

            edge2Order=minValue-strength*(minValue-enhancedF);
            strength=maxValue+strength*(enhancedF-maxValue);
            strength=strength<255 ? strength:255;
            edge2Order=enhancedF<minValue ? (edge2Order>0 ? edge2Order : 0) : pSharpness_value;
            dstImage[i][j]=enhancedF>maxValue ? strength : edge2Order;

        }
    }

    gettimeofday(&end_cpu[5],NULL);

    frees(pSharpness);
    frees(pEdge);
}


int DownScaleNewX16_acc(unsigned char** pImageSrc,int height, int width, unsigned char** pImageDst)
{
#pragma acc parallel loop present(pImageSrc, pImageDst)
    {

        unsigned char *p=pImageSrc[0],*p1=pImageSrc[1],*p2=pImageSrc[2],*p3=pImageSrc[3];
        unsigned char *d=pImageDst[0];

        for(int j=0;j<height;j++)
        {
#pragma acc loop
            for(int i=0;i<width;i++)
            {
                *d=(*(p)+*(p+1)+*(p+2)+*(p+3)+
                        *(p1)+*(p1+1)+*(p1+2)+*(p1+3)+
                        *(p2)+*(p2+1)+*(p2+2)+*(p2+3)+
                        *(p3)+*(p3+1)+*(p3+2)+*(p3+3)+8)>>4;
                d++;
                p+=4;
                p1+=4;
                p2+=4;
                p3+=4;
            }

            p +=3*width*4;
            p1+=3*width*4;
            p2+=3*width*4;
            p3+=3*width*4;

        } 

    }
    return 0;
}

int DownScaleNewX16(unsigned char** pImageSrc,int height, int width, unsigned char** pImageDst)
{
    unsigned char *p=pImageSrc[0],*p1=pImageSrc[1],*p2=pImageSrc[2],*p3=pImageSrc[3];
    unsigned char *d=pImageDst[0];

    for(int j=0;j<height;j++)
    {
        for(int i=0;i<width;i++)
        {
            *d=(*(p)+*(p+1)+*(p+2)+*(p+3)+
                    *(p1)+*(p1+1)+*(p1+2)+*(p1+3)+
                    *(p2)+*(p2+1)+*(p2+2)+*(p2+3)+
                    *(p3)+*(p3+1)+*(p3+2)+*(p3+3)+8)>>4;
            d++;
            p+=4;
            p1+=4;
            p2+=4;
            p3+=4;
        }

        p +=3*width*4;
        p1+=3*width*4;
        p2+=3*width*4;
        p3+=3*width*4;

    } 

    return 0;
}

int UpScaleNewX16_acc(unsigned char** srcImage,int height,int width ,unsigned char** dstImage)
{
    int dstWidth=width<<2;
    int dstHeight=height<<2;

    float temp1 = 0.0f, temp2 = 0.0f;
    unsigned char *p1,*p2, *pDst1, *pDst2, *pDst3, *pDst4;


    #pragma acc parallel loop present(srcImage, dstImage) cache(srcImage)
    {

        p1=srcImage[0];
        p2=srcImage[1];
        pDst1=dstImage[0];
        pDst2=dstImage[1];
        pDst3=dstImage[2];
        pDst4=dstImage[3];

        //column
        for(int h=0;h<height-1;h++)
        {
            *pDst1=*(pDst1+1)=*p1;
            temp1 = (float)(*p1);
            temp1 = temp1*(3/4.0f);
            temp2 = (float)(*p2);
            temp2 = temp2*(1/4.0f);
            *pDst2=*(pDst2+1)=(unsigned char)(temp1+temp2);
            //*pDst3=*(pDst3+1)=*p1*2/4.0+*p2*2/4.0;
            //*pDst4=*(pDst4+1)=*p1*1/4.0+*p2*3/4.0;

            pDst1 +=dstWidth-2;
            pDst2 +=dstWidth-2;
            pDst3 +=dstWidth-2;
            pDst4 +=dstWidth-2;
            p1 +=width-1;
            p2 +=width-1;


            *pDst1=*(pDst1+1)=*p1;
            //*pDst2=*(pDst2+1)=*p1*3/4.0+*p2*1/4.0;
            //*pDst3=*(pDst3+1)=*p1*2/4.0+*p2*2/4.0;
            //*pDst4=*(pDst4+1)=*p1*1/4.0+*p2*3/4.0;


            pDst1 =pDst4+2;
            pDst2 =pDst1+dstWidth;
            pDst3 =pDst2+dstWidth;
            pDst4 =pDst3+dstWidth;
            p1++;
            p2++;
        }
        *pDst1=*(pDst1+1)=*pDst2=*(pDst2+1)=srcImage[height-1][0];
        pDst1=pDst2-2;
        pDst2=pDst3-2;
        pDst3=pDst4-2;
        pDst4=pDst4+dstWidth-2;
        *pDst1=*(pDst1+1)=*pDst2=*(pDst2+1)=*pDst3=*(pDst3+1)=*pDst4=*(pDst4+1)=srcImage[height-1][width-1];
    }

    //row
    p1=srcImage[0];
    p2=p1+1;
    pDst1=dstImage[0];
    pDst2=pDst1+1;
    pDst3=pDst2+1;
    pDst4=pDst3+1;

    //#pragma acc parallel loop present(srcImage, dstImage) cache(srcImage)
    for(int w=0;w<width-1;w++)
    {
        *pDst1=*(pDst1+dstWidth)=*p1;
        *pDst2=*(pDst2+dstWidth)=*p1*3/4.0+*p2*1/4.0;
        *pDst3=*(pDst3+dstWidth)=*p1*2/4.0+*p2*2/4.0;
        *pDst4=*(pDst4+dstWidth)=*p1*1/4.0+*p2*3/4.0;

        pDst1+=4;
        pDst2+=4;
        pDst3+=4;
        pDst4+=4;
        p1++;
        p2++;
    }
    *pDst1=*(pDst1+dstWidth)=*pDst2=*(pDst2+dstWidth)=srcImage[0][width-1];

    pDst1 =dstImage[dstHeight-2];
    pDst2 =pDst1+1;
    pDst3 =pDst2+1;
    pDst4 =pDst3+1;
    p1 =srcImage[height-1];
    p2 =p1+1;

    //#pragma acc parallel loop present(srcImage, dstImage) cache(srcImage)
    for(int w=0;w<width-1;w++)
    {
        *pDst1=*(pDst1+dstWidth)=*p1;
        *pDst2=*(pDst2+dstWidth)=*p1*3/4.0+*p2*1/4.0;
        *pDst3=*(pDst3+dstWidth)=*p1*2/4.0+*p2*2/4.0;
        *pDst4=*(pDst4+dstWidth)=*p1*1/4.0+*p2*3/4.0;


        pDst1 +=4;
        pDst2 +=4;
        pDst3 +=4;
        pDst4 +=4;
        p1++;
        p2++;
    }
    *pDst1=*(pDst1+dstWidth)=*pDst2=*(pDst2+dstWidth)=srcImage[height-1][width-1];


    //body
    pDst1=dstImage[2]+2;
    pDst2=dstImage[3]+2;
    pDst3=dstImage[4]+2;
    pDst4=dstImage[5]+2;
    p1=srcImage[0];
    p2=srcImage[1];

    //#pragma acc parallel loop present(srcImage, dstImage)
    for(int h=0;h<height-1;h++)
    {
        //#pragma acc loop cache(srcImage)
        for(int w=0;w<width-1;w++)
        {
            *pDst1=((*p1)*(7/8.0)+(*(p1+1))*(1/8.0))*(7/8.0)+((*p2)*(7/8.0)+(*(p2+1))*(1/8.0))*(1/8.0);
            *(pDst1+1)=((*p1)*(5/8.0)+(*(p1+1))*(3/8.0))*(7/8.0)+((*p2)*(5/8.0)+(*(p2+1))*(3/8.0))*(1/8.0);
            *(pDst1+2)=((*p1)*(3/8.0)+(*(p1+1))*(5/8.0))*(7/8.0)+((*p2)*(3/8.0)+(*(p2+1))*(5/8.0))*(1/8.0);
            *(pDst1+3)=((*p1)*(1/8.0)+(*(p1+1))*(7/8.0))*(7/8.0)+((*p2)*(1/8.0)+(*(p2+1))*(7/8.0))*(1/8.0);

            *pDst2=((*p1)*(7/8.0)+(*(p1+1))*(1/8.0))*(5/8.0)+((*p2)*(7/8.0)+(*(p2+1))*(1/8.0))*(3/8.0);
            *(pDst2+1)=((*p1)*(5/8.0)+(*(p1+1))*(3/8.0))*(5/8.0)+((*p2)*(5/8.0)+(*(p2+1))*(3/8.0))*(3/8.0);
            *(pDst2+2)=((*p1)*(3/8.0)+(*(p1+1))*(5/8.0))*(5/8.0)+((*p2)*(3/8.0)+(*(p2+1))*(5/8.0))*(3/8.0);
            *(pDst2+3)=((*p1)*(1/8.0)+(*(p1+1))*(7/8.0))*(5/8.0)+((*p2)*(1/8.0)+(*(p2+1))*(7/8.0))*(3/8.0);

            *pDst3=((*p1)*(7/8.0)+(*(p1+1))*(1/8.0))*(3/8.0)+((*p2)*(7/8.0)+(*(p2+1))*(1/8.0))*(5/8.0);
            *(pDst3+1)=((*p1)*(5/8.0)+(*(p1+1))*(3/8.0))*(3/8.0)+((*p2)*(5/8.0)+(*(p2+1))*(3/8.0))*(5/8.0);
            *(pDst3+2)=((*p1)*(3/8.0)+(*(p1+1))*(5/8.0))*(3/8.0)+((*p2)*(3/8.0)+(*(p2+1))*(5/8.0))*(5/8.0);
            *(pDst3+3)=((*p1)*(1/8.0)+(*(p1+1))*(7/8.0))*(3/8.0)+((*p2)*(1/8.0)+(*(p2+1))*(7/8.0))*(5/8.0);

            *pDst4=((*p1)*(7/8.0)+(*(p1+1))*(1/8.0))*(1/8.0)+((*p2)*(7/8.0)+(*(p2+1))*(1/8.0))*(7/8.0);
            *(pDst4+1)=((*p1)*(5/8.0)+(*(p1+1))*(3/8.0))*(1/8.0)+((*p2)*(5/8.0)+(*(p2+1))*(3/8.0))*(7/8.0);
            *(pDst4+2)=((*p1)*(3/8.0)+(*(p1+1))*(5/8.0))*(1/8.0)+((*p2)*(3/8.0)+(*(p2+1))*(5/8.0))*(7/8.0);
            *(pDst4+3)=((*p1)*(1/8.0)+(*(p1+1))*(7/8.0))*(1/8.0)+((*p2)*(1/8.0)+(*(p2+1))*(7/8.0))*(7/8.0);

            p1++;
            p2++;

            pDst1 += 4;
            pDst2 += 4;
            pDst3 += 4;
            pDst4 += 4;
        }
        p1++;
        p2++;

        pDst1 = pDst1 + 3*dstWidth + 4;
        pDst2 = pDst2 + 3*dstWidth + 4;
        pDst3 = pDst3 + 3*dstWidth + 4;
        pDst4 = pDst4 + 3*dstWidth + 4;

    }

    return 0;
}



int UpScaleNewX16(unsigned char** srcImage,int height,int width ,unsigned char** dstImage)
{
    int dstWidth=width<<2;
    int dstHeight=height<<2;

    unsigned char *p1=srcImage[0];
    unsigned char *p2=srcImage[1];
    unsigned char* pDst1=dstImage[0];
    unsigned char* pDst2=dstImage[1];
    unsigned char* pDst3=dstImage[2];
    unsigned char* pDst4=dstImage[3];

    //column
    for(int h=0;h<height-1;h++)
    {
        *pDst1=*(pDst1+1)=*p1;
        *pDst2=*(pDst2+1)=*p1*3/4.0+*p2*1/4.0;
        *pDst3=*(pDst3+1)=*p1*2/4.0+*p2*2/4.0;
        *pDst4=*(pDst4+1)=*p1*1/4.0+*p2*3/4.0;

        pDst1 +=dstWidth-2;
        pDst2 +=dstWidth-2;
        pDst3 +=dstWidth-2;
        pDst4 +=dstWidth-2;
        p1 +=width-1;
        p2 +=width-1;


        *pDst1=*(pDst1+1)=*p1;
        *pDst2=*(pDst2+1)=*p1*3/4.0+*p2*1/4.0;
        *pDst3=*(pDst3+1)=*p1*2/4.0+*p2*2/4.0;
        *pDst4=*(pDst4+1)=*p1*1/4.0+*p2*3/4.0;


        pDst1 =pDst4+2;
        pDst2 =pDst1+dstWidth;
        pDst3 =pDst2+dstWidth;
        pDst4 =pDst3+dstWidth;
        p1++;
        p2++;
    }
    *pDst1=*(pDst1+1)=*pDst2=*(pDst2+1)=srcImage[height-1][0];
    pDst1=pDst2-2;
    pDst2=pDst3-2;
    pDst3=pDst4-2;
    pDst4=pDst4+dstWidth-2;
    *pDst1=*(pDst1+1)=*pDst2=*(pDst2+1)=*pDst3=*(pDst3+1)=*pDst4=*(pDst4+1)=srcImage[height-1][width-1];

    //row
    p1=srcImage[0];
    p2=p1+1;
    pDst1=dstImage[0];
    pDst2=pDst1+1;
    pDst3=pDst2+1;
    pDst4=pDst3+1;
    for(int w=0;w<width-1;w++)
    {
        *pDst1=*(pDst1+dstWidth)=*p1;
        *pDst2=*(pDst2+dstWidth)=*p1*3/4.0+*p2*1/4.0;
        *pDst3=*(pDst3+dstWidth)=*p1*2/4.0+*p2*2/4.0;
        *pDst4=*(pDst4+dstWidth)=*p1*1/4.0+*p2*3/4.0;

        pDst1+=4;
        pDst2+=4;
        pDst3+=4;
        pDst4+=4;
        p1++;
        p2++;
    }
    *pDst1=*(pDst1+dstWidth)=*pDst2=*(pDst2+dstWidth)=srcImage[0][width-1];

    pDst1 =dstImage[dstHeight-2];
    pDst2 =pDst1+1;
    pDst3 =pDst2+1;
    pDst4 =pDst3+1;
    p1 =srcImage[height-1];
    p2 =p1+1;
    for(int w=0;w<width-1;w++)
    {
        *pDst1=*(pDst1+dstWidth)=*p1;
        *pDst2=*(pDst2+dstWidth)=*p1*3/4.0+*p2*1/4.0;
        *pDst3=*(pDst3+dstWidth)=*p1*2/4.0+*p2*2/4.0;
        *pDst4=*(pDst4+dstWidth)=*p1*1/4.0+*p2*3/4.0;


        pDst1 +=4;
        pDst2 +=4;
        pDst3 +=4;
        pDst4 +=4;
        p1++;
        p2++;
    }
    *pDst1=*(pDst1+dstWidth)=*pDst2=*(pDst2+dstWidth)=srcImage[height-1][width-1];


    //body
    pDst1=dstImage[2]+2;
    pDst2=dstImage[3]+2;
    pDst3=dstImage[4]+2;
    pDst4=dstImage[5]+2;
    p1=srcImage[0];
    p2=srcImage[1];
    for(int h=0;h<height-1;h++)
    {
        for(int w=0;w<width-1;w++)
        {
            *pDst1=((*p1)*(7/8.0)+(*(p1+1))*(1/8.0))*(7/8.0)+((*p2)*(7/8.0)+(*(p2+1))*(1/8.0))*(1/8.0);
            *(pDst1+1)=((*p1)*(5/8.0)+(*(p1+1))*(3/8.0))*(7/8.0)+((*p2)*(5/8.0)+(*(p2+1))*(3/8.0))*(1/8.0);
            *(pDst1+2)=((*p1)*(3/8.0)+(*(p1+1))*(5/8.0))*(7/8.0)+((*p2)*(3/8.0)+(*(p2+1))*(5/8.0))*(1/8.0);
            *(pDst1+3)=((*p1)*(1/8.0)+(*(p1+1))*(7/8.0))*(7/8.0)+((*p2)*(1/8.0)+(*(p2+1))*(7/8.0))*(1/8.0);

            *pDst2=((*p1)*(7/8.0)+(*(p1+1))*(1/8.0))*(5/8.0)+((*p2)*(7/8.0)+(*(p2+1))*(1/8.0))*(3/8.0);
            *(pDst2+1)=((*p1)*(5/8.0)+(*(p1+1))*(3/8.0))*(5/8.0)+((*p2)*(5/8.0)+(*(p2+1))*(3/8.0))*(3/8.0);
            *(pDst2+2)=((*p1)*(3/8.0)+(*(p1+1))*(5/8.0))*(5/8.0)+((*p2)*(3/8.0)+(*(p2+1))*(5/8.0))*(3/8.0);
            *(pDst2+3)=((*p1)*(1/8.0)+(*(p1+1))*(7/8.0))*(5/8.0)+((*p2)*(1/8.0)+(*(p2+1))*(7/8.0))*(3/8.0);

            *pDst3=((*p1)*(7/8.0)+(*(p1+1))*(1/8.0))*(3/8.0)+((*p2)*(7/8.0)+(*(p2+1))*(1/8.0))*(5/8.0);
            *(pDst3+1)=((*p1)*(5/8.0)+(*(p1+1))*(3/8.0))*(3/8.0)+((*p2)*(5/8.0)+(*(p2+1))*(3/8.0))*(5/8.0);
            *(pDst3+2)=((*p1)*(3/8.0)+(*(p1+1))*(5/8.0))*(3/8.0)+((*p2)*(3/8.0)+(*(p2+1))*(5/8.0))*(5/8.0);
            *(pDst3+3)=((*p1)*(1/8.0)+(*(p1+1))*(7/8.0))*(3/8.0)+((*p2)*(1/8.0)+(*(p2+1))*(7/8.0))*(5/8.0);

            *pDst4=((*p1)*(7/8.0)+(*(p1+1))*(1/8.0))*(1/8.0)+((*p2)*(7/8.0)+(*(p2+1))*(1/8.0))*(7/8.0);
            *(pDst4+1)=((*p1)*(5/8.0)+(*(p1+1))*(3/8.0))*(1/8.0)+((*p2)*(5/8.0)+(*(p2+1))*(3/8.0))*(7/8.0);
            *(pDst4+2)=((*p1)*(3/8.0)+(*(p1+1))*(5/8.0))*(1/8.0)+((*p2)*(3/8.0)+(*(p2+1))*(5/8.0))*(7/8.0);
            *(pDst4+3)=((*p1)*(1/8.0)+(*(p1+1))*(7/8.0))*(1/8.0)+((*p2)*(1/8.0)+(*(p2+1))*(7/8.0))*(7/8.0);

            p1++;
            p2++;

            pDst1 += 4;
            pDst2 += 4;
            pDst3 += 4;
            pDst4 += 4;
        }
        p1++;
        p2++;

        pDst1 = pDst1 + 3*dstWidth + 4;
        pDst2 = pDst2 + 3*dstWidth + 4;
        pDst3 = pDst3 + 3*dstWidth + 4;
        pDst4 = pDst4 + 3*dstWidth + 4;

    }

    return 0;
}

int main(int argc,char* argv[])
{
    int height=512,width=512;
    double duration_cpu; 

    MMC_CSE_PARAMETER_PUBLIC cseParamPublic;
    int  quarterWidth=width>>2;
    int quarterHeight=height>>2;

    cseParamPublic.cutoff2=256.0f;
    cseParamPublic.cutoff3Coef=1.0f;
    cseParamPublic.cutoffCoef=1.0f;
    cseParamPublic.peak=2.0f;

    unsigned char **yPlane=allocu(height,width);
    unsigned char ** DST=allocu(height,width);
    unsigned char **yPlaneCSER=allocu(height,width);
    unsigned char** yPlaneDown=allocu(quarterHeight,quarterWidth);

    unsigned char ** DST_acc=allocu(height,width);
    unsigned char **yPlaneCSER_acc=allocu(height,width);
    unsigned char** yPlaneDown_acc=allocu(quarterHeight,quarterWidth);

    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++)
            yPlane[i][j]=rand()%100+1;

    DownScaleNewX16(yPlane,quarterHeight,quarterWidth,yPlaneDown);
    UpScaleNewX16(yPlaneDown,quarterHeight,quarterWidth,yPlaneCSER);
    Sharpness(yPlane,yPlaneCSER,width,height,&cseParamPublic,DST);

#pragma acc data copyin(yPlane[0:height][0:width]) copyout(yPlaneDown_acc[0:height/4][0:width/4]) 
    {
        DownScaleNewX16_acc(yPlane,quarterHeight,quarterWidth,yPlaneDown_acc);
    }
#pragma acc data copyin(yPlaneDown_acc[0:height/4][0:width/4]) copyout(yPlaneCSER_acc[0:height][0:width]) 
    {
        UpScaleNewX16_acc(yPlaneDown_acc,quarterHeight,quarterWidth,yPlaneCSER_acc);
    }
#pragma acc data copyin(yPlane[0:height][0:width],yPlaneDown_acc[0:height][0:width]) copyout(DST_acc[0:height][0:width]) 
    {
        Sharpness_acc(yPlane,yPlaneCSER_acc,width,height,&cseParamPublic,DST_acc);
    }

    for(int i=0; i < height; i++) {
        for(int j=0; j < width; j++)
        {
            unsigned char pre  = DST[i][j];
            unsigned char last = DST_acc[i][j];

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
        DownScaleNewX16(yPlane,quarterHeight,quarterWidth,yPlaneDown);
        gettimeofday(&end_cpu[0], NULL);

        gettimeofday(&start_cpu[1], NULL);
        UpScaleNewX16(yPlaneDown,quarterHeight,quarterWidth,yPlaneCSER);
        gettimeofday(&end_cpu[1], NULL);

        gettimeofday(&start_cpu[2], NULL);
        Sharpness(yPlane,yPlaneCSER,width,height,&cseParamPublic,DST);
        gettimeofday(&end_cpu[2], NULL);


        gettimeofday(&start_cpu[6], NULL);
        DownScaleNewX16_acc(yPlane,quarterHeight,quarterWidth,yPlaneDown_acc);
        gettimeofday(&end_cpu[6], NULL);

        gettimeofday(&start_cpu[7], NULL);
        UpScaleNewX16_acc(yPlaneDown_acc,quarterHeight,quarterWidth,yPlaneCSER_acc);
        gettimeofday(&end_cpu[7], NULL);

        gettimeofday(&start_cpu[8], NULL);
        Sharpness_acc(yPlane,yPlaneCSER_acc,width,height,&cseParamPublic,DST_acc);
        gettimeofday(&end_cpu[8], NULL);

        for (int i = 0; i < 12; i++) 
        {
            duration_cpu = 1000 * ((end_cpu[i]).tv_sec - (start_cpu[i]).tv_sec) + ((end_cpu[i]).tv_usec - (start_cpu[i]).tv_usec)/1000.0;
            if (i == 0)
                cout << "down_scale: ";
            else if (i == 1)
                cout << "up_scale: ";
            else if (i == 2)
                cout << "sharpness_total";
            else if (i == 3)
                cout << "soble: ";
            else if (i == 4)
                cout << "mean: ";
            else if (i == 5)
                cout << "sub_sharpnewss: ";
            if (i == 6)
                cout << "down_scale_acc: ";
            else if (i == 7)
                cout << "up_scale_acc: ";
            else if (i == 8)
                cout << "sharpness_total_acc";
            else if (i == 9)
                cout << "soble_acc: ";
            else if (i == 10)
                cout << "mean_acc: ";
            else if (i == 11)
                cout << "sub_sharpnewss_acc: ";
            else if (i == 12)
                cout << "Total: ";
            printf("%.2f ms\n", duration_cpu);

        }    

        cout << std::endl;
    }

    return 0;
}
