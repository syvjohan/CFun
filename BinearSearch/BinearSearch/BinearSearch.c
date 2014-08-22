#include <stdlib.h>
#include <stdio.h>

#define SIZE 15

int binearSearch(const int arr[], int key, int low, int high);
int printRow(const int arr[], int row, int low, int high);
void printHeader(void);

int main(void) {
	int arr[SIZE];
	int element;
	int searchKey;
	int count;

	for (count = 0; count < SIZE; count++) {
		arr[count] = 2 * count;
	}

	printf("Enter a number between 0 and 28: \n");
	scanf("%d", &searchKey);

	printHeader();

	element = binearSearch(arr, searchKey, 0, SIZE - 1);

	if (element != -1) {
		printf("\n%dvalue found in array%d\n", searchKey, element);
	}
	else {
		printf("\n%dSearched value not found in array\n", searchKey);
	}

	system("pause");
	return 0;
}

int binearSearch(const int arr[], int key, int low, int high) {
	int middle;

	while (low <= high) {
		middle = (low + high) / 2;

		printRow(arr, low, middle, high);

		if (key == arr[middle]) {
			return middle;
		}
		else if (key < arr[middle]) {
			high = middle - 1;
		}
		else {
			low = middle + 1;
		}
	}
	return -1;//searched key not found!
}

int printRow(const int arr[], int middle, int low, int high) {
	int counter;

	for (counter = 0; counter < SIZE; counter++) {
		if (counter < low || counter > high) {
			printf("  ");
		}
		else if (counter == middle) {
			printf("%3d*", arr[counter]);
		}
		else {
			printf("%3d", arr[counter]);
		}
	}
	printf("\n");
}

void printHeader(void) {
	int count;
	printf("\nSubscripts:\n"); 

	 for (count = 0; count < SIZE; count++) {
		 printf("%3d", count);
	 }

	 printf("\n");

	 for (count = 1; count <= 4 * SIZE; count++) {
		 printf("-");
	 }

	 printf("\n");

}