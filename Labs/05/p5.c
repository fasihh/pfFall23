/*
 * Creator: Fasih Hasan
 * Date: 19/9/23
 * Description: Determine what type of character is input
 */

#include <stdio.h>

void main() {
	char userInput;
	int digit;

	printf("Input any character: ");
	scanf(" %c", &userInput);

	// converting character to the equivalent integer value 
	digit = (int) userInput;

	if (digit >= 97 && digit <= 122) {
		printf("Lower case character");
	} else if (digit >= 65 && digit <= 90) {
		printf("Upper case character");
	} else if (digit >= 48 && digit <= 57) {
		printf("Digit character");
	} else {
		printf("Special case character");
	}
} // end main()
