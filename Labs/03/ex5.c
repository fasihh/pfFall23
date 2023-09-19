/* 
 * Fasih Hasan
 * Description: Fuel consumption calculator
 */

#include <stdio.h>

void main() {
	int totalDistance, fuelRate;

	printf("Find fuel consumed\n\n");

	printf("Input total distance travelled by vehicle (in km): ");
	scanf("%d", &totalDistance);

	printf("Input fuel consumption rate of vehicle (in litre): ");
	scanf("%d", &fuelRate);

	printf("Amount of fuel consumed is %.1f litres", (float) fuelRate * totalDistance);
}; // end main()
