#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "defs.h"
#include "queue.h"

//Forward declaration.
void pushBack();
void mainMenu();
void popFront();
void eraseNode();
void print();

void drawMenu() {
	printf("****Queue menu****\n");
	printf("1. Add node to queue\n"
		"2. Erase last node from queue\n"
		"3. Erase specific node\n"
		"4. Print queue\n"
		"5. Exit\n"
		"**********************\n\n");
	printf("Choose one of the above alternatives: ");
	mainMenu();
}

void pushBack() {
	printf("Print the value you want to insert: ");

	int input;
	scanf("%d", &input);

	(isdigit(input) == 1) ? printf("invalid input!\n") : ((enqueue(input) == 1) ? printf("Inserted value succesful!\n") : printf("insert value failed!\n"));

	printf("\n");
	drawMenu();
}

void mainMenu() {
	int chooice;
	scanf("%d", &chooice);
	do {
		switch(chooice) {
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
		}
	} while (chooice != 5);
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
	scanf("%d", &input);

	(isdigit(input) == 1) ? printf("Invalid input\n") : (deleteNode(input) == 1) ? printf("Value has been succesful removed\n") : printf("Failed to erase value, value could't be found!\n");
	
	printf("\n");
	drawMenu();
}

void print() {
	printQueue();
	printf("\n");
	drawMenu();
}
