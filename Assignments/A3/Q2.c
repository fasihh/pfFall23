/*
 * Creator: Fasih Hasan
 *    Date: 2/12/23
 *    Desc: Creates a 2D array for multiple departments. Assigns each department with employees with random names, roles and stats. Finds the best department according to stats
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
	char name[20];
	char role[10];
	int communication;
	int team_work;
	int creativity;
} Employee;

char *depart_names[4] = {"HR", "Finance", "Marketing", "Logistics"};
char *names[20] = {"Oliver Reynolds", "Stella Hayes", "Leo Mitchell", "Ava Davidson", "Ethan Porter", "Mia Bennett", "Noah Coleman", "Lily Morgan", "Lucas Griffin", "Harper Parker", "Jackson Hunter", "Grace Turner", "Aiden Sullivan", "Chloe Brooks", "Walter White", "Emily Foster", "Liam Wallace", "Sophia Carpenter", "Logan Harrison", "Isabella Harper"};
char *roles[5] = {"Director", "Executive", "Manager", "Employee", "Trainee"};

Employee **create_departments()
{
	Employee **depart = (Employee **)malloc(sizeof(Employee *) * 4);
	Employee *employees = (Employee *)malloc(sizeof(Employee) * 5*4);

	for (int i = 0; i < 4; i++) depart[i] = &employees[i*5];

	return depart;
} // end create_departments()

void print_employees(Employee *depart)
{
	printf("%7c%-12s|%9s%4c|%15s%-2c|%11s%-2c|%12s%-2c|\n", 
		' ', "Name", "Role", ' ', "Communication", ' ', "Team Work", ' ', "Creativity", ' '
	);
	for (int i = 0, index; i < 5; i++) {
		printf("%2c%-17s|%2c%-11s|%10d%-7c|%8d%-5c|%8d%-6c|\n",
			' ', depart[i].name, ' ', depart[i].role, depart[i].communication, ' ', depart[i].team_work, ' ',depart[i].creativity, ' '
		);
	}
} // end print_employees()

int assign(Employee *depart)
{
	bool roles_check[5] = {true, true, true, true, true};

	for (int i = 0, index_n, index_r; i < 5; i++) {
		do {
			index_n = rand() % 20; 
		} while (names[index_n] == NULL);

		do {
			index_r = rand() % 5; 
		} while (roles_check[index_r] == false);

		strcpy(depart[i].role, roles[index_r]);
		strcpy(depart[i].name, names[index_n]);

		depart[i].communication = rand() % 100 + 1;
		depart[i].team_work = rand() % 100 + 1;
		depart[i].creativity = rand() % 100 + 1;

		names[index_n] = NULL, roles_check[index_r] = false;
	}
	
	return 0;
} // end assign()

int get_highest_stats_depart(Employee **departs)
{
	int max_stats = 1 << 31, total_stats = 0, highest_depart;
	for (int i = 0; i < 4; i++) {
		total_stats = 0;
		for (int j = 0; j < 5; j++) {
			total_stats += departs[i][j].communication + departs[i][j].team_work + departs[i][j].creativity;
		}

		if (total_stats > max_stats) max_stats = total_stats, highest_depart = i;
	}

	return highest_depart;
} // get_highest_stats_depart()

int main()
{
	time_t t;
	srand(t);

	Employee **departs = create_departments();

	for (int i = 0; i < 4; i++) assign(departs[i]);
	int k = get_highest_stats_depart(departs);	

	for (int i = 0; i < 4; i++) {
		if (i == k) continue;
		printf("%20cEmployees of department: %s\n", ' ', depart_names[i]);
		print_employees(departs[i]);
		printf("\n");
	}

	printf("%20cBest department award goes to: %s\n", ' ', depart_names[k]);
	print_employees(departs[k]);

	return 0;
} // end main()