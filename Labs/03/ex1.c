/* 
 * Fasih Hasan
 * Description: Calculator
 */

#include <stdio.h>

int main() {
	int num1, num2;
	char userChoice;

	printf("Operations -> '+', '-', '*', '/' OR press 'E' to exit.\n");

	// infinite loop until user exits
	do {
		// userChoice
		printf("Input choice: ");
		scanf(" %c", &userChoice);

		// exit
		if (userChoice == 'e' || userChoice == 'E') {
			break;
		};

		// num1
		printf("Input first number: ");
		scanf("%d", &num1);

		// num2
		printf("Input second number: ");
		scanf("%d", &num2);

		if (userChoice == '+') {
			printf("Answer: %d\n", num1 + num2);
		} else if (userChoice == '-') {
			printf("Answer: %d\n", num1 - num2);

		} else if (userChoice == '*') {
			printf("Answer: %d\n", num1 * num2);

		} else if (userChoice == '/') {
			printf("Answer: %.1f\n", (float) num1 / num2);
		};
		
	} while(1);
	
	return 0;
}; // end main()
