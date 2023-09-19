#include <stdio.h>
#include <math.h>

void main() {
	int a, b, c;
	float d;	

	printf("Input 'a b c' in this format: ");
	scanf("%d %d %d", &a, &b, &c); 

	d = b * b - (4 * a * c);	

	if (d == 0) {
		printf("x = %.4f", (float) ( -b + sqrt(d) ) / (2 * a));
	} else if (d > 0) {
		printf("x1 = %.4f and x2 = %.4f", (float) ( -b + sqrt(d) ) / (2 * a), ( -b - sqrt(d) ) / (2 * a));
	} else {
		printf("no roots");
	}

}// end main