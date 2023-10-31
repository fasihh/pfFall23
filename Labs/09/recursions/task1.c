/*
 * Creator: Fasih Hasan Khan
 * Desc: finding factorial using recursions
 * Date: 31/10/23
 */

#include <stdio.h>

int factorial(int n, int ans)
{
    // general case
    if (n) {
        return factorial(n-1, ans*n);
    }

    // base case when n is 0
    return ans;
}

int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("%d", factorial(n, 1));
    return 0;
}