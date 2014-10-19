//Johan Fredriksson AB5785.
#include "queue.h"
#include "defs.h"
#include <string.h>

//Can't forward declare functions in this file because menu.c need access to them!

struct person 
{
	char firstname[STRINGSIZE];
	char lastname[STRINGSIZE];
	char personID[STRINGSIZE];
};
 struct person static queue[QUEUE_MAX_SIZE];

tail = 0;
head = 0;
numbOfElements = 0;

//Using modulus to make the queue circular, eg:
// arr[10].
// 0 % 10 = 0,
// 1 % 10 = 1,...,
// 10 % 10 = 0,
// 11 % 10 = 1,.....
void enqueue(struct person *p) 
{
	int newTail = tail % QUEUE_MAX_SIZE;
	//Copying the values from input parameter into queue.
	strcpy(queue[newTail].firstname, p->firstname);
	strcpy(queue[newTail].lastname, p->lastname);
	strcpy(queue[newTail].personID, p->personID);
	//Moves tail forward one step. Tail now points to the next free index in the queue.
	tail++;
	//increment the number of persons in the queue by 1.
	numbOfElements++;
}

void dequeue(struct person *p) 
{
	int newHead = head % QUEUE_MAX_SIZE;
	//Copy the information to *p.
	strcpy(p->firstname, queue[newHead].firstname);
	strcpy(p->lastname, queue[newHead].lastname);
	strcpy(p->personID, queue[newHead].personID);

	//Erase information at the first(head) position in the queue.
	*queue[newHead].firstname = '\0';
	*queue[newHead].lastname = '\0';
	*queue[newHead].personID = '\0';
	//Moves head forward one step. Head now points to the first person in the list.
	head++;
	//Decrement the number of persons in the queue by -1.
	numbOfElements--;
}

void get_person(struct person *p, int *pos) 
{
	int newPos = ((head + *pos) % QUEUE_MAX_SIZE);

	//Copys information about an person at a specific position. 
	strcpy(p->firstname, queue[newPos].firstname);
	strcpy(p->lastname, queue[newPos].lastname);
	strcpy(p->personID, queue[newPos].personID);
	*pos = newPos;
}

// Get the total number of persons in the queue
int get_number_of_person() 
{
	return numbOfElements;
}

int empty() 
{
	if (numbOfElements == 0) {
		return 1;
	} 
	//The queue is NOT empty.
	return 0;
}

int full() 
{
	if (numbOfElements == QUEUE_MAX_SIZE) {
		return 1;
	}
	//The queue is NOT full.
	return 0;
}
