/*
 * Creator: Fasih Hasan Khan
 * Date: 15/10/23
 * Description: creates an n x n grid, takes user input for each 3x3 matrix within. 
 *              prints out a matrix with highest value of each matrix
 */

#include <stdio.h>
#include <math.h>

int *getMaxLocalMatrix(int *arr, int n) {
	int count = 0, max = 1 << 31, maxLocal[1000];

	// initialize maxLocal with 0 (not really needed but good practice)
	for (int i = 0; i < (n - 2)*(n - 2); i++) maxLocal[i] = 0;

	// main loop for the array passed
	// i and j are for the sake of user and keeping track of the amount of the 3x3 matrices
	// k is for the main array
	for (int i = 0, j = 0, k = 0; k < n*n; k++) {
		printf("Enter element in matrix %d at [%d][%d]: ", count + 1, i, j);
		scanf("%d", &arr[k]);
		j++;

		// checking max value of local matrix
		if (arr[k] > max) { 
			max = arr[k];
			maxLocal[count] = max;
		}

		// moving to next matrix if both at end
		if (i > 1 && j > 2) {
			count++;
			i = 0, j = 0, max = 1 << 31;
		}
		// moving to next row
		if (j > 2) {
			j = 0;
			i++;
		}
	}

	// matrices in an n x n grid will have square number of 3 x 3 matrices within
	int m = (int) sqrt(count);

	printf("\nMax Local:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			printf("%-3d ", *(maxLocal + i*m + j));
		}
		printf("\n");
	}
} // end getMaxLocalMatrix(int *, int)

int main() {
	int arr[1000];
	int n;

	do {
		printf("Enter grid size (n has to be divisible by 3): ");
		scanf("%d", &n);
	} while (n % 3)
	
	getMaxLocalMatrix(arr, n);

	return 0;
} // end main()
