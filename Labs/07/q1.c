/*
 * Creator: Fasih Hasan Khan
 * Date: 10/10/23
 * Description: Divide without '/' operator
 */

#include <stdio.h>

int divide(int, int);

int main() {
    int num1, num2;
    printf("Enter num1/num2: ");
    scanf("%d/%d", &num1, &num2);

    printf("ans: %d", divide(num1, num2));

    return 0;
} // end main()

int divide(int num1, int num2) {
    int c = 0;
    // subtracting num1 with num2 until 0
    while (num1 > 0) {
        if (num1 < num2) break;
        // the amount of times num1 needs to be subtracted by num2
        c++;
        num1 -= num2;
    }
    return c;
} // end divide(int, int)
