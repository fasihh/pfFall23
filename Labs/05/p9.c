/*
 * Fasih Hasan
 * Date: 19/9/23
 * Description: Finding roots of an equations by evaluating determinant
 */

#include <stdio.h>
#include <math.h>

void main() {
	int a, b, c;
	float d;	

	printf("Input 'a b c' in this format: ");
	scanf("%d %d %d", &a, &b, &c); 

	// finding determinant
	d = b * b - (4 * a * c);	

	// giving appropriate result
	if (d == 0) {
		printf("x = %.4f", (float) ( -b + sqrt(d) ) / (2 * a));
	} else if (d > 0) {
		printf("x1 = %.4f, x2 = %.4f", (float) ( -b + sqrt(d) ) / (2 * a), (float) ( -b - sqrt(d) ) / (2 * a));
	} else {
		printf("no real roots");
	}

} // end main()
