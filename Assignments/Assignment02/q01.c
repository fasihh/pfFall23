/*
 * Creator: Fasih Hasan Khan
 * Date: 23/10/23
 * Desc: using 2D arrays, calculate performance of each player in a cricket team and display it appropriately
 */

#include <stdio.h>

int main()
{
	int batsmen, innings, performance[100][100];

	// rows and columns
	printf("Enter the number of batsmen: ");
	scanf("%d", &batsmen);
	printf("Enter the number of innings: ");
	scanf("%d", &innings);

	// input runs
	for (int i = 0, total, max, cent, half_cent; i < batsmen; i++) {
		total = 0, max = 1 << 31, cent = 0, half_cent = 0;
		for (int j = 0; j < innings; j++) {
			// input runs
			printf("Enter runs for batsman #%02d's inning #%02d: ", i+1, j+1);
			scanf("%d", &performance[i][j]);

			// all runs
			total += performance[i][j];

			// max runs
			if (performance[i][j] > max) max = performance[i][j];

			// centuries and halfs
			if (performance[i][j] >= 100) cent++;
			else if (performance[i][j] >= 50) half_cent++;
		}

		// output for each player
		printf("\nTotal runs: %d\nAverage run: %.2f\nHighest runs: %d\nCenturies: %d\nHalf centuries: %d\n", 
			total, 
			(float) total / innings,
			max,
			cent,
			half_cent
		);
	}
  
	return 0;
}
