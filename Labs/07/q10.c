/*
 * Creator: Fasih Hasan Khan
 * Date: 10/10/23
 * Description: check sum of elements and give subarray if it exists
 */

#include <stdio.h>

int input(int *arr) {
    int n;
    do {
        printf("Enter size of array: ");
        scanf("%d", &n);
    } while (n > 99 || n < 1);

    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &(*(arr + i)));
    }
    return n;
} 

void subarray(int *arr, int n, int s) {
    for (int i = 0, sum; i < n; i++) {
        sum = 0;
        for (int j = i; j < n && sum < s; j++) {
            sum += arr[j];
            if (sum == s) {
                printf("%d to %d", i, j);
                return;
            }
        }
    }
    printf("No subarray");
    return;
} 

int main() {
    int arr[100] = {0};
    int s;
    int n = input(arr);

    printf("Enter 's': ");
    scanf("%d", &s);

    subarray(arr, n, s);

    return 0;
} // end main()
