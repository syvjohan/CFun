#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int compare(const void *a, const void *b);

int main() {

	srand(time(0));
	char arr[SIZE];
	int i, temp;
	temp = 0;

	for (i = 0; i < SIZE; i++) {
		arr[i] = (rand() % 100) +1;
	}

	for (i = 0; i < SIZE; i++) {
		printf("%d\n", arr[i]);
	}

	for (i = 0; i < SIZE; i++) {
		if (arr[i] <= arr[i + 1]) {
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
		}
	}

	for (i = 0; i < SIZE; i++) {
		printf("%d\n", arr[i]);
	}

	system("pause");
	return 0;

}

int compare(const void *a, const void *b) {
	int int_a = *((int*)a);
	int int_b = *((int*)b);

	if (int_a == int_b) return 0;
	else if (int_a < int_b) return -1;
	else return 1;

	qsort(a, 6, sizeof(int), compare)
}