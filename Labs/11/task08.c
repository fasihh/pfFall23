/*
 * Creator: Fasih Hasan Khan
 * Date: 26/11/23
 * Description: fidning volume of the parallelepiped box if it can pass through a 41 feet tunnel (???)
 */

#include <stdio.h>

typedef struct {
	int length;
	int width;
	int height;
} Box;


int main()
{
	Box box;
	printf("Enter box length, width and heiht in format 'l w h': ");
	scanf("%d %d %d", &box.length, &box.width, &box.height);

	if (box.height >= 41) {
		printf("box shall not pass");
		return 0;
	}

	printf("volume of box: %d", box.length * box.height * box.width);

	return 0;
} // end main()
