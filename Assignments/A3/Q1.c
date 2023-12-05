/*
 * Creator: Fasih Hasan
 *    Date: 2/12/23
 *    Desc: Creates a matrix from the max values of a matrix's submatrix
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 100

int **create_matrix(int n)
{
	int **mat = (int **)malloc(sizeof(int *) * n);
	int *block = (int *)malloc(sizeof(int) * n*n);

	for (int i = 0; i < n; i++) mat[i] = block + i*n;

	return mat;
}

void read_file_matrix(FILE *fp, int **mat, int n)
{
	char buffer[MAX_BUFFER_SIZE];

	for (int i = 0; !feof(fp) && i < n; i++) {
		fgets(buffer, MAX_BUFFER_SIZE, fp);
		buffer[strcspn(buffer, "\n")] = 0;

		char *num = strtok(buffer, " ");
		for (int j = 0; num != NULL && j < n; j++) {
			mat[i][j] = atoi(num);

			num = strtok(NULL, " ");
		}
	}
}

void print_matrix(int **mat, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%-3d ", mat[i][j]);
		}
		printf("\n\n");
	}
}

int max(int **mat, int i, int j, int n)
{
	int max_val = 1 << 31;

	for (int k = i; k < i + n/2 && k < n; k++) {
		for (int q = j; q < j + n/2 && q < n; q++) {
			max_val = (mat[k][q] > max_val) ? mat[k][q] : max_val;
		}
	}

	return max_val;
}

int **get_sub_matrix(int **mat, int n) 
{	
	int **sub_mat = create_matrix(n/2);

	for (int i = 0; i < n; i += 2) {
		for (int j = 0; j < n; j += 2) {
			sub_mat[i/2][j/2] = max(mat, i, j, n);
		}
	}

	return sub_mat;
}

int main(int argc, char const *argv[])
{
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

	free(sub_max);
	free(*mat);
	free(mat);

	return 0;
}
