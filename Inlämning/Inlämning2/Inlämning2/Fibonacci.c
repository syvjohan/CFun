#include "Defs.h"
#include "Fibonacci.h"
#include "GameManager.h"
#include "InputValidation.h"


void drawFibMenu() {
	printf("\nWelcome to the fabolous game, that print fibonacci numbers\n");
	printf("----------------------------------------------------\n");
	printf("Print the maximum numbers to be printed: ");
}

void drawFibResult() {

}

void calculateFibo(int maxNumber) {

}

void selectFib() {
	int input = -1;
	do {
		scanf(" %d", &input);
		if (validateIntMax(input) == 1) {
			if (validateNumber(&input) == 0) {
				calculateFibo(input);
				setState(GS_MAINMENU);
				manage(); //Go back to main menu.
			} else {
				printf("Invalid input\n");
			}
		} else {
			printf("Number to big! maximum size is: %d\n", sizeof(__int32));
		}
	} while (input <= 0);
}