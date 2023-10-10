/*
 * Creator: Fasih Hasan Khan
 * Date: 10/10/23
 * Description: Count the sum of the digits
 */

#include <stdio.h>

int main() {
    int num;

    printf("Enter number: ");
    scanf("%d", &num);

    int sum = 0;
    // run until num is 0
    while (num) {
        sum += num % 10;
        num /= 10;
    }

    printf("sum: %d", sum);
    return 0;
} // end main()
