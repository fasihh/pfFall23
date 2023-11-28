/*
 * Creator: Fasih Hasan 
 * Date: 28/11/23
 * Desc: reading from a csv file and then printing the lines with the correct table format
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 100

int format_line(char str[100])
{
    char delim[2] = ",";
    int cols = 0;
    char *col = strtok(str, delim);

    // separating words with commas
    while (col != NULL) {
        cols++;
        col[strcspn(col, "\n")] = 0; // removing new line from the end of file line
        printf("%-14s | ", col); // printing in correct format
        col = strtok(NULL, delim);
    }

    printf("\n");
    return cols;
} // end format_line()

void read_file(FILE *fptr)
{
    char buffer[MAX_BUFFER_SIZE];
    int rows = 0, cols = 0;

    // reading all lines
    while (!feof(fptr)) {
        rows = format_line(fgets(buffer, MAX_BUFFER_SIZE, fptr)); 
        cols++;
    }

    printf("\n\nrows: %d, cols: %d", cols, rows);
} // end read_stable_file()

int main()
{
    FILE *fptr = fopen("table.csv", "r");
    read_file(fptr);
    fclose(fptr);

    return 0;
} // end main()
