//Johan Fredriksson AB5785.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define FLAGG 1
#define MINSIZE 1
#define MAXSIZE 100

void menu();
int readNumber(int *outInt);
int generateRndNum();

int main(void)  
{

	int rndNum;
	int count;
	int input;
	int temp;
	
	//sets the seed with help of time.
	srand(time(NULL));

	menu();
	rndNum = generateRndNum();
	count = 0;

	do {
		scanf("%d", &input);
		temp = input;
		if (readNumber(&input) == 0) {
			if (temp >= MINSIZE && temp <= MAXSIZE) {
				if (temp == rndNum) {
					printf("\nCongratulations you guessed correct number\n");
					printf("Total number of guesses was: %d\n\n", count);
					#undef FLAGG
					rndNum = generateRndNum();
					menu();
				} else if (temp > rndNum) {
					printf("%dWrong number input was to high, guess again: ", rndNum);
					count++;
				} else {
					printf("%dWrong number input was to low, guess again: ", rndNum);
					count++;
				}
			} else {
				printf("Input value must be between 1 and 100, guess again: ");
			}
		} else {
			printf("Input value shall be a number: ");
		}
	} while (1);

	return 0;
}

void menu() 
{
	printf("Welcome to the fabolous game, guess the number\n");
	printf("----------------------------------------------------\n");
	printf("Guess a number between 1 - 100: ");
}

int readNumber(int *outInt) 
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

	*outInt = result * mod;

	return 0;
}

int generateRndNum() 
{
	return rand() % MAXSIZE + 1;
}