//复数矩阵的SVD分解
//贾海鹏   jiahaipeng95@gmail.com
//
//复数矩阵的奇异值分解，复数矩阵的存储格式为矩阵的每一个元素的实部和虚部相邻存储，
//一个n*n的复数矩阵的大小为n*2n
//计算结果与matlab结果比较，奇异值S相等，变换后A的精度在10的-5次方，V的精度为10的-3次方
//当矩阵规模为256 * 256时，收敛的迭代次数为10
//当矩阵规模为64 * 64时，收敛的迭代次数为13
//本程序只实现了复数矩阵的SVD分解

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;
using std::cout;
using std::endl;

#define COLS  256 
#define ROWS  256 
#define TYPE  float 
#define MAX_ITERATIONS 40 
#define THRESHOLD  0.00001

#define FLAG   1      //0 为实数矩阵， 1为复数矩阵
#define IN_PRODUCT  0

//打印矩阵 只为调试
void print_matrix(TYPE *A)
{
    cout.setf(ios::fixed);
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS * 2; j++)
            cout << setprecision(6) <<  A[i * COLS * 2 + j] << " ";
        cout << endl;
    }
}
//打印向量  只为调试
void print_vector(TYPE *A)
{
    for(int i = 0; i < COLS; i++)
    {
        cout << setprecision(6) << A[i] << " ";
        cout << endl;
    }
}
//比较两个向量是否相等，只为测试
bool is_matrix_equal(TYPE *A, TYPE *B) 
{
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS * 2; j++)
        {
            if(fabs(A[i * COLS *2 + j] - B[i * COLS * 2 +j]) > 0.001)
            {
                cout << "i = " << i << "j = " << j  <<endl;
                cout << "A = " << A[i * COLS *2 + j] <<endl;
                cout << "B= "  << B[i * COLS *2 +j] << endl; 
                return 0;
            }
        }

    return 1;
}
//比较两个奇异值是否相等，只为测试
bool is_vector_equal(TYPE *A, TYPE *B) 
{
    for(int j = 0; j < COLS; j++)
    {
        if(fabs(A[j] - B[j]) > 0.00001)
        {
            cout << "j = " << j  <<endl;
            cout << "A = " << A[j] <<endl;
            cout << "B= "  << B[j] << endl; 
            return 0;
        }
    }

    return 1;
}

//读取复数矩阵的一列，复数实部和虚部相邻存储
void get_cols(TYPE *src, TYPE *dst ,int col)
{

    for(int k = 0; k < ROWS; k++) 
    {
        dst[2 * k]     = src[k * COLS * 2 + 2 * col    ];
        dst[2 * k + 1] = src[k * COLS * 2 + 2 * col + 1];
    }
}

//求取两个复数列向量的内积，返回内积结果的模
//复数向量内积公式：(a + bi)'*(c + di) = (a -bi) * (c + di);
//复数相乘公式：(a+bi)*(c+di) = (ac-bd) + (ad+bc)
double inner_product(TYPE *src1, TYPE *src2)
{
    double  real = 0.0f;
    double  imag = 0.0f;

    for(int i = 0; i < ROWS; i++)
    {
        real += (double)src1[2 * i] * src2[2 * i]     + src1[2 * i + 1] * src2[2 * i + 1];
        imag += (double)src1[2 * i] * src2[2 * i + 1] - src1[2 * i + 1] * src2[2 * i];
    }

    return (double)sqrt((double)real * (double)real + (double)imag * (double)imag);
}

//计算复数列向量的2范数：
//x = (x1, x2, .....,xn), xi为复数
//norm(x) = |x1| * |x1| +  |x2| * |x2| + .... + |xn| * |xn|(开根号）
double norm(TYPE *src)
{
    double result = 0;

    for(int i = 0; i < ROWS; i++)
        result += src[2 * i] * src [2 * i] + src[2 * i + 1] * src[2 * i + 1];

    return sqrt(fabs(result));
}


//计算两个复数列向量，实部列和虚部列向量的内积
//is_src1_real 判断取src1的实部列还是虚部列, 为1取实部列，为0取虚部列
//is_src2_real 判断取src2的实部列还是虚部列, 为1取实部列，为0取虚部列
double part_product(TYPE *src1, TYPE *src2, int is_src1_real, int is_src2_real)
{
    double result = 0.0f;

    if(is_src1_real == 1 && is_src2_real == 1)
        for(int i = 0; i < ROWS; i++)
            result += (double)src1[2 * i] * src2[2 * i];

    if(is_src1_real == 0 && is_src2_real == 0)
        for(int i = 0; i < ROWS; i++)
            result += (double)src1[2 * i + 1] * src2[2 * i + 1];

    if(is_src1_real == 1 && is_src2_real == 0)
        for(int i = 0; i < ROWS; i++)
            result += (double)src1[2 * i] * src2[2 * i + 1];

    if(is_src1_real == 0 && is_src2_real == 1)
        for(int i = 0; i < ROWS; i++)
            result += (double)src1[2 * i + 1] * src2[2 * i];

    return result;
}

