//sharpness.cpp
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<sys/time.h>
#include<iostream>
#include <smmintrin.h>
#include <xmmintrin.h>
#include <emmintrin.h>

using namespace std;

#define MIN2(a,b)  ((a)<(b) ? (a):(b))
#define MAX2(a,b)  ((a)>(b) ? (a):(b))
#define MAX3(a,b,c)   (MAX2((a),MAX2((b),(c))))
#define MIN3(a,b,c)   (MIN2((a),MIN2((b),(c))))
#define DEF_PADDING 10

struct timeval start_cpu[10];
struct timeval end_cpu[10];

typedef struct MMC_CSE_PARAMETER_PUBLIC
{
	float peak;
	float cutoffCoef;
	float cutoff2;
	float cutoff3Coef;
}MMC_CSE_PARAMETER_PUBLIC;


float GetStrengthX16(short edge,float cutoff,float order,float peak,float low,float order2,float cutoff2)
{
	float weight=1/(1+pow(edge/cutoff2,2*order2));
	float strength=(peak-low)*(1-1/(1+pow(edge/cutoff,2*order)));
	strength=strength*weight+low;
	
	return strength;
}	

float GetOSCX16(short edge,float cutoff,float order,float peak,float low)
{
	float cutoff2Order=pow(cutoff,2*order);
	float edge2Order=pow(float(edge),2*order);
	float osc=(peak*cutoff2Order+low*edge2Order)/(cutoff2Order+edge2Order);
	
	return osc;
}	
void OvershootControlFloatX16(unsigned char *src,short *ySharpen,short *sobelEdge,short meanEdge,int width,int height,MMC_CSE_PARAMETER_PUBLIC *cseParamPublic)
{
	float oscStrength;
	
	float cutoff=cseParamPublic->cutoff3Coef*meanEdge;
	float order=2;
	float peak=1;
	float low=0.05f;
	
	unsigned char *pSrc0,*pSrc1,*pSrc2;
	unsigned char *pic;
	int enhanced,maxValue,minValue;
	float maxValue4[4];
	float minValue4[4];
	int size=width*height;
	unsigned char* cache=(unsigned char*)malloc(size);
	
	pSrc0=src;
	pSrc1=pSrc0+width;
	pSrc2=pSrc1+width;
	
	pic=cache;
	
	short* pySharpen=ySharpen;
	short* pEdge=sobelEdge+width;
	//first row
	gettimeofday(&start_cpu[2], NULL);
	
  for(int w=0;w!=width;w++)
	{
		*pic++=(unsigned char)*pySharpen++;
	}
	
    float cutoff2Order=pow(cutoff,2*order);
    __m128 cutoff2Order_4 = _mm_set_ps (cutoff2Order, cutoff2Order, cutoff2Order, cutoff2Order);
    __m128 cutoff2OrderPeak_4 = _mm_set_ps (cutoff2Order * peak, cutoff2Order * peak, cutoff2Order * peak, cutoff2Order * peak);
    __m128 low_4 = _mm_set_ps (low, low, low, low);

	for(int h=0;h<height-2;h++)
	{

		*pic++=(unsigned char)*pySharpen++;
		pEdge++;
		
		//middle cols
		for(int w=0; w < width - 4; w += 4)
		{
			/*original codes*/
			/*
			oscStrength=GetOSCX16(*pEdge,cutoff,order,peak,low);
            */

			/*Serial code*/
			/*
			float edge2Order=pow(float(*pEdge),2*order);
			oscStrength = (peak*cutoff2Order+low*edge2Order)/(cutoff2Order+edge2Order);
            */
			__m128i pEdge_4i = _mm_loadl_epi64 ((__m128i*)pEdge);

			__m128 const_255_4 = _mm_set_ps (255.0, 255.0, 255.0, 255.0);
			__m128 const_0_4 = _mm_set_ps (0.0, 0.0, 0.0, 0.0);

			__m128 pEdge_4 = _mm_cvtpi16_ps (_mm_movepi64_pi64(pEdge_4i));

			__m128 enhanced_4 = _mm_cvtpi16_ps (_mm_movepi64_pi64(_mm_loadl_epi64 ((__m128i*)pySharpen)));

			__m128 edge2Order_4 = _mm_mul_ps (pEdge_4, pEdge_4);

			__m128i pSrc0_8 = _mm_loadl_epi64 ((__m128i*)pSrc0);
			__m128i pSrc1_8 = _mm_loadl_epi64 ((__m128i*)pSrc1);
	    __m128i pSrc2_8 = _mm_loadl_epi64 ((__m128i*)pSrc2);

			edge2Order_4 = _mm_mul_ps (edge2Order_4, edge2Order_4);

			__m128i maxValue_8 = _mm_max_epu8 (pSrc0_8, _mm_max_epu8 (pSrc1_8, pSrc2_8));

      __m128 oscStrength_4 = _mm_mul_ps (edge2Order_4, low_4);

      __m128i minValue_8 = _mm_min_epu8 (pSrc0_8, _mm_min_epu8 (pSrc1_8, pSrc2_8));

			oscStrength_4 = _mm_add_ps (oscStrength_4, cutoff2OrderPeak_4);

			maxValue_8 = _mm_max_epu8 (_mm_srli_si128 (maxValue_8, 2), _mm_max_epu8 (_mm_srli_si128 (maxValue_8, 1), maxValue_8));
      minValue_8 = _mm_min_epu8 (_mm_srli_si128 (minValue_8, 2), _mm_min_epu8 (_mm_srli_si128 (minValue_8, 1), minValue_8));

			oscStrength_4 = _mm_div_ps (oscStrength_4, _mm_add_ps(cutoff2Order_4, edge2Order_4));

			/*Serial code*/
			/*
			for (int t = 0; t < 4; t++) {
				enhanced=*pySharpen;

				maxValue=MAX2(MAX2(pSrc0[0],pSrc0[1]),pSrc0[2]);
				maxValue=MAX2(maxValue,MAX2(MAX2(pSrc1[0],pSrc1[1]),pSrc1[2]));
				maxValue=MAX2(maxValue,MAX2(MAX2(pSrc2[0],pSrc2[1]),pSrc2[2]));

				minValue=MIN3(pSrc0[0],pSrc0[1],pSrc0[2]);
				minValue=MIN2(minValue,MIN3(pSrc1[0],pSrc1[1],pSrc1[2]));
				minValue=MIN2(minValue,MIN3(pSrc2[0],pSrc2[1],pSrc2[2]));

				if(enhanced>maxValue)
				{
					*pic = MIN2(maxValue + oscStrength_4p[t] * (enhanced-maxValue),255);
				}
				else if(enhanced<minValue)
				{
					*pic = MAX2(0, minValue - (oscStrength_4p[t] * (minValue-enhanced)));
				}
				else
				{
					*pic = MIN2(MAX2(enhanced,0),255);
				}

				pic++;
				pySharpen++;
				pSrc0++;
				pSrc1++;
				pSrc2++;
			}*/

			__m128 maxValue_4 = _mm_cvtepi32_ps (_mm_cvtepu8_epi32 (maxValue_8));
			__m128 minValue_4 = _mm_cvtepi32_ps (_mm_cvtepu8_epi32 (minValue_8));

			__m128 other = _mm_and_ps (_mm_cmpge_ps (enhanced_4, minValue_4), _mm_cmple_ps (enhanced_4, maxValue_4));

			__m128 pic_temp_4 = _mm_add_ps(_mm_mul_ps (_mm_sub_ps (enhanced_4, maxValue_4), oscStrength_4), maxValue_4);
			__m128 pic_temp1_4 = _mm_sub_ps (minValue_4, _mm_mul_ps (_mm_sub_ps (minValue_4, enhanced_4), oscStrength_4));

			pic_temp_4 = _mm_and_ps (pic_temp_4, _mm_cmpgt_ps (enhanced_4, maxValue_4));

			pic_temp1_4 = _mm_and_ps (pic_temp1_4, _mm_cmplt_ps (enhanced_4, minValue_4));

			pic_temp_4 = _mm_or_ps (_mm_or_ps (pic_temp_4, pic_temp1_4), _mm_and_ps (enhanced_4, other));
			pic_temp_4 = _mm_min_ps (_mm_max_ps (pic_temp_4, const_0_4), const_255_4);
			__m128i pic_temp_4i = _mm_cvttps_epi32 (pic_temp_4);

			unsigned char* pic_4p = (unsigned char*)(&pic_temp_4i);
			*pic = pic_4p[0];
			*(pic + 1) = pic_4p[4];
			*(pic + 2) = pic_4p[8];
			*(pic + 3) = pic_4p[12];

			pSrc0 += 4;
			pSrc1 += 4;
			pSrc2 += 4;
			pic += 4;
			pySharpen += 4;
			pEdge += 4;
		}

		for(int w=0;w<2;w++)
		{
			/*Not vectorized. Step doesnt divide the vector size.*/
			enhanced=*pySharpen;
			
			maxValue=MAX2(MAX2(pSrc0[0],pSrc0[1]),pSrc0[2]);
			maxValue=MAX2(maxValue,MAX2(MAX2(pSrc1[0],pSrc1[1]),pSrc1[2]));
			maxValue=MAX2(maxValue,MAX2(MAX2(pSrc2[0],pSrc2[1]),pSrc2[2]));
			
			minValue=MIN3(pSrc0[0],pSrc0[1],pSrc0[2]);
			minValue=MIN2(minValue,MIN3(pSrc1[0],pSrc1[1],pSrc1[2]));
			minValue=MIN2(minValue,MIN3(pSrc2[0],pSrc2[1],pSrc2[2]));
			
			/*original codes*/
			/*
			oscStrength=GetOSCX16(*pEdge,cutoff,order,peak,low);
            */


			float edge2Order=pow(float(*pEdge),2*order);
			oscStrength = (peak*cutoff2Order+low*edge2Order)/(cutoff2Order+edge2Order);


			if(enhanced>maxValue)
			{
				*pic=MIN2(maxValue+oscStrength*(enhanced-maxValue),255);
			}
			else if(enhanced<minValue)
			{
				*pic=MAX2(0,minValue-(oscStrength*(minValue-enhanced)));
			}
			else
			{
				*pic=MIN2(MAX2(enhanced,0),255);
			}
			
			pic++;
			pEdge++;
			pySharpen++;
			pSrc0++;
			pSrc1++;
			pSrc2++;
		}

		pSrc0 +=2;
		pSrc1 +=2;
		pSrc2 +=2;
		

		*pic++=*pySharpen++;
		pEdge++;
	}
	
	short tmp;
	for(int w=0;w<width;w++)
	{
		tmp=*pySharpen++;
		
		*pic++=MAX2(0,MIN2(tmp,255));
	}
	
	for(int i=0;i<size;i++)
	{
		ySharpen[i]=cache[i];
	}
	gettimeofday(&end_cpu[2], NULL);
}



