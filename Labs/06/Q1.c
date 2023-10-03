/*
 *  Creator: Fasih Hasan
 *  Date: 10/3/2023
 *  Description: Checks if perfect number or not
 */ 

#include <stdio.h>

int main() {
    int n, total = 0;

    printf("Enter any number: ");
    scanf("%d", &n);

    int i = 0;
    while (++i < n) {
        if (!(n % i)) {
            // if divisible then add to total
            total += i;
        }
    }
    
    (total == n) ? printf("Perfect Number") : printf("Not Perfect Number");

    return 0;
} // end main()
