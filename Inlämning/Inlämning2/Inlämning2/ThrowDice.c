#include "Defs.h"
#include "GameManager.h"
#include "Random.h"
#include "InputValidation.h"

#include <stdio.h>
#include <stdlib.h>

struct Dice {
	int side1;
	int side2;
	int side3;
	int side4;
	int side5;
	int side6;
}dice;

void drawDiceMenu() {
	printf("Welcome to the throw dice game\n");
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
	for (int i = 0; i != numbOfCast; i++) {	
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
	drawResult(numbOfCast);
}

void select() {
	int input = -1;
	do {
		scanf(" %d", &input);
		if (validateIntMax(input) == 1) {
			if (validateNumber(&input) == 0) {
				castDice(input);
				setState(GS_MAINMENU);
				manage(); //Go back to main menu.
			}
			else {
				printf("Invalid input\n");
			}
		} else {
			printf("Number to big! maximum size is: %d\n", sizeof(__int32));
		}	
	} while (input <= 0);
}