void SobelX16(unsigned char *pSrc,short *pEdge,int width,int height,int stride,int edgeStride)
{
	unsigned char *pSrcL0,*pSrcL1,*pSrcL2/*,*pSrcL*/;
	short *pEdgeL;
	
	int gx,gy;
	int srcPad = stride-width + 2;
	int dstPad = edgeStride - width;
	int edgeV;
	int x, y;
	
	memset(pEdge, 0, width * sizeof(short));//memset(pDst,0,width );
	
	pEdgeL = pEdge + (height-1) * edgeStride;
	
	memset(pEdgeL, 0, width * sizeof(short));//memset(pEdgeL,0,width );
	
	pSrcL0 = pSrc;
	pSrcL1=pSrcL0 + stride;
	pSrcL2=pSrcL1 + stride;
	pEdgeL=pEdge + edgeStride;
	
  gettimeofday(&start_cpu[3], NULL);
	for(y = 0; y < height-2; y++)
	{
		*pEdgeL++ = 0;
		for(x = 0; x < width-2; x++)
		{
			gx=(pSrcL0[2]+((int)pSrcL1[2]<<1) + pSrcL2[2]) - (pSrcL0[0] + ((int)pSrcL1[0]<<1) + pSrcL2[0]);
			gy=(pSrcL0[0]+((int)pSrcL0[1]<<1) + pSrcL0[2]) - (pSrcL2[0] + ((int)pSrcL2[1]<<1) + pSrcL2[2]);
			
			edgeV=(abs(gx)+abs(gy));
			
			*pEdgeL++=edgeV;
			
			pSrcL0++;
			pSrcL1++;
			pSrcL2++;
		}
		
		*pEdgeL++=0;
		
		pSrcL0 +=srcPad;
		pSrcL1 +=srcPad;
		pSrcL2 +=srcPad;
		pEdgeL +=dstPad;
	}
	gettimeofday(&end_cpu[3], NULL);
}


