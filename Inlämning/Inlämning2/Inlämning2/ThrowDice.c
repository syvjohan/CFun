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

void drawDireMenu() {
	printf("Welcome to the throw dice game\n");
	printf("----------------------------------------------------\n");
	printf("Please enter the number of cast you wish to do: ");
}

void drawResult(int numbOfCast) {
	printf("\nResult of throwing the dice");
	printf("\nOne %d", dice.side1);
	printf("\nTwo %d", dice.side2);
	printf("\nThree %d", dice.side3);
	printf("\nFour %d", dice.side4);
	printf("\nFive %d", dice.side5);
	printf("\nSix %d", dice.side6);

	printf("\n\nFrequencies in percent");
	printf("\nOne %.1f%%", ((dice.side1 * 100) / numbOfCast));
	printf("\nTwo %.1f%%", ((dice.side2 * 100) / numbOfCast));
	printf("\nThree %.1f%%", ((dice.side3 * 100) / numbOfCast));
	printf("\nFour %.1f%%", ((dice.side4 * 100) / numbOfCast));
	printf("\nFive %.1f%%", ((dice.side5 * 100) / numbOfCast));
	printf("\nSix %.1f%%", ((dice.side6 * 100) / numbOfCast));
}


void castDire(int numbOfCast) {
	for (int i = 1; i != numbOfCast; i++) {	
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
		scanf("%d", &input);
		if (validateNumber(&input) == 0) {
			castDire(input);
		}
	} while (input <= 0);
}


