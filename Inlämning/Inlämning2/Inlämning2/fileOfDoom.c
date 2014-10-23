#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <crtdbg.h>
#include <ctype.h>

#define MALLOC(SZ) _malloc_dbg((SZ), _NORMAL_BLOCK, __FILE__, __LINE__)
#define CALLOC(C, SZ) _calloc_dbg((C), (SZ), _NORMAL_BLOCK, __FILE__, __LINE__)
#define REALLOC(PTR, SZ) _realloc_dbg(PTR, SZ, _NORMAL_BLOCK, __FILE__, __LINE__)

#define FLAGG 1
#define MINSIZE 1
#define MAXSIZE 100

typedef enum gameState{
	GS_MAINMENU,
	GS_QUIT,
	GS_GUESSNUMBER,
	GS_THROWDICE,
	GS_FIBONACCI
} gameState;

gameState currentState;

struct Dice {
	int side1;
	int side2;
	int side3;
	int side4;
	int side5;
	int side6;
}dice;

void initializeGame() {
	srand(time(NULL)); /*sets the seed in random generator*/
	currentState = GS_MAINMENU;
	manage();
}

void manage() {
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

void handleGameInput() {
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

void drawDiceMenu() {
	printf("\nWelcome to the throw dice game.\n");
	printf("Beware program is implemented with UINT_MAX, huge numbers are alowed (4294967295U) it will take som time to calculate!\n\n");
	printf("----------------------------------------------------\n");
	printf("Please enter the number of cast you wish to do: ");
}

double dicePercent(double side, double numbOfCast) {
	double result = side / numbOfCast;
	return result * 100;
}

void drawDiceResult(double numbOfCast) {
	printf("\nResult of throwing the dice %i", (int)numbOfCast);
	printf(" times");
	printf("\nOne %d", dice.side1);
	printf("\nTwo %d", dice.side2);
	printf("\nThree %d", dice.side3);
	printf("\nFour %d", dice.side4);
	printf("\nFive %d", dice.side5);
	printf("\nSix %d", dice.side6);

	printf("\n\nFrequencies in percent");
	printf("\nOne %.2f%%", dicePercent(dice.side1, numbOfCast));
	printf("\nTwo %.2f%%", dicePercent(dice.side2, numbOfCast));
	printf("\nThree %.2f%%", dicePercent(dice.side3, numbOfCast));
	printf("\nFour %.2f%%", dicePercent(dice.side4, numbOfCast));
	printf("\nFive %.2f%%", dicePercent(dice.side5, numbOfCast));
	printf("\nSix %.2f%%", dicePercent(dice.side6, numbOfCast));
	printf("\n----------------------------------------------------\n\n");
}

void castDice(double numbOfCast) {
	int i;
	for (i = 0; i != numbOfCast; i++) {
		int roll = generateRndNum(6);
		if (roll == 1) {
			dice.side1++;
		} else if (roll == 2) {
			dice.side2++;
		} else if (roll == 3) {
			dice.side3++;
		} else if (roll == 4) {
			dice.side4++;
		} else if (roll == 5) {
			dice.side5++;
		} else {
			dice.side6++;
		}
	}
	drawDiceResult(numbOfCast);
}

void handleDiceInput() {
	int input = -1;
	do {
		_flushall();
		scanf(" %d", &input);
		if (validateNumber(&input) == 0) {
			if (validateUINTMAX(input) == 1 && validateMin(input) == 1) {
				castDice(input);
				setState(GS_MAINMENU);
#undef FLAGG
				manage(); //Go back to main menu.
			} else {
				printf("\nValue not in range!\n");
				drawDiceMenu();
				handleDiceInput();
			}
		} else {
			printf("\nInput value shall be a number!\n");
			drawDiceMenu();
			handleDiceInput();
		}
	} while (1);
}

void drawFibMenu() {
	printf("\nWelcome to the fabolous game, that print fibonacci numbers.\n");
	printf("Beware program is implemented with UINT_MAX, huge numbers are alowed (4294967295U) it will take som time to calculate!\n");
	printf("\n----------------------------------------------------\n");
	printf("Print the maximum numbers to be printed: ");
}

void calculateFib(unsigned int iterations) {
	unsigned rIterations = iterations - 2;
	unsigned int v0, v1, tmp, i, k;
	v0 = 0;
	v1 = 1;
	if (iterations == 1) {
		printf("%u", v0);
	} else if (iterations == 2) {
		printf("%u %u", v0, v1);
	} else {
		printf("\n----------------------------------------------------\n");
		printf("The Fibonacci numbers are:\n");
		printf("%u %u ", v0, v1);
		for (i = 0; i != rIterations; ++i) {
			tmp = v0 + v1;
			printf("%u ", tmp);
			v0 = v1;
			v1 = tmp;
		}
	}

	printf("\n\n");
}

void handleFibInput() {
	int input = -1;
	do {
		_flushall();
		scanf(" %d", &input);
		if (validateNumber(&input) == 0) {
			if (validateUINTMAX(input) == 1 && validateMin(input) == 1) {
				calculateFib(input);
				setState(GS_MAINMENU);
#undef FLAGG
				manage(); //Go back to main menu.
			} else {
				printf("Number not in range!\n");
				drawFibMenu();
			}
		} else {
			printf("Invalid input!\n");
			drawFibMenu();
		}
	} while (1);
}

void drawGuessMenu(void) {
	printf("\nWelcome to the fabolous game, guess the number\n");
	printf("----------------------------------------------------\n");
	printf("guess a number between 1 - 100: ");
}

//Handle input and draw.
void handleGuessInput(void) {
	int rndNum;
	int count = 0;
	int input = -1;
	int temp = 0;
	rndNum = generateRndNum(MAXSIZE);
	do {
		_flushall();
		scanf(" %d", &input);
		temp = input;
		if (validateNumber(&input) == 0) {
			if (temp >= MINSIZE && temp <= MAXSIZE) {
				if (temp == rndNum) {
					printf("\nCongratulations you guessed correct number\n");
					printf("Total number of guesses was: %d\n", count);
					printf("---------------------------------------------\n\n");
					setState(GS_MAINMENU);
#undef FLAGG
					manage(); //Go back to main menu.
				} else if (temp > rndNum) {
					printf("Wrong number input was to high, guess again: "); /*printf("%dwrong number input was to high, guess again: ", rndNum);*/ /*line for testing game*/
					count++;
				} else {
					printf("Wrong number input was to low, guess again: "); /*printf("%dWrong number input was to low, guess again: ", rndNum); *//*line for testing game.*/
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

int validateNumber(int *outInt) {
	int result = 0;
	char in;
	int mod = 1;
	int first = 1;

	while ((in = getchar()) != EOF) {
		if (first && in == '-') {
			mod = -1;
		} else if (isdigit(in)) {
			result *= 10;
			result += in - '0';
		} else {
			break;
		}

		first = 0;
	}

	if (in != '\n' && in != '\r' && in != EOF && in != ' ' && in != '\t') {
		return -1;
	}

	//*outInt = result * mod;

	return 0;
}

int validateUINTMAX(int number) {
	if (number != UINT_MAX) {
		return 1;
	} else {
		return 0;
	}
}

int validateMin(int number) {
	if (number > 0) {
		return 1;
	}
	return 0;
}

int generateRndNum(int maxSize) {
	return rand() % maxSize + 1;
}

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //Check for memoryLeaks.

	//GameManager
	initializeGame();

	return 0;
}
//exit(0) tvångsstänger programmet utan att frigöra minnet innana avslut, stänger med felkod 0. Dålig programmeringsstil!!!!