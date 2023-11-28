/*
 * Creator: Fasih Hasan 
 * Date: 28/11/23
 * Desc: reading from a csv file and then printing the lines with the correct table format
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 100
#define MAX_FILE_SIZE 500

int format_line(char str[100])
{
    char delim[2] = ",";
    int rows = 0;
    char *row = strtok(str, delim);

    // separating words with commas
    while (row != NULL) {
        rows++;
        row[strcspn(row, "\n")] = 0; // removing new line from the end of file line
        printf("%-14s | ", row); // printing in correct format
        row = strtok(NULL, delim);
    }

    printf("\n");
    return rows;
} // end format_line()

void read_file(FILE *fptr)
{
    char buffer[MAX_BUFFER_SIZE];
    int cols = 0, rows = 0;

    // reading all lines
    while (!feof(fptr)) {
        rows = format_line(fgets(buffer, MAX_BUFFER_SIZE, fptr)); 
        cols++;
    }

    printf("\n\nrows: %d, cols: %d", rows-1, cols);
} // end read_stable_file()

int main()
{
    FILE *fptr = fopen("table.csv", "r");
    read_file(fptr);
    fclose(fptr);

    return 0;
} // end main()
