/*
 * Creator: Fasih Hasan Khan
 * Date: 27/10/23
 * Description: Input shirt details and print out prices in desc. and age in asc. order
 */

#include <stdio.h>

void show(int arr[][2], int n)
{
	printf("\nAge : Price\n");
	for (int i = 0; i < n; i++) {
		printf("%3d - %d\n", arr[i][0], arr[i][1]);
	}
} // show(int *[2], int)

void sort(int arr[][2], int n, int col, int order)
{
	// insertion sort
	for (int i = 0; i < n; i++) {
		// checking if ascending or descening order
		for (int j = i; ((arr[j - 1][col] < arr[j][col] && order) || (arr[j - 1][col] > arr[j][col] && !order)) && j > 0; j--) {

			// swaps
			int temp1 = arr[j - 1][col];
			int temp2 = arr[j - 1][!col];
			arr[j - 1][col] = arr[j][col];
			arr[j - 1][!col] = arr[j][!col];
			arr[j][col] = temp1;
			arr[j][!col] = temp2;
		}
	}
} // sort(int *[2], int, int)

int main()
{
	int shirts_age[100][2], shirts_price[100][2], n;

	printf("Enter number of shirts: ");
	scanf("%d", &n);

	printf("Enter shirt details for each shirt:\n");

	// input
	for (int i = 0, age, price; i < n; i++) {
		printf("Shirt %d\n", i+1);
		printf("Age: ");
		scanf("%d", &age);
		printf("Price: ");
		scanf("%d", &price);
		printf("\n");

		shirts_age[i][0] = age, shirts_price[i][0] = age;
		shirts_age[i][1] = price, shirts_price[i][1] = price;
	}

	printf("Shirt details in terms of ages in ascending order:\n");
	sort(shirts_age, n, 0, 0);
	show(shirts_age, n);
	printf("\n");
	printf("Shirt details in terms of prices in descening order: \n");
	sort(shirts_price, n, 1, 1);
	show(shirts_price, n);
	
	return 0;
} // main()
