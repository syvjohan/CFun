#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int readNumber(int *outInt);

int main(void) {

	int in = 0;
	scanf(" %d", in);


	if (readNumber(&in) == 0) {
		printf("is a number");
	} else {
		printf("not a number");
	}

	system("pause");
	return 0;
}

int readNumber(int *outInt) {
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

	*outInt = result * mod;

	return 0;
}