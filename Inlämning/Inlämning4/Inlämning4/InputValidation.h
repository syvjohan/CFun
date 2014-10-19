//Johan Fredriksson AB5785.
#pragma once

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//For number input.
int validateNumber(int *outInt) 
{
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

////For string input
//int getLine(char buffer[]) {
//	size_t i = 0;
//	char c;
//
//	while ((c = getchar()) != EOF && c != '\n')
//		buffer[i++] = c;
//
//	buffer[i] = '\0';
//	return i;
//}
//
//char* memAllocation(char *msg) {
//	char *string;
//	string = malloc(40 * sizeof(char)); //Allocate memory for 30 chars.
//
//	if (sizeof(string) < sizeof(msg)) {
//		int size = sizeof(msg) / sizeof(msg[0]); //Gets the number of char in msg.
//		string = realloc(string, size * sizeof(char));
//
//		if (string == NULL) {
//			fprintf(stderr, "ERROR, unable to reallocate requaried memory\n");
//		} else {
//			strcpy(string, msg);
//		}
//	} else {
//		if (string == NULL) {
//			fprintf(stderr, "ERROR, unable to allocate memory\n");
//		} else {
//			strcpy(string, msg);
//		}
//	}
//
//	return string;
//}