short MeanX16(short *pEdge,int width ,int height)
{
	short mean;
	int sum = 0;
	int size=height*width;
	short* p=pEdge;
	
	for(int i=0;i!=size;i++)
	{
		sum +=*p++;
	}
	
	mean=(sum+size/2)/size;
	
	return mean;
}

void Sharpness(unsigned char** yPlane,unsigned char** yPlaneCSER,short** pError,int width,int height,MMC_CSE_PARAMETER_PUBLIC* cseParamPublic)
{
	short* pEdge=(short*)malloc(width*height*sizeof(short));
	short* pSharpness=(short*)malloc(width*height*sizeof(short));
	
	SobelX16(yPlane[0],pEdge,width,height,width,width);
	
	
	short mean=MeanX16(pEdge,width,height);
	float cutoff=cseParamPublic->cutoffCoef*mean;
	float peak=cseParamPublic->peak;
	float cutoff2=cseParamPublic->cutoff2;
	
	float order=2;
	float order2=2;
	
	float strength=1;
	float weight = 0.0;
	
	gettimeofday(&start_cpu[5], NULL);

	__m128 cutoff2_4 = _mm_set_ps (cutoff2, cutoff2, cutoff2, cutoff2);
	__m128 const1_4 = _mm_set_ps (1.0, 1.0, 1.0, 1.0);
  __m128 cutoff_4 = _mm_set_ps (cutoff, cutoff, cutoff, cutoff);
  __m128 peak_1_4 = _mm_set_ps (peak - 1.0, peak - 1.0, peak - 1.0, peak - 1.0);

  for(int h=0;h<height;h++)
	{
		for(int w=0;w<width;w+=4)
		{
            /* Original
			strength=GetStrengthX16(pEdge[h*width+w],cutoff,order,peak,1.0,order2,cutoff2);
			pSharpness[h*width+w]=yPlaneCSER[h][w]+(float)(pError[h][w])*strength;
            */
		    /*
		     * Serial*/
			/*
			weight = 1 / (1 + (pEdge[h*width+w] / cutoff2) * (pEdge[h*width+w] / cutoff2) * (pEdge[h*width+w] / cutoff2) * (pEdge[h*width+w] / cutoff2));
		    strength = (peak - 1.0) * (1 - 1 / (1 + (pEdge[h*width+w] / cutoff) * (pEdge[h*width+w] / cutoff) * (pEdge[h*width+w] / cutoff) * (pEdge[h*width+w] / cutoff)));
			strength = strength * weight + 1.0;

			pSharpness[h*width+w]=yPlaneCSER[h][w]+(float)(pError[h][w])*strength;
            */
			__m128i pEdge_4i = _mm_loadl_epi64 ((__m128i*)(pEdge + h * width + w));
			__m128 pEdge_4 = _mm_cvtpi16_ps (_mm_movepi64_pi64(pEdge_4i));

			__m128 weight_4 = _mm_div_ps (pEdge_4, cutoff2_4);
			__m128 strength_4 = _mm_div_ps (pEdge_4, cutoff_4);

			__m128i pError_4i = _mm_loadl_epi64 ((__m128i*)(*(pError + h) + w));
			__m128 pError_4 = _mm_cvtpi16_ps (_mm_movepi64_pi64(pError_4i));

			__m128i yPlaneCSER_4i =  _mm_loadl_epi64 ((__m128i*)(*(yPlaneCSER + h) + w));
			__m128 yPlaneCSER_4 = _mm_cvtpu8_ps (_mm_movepi64_pi64(yPlaneCSER_4i));

			weight_4 = _mm_mul_ps (weight_4, weight_4);
			strength_4 = _mm_mul_ps (strength_4, strength_4);
			weight_4 = _mm_mul_ps (weight_4, weight_4);
			strength_4 = _mm_mul_ps (strength_4, strength_4);
			weight_4 = _mm_add_ps (weight_4, const1_4);
			strength_4 = _mm_add_ps (strength_4, const1_4);


			strength_4 = _mm_div_ps (const1_4, strength_4);
			weight_4 = _mm_div_ps (const1_4, weight_4);

			strength_4 = _mm_sub_ps (const1_4, strength_4);
			strength_4 = _mm_mul_ps (peak_1_4, strength_4);
			strength_4 = _mm_mul_ps (strength_4, weight_4);
			strength_4 = _mm_add_ps (strength_4, const1_4);

			__m128 pSharpness_4 = _mm_mul_ps (pError_4, strength_4);

			pSharpness_4 = _mm_add_ps (pSharpness_4, yPlaneCSER_4);
			float* pSharpness_4_p = (float*)(&pSharpness_4);
			pSharpness[h*width+w] = *pSharpness_4_p;
			pSharpness[h*width+w+1] = *(pSharpness_4_p + 1);
			pSharpness[h*width+w+2] = *(pSharpness_4_p + 2);
			pSharpness[h*width+w+3] = *(pSharpness_4_p + 3);
		}
	}
	gettimeofday(&end_cpu[5], NULL);
	

	OvershootControlFloatX16(yPlane[0],pSharpness,pEdge,mean,width,height,cseParamPublic);
	
	gettimeofday(&start_cpu[6], NULL);
	for(int h =0;h<height;h++)
	{
		for(int w=0;w<width;w++)
		{
			if(pSharpness[h*width+w]>255)
			{
				yPlane[h][w]=255;
			}
			else if (pSharpness[h*width+w]<0)
			{
				yPlane[h][w]=0;
			}
			else
				yPlane[h][w]=pSharpness[h*width+w];
		}
	}
	gettimeofday(&end_cpu[6], NULL);
	
	free(pSharpness);
	free(pEdge);
}

