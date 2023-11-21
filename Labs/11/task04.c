/*
 * Name: Fasih Hasan Khan
 * Date: 21/11/23
 * Desc: Calculate salary increments of each employee in a struct and display
 */

#include <stdio.h>

struct Employee {
    char name[20];
    float salary;
    int hours;
};

void show_employees(struct Employee employees[10])
{
    for (int i = 0; i < 10; i++) {
        printf("Name: %s\nSalary: $%.2f\nHours: %d\n\n", employees[i].name, employees[i].salary, employees[i].hours);
    }
} // end show_employees()

void increase_salary(struct Employee employees[10])
{
    for (int i = 0; i < 10; i++) {
        if (employees[i].hours >= 12) employees[i].salary += 150;
        else if (employees[i].hours >= 10) employees[i].salary += 100;
        else if (employees[i].hours >= 8) employees[i].salary += 50;
    }
} // end increase_salary()

int main()
{
    struct Employee employees[10] = {
        {"Fasih Hasan", 2300.00, 8},
        {"Muhammad Ali", 1500.00, 8},
        {"Abser Mansoor", 3000.00, 4},
        {"Fahad Faheem", 150.00, 2},
        {"Muhammad Umar", 50.00, 12},
        {"Abdul Rehman", 10.0, 24},
        {"Saif Ur Rehman", 1.00, 1},
        {"Raghib Rizwan", 40000, 32},
        {"Muhammad Owais", 100.00, 12},
        {"John Raza", 12000.00, 9}
    };
    
    increase_salary(employees);
    show_employees(employees);
    
    return 0;
} // end main()
