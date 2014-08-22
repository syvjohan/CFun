#include <stdio.h>
#include <stdlib.h>
	
#define SIZE 10

int main(void) {
	int n[SIZE] = {5, 4, 10, 45, 33, 27, 14, 2, 9, 25};
	int i;
	int j;

	printf("%s%13s%17s\n", "Element", "Value", "Histogram");

	for (i = 0; i < SIZE; i++) {
		printf("%7d%13d       ", i, n[i]);

		for (j = 1; j < n[i]; j++) {
			printf("%c", '*');
		}
		printf("\n");
	}

	system("pause");
	return 0;

}