int DownScaleNewX16(unsigned char *pImageSrc,int nHeight, int nWidth, unsigned char *pImageDst)
{
	int i=0,j=0;
	
	unsigned char *pSrc1=pImageSrc;
	unsigned char*pSrc2=pSrc1+nWidth;
	unsigned char*pSrc3=pSrc2+nWidth;
	unsigned char*pSrc4=pSrc3+nWidth;
	
	unsigned char *pDst = pImageDst;
	

	gettimeofday(&start_cpu[0], NULL);
        for(i=0;i!=nHeight;i +=4)
	{
		for(j=0;j!=nWidth;j +=4)
		{
			//biliner interpolation
			*pDst=(*pSrc1+*(pSrc1+1)+*(pSrc1+2)+*(pSrc1+3)
			+*pSrc2+*(pSrc2+1)+*(pSrc2+2)+*(pSrc2+3)
			+*pSrc3+*(pSrc3+1)+*(pSrc3+2)+*(pSrc3+3)
			+*pSrc4+*(pSrc4+1)+*(pSrc4+2)+*(pSrc4+3)+8)>>4;
			
			pDst++;
			
			pSrc1 += 4;
			pSrc2 += 4;
			pSrc3 += 4;
			pSrc4 += 4;
		}
		
		pSrc1 += 3*nWidth;
		pSrc2 += 3*nWidth;
		pSrc3 += 3*nWidth;
		pSrc4 += 3*nWidth;
	}
	gettimeofday(&end_cpu[0], NULL);
	
	return 0;
}


