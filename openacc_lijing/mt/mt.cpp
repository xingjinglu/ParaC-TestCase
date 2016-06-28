#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include<sys/time.h>
#include<time.h>
#include<math.h>
#define Niter 10
struct timeval start_cpu[Niter];
struct timeval end_cpu[Niter];

int main(int argc, char *argv[])
{
	int n = 8192;
	n = argc > 1 ? atoi(argv[1]) : n;
	int N = n * n;

	float *A, *B;

	A = (float*)malloc(N*sizeof(float));
	B = (float*)malloc(N*sizeof(float));

	int i = 0, j = 0;
	double t_calc_start = 0 , t_calc_end = 0, t_ave, t_total_start = 0, t_total_end = 0;
	int check = 1;

	for(i = 0 ; i < n ; i++)
		for(j = 0 ; j < n ; j++)
		{
			A[i * n + j] = i * n + j;
		}

	printf("----MT(%d*%d)----\n", n, n);


	for(int k = 0 ; k < Niter ; k ++)
	{
		gettimeofday(&start_cpu[k], NULL);
#pragma acc data copyin(A[0:n*n]) copyout(B[0:n*n]) 
#pragma cap data copyin(A[0:n*n]) copyout(B[0:n*n]) 
		{
#pragma cap parallel 
#pragma cap map thread([0:1][1:0]) threadblock([0:1][1:0])
#pragma cap loop id(0)
#pragma acc parallel loop collapse(2)
			for(int i = 0; i < n; i++) 
			{
#pragma cap loop id(1)
				for(int j = 0 ;j < n ;j++)
				{
					B[j*n+i] = A[i*n+j];
				}
			}
		}
		gettimeofday(&end_cpu[k], NULL);

		printf("%lf\n", B[10]);
	}

	for(int i = 0 ; i < Niter ; i ++)
	{
		double duration_cpu = 1000 * ((end_cpu[i]).tv_sec - (start_cpu[i]).tv_sec) + ((end_cpu[i]).tv_usec - (start_cpu[i]).tv_usec)/1000.0;
		printf("MT exe time OPENACC:\t%f ms\n", duration_cpu);
	}

	for(i = 0 ; i < n ; i++)
	{
		for(j = 0 ; j < n ; j++)
		{
			if(B[i * n + j] != A[j * n + i])
			{
				check &= 0;
				break;
			}
		}
	}
	if(check)
		printf("OK\n\n");
	else
		printf("Error\n\n");

	free(A);
	free(B);

	return 0;
}
