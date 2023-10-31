/*
 * Creator: Fasih Hasan Khan
 * Desc: Printing fibonacci series using recursions
 * Date: 31/10/23
 */

#include <stdio.h>

void fibonacci(int a, int b, int r, int n)
{
    // general case
    if (n) {
        printf("%d ");
        fibonacci(b, r, r+b, n-1);
    }

    // base case is when n is 0
    return;
} // end fibonacci(int, int, int, int)

int main()
{
    int n;
    printf("Enter length of fibonacci: ");
    scanf("%d", &n);
    fibonacci(1, 0, 1, n);
    return 0;
} // end main()