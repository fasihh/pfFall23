/*
 * Creator: Fasih Hasan Khan
 * Date: 10/10/23
 * Description: Rotate the elements of an array about a pivot 'd'
 */

#include <stdio.h>

void showArray(int *arr, int N) {
    for (int n = 0; n < N; n++) {
        printf("%d ", *(arr + n));
    }
} // end showArray(int *, int)

void rotateElements(int *arr, int N, int p) {
    for (int k = p - 1, c = 0; k >= 0; k--, c++) {
        for (int j = k; j + 1 < N - c; j++) { 
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
} // end showArray(int *, int, int)

int main() {
    int arr[100] = {1, 2, 3, 4, 5};
    int N = 5, d = 0;
    do {
        printf("Enter elements: ");
        scanf("%d", &N);
    } while (N > 100 || N < 1);

    for (int i = 0; i < N; i++) {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    } 

    printf("\nEnter pivot: ");
    scanf("%d", &d);

    rotateElements(arr, N, d);
    
    showArray(arr, N);

    return 0;
} // end main()
