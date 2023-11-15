/*
 * Creator: Fasih Hasan Khan
 * Date: 14/11/23
 * Description: swapping two variable datatypes using XOR
 */

#include <stdio.h>

void swap(void *n1, void *n2, char type)
{
	// create a XOR mask for both values
	// XOR the mask with each value to swap it

	if (type == 'd' || type == 'f' || type == 'l') {
		long mask = *(long *)n1 ^ *(long *)n2;
		*(long *)n1 ^= mask, *(long *)n2 ^= mask;
	} else if (type == 'c') {
		char mask = *(char *)n1 ^ *(char *)n2;
		*(char *)n1 ^= mask, *(char *)n2 ^= mask;
	}
} // end swap()

int main()
{
	int num1 = 3, num2 = 1;
	char char1 = 'A', char2 = 'B';
	float float1 = 3.5, float2 = 1.5;

	// pass void * casted pointer
	printf("%d %d ", num1, num2);
	swap((void *) &num1, (void *) &num2, 'd');
	printf("swaps %d %d\n", num1, num2);

	printf("%c %c ", char1, char2);
	swap((void *) &char1, (void *) &char2, 'c');
	printf("swaps %c %c\n", char1, char2);

	printf("%.1f %.1f ", float1, float2);
	swap((void *) &float1, (void *) &float2, 'f');
	printf("swaps %.1f %.1f", float1, float2);

	return 0;
} // end main()
