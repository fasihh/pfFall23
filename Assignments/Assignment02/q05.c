/*
 * Creator: Fasih Hasan Khan
 * Date: 23/10/23
 * Desc: prints out ramanujan numbers within n^3
 */

#include <stdio.h>
#include <conio.h>

// checks if item exists in array
int check(int *arr, int n, int num) {
	for (int i = 0; i < n; i++) {
		if (*(arr + i) == num) return 1;
	}
	return 0;
} // check(int *, int, int)

void ramanujan_hardy(int num) 
{
	int magic_num_arr[1000] = {0}, nums = 0;

	for (int i = 0; i < num*num*num; i++) {
		for (int j = 0; j < num*num*num; j++) {
			for (int k = 0; k < num*num*num; k++) {
				for (int l = 0; l < num*num*num; l++) {
					int magic_num = k*k*k + l*l*l;

					// checking if ramanujan's number
					if (i != j && i != k && i != l
						&& i*i*i + j*j*j == magic_num) {

						int exists = check(magic_num_arr, nums, magic_num);

						// if exists then don't print
						if (!exists) printf("%d ", magic_num);

						// adding to array
						magic_num_arr[nums] = magic_num;
						nums++;
					}
				}
			}
		}	
	}
} // ramanujan_hardy(int)

int main()
{
	int n;
	printf("Enter number 'n' to get magic numbers less than n^3: ");
	scanf("%d", &n);

	ramanujan_hardy(n);
	return 0;
} // main()
