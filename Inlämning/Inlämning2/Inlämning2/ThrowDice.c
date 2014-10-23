// Johan Fredriksson AB5785.
#include "Defs.h"
#include "GameManager.h"
#include "Random.h"
#include "InputValidation.h"

#include <stdio.h>
#include <stdlib.h>

struct Dice 
{
	int side1;
	int side2;
	int side3;
	int side4;
	int side5;
	int side6;
}dice;

void drawDiceMenu() 
{
	printf("\nWelcome to the throw dice game.\n");
	printf("Beware program is implemented with UINT_MAX, huge numbers are alowed (4294967295U) it will take som time to calculate!\n\n");
	printf("----------------------------------------------------\n");
	printf("Please enter the number of cast you wish to do: ");
}

double dicePercent(double side, double numbOfCast) 
{
	double result = side / numbOfCast;
	return result * 100;
}

void drawDiceResult(double numbOfCast) 
{
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

void castDice(double numbOfCast)
{
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

void handleDiceInput() 
{
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


