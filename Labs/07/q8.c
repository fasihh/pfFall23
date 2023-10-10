/*
 * Creator: Fasih Hasan Khan
 * Date: 10/10/23
 * Description: Sort an array in ascending order
 */

#include <stdio.h>

int main() {
    int arr[100], N, d;

    // defining
    do {
        printf("Enter elements: ");
        scanf("%d", &N);
    } while (N > 100 || N < 1);

    // input
    for (int i = 0; i < N; i++) {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    // insertion sort
    for (int i = 0; i < N; i++) {
        int j = i;
        while (arr[j] < arr[j - 1] && j > 0) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }

    // output
    for (int n = 0; n < N; n++) {
        printf("%d ", arr[n]);
    }

    return 0;
} // end main()
