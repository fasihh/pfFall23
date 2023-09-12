/*
 * Creator: Fasih Hasan
 * Date: 12/9/23
 * Description: Finding answer using appropriate values for quadratic
 */

// included libs
#include <stdio.h>
#include <math.h>

void main() {
	int i, a, b, c; // input counter, a, b and c for quadratic
	float d; // determinant of equation	

	printf("Input 'a': ");
	scanf("%d", &a);
	printf("Input 'b': ");
	scanf("%d", &b);
	printf("Input 'c': ");
	scanf("%d", &c); 

	// calculating determinant
	d = pow(b, 2) - (4 * a * c);
	
	// identifying if determinant =, < or > 0
	if (d == 0) {
		printf("x = %.4f", ( -b + sqrt(d) ) / (2 * a));
	} else if (d > 0) {
		printf("x = %.4f and x = %.4f", ( -b + sqrt(d) ) / (2 * a), ( -b - sqrt(d) ) / (2 * a));
	} else {
		printf("roots are imaginary");
	}

}// end main