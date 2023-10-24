/*
 * Creator: Fasih Hasan Khan
 * Date: 24/10/23
 * Desc: calculates the value of the 2 integers for given operation
 */

#include <stdio.h>

int calculator(int num1, int num2, char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return (num2) ? num1 / num2 : ~(1 << 31);
    }
} // calculator(int, int, char)

int main() {
    int num1, num2;
    char op;

    printf("Enter num1: ");
    scanf("%d", &num1);
    printf("Enter num2: ");
    scanf("%d", &num2);
    printf("Enter operation: ");
    scanf(" %c", &op);

    printf("answer: %d", calculator(num1, num2, op));

    return 0;
} // main()