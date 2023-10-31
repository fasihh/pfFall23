/*
 * Creator: Fasih Hasan Khan
 * Desc: reversing an array using pointers and functions
 * Date: 31/10/23
 */

#include <stdio.h>

void reverse(int *arr, int size)
{
    for (int i = 0; i < size/2; i++) {
        // using pointer notation for all values

        // swap
        int temp = *(arr + i);
        *(arr + i) = *(arr + size-1 - i);
        *(arr + size-1 - i) = temp;
    }
} // end reverse(int *, int)

int main()
{
    int arr[10] = {0}, size = 10;

    for (int i = 0; i < size; i++) {
        printf("Enter element [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nArray\n");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    reverse(arr, size);
    printf("\nReversed array\n");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    return 0;
} // end main()
