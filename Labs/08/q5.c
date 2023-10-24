/*
 * Creator: Fasih Hasan Khan
 * Date: 24/10/23
 * Desc: checks if car can be used
 */

#include <stdio.h>

int decideCarUsage(int car_num, int day) {
    return !(car_num & 1 ^ day & 1);
} // decideCarUsage(int, int)

int main() {
    int car_num, day;
    printf("Enter your car number: ");
    scanf("%d", &car_num);
    printf("Enter day number (1 - 7): ");
    scanf("%d", &day);

    (decideCarUsage(car_num, day)) ? printf("Can be used") : printf("Can not be used");

    return 0;
} // main()