/*
 * Creator: Fasih Hasan
 * Date: 19/9/23
 * Description: Check if multiple of 3
 */

#include <stdio.h>

void main() {
	int num;

	printf("Input number: ");
	scanf("%d", &num);

	if (!(num % 3)) {
		printf("This number is multiple of 3");
	} else {
		printf("This number is not multiple of 3");
	}
}// end main()
