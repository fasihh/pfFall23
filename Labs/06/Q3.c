/*
 *  Creator: Fasih Hasan
 *  Date: 10/3/2023
 *  Description: Prints GCD and LCM of 2 numbers
 */ 


#include <stdio.h>

int main() {
    int num1, num2, n;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    // assign smaller number to n
    if (num1 > num2) {
        n = num1 - num2;
    } else {
        n = num2 - num1;
    }

    // check divisibility
    while (num1 % n || num2 % n) {
        n--;
    }

    printf("GCD: %d\nLCM: %d", n, (num1 * num2) / n /* formula for lcm */);

    return 0;
} // end main()