/*
 * Creator: Fasih Hasan
 * Date: 10/3/2023
 * Description: Take 'n' numbers, store them in an array and print their total
 */

#include <stdio.h>

int main() {
	int numArr[100];
	int n, num, total = 0; 

	// validation loop to ensure input size doesn't exceed size of array
	do {
		printf("Enter length of array: ");
		scanf("%d", &n);
	} while (n > 100 || n < 1);

	// user input
	int i = 0;
	while (i < n) {
		printf("Enter number: ");
		scanf("%d", &num);
		numArr[i++] = num;
	}

	// summing all values
	for (int j = 0; j < n; j++) {
		total += numArr[j];
	}

	printf("Sum of all numbers: %d", total);

	return 0;
}