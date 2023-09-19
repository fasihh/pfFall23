/*
 * Fasih Hasan
 * Date: 19/9/23
 * Description: flip 4 bits at start withh 4 bits at end
 */

#include <stdio.h>

void main() {	
	int num, bit, front, back;
	front = 0;

	printf("Input 8-bit number: ");
	scanf("%d", &num);

	// finding the 4bits at the start
	back = num / 10000;

	int i = 0;
	while(i < 4) {
		bit = num % 10;

		// reducing number
		num = num / 10;

		// 10^x without pow() function
		int j = i;
		while(j--) {
			bit = bit * 10;
		}

		// adding the bits
		front = front + bit;
		i++;
	}

	// last 4 bits
	front = front * 10000;

	// combine all results and pad with 0s
	printf("%08d", front + back);
} // end main()
