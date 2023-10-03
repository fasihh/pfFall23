#include <stdio.h>

int main() {
	int sticks = 21, n;
	printf("Sticks %d\n", sticks);

	while (sticks > 0) {
		
		do {
			printf("Enter number of sticks (1, 2, 3 or 4): ");
			scanf("%d", &n);
		} while (n > 4 || n < 1 && sticks < n);
		sticks -= n;

		if (sticks < 5) {
			while (sticks > 1) {
				sticks--;
			}
		} else {
			sticks -= 3;
		}

		printf("Sticks left %d\n", sticks);
	}

	return 0;
}
