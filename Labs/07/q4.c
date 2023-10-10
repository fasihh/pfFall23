/*
 * Creator: Fasih Hasan Khan
 * Date: 10/10/23
 * Description: Check if matrix is symmetric
 */

#include <stdio.h>

int main() {
    int matrix[100][100];
    int d;

    printf("Enter dimension: ");
    scanf("%d", &d);
    
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            int num;
            printf("Enter num: ");
            scanf("%d", &num);
            matrix[i][j] = num;
        }
    }

    for (int c = 0; c < d; c++) {
        for (int r = 0; r < d; r++) {
            if (matrix[c][r] != matrix[r][c]) {
                printf("Array not asymmetric");
                return 0;
            }
        }
    }

    printf("Array is symmetric");

    return 0;
} // end main()
