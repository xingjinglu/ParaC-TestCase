__kernel void PyramidFilter_padding(
__global unsigned char * const pSrc_pad,
__global unsigned char * pBufL,
int stepwide,
int shift,
int width,
int height)
{
    int gidx = get_global_id(0);
    int gidy = get_global_id(1);

    short2 pre,later;
    short4 mid,pre4,result;
    int inputIndex;

    int upwidth= (width%4==0) ? (width/4) : (width/4+1);

    if(gidx >= upwidth || gidy >= height)
        return;

    inputIndex=mad24(gidy,stepwide,shift)+(gidx<<2);

    pre   = convert_short2(*((__global uchar2 *)(pSrc_pad+inputIndex-2)));
    mid   = convert_short4(*((__global uchar4 *)(pSrc_pad+inputIndex)));
    later = convert_short2(*((__global uchar2 *)(pSrc_pad+inputIndex+4)));
      
    if(gidx==0)
    {
        pre.s0=(mid.s0<<1)-(mid.s1<<2)-mid.s2+(mid.s3<<2);
        pre.s1=(mid.s1<<1)-mid.s3;
    }
#if VALUE==1
    else if(gidx==upwidth-2)
        later.s1=(mid.s3<<1)-mid.s1;
#endif
    else if(gidx==upwidth-1)
    {
#if VALUE==0
        later.s0=(mid.s2<<1)-mid.s0;
        later.s1=(mid.s3<<1)-(mid.s2<<2)-mid.s1+(mid.s0<<2);
#endif

#if VALUE==1
        pre4 = convert_short4(*((__global uchar4 *)(pSrc_pad+inputIndex-4)));
        mid.s1=(pre4.s3<<1)-pre4.s1;
        mid.s2=(mid.s0<<1)-(pre4.s3<<2)-pre4.s2+(pre4.s1<<2);
#endif

#if VALUE==2
        mid.s2=(mid.s0<<1)-pre.s0;
        mid.s3=(mid.s1<<1)-(mid.s0<<2)-pre.s1+(pre.s0<<2);
#endif

#if VALUE==3
        mid.s3=(mid.s1<<1)-pre.s1;
        later.s0=(mid.s2<<1)-(mid.s1<<2)-mid.s0+(pre.s1<<2);
#endif
     }

     result.s0 = mad24(pre.s1,4,pre.s0) + mad24(6,mid.s0,mid.s2) + mad24(mid.s1,4,8);
     result.s1 = mad24(mid.s0,4,pre.s1) + mad24(6,mid.s1,mid.s3) + mad24(mid.s2,4,8);
     result.s2 = mad24(mid.s1,4,mid.s0) + mad24(6,mid.s2,later.s0) + mad24(mid.s3,4,8);
     result.s3 = mad24(mid.s2,4,mid.s1) + mad24(6,mid.s3,later.s1) + mad24(later.s0,4,8);

     result = result >> (short)(short)(short)(short)(short)(short)(short)(short)(short)4;

     *((__global uchar4 *)(pBufL+inputIndex)) = convert_uchar4(result);
}


