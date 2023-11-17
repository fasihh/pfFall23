#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10
#define f_name "wins.txt"

typedef struct {
	int y;
	int x;
} Position;

// default settings
const char X = ' ', P1 = 'R', P2 = 'B';
const int rows = 6, cols = 7;


// create a game grid
char **create_game_grid();

// print the game grid
void print_grid(char **grid);

// update the frame by clearing the screen and printing the grid
void update_frame(char **grid);

// user input for the column number
int user_input(int player);

// validate a move in the specified column
bool validate_move(char **grid, int col);

// get the first empty row in a column
int get_first_empty(char **grid, int col);

// set the grid at the specified column and row with the player's character
void set_grid(char **grid, int col, char player_char);

// check the win status of the game after a move
bool game_win_status(char **grid, int col, char player_char);

// check if the game is a draw
bool game_draw_status(char **grid);

// extracts player wins from the wins file
int *save_win(int player);

// shows the wins for each player
void display_wins(int player);


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
				display_wins(player);
				return 0;
			}
		}
	}

	fin:
	update_frame(grid);
	(player) ? printf("%c wins", P1) : printf("%c wins", P2);
	display_wins(player);

	return 1;
} // end main()


char **create_game_grid()
{
	// creates double pointer for number of rows
	char **grid = (char **)malloc(sizeof(char *) * rows);

	// creates single pointers and sets them in all rows
	for (int i = 0; i < rows; i++) grid[i] = (char *)malloc(sizeof(char) * cols);

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
} // end update_frame()


int user_input(int player)
{
	int col;
	printf("Enter column number for Player %d: ", player+1);
	scanf("%d", &col);

	return col-1;
} // user_input(int)


bool validate_move(char **grid, int col)
{
    // range check and overflow check
    return (col < cols && col >= 0) ? grid[0][col] == X : false;
} // end validate_move()


int get_first_empty(char **grid, int col)
{
	int i = rows-1;
	for (i; i >= 0; i--)
		// loop from bottom until first non player character found
		if (grid[i][col] != X) continue;
		else break;
	return i;
} // end get_first_empty()


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
} // end game_win_status()


bool game_draw_status(char **grid)
{
	// if top row is not full return false
	for (int i = 0; i < cols; i++) if (grid[0][i] == X) return false;
	return true;
} // end game_draw_status()


int *save_win(int player)
{
	char line[BUFFER_SIZE], player1[BUFFER_SIZE], player2[BUFFER_SIZE];;
	int *wins = (int *)calloc(2, sizeof(int));

	FILE *f_ptr = fopen(f_name, "r");

	// if file exists
	if (f_ptr != NULL) {
		for (int i = 0;!feof(f_ptr); i++) {
			// reading win from file
			fgets(line, BUFFER_SIZE, f_ptr);

			// trimming string
			line[strcspn(line, "\n")] = 0;

			// adding into win of the player
			wins[i] = atoi(line) + (i == player);
		}

		fclose(f_ptr);
	}

	f_ptr = fopen(f_name, "w");

	// converting integer to string
	itoa(wins[0], player1, BUFFER_SIZE);
	itoa(wins[1], player2, BUFFER_SIZE);

	// adding strings to the line buffer
	sprintf(line, "%s\n%s", player1, player2);

	// writing the lines in to the file
	fprintf(f_ptr, line);

	fclose(f_ptr);

	return wins;
} // end save_win()

void display_wins(int player)
{
	// get wins from the file
	int *wins = save_win(player);
	printf("\nTotal %c wins: %d\nTotal %c wins: %d", P1, wins[1], P2, wins[0]);
} // end display_wins()
