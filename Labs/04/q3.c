/*
 * Creator: Fasih Hasan
 * Date: 12/9/23
 * Description: Find sum of square of 'n' numbers
 */

// included libs
#include <stdio.h>
#include <math.h>

void main() {
	int n, i, num, total; // amount of inputs, counter for sum, total, num taken as input
	total = 0, i = 0; // initializing total and sum counter

	printf("Input 'n' the amount of numbers to be taken as input: ");
	scanf("%d", &n);

	while (i < n) {
		printf("%d. Input number : ", i + 1);
		scanf("%d", &num);
		total += pow(num, 2);
		i++;
	}

	printf("Total is: %d", total);

}// end main