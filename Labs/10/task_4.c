/*
 * Creator: Fasih Hasan Khan
 * Date: 15/11/23
 * Description: reverse each word in a sentence while mantaining the order of the words
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *rev_str(char *str, int size)
{
	char *new_str = (char *)malloc(size+2);
	*new_str = '\0', strncat(new_str, str, size);

	// reversing string
	for (int i = 0; i < size/2; i++) {
		char temp = new_str[i];
		new_str[i] = new_str[size - i -1], new_str[size - i -1] = temp;
	}

	// adding space in between
	strcat(new_str, " ");
	return new_str;
} // end rev_str()


char *spin_str(char *str)
{
	// using front and back pointers to solve it like a sliding window
	char *new_str = (char *)malloc(strlen(str)+1), *front = str, *back = str;
	memset(new_str, '\0', strlen(str)+1); // initialization of malloc'd string

	while (*front) {
		if (*(front + 1) == '\0' || *(front + 1) == ' ')  {
			// reverse each word
			char *rev = rev_str(back, front-back+1);
			// concat it to new string and move back pointer to next non space after front
			strcat(new_str, rev), back = front+2;
			free(rev);
		}

		front++;
	}

	// removing last space
	new_str[strlen(str)] = '\0';
	return new_str;
} // end spin_str()


int main()
{
	char str[] = "Hello World!", *spun_str = spin_str(str);

	printf("%s", spun_str);

	free(spun_str);

	return 0;
} // end main()
