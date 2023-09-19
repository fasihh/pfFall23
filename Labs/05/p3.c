/*
 * Creator: Fasih Hasan
 * Date: 19/9/23
 * Description: Prompts for deleting an item using switch case
 */

#include <stdio.h>

void main() {
	char choice = ' ';
	int flag = 1;

	// infinite loop until meaningful value
	while (flag) {
		printf("Are you sure to delete? [Y/y] / [N/n]: ");		
		scanf(" %c", &choice);

		// converting lower cases to upper case
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
