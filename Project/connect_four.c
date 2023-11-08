#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define P1 'R'
#define P2 'B'
#define X ' '

#define rows 6
#define cols 7

typedef struct {
	char type;
} Player;

typedef struct {
	int y;
	int x;
} Position;


Player **create_game_grid()
{
	// creates double pointer for number of rows
	Player **grid = (Player **)malloc(sizeof(Player *) * rows);

	// creates single pointer and sets them in all rows
	for (int i = 0; i < rows; i++) {
		grid[i] = (Player *)malloc(sizeof(Player) * cols);
	}

	// initializing as default
	for (int i = 0; i < rows; i++) 
		for (int j = 0; j < cols; j++)
			grid[i][j].type = X;

	return grid;
} // end create_game_grid()


void print_grid(Player **grid)
{
	printf("%-2c", ' ');
	for (int i = 0; i < cols; i++) printf("%-4d", i+1);
	printf("\n");
	for (int i = 0; i < rows; i++) {
		printf("%-2d", i+1);
		for (int j = 0; j < cols; j++)
			printf("%-4c", grid[i][j].type);
		printf("\n\n");
	}
} // end print_grid(Player **)


Position user_input(int turn)
{
	Position pos;
	printf("Enter x co-ords for Player %d: ", turn+1);
	scanf("%d", &pos.x);
	printf("Enter y co-ords for Player %d: ", turn+1);
	scanf("%d", &pos.y);
	pos.x--, pos.y--;

	return pos;
} // user_input(int)


void set_grid(Player **grid, Position pos, int turn)
{
	// sets char on given co-ords according to player turn val
	grid[pos.y][pos.x].type = (turn & 1) ? P2 : P1;
} // end set_grid(Player **, int, int)


bool validate_move(Player **grid, Position pos)
{
	// boundary check
    if (pos.x < 0 || pos.x >= cols || pos.y < 0 || pos.y >= rows) {
        return false;
    }

    // check if free
    return (grid[pos.y][pos.x].type == X);
}

int main()
{
	int player;
	Position pos;
	bool valid = true;
	Player **grid = create_game_grid();

	// game loop
	while (1) {
		// for each player
		for (player = 0; player < 2; player++) {
			// loop until valid input
			do {
				system("cls");
				print_grid(grid);
				if (!valid) printf("-- Enter appropriate co-ords --\n\n");
				pos = user_input(player);
				valid = validate_move(grid, pos);
			} while (!valid);
			// sets value in grid
			set_grid(grid, pos, player);
		}
	}

	return 0;
} // end main()
