/*
 *  Creator: Fasih Hasan
 *  Date: 10/3/2023
 *  Description: Prints numbers in english below 10 and then prints either even or odd
 */ 


#include <stdio.h>

int main() {
    int a, b;
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    while (a <= b) {
        switch(a) {
            case 1:
                printf("One ");
                break;
            case 2:
                printf("Two ");
                break;
            case 3:
                printf("Three ");
                break;
            case 4:
                printf("Four ");
                break;
            case 5:
                printf("Five ");
                break;
            case 6:
                printf("Six ");
                break;
            case 7:
                printf("Seven ");
                break;
            case 8:
                printf("Eight ");
                break;
            case 9:
                printf("Nine ");
                break;
            default:
                // checking last bit. if off then even otherwise odd.
                (a & 1) ? printf("Odd ") : printf("Even ");
        }
        a++;
    }

    return 0;
} // end main()