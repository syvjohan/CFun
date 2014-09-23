#include "Defs.h"
#include "GuessNumber.h"
#include "InputValidation.h"
#include "GameManager.h"
#include "Random.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void drawGuessMenu(void) {
	printf("\nWelcome to the fabolous game, guess the number\n");
	printf("----------------------------------------------------\n");
	printf("guess a number between 1 - 100: ");
}

//Handle input and draw.
void handleInput(void) {
	int rndNum;
	int count = 0;
	int input = -1;
	int temp = 0;
	rndNum = generateRndNum(MAXSIZE);
	do {
		scanf("%d", &input);
		temp = input;
		if (validateNumber(&input) == 0) {
			if (temp >= MINSIZE && temp <= MAXSIZE) {
				if (temp == rndNum) {
					printf("\nCongratulations you guessed correct number\n");
					printf("Total number of guesses was: %d\n", count);
					printf("---------------------------------------------\n\n");
#undef FLAGG
					setState(GS_MAINMENU);
					manage(); //Go back to main menu.
				} else if (temp > rndNum) {
					/*printf("Wrong number input was to high, guess again: ");*/ printf("%dwrong number input was to high, guess again: ", rndNum); /*line for testing game*/
					count++;
				} else {
					/*printf("Wrong number input was to low, guess again: ");*/ printf("%dWrong number input was to low, guess again: ", rndNum); /*line for testing game.*/
					count++;
				}
			} else {
				printf("Input value must be between 1 and 100, guess again: ");
			}
		} else {
			printf("Input value shall be a number: ");
		}
	} while (1);
}


