/*
 * Creator: Fasih Hasan
 * Date: 19/9/23
 * Description: Calculator using switch case
 */

#include <stdio.h>

void main() {
	char op;
	int num1, num2;

	printf("Input operator: ");	
	scanf(" %c", &op);

	printf("Input number 1: ");
	scanf("%d", &num1);

	printf("Input number 2: ");
	scanf("%d", &num2);

	switch (op) {
		case '+':
			printf("answer: %d", num1 + num2);
			break;
		case '-':
			printf("answer: %d", num1 - num2);
			break;	
		case '*':
			printf("answer: %d", num1 * num2);
			break;
		case '/':
			printf("answer: %.4f", (float) num1 / num2);
			break;
	}
} // end main()
