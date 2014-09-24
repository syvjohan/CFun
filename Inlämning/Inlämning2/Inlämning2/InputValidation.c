// Johan Fredriksson AB5785.
#include "Defs.h"
#include "InputValidation.h"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

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