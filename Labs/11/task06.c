/*
 * Creator: Fasih Hasan Khan
 * Date: 21/11/23
 * Description: Add 45 days to a struct of date inputted by the user
 */

#include <stdio.h>

typedef struct {
	int date;
	int month;
	int year;
} Date;

int main()
{
	const int days = 45;
	Date current_date;

	printf("Enter date DD/MM/YY: ");
	scanf("%d/%d/%d", &current_date.date, &current_date.month, &current_date.year);

	// add to days
	current_date.date += days % 30;
	// carry to month
	if (current_date.date > 30) current_date.date %= 30, current_date.month++;
	// add to months
	current_date.month += days / 30 % 12;
	// carry to year
	if (current_date.month > 12) current_date.month %= 12, current_date.year++;


	printf("%02d/%02d/%02d", current_date.date, current_date.month, current_date.year);
	return 0;
} // end main()
