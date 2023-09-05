#include <stdio.h>
#include <math.h>

void main() {
	float opp, adj;

	printf("Hypotenus of triangle\n\n");

	printf("Input perpendicular of triangle: ");
	scanf("%f", &opp);

	printf("Input base of triangle: ");
	scanf("%f", &adj);

	printf("\n\nHypotenus is %.2lf", sqrt( ((opp * opp) + (adj * adj)) ) );
}; // end main()
