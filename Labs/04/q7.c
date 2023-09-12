/*
 * Creator: Fasih Hasan
 * Date: 12/9/23
 * Description: Identifying whether word is palindrome or not
 */

// included libs
#include <stdio.h>

int main() {
	int n, i; // initializing n for number of characters and i for counter

	char wordArray[100] = {' '}; // initializing list with ' ' to indicate it's empty
	i = 0;

	printf("Length of word: ");
	scanf("%d", &n);

	while (i < n) {
		printf("Input character: ");
		scanf(" %c", &wordArray[i]);

		i++;
	}

	i = 0;
	while (i < n / 2) {

		// check if letters are equal
		if (wordArray[i] != wordArray[n - i - 1]) {
			printf("Word is not palindrome");
			return 0; // exit function if not palindrome
		}

		i++;
	}

	printf("Word is palindrome");	
	return 1;

}// end main
