#include <stdio.h>

void main() {	
	int num;

	printf("Input 8-bit number: ");
	scanf("%d", &num);

	if (num / 1000 && num / 1000000) {
		num = num - 1000000 - 1000;
	} 	

	printf("%d", num);
}

// 01001000