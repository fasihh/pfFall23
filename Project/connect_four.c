#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

const char X = ' ';
const char P1 = 'R';
const char P2 = 'B';

const int rows = 6;
const int cols = 7;

typedef struct {
	char type;
} Player;

typedef struct {
	int y;
	int x;
} Position;


char **create_game_grid()
{
	// creates double pointer for number of rows
	char **grid = (char **)malloc(sizeof(char *) * rows);

	// creates single pointer and sets them in all rows
	for (int i = 0; i < rows; i++) {
		grid[i] = (char *)malloc(sizeof(char) * cols);
	}

	// initializing as default
	for (int i = 0; i < rows; i++) 
		for (int j = 0; j < cols; j++)
			grid[i][j] = X;

	return grid;
} // end create_game_grid()


void print_grid(char **grid)
{
	printf("%-2c", ' ');
	for (int i = 0; i < cols; i++) printf("%-4d", i+1);
	printf("\n");
	for (int i = 0; i < rows; i++) {
		printf("%-2d", i+1);
		for (int j = 0; j < cols; j++)
			printf("%-4c", grid[i][j]);
		printf("\n\n");
	}
} // end print_grid(Player **)

void update_frame(char **grid)
{
	// clear screen and print grid
	system("cls");
	print_grid(grid);
}


int user_input(int turn)
{
	int col;
	printf("Enter column number for Player %d: ", turn+1);
	scanf("%d", &col);

	return col-1;
} // user_input(int)


bool validate_move(char **grid, int col)
{
    // range check and overflow check
    return (col < cols && col >= 0) ? grid[0][col] == X : false;
}


int get_first_empty(char **grid, int col)
{
	int i = rows-1;
	for (i; i >= 0; i--)
		// loop from bottom until first non player character found
		if (grid[i][col] != X) continue;
		else break;
	return i;
}


void set_grid(char **grid, int col, char player_char)
{
	// get row where empty slot
	int row = get_first_empty(grid, col);
	grid[row][col] = player_char;
} // end set_grid()


bool game_win_status(char **grid, int col, char player_char)
{
	// getting row of current player character
	int row = get_first_empty(grid, col)+1;

	// down
	if (row + 3 < rows) {
		if (grid[row+1][col] == player_char && grid[row+2][col] == player_char && grid[row+3][col] == player_char)
				return true;
	}

	// right
	if (col + 3 < cols) {
		if (grid[row][col+1] == player_char && grid[row][col+2] == player_char && grid[row][col+3] == player_char)
				return true;
	}

	// left
	if (col - 3 >= 0) {
		if (grid[row][col-1] == player_char && grid[row][col-2] == player_char && grid[row][col-3] == player_char)
				return true;
	}

	// up right
	if (col + 3 < cols && row - 3 >= 0) {
		if (grid[row-1][col+1] == player_char && grid[row-2][col+2] == player_char && grid[row-3][col+3] == player_char)
				return true;
	}

	// up left
	if (col - 3 >= 0 && rows - 3 >= 0) {
		if (grid[row-1][col-1] == player_char && grid[row-2][col-2] == player_char && grid[row-3][col-3] == player_char)
				return true;
	}

	// down right
	if (col + 3 < cols && row + 3 < rows) {
		if (grid[row+1][col+1] == player_char && grid[row+2][col+2] == player_char && grid[row+3][col+3] == player_char)
				return true;
	}

	// down left
	if (col - 3 >= 0 && row + 3 < rows) {
		if (grid[row+1][col-1] == player_char && grid[row+2][col-2] == player_char && grid[row+3][col-3] == player_char)
				return true;
	}

	return false;
}

bool game_draw_status(char **grid)
{
	// if top row is not full return false
	for (int i = 0; i < cols; i++) if (grid[0][i] == X) return false;
	return true;
}

int main()
{
	int player, col;
	bool valid = true;
	char **grid = create_game_grid();
	
	// game loop
	while (1) {
		// for each player
		for (player = 0; player < 2; player++) {
			char player_char = (player) ? P1 : P2;

			// loop until valid input
			do {
				update_frame(grid);
				if (!valid) printf("-- Enter appropriate column number --\n\n");
				col = user_input(player);
				valid = validate_move(grid, col);
			} while (!valid);

			// set to grid
			set_grid(grid, col, player_char);

			// check if win or draw
			bool win = game_win_status(grid, col, player_char);
			bool draw = game_draw_status(grid);
			if (win) {
				goto fin;
			} else if (draw) {
				printf("DRAW");
				return 0;
			}
		}
	}

	fin:
	update_frame(grid);
	(player) ? printf("%c wins", P1) : printf("%c wins", P2);
	return 0;
} // end main()
