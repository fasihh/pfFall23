/*
 * Creator: Fasih Hasan 
 * Date: 28/11/23
 * Desc: reading from a csv file and then printing the lines with the correct table format
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 100

void format_line(char str[100])
{
    char delim[2] = ",";
    char *row = strtok(str, delim);

    // separating words with commas
    while (row != NULL) {
        row[strcspn(row, "\n")] = 0; // removing new line from the end of file line
        printf("%-14s | ", row); // printing in correct format
        row = strtok(NULL, delim);
    }

    printf("\n");
} // end format_line()

void read_file(FILE *fptr)
{
    char buffer[MAX_BUFFER_SIZE];

    // reading all lines
    while (!feof(fptr)) {
        format_line(fgets(buffer, MAX_BUFFER_SIZE, fptr)); 
    }
} // end read_table_file()

int main()
{
    FILE *fptr = fopen("table.csv", "r");
    read_file(fptr);
    fclose(fptr);
    
    return 0;
} // end main()
