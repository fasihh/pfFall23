#include <stdio.h>

void main() {
	int items, price, actualTotal, total;
	total = 0, actualTotal = 0;

	printf("Input amount of items: ");
	scanf("%d", &items);

	while (items--) {
		printf("Input price of item: ");
		scanf("%d", &price);

		actualTotal = actualTotal + price;

		if (price > 1999) {
			price = price * 0.5;
		}
	
		total = total + price;
	}

	printf("Actual amount: %d\n", actualTotal);
	printf("Saved amount: %d\n", total);

	if (total >= 2000 && total <= 4000) {
		total = total - (total * 0.2);
	} else if (total >= 4001 && total <= 6000) {
		total = total - (total * 0.3);
	} else if (total >= 6001) {
		total = total * 0.5;
	}

	printf("Discounted amount: %d", total);
}