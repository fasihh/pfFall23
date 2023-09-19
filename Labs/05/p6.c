/*
 * Fasih Hasan
 * Date: 19/9/23
 * Description: Check if 7th and 4th bits are on. If yes then turn them off
 */

#include <stdio.h>

void main() {	
	int num, bitSeven, bitFour;

	printf("Input 8-bit number: ");
	scanf("%d", &num);

	// finding seventh and fourth bit
	bitSeven = (num / 1000000) % 10;
	bitFour = (num / 1000) % 10;

	if (bitSeven && bitFour) {
		num = num - 1000000 - 1000;
	} 	

	printf("%d", num);
} // end main()
