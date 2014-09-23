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

int validateIntMax(int number) {
	if (number != INT_MAX) {
		return 1;
	} else {
		return 0;
	}
}
