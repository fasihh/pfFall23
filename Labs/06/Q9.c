/*
 * Creator: Fasih Hasan
 * Date: 10/3/2023
 * Description: Take 'n' numbers, store them in an array and print the maximum value and the minimum value stored in the array
 */

#include <stdio.h>

int main() {
	int numArr[100];
	int n, num, min = ~(1 << 31), max = 1 << 31; 

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

	// checking each value against the max and min variables
	for (int i = 0; i < n; i++) {
		if (numArr[i] < min) {
			min = numArr[i];
		}

		if (numArr[i] > max) {
			max = numArr[i];
		}
	}

	printf("Minimum value = %d\nMaximum value = %d", min, max);

	return 0;
} // end main()