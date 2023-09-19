/* 
 * Fasih Hasan
 * Description: Find discount on a price
 */

#include <stdio.h>

void main() {
	int discount, price;
	
	printf("Find discount on a price\n\n");

	printf("Input price: ");
	scanf("%d", &price);

	printf("Input discount (e.g 20): ");
	scanf("%d", &discount);

	printf("\nPrice after discount: %0.2f", (float) ( (1 - ( (float) discount/100)) * price ) );
}; // end main()
