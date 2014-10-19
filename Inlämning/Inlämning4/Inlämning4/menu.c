//Johan Fredriksson AB5785.#include "queue.h"
#include "defs.h"
#include "InputValidation.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct personInfo {
	char firstname[STRINGSIZE];
	char lastname[STRINGSIZE];
	char personID[STRINGSIZE];
};

//Forward declaration, increases functions isolation!
void main_menu();
void add_to_queue();
void remove_from_queue();
void print_queue();

void draw_menu() {
	printf("****Queue menu****\n");
	printf("1. Add person to queue\n"
		   "2. Erase person from queue\n"
		   "3. Print queue\n"
		   "4. Exit\n"
		   "**********************\n\n");
	printf("Choose one of the above alternatives: ");
	main_menu();
}

void add_to_queue() {
	//If the queue is NOT full add person.
	if (full() == 0) {
		struct personInfo per;
		printf("\n****Add persson*****\n");

		printf("\nWrite the first name: ");
		scanf(" %s", &per.firstname);

		printf("\nWrite the last name: ");
		scanf(" %s", &per.lastname);

		printf("\nWrite the Personal ID number: ");
		scanf(" %s", &per.personID);

		enqueue(&per); //Uses referece highly more efficient.

	} else {
		printf("\nQueue is full! Max number of elements is %i", QUEUE_MAX_SIZE);
	}

	draw_menu();
}

void remove_from_queue() {
	if (empty() == 0) {
		struct personInfo per;
		printf("\n****Remove person****\n");

		dequeue(&per);
		printf("\nfirstname is %s", &per.firstname);
		printf("\nlastname is %s", &per.lastname);
		printf("\nPersonal ID is %s", &per.personID);
		printf("\n");
	} else {
		printf("\nThere is no person in the list to erase!\n");
	}

	printf("\n");
	draw_menu();
}

void print_queue() {
	if (empty() == 0) {
		struct personInfo per;
		int number = get_number_of_person(); //gets the number of persons.

		printf("\n****Print queue****\n");
		int i, temp;
		for (i = 0; i != number; i++) {
			temp = i; //Using temp variable to make sure right index is writen out. Temp get incremented by head.
			get_person(&per, &temp);
			
			printf("\nQueue number is: %i", temp);
			printf("\nfirstname is: %s", &per.firstname);
			printf("\nlastname is: %s", &per.lastname);
			printf("\nPersonal ID is: %s", &per.personID);
			printf("\n");
		}
	} else {
		printf("\nThere is no persons in the list to print!\n");
	}

	printf("\n");
	draw_menu();
}

void main_menu() {
	int choice = -1;
	do {
		scanf(" %d", &choice);
		if (validateNumber(&choice) == 0) {
			switch (choice) {
			case 1:
				add_to_queue();
				break;
			case 2:
				remove_from_queue();
				break;
			case 3:
				print_queue();
				break;
			}
		} else {
			printf("\nInput value shall be a number!\n\n");
			draw_menu();
		}
	} while (choice != 4);
}


