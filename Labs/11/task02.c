/*
 * Name: Fasih Hasan Khan
 * Date: 21/11/23
 * Desc: Take input of parts and print out from BB1 to CC6
 */

#include <stdio.h>
#include <string.h>

typedef struct {
    char serial_num[4];
    int manufacture_year;
    char material[10];
    int quantity;
} Part;

void input_parts(Part *parts, int size)
{
    for (int i = 0; i < size; i++) {
        printf("[%d] Enter serial number (AA0-FF9): ", i+1);
        scanf("%s", &parts[i].serial_num);

        printf("[%d] Enter manufacture year: ", i+1);
        scanf("%d", &parts[i].manufacture_year);

        printf("[%d] Enter material: ", i+1);
        scanf("%s", &parts[i].material);

        printf("[%d] Enter quantity: ", i+1);
        scanf("%d", &parts[i].quantity);
    }
} // end input_parts()

void show_parts(Part *parts, int size)
{
    for (int i = 0; i < size; i++) {
        if (strcmp("CC6", parts[i].serial_num) >= 0 && strcmp(parts[i].serial_num, "BB1") >= 0) {
            printf("\n\n[%d] Serial number (AA0-FF9): %s\n", i+1, parts[i].serial_num);
            printf("[%d] Manufacture year: %d\n", i+1, parts[i].manufacture_year);
            printf("[%d] Material: %s\n", i+1, parts[i].material);
            printf("[%d] Quantity: %d\n", i+1, parts[i].quantity);
        }
    }
} // end show_parts()

int main()
{
    int N;
    printf("Enter amount of parts: ");
    scanf("%d", &N);
    
    Part *parts = (Part *)malloc(sizeof(Part) * N);
    
    input_parts(parts, N);
    show_parts(parts, N);
    
    return 0;
} // end main()
