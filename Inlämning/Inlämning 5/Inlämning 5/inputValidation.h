//Johan Fredriksson AB5785.
#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

//Validates int input as a string.
int validateIntInput(int *input) {
	int result = 0;
	char in;
	int mod = 1;
	int first = 1;

	//iterate through the input (for each element).
	while ((in = getchar()) != EOF) {
		if (first && in == '-') {
			mod = -1;
		}
		else if (isdigit(in)) {
			result *= 10;
			result += in - '0';
		}
		else {
			break;
		}

		first = 0;
	}

	//Check if none off the characters is in the input.
	if (in != '\n' && in != '\r' && in != EOF && in != ' ' && in != '\t') {
		return -1;
	}

	//*outInt = result * mod;

	return 0;
}
