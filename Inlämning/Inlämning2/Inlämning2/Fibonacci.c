// Johan Fredriksson AB5785.
#include "Defs.h"
#include "Fibonacci.h"
#include "GameManager.h"
#include "InputValidation.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

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