/*
 * Creator: Fasih Hasan Khan
 * Date: 10/10/23
 * Description: Rotate the elements of an array about a pivot 'd'
 */

#include <stdio.h>

int main() {
    int arr[100], N, d;
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

    for (int k = d; k > 0; k--) {
        for (int j = k; j < N; j++) {
            printf("%d\n", arr[j]);
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
        }
    }
    
    for (int n = 0; n < N; n++) {
        printf("%d ", arr[n]);
    }

    return 0;
} // end main()
