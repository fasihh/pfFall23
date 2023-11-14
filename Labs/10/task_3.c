/*
 * Creator: Fasih Hasan Khan
 * Date: 14/11/23
 * Description: dynamically create a 2d array and initialize it with prime numbers
 */

#include <stdio.h>
#include <stdlib.h>

int is_prime(int n)
{
	// check if prime number
	for (int i = 2; i*i <= n; i++) if (!(n % i)) return 0;
	return 1;
} // end is_prime()

void show_arr(int** arr, int x, int y)
{
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) printf("%-4d", arr[i][j]);
		printf("\n");
	}
} // end show_arr()

int **create_arr(int x, int y)
{
	// memory allocation for array
	int **arr = (int **)malloc(sizeof(int *) * y);
	for (int i = 0; i < y; i++) arr[i] = (int *)malloc(sizeof(int) * x);

	// initialize with prime numbers
	for (int i = 0, num = 2; i < y; i++) {
		for (int j = 0; j < x; j++) {
			for(;!is_prime(num);num++);
			arr[i][j] = num++;
		}
	}

    return arr; // return double pointer to array
} // end create_arr()

void free_arr(int **arr, int y)
{
	// free all pointers
	for (int i = 0; i < y; i++) free(arr[i]);
	free(arr);
} // end free_arr()

int main()
{
	int x = 5, y = 5, ** arr = create_arr(x, y);
	show_arr(arr, x, y);
	free_arr(arr, y);

	return 0;
} // end main()
