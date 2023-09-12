/*
 * Creator: Fasih Hasan
 * Date: 12/9/23
 * Description: Printing pattern by taking 'n' as input
 */

// included libs
#include <stdio.h>

void main() {
	int n, i, j, k, r; // k is the space in between
	j = 0, k = 1, r = 0; // initialize j and k and r

	printf("Input any number 'n': ");
	scanf("%d", &n);
	
	i = n;	

	while (i > 0) {
		// adding '*'
		j = 0;
		while (j < i) {
			printf(" ");
			j++;
		}
		printf("*");
		
		
		r = 0;
		if (k - 1) {
			printf("*");
			while (r < k) {
				printf(" ");
				r++;
			}
		}
		k += 2;

		printf("\n"); // starting new line
		i--;
	}

}// end main

//   *  
//  * *
// *   *
//*     * 
// *   *
//  * *
//   *


//    *
//   * *
//  *   *
// *     *
//*       *
