#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void writeTofile();
void createAndOpenFile();
int validateFileExtension();
int validateFileName();

typedef struct 
{
	int age;
	char name[50];
	int idNum;
	int tableIdNum;

}Customer;

char fileName[50];

FILE *cfPtr;

int main(void) {

	printf("write the name and extension on the file you would like to open:\n");
	scanf("%s", &fileName);

	// Open the file if filename exist and extension is ok!
	if(validateFileName(fileName) == 1) {
		if (validateFileExtension(fileName) == 1) {
			// if the file exist open and write to it!
			writeTofile();

		} else {
			printf("extension is not supported");
		}

	} else {
		printf("file could not be found \n");
		createAndOpenFile(fileName);
	}

	system("pause");
	return 0;
}

void createAndOpenFile(char fileName[]) {

	char choice;
	do {
		printf("Would you like to create a new file with the filename %s", fileName);
		printf("?\nPress (y), (n) or (e): ");

		scanf(" %c", &choice);

		switch (choice)
		{
		case 'y':
			cfPtr = fopen (fileName, "wb");
			writeTofile();
			break;
		case 'n':
			memset(fileName, 0, sizeof(fileName)); // empty the filename array.
			printf("write the name on the file you would like to open:\n");
			scanf("%s", &fileName);

			if ((cfPtr = fopen(fileName, "rb+")) == NULL) {
				printf("file could not be opened \n");
			}
			else {
				writeTofile();
			}
			break;
		case 'e':
			break;
		default:
			printf("\nInvalid character!\n");
			break;
		}
	} while(choice != 'e');
}

int validateFileExtension(const char fileName[]) {

	const char extension[] = {'txt', 'c', 'cpp', 'xml', 'html'};
	// Determines the number of elements in the array.
	int numElement = sizeof(extension) / sizeof(int);
	int i;
	for (i = 0; i <= numElement; i++) {
		const char *dot = strrchr(fileName, i);
		if (!dot || dot == fileName) {
			return 0;
		}
		return 1;
	}
}

int validateFileName(const char fileName[]) {

	if ((cfPtr = fopen(fileName, "rb+")) == NULL) {
		return 0;
	}
	return 1;
}

void writeTofile() {

	Customer customer = {0, "", 0, 0};

	printf("Enter a tableIdNum between (1 and 10, 0 to end input):\n");
	scanf("%i", &customer.tableIdNum);

	while (customer.tableIdNum != 0) {
		printf("Enter: age, name, id number\n");

		// Set values
		fscanf(stdin, "%i%s%i", &customer.age, customer.name, &customer.idNum);

		//seek position in file
		fseek( cfPtr, (customer.idNum - 1) *
			sizeof(Customer), SEEK_SET);

		//Write information in file
		fwrite(&customer, sizeof(Customer), 1, cfPtr);

		//enable user to write new input to file,
		printf("Enter a tableIdNum between (1 and 10, 0 to end input):\n");
		scanf("%i", &customer.tableIdNum);

	}
	fclose(cfPtr);
}