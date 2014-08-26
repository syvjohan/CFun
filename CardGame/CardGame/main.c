#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 4
#define COLUMN 13 
#define CARD 52

void shuffle(int wDeck[][COLUMN]);
void deal(const int wDeck[][COLUMN], const char *wFace[], const char *wSuit[]);

int main(void) {

	const char *suit[ROW] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	const char *face[COLUMN] =
	{
		"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
		"Ten", "Jack", "Queen", "King"
	};

	int deck[ROW][COLUMN] = { 0 };

	srand( time( 0 ) );

	shuffle(deck);
	deal(deck, face, suit);

	system("pause");
	return 0;
}

void shuffle(int wDeck[][COLUMN]) {
	int row;
	int column;
	int card;

	for (card = 1; card <= CARD; card++) {
		/* choose new random location until unoccupied slot found */
		do {
			row = rand() % ROW;
			column = rand() % COLUMN;
		} while (wDeck[row][column] != 0);

		wDeck[row][column] = card;
	}
}

void deal(const int wDeck[][COLUMN], const char *wFace[], const char *wSuit[]) {
	int card;
	int row;
	int column;

	/* deal each of the 52 cards */
	for (card = 1; card <= CARD; card++) {
		for (row = 0; row <= 3; row++) {
			for (column = 0; column <= 12; column++) {
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card) {
					printf("%5s of %-8s%c", wFace[column], wSuit[row],
						card % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}
}