//符号函数
int sign(double a)
{
    if(a > 0) 
        return 1;

    if(a == 0)
        return 0;

    return -1;
}

//根据计算结果更新矩阵A的数据
void update_data(TYPE *A, TYPE *ci, TYPE *cj, double sin_x, double cos_x, double sin_alpha, double cos_alpha, int col, int flag)
{
    double real = 0.0f;
    double imag = 0.0f;

    for(int i = 0; i < ROWS; i++)
    {
        real = ci[2 * i    ] * cos_x + flag * cj[2 * i    ] * cos_alpha * sin_x + cj[2 * i +1] * sin_alpha * sin_x;
        imag = ci[2 * i + 1] * cos_x + flag * cj[2 * i + 1] * cos_alpha * sin_x - cj[2 * i   ] * sin_alpha * sin_x;

        A[i * COLS * 2 + 2 * col]     = real;
        A[i * COLS * 2 + 2 * col + 1] = imag; 
    }
}

//svd计算   A = BSV
void svd(TYPE *A, TYPE *B, TYPE *S, TYPE *V)
{
    int pass;
    int iterations_passed = 0;
    
    //初始化列索引
    int *rotate_col_idx = new int[COLS];
    for(int i = 0; i < COLS; i++)
        rotate_col_idx[i] = i;

    //分配列向量空间
    TYPE *ci = new TYPE[ROWS * 2];
    TYPE *cj = new TYPE[ROWS * 2];
    TYPE *vi = new TYPE[ROWS * 2];
    TYPE *vj = new TYPE[ROWS * 2];

    int iteration = MAX_ITERATIONS;
    int start_index, col_p, col_q, skip_trans;
    while(iteration > 0)
    {
        //判断程序是否收敛
        pass = 1;

        for(int i = 0; i < COLS; i++)
        {
            //判断是奇数阶段还是偶数阶段，如果是偶数阶段，从第0个索引开始，否则从第1个索引开始
            start_index = (i % 2 == 0) ? 0 : 1;

            for(int j = start_index + 1; j < COLS; j+=2)
            {
                //获取需要进行正交变换的两列
                col_p = rotate_col_idx[j - 1];
                col_q = rotate_col_idx[j];

                get_cols(A, ci, col_p);
                get_cols(A, cj, col_q);
                get_cols(V, vi, col_p);
                get_cols(V, vj, col_q);

                skip_trans = 0;

                //判断两列是否正交
                double value = inner_product(ci, cj);

                double value1;
                if(IN_PRODUCT != 1)
                    value1 = value/norm(ci)/norm(cj); 

                if(value < THRESHOLD || value1 < THRESHOLD)
                    skip_trans = 1;

                if(skip_trans ==0)
                {
                    //SVD 列列变换
                    pass = 0;

                    double inner_ri = part_product(ci, cj, 1, 0);
                    double inner_ir = part_product(ci, cj, 0, 1);
                    double inner_rr = part_product(ci, cj, 1, 1);
                    double inner_ii = part_product(ci, cj, 0, 0);

                    double a = (double)inner_ri - (double)inner_ir;
                    double b = (double)inner_rr + (double)inner_ii;

                    double s_a2b2 = (double)sign(b) * sqrt(a * a + b * b);
                    double sin_alpha = a / s_a2b2;
                    double cos_alpha = b / s_a2b2;
                    double m = -1 * (b * cos_alpha + a * sin_alpha);

                    double inner_rrj = part_product(cj, cj, 1, 1);
                    double inner_iij = part_product(cj, cj, 0, 0);
                    double inner_rri = part_product(ci, ci, 1, 1);
                    double inner_iii = part_product(ci, ci, 0, 0);

                    double n = (double)0.5 * (inner_rrj + inner_iij - inner_rri - inner_iii);
                    double w = (double)sign(n) * m / sqrt(m*m + n*n);

                    double sin_x = w/sqrt(2 * (1 + sqrt(1 - w * w)));
                    double cos_x = sqrt(1 - sin_x * sin_x);

                    update_data(A, ci, cj, sin_x, cos_x, sin_alpha, cos_alpha, col_p,  1); 
                    update_data(A, cj, ci, sin_x, cos_x, sin_alpha, cos_alpha, col_q, -1); 
                    update_data(V, vi, vj, sin_x, cos_x, sin_alpha, cos_alpha, col_p,  1); 
                    update_data(V, vj, vi, sin_x, cos_x, sin_alpha, cos_alpha, col_q, -1); 
                }

                rotate_col_idx[j - 1] = col_q;
                rotate_col_idx[j    ] = col_p;
            }
        }

        iteration--;
        if(pass == 1)
            break;
    }

    iterations_passed = MAX_ITERATIONS - iteration;

    cout << iterations_passed << endl;

    //计算奇异值
    int rank = 0;
    for(int i = 0; i < COLS; i++)
    {
        get_cols(A, ci, i);
        TYPE norm_A = sqrt(inner_product(ci, ci)); 
        if(norm_A > THRESHOLD)
            rank++;

        if(i < ROWS)
            S[i] = norm_A;
    }

    //计算左奇异向量
    for(int i = 0; i < ROWS; i++) 
        for(int j= 0; j < COLS * 2; j++)
            B[i * COLS * 2 + j] = A[i * COLS * 2 + j] / S[j]; 


    //释放内存
    delete rotate_col_idx;
    delete ci;
    delete cj;
    delete vi;
    delete vj;
}

