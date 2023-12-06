/*
 * Creator: Fasih Hasan
 *    Date: 2/12/23
 *    Desc: Creates a matrix from the max values of a matrix's submatrix
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 100

// dynamic allocation of the matrix
int **create_matrix(int n)
{
	int **mat = (int **)malloc(sizeof(int *) * n);
	int *block = (int *)malloc(sizeof(int) * n*n);

	for (int i = 0; i < n; i++) mat[i] = block + i*n;

	return mat;
} // end create_matrix()

void read_file_matrix(FILE *fp, int **mat, int n)
{
	char buffer[MAX_BUFFER_SIZE];

	for (int i = 0; !feof(fp) && i < n; i++) {
		fgets(buffer, MAX_BUFFER_SIZE, fp);
		buffer[strcspn(buffer, "\n")] = 0; // remove new line

		// read through space separated values in the file
		char *num = strtok(buffer, " ");
		for (int j = 0; num != NULL && j < n; j++) {
			mat[i][j] = atoi(num);

			num = strtok(NULL, " ");
		}
	}
} // end read_file_matrix()

void print_matrix(int **mat, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%-3d ", mat[i][j]);
		}
		printf("\n\n");
	}
} // end print_matrix()

int max(int **mat, int i, int j, int n)
{
	int max_val = 1 << 31;

	// checking for the entire square matrix's positions
	for (int k = 0, check[] = {0,0, 1,0, 1,1, 0,1}; k < 8;)
		max_val = (mat[i+check[k++]][j+check[k++]] > max_val) ? mat[i+check[k-2]][j+check[k-1]] : max_val;

	return max_val;
} // end max()

int **get_sub_matrix(int **mat, int n) 
{	
	int **sub_mat = create_matrix(n/2);

	for (int i = 0; i < n; i += 2) {
		for (int j = 0; j < n; j += 2) {
			// assign max value to the sub matrix
			sub_mat[i/2][j/2] = max(mat, i, j, n);
		}
	}

	return sub_mat;
} // end get_sub_matrix()

int main(int argc, char const *argv[])
{
	printf("Creator: Fasih Hasan Khan\nID: 23K-0018\n\n");
	int n = atoi(argv[1]);

	while (!(n == 2 || n == 4 || n == 8)) {
		printf("Incorrect dimension\nEnter dimension again: ");
		scanf("%d", &n);
	}

	FILE *fp = fopen(argv[2], "r");

	int **mat = create_matrix(n);
	read_file_matrix(fp, mat, n);
	print_matrix(mat, n);

	int **sub_mat = get_sub_matrix(mat, n);
	printf("\nSubmatrix with maximum values:\n");
	print_matrix(sub_mat, n/2);

	return 0;
} // end main()
