#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <memory.h>
#include <sys/time.h>

#define COLS  256 
#define ROWS  256 
#define TYPE  double 
#define MAX_ITERATIONS 40 
#define THRESHOLD  0.00001

bool is_matrix_equal(TYPE *A, TYPE *B) 
{
	for(int i = 0; i < ROWS; i++)
		for(int j = 0; j < COLS * 2; j++)
		{
			if(fabs(A[i * COLS *2 + j] - B[i * COLS * 2 +j]) > 0.001)
			{
				printf("i = %d j = %d\n", i, j);
				printf("A = %.6f\n", A[i * COLS * 2 + j]);
				printf("B = %.6f\n", B[i * COLS * 2 + j]);
				return 0;
			}
		}

	return 1;
}

bool is_vector_equal(TYPE *A, TYPE *B) 
{
	for(int j = 0; j < COLS; j++)
	{
		if(fabs(A[j] - B[j]) > 0.00001)
		{
			printf("j = %d\n", j);
			printf("A = %.6f\n", A[j]);
			printf("B = %.6f\n", B[j]);
			return 0;
		}
	}

	return 1;
}

#pragma acc routine
int sign(double a)
{
	if(a > 0) 
		return 1;

	if(a == 0)
		return 0;

	return -1;
}

void svd(TYPE *A, TYPE *B, TYPE *S, TYPE *V)
{
	int *pass = (int *)malloc(sizeof(int));

	TYPE *A_H = new TYPE[ROWS * COLS * 2];
	TYPE *B_H = new TYPE[ROWS * COLS * 2];
	TYPE *V_H = new TYPE[ROWS * COLS * 2];
	TYPE *S_H = new TYPE[ROWS];
	int *rotate_col_idx = new int[COLS];
	TYPE *ci = new TYPE[COLS*ROWS * 2];
	TYPE *cj = new TYPE[COLS/2*ROWS * 2];
	TYPE *vi = new TYPE[COLS/2*ROWS * 2];
	TYPE *vj = new TYPE[COLS/2*ROWS * 2];
	TYPE value[COLS/2] ;

	for(int i = 0; i < COLS; i++)
		rotate_col_idx[i] = i;

	int iteration = MAX_ITERATIONS;
	int start_index, col_p, col_q, skip_trans;

	struct timeval begin_total, end_total;
	struct timeval begin_calc, end_calc;
	struct timeval mid1, mid2;

	for(int ii = 0; ii < 10; ii++)
	{
		for(int i = 0; i < ROWS; i++) 
			for(int j = 0; j < COLS; j++)
				A_H[i * ROWS + j] = A[j * ROWS + i];

		for(int i = 0; i < ROWS; i++) 
			for(int j = 0; j < COLS; j++)
				A_H[COLS * ROWS + i * ROWS + j] = A[COLS * ROWS + j * ROWS + i];

		memset(V_H, 0, ROWS * COLS * 2 * sizeof(TYPE));
		for(int i = 0; i < ROWS; i++)
			V_H[i * ROWS + i] = 1.0f;

		for(int j = 0; j < COLS; j++)
			S_H[j] = 0;

		for(int i = 0; i < COLS; i++)
			rotate_col_idx[i] = i;

		iteration = MAX_ITERATIONS;

		gettimeofday(&begin_total, NULL);
#pragma acc data copy(A_H[0:COLS*ROWS*2], V_H[0:ROWS*COLS*2]) copyin(rotate_col_idx[0:COLS]) create(ci[0:COLS*ROWS*2], cj[0:COLS/2*ROWS*2], vi[0:COLS/2*ROWS*2], vj[0:COLS/2*ROWS*2], value[0:COLS/2]) copyout(B_H[0:COLS*ROWS*2], S_H[0:ROWS])
#pragma cap data copy(A_H[0:COLS*ROWS*2], V_H[0:ROWS*COLS*2]) copyin(rotate_col_idx[0:COLS]) create(ci[0:COLS*ROWS*2], cj[0:COLS/2*ROWS*2], vi[0:COLS/2*ROWS*2], vj[0:COLS/2*ROWS*2], value[0:COLS/2]) copyout(B_H[0:COLS*ROWS*2], S_H[0:ROWS])
		{
			gettimeofday(&begin_calc, NULL);
			while(iteration > 0)
			{
				pass[0] = 1;

#pragma cap data copy(pass[0:1]) 
#pragma acc data copy(pass[0:1]) 
				{
					for(int i = 0; i < COLS; i++)
					{
						start_index = (i % 2 == 0) ? 0 : 1;

#pragma cap parallel
						{
#pragma acc parallel loop
#pragma cap map threadblock([0:5]) thread([0:6][0:7][0:8][0:9][0:10][0:11][0:12][0:13][0:14][0:15][0:16][0:17][0:18][0:19][0:20][0:21][0:22])
#pragma cap loop id(5)
							for(int j = start_index + 1; j < COLS; j+=2)
								//for(int j = 0; j < COLS/2-(start_index+1)/2; j++)
							{
								//获取需要进行正交变换的两列
								//int col_p = rotate_col_idx[(j*2+start_index+1) - 1];
								//int col_q = rotate_col_idx[(j*2+start_index+1)];
								int col_p = rotate_col_idx[j - 1];
								int col_q = rotate_col_idx[j];
								double  real1 = 0.0f;
								double  imag1 = 0.0f;

								//void get_cols(TYPE *src, TYPE *dst ,int col)
								//get_cols(A_H, ci+j/2*ROWS*2, col_p);
#pragma cap loop id(6)
#pragma acc loop 
								for(int k = 0; k < ROWS; k++) 
								{
									(ci+j/2*ROWS*2)[k]     = A_H[col_p * ROWS + k    ];
									(ci+j/2*ROWS*2)[COLS + k] = A_H[COLS * ROWS + col_p * ROWS + k];
								}
								//get_cols(A_H, cj+j/2*ROWS*2, col_q);
#pragma cap loop id(7)
#pragma acc loop 
								for(int k = 0; k < ROWS; k++) 
								{
									(cj+j/2*ROWS*2)[k]     = A_H[col_q * ROWS + k    ];
									(cj+j/2*ROWS*2)[COLS + k] = A_H[COLS * ROWS + col_q * ROWS + k];
								}
								//get_cols(V_H, vi+j/2*ROWS*2, col_p);
#pragma cap loop id(8)
#pragma acc loop 
								for(int k = 0; k < ROWS; k++) 
								{
									(vi+j/2*ROWS*2)[k]     = V_H[col_p * ROWS + k    ];
									(vi+j/2*ROWS*2)[COLS + k] = V_H[COLS * ROWS + col_p * ROWS + k];
								}
								//get_cols(V_H, vj+j/2*ROWS*2, col_q);
#pragma cap loop id(9)
#pragma acc loop 
								for(int k = 0; k < ROWS; k++) 
								{
									(vj+j/2*ROWS*2)[k]     = V_H[col_q * ROWS + k    ];
									(vj+j/2*ROWS*2)[COLS + k] = V_H[COLS * ROWS + col_q * ROWS + k];
								}

								int skip_trans = 0;

#pragma cap loop id(10) reduction(+:real1,imag1)
#pragma acc loop reduction(+:real1,imag1)
								for(int k = 0; k < ROWS; k++)
								{
									real1 += (double)(ci+j/2*ROWS*2)[k] * (cj+j/2*ROWS*2)[k]     + (ci+j/2*ROWS*2)[COLS + k] * (cj+j/2*ROWS*2)[COLS + k];
									imag1 += (double)(ci+j/2*ROWS*2)[k] * (cj+j/2*ROWS*2)[COLS + k] - (ci+j/2*ROWS*2)[COLS + k] * (cj+j/2*ROWS*2)[k];
								}
								value[j/2] = (double)sqrt((double)real1 * (double)real1 + (double)imag1 * (double)imag1);

								if(value[j/2] < THRESHOLD)
									skip_trans = 1;

								if(skip_trans ==0)
								{
									pass[0] = 0;

									//double inner_ri = part_product(ci+j/2*ROWS*2, cj+j/2*ROWS*2, 1, 0);
									//double part_product(TYPE *src1, TYPE *src2, int is_src1_real, int is_src2_real)
									double result1 = 0.0f;
									double result2 = 0.0f;
									double result3 = 0.0f;
									double result4 = 0.0f;
									double result5 = 0.0f;
									double result6 = 0.0f;
									double result7 = 0.0f;
									double result8 = 0.0f;
#pragma cap loop id(11) reduction(+:result1)
#pragma acc loop reduction(+:result1) 
									for(int k = 0; k < ROWS; k++)
										result1 += (double)(ci+j/2*ROWS*2)[k] * (cj+j/2*ROWS*2)[k + COLS];
									double inner_ri = result1;
									//double inner_ir = part_product(ci+j/2*ROWS*2, cj+j/2*ROWS*2, 0, 1);
#pragma cap loop id(12) reduction(+:result2)
#pragma acc loop reduction(+:result2) 
									for(int k = 0; k < ROWS; k++)
										result2 += (double)(ci+j/2*ROWS*2)[k + COLS] * (cj+j/2*ROWS*2)[k];
									double inner_ir = result2;
									//double inner_rr = part_product(ci+j/2*ROWS*2, cj+j/2*ROWS*2, 1, 1);
#pragma cap loop id(13) reduction(+:result3)
#pragma acc loop reduction(+:result3) 
									for(int k = 0; k < ROWS; k++)
										result3 += (double)(ci+j/2*ROWS*2)[k] * (cj+j/2*ROWS*2)[k];
									double inner_rr = result3;
									//double inner_ii = part_product(ci+j/2*ROWS*2, cj+j/2*ROWS*2, 0, 0);
#pragma cap loop id(14) reduction(+:result4)
#pragma acc loop reduction(+:result4) 
									for(int k = 0; k < ROWS; k++)
										result4 += (double)(ci+j/2*ROWS*2)[k + COLS] * (cj+j/2*ROWS*2)[k + COLS];
									double inner_ii = result4;

									double a = (double)inner_ri - (double)inner_ir;
									double b = (double)inner_rr + (double)inner_ii;

									double s_a2b2 = (double)sign(b) * sqrt(a * a + b * b);
									double sin_alpha = a / s_a2b2;
									double cos_alpha = b / s_a2b2;
									double m = -1 * (b * cos_alpha + a * sin_alpha);

									//double inner_rrj = part_product(cj+j/2*ROWS*2, cj+j/2*ROWS*2, 1, 1);
#pragma cap loop id(15) reduction(+:result5)
#pragma acc loop reduction(+:result5) 
									for(int k = 0; k < ROWS; k++)
										result5 += (double)(cj+j/2*ROWS*2)[k] * (cj+j/2*ROWS*2)[k];
									double inner_rrj = result5;
									//double inner_iij = part_product(cj+j/2*ROWS*2, cj+j/2*ROWS*2, 0, 0);
#pragma cap loop id(16) reduction(+:result6)
#pragma acc loop reduction(+:result6) 
									for(int k = 0; k < ROWS; k++)
										result6 += (double)(cj+j/2*ROWS*2)[k + COLS] * (cj+j/2*ROWS*2)[k + COLS];
									double inner_iij = result6;
									//double inner_rri = part_product(ci+j/2*ROWS*2, ci+j/2*ROWS*2, 1, 1);
#pragma cap loop id(17) reduction(+:result7)
#pragma acc loop reduction(+:result7) 
									for(int k = 0; k < ROWS; k++)
										result7 += (double)(ci+j/2*ROWS*2)[k] * (ci+j/2*ROWS*2)[k];
									double inner_rri = result7;
									//double inner_iii = part_product(ci+j/2*ROWS*2, ci+j/2*ROWS*2, 0, 0);
#pragma cap loop id(18) reduction(+:result8)
#pragma acc loop reduction(+:result8) 
									for(int k = 0; k < ROWS; k++)
										result8 += (double)(ci+j/2*ROWS*2)[k + COLS] * (ci+j/2*ROWS*2)[k + COLS];
									double inner_iii = result8;

									double n = (double)0.5 * (inner_rrj + inner_iij - inner_rri - inner_iii);
									double w = (double)sign(n) * m / sqrt(m*m + n*n);

									double sin_x = w/sqrt(2 * (1 + sqrt(1 - w * w)));
									double cos_x = sqrt(1 - sin_x * sin_x);

									//update_data(A_H, ci+j/2*ROWS*2, cj+j/2*ROWS*2, sin_x, cos_x, sin_alpha, cos_alpha, col_p,  1); 
									double real2 = 0.0f;
									double imag2 = 0.0f;
									double real3 = 0.0f;
									double imag3 = 0.0f;
									double real4 = 0.0f;
									double imag4 = 0.0f;
									double real5 = 0.0f;
									double imag5 = 0.0f;
#pragma cap loop id(19)
#pragma acc loop 
									for(int k = 0; k < ROWS; k++)
									{
										real2 = (ci+j/2*ROWS*2)[k    ] * cos_x + 1 * (cj+j/2*ROWS*2)[k    ] * cos_alpha * sin_x + (cj+j/2*ROWS*2)[k +COLS] * sin_alpha * sin_x;
										imag2 = (ci+j/2*ROWS*2)[k + COLS] * cos_x + 1 * (cj+j/2*ROWS*2)[k + COLS] * cos_alpha * sin_x - (cj+j/2*ROWS*2)[k   ] * sin_alpha * sin_x;

										A_H[col_p * COLS + k]     = real2;
										A_H[COLS * ROWS + col_p * COLS + k] = imag2; 
									}
									//update_data(A_H, cj+j/2*ROWS*2, ci+j/2*ROWS*2, sin_x, cos_x, sin_alpha, cos_alpha, col_q, -1); 
#pragma cap loop id(20)
#pragma acc loop 
									for(int k = 0; k < ROWS; k++)
									{
										real3 = (cj+j/2*ROWS*2)[k    ] * cos_x + (-1) * (ci+j/2*ROWS*2)[k    ] * cos_alpha * sin_x + (ci+j/2*ROWS*2)[k +COLS] * sin_alpha * sin_x;
										imag3 = (cj+j/2*ROWS*2)[k + COLS] * cos_x + (-1) * (ci+j/2*ROWS*2)[k + COLS] * cos_alpha * sin_x - (ci+j/2*ROWS*2)[k   ] * sin_alpha * sin_x;

										A_H[col_q * COLS + k]     = real3;
										A_H[COLS * ROWS + col_q * COLS + k] = imag3; 
									}
									//update_data(V_H, vi+j/2*ROWS*2, vj+j/2*ROWS*2, sin_x, cos_x, sin_alpha, cos_alpha, col_p,  1); 
#pragma cap loop id(21)
#pragma acc loop 
									for(int k = 0; k < ROWS; k++)
									{
										real4 = (vi+j/2*ROWS*2)[k    ] * cos_x + 1 * (vj+j/2*ROWS*2)[k    ] * cos_alpha * sin_x + (vj+j/2*ROWS*2)[k +COLS] * sin_alpha * sin_x;
										imag4 = (vi+j/2*ROWS*2)[k + COLS] * cos_x + 1 * (vj+j/2*ROWS*2)[k + COLS] * cos_alpha * sin_x - (vj+j/2*ROWS*2)[k   ] * sin_alpha * sin_x;

										V_H[col_p * COLS + k]     = real4;
										V_H[COLS * ROWS + col_p * COLS + k] = imag4; 
									}
									//update_data(V_H, vj+j/2*ROWS*2, vi+j/2*ROWS*2, sin_x, cos_x, sin_alpha, cos_alpha, col_q, -1); 
#pragma cap loop id(22)
#pragma acc loop 
									for(int k = 0; k < ROWS; k++)
									{
										real5 = (vj+j/2*ROWS*2)[k    ] * cos_x + (-1) * (vi+j/2*ROWS*2)[k    ] * cos_alpha * sin_x + (vi+j/2*ROWS*2)[k +COLS] * sin_alpha * sin_x;
										imag5 = (vj+j/2*ROWS*2)[k + COLS] * cos_x + (-1) * (vi+j/2*ROWS*2)[k + COLS] * cos_alpha * sin_x - (vi+j/2*ROWS*2)[k   ] * sin_alpha * sin_x;

										V_H[col_q * COLS + k]     = real5;
										V_H[COLS * ROWS + col_q * COLS + k] = imag5; 
									}
								}

								rotate_col_idx[j - 1] = col_q;
								rotate_col_idx[j    ] = col_p;
							}
						}
					}
				}

				iteration--;
				if(pass[0] == 1)
					break;
			}
			gettimeofday(&mid1, NULL); 

#pragma cap parallel //
			{
#pragma acc parallel loop
#pragma cap map threadblock([0:2]) thread([0:3][0:4])
#pragma cap loop id(2)
				for(int i = 0; i < COLS; i++)
				{
					double  real = 0.0f;
					double  imag = 0.0f;
#pragma cap loop id(3)
#pragma acc loop 
					for(int k = 0; k < ROWS; k++) 
					{
						(ci+i*ROWS*2)[k]     = A_H[i * ROWS + k    ];
						(ci+i*ROWS*2)[COLS + k] = A_H[COLS * ROWS + i * ROWS + k];
					}

#pragma cap loop id(4) reduction(+:real,imag)
#pragma acc loop reduction(+:real,imag)
					for(int l = 0; l < ROWS; l++)
					{
						real += (double)(ci+i*ROWS*2)[l] * (ci+i*ROWS*2)[l]     + (ci+i*ROWS*2)[COLS + l] * (ci+i*ROWS*2)[COLS + l];
						imag += (double)(ci+i*ROWS*2)[l] * (ci+i*ROWS*2)[COLS + l] - (ci+i*ROWS*2)[COLS + l] * (ci+i*ROWS*2)[l];
					}

					TYPE norm_A = sqrt((double)sqrt((double)real * (double)real + (double)imag * (double)imag));
					S_H[i] = norm_A;
				}
			}
			gettimeofday(&mid2, NULL);

#pragma cap parallel //
			{
#pragma acc parallel loop collapse(2) 
#pragma cap map threadblock([0:1][1:0]) thread([0:1][1:0])
#pragma cap loop id(0)
				for(int j= 0; j < COLS; j++)
#pragma cap loop id(1)
					for(int i = 0; i < ROWS; i++) 
					{
						B_H[j * ROWS + i] = A_H[j * ROWS + i] / S_H[j];
						B_H[COLS * ROWS + j * ROWS + i] = A_H[COLS * ROWS + j * ROWS + i] / S_H[j];
					}
			}
			gettimeofday(&end_calc, NULL);

		}
		gettimeofday(&end_total, NULL);

		printf("%lf %lf %lf %lf\n", A_H[0], B_H[0], V_H[0], S[0]);

		printf("Used %d iters\n", MAX_ITERATIONS - iteration);
		printf("Total: %ld ms\n", (end_total.tv_sec - begin_total.tv_sec) * 1000 + (end_total.tv_usec - begin_total.tv_usec)/1000);             
		printf("V: %ld ms\n", (mid1.tv_sec - begin_calc.tv_sec) * 1000 + (mid1.tv_usec - begin_calc.tv_usec)/1000 );                            
		printf("S: %ld ms\n", (mid2.tv_sec - mid1.tv_sec) * 1000 + (mid2.tv_usec - mid1.tv_usec)/1000 );                                         
		printf("B: %ld ms\n", (end_calc.tv_sec - mid2.tv_sec) * 1000 + (end_calc.tv_usec - mid2.tv_usec)/1000 );   
		printf("Env1: %ld ms\n", (end_total.tv_sec - end_calc.tv_sec) * 1000 + (end_total.tv_usec - end_calc.tv_usec)/1000 );   
		printf("Env2: %ld ms\n", (begin_calc.tv_sec - begin_total.tv_sec) * 1000 + (begin_calc.tv_usec - begin_total.tv_usec)/1000 );   
	}


	for(int i = 0 ; i < ROWS ; i ++)
		for(int j = 0 ; j < COLS ; j ++)
		{
			A[i * COLS * 2 + j * 2] = A_H[j * ROWS + i];
			A[i * COLS * 2 + j * 2 + 1] = A_H[COLS * ROWS + j * ROWS + i];
			B[i * COLS * 2 + j * 2] = B_H[j * ROWS + i];
			B[i * COLS * 2 + j * 2 + 1] = B_H[COLS * ROWS + j * ROWS + i];
			V[i * COLS * 2 + j * 2] = V_H[j * ROWS + i];
			V[i * COLS * 2 + j * 2 + 1] = V_H[COLS * ROWS + j * ROWS + i];
		}

	for(int i = 0 ; i < COLS ; i ++)
		S[i] = S_H[i];

	delete rotate_col_idx;
	delete A_H;
	delete B_H;
	delete V_H;
	delete S_H;
	delete ci;
	delete cj;
	delete vi;
	delete vj;
}

