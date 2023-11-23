/*
 * Creators: Fasih Hasan, Syed Ukkashah, Muhammad Ali
 * Date (Last changed): 23/11/23
 * Desc: A game called connect 4. First player to create a sequence of 4 characters in a row in a 6 by 7 grid will win
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define P1 'R'
#define P2 'B'
#define X '.'

const int rows = 6, cols = 7;

// create a game grid
char **create_game_grid(); // by Ali, modi

// uses the window lib to color the text
void color_char(char player); // by Fasih

// print the game grid
void print_grid(char **grid); // by Ali, modified by Fasih and Ukkashah

// update the frame by clearing the screen and printing the grid
void update_frame(char **grid); // by Fasih

// user input for the column number
int user_input(int player); // by Ukkashah

// validate a move in the specified column
bool validate_move(char **grid, int col); // by Fasih

// get the first empty row in a column
int get_first_empty(char **grid, int col); // by Ukkashah

// set the grid at the specified column and row with the player's character
void set_grid(char **grid, int col, int player); // by Ukkashah

// check the win status of the game after a move
bool game_win_status(char **grid, int col, int player); // by Fasih, Ali and Ukkashah

// displays relevant game end screen to player
void game_end_display(char **grid, int player, bool type); // by Ali

/*
		to-do:

- draw condition
- save wins and display them at the end
*/

int main()
{
	int player, col;
	bool valid = true, win = false;
	char player_char, **grid = create_game_grid();

	// default color scheme
	system("Color 0E");

	// game loop
	while (!win) {
		// for each player
		for (player = 0; player < 2; player++) {
			// loop until valid input
			do {
				update_frame(grid);
				if (!valid) printf("-- Enter appropriate column number --\n\n");
				col = user_input(player);
				valid = validate_move(grid, col);
			} while (!valid);

			// set to grid
			set_grid(grid, col, player);

			// check if win or draw
			win = game_win_status(grid, col, player);

			if (win) {
				break;
			}
		}
	}
	
	// display screen for WIN of player
	update_frame(grid);
	color_char((player) ? P1 : P2);
	printf(" WINS");

	// resetting color scheme
	system("Color 07");
	return 0; // end
} // end main()


char **create_game_grid()
{
	// creates double pointer for number of rows
	char **grid = (char **)malloc(sizeof(char *) * rows);

	// creates single pointers and sets them in all rows
	for (int i = 0; i < rows; i++) {
		grid[i] = (char *)malloc(sizeof(char) * cols);
	}

	// initializing as default
	for (int i = 0; i < rows; i++) {
		memset(grid[i], X, cols);
	}

	return grid;
} // end create_game_grid()

void color_char(char player)
{
	switch (player) {
        case P1:
        	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("%c", player); // Red color for P1
            break;
        case P2:
        	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
            printf("%c", player); // Blue color for P2
            break;
        default:
            printf("%c", player);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
} // end color_char()

void print_grid(char **grid)
{
	
	printf("%-4c", ' ');
	for (int i = 0; i < cols; i++) {
		printf("%-4d", i+1);
	}
	printf("\n");
	printf("%-2c|", ' ');
	for (int i = 2; i <= cols*4; i++) printf("%c", '-');
	printf("|");

	printf("\n");
	for (int i = 0; i < rows; i++) {
		printf("%d | ", i+1);
		for (int j = 0; j < cols; j++) {
			if (j == cols - 1) {
				color_char(grid[i][j]);
				printf(" |");
				break;
			}
			color_char(grid[i][j]);
			printf("%-3c", ' ');
		}
		if (i == rows - 1) continue;
		printf("\n");
		printf("%3c", '|');
		for (int i = 2; i < cols*4; i++) printf("%c", ' ');
		printf(" |\n");
	}
	printf("\n");
	printf("%-2c|", ' ');
	for (int i = 2; i <= cols*4; i++) printf("%c", '-');
	printf("|\n\n");
} // end print_grid(Player **)


void update_frame(char **grid)
{
	// clear screen and print grid
	system("cls");
	print_grid(grid);
} // end update_frame()


int user_input(int player)
{
	char col;
	printf("Enter column number for Player %d: ", player+1);
	scanf(" %c", &col);

	return col-'1';
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


void set_grid(char **grid, int col, int player)
{
	// get row where empty slot
	int row = get_first_empty(grid, col);
	grid[row][col] = (player) ? P1 : P2;
} // end set_grid()


bool game_win_status(char **grid, int col, int player)
{
	// getting row of current player character
	char player_char = (player) ? P1 : P2;
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
	if (col - 3 >= 0 && row - 3 >= 0) {
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