__kernel void PyramidFilter_vertical_downsample(
__global unsigned char* const pBufL_pad,
__global unsigned char* pDownsampleBuf,
int stepwide,
int shift,
int downstepwide,
int downshift,
int width,
int height)
{
    int gidx = get_global_id(0);
    int gidy = get_global_id(1);

    short2 pre,later;
    short4 pre4,result;
    short8 mid;
    int inputIndex,outputIndex;

    int upheight = (height%4==0) ? (height/4) : (height/4+1);

    if(gidx >= width || gidy >= upheight)
        return ;

    inputIndex = mad24(gidy<<3,stepwide,(gidx<<1) + shift);
    outputIndex = mad24(gidy<<2,downstepwide,gidx + downshift);

    if(gidy != upheight-1)
    {
        pre.s0 = pBufL_pad[inputIndex - (stepwide<<1)];
        pre.s1 = pBufL_pad[inputIndex - stepwide];
        mid.s0 = pBufL_pad[inputIndex];
        mid.s1 = pBufL_pad[inputIndex + stepwide];
        mid.s2 = pBufL_pad[mad24(stepwide,2,inputIndex)];
        mid.s3 = pBufL_pad[mad24(stepwide,3,inputIndex)];
        mid.s4 = pBufL_pad[mad24(stepwide,4,inputIndex)];
        mid.s5 = pBufL_pad[mad24(stepwide,5,inputIndex)];
        mid.s6 = pBufL_pad[mad24(stepwide,6,inputIndex)];
        mid.s7 = pBufL_pad[mad24(stepwide,7,inputIndex)];
        later.s0 = pBufL_pad[mad24(stepwide,8,inputIndex)];
        later.s1 = pBufL_pad[mad24(stepwide,9,inputIndex)];
        
        if(gidy==0)
        {
            pre.s0 = (mid.s0<<1)-(mid.s1<<2)-mid.s2+(mid.s3<<2); 
            pre.s1 = (mid.s1<<1)-mid.s3;
        }
#if VALUEE==1
        else if(gidy == upheight-2)
            later.s1 = (mid.s7<<1)-mid.s5;
#endif
    }
    else 
    {
#if VALUEE==0
        pre.s0 = pBufL_pad[inputIndex - (stepwide<<1)];
        pre.s1 = pBufL_pad[inputIndex - stepwide];
        mid.s0 = pBufL_pad[inputIndex];
        mid.s1 = pBufL_pad[inputIndex + stepwide];
        mid.s2 = pBufL_pad[mad24(stepwide,2,inputIndex)];
        mid.s3 = pBufL_pad[mad24(stepwide,3,inputIndex)];
        mid.s4 = pBufL_pad[mad24(stepwide,4,inputIndex)];
        mid.s5 = pBufL_pad[mad24(stepwide,5,inputIndex)];
        mid.s6 = pBufL_pad[mad24(stepwide,6,inputIndex)];
        mid.s7 = pBufL_pad[mad24(stepwide,7,inputIndex)];

        later.s0 = (mid.s6<<1)-mid.s4;
#endif

#if VALUEE==1
        pre4.s1 = pBufL_pad[inputIndex - stepwide*3];
        pre4.s2 = pBufL_pad[inputIndex - stepwide*2];
        pre4.s3 = pBufL_pad[inputIndex - stepwide];
        pre.s0 = pre4.s2;
        pre.s1 = pre4.s3;
        mid.s0 = pBufL_pad[inputIndex];

        mid.s1 = (pre4.s3<<1)-pre4.s1;
        mid.s2 = (mid.s0<<1)-(pre4.s3<<2)-pre4.s2+(pre4.s1<<2);
#endif

#if VALUEE==2
        pre.s0 = pBufL_pad[inputIndex - (stepwide<<1)];
        pre.s1 = pBufL_pad[inputIndex - stepwide];
        mid.s0 = pBufL_pad[inputIndex];
        mid.s1 = pBufL_pad[inputIndex + stepwide];

        mid.s2 = (mid.s0<<1)-pre.s0;
#endif
 
#if VALUEE==3
        pre.s0 = pBufL_pad[inputIndex - (stepwide<<1)];
        pre.s1 = pBufL_pad[inputIndex - stepwide];
        mid.s0 = pBufL_pad[inputIndex];
        mid.s1 = pBufL_pad[inputIndex + stepwide];
        mid.s2 = pBufL_pad[mad24(stepwide,2,inputIndex)];

        mid.s3=(mid.s1<<1)-pre.s1;
        mid.s4=(mid.s2<<1)-(mid.s1<<2)-mid.s0+(pre.s1<<2);
#endif

#if VALUEE==4
        pre.s0 = pBufL_pad[inputIndex - (stepwide<<1)];
        pre.s1 = pBufL_pad[inputIndex - stepwide];
        mid.s0 = pBufL_pad[inputIndex];
        mid.s1 = pBufL_pad[inputIndex + stepwide];
        mid.s2 = pBufL_pad[mad24(stepwide,2,inputIndex)];
        mid.s3 = pBufL_pad[mad24(stepwide,3,inputIndex)];

        mid.s4=(mid.s2<<1)-mid.s0;
#endif

#if VALUEE==5
        pre.s0 = pBufL_pad[inputIndex - (stepwide<<1)];
        pre.s1 = pBufL_pad[inputIndex - stepwide];
        mid.s0 = pBufL_pad[inputIndex];
        mid.s1 = pBufL_pad[inputIndex + stepwide];
        mid.s2 = pBufL_pad[mad24(stepwide,2,inputIndex)];
        mid.s3 = pBufL_pad[mad24(stepwide,3,inputIndex)];
        mid.s4 = pBufL_pad[mad24(stepwide,4,inputIndex)];

        mid.s5 = (mid.s3<<1)-mid.s1;
        mid.s6 = (mid.s4<<1)-(mid.s3<<2)-mid.s2+(mid.s1<<2);
#endif

#if VALUEE==6
        pre.s0 = pBufL_pad[inputIndex - (stepwide<<1)];
        pre.s1 = pBufL_pad[inputIndex - stepwide];
        mid.s0 = pBufL_pad[inputIndex];
        mid.s1 = pBufL_pad[inputIndex + stepwide];
        mid.s2 = pBufL_pad[mad24(stepwide,2,inputIndex)];
        mid.s3 = pBufL_pad[mad24(stepwide,3,inputIndex)];
        mid.s4 = pBufL_pad[mad24(stepwide,4,inputIndex)];
        mid.s5 = pBufL_pad[mad24(stepwide,5,inputIndex)];

        mid.s6 = (mid.s4<<1)-mid.s2;
#endif
      
#if VALUEE==7
        pre.s0 = pBufL_pad[inputIndex - (stepwide<<1)];
        pre.s1 = pBufL_pad[inputIndex - stepwide];
        mid.s0 = pBufL_pad[inputIndex];
        mid.s1 = pBufL_pad[inputIndex + stepwide];
        mid.s2 = pBufL_pad[mad24(stepwide,2,inputIndex)];
        mid.s3 = pBufL_pad[mad24(stepwide,3,inputIndex)];
        mid.s4 = pBufL_pad[mad24(stepwide,4,inputIndex)];
        mid.s5 = pBufL_pad[mad24(stepwide,5,inputIndex)];
        mid.s6 = pBufL_pad[mad24(stepwide,6,inputIndex)];

        mid.s7 = (mid.s5<<1)-mid.s3;
        later.s0 = (mid.s6<<1)-(mid.s5<<2)-mid.s4+(mid.s3<<2);
#endif
        
    }

    result.s0 = mad24(pre.s1,4,pre.s0) + mad24(6,mid.s0,mid.s2) + mad24(mid.s1,4,8);
    result.s1 = mad24(mid.s1,4,mid.s0) + mad24(6,mid.s2,mid.s4) + mad24(mid.s3,4,8);
    result.s2 = mad24(mid.s3,4,mid.s2) + mad24(6,mid.s4,mid.s6) + mad24(mid.s5,4,8);
    result.s3 = mad24(mid.s5,4,mid.s4) + mad24(6,mid.s6,later.s0) + mad24(mid.s7,4,8);

    result = result >> (short)4;

    if(gidy != upheight-1)
    {
        pDownsampleBuf[outputIndex] = result.s0; 
        pDownsampleBuf[outputIndex + downstepwide] = result.s1; 
        pDownsampleBuf[mad24(downstepwide,2,outputIndex)] = result.s2; 
        pDownsampleBuf[mad24(downstepwide,3,outputIndex)] = result.s3; 
    }
    else
    {
#if VALUEE==1 || VALUEE==2
        pDownsampleBuf[outputIndex] = result.s0; 
#else
        pDownsampleBuf[outputIndex] = result.s0; 
        pDownsampleBuf[outputIndex + downstepwide] = result.s1; 
        pDownsampleBuf[mad24(downstepwide,2,outputIndex)] = result.s2; 
        pDownsampleBuf[mad24(downstepwide,3,outputIndex)] = result.s3; 
#endif
    }
}


