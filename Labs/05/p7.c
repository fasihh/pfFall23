/*
 * Fasih Hasan
 * Date: 19/9/23
 * Description: Online shopping store that prints out amount, saved amount and discounted amount.
 */

#include <stdio.h>

void main() {
	int actualTotal, total, saved;
	total = 0, actualTotal = 0, saved = 0;

	printf("Input total amount: ");
	scanf("%d", &actualTotal);

	// checking what criteria final cost meets
	if (actualTotal >= 2000 && actualTotal <= 4000) {
		saved = actualTotal * 0.2;
	} else if (actualTotal >= 4001 && actualTotal <= 6000) {
		saved = actualTotal * 0.3;
	} else if (actualTotal >= 6001) {
		saved = actualTotal * 0.5;
	} else {
		total = actualTotal;
	}

	total = actualTotal - saved;

	printf("\n---------------------------------------------------------------\n\n");

	printf("Actual amount: %d\n", actualTotal);
	printf("Final amount: %d\n", total);
	printf("Saved: %d", saved);
} // end main()
