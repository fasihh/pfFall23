/*
 * Creator: Fasih Hasan
 *    Date: 2/12/23
 *    Desc: Takes entries for different files and then combines them together in a seprate file according tot he IDs
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 30
#define f_personal "Personal.txt"
#define f_department "Department.txt"
#define f_combine "Combine.txt"

char *get_record(char *id, FILE *fp)
{
	if (fp == NULL) return NULL;

	char buffer[BUFFER_SIZE], delim[2] = ",";
	char *record = (char *)malloc(sizeof(char) * BUFFER_SIZE);

	while (!feof(fp)) {
		fgets(buffer, BUFFER_SIZE, fp);
		buffer[strcspn(buffer, "\n")] = 0;

		char *record_id = strtok(buffer, delim);

		if (!strcmp(id, record_id)) {
			strcpy(record, strtok(NULL, delim));
			return record;
		}
	}

	return NULL;
} // end get_record()

bool check_record(char *id, FILE *fp)
{
	if (fp == NULL) return false;

	char buffer[BUFFER_SIZE], delim[2] = ",";

	while (!feof(fp)) {
		fgets(buffer, BUFFER_SIZE, fp);
		buffer[strcspn(buffer, "\n")] = 0;

		char *record_id = strtok(buffer, delim);
		if (!strcmp(record_id, id)) return true;
	}

	return false;
} // end check_record()

int main()
{
	char id[BUFFER_SIZE], merge[BUFFER_SIZE * 2];

	printf("Enter ID to merge: ");
	fgets(id, BUFFER_SIZE, stdin);
	id[strcspn(id, "\n")] = 0;

	FILE *personal = fopen(f_personal, "r"), *department = fopen(f_department, "r"), *combine = fopen(f_combine, "r");
	char *name = get_record(id, personal), *salary = get_record(id, department);

	if (name == NULL || salary == NULL) {
		printf("Record missing in either both or one file!");
		return 0;
	}

	fclose(department), fclose(personal);
	
	if (!check_record(id, combine)) {
		fclose(combine);
		combine = fopen(f_combine, "a");

		sprintf(merge, "%s,%s,%s\n", id, name, salary);
		fputs(merge, combine);

		printf("Record merged and appended successfully!");
	} else {
		printf("Record already exists!");
	}

	fclose(combine);

	return 0;
} // end main()