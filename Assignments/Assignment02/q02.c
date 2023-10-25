/*
 * Creator: Fasih Hasan Khan
 * Date: 25/10/23
 * Desc: finds largest submatrix of 1s
 */

#include <stdio.h>

void show_matrix(int mat[][100], int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) printf("%-*d", n, mat[i][j]);
        printf("\n");
    }
}

int find_largest_square(int mat[][100], int n, int m)
{
    int sq = (n > m) ? m : n;
    
    return sq;
}

int main() 
{
    int n = 4, m = 3;
    int arr[100][100] = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 1, 0},
        {1, 0, 1},
    };
    
    show_matrix(arr, n, m);
    printf("%d", find_largest_square(arr, n, m));

    return 0;
} // main()
