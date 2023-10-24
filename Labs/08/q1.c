/*
 * Creator: Fasih Hasan Khan
 * Date: 24/10/23
 * Desc: swaps the value of the 2 integers
 */

#include <stdio.h>

void swapInteger(int *num1, int *num2) {
    // create a temp to swap
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
} // swapInteger(int *, int *)

int main() {
    int num1, num2;

    printf("Enter num1: ");
    scanf("%d", &num1);
    printf("Enter num2: ");
    scanf("%d", &num2);

    // show num before swap
    printf("Before swap\nnum1: %d\nnum2: %d\n\n", num1, num2);
    swapInteger(&num1, &num2);
    printf("After swap\nnum1: %d\nnum2: %d", num1, num2);

    return 0;
} // main()
