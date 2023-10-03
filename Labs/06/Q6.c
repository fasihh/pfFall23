/*
 * Creator: Fasih Hasan
 * Date: 10/3/2023
 * Description: A match stick game between the computer and a user. Make the computer win by having the user pick the last stick
 */

#include <stdio.h>

int main() {
	int sticks = 21, n;
	printf("Sticks %d\n", sticks);

	while (sticks > 0) {
		
		// keep taking input until value is within range
		do {
			printf("Enter number of sticks (1, 2, 3 or 4): ");
			scanf("%d", &n);
		} while (n > 4 || n < 1);
		sticks -= n;

		// computer always subtracts alternate number in the list. if user picks 4 then 1, 3 then 2, 2 then 3 etc
		switch (n) {
			case 4:
				sticks -= 1;
				break;
			case 3:
				sticks -= 2;
				break;
			case 2:
				sticks -= 3;
				break;
			case 1:
				sticks -= 4;
				break;
		}		

		// don't print negative value for sticks at the end
		if (sticks >= 0) 
			printf("Sticks left %d\n", sticks);
		else 
			printf("Sticks left 0");
	}

	return 0;
} // end main()
