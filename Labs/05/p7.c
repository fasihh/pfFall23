/*
 * Fasih Hasan
 * Date: 19/9/23
 * Description: Online shopping store that prints out amount, saved amount and discounted amount.
 */

#include <stdio.h>

void main() {
	int items, actualTotal, price, total;
	total = 0, actualTotal = 0;

	printf("Input amount of items: ");
	scanf("%d", &items);

	// get items one by one 
	while (items--) {
		printf("Input price of item: ");
		scanf("%d", &price);

		// keeping track of actual amount side by side
		actualTotal = actualTotal + price;

		if (price > 1999) {
			price = price * 0.5;
		}
	
		// saved amount total
		total = total + price;
	}

	printf("Actual amount: %d\n", actualTotal);
	printf("Saved amount: %d\n", total);

	// checking what criteria final cost meets
	if (total >= 2000 && total <= 4000) {
		total = total - (total * 0.2);
	} else if (total >= 4001 && total <= 6000) {
		total = total - (total * 0.3);
	} else if (total >= 6001) {
		total = total * 0.5;
	}

	printf("Discounted amount: %d", total);
} // end main()
