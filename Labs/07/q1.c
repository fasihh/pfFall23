/*
 * Creator: Fasih Hasan Khan
 * Date: 10/10/23
 * Description: Divide without '/' operator
 */

#include <stdio.h>

int main() {
    int num1, num2;
    printf("Enter num1/num2: ");
    scanf("%d/%d", &num1, &num2);

    int c = 0;
    // subtracting num1 with num2 until 0
    while (num1 > 0) {
        // the amount of times num1 needs to be subtracted by num2
        c++;
        num1 -= num2;
    }

    printf("ans: %d", c);

    return 0;
} // end main()
