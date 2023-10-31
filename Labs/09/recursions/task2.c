/*
 * Creator: Fasih Hasan Khan
 * Desc: Multiplying using recursions without *
 * Date: 31/10/23
 */

#include <stdio.h>

int multiply(int n, int m, int ans)
{
    // general case
    if (m) {
        // keep calling function and adding a into answer
        return multiply(n, m-1, ans+n);
    }
    // base case when m is 0
    return ans;
} // end multiply(int, int, int)

int main()
{
    int n, m;
    printf("Enter numbers (nxm): ");
    scanf("%dx%d", &n, &m);
    printf("ans = %d", multiply(n, m, 0));
    return 0;
} // end main()