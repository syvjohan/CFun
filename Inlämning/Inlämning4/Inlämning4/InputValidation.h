#pragma once

#include <ctype.h>
#include <stdio.h>
#include <string.h>

//For number input.
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

//For string input
int getLine(char buffer[], size_t sz) {
	size_t i = 0;
	char c;

	while ((c = getchar()) != EOF && c != '\n' && i < sz)
		buffer[i++] = c;

	buffer[i] = '\0';
	return i;
}