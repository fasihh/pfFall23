#include <stdio.h>

void main() {
	int intensity, lightSensor;

	do {
		printf("Input intensity value: ");
		scanf("%d", &intensity);	
	} while (intensity < 0);

	if (intensity > 0 && intensity < 100) {

	}
}