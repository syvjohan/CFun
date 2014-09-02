#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void writeTofile();
int createFile(const char fileName[]);
int openFile(const char fileName[]);
deleteFile(const char fileName[]) ;
void start();
void menu();

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

	start();

	system("pause");
	return 0;
}

void menu() {
	int choice = 0;
	// empty the filename array.
	memset(&fileName[0], 0, sizeof(fileName)); 

	scanf(" %i", &choice);
	if (!isdigit(choice)) {
		if (choice < 0 || choice > 3) {
			printf("Not a valid choice\n");
		} else {
			switch (choice)
			{
			case 1:
				//Create new file
				printf("Write the name of the file to create: \n");
				scanf(" %s", fileName);
				createFile(fileName);
				if (createFile(fileName) == 0) {
					printf("File could not be created\n");
				} else {
					printf("file has been succesful created\n");
				}
				break;
			case 2:
				//open file
				printf("Write the name on the file to open: \n");
				scanf(" %s", fileName);
				if (openFile(fileName) == 0) {
					printf("File could not be found\n");
				} else {
					//write to that file
					writeTofile();
				}
				break;
			case 3:
				//Delete file
				printf("Write the name of the file to delete\n");
				scanf(" %s", fileName);
				if (openFile(fileName) != 0) {
					//close file!
					fclose(cfPtr);
					if (deleteFile(fileName) == 0) {
						perror("Error file not deleted\n");
					} else {
						printf("File deleted\n\n");
					}
				} else {
					printf("File name does not exist\n");
				}
				break;
			case 0:
				//End program
				exit(0);
				break;
			}
		}
	} else {
		printf("input shall be an integer\n");
	}
	start();
}

void start() {
	printf("Welcome to the file handling c program\n");
	printf("---------------------------------------\n");
	printf("Choose one of the 4 choices:\n\n");
	printf("Press 1 to Create a new file\nPress 2 to make changes in a existing file\nPress 3 to delete file\nPress 0 to exit program\n");
	menu();
}

int createFile(const char fileName[]) {

	if ((cfPtr = fopen (fileName, "wb")) == NULL) {
		return 0;
	} else {
		//close file!
		fclose(cfPtr);
		return 1;
	}
}

int openFile(const char fileName[]) {

	if ((cfPtr = fopen(fileName, "rb+")) == NULL) {
		return 0;
	} else {
		return 1;
	}
}

void writeTofile() {

	Customer customer = {0, "", 0, 0};
	char choice;

	printf("Enter a tableIdNum between (1 and 10, 0 to end input):\n");
	scanf("%i", &customer.tableIdNum);

	while (customer.tableIdNum > 0 && customer.tableIdNum <= 10) {
		printf("Enter: age, name, id number\n");

		// Set values
		fscanf(stdin, "%i%s%i", &customer.age, customer.name, &customer.idNum);

		//seek position in file
		fseek( cfPtr, (customer.idNum - 1) *
			sizeof(Customer), SEEK_SET);

		//Write information in file
		fwrite(&customer, sizeof(Customer), 1, cfPtr);

		printf("Do you like to add (a) more input or close (c) the file? \n");
		scanf(" %c", &choice);
		if (isalpha(choice) && (choice == 'a' || 'c')) {
			do {
				switch (choice)
				{
				case 'a':
					//recursive call
					//enable user to write new input to file,
					writeTofile();
					break;
					//close file.
				case 'c':
					fclose(cfPtr);
					start();
					break;
				}
			} while(choice != 'c');
		} else {
			printf("input shall be 'a' or 'c'\n");
		}
	}
	fclose(cfPtr);
}

int deleteFile(const char fileName[]) {
	if (remove(fileName) != 0) {
		return 0;
	} else {
		return 1;
	}
}