int UpScaleNewX16(unsigned char* srcImage,int height,int width ,unsigned char *dstImage)
{
	int h,w;
	int dstWidth=width<<2;
	int dstHeight=height<<2;
	unsigned char* p1=srcImage;
	unsigned char* p2=srcImage+width;
	
	unsigned char* pDst1=dstImage+dstWidth*2+2;
	unsigned char* pDst2=pDst1+dstWidth;
	unsigned char* pDst3=pDst2+dstWidth;
	unsigned char* pDst4=pDst3+dstWidth;
	
	unsigned char* pTmp1=dstImage;
	unsigned char* pTmp2=dstImage+dstWidth-1;
	

	
	gettimeofday(&start_cpu[1], NULL);
        pTmp1=dstImage;

	for(int h=0;h<height;h++)
	{
		*pTmp1=srcImage[h*width];
		pTmp1 +=(dstWidth*4);
	}
	pTmp1=dstImage;
	pTmp2=dstImage+dstWidth*4;
	for(int h=0;h<height-1;h++)
	{
		*(pTmp1+dstWidth)=(*pTmp1)*3/4.0+(*pTmp2)*1/4.0;
		*(pTmp1+2*dstWidth)=(*pTmp1)*2/4.0+(*pTmp2)*2/4.0;
		*(pTmp1+3*dstWidth)=(*pTmp1)*1/4.0+(*pTmp2)*3/4.0;
		
		pTmp1 +=(dstWidth*4);
		pTmp2 +=(dstWidth*4);
	}
	*(pTmp1+dstWidth)=*pTmp1;
	

	pTmp1=dstImage;
	for(int h=0;h<dstHeight;h++)
	{
		*(pTmp1+1)=*pTmp1;
		pTmp1 +=dstWidth;
	}
	

	pTmp1=dstImage;
	for(int w=0;w<width;w++)
	{
		*pTmp1=srcImage[w];
		pTmp1 +=4;
	}
	pTmp1=dstImage;
	pTmp2=dstImage+4;
	for(int w=0;w<width-1;w++)
	{
		*(pTmp1+1)=(*pTmp1)*3/4.0+(*pTmp2)*1/4.0;
		*(pTmp1+2)=(*pTmp1)*2/4.0+(*pTmp2)*2/4.0;
		*(pTmp1+3)=(*pTmp1)*1/4.0+(*pTmp2)*3/4.0;
			
		pTmp1 +=4;
		pTmp2 +=4;
	}
	*(pTmp1+1)=*pTmp1;

	pTmp1=dstImage;
	pTmp2=dstImage+dstWidth;
	for(int w=0;w<dstWidth;w++)
	{
		*pTmp2++=*pTmp1++;
	}
	

	pTmp1=dstImage+(dstHeight-2)*dstWidth;
	for(int w=0;w<width;w++)
	{
		*pTmp1=srcImage[(height-1)*width+w];
		pTmp1+=4;
	}
	pTmp1=dstImage+(dstHeight-2)*dstWidth;
	pTmp2=pTmp1+4;
	for(int w=0;w<width-1;w++)
	{
		*(pTmp1+1)=(*pTmp1)*3/4.0+(*pTmp2)*1/4.0;
		*(pTmp1+2)=(*pTmp1)*2/4.0+(*pTmp2)*2/4.0;
		*(pTmp1+3)=(*pTmp1)*1/4.0+(*pTmp2)*3/4.0;
		
		pTmp1 +=4;
		pTmp2 +=4;
	}
	*(pTmp1+1)=*pTmp1;
	

	pTmp1=dstImage+(dstHeight-2)*dstWidth;
	pTmp2=dstImage+(dstHeight-1)*dstWidth;
	for(int w=0;w<dstWidth;w++)
	{
		*pTmp2++=*pTmp1++;
	}
	

	pTmp1=dstImage+dstWidth-2;
	for(int h=0;h<height;h++)
	{
		*pTmp1=srcImage[h*width+width-1];
		pTmp1 +=(dstWidth*4);
	}
	pTmp1=dstImage+dstWidth-2;
	pTmp2=pTmp1+dstWidth*4;
	for(int h=0;h<height-1;h++)
	{
		*(pTmp1+dstWidth)=(*pTmp1)*3/4.0+(*pTmp2)*1/4.0;
		*(pTmp1+2*dstWidth)=(*pTmp1)*2/4.0+(*pTmp2)*2/4.0;
		*(pTmp1+3*dstWidth)=(*pTmp1)*1/4.0+(*pTmp2)*3/4.0;
		
		pTmp1 +=(dstWidth*4);
		pTmp2 +=(dstWidth*4);
	}
	*(pTmp1+dstWidth)=*pTmp1;
	*(pTmp1+2*dstWidth)=*pTmp1;
	*(pTmp1+3*dstWidth)=*pTmp1;
	

	pTmp1=dstImage+dstWidth-2;
	for(int h=0;h<dstHeight;h++)
	{	
		*(pTmp1+1)=*pTmp1;
		pTmp1 +=dstWidth;
	}
	
    __m128 const_7_8_4 = _mm_set_ps (7/8.0, 7/8.0, 7/8.0, 7/8.0);
    __m128 const_5_8_4 = _mm_set_ps (5/8.0, 5/8.0, 5/8.0, 5/8.0);
    __m128 const_3_8_4 = _mm_set_ps (3/8.0, 3/8.0, 3/8.0, 3/8.0);
	__m128 const_1_8_4 = _mm_set_ps (1/8.0, 1/8.0, 1/8.0, 1/8.0);

	int wLimit = (width - 1) / 3;
	int wEnd = (width - 1) % 3;
    __m128i mask = _mm_set_epi8 (0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);

	for(h=0;h<height-1;h++)
	{
		/*Serial*/
		/*
		for(w=0;w<width-1;w++)
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
		*/

		for (w = 0; w < wLimit; w++) {
			__m128i p1_4i = _mm_cvtepi8_epi32 (_mm_loadl_epi64 ((__m128i*) p1));
      __m128i p2_4i = _mm_cvtepi8_epi32 (_mm_loadl_epi64 ((__m128i*) p2));
			__m128 p1_4 = _mm_cvtepi32_ps (p1_4i);
			__m128 p2_4 = _mm_cvtepi32_ps (p2_4i);
			__m128 p1_r3 = _mm_cvtepi32_ps (_mm_srli_si128 (p1_4i, 4));
			__m128 p2_r3 = _mm_cvtepi32_ps (_mm_srli_si128 (p2_4i, 4));
			__m128 pDstC0l_4 = _mm_add_ps (_mm_mul_ps (p1_4, const_7_8_4), _mm_mul_ps (p1_r3, const_1_8_4));
			__m128 pDstC0r_4 = _mm_add_ps (_mm_mul_ps (p2_4, const_7_8_4), _mm_mul_ps (p2_r3, const_1_8_4));
			__m128 pDstC1l_4 = _mm_add_ps (_mm_mul_ps (p1_4, const_5_8_4), _mm_mul_ps (p1_r3, const_3_8_4));
			__m128 pDstC1r_4 = _mm_add_ps (_mm_mul_ps (p2_4, const_5_8_4), _mm_mul_ps (p2_r3, const_3_8_4));
			__m128 pDstC2l_4 = _mm_add_ps (_mm_mul_ps (p1_4, const_3_8_4), _mm_mul_ps (p1_r3, const_5_8_4));
			__m128 pDstC2r_4 = _mm_add_ps (_mm_mul_ps (p2_4, const_3_8_4), _mm_mul_ps (p2_r3, const_5_8_4));
			__m128 pDstC3l_4 = _mm_add_ps (_mm_mul_ps (p1_4, const_1_8_4), _mm_mul_ps (p1_r3, const_7_8_4));
			__m128 pDstC3r_4 = _mm_add_ps (_mm_mul_ps (p2_4, const_1_8_4), _mm_mul_ps (p2_r3, const_7_8_4));

			__m128i pDstC0R0_4 = _mm_cvttps_epi32 (_mm_add_ps (_mm_mul_ps (pDstC0l_4, const_7_8_4), _mm_mul_ps (pDstC0r_4, const_1_8_4)));
			__m128i pDstC0R1_4 = _mm_cvttps_epi32 (_mm_add_ps (_mm_mul_ps (pDstC0l_4, const_5_8_4), _mm_mul_ps (pDstC0r_4, const_3_8_4)));
			__m128i pDstC0R2_4 = _mm_cvttps_epi32 (_mm_add_ps (_mm_mul_ps (pDstC0l_4, const_3_8_4), _mm_mul_ps (pDstC0r_4, const_5_8_4)));
			__m128i pDstC0R3_4 = _mm_cvttps_epi32 (_mm_add_ps (_mm_mul_ps (pDstC0l_4, const_1_8_4), _mm_mul_ps (pDstC0r_4, const_7_8_4)));

			__m128i pDstC1R0_4 = _mm_cvttps_epi32 (_mm_add_ps (_mm_mul_ps (pDstC1l_4, const_7_8_4), _mm_mul_ps (pDstC1r_4, const_1_8_4)));
			__m128i pDstC1R1_4 = _mm_cvttps_epi32 (_mm_add_ps (_mm_mul_ps (pDstC1l_4, const_5_8_4), _mm_mul_ps (pDstC1r_4, const_3_8_4)));
			__m128i pDstC1R2_4 = _mm_cvttps_epi32 (_mm_add_ps (_mm_mul_ps (pDstC1l_4, const_3_8_4), _mm_mul_ps (pDstC1r_4, const_5_8_4)));
			__m128i pDstC1R3_4 = _mm_cvttps_epi32 (_mm_add_ps (_mm_mul_ps (pDstC1l_4, const_1_8_4), _mm_mul_ps (pDstC1r_4, const_7_8_4)));

			__m128i pDstC2R0_4 = _mm_cvttps_epi32 (_mm_add_ps (_mm_mul_ps (pDstC2l_4, const_7_8_4), _mm_mul_ps (pDstC2r_4, const_1_8_4)));
			__m128i pDstC2R1_4 = _mm_cvttps_epi32 (_mm_add_ps (_mm_mul_ps (pDstC2l_4, const_5_8_4), _mm_mul_ps (pDstC2r_4, const_3_8_4)));
			__m128i pDstC2R2_4 = _mm_cvttps_epi32 (_mm_add_ps (_mm_mul_ps (pDstC2l_4, const_3_8_4), _mm_mul_ps (pDstC2r_4, const_5_8_4)));
			__m128i pDstC2R3_4 = _mm_cvttps_epi32 (_mm_add_ps (_mm_mul_ps (pDstC2l_4, const_1_8_4), _mm_mul_ps (pDstC2r_4, const_7_8_4)));

			__m128i pDstC3R0_4 = _mm_cvttps_epi32 (_mm_add_ps (_mm_mul_ps (pDstC3l_4, const_7_8_4), _mm_mul_ps (pDstC3r_4, const_1_8_4)));
			__m128i pDstC3R1_4 = _mm_cvttps_epi32 (_mm_add_ps (_mm_mul_ps (pDstC3l_4, const_5_8_4), _mm_mul_ps (pDstC3r_4, const_3_8_4)));
			__m128i pDstC3R2_4 = _mm_cvttps_epi32 (_mm_add_ps (_mm_mul_ps (pDstC3l_4, const_3_8_4), _mm_mul_ps (pDstC3r_4, const_5_8_4)));
			__m128i pDstC3R3_4 = _mm_cvttps_epi32 (_mm_add_ps (_mm_mul_ps (pDstC3l_4, const_1_8_4), _mm_mul_ps (pDstC3r_4, const_7_8_4)));

			__m128i pDstR0_4 = _mm_or_si128 (pDstC0R0_4, _mm_or_si128 (_mm_slli_si128 (pDstC1R0_4, 1), _mm_or_si128 (_mm_slli_si128 (pDstC2R0_4, 2), _mm_slli_si128 (pDstC3R0_4, 3))));
			__m128i pDstR1_4 = _mm_or_si128 (pDstC0R1_4, _mm_or_si128 (_mm_slli_si128 (pDstC1R1_4, 1), _mm_or_si128 (_mm_slli_si128 (pDstC2R1_4, 2), _mm_slli_si128 (pDstC3R1_4, 3))));
			__m128i pDstR2_4 = _mm_or_si128 (pDstC0R2_4, _mm_or_si128 (_mm_slli_si128 (pDstC1R2_4, 1), _mm_or_si128 (_mm_slli_si128 (pDstC2R2_4, 2), _mm_slli_si128 (pDstC3R2_4, 3))));
			__m128i pDstR3_4 = _mm_or_si128 (pDstC0R3_4, _mm_or_si128 (_mm_slli_si128 (pDstC1R3_4, 1), _mm_or_si128 (_mm_slli_si128 (pDstC2R3_4, 2), _mm_slli_si128 (pDstC3R3_4, 3))));

			_mm_maskmoveu_si128 (pDstR0_4, mask, (char*)pDst1);
			_mm_maskmoveu_si128 (pDstR1_4, mask, (char*)pDst2);
			_mm_maskmoveu_si128 (pDstR2_4, mask, (char*)pDst3);
			_mm_maskmoveu_si128 (pDstR3_4, mask, (char*)pDst4);

			p1 += 3;
			p2 += 3;

			pDst1 += 12;
			pDst2 += 12;
			pDst3 += 12;
			pDst4 += 12;
		}

		for (w = 0; w < wEnd; w++)
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

	gettimeofday(&end_cpu[1], NULL);
	return 0;
}



static void dump_to_file(const char *file_name, unsigned char *buffer,size_t count)
{
	FILE *fp=NULL;
	unsigned char *pos=buffer;
	size_t had_wirte=0;
	
	fp=fopen(file_name,"wb");
	if(fp==NULL)
	{
		return;
	}
	while(had_wirte !=count)
	{
		had_wirte +=fwrite(pos+had_wirte,1,(count-had_wirte),fp);
	}
	fclose(fp);
}

unsigned char *load_image(char *filename,unsigned char *buf ,size_t file_size)
{
	FILE *fp=NULL;
	size_t had_read=0;
	
	fp=fopen(filename,"rb");
	if(fp==NULL)
	{
		printf("Open Error!!\n");
		return NULL;
	}
	if(buf==NULL)
	{
		printf("malloc failed!");
		return NULL;
	}
	memset(buf,0,file_size);
	
	while(had_read!=file_size)
	{
		if(feof(fp))
		{
			break;
		}
		had_read+=fread(buf+had_read,1,(file_size-had_read),fp);
	}
	
	fclose(fp);
	return buf;
}

/*Allocate a matrix. Return the row address array of the matrix*/
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
	if(p!=NULL)
	{
		free(p[0]);
		free(p);
		p=NULL;
	}
}

