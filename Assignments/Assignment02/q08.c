/*
 * Creator: Fasih Hasan Khan
 * Date: 23/10/23
 * Desc: finding persistence for indefinite amount of numbers until user enters nothing
 */

#include <stdio.h>
#include <conio.h>

int persistence(int num) 
{
	int count = 0;

	// checking if number is not 1 digit
	while (num > 9) {
		int new_num = 1;

		// find product of all digits
		for (; num > 0; num /= 10) {
			new_num *= num % 10;
		}

		// make num the product of previous num's digit
		num = new_num;

		// keep track of the amount of times this has been done
		count++;
	}

	return count;
} // persistence(int)

int main()
{
	char num[10];
	while (1) {
		printf("Enter number: ");
		gets(num);

		// check if string length is 0 (EOF)
		if (!strlen(num)) break;

		// output
		printf("\nPersistence of %s is %d\n", num, persistence(atoi(num)));
	}
	return 0;
} // main()
