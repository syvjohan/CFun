//Johan Fredriksson AB5785.
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "defs.h"
#include "queue.h"
#include "inputValidation.h"

//Forward declaration.
void pushBack();
void mainMenu();
void popFront();
void eraseNode();
void print();

void drawMenu() {
	printf("****Queue menu****\n");
	printf("1. Add node to queue\n"
		"2. Erase first node from queue\n"
		"3. Erase specific node\n"
		"4. Print queue\n"
		"5. Exit\n"
		"**********************\n\n");
	printf("Choose one of the above alternatives: ");
	mainMenu();
}

void pushBack() {
	printf("Print the value you want to insert: ");

	int *input = 0;
	scanf(" %i", &input);

	(validateIntInput(input) == 1) ? printf("invalid input!\n") : ((enqueue(input) == 1) ? printf("Inserted value succesful!\n") : printf("insert value failed!\n"));

	printf("\n");
	drawMenu();
}

void mainMenu() {
	int choice = -1;
	scanf(" %i", &choice);
	if (validateIntInput(choice) == 0) {
		do {
			switch (choice) {
			case 1:
				pushBack();
				break;
			case 2:
				popFront();
				break;
			case 3:
				eraseNode();
				break;
			case 4:
				print();
				break;
			case 5:
				cleanUpMemory();
				exit(EXIT_SUCCESS);
			default:
				break;
			}
		} while (choice != 5);
	}
	else {
		printf("\nInvalid input!\n\n");
		drawMenu();
	}
}

void popFront() {
	int value = 0;
 	(dequeue(&value) == 0) ? printf("No nodes in the list\n") : printf("\nFirst node has been succesful removed, returned value is: %i", value);

	printf("\n");
	drawMenu();
}

void eraseNode() {
	printf("Print the value you want to erase: ");

	int input;
	scanf(" %i", &input);

	(validateIntInput(input) == 1) ? printf("Invalid input\n") : (deleteNode(input) == 1) ? printf("Value has been succesful removed\n") : printf("Failed to erase value, value could't be found!\n");
	
	printf("\n");
	drawMenu();
}

void print() {
	printQueue();
	printf("\n");
	drawMenu();
}
