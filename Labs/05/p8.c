/*
 * Fasih Hasan
 * Date: 19/9/23
 * Description: Give appropriate actions when a value of intensity is given
 */

#include <stdio.h>

void main() {
	int intensity;

	// taking inputs until proper intensity value
	do {
		printf("Input intensity value: ");
		scanf("%d", &intensity);	
	} while (intensity < 0 || intensity > 1000);

	if (intensity >= 0 && intensity <= 100) {
		printf("Evening: low brightness");
	} else if (intensity > 100 && intensity <= 500) {
		printf("Lighting: moderate brightness");
	} else if (intensity > 500) {
		printf("Sunshine: maximum brightness");
	}
} // end main()
