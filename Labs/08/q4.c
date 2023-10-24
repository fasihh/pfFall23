/*
 * Creator: Fasih Hasan Khan
 * Date: 24/10/23
 * Desc: checks if password is correct
 */

#include <stdio.h>
#include <string.h>

const char *stored_pass = "Secure123.";

void check_pass(char *pass) {
    (!strcmp(stored_pass, pass)) ? printf("Login successful. Welcome!") : printf("Login failed. Incorrect password.");
} // check_pass(char *)

int main() {
    char pass[100];

    do {
        printf("Enter your password: ");
        gets(pass);
    } while (strlen(pass) < 8);

    check_pass(pass);

    return 0;
} // main()