int main()
{
	TYPE *A = new TYPE[ROWS * COLS * 2]; 
	TYPE *B = new TYPE[ROWS * COLS * 2];
	TYPE *S = new TYPE[COLS];          
	TYPE *V = new TYPE[ROWS * COLS * 2]; 

	FILE* fp = fopen("./data/Matrix_input_256A_m.txt", "r");
	if(fp == NULL)
	{
		printf("matrix input A is not found\n");
		return 1;
	}
	TYPE temp;
	for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			fscanf(fp, "%lf", &temp);
			A[i * COLS + j] = temp;
		}

		for(int j = 0; j < COLS; j++)
		{
			fscanf(fp, "%lf", &temp);
			A[ROWS * COLS + i * COLS + j] = temp;
		}
	}
	fclose(fp);

	for(int i = 0; i < ROWS; i++)
		for(int j = 0; j < COLS * 2; j++)
		{
			if(j == 2 * i)
				V[i * COLS * 2 + j] = 1; 
			else
				V[i * COLS * 2 + j] = 0; 
		}


	for(int i =0; i < COLS; i++)
		S[i] = 0;

	svd(A, B, S, V);

	printf("\n\n");

	TYPE *A1 = new TYPE[ROWS * COLS * 2]; 
	TYPE *V1 = new TYPE[ROWS * COLS * 2];
	TYPE *S1 = new TYPE[COLS];          

	FILE* fp1 = fopen("./data/Matrix_out_A256.txt", "r");
	if(fp1 == NULL)
	{
		printf("matrix output A is not found\n");
		return 1;
	}
	for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			fscanf(fp1, "%lf", &temp);
			A1[i * COLS * 2 + j * 2] = temp;
		}

		for(int j = 0; j < COLS; j++)
		{
			fscanf(fp1, "%lf", &temp);
			A1[i * COLS * 2 + j * 2 + 1] = temp;
		}
	}
	fclose(fp1);

	printf("compare A\n") ;

	bool result = is_matrix_equal(A, A1);
	if(result ==1)
		printf("success\n");

	FILE* fp2 = fopen("./data/Matrix_out_V256.txt", "r");
	if(fp2 == NULL)
	{
		printf("matrix output V is not found\n");
		return 1;
	}
	for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			fscanf(fp2, "%lf", &temp);
			V1[i * COLS * 2 + j * 2] = temp;
		}

		for(int j = 0; j < COLS; j++)
		{
			fscanf(fp2, "%lf", &temp);
			V1[i * COLS * 2 + j * 2 + 1] = temp;
		}
	}
	fclose(fp2);

	printf("compare V\n");

	result = is_matrix_equal(V, V1);
	if(result ==1)
		printf("success\n"); 


	FILE* fp3 = fopen("./data/Matrix_out_S256.txt", "r");
	if(fp3 == NULL)
	{
		printf("matrix output S is not found\n");
		return 1;
	}
	for(int j = 0; j < COLS; j++)
	{
		fscanf(fp3, "%lf", &temp);
		S1[j] = temp;
	}

	fclose(fp3);

	printf("compare S\n");

	result = is_vector_equal(S, S1);
	if(result ==1)
		printf("success\n");

	delete A;
	delete B;
	delete S;
	delete V;

	return 0;
}
