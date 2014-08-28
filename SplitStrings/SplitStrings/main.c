#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int main(void) {


	char text[] = {"a2"};

	char string[SIZE] = "";
	int num[SIZE] = {0};
	char space[SIZE] = "";
	int garbage[SIZE] = {0};

	int count;

	for (count = 1; text[count] != '\0'; count++) { 

		if (isalpha(text[count])) {
			string[count] = text[count];
		}	
		else if (isspace(text[count])) {
			space[count] = text[count];
		}
		else if (isalnum(text[count])) {
			num[count] = text[count];
		}
		else {
			garbage[count] = text[count];
		}
	}

	for (count = 0; count <= SIZE; count++) {

	//printf("all the strings\n");
	printf("%1c", string[count], "\n");

	//printf("all the spaces\n");
	//printf("%1c", space[count], "\n");

	//printf("all the numbers\n");
	printf("%1i", num[count], "\n");

	//printf("all the garbage\n");
	//printf("%1i", garbage[count], "\n");
	
	}

	system("pause");
	return 0;
}
