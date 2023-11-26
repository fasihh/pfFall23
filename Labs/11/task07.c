/*
 * Creator: Fasih Hasan Khan
 * Date: 26/11/23
 * Description: making a library management system using structs
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
	int num;
	char author[20];
	char name[30];
	bool issued;
} Book;

void display_books(Book books[100], int size)
{
	printf("\nAll books (%d) info:", size);
	for (int i = 0; i < size; i++) {
		printf("\nBook number: %d\nBook author: %s\nBook  title: %s\nBook issued: %s\n",
			books[i].num,
			books[i].author,
			books[i].name,
			(books[i].issued) ? "YES" : "NO"
		);
	}
	printf("\n");
} // end display_books()

int add_book(Book books[100], int *size)
{
	if (*size > 99) {
		printf("\n--Max books reached--\n");
		return *size;
	}

	printf("\n--Add book--\n");
	Book book;

	printf("Enter book number: ");
	scanf("%d", &book.num); fflush(stdin);

	printf("Enter book author: ");
	fgets(book.author, 20, stdin); fflush(stdin);
	book.author[strlen(book.author)-1] = 0;

	printf("Enter book name: ");
	fgets(book.name, 30, stdin); fflush(stdin);
	book.name[strlen(book.name)-1] = 0;

	book.issued = false;

	books[*size] = book;
	*size += 1; // increasing size of array

	printf("--Book inserted--\n\n");

	return *size;
} // end add_book()

int title_count(Book books[100], int size, char *title)
{
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (!strcmp(books[i].name, title)) count++;
	}
	return count;
} // end title_count()

int books_count(Book books[100], int size)
{
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (!books[i].issued) count++; // if not issued
	}
	return count;
} // end books_count

int issue_book(Book books[100], int *size)
{
	int num;

	printf("\nEnter book number to issue: ");
	scanf("%d", &num);

	for (int i = 0; i < *size; i++) {
		if (num == books[i].num) {
			books[i].issued = true;
			return *size - 1; // returning new book count
		}
	}

	printf("\n--Book does not exist--\n");
	return *size;
} // end issue_book()

int main()
{
	Book books[100] = {
		{9123, "Serena Everhart", "Whispers in the Wind", false},
		{9456, "Donovan Steele", "Ephemeral Echoes", false},
		{9789, "Isabella Blackwood", "Labyrinth of Shadows", false},
		{1122, "Orion Nightshade", "Chronicles of Stardust", false},
		{1455, "Lila Moon", "Silent Serenade", false},
		{1788, "Xavier Storm", "Enigma's Embrace", false},
		{2121, "Celeste Rivers", "Midnight Mirage", false},
		{2454, "Lyra Starling", "Surrender to the Stars", false},
		{2787, "Damien Darkwood", "Crimson Cascade", false},
		{3120, "Aurora Skye", "Veil of Visions", false},
		{3453, "Thalia Ember", "Whirlwind Whispers", false},
		{3786, "Victor Eclipsion", "Quantum Quill", false},
		{4119, "Seraphina Frost", "Mystic Masquerade", false},
		{4452, "Gabriel Shadowheart", "Eternal Echo", false},
		{4785, "Selene Dusk", "Rogue Reflections", false},
		{5118, "Astrid Nova", "Aetherial Alchemy", false},
		{5451, "Caspian Mirage", "The Oracle's Overture", false},
		{5784, "Raven Nightshade", "Crimson Chronicles", false},
		{6117, "Elysia Enchant", "Whispering Woods", false},
		{6450, "Octavia Moonfall", "Spectral Symphony", false}
	};
	int size = 20, total_books = books_count(books, size);

	display_books(books, size);
	total_books = add_book(books, &size);

	char name[20];
	printf("Enter book name: ");
	fgets(name, 30, stdin); fflush(stdin);
	name[strlen(name)-1] = 0;

	printf("Number of books with the title: %d\n", title_count(books, size, name));

	printf("\nTotal books in the library: %d\n", total_books);

	total_books = issue_book(books, &size);
	display_books(books, size);
	
	printf("\nTotal books in the library: %d\n", total_books);

	return 0;
} // end main()
