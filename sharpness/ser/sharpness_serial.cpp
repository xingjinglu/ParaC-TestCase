//sharpness.cpp
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<sys/time.h>
#include<iostream>

using namespace std;

#define MIN2(a,b)  ((a)<(b) ? (a):(b))
#define MAX2(a,b)  ((a)>(b) ? (a):(b))
#define MAX3(a,b,c)   (MAX2((a),MAX2((b),(c))))
#define MIN3(a,b,c)   (MIN2((a),MIN2((b),(c))))
#define DEF_PADDING 10

struct timeval start_cpu[10];
struct timeval end_cpu[10];
double time_prof[10];

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
  int size=width*height;
  unsigned char* cache=(unsigned char*)malloc(size);

  pSrc0=src;
  pSrc1=pSrc0+width;
  pSrc2=pSrc1+width;

  pic=cache;

  short* pySharpen=ySharpen;
  short* pEdge=sobelEdge+width;
  //first row
  //gettimeofday(&start_cpu[2], NULL);

  for(int w=0;w!=width;w++)
  {
    *pic++=(unsigned char)*pySharpen++;
  }


  for(int h=0;h<height-2;h++)
  {
    //第一列不进行osc
    *pic++=(unsigned char)*pySharpen++;
    pEdge++;

    //middle cols
    for(int w=0;w<width-2;w++)
    {
      enhanced=*pySharpen;

      maxValue=MAX2(MAX2(pSrc0[0],pSrc0[1]),pSrc0[2]);
      maxValue=MAX2(maxValue,MAX2(MAX2(pSrc1[0],pSrc1[1]),pSrc1[2]));
      maxValue=MAX2(maxValue,MAX2(MAX2(pSrc2[0],pSrc2[1]),pSrc2[2]));

      minValue=MIN3(pSrc0[0],pSrc0[1],pSrc0[2]);
      minValue=MIN2(minValue,MIN3(pSrc1[0],pSrc1[1],pSrc1[2]));
      minValue=MIN2(minValue,MIN3(pSrc2[0],pSrc2[1],pSrc2[2]));

      oscStrength=GetOSCX16(*pEdge,cutoff,order,peak,low);
      //过冲控制
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

    //最后一列不进行osc
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
  //gettimeofday(&end_cpu[2], NULL);
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

  gettimeofday(&start_cpu[4], NULL);
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
  gettimeofday(&end_cpu[4], NULL);
}


short MeanX16(short *pEdge,int width ,int height)
{
  short mean;
  int sum = 0;
  int size=height*width;
  short* p=pEdge;

  gettimeofday(&start_cpu[5], NULL);
  for(int i=0;i!=size;i++)
  {
    sum +=*p++;
  }

  mean=(sum+size/2)/size;
  gettimeofday(&end_cpu[5], NULL);

  return mean;
}
// Src, Up, pError
void Sharpness(unsigned char** yPlane,unsigned char** yPlaneCSER,short** pError,int width,int height,MMC_CSE_PARAMETER_PUBLIC* cseParamPublic)
{
  short* pEdge=(short*)malloc(width*height*sizeof(short));
  short* pSharpness=(short*)malloc(width*height*sizeof(short));

  // step 3.1: Sobel algorithm.
  SobelX16(yPlane[0],pEdge,width,height,width,width);


  // step 3.2: mean.
  short mean=MeanX16(pEdge,width,height);

  float cutoff=cseParamPublic->cutoffCoef*mean;
  float peak=cseParamPublic->peak;
  float cutoff2=cseParamPublic->cutoff2;

  float order=2;
  float order2=2;

  float strength=1;

  // step 3.3: GetStrength.
  gettimeofday(&start_cpu[6], NULL);
  for(int h=0;h<height;h++)
  {
    for(int w=0;w<width;w++)
    {
      strength=GetStrengthX16(pEdge[h*width+w],cutoff,order,peak,1.0,order2,cutoff2);
      pSharpness[h*width+w]=yPlaneCSER[h][w]+(float)(pError[h][w])*strength;
    }
  }

  // step 3.4: OvershootControl.
  //输出存储在pSharpness中
  OvershootControlFloatX16(yPlane[0],pSharpness,pEdge,mean,width,height,cseParamPublic);

  // step 3.5: Do subsharpness.
  gettimeofday(&end_cpu[6], NULL);
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
  //gettimeofday(&end_cpu[6], NULL);

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

  //隔行隔列遍历大图
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

  unsigned char* pTmp1=dstImage; // First line of dst.
  unsigned char* pTmp2=dstImage+dstWidth-1; // Second line of dst

  /**************************/
  /* 插值法              */
  /**************************/

  gettimeofday(&start_cpu[1], NULL);
  pTmp1=dstImage;
  //第一列
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

  //第二列
  pTmp1=dstImage;
  for(int h=0;h<dstHeight;h++)
  {
    *(pTmp1+1)=*pTmp1;
    pTmp1 +=dstWidth;
  }


  //倒数第二列
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

  //倒数第一列
  pTmp1=dstImage+dstWidth-2;
  for(int h=0;h<dstHeight;h++)
  {	
    *(pTmp1+1)=*pTmp1;
    pTmp1 +=dstWidth;
  }

  gettimeofday(&end_cpu[1], NULL);


  gettimeofday(&start_cpu[2], NULL);

  //第一行
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
  //第二行
  pTmp1=dstImage;
  pTmp2=dstImage+dstWidth;
  for(int w=0;w<dstWidth;w++)
  {
    *pTmp2++=*pTmp1++;
  }

  //倒数第二行
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

  //倒数第一行
  pTmp1=dstImage+(dstHeight-2)*dstWidth;
  pTmp2=dstImage+(dstHeight-1)*dstWidth;
  for(int w=0;w<dstWidth;w++)
  {
    *pTmp2++=*pTmp1++;
  }
  gettimeofday(&end_cpu[2], NULL);

  // Up.
  gettimeofday(&start_cpu[3], NULL);

  //主体
  for(h=0;h<height-1;h++)
  {
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
    p1++;
    p2++;

    pDst1 = pDst1 + 3*dstWidth + 4;
    pDst2 = pDst2 + 3*dstWidth + 4;
    pDst3 = pDst3 + 3*dstWidth + 4;
    pDst4 = pDst4 + 3*dstWidth + 4;

  }
  gettimeofday(&end_cpu[3], NULL);

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
  char output_file[128] = "output_serial";
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

  /*读取YUV图片，只使用Y分量*/
  //load_image(yuvfile,yPlane[0],width*height);
  p=yuvfile;
  q = yPlane[0];
  for(int i=0;i<height*width;i++)
  {
    *q++ = *p++;
  }
  int times = 20;
  double duration_cpu = 0.0;
  for( int i = 0; i < 7; i++)
    time_prof[i] = 0;

  for( int i = 0; i < times; i++){

    /* step 1: 下采样*/
    DownScaleNewX16(yPlane[0],height,width,yPlaneDown[0]);

    /*step 2: UpSample 计算误差*/
    UpScaleNewX16(yPlaneDown[0],quarterHeight,quarterWidth,yPlaneCSER[0]);

    // step 3: pError.
    for(int h=0;h<height;h++)
    {
      for(int w=0;w<width;w++)
      {
        pError[h][w]=yPlane[h][w]-yPlaneCSER[h][w];
      }		
    }

    // step 3: Do Sharpness.	input: Src, Up, pError.
    Sharpness(yPlane,yPlaneCSER,pError,width,height,&cseParamPublic);

    for (int j = 0; j < 7; j++) {
      duration_cpu = 1000 * ((end_cpu[j]).tv_sec - (start_cpu[j]).tv_sec) + ((end_cpu[j]).tv_usec - (start_cpu[j]).tv_usec)/1000.0;
      time_prof[j] += duration_cpu;
    }

  }
  cout<< "Size: " << height << "x" << width << endl;
  for (int i = 0; i < 7; i++) {
    if (i == 0)
      cout << "DownScale: ";
    else if (i == 1)
      cout << "UpCol: ";
    else if (i == 2)
      cout << "OpRow: ";
    else if (i == 3)
      cout << "Up: ";
    else if (i == 4)
      cout << "Sobel: ";
    else if (i == 5)
      cout << "Mean: ";
    else if (i == 6)
      cout << "Sharpness: ";

    printf("%.2f ms\n", time_prof[i]/times);
  }


  /*dump 结果到文件上*/
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
