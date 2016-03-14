//TODO:这几个参数应从CPU端传过来
//#include<ClHost.h>
#define TYPE double
#define THRESHOLD 0.00001

//因为对矩阵进行了转置，所以，这里ROWS和COLS的值应该和在CPU端的值相互置换
#define ROWS 256
#define COLS 256

//计算两个复数向量的内积
//result 计算实部
//result1 计算虚部
//(a + bi)'* (c + di) = (a - bi)*(c+di) = ac + bd + (ad -bc)i 
void* inner_product(TYPE p_real, TYPE p_imag, TYPE q_real, TYPE q_imag,
                   __local TYPE *result, __local TYPE *result1, int l_idx) {    
    //初始化  
    TYPE middle_result;
     middle_result = p_real * q_real;
    middle_result = fma(p_imag, q_imag, middle_result); //ac + bd
    result[l_idx]  = middle_result; //ac + bd 


    middle_result = -(p_imag * q_real);
    middle_result = fma(p_real, q_imag, middle_result); //ad -bc 
    result1[l_idx]  = middle_result; //ad - bc 
    barrier(CLK_LOCAL_MEM_FENCE); 


    //进行规约计算, 
    //AMD GPU work-group(block,CUDA)最大为256 
    //目前，为性能测试，work-group大小为256  
    //前128个线程计算result（实部），后128个线程计算result1(虚部） 
    if(l_idx < 128) 
        result[l_idx] += result[l_idx + 128];
    if(l_idx >= 128) 
        result1[l_idx -128] += result1[l_idx - 128 + 128];

     barrier(CLK_LOCAL_MEM_FENCE);

    //AMD GPU wavefront(warp,CUDA)大小为64个线程, work-group 大小最小为64个线程 
    if(l_idx < 64) 
        result[l_idx] += result[l_idx + 64];
    if(l_idx < 32) 
        result[l_idx] += result[l_idx + 32];
    if(l_idx < 16) 
        result[l_idx] += result[l_idx + 16];
    if(l_idx < 8) 
        result[l_idx] += result[l_idx + 8];
    if(l_idx < 4) 
        result[l_idx] += result[l_idx + 4];
    if(l_idx < 2) 
        result[l_idx] += result[l_idx + 2]; 
    if(l_idx < 1) 
        result[l_idx] += result[l_idx + 1]; 


    if(l_idx >= 128) 
    { 
        if(l_idx < 192)  
            result1[l_idx - 128] += result1[l_idx - 128 + 64];
        if(l_idx < 160) 
            result1[l_idx - 128] += result1[l_idx - 128 + 32];
        if(l_idx < 144) 
            result1[l_idx - 128] += result1[l_idx - 128 + 16];
        if(l_idx < 136) 
            result1[l_idx - 128] += result1[l_idx - 128 + 8]; 
        if(l_idx < 132) 
            result1[l_idx - 128] += result1[l_idx - 128 + 4]; 
        if(l_idx < 130) 
            result1[l_idx - 128] += result1[l_idx - 128 + 2]; 
        if(l_idx < 129) 
            result1[l_idx - 128] += result1[l_idx - 128 + 1]; 
    } 

    barrier(CLK_LOCAL_MEM_FENCE); 
} 

TYPE part_product(TYPE p_real, TYPE p_imag, TYPE q_real, TYPE q_imag,
                  __local TYPE *result, int l_idx) {    
    //初始化  
    TYPE middle_result;

    middle_result = q_real * q_real;
    middle_result = fma(q_imag,  q_imag, middle_result);
    middle_result = fma(-p_real, p_real, middle_result);
    middle_result = fma(-p_imag, p_imag, middle_result);
    result[l_idx]  = middle_result; 

    barrier(CLK_LOCAL_MEM_FENCE); 

    //进行规约计算, 
    //AMD GPU work-group(block,CUDA)最大为256 
    //目前，为性能测试，work-group大小为256  
    //前128个线程计算result（实部），后128个线程计算result1(虚部） 
    if(l_idx < 128) 
        result[l_idx] += result[l_idx + 128];

     barrier(CLK_LOCAL_MEM_FENCE);

    //AMD GPU wavefront(warp,CUDA)大小为64个线程, work-group 大小最小为64个线程 
    if(l_idx < 64) 
        result[l_idx] += result[l_idx + 64];
    if(l_idx < 32) 
        result[l_idx] += result[l_idx + 32];
    if(l_idx < 16) 
        result[l_idx] += result[l_idx + 16];
    if(l_idx < 8) 
        result[l_idx] += result[l_idx + 8];
    if(l_idx < 4) 
        result[l_idx] += result[l_idx + 4];
    if(l_idx < 2) 
        result[l_idx] += result[l_idx + 2]; 
    if(l_idx < 1) 
        result[l_idx] += result[l_idx + 1]; 

    barrier(CLK_LOCAL_MEM_FENCE); 
     return result[l_idx];
} 


