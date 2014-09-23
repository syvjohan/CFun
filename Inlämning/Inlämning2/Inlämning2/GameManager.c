#include "Defs.h"
#include "GameManager.h"
#include "GuessNumber.h"
#include "Fibonacci.h"
#include "ThrowDice.h"
#include "InputValidation.h"

gameState currentState;

void initializeGame() {
	srand(time(NULL)); /*sets the seed in random generator*/
	currentState = GS_MAINMENU;
	manage();
}

void manage() {
	if (getCurrentState() == GS_MAINMENU) {
		drawMainMenu();
		selection();
	} else if (getCurrentState() == GS_GUESSNUMBER) {
		generateRndNum();
		drawGuessMenu();
		handleInput();
	} else if (getCurrentState() == GS_THROWDICE) {
		drawDiceMenu();
		select();
	} else if (getCurrentState() == GS_FIBONACCI) {

	} else {
		//If something goes really wrong....
		initializeGame();
	}
}

gameState setState(gameState state) {
	return (currentState = state);
}

gameState getCurrentState() {
	return currentState;
}

void drawMainMenu() {
	printf("*****Menu*****\n");
	printf("1. Guess Number\n"
		   "2. Throw Dice\n"
		   "3. Fibonacci\n"
		   "4. Exit\n");
	printf("Specify an option (1-4): ");
}

void selection() {
	int choice = -1;

	do {
		scanf("%d", &choice);
		if (validateNumber(&choice) == 0) {
			switch (choice) {
			case 1:
				setState(GS_GUESSNUMBER);
				manage();
				break;
			case 2:
				setState(GS_THROWDICE);
				manage();
				break;
			case 3:
				setState(GS_FIBONACCI);
				manage();
				break;
			}
		} else {
			printf("Invalid input!\n");
			drawMainMenu();
		}

	} while (choice != 4);
}
