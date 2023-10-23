/*
 * Creator: Fasih Hasan Khan
 * Date: 23/10/23
 * Desc: finds a path from the start to the end of a maze
 */

#include <stdio.h>

#define marked 'V'

int create_path(char maze[5][5], int s_i, int s_j) 
{
    // base case
    if (maze[s_i][s_j] == 'E') {
    	maze[s_i][s_j] = marked;
    	return 1;
    }

    maze[s_i][s_j] = marked; // mark traversed path

    // right
    if (s_j + 1 < 5 && maze[s_i][s_j + 1] != 'W' && maze[s_i][s_j + 1] != marked)
        if (create_path(maze, s_i, s_j + 1)) return 1;

    // down
    if (s_i + 1 < 5 && maze[s_i + 1][s_j] != 'W' && maze[s_i + 1][s_j] != marked)
        if (create_path(maze, s_i + 1, s_j)) return 1;

    // go back
    maze[s_i][s_j] = 'O';
    return 0;
} // create_path(char[][5], int, int)

void show_path(char maze[5][5]) 
{
	// show points where marked as visited
	for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) if (maze[i][j] == marked) printf("%d,%d  ", i, j);
} // show_path(char[][5])

void show_maze(char maze[5][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}
} // show_maze(char[][5])

int main()
{
	int s_i, s_j;
	char maze[5][5];

	// input maze elements
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("Enter maze element at (%d, %d): ", i, j);
			scanf(" %c", &maze[i][j]);

			// saving start point
			if (maze[i][j] == 'S') {
				s_i = i;
				s_j = j;
			}
		}
	}

	printf("\n");
	show_maze(maze); // output maze
	printf("\nPath to complete maze:\n")
	create_path(maze, s_i, s_j);
	show_path(maze); // output path
	
	return 0;
} // end main()
