/*
 *  Creator: Fasih Hasan
 *  Date: 10/3/2023
 *  Description: Prints fibonacci until number in series is greater than 10k
 *               and print the sum of numbers that are divisible by 3, 5 or 7
 */ 


#include <stdio.h>

int main() {
    int n1 = 1, n2 = 0, n3 = 1 , total = 0;

    for (int n = 0; n < 999; n++) {
        n3 = n1 + n2;
        if (n3 > 10000) break;

        if (!(n3 % 3) || !(n3 % 5) || !(n3 % 7)) total += n3;
        printf("%d ", n3);
        n1 = n2;
        n2 = n3;
    }

    printf("\n%d", total);

    return 0;
} // end main()