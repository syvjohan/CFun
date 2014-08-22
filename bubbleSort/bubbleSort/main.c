#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main(void) {

	int hold;
	int count;
	int pass;
	int arr[SIZE] = {10, 23, 45, 89, 32, 7, 97, 33, 22, 11};

	printf("numbers in original order:\n");
	for (count = 0; count < SIZE; count++) {
		printf("%4d", arr[count]);
	}

	//Bubble sort!
	//controll number of passes!
	for (pass = 1; pass <SIZE; pass++) {
		//controll comparisons/pass
		for ( count = 0; count < SIZE - 1; count++) {
			if (arr[count] > arr[count + 1]) {
				hold = arr[count];
				arr[count] = arr[count + 1];
				arr[count + 1] = hold;
			}
		}
	}

	printf("\n\nBubble sorted in adjacent order:\n");
	for (count = 0; count < SIZE; count++) {
		printf("%4d", arr[count]);
	}

	printf("\n\n");

	system("pause");
	return 0;

}