int main()
{
    TYPE *A = new TYPE[ROWS * COLS * 2];   //复数矩阵，相邻两个元素：一个为实部，一个为虚部
    TYPE *B = new TYPE[ROWS * COLS * 2];   //左奇异向量矩阵
    TYPE *S = new TYPE[COLS];             //奇异值
    TYPE *V = new TYPE[ROWS * COLS * 2];   //右奇异向量矩阵

    FILE* fp = fopen("./data/Matrix_input_A256.txt", "r");
    //fstream f("./data/Matrix_input_A256.txt", ios::in);
    if(fp == NULL)
    {
        cout << "matrix input A is not found" << endl;
        return 1;
    }
    //从外部文件中读取原始矩阵A
    TYPE temp;
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            fscanf(fp, "%f", &temp);
            A[i * COLS * 2 + j * 2] = temp;
        }

        for(int j = 0; j < COLS; j++)
        {
            fscanf(fp, "%f", &temp);
             A[i * COLS * 2 + j * 2 + 1] = temp;
        }
    }

    fclose(fp);

//    print_matrix(A);

    //将矩阵V初始化为单位矩阵
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS * 2; j++)
        {
            if(j == 2 * i)
                V[i * COLS * 2 + j] = 1; 
            else
                V[i * COLS * 2 + j] = 0; 
        }


    //将S初始化为0
    for(int i =0; i < COLS; i++)
        S[i] = 0;

    //进行SVD计算
    svd(A, B, S, V);

 //   print_matrix(A);

    cout << endl;
    cout << endl;

//    print_matrix(V);

    /*****************************测试运算结果************************************/
    TYPE *A1 = new TYPE[ROWS * COLS * 2];   //复数矩阵，相邻两个元素：一个为实部，一个为虚部
    TYPE *V1 = new TYPE[ROWS * COLS * 2];   //右奇异向量矩阵
    TYPE *S1 = new TYPE[COLS];              //奇异值

    //测试矩阵A的正确性
    fstream f1("./data/Matrix_out_A256.txt", ios::in);
    if(!f1)
    {
        cout << "matrix output A is not found" << endl;
        return 1;
    }
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
            f1 >>setprecision(6) >>  A1[i * COLS * 2 + j * 2];

        for(int j = 0; j < COLS; j++)
            f1 >>setprecision(6) >>  A1[i * COLS * 2 + j * 2 + 1];
    }

    f1.close();

    cout << "compare A" << endl;

    bool result = is_matrix_equal(A, A1);
    if(result ==1)
        cout << "success" << endl;

    //测试矩阵V的正确性
    fstream f2("./data/Matrix_out_V256.txt", ios::in);
    if(!f2)
    {
        cout << "matrix output V is not found" << endl;
        return 1;
    }
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
            f2 >>setprecision(6) >>  V1[i * COLS * 2 + j * 2];

        for(int j = 0; j < COLS; j++)
            f2 >>setprecision(6) >>  V1[i * COLS * 2 + j * 2 + 1];
    }

    f2.close();

    cout << "compare V" << endl;

    result = is_matrix_equal(V, V1);
    if(result ==1)
        cout << "success" << endl;


    //测试矩阵S的正确性
    fstream f3("./data/Matrix_out_S256.txt", ios::in);
    if(!f3)
    {
        cout << "matrix output S is not found" << endl;
        return 1;
    }

    for(int i = 0; i < COLS; i++)
        f3 >>setprecision(6) >>  S1[i];

    f3.close();

    cout << "compare S" << endl;

    result = is_vector_equal(S, S1);
    if(result ==1)
        cout << "success" << endl;

    //释放内存
    delete A;
    delete B;
    delete S;
    delete V;

    return 0;
}
