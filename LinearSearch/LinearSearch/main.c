#include <stdio.h>
#include <stdlib.h>

#define SIZE 101

int linearSeach(const int arr[], int key, int size);

int main(void) {
	int searchKey;
	int element;
	int arr[SIZE];
	int count;

	//initialize array
	for (count = 0; count < SIZE; count++) {
		arr[count] = 0 + count;
	}

	printf("print the searched key integer (between 0 and 100): ");

	searchKey = -1;
	scanf("%d", &searchKey);

	//try to locate the searched key.
	element = linearSeach(arr ,searchKey, SIZE);

	if (element != -1) {
		printf("found value: %d\n", element);
	}
	else {
		printf("value could't be located");
	}

	system("pause");
	return 0;
}

int linearSeach(const int arr[], int key, int size) {
	int count;

	for (count = 0; count < SIZE; count++) {
		if (arr[count] == key) {
			return count;
		}
	}
	return -1;//key not found!
}