__kernel void Upsample(
__global unsigned char* const pSrc,
__global unsigned char* const pDownsample,
__global short* pDst,
int stepwide,
int shift,
int stepwideShort,
int shiftShort,
int downstepwide,
int downshift,
int halfwidth,
int halfheight)
{
    int gidx = get_global_id(0);
    int gidy = get_global_id(1);

    short2 buf2;
    short4 buffer,result,src;
    int inputIndex,outputIndex,inputIndexSrc;

    if(gidx >= halfwidth || gidy >= halfheight-1)
        return ;
    
    inputIndex          = mad24(gidy,downstepwide,gidx + downshift);
    inputIndexSrc       = mad24((gidy<<1),stepwide,(gidx<<1)+ shift + stepwide);
    outputIndex         = mad24((gidy<<1),stepwideShort,(gidx<<2)+ shiftShort + stepwideShort);
    
    buffer.s0 = *(__global uchar *)(pDownsample + inputIndex);
    buffer.s1 = *(__global uchar *)(pDownsample + inputIndex +1);
    buffer.s2 = *(__global uchar *)(pDownsample + inputIndex + downstepwide);
    buffer.s3 = *(__global uchar *)(pDownsample + inputIndex + downstepwide +1);
   
    if(gidy==0)
    {
        int indexsrc,indexdst;
        indexsrc = (gidx<<1)+shift;
        indexdst = (gidx<<2)+shiftShort;

        buf2.s0 = buffer.s0;
        buf2.s1 = (buffer.s0 + buffer.s1 +1)>>1;
        
        src.s01 = convert_short2(*(__global uchar2 *)(pSrc + indexsrc));
#if ODDX==0
        if(gidx == halfwidth-1)
            buf2.s1 = buf2.s0;
#endif
        buf2 = src.s01 - buf2;
        *(__global short2 *)((__global uchar *)pDst + indexdst)=buf2;
    }

#if ODDY==0
    if(gidy== halfheight-2)
    {
        int indexsrc,indexdst;
        indexsrc = stepwide*((halfheight<<1)-1)+(gidx<<1)+shift;
        indexdst = stepwideShort*((halfheight<<1)-1)+(gidx<<2)+shiftShort;

        buf2.s0 = buffer.s2;
        buf2.s1 = (buffer.s2 + buffer.s3 +1)>>1;
        
        src.s01 = convert_short2(*(__global uchar2 *)(pSrc + indexsrc));
#if ODDX==0
        if(gidx == halfwidth-1)
            buf2.s1 = buf2.s0;
#endif
        buf2 = src.s01 - buf2;
        *(__global short2 *)((__global uchar *)pDst + indexdst)=buf2;
    }
#endif

    src.s01 = convert_short2(*(__global uchar2 *)(pSrc + inputIndexSrc));
    src.s23 = convert_short2(*(__global uchar2 *)(pSrc + inputIndexSrc + stepwide));

    result.s0 = (buffer.s0 + buffer.s2 + 1)>>1;
    result.s1 = (buffer.s0 + buffer.s1 + buffer.s2 + buffer.s3 + 2)>>2;
    result.s2 = buffer.s2;
    result.s3 = (buffer.s2 + buffer.s3 + 1)>>1;

#if ODDX==0
    if(gidx == halfwidth-1)
    {
        result.s1 = result.s0;
        result.s3 = result.s2;
    }
#endif 

    result = src-result;
    *(__global short2 *)((__global uchar *)pDst + outputIndex)= result.s01;
    *(__global short2 *)((__global uchar *)pDst + outputIndex + stepwideShort)= result.s23;
}


