/*
 * Creator: Fasih Hasan Khan
 * Date: 19/11/23
 * Description: create 2 2d arrays by different allocation methods and calculate their time for a given function
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **create_arr_1(int M, int N)
{
	int **arr = (int **)malloc(sizeof(int *) * M);
	for (int i = 0; i < M; i++) arr[i] = (int *)malloc(sizeof(int) * N);

	return arr;
} // end create_arr_1()

int **create_arr_2(int M, int N)
{
	int *block = (int *)malloc(sizeof(int) * M * N);

	int **arr = (int **)malloc(sizeof(int *) * M);

	for (int i = 0, j = 0; i < M; i++, j += N) {
		// assigning pointer of each row start to arr pointer
		arr[i] = &block[j];
	}

	return arr;
} // end create_arr_2()

double time_arr(int **arr, int N, int M)
{
	clock_t time = clock();

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] *= 3;
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] /= 2;
		}
	}

	return (double) (clock() - time)/CLOCKS_PER_SEC;
} // end time_arr()

int main()
{
	int M = 1000, N = 1000;

	printf("Enter M: ");
	scanf("%d", &M);
	printf("Enter N: ");
	scanf("%d", &N);

	int **arr_1 = create_arr_1(M, N);
	int **arr_2 = create_arr_2(M, N);

	printf("Time for arr_1: %.fms\n", time_arr(arr_1, M, N) * 1000);
	printf("Time for arr_2: %.fms\n", time_arr(arr_2, M, N) * 1000);

	return 0;
} // end main()