void usage()
{
	printf("usage:sharpness width height\n");
}

int main(int argc,char* argv[])
{
	int width=0,height=0;
	unsigned long start,end;
	//char *yuvfile=NULL;
	char output_file[128] = "output_simd";
	MMC_CSE_PARAMETER_PUBLIC cseParamPublic;
	if(3 !=argc)
	{
		usage();
		return -1;
	}
	//yuvfile =argv[1];
	width=atoi(argv[1]);
	height=atoi(argv[2]);

	unsigned char *yuvfile=(unsigned char*)malloc(sizeof(unsigned char)*width*height);
	memset(yuvfile,0,width*height*sizeof(char));
	unsigned char *p, *q;
	p=yuvfile;
	for(int i=0;i<height*width;i++)
	{
		 *p++=rand()%100+1;
	}
        	
	int  quarterWidth=width/4;
	int quarterHeight=height/4;
	
	cseParamPublic.cutoff2=256.0f;
	cseParamPublic.cutoff3Coef=1.0f;
	cseParamPublic.cutoffCoef=1.0f;
	cseParamPublic.peak=2.0f;
	
	
	unsigned char **yPlane=allocu(height,width);
	unsigned char** yPlaneCSE=allocu(quarterHeight,quarterWidth);
	unsigned char **yPlaneCSER=allocu(height,width);
	unsigned char** yPlaneDown=allocu(quarterHeight,quarterWidth);
	short** pError=allocs(height,width);
	

        //load_image(yuvfile,yPlane[0],width*height);
	p=yuvfile;
        q = yPlane[0];
        for(int i=0;i<height*width;i++)
        {
             *q++ = *p++;
        }
        
	gettimeofday(&start_cpu[7], NULL);

	DownScaleNewX16(yPlane[0],height,width,yPlaneDown[0]);


	UpScaleNewX16(yPlaneDown[0],quarterHeight,quarterWidth,yPlaneCSER[0]);
	
	gettimeofday(&start_cpu[4], NULL);
	for(int h=0;h<height;h++)
	{
		for(int w=0;w<width;w++)
		{
			pError[h][w]=yPlane[h][w]-yPlaneCSER[h][w];
		}		
	}
	
	gettimeofday(&end_cpu[4], NULL);
	
	Sharpness(yPlane,yPlaneCSER,pError,width,height,&cseParamPublic);
	gettimeofday(&end_cpu[7], NULL);

	double duration_cpu = 0.0;
  cout<< "Size: " << height << "x" << width << endl;
	for (int i = 0; i < 8; i++) {
		duration_cpu = 1000 * ((end_cpu[i]).tv_sec - (start_cpu[i]).tv_sec) + ((end_cpu[i]).tv_usec - (start_cpu[i]).tv_usec)/1000.0;
		if (i == 0)
		    cout << "DownScale: ";
		else if (i == 1)
		    cout << "UpScale: ";
		else if (i == 2)
		    cout << "OverShoot: ";
		else if (i == 3)
		    cout << "Sobel: ";
		else if (i == 4)
		    cout << "Error: ";
		else if (i == 5)
				cout << "Sharp_Strength: ";
		else if (i == 6)
				cout << "Sharp_Cut: ";
		else if (i == 7)
				cout << "Total: ";

		printf("%.2f ms\n", duration_cpu);
	}

	

	//memset(output_file,0,sizeof(output_file));
	//strcpy(output_file,yuvfile);
	//strcpy(output_file+strlen(output_file)-4,"_out_cpu.y");
	dump_to_file(output_file,yPlane[0],width*height);
	
	freeu(yPlane);
	freeu(yPlaneCSE);
	freeu(yPlaneCSER);
	freeu(yPlaneDown);
	frees(pError);
	
	return 0;
}
