/*
 * Creator: Fasih Hasan Khan
 * Desc: finding GCD using iterations AND recursions
 * Date: 31/10/23
 */

#include <stdio.h>

int GCD_iter(int a, int b)
{
    // loop until b is 0
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    // return a when b is 0
    return a;
} // end GCD_iter(int, int)

int GCD_rec(int a, int b)
{
    // general case
    if (b) {
        return GCD_rec(b, a % b);
    }

    // base case when b is 0
    return a;
} // end GCD_rec(int, int)

int main()
{
    int n1, n2;
    printf("Enter number 1: ");
    scanf("%d", &n1);
    printf("Enter number 2: ");
    scanf("%d", &n2);
    
    printf("GCD using iterations: %d\n", GCD_iter(n1, n2));
    printf("GCD using recursions: %d", GCD_rec(n1, n2));
    return 0;
} // end main()