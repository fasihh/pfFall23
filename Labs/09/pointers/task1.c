/*
 * Creator: Fasih Hasan Khan
 * Desc: Swaping values of 2 variables using a function and a pointer
 * Date: 31/10/23
 */

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
} // end swap(int, int)

int main()
{
    int a = 2, b = 5;
    printf("a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("a = %d, b = %d", a, b);
    return 0;
} // end main()
