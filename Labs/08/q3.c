/*
 * Creator: Fasih Hasan Khan
 * Date: 24/10/23
 * Desc: counts how many times a character comes in a string
 */

#include <stdio.h>
#include <string.h>

int count(char *str, char ch) {
    int c = 0;
    char *locate = strchr(str, ch);

    while (locate != NULL && *locate == ch) {
        locate = strchr(locate + 1, ch);
        c++;
    }

    return c; 
} // count(char *, char)

int main() {
    char str[100];
    char ch;

    printf("Enter your text:\n");
    gets(str);
    printf("Enter characters to find: ");
    scanf(" %c", &ch);

    printf("%c comes %d times", ch, count(str, ch));

    return 0;
} // main()