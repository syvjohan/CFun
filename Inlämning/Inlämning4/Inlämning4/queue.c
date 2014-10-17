#include "queue.h"
#include "defs.h"
#include <string.h>

struct person {
	char firstName[50];
	char lastName[50];
	char personID[50];
};
 struct person static queue[QUEUE_MAX_SIZE];

tail = 0;
head = 0;
numbOfElements = 0;

void enqueue(struct person *p) {
	strcpy(&queue[tail].firstName, p->firstName);
	strcpy(&queue[tail].lastName, p->lastName);
	strcpy(&queue[tail].personID, p->personID);
	//Moves tail forward one step. Tail now points to the next free index in the queue.
	tail++;
	//increment the number of persons in the queue by 1.
	numbOfElements++;

}

void dequeue(struct person *p) {
	//Copy the information to *p.
	strcpy(p->firstName, &queue[head].firstName);
	strcpy(p->lastName, &queue[head].lastName);
	strcpy(p->personID, &queue[head].personID);

	//Erase information at the first(head) position in the queue.
	queue->firstName[head] = '\0';
	queue->lastName[head] = '\0';
	queue->personID[head] = '\0';
	//Moves head forward one step. Head now points to the first person in the list.
	head++;
	//Decrement the number of persons in the queue by -1.
	numbOfElements--;
}

void get_person(struct person *p, int pos) {
	//Copys information about an person at a specific position. 
	strcpy(p->firstName, &queue[pos].firstName);
	strcpy(p->lastName, &queue[pos].lastName);
	strcpy(p->personID, &queue[pos].personID);
}

int get_number_of_person() {
	return numbOfElements;
}

int empty() {
	if (numbOfElements == 0) {
		return 1;
	} 
	//The queue is NOT empty.
	return 0;
	
}

int full() {
	if (numbOfElements == QUEUE_MAX_SIZE) {
		return 1;
	}
	//The queue is NOT full.
	return 0;
}
