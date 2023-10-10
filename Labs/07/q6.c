/*
 * Creator: Fasih Hasan Khan
 * Date: 10/10/23
 * Description: check the frequency of number
 */

#include <stdio.h>

int main() {
    int arr[100], N, d;
    int freq[100] = {0};
    do {
        printf("Enter elements: ");
        scanf("%d", &N);
    } while (N > 100 || N < 1);

    for (int i = 0; i < N; i++) {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < N; i++) {
        freq[arr[i]]++;
    }

    for (int n = 0; n < 100; n++) {
        if (!freq[n]) continue;
        printf("Frequency of %d = %d\n", n, freq[n]);
    }


    return 0;
} // end main()
