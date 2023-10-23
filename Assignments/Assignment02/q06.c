/*
 * Creator: Fasih Hasan Khan
 * Date: 23/10/23
 * Desc: finding pair of numbers that equal to the sum provided by the user in an array
 */

#include <stdio.h>

int main()
{
	int n, sum, arr[100], pairs[100], count = 0;
	printf("Enter number of elements in array: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("Enter element %d: ", i+1);
		scanf("%d", &arr[i]);
	}

	printf("Enter sum: ");
	scanf("%d", &sum);

	// find pair for each number
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] + arr[j] == sum) {
				// add values as a pair to the pairs array
				pairs[count++] = arr[j], pairs[count++] = arr[i];
				break;
			}
		}
	}

	// output pairs
	for (int i = 0; i < count;) {
		printf("(%d, %d)", pairs[i++], pairs[i++]);
		if (i != count) printf(", ");
	}

	return 0;
} // main()
