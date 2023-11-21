/*
 * Name: Fasih Hasan Khan
 * Date: 21/11/23
 * Desc: Take input 2 dates and compare them using structs
 */

#include <stdio.h>

struct Date {
    int date;
    int month;
    int year;
};

int main()
{
    struct Date date1, date2;
    
    printf("Enter date1 DD/MM/YYYY: ");
    scanf("%d/%d/%d", &date1.date, &date1.month, &date1.year);
    
    printf("Enter date2 DD/MM/YYYY: ");
    scanf("%d/%d/%d", &date2.date, &date2.month, &date2.year);
    
    (date1.date == date2.date && date1.month == date2.month && date1.year == date2.year) ? printf("Same") : printf("Different");
    
    return 0;
} // end main()
