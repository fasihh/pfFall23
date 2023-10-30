/*
 * Creator: Fasih Hasan Khan
 * Date: 28/10/23
 * Description: a flight booking system that outputs flights based on preference and shows availability on selected day
 */

#include <stdio.h>
#include <stdlib.h>

const char *days[5] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

void show_flights(int arr[][2])
{
	printf("%7s%4c | %s - %s | %s - %s |\n%12c|%19c|%19c|\n", 
		"Day", ' ', " Morning ", "Price", " Evening ", "Price",
		' ', ' ', ' ', ' ', ' '
	);
	char snum[10];
	for (int i = 0; i < 5; i++) {
		printf("%-2d%-9s | %5d %5c %5s | %5d %5c %5s |\n",
				i + 1,
				days[i],
				arr[i][0],
				'-',
				(arr[i][1]) ? itoa(arr[i][1], snum, 10) : "---",
				arr[i+5][0],
				'-',
				(arr[i+5][1]) ? itoa(arr[i+5][1], snum, 10) : "---"
		);
	}
	printf("\n");
} // end show_flights(int [][2])

void get_preference(int arr[][2])
{
	int min = ~(1 << 31), min_day;

	// first preference
	printf("Flights available in the morning:\n");
	for (int i = 0; i < 5; i++)  { 
		if (arr[i][1] < min && arr[i][1]) min = arr[i][1], min_day = i;
		if (arr[i][0]) (i-4) ? printf("%s, ", days[i]) : printf("%s\n", days[i]);
	}
	printf("Best option for morning flight on %s for price %d\n", days[min_day], min);
	
	printf("\nFlights available in the evening:\n");
	for (int i = 5; i < 10; i++)  { 
		if (arr[i][1] < min && arr[i][1]) min = arr[i][1], min_day = i%5;
		if (arr[i][0]) (i-9) ? printf("%s, ", days[i%5]) : printf("%s\n", days[i%5]);
	}
	printf("Best option for evening flight on %s for price %d\n\n", days[min_day], min);
} // end get_preference(int [][2])

void get_flight(int arr[][2], int day) 
{
	if (arr[day-1][0] || arr[day+4][0])
		printf("\nFlight available on %s\n  Time  : Price\nMorning : %d\nEvening : %d", days[day-1], arr[day-1][1], arr[day+4][1]);
	else 
		printf("\nNo flights available on %s", days[day-1]);
} // end get_flight(int *[2], int)

int main()
{
	int flights[10][2] = {
		// morning
		{1, 300},
		{1, 320},
		{0,   0},
		{1, 380},
		{1, 375},
		// evening
		{0,   0},
		{1, 310},
		{1, 280},
		{0,   0},
		{1, 400}
	};

	int day;

	show_flights(flights);

	get_preference(flights);
	printf("Select day (1 - 5): ");
	scanf("%d", &day);

	get_flight(flights, day);

	return 0;
} // end main()
