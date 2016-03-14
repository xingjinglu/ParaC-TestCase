#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <iostream>
#include <x86intrin.h>
#include <smmintrin.h>
#include <xmmintrin.h>
#include <emmintrin.h>

#define MIN2(a,b)  ((a)<(b) ? (a):(b))
#define MAX2(a,b)  ((a)>(b) ? (a):(b))
#define MAX3(a,b,c)   (MAX2((a),MAX2((b),(c))))
#define MIN3(a,b,c)   (MIN2((a),MIN2((b),(c))))
#define DEF_PADDING 10
//#define TIME_PAR

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
	if(p!=NULL)
	{
		free(p[0]);
		free(p);
		p=NULL;
	}
}

#ifndef TIME_PAR
void Sharpness(unsigned char** yPlane,unsigned char** yPlaneCSER,int width,int height,MMC_CSE_PARAMETER_PUBLIC* cseParamPublic,unsigned char** dstImage)
#endif
#ifdef TIME_PAR
void Sharpness(unsigned char** yPlane,unsigned char** yPlaneCSER,int width,int height,MMC_CSE_PARAMETER_PUBLIC* cseParamPublic,unsigned char** dstImage,double &sumt4,double &sumt5,double &sumt6)
#endif
{
short** pEdge=allocs(height,width);
short** pSharpness=allocs(height,width);
#ifdef TIME_PAR
struct timeval tt11,tt12,tt22,tt21,tt32,tt31;
#endif

#ifdef TIME_PAR
gettimeofday(&tt11,NULL);
#endif
 
  short *pEdgeL=pEdge[1];
  memset(pEdge[0],0,width*sizeof(short));
  memset(pEdge[height-1],0,width*sizeof(short));
  int edgeV=0;
  unsigned char *pSrcL0=yPlane[0],*pSrcL1=yPlane[1],*pSrcL2=yPlane[2];
  for(int y = 0; y < height-2; y++)
	{
		*pEdgeL++ =0;
    int x;
    for(x = 0; x <= width-2-8; x+=8)
		{
        __m128i ps00=_mm_loadl_epi64((__m128i *)(pSrcL0));
        __m128i ps01=_mm_loadl_epi64((__m128i *)(pSrcL0+1)); 
        __m128i ps02=_mm_loadl_epi64((__m128i *)(pSrcL0+2));
        __m128i ps10=_mm_loadl_epi64((__m128i *)(pSrcL1));
        __m128i ps12=_mm_loadl_epi64((__m128i *)(pSrcL1+2));
        __m128i ps20=_mm_loadl_epi64((__m128i *)(pSrcL2)); 
        __m128i ps21=_mm_loadl_epi64((__m128i *)(pSrcL2+1));
        __m128i ps22=_mm_loadl_epi64((__m128i *)(pSrcL2+2));
 
        ps00=_mm_cvtepu8_epi16(ps00);
        ps01=_mm_cvtepu8_epi16(ps01);
        ps02=_mm_cvtepu8_epi16(ps02);
        ps10=_mm_cvtepu8_epi16(ps10);
        ps12=_mm_cvtepu8_epi16(ps12);
        ps20=_mm_cvtepu8_epi16(ps20);
        ps21=_mm_cvtepu8_epi16(ps21);
        ps22=_mm_cvtepu8_epi16(ps22);

        ps01=_mm_slli_epi16(ps01,1);
        ps01=_mm_add_epi16(ps01,ps00);
        ps01=_mm_add_epi16(ps01,ps02);
        ps01=_mm_sub_epi16(ps01,ps20);
        ps21=_mm_slli_epi16(ps21,1);
        ps01=_mm_sub_epi16(ps01,ps21);
        ps01=_mm_abs_epi16(_mm_sub_epi16(ps01,ps22));

        ps12=_mm_slli_epi16(ps12,1);
        ps02=_mm_add_epi16(ps02,ps22);
        ps12=_mm_add_epi16(ps12,ps02);
        ps12=_mm_sub_epi16(ps12,ps00);
        ps10=_mm_slli_epi16(ps10,1);
        ps12=_mm_sub_epi16(ps12,ps10);
        ps12=_mm_abs_epi16(_mm_sub_epi16(ps12,ps20));

        __m128i res=_mm_add_epi16(ps01,ps12);

        _mm_storeu_si128((__m128i *)pEdgeL,res);

        pEdgeL+=8;
        pSrcL0+=8;
		  	pSrcL1+=8;
		  	pSrcL2+=8;
    }

		for(; x < width-2; x++)
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

#ifdef TIME_PAR
  gettimeofday(&tt12,NULL);
#endif

#ifdef TIME_PAR
  gettimeofday(&tt21,NULL);
#endif
  int sum=0;
  short mean=0;

  int size=width*height;
  short *p=pEdge[0];  
  int s;
  for(s=0;s<=size-32;s+=32)
  {
      __m128i val =_mm_loadl_epi64((__m128i *)p);
      __m128i val1=_mm_loadl_epi64((__m128i *)(p+4));
      __m128i val2=_mm_loadl_epi64((__m128i *)(p+8));
      __m128i val3=_mm_loadl_epi64((__m128i *)(p+12));
      __m128i val4=_mm_loadl_epi64((__m128i *)(p+16));
      __m128i val5=_mm_loadl_epi64((__m128i *)(p+20));
      __m128i val6=_mm_loadl_epi64((__m128i *)(p+24));
      __m128i val7=_mm_loadl_epi64((__m128i *)(p+28));

      val =_mm_cvtepi16_epi32(val ); 
      val1=_mm_cvtepi16_epi32(val1);
      val2=_mm_cvtepi16_epi32(val2);
      val3=_mm_cvtepi16_epi32(val3);
      val4=_mm_cvtepi16_epi32(val4);
      val5=_mm_cvtepi16_epi32(val5);
      val6=_mm_cvtepi16_epi32(val6);
      val7=_mm_cvtepi16_epi32(val7);

      val = _mm_add_epi32(val,val1);
      val2= _mm_add_epi32(val2,val3);
      val4= _mm_add_epi32(val4,val5);
      val6= _mm_add_epi32(val6,val7);
      val = _mm_add_epi32(val,val2);
      val4= _mm_add_epi32(val4,val6);
      val = _mm_add_epi32(val,val4);

      val = _mm_hadd_epi32(val,val7);
      val = _mm_hadd_epi32(val,val7);
      sum +=_mm_extract_epi32(val,0);
      p+=32;
  }

  for(;s<size;s++)
      sum +=*p++;
  mean=(sum+size/2)/size;

#ifdef TIME_PAR
  gettimeofday(&tt22,NULL);
#endif

  cseParamPublic->cutoff2=256.0f;
  cseParamPublic->cutoff3Coef=1.0f;
  cseParamPublic->cutoffCoef=1.0f;
  cseParamPublic->peak=2.0f;
  cseParamPublic->low=0.05f;

  float weight_tmp=pow(1/cseParamPublic->cutoff2,4);
  float cutoff=cseParamPublic->cutoffCoef*mean;
  float tmp2=cseParamPublic->peak-1.0f;
  float cutoff2Order=pow(cseParamPublic->cutoff3Coef*mean,4);
#ifdef TIME_PAR
  gettimeofday(&tt31,NULL);
#endif
  unsigned char *p0=yPlane[0],*p1=yPlane[1],*p2=yPlane[2];
  __m128i shuffle=_mm_set_epi8(0,0,0,0,0,0,0,0,0,0,0,5,4,3,2,1);
  __m128i shuffle1 = _mm_set_epi8(0,0,0,0,0,0,0,0,0,0,0,0,12,8,4,0);
  __m128 val1 = _mm_set_ps(1,1,1,1);
  __m128 val05 = _mm_set_ps(0.05,0.05,0.05,0.05);
  __m128 val0 = _mm_set_ps(0,0,0,0);
  __m128 val255 = _mm_set_ps(255,255,255,255);
  __m128 cutoff2Orderv = _mm_set_ps(cutoff2Order,cutoff2Order,cutoff2Order,cutoff2Order);

  float m1=1.0/mean; m1=m1*m1*m1*m1;
  float m2=1.0/256; m2=m2*m2*m2*m2;
  __m128 m1f=_mm_set_ps(m1,m1,m1,m1);
  __m128 m2f=_mm_set_ps(m2,m2,m2,m2);

  for(int i=1;i<=height-1;i++)
  {
      dstImage[i][0]=yPlane[i][0]; 
      int j;
      for(j=1;j<=width-4-1;j+=4)
      {
          __m128i Value = _mm_loadl_epi64((__m128i *)p0);
          __m128i Value1= _mm_loadl_epi64((__m128i *)p1);
          __m128i Value2= _mm_loadl_epi64((__m128i *)p2);

          __m128i maxValue,maxValue1,minValue,minValue1;

          maxValue = _mm_max_epu8(Value,Value1);
          maxValue = _mm_max_epu8(maxValue,Value2);
          maxValue1= _mm_shuffle_epi8(maxValue,shuffle);
          maxValue = _mm_max_epu8(maxValue1,maxValue);
          maxValue1= _mm_shuffle_epi8(maxValue1,shuffle);
          maxValue = _mm_max_epu8(maxValue1,maxValue);

          minValue = _mm_min_epu8(Value,Value1);
          minValue = _mm_min_epu8(minValue,Value2);
          minValue1= _mm_shuffle_epi8(minValue,shuffle);
          minValue = _mm_min_epu8(minValue,minValue1);
          minValue1= _mm_shuffle_epi8(minValue1,shuffle);
          minValue = _mm_min_epu8(minValue,minValue1);
         
          Value = _mm_shuffle_epi8(Value1,shuffle);
          Value = _mm_cvtepu8_epi32(Value);
          maxValue = _mm_cvtepu8_epi32(maxValue);
          minValue = _mm_cvtepu8_epi32(minValue);
         
          __m128 maxvalue = _mm_cvtepi32_ps(maxValue);
          __m128 minvalue = _mm_cvtepi32_ps(minValue);

          __m128i upvalue = _mm_cvtepu8_epi32(_mm_loadl_epi64((__m128i *)(yPlaneCSER[i]+j)));
          
          __m128i pErrorvs = _mm_sub_epi32(Value,upvalue);
          __m128i pEdgevalu = _mm_cvtepi16_epi32(_mm_loadl_epi64((__m128i *)(pEdge[i]+j)));
          __m128 pEdgevalue = _mm_cvtepi32_ps(pEdgevalu);

          __m128 edge2Orderv = _mm_mul_ps(pEdgevalue,pEdgevalue);
          edge2Orderv = _mm_mul_ps(edge2Orderv,edge2Orderv);

          __m128 enhan = _mm_add_ps(val1,_mm_mul_ps(edge2Orderv,m1f));
          __m128 strengthv = _mm_add_ps(val1,_mm_mul_ps(edge2Orderv,m2f));
          strengthv = _mm_div_ps(_mm_sub_ps(enhan,val1),_mm_mul_ps(enhan,strengthv));
          strengthv = _mm_add_ps(val1,strengthv);
         
          __m128 pErrorv = _mm_cvtepi32_ps(pErrorvs);
          __m128 enhancedFv = _mm_mul_ps(pErrorv,strengthv);

          __m128 upval=_mm_cvtepi32_ps(upvalue);
          enhancedFv = _mm_add_ps(upval,enhancedFv);
          __m128i enhancedFvs =_mm_cvttps_epi32(enhancedFv);
          enhancedFv = _mm_cvtepi32_ps(enhancedFvs);

          strengthv = _mm_mul_ps(val05,edge2Orderv);
          edge2Orderv = _mm_add_ps(cutoff2Orderv,edge2Orderv);
          strengthv = _mm_add_ps(strengthv,cutoff2Orderv);
          strengthv =  _mm_div_ps(strengthv,edge2Orderv);

          __m128 pSharpnessv = _mm_min_ps(enhancedFv,val255); 
          pSharpnessv = _mm_max_ps(pSharpnessv,val0);

          edge2Orderv = _mm_sub_ps(minvalue,enhancedFv);
          edge2Orderv = _mm_mul_ps(edge2Orderv,strengthv);
          edge2Orderv = _mm_sub_ps(minvalue,edge2Orderv);

          __m128 cutoffvs = _mm_sub_ps(enhancedFv,maxvalue);
          strengthv = _mm_mul_ps(cutoffvs,strengthv);
          strengthv = _mm_add_ps(maxvalue,strengthv);
         
          strengthv = _mm_min_ps(strengthv,val255);
          edge2Orderv = _mm_max_ps(edge2Orderv,val0);
          cutoffvs = _mm_and_ps(edge2Orderv,_mm_cmpgt_ps(minvalue,enhancedFv));
          edge2Orderv = _mm_and_ps(pSharpnessv,_mm_cmple_ps(minvalue,enhancedFv));
          edge2Orderv = _mm_or_ps(cutoffvs,edge2Orderv);

          enhancedFv = _mm_and_ps(strengthv,_mm_cmpgt_ps(enhancedFv,maxvalue));
          edge2Orderv = _mm_and_ps(edge2Orderv,_mm_cmple_ps(enhancedFv,maxvalue));
          enhancedFv = _mm_or_ps(enhancedFv,edge2Orderv);
          
          __m128i ress = _mm_cvttps_epi32(enhancedFv);
          ress = _mm_shuffle_epi8(ress,shuffle1);
          int result = _mm_extract_epi32(ress,0);
          _mm_stream_si32((int *)(dstImage[i]+j),result);

          p0+=4;
          p1+=4;
          p2+=4;
      }
  
      for(;j<width-1;j++)
      {
          float weight,strength;
          unsigned char maxValue,minValue;
          maxValue=minValue=yPlane[i][j];
          
          maxValue=MAX3(p0[0],p0[1],p0[2]);
          maxValue=MAX2(maxValue,MAX3(p1[0],p1[1],p1[2]));
          maxValue=MAX2(maxValue,MAX3(p2[0],p2[1],p2[2]));

          minValue=MIN3(p0[0],p0[1],p0[2]);
          minValue=MIN2(minValue,MIN3(p1[0],p1[1],p1[2]));
          minValue=MIN2(minValue,MIN3(p2[0],p2[1],p2[2]));
          
          float pError=yPlane[i][j]-yPlaneCSER[i][j];
          float edge2Order=pow(float(pEdge[i][j]),4);
          
          float enhancedFs=edge2Order*m1+1;
          strength = edge2Order*m2+1;
          strength = (enhancedFs -1)/(enhancedFs*strength)+1;

          int enhancedF=pError*strength+yPlaneCSER[i][j];
          strength=(0.05f*edge2Order+cutoff2Order)/(cutoff2Order+edge2Order);

          float pSharpness_value=enhancedF>255 ? 255 : (enhancedF<0 ? 0 : enhancedF);

          edge2Order=minValue-strength*(minValue-enhancedF);
          strength=maxValue+strength*(enhancedF-maxValue);
          strength=strength<255 ? strength:255;
          edge2Order=enhancedF<minValue ? (edge2Order>0 ? edge2Order : 0) : pSharpness_value;
          dstImage[i][j]=enhancedF>maxValue ? strength : edge2Order;

          p0++;
          p1++;
          p2++;
      }
      p0+=2;
      p1+=2;
      p2+=2;
      dstImage[i][width-1]=yPlane[i][width-1];
  }

  for(int i=0;i<height;i=i+height-1)
      for(int j=0;j<width;j++)
          dstImage[i][j]=yPlane[i][j];
 
#ifdef TIME_PAR
  gettimeofday(&tt32,NULL);

  sumt4+=(double)(tt12.tv_usec-tt11.tv_usec)*0.001+(tt12.tv_sec-tt11.tv_sec)*1000;
  sumt5+=(double)(tt22.tv_usec-tt21.tv_usec)*0.001+(tt22.tv_sec-tt21.tv_sec)*1000;
  sumt6+=(double)(tt32.tv_usec-tt31.tv_usec)*0.001+(tt32.tv_sec-tt31.tv_sec)*1000;
#endif
	frees(pSharpness);
	frees(pEdge);
}

int DownScaleNewX16(unsigned char** pImageSrc,int height, int width, unsigned char** pImageDst)
{
  unsigned char *p=pImageSrc[0],*p1=pImageSrc[1],*p2=pImageSrc[2],*p3=pImageSrc[3];
  unsigned char *d=pImageDst[0];
  
  __m128i shuffle=_mm_set_epi8(0,0,0,0,0,0,0,0,0,0,0,0,6,4,2,0);
  __m128i val8=_mm_set_epi16(8,8,8,8,8,8,8,8);

  for(int j=0;j<height;j++)
  {
      int i;
      for(i=0;i<=width-4;i+=4)
      {
          __m128i dst  =_mm_loadl_epi64((__m128i *)(p));
          __m128i dst1 =_mm_loadl_epi64((__m128i *)(p+8));
          __m128i dst2 =_mm_loadl_epi64((__m128i *)(p1));
          __m128i dst3 =_mm_loadl_epi64((__m128i *)(p1+8));
          __m128i dst4 =_mm_loadl_epi64((__m128i *)(p2));
          __m128i dst5 =_mm_loadl_epi64((__m128i *)(p2+8));
          __m128i dst6 =_mm_loadl_epi64((__m128i *)(p3));
          __m128i dst7 =_mm_loadl_epi64((__m128i *)(p3+8));

          dst  =_mm_cvtepu8_epi16(dst);
          dst1 =_mm_cvtepu8_epi16(dst1);
          dst2 =_mm_cvtepu8_epi16(dst2);
          dst3 =_mm_cvtepu8_epi16(dst3);
          dst4 =_mm_cvtepu8_epi16(dst4);
          dst5 =_mm_cvtepu8_epi16(dst5);
          dst6 =_mm_cvtepu8_epi16(dst6);
          dst7 =_mm_cvtepu8_epi16(dst7);

          dst  =_mm_add_epi16(dst,dst2);
          dst  =_mm_add_epi16(dst,dst4);
          dst  =_mm_add_epi16(dst,dst6);
          dst1 =_mm_add_epi16(dst1,dst3);
          dst1 =_mm_add_epi16(dst1,dst5);
          dst1 =_mm_add_epi16(dst1,dst7);

          __m128i res=_mm_hadd_epi16(dst,dst1);
          res=_mm_hadd_epi16(res,dst1);
          res=_mm_add_epi16(res,val8);
          res=_mm_srai_epi16(res,4);
          res=_mm_shuffle_epi8(res,shuffle);
          int result=_mm_extract_epi32(res,0);
          _mm_stream_si32((int *)d,result);
          
          d +=4;
          p +=16;
          p1+=16;
          p2+=16;
          p3+=16;
      }
      
      for(;i<width;i++)
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
  //vector
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
  //vector
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

  __m128 const_7_8_4 = _mm_set_ps (7/8.0, 7/8.0, 7/8.0, 7/8.0);
  __m128 const_5_8_4 = _mm_set_ps (5/8.0, 5/8.0, 5/8.0, 5/8.0);
  __m128 const_3_8_4 = _mm_set_ps (3/8.0, 3/8.0, 3/8.0, 3/8.0);
	__m128 const_1_8_4 = _mm_set_ps (1/8.0, 1/8.0, 1/8.0, 1/8.0);

	int wLimit = (width - 1) / 3;
	int wEnd = (width - 1) % 3;
  __m128i mask = _mm_set_epi8 (0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);

	for(int h=0;h<height-1;h++)
	{
		for (int w = 0; w < wLimit; w++) {
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

		for (int w = 0; w < wEnd; w++)
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
  int height=16,width=16;
  unsigned long start,end;
  
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
	
  for(int i=0;i<height;i++)
      for(int j=0;j<width;j++)
          yPlane[i][j]=rand()%100+1;

#ifdef TIME_PAR
  struct timeval t11,t12,t21,t22,t32,t31,t41,t42;
  double sumt1=0,sumt2=0,sumt3=0,
         avgt1=0,avgt2=0,avgt3=0,avgt4=0,avgt5=0,avgt6=0;
  double sumt4,sumt5,sumt6;
  sumt4=0;
  sumt5=0;
  sumt6=0;
  int testtime=30;
  
  for(int tt=0;tt<testtime;tt++)
  {
  gettimeofday(&t31,NULL);
#endif
  
#ifdef TIME_PAR
  gettimeofday(&t11,NULL);
#endif
	/*下采样*/
	DownScaleNewX16(yPlane,quarterHeight,quarterWidth,yPlaneDown);
#ifdef TIME_PAR
  gettimeofday(&t12,NULL);
#endif
  
#ifdef TIME_PAR
  gettimeofday(&t21,NULL);
#endif
	UpScaleNewX16(yPlaneDown,quarterHeight,quarterWidth,yPlaneCSER);
#ifdef TIME_PAR
  gettimeofday(&t22,NULL);
#endif

#ifndef TIME_PAR
  Sharpness(yPlane,yPlaneCSER,width,height,&cseParamPublic,DST);
#endif

#ifdef TIME_PAR
  Sharpness(yPlane,yPlaneCSER,width,height,&cseParamPublic,DST,sumt4,sumt5,sumt6);

  gettimeofday(&t32,NULL);
  sumt1+=(double)(t12.tv_usec-t11.tv_usec)*0.001+(t12.tv_sec-t11.tv_sec)*1000;
  sumt2+=(double)(t22.tv_usec-t21.tv_usec)*0.001+(t22.tv_sec-t21.tv_sec)*1000;
  sumt3+=(double)(t32.tv_usec-t31.tv_usec)*0.001+(t32.tv_sec-t31.tv_sec)*1000;
 
  }
  avgt1=(double)sumt1/testtime;
  avgt2=(double)sumt2/testtime;
  avgt3=(double)sumt3/testtime;
  avgt4=(double)sumt4/testtime;
  avgt5=(double)sumt5/testtime;
  avgt6=(double)sumt6/testtime;

  printf("%f\n%f\n%f\n%f\n%f\n%f\n",avgt4,avgt5,avgt6,avgt1,avgt2,avgt3);
#endif

#ifndef TIME_PAR
  printf("out: \n");
  for(int i=0;i<height;i++)
  {
      for(int j=0;j<width;j++)
      {
          if(DST[i][j]<10)
              printf("%d   ",DST[i][j]);
          else if (DST[i][j]<100)
              printf("%d  ",DST[i][j]);
          else
              printf("%d ",DST[i][j]);
      }
        printf("\n");
  }
  printf("\n");
#endif 

	freeu(yPlaneCSER);
	freeu(yPlaneDown);
	
	return 0;
}
