/*
 * Creator: Fasih Hasan 
 * Date: 28/11/23
 * Desc: inputting student data in a file and then extracting necessary information from it. Using structs to store data too
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 100

typedef struct {
    int code;
    char name[30];
    int credit;
    int gpa;
    int sem;
} Course;

Course read_record(FILE *fp)
{
    Course record;
    char buffer[MAX_BUFFER_SIZE];

    fgets(buffer, MAX_BUFFER_SIZE, fp);

    printf("%s", buffer);

    sscanf(buffer, "%d,%s,%d,%d,%d", record.code, record.name, record.credit, record.gpa, record.sem);

    return record;
}

void write_record(Course rec, FILE *fp)
{
    char buffer[MAX_BUFFER_SIZE];

    sprintf(buffer, "%d,%s,%d,%d,%d\n", rec.code, rec.name, rec.credit, rec.gpa, rec.sem);

    fputs(buffer, fp);
}

void create_transcript(FILE *fp, int sem)
{
    while (!feof(fp)) {
        read_record(fp);
    }
}

int main()
{
    /* FILE *fp = fopen("course_records.txt", "a");

    Course record[100];
    int courses; */

    /* printf("Enter number of courses: ");
    scanf("%d", &courses);

    for (int i = 0; i < courses; i++) {
        printf("Enter couse code: ");
        scanf("%d", &record[i].code);
        fflush(stdin);

        printf("Enter course name: ");
        fgets(record[i].name, 25, stdin);
        record[i].name[strcspn(record[i].name, "\n")] = 0;
        fflush(stdin);

        printf("Enter course credit hours: ");
        scanf("%d", &record[i].credit);

        printf("Enter course gpa: ");
        scanf("%d", &record[i].gpa);

        printf("Enter semester: ");
        scanf("%d", &record[i].sem);

        write_record(record[i], fp);
    }

    fclose(fp); */

    int sem;

    FILE *fp = fopen("course_records.txt", "r");

    printf("Which semester transcript do you want to create: ");
    scanf("%d", &sem);

    //create_transcript(fp, sem);
    Course record1 = read_record(fp);
    printf("%s %d", record1.name, record1.code);
    Course record2 = read_record(fp);
    printf("%s %d", record2.name, record2.code);

    fclose(fp);

    return 0;
} // end main()
