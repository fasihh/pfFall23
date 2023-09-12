/*
 * Creator: Fasih Hasan
 * Date: 12/9/23
 * Description: Printing diamond pattern by taking 'n' as input
 */

// included libs
#include <stdio.h>

void main() {
	int n, i, j, r, k;
	j = 0, r = 0, k = 1, n = 0;

	printf("Input any number 'n' above 0: ");
	scanf("%d", &n);
	
	i = n;	

	// making top half of the pattern
	while (i > 0) {

		// left side '*'
		j = 0;
		while (j < i - 1) {
			printf(" ");
			//printf("%d, %d", j, i);
			j++;
		}
		printf("*");

		// right side '*'
		j = 0;
		while (j < r) {
			printf(" ");
			j++;
		}

		// not printing '*' if k is first row
		if (k > 1) {
			printf("*");
		}

		r = (2 * k) - 1; // odd number of space between '*'

		printf("\n"); // starting new line

		k++;
		i--;
	}

	// is run 1 time less than top half
	i = 1;

	// 1 less row requires -4 odd number
	r -= 4;  


	// making the lower half of the pattern
	while (i < n) {

		// left side
		j = 0;
		while (j < i) {
			printf(" ");
			j++;
		}
		printf("*");

		// right side
		j = 0;
		while (j < r) {
			printf(" ");
			j++;
		}

		if (r > 0) {
			printf("*");
		}

		printf("\n"); // starting new line

		r -= 2; // decreasing space between '*'
		k--;
		i++;
	}

}// end main
