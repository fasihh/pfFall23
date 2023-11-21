/*
 * Name: Fasih Hasan Khan
 * Date: 21/11/23
 * Desc: Take input of not more than 450 students in a struct and display it
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char roll_num[8];
    char name[20];
    char department[3];
    char course[5];
    char year[5];
} Student;

void input_students(Student *students, int size)
{
    for (int i = 0; i < size; i++) {
        printf("[%d] Enter roll number (e.g 23K0018): ", i+1);
        scanf("%s", &students[i].roll_num);

        printf("[%d] Enter name: ", i+1);
        scanf("%s", &students[i].name);

        printf("[%d] Enter department (e.g AI): ", i+1);
        scanf("%s", &students[i].department);

        printf("[%d] Enter course (e.g PF, OOP, COAL): ", i+1);
        scanf("%s", &students[i].course);

        printf("[%d] Enter year of admission (e.g 2023): ", i+1);
        scanf("%s", &students[i].year);
    }
} // end input_students()

void print_students(Student *students, int size)
{
    for (int i = 0; i < size; i++) {
        printf("\n\nStudent [%d]:\nName: %s\nDepartment: %s\nCourse: %s\nYear: %s", i+1, students[i].name, students[i].department, students[i].course, students[i].year);
    }
} // end print_students()

int main()
{
    int N;

    do {
        printf("Input amount of students to be taken as input: ");
        scanf("%d", &N);
    } while (N > 450);
    
    // allocating N-students array
    Student *students = (Student *)malloc(sizeof(Student) * N);
    input_students(students, N);
    print_students(students, N);

    return 0;
} // end main()
