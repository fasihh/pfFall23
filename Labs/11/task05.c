#include <stdio.h>
#include <string.h>

typedef struct {
	char employee_id[5];
	char name[20];
	int salary;
} Employee;

typedef struct {
	char organization_name[40];
	char organization_number[50];
	Employee emp; 
} Organization;

int main()
{
	Organization org;

	strcpy(org.organization_name, "NU-Fast");
	strcpy(org.organization_number, "NUFAST123ABC");
	strcpy(org.emp.employee_id, "127");
	strcpy(org.emp.name, "Linus Sebastian");
	org.emp.salary = 40000;

	printf("The size of structure organization : %d\n", sizeof(Organization));
	printf("Organization Name : %s\nOrganization Number : %s\nEmployee id : %s\nEmployee name : %s\nEmployee Salary : %d", 
		org.organization_name, org.organization_number, org.emp.employee_id, org.emp.name, org.emp.salary
	);

	return 0;
}
