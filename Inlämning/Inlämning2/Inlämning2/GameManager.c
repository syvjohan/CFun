// Johan Fredriksson AB5785.
#include "Defs.h"
#include "GameManager.h"
#include "GuessNumber.h"
#include "Fibonacci.h"
#include "ThrowDice.h"
#include "InputValidation.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

gameState currentState;

void initializeGame() 
{
	srand(time(NULL)); /*sets the seed in random generator*/
	currentState = GS_MAINMENU;
	manage();
}

void manage()
{
	if (getCurrentState() == GS_MAINMENU) {
		drawMainMenu();
		handleGameInput();
	} else if (getCurrentState() == GS_GUESSNUMBER) {
		drawGuessMenu();
		handleGuessInput();
	} else if (getCurrentState() == GS_THROWDICE) {
		drawDiceMenu();
		handleDiceInput();
	} else if (getCurrentState() == GS_FIBONACCI) {
		drawFibMenu();
		handleFibInput();
	} else if (getCurrentState() == GS_QUIT) {
		exit(EXIT_SUCCESS); //Quit the program.
	} else {
		initializeGame(); //If something goes really wrong....
	}
}

gameState setState(gameState state) 
{
	return (currentState = state);
}

gameState getCurrentState()
{
	return currentState;
}

void drawMainMenu() 
{
	printf("*****Menu*****\n");
	printf("1. Guess Number\n"
		   "2. Throw Dice\n"
		   "3. Fibonacci\n"
		   "4. Exit\n");
	printf("Specify an option (1-4): ");
}

void handleGameInput()
{
	int choice = -1;
	do {
		_flushall();
		scanf(" %d", &choice);
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
			case 4:
				setState(GS_QUIT);
				manage();
				break;
			default:
				manage();
				printf("\n");
				break;
			}
		} else {
			printf("\nInput value shall be a number!\n\n");
			drawMainMenu();
		}
	} while (getCurrentState() == GS_MAINMENU);
}
