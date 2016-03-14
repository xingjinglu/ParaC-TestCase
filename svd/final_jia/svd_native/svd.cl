//TODO:这几个参数应从CPU端传过来
#define TYPE double
#define THRESHOLD 0.00001

//因为对矩阵进行了转置，所以，这里ROWS和COLS的值应该和在CPU端的值相互置换
#define ROWS 256
#define COLS 256

//计算两个复数向量的内积
//result 计算实部
//result1 计算虚部
//(a + bi)'* (c + di) = (a - bi)*(c+di) = ac + bd + (ad -bc)i 
void inner_product(TYPE p_real, TYPE p_imag, TYPE q_real, TYPE q_imag,
                   __local TYPE *result, __local TYPE *result1, int l_idx) {    
    //初始化  
    result[l_idx]  = p_real * q_real + p_imag * q_imag; //ac + bd 
    result1[l_idx] = p_real * q_imag - p_imag * q_real; //ad - bc 
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

    barrier(CLK_LOCAL_MEM_FENCE); 
    if(l_idx < 32) 
        result[l_idx] += result[l_idx + 32];

    barrier(CLK_LOCAL_MEM_FENCE); 
    if(l_idx < 16) 
        result[l_idx] += result[l_idx + 16];

    barrier(CLK_LOCAL_MEM_FENCE); 
    if(l_idx < 8) 
        result[l_idx] += result[l_idx + 8];

    barrier(CLK_LOCAL_MEM_FENCE); 
    if(l_idx < 4) 
        result[l_idx] += result[l_idx + 4];

    barrier(CLK_LOCAL_MEM_FENCE); 
    if(l_idx < 2) 
        result[l_idx] += result[l_idx + 2]; 

    barrier(CLK_LOCAL_MEM_FENCE); 
    if(l_idx < 1) 
        result[l_idx] += result[l_idx + 1]; 

    barrier(CLK_LOCAL_MEM_FENCE); 

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

void part_product(TYPE p_real, TYPE p_imag, TYPE q_real, TYPE q_imag,
                  __local TYPE *result, int l_idx) {    
    //初始化  
    result[l_idx]  = q_real * q_real +  q_imag * q_imag - p_real * p_real -  p_imag * p_imag; 
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

    barrier(CLK_LOCAL_MEM_FENCE); 
    if(l_idx < 32) 
        result[l_idx] += result[l_idx + 32];

    barrier(CLK_LOCAL_MEM_FENCE); 
    if(l_idx < 16) 
        result[l_idx] += result[l_idx + 16];

    barrier(CLK_LOCAL_MEM_FENCE); 
    if(l_idx < 8) 
        result[l_idx] += result[l_idx + 8];

    barrier(CLK_LOCAL_MEM_FENCE); 
    if(l_idx < 4) 
        result[l_idx] += result[l_idx + 4];

    barrier(CLK_LOCAL_MEM_FENCE); 
    if(l_idx < 2) 
        result[l_idx] += result[l_idx + 2]; 

    barrier(CLK_LOCAL_MEM_FENCE); 
    if(l_idx < 1) 
        result[l_idx] += result[l_idx + 1]; 

    barrier(CLK_LOCAL_MEM_FENCE); 
} 

//矩阵A和矩阵V都进行了转置，以便按行读取数据
//A:输入矩阵
//V:右奇异向量
//row_index:进行正交变换的行序列
//is_convergence:判断是否收敛，初始化为0, 如有列对正交，赋值为1
//start_row: 开始进行正交计算的行号
//init_pass：判断是否要初始化is_convergence
__kernel void svd_op(__global TYPE *A, __global TYPE *V, __global int *row_index, __global int *is_convergence, int start_row, int init_pass) 
{
    int g_idx  = get_global_id(0);
    int l_idx  = get_local_id(0);
    int gp_idx = get_group_id(0);

    //在每一轮开始时，第一个线程将is_convergence 初始化为1
    //TODO:是否能有更好的实现方式？
    if((init_pass == 1) && (g_idx == 0))
        *is_convergence = 1;

    int rows = ROWS;
    int cols = COLS;

    //__local TYPE p_real[COLS];
    //__local TYPE p_imag[COLS];
    //__local TYPE q_real[COLS];
    //__local TYPE q_imag[COLS];
    __local TYPE result[COLS];
    __local TYPE result1[COLS];
    __local int selected_rows[2];

    //判断线程组是否越界，当rows为偶数时，奇数阶段的正交变换次数少1
    //奇数阶段，会有一个work-group处于空闲状态
    //TODO:能够有更好的实现方式？
    if((gp_idx << 1) + start_row + 1  < rows)
    {
        //将每个work-group负责处理的两行，读入本地内存中
        if(l_idx < 2)
            selected_rows[l_idx] = row_index[start_row + (gp_idx << 1) + l_idx];
        barrier(CLK_LOCAL_MEM_FENCE);

        int p_real_row_index = selected_rows[0];
        int p_imag_row_index = p_real_row_index + rows;

        int q_real_row_index = selected_rows[1];
        int q_imag_row_index = q_real_row_index + rows;

        TYPE p_real = A[p_real_row_index * cols + l_idx];
        TYPE p_imag = A[p_imag_row_index * cols + l_idx];
        TYPE q_real = A[q_real_row_index * cols + l_idx];
        TYPE q_imag = A[q_imag_row_index * cols + l_idx];

        inner_product(p_real, p_imag, q_real, q_imag, result, result1, l_idx);

        TYPE a = result1[0];
        TYPE b = result[0];

        TYPE value = sqrt(a * a + b * b);
        if(value >= THRESHOLD)
        {
            //TODO:能否有更好的实现方式？
            if(l_idx == 0)
                *is_convergence = 0;

            int sig = (b == 0) ? 0 : (b > 0 ? 1 : -1);
            TYPE s_a2b2 = sig * sqrt(a * a + b * b);
            TYPE sin_alpha = a / s_a2b2;
            TYPE cos_alpha = b / s_a2b2;
            TYPE m = -1 * (b * cos_alpha + a * sin_alpha);

            part_product(p_real, p_imag, q_real, q_imag, result, l_idx);

            TYPE n = 0.5 * result[0];
            sig = (n == 0) ? 0 : (n > 0 ? 1 : -1);
            TYPE w = sig * m / sqrt(m*m + n*n);

            TYPE sin_x = w/sqrt(2 * (1 + sqrt(1 - w * w)));
            TYPE cos_x = sqrt(1 - sin_x * sin_x);

            A[p_real_row_index * cols + l_idx] = p_real * cos_x + q_real * cos_alpha * sin_x + q_imag * sin_alpha * sin_x;
            A[p_imag_row_index * cols + l_idx] = p_imag * cos_x + q_imag * cos_alpha * sin_x - q_real * sin_alpha * sin_x;

            A[q_real_row_index * cols + l_idx] = q_real * cos_x - p_real * cos_alpha * sin_x + p_imag * sin_alpha * sin_x;
            A[q_imag_row_index * cols + l_idx] = q_imag * cos_x - p_imag * cos_alpha * sin_x - p_real * sin_alpha * sin_x;



            //共享内存复用 取V
            p_real = V[p_real_row_index * cols + l_idx];
            p_imag = V[p_imag_row_index * cols + l_idx];
            q_real = V[q_real_row_index * cols + l_idx];
            q_imag = V[q_imag_row_index * cols + l_idx];

      if(g_idx == 0)
          printf("mid0 = %f, mid1= %f, mid2 = %f, mid3= %f\n", V[p_real_row_index * cols + l_idx], V[p_imag_row_index * cols + l_idx],V[q_real_row_index * cols + l_idx],V[q_imag_row_index * cols + l_idx])  ;

            V[p_real_row_index * cols + l_idx] = p_real * cos_x + q_real * cos_alpha * sin_x + q_imag * sin_alpha * sin_x;
            V[p_imag_row_index * cols + l_idx] = p_imag * cos_x + q_imag * cos_alpha * sin_x - q_real * sin_alpha * sin_x;

            V[q_real_row_index * cols + l_idx] = q_real * cos_x - p_real * cos_alpha * sin_x + p_imag * sin_alpha * sin_x;
            V[q_imag_row_index * cols + l_idx] = q_imag * cos_x - p_imag * cos_alpha * sin_x - p_real * sin_alpha * sin_x;

        }

        if(l_idx == 0)
        {
            row_index[start_row + (gp_idx << 1)] = q_real_row_index;
            row_index[start_row + (gp_idx << 1) + 1] = p_real_row_index;;
        }
    }
}

//计算S
//S[i] = A[i]' * A[i]
//A[i] 为矩阵A（转置后）的行向量
__kernel void s_comp(__global TYPE *A, __global TYPE *S)
{
    int l_idx  = get_local_id(0);
    int gp_idx = get_group_id(0);

    int rows = ROWS;
    int cols = COLS;

    //__local TYPE A_real[COLS];
   // __local TYPE A_imag[COLS];
    __local TYPE result[COLS];
    __local TYPE result1[COLS];

    //将每个work-group负责处理的两行，读入本地内存中
    int A_real_row_index = gp_idx;
    int A_imag_row_index = gp_idx + rows;

    TYPE A_real = A[A_real_row_index * cols + l_idx];
    TYPE A_imag = A[A_imag_row_index * cols + l_idx];

    //TODO：这步运算可以优化
    //两个相同向量的内积，虚部为零，不用计算
    inner_product(A_real, A_imag, A_real, A_imag, result, result1, l_idx);

    TYPE a = result[0];
    TYPE b = result1[0]; 

    TYPE s = sqrt(sqrt(a * a + b * b));

    if(l_idx == 0)
        S[gp_idx] = s;
}
