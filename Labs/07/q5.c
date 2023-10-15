/*
 * Creator: Fasih Hasan Khan
 * Date: 10/10/23
 * Description: prints out a man of size 'n' where n is odd.
 */

#include <stdio.h>

#define ch '*'

void hat(int n) {
    for (int i = 0; i < n - 2; i++) {
        for (int j = 1; j < n; j++) printf(" ");

        for (int k = 0; k < n; k++) printf("%c", ch);
        printf("\n");
    }

    printf(" ");
    // 3n - 4 gave the correct number of spaces. Figured it out by trial and error
    for (int i = 0; i < 3*n - 4; i++) {
        printf("%c", ch);
    }
    printf("\n");
} // end hat(int)

void face(int n) {
    for (int i = 0; i < 3; i++) {
        switch(i) {
            case 0:
                for (int k = 1; k < n; k++) printf(" ");
                printf("%c", ch);
                for (int k = 2; k < n; k++) printf(" ");
                printf("%c", ch);
                break;
            case 1:
                for (int k = -1; k < (3*n - 4)/2; k++) printf(" ");
                printf("|");
                break;
            case 2:
                for (int k = 0; k < (3*n - 4)/2; k++) printf(" ");
                printf("\\_/");
                break;
        }
        printf("\n");
    }
    printf("\n");
} // end face(int)

void neck(int n) {
    // again, trial and error
    for (int i = 0; i < (3*n - 4)/2; i++) printf(" ");
    printf("| |\n");
} // end neck(int)

void torso(int n) {
    for (int i = 0; i < 3*n - 2; i++) printf("%c", ch);
    printf("\n");
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n/2; j++) printf("%c", ch);
        for (int j = 0; j < n/2; j++) printf(" ");
        for (int j = 0; j < n; j++) printf("%c", ch);
        for (int j = 0; j < n/2; j++) printf(" ");
        for (int j = 0; j < n/2; j++) printf("%c", ch);

        printf("\n");
    }
} // end torso(int)

void legs(int n) {
    for (int i = 1; i < n; i++) printf(" ");
    for (int i = 0; i < n; i++) printf("%c", ch);
    printf("\n");
    for (int i = 0; i < (3*n - 4)/2; i++) {
        for (int j = 1; j < n; j++) printf(" ");
        for (int j = 0; j < n/2; j++) printf("%c", ch);
        printf(" ");
        for (int j = 0; j < n/2; j++) printf("%c", ch);

        printf("\n");
    }
} // end legs(int)

void shoes(int n) {
    for (int i = 1; i < n/2; i++) printf(" ");
    for (int i = 0; i < n; i++) printf("%c", ch);
    printf(" ");
    for (int i = 0; i < n; i++) printf("%c", ch);
    printf("\n");
} // end shoes(int)

int main() {
    int n;

    do {
        printf("Enter 'n': ");
        scanf("%d", &n);

    } while (!(n & 1));

    hat(n);
    face(n);
    neck(n);
    torso(n);
    legs(n);
    shoes(n);

    return 0;
} // end main()
