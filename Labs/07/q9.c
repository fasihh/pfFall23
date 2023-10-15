/*
 * Creator: Fasih Hasan Khan
 * Date: 15/10/23
 * Description: inputting mobile phone prices, calculating bill from each branch
 *              and outputting max bill and branch id along with phhone ids where it happened
 */

#include <stdio.h>

void getBillDetails(int *arr, int n, int m) {
	int total_bill = 0, branch_bill = 0, max_bill = 1 << 31, max_branch;

	printf("\n");
	for (int i = 0; i < n; i++) {
		branch_bill = 0;
		// total of each branch
		for (int j = 0; j < n; j++) {
			branch_bill += *(arr + i*n + j);
		}

		printf("Bill for branch #%d: %d\n", i, branch_bill);

		// checking if bill larger than max value
		if (branch_bill > max_bill) {
			max_bill = branch_bill;
			// keeping track of max value branch
			max_branch = i;
		}

		total_bill += branch_bill;
	}

	printf("Total bill: %d\n", total_bill);
	printf("\nBranch #%d with highest bill: %d\n", max_branch, max_bill);

	for (int i = 1; i <= m; i++) {
		printf("Mobile phone #%d-%d price: %d\n", max_branch, i - 1, *(arr + max_branch + i));
	}
} // end getBranchDetails(int *, int, int)

void inputBranches(int *arr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("Enter price of mobile phone #%d-%d: ", i, j);
			scanf("%d", (arr + i*n + j));
		}
	}
} // end inputBranches(int *, int, int)

int main() {
	int arr[1000];
	int n, m;

	printf("Enter number of branches: ");
	scanf("%d", &n);
	printf("Enter number of mobile phones per branch: ");
	scanf("%d", &m);
	inputBranches(arr, n, m);
	getBillDetails(arr, n, m);

	return 0;
} // end main()
