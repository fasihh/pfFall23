/*
 * Creator: Fasih Hasan
 * Date: 19/9/23
 * Description: Give appropriate greetings for certain times
 */

#include <stdio.h>

void main() {
	char choice = ' ';
	int flag = 1;

	while (flag) {
		printf("Are you sure to delete? [Y/y] / [N/n]: ");		
		scanf(" %c", &choice);

		if (choice == 'y') {
			choice = 'Y';
		} else if (choice == 'n') {
			choice = 'N';
		}

		switch (choice) {
			case 'Y':
				printf("Deleted successfully");
				flag = 0;
				break;
			case 'N':
				printf("Delete canceled");
				flag = 0;
				break;
			default:
				printf("Choose correct option\n");
		}

	}
	
} // end main()
