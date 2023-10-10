/*
 * Creator: Fasih Hasan Khan
 * Date: 10/10/23
 * Description: multiply 2 matrices
 */

#include <stdio.h>

void showMatrix(int *mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%-4d ", *(mat + i*n + j));
        }
        printf("\n");
    }
} // end showMatrix(int *, int)

void takeInput(int *mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &(*(mat + i*n + j)));
        }
    }
} // end takeInput(int *)

void multiplyMatrix(int *mat1, int *mat2, int *ans, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                *(ans + i*n + j) += *(mat1 + i*n + k) * *(mat2 + k*n + j);
            }
        }
    }
}

int main() {
    int matrix1[100], matrix2[100], ans[100] = {0};

    int n;
    do {
        printf("Enter dimension (square matrix): ");
        scanf("%d", &n);
    } while (n > 100 || n < 1);

    printf("Matrix 1:\n");
    takeInput(matrix1, n);
    printf("Matrix 2:\n");
    takeInput(matrix2, n);

    multiplyMatrix(matrix1, matrix2, ans, n);
    showMatrix(ans, n);

    return 0;
} // end main()
