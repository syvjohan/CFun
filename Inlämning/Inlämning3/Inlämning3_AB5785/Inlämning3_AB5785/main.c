//Johan Fredriksson AB5785
#include <stdio.h>
#include <time.h>

#define SIZE 10

void fill_rand_ver1(int array[], int size) {
	int i;
	for (i = 0; i != size; ++i) {
		array[i] = ((rand() % size) + 1);
	}
}

void sort_ver1(int array[], int size) {
	int i, j, temp;
	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size; j++) {
			if (array[j] < array[i]) {
				//Swap.
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}
}

void print_values_ver1(char string[], int array[], int size) {
	int i;
	for (i = 0; string[i] != '\0'; i++) {
		printf("%c", string[i]);
	}
	printf("\n");
	for (i = 0; i != size; i++) {
		printf("%i ", array[i]);
	}
	printf("\n\n");
}


void fill_rand_ver2(int *pointer, int size) {
	int *pi;
	for (pi = pointer; pi != (pointer + size); pi++) {
		int r = ((rand() % size) + 1);
		*pi = r;
	}
}

void sort_ver2(int *pointer, int size) {
	int *pi;
	int *pj;
	int temp;
	for (pi = pointer; pi < (pointer + size); pi++) {
		for (pj = (pi + 1); pj < (pointer + size); pj++) {
			if (*pj < *pi) {
				//Swap.
				temp = *pj;
				*pj = *pi;
				*pi = temp;
			}
		}
	}
}
void print_values_ver2(char *string, int *pointer, int size) {
	int *pi;
	int i;
	char *pc;
	pc = string;
	pi = pointer;

	printf("%s", pc);
	printf("\n");
	for (pi; pi < (pointer + size); pi++) {
		printf("%i ", *pi);
	}
	printf("\n\n");
}

void emptyArray(int array[], int size) {
	int i;
	for (i = 0; i != size; i++) {
		array[i] = '\0';
	}
}

int main() {
	int array[SIZE]; /* Deklarerar en array av integers */

	srand(time(NULL)); /* Frö till funktionen rand()*/

	fill_rand_ver1(array, SIZE); /* Fyll arrayen med slumptal */

	/* Skriv ut textsträngen och arrayens värden */
	print_values_ver1("Osorterad array, version 1", array, SIZE);

	sort_ver1(array, SIZE); /* Sortera arrayen */

	/* Skriv ut textsträngen och arrayens nu sorterade värden */
	print_values_ver1("Sorterad array, version 1", array, SIZE);

	int *pointer; /* Deklarerar en pekare av typen integer */

	emptyArray(array, SIZE);

	pointer = array; /* Pekaren initieras att peka på första elementet i arrayen */

	fill_rand_ver2(pointer, SIZE); /* Fyll arrayen med nya slumptal */

	/* Skriv ut textsträngen och arrayens värden */
	print_values_ver2("Osorterad array, version 2", pointer, SIZE);

	sort_ver2(pointer, SIZE); /* Sortera arrayen */

	/* Skriv ut textsträngen och arrayens nu sorterade värden */
	print_values_ver2("Sorterad array, version 2", pointer, SIZE);

	system("pause");
	return 0;
}