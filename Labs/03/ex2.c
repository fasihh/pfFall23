#include <stdio.h>

void main() {
	float x, y, z;
	x=0;y=0;z=0;

	printf("Volume of container\n\n");

	printf("Input length, width, breadth (In format -> 'x y z'): ");
	scanf("%d %d %d", &x, &y, &z);

	printf("Volume is: %.2f", x*y*z);
		
}; // end main()
