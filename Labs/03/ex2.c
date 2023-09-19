/* 
 * Fasih Hasan
 * Description: Volume of a container
 */

#include <stdio.h>

int main() {
	int x, y, z;
	x=0;y=0;z=0;

	printf("Volume of Ahmed's container\n\n");

	printf("Input length, width, breadth (In format -> 'x y z'): ");
	scanf("%d %d %d", &x, &y, &z);

	printf("Volume is: %d", x*y*z);
		
	return 0;
}; // end main()
