#include <stdio.h>

void main() {
	int num;

	printf("Input number: ");
	scanf("%d", &num);

	// (!(num % 3)) ? printf("This number is multiple of 3") : printf("This number is not multiple of 3");

	if (!(num % 3)) {
		printf("This number is multiple of 3");
	} else {
		printf("This number is not multiple of 3");
	}
}
