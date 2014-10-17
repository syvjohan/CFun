#include "queue.h"
#include "defs.h"
#include "InputValidation.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct personInfo {
	char firstname[50];
	char lastname[50];
	char personID[50];
};

void draw_menu();
void main_menu();
void add_to_queue();
void remove_from_queue();
void print_queue();

int main(void) {
	draw_menu();
}

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
			default:
				break;
			}
		} else {
			printf("\nInput value shall be a number!\n\n");
			draw_menu();
		}
	} while (choice != 4);

}

void add_to_queue() {
	//If the queue is NOT full add person.
	if (full() == 0) {
		struct personInfo per;
		printf("****Add persson*****\n");

		printf("\nPrint the first name: ");
		scanf(" %s", &per.firstname);

		printf("\nPrint the last name: ");
		scanf(" %s", &per.lastname);

		printf("\nPrint the Personal ID number: ");
		scanf(" %s", &per.personID);

		enqueue(&per);

	} else {
		printf("\nQueue is full! Max number of elements is %i", QUEUE_MAX_SIZE);
	}

	draw_menu();
}

void remove_from_queue() {
	if (empty() == 0) {
		struct personInfo per;
		printf("****Remove person****\n");

		dequeue(&per);
		printf("\nFirstname is %s", &per.firstname);
		printf("\nLastname is %s", &per.lastname);
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
		int number = get_number_of_person();

		int i;
		for (i = 0; i != number; i++) {
			get_person(&per, i);

			printf("\nQueue number is: %i", i);
			printf("\nFirstname is: %s", per.firstname);
			printf("\nLastname is: %s", per.lastname);
			printf("\nPersonal ID is: %s", per.personID);
			printf("\n");
		}
	} else {
		printf("\nThere is no persons in the list to print!\n");
	}

	printf("\n");
	draw_menu();
}