#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int i;
	int arr[10];

	for (i = 0; i < 10; i++) {
		arr[i] = 0;
	}

	printf("%s%13s\n", "Element", "Value");

	for (i = 0; i < 10; i++) {
		printf("%7i%13i\n", i, arr[i]);
	}

	system("pause");
	return 0;
}