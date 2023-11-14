/*
 * Creator: Fasih Hasan Khan
 * Date: 14/11/23
 * Description: Creating a universal array print function that
 *              makes use of pointer arithmetics and variable casting
 */

#include <stdio.h>
#include <stdlib.h>

void print_arr(void *arr, int size, char type)
{
	for (int i = 0; i < size; i++) {
		switch (type) {
			// pointer casted in each type
			case 'd':
				printf("%d ",  *((int *) arr + i));
				break;
			case 'c':
				printf("%c ",  *((char *) arr + i));
				break;
			case 'f':
				printf("%.1f ",  *((float *) arr + i));
				break;
			default:
				printf("Incorrect datatype passed\n");
				return;
		}
	}
} // end print_arr()


int main()
{
	char  c_arr[3] = {'A', 'B', 'C'};
	int   i_arr[3] = {  1,   2,   3};
	float f_arr[3] = {1.5, 2.5, 3.5};

	print_arr((void *)c_arr, 3, 'c');
	printf("\n");
	print_arr((void *)i_arr, 3, 'd');
	printf("\n");
	print_arr((void *)f_arr, 3, 'f');
	printf("\n");
	print_arr((void *)0, 1, 0);

	return 0;
} // end main()
