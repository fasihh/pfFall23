/*
 * Creator: Fasih Hasan Khan
 * Date: 25/10/23
 * Desc: finds discount on the basis of frequency of visit and total purchase
 */

#include <stdio.h>

float calculateDiscount(int total, int count)
{
    if (count > 10 && total >= 50) return 0.85;
    else if (count > 5 && total >= 30) return 0.90;
    else return 1;
} // calculateDiscount(int, int)

int main() 
{
    int total, count;
    
    printf("Enter number of times visited this month: ");
    scanf("%d", &count);
    printf("Enter total of purchases made this month: ");
    scanf("%d", &total);
    
    float discount = calculateDiscount(total, count);
    printf("\nYour discount is: %.2f", 100 - 100*discount);
    printf("\nTotal: %.2f", total * discount);

    return 0;
} // main()
