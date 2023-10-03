/*
 *  Creator: Fasih Hasan
 *  Date: 10/3/2023
 *  Description: Printing a pattern without nested loops
 */ 


#include <stdio.h>

int main() {
    int i = -1, n = 6;
    while (i++ < n) {
        if (!(i % 2)) {
            // adding proper padding to space the pattern
            printf("%-2d%-2d%-2d%d\n", i, i, i, i);
        } else {
            // adding proper padding to space the pattern
            printf("%3d%2d\n", i, i);
        }
    }

    return 0;
} // end main()