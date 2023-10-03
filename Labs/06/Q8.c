/*
 * Creator: Fasih Hasan
 * Date: 10/3/2023
 * Description: Take 'n' numbers, store them in an array and print them in reverse order
 */

#include <stdio.h>

int main() {
	int numArr[100];
	int n, num; 

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

	// counting from n-1 all the way to 0
	while (n--) {
		printf("%d ", numArr[n]);
	}

	return 0;
} // end main()