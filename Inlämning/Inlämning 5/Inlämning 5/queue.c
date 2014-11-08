//Johan Fredriksson AB5785.
#include "defs.h"
#include "queue.h"
#include <assert.h>

typedef struct {
	int data;
	struct node *next;
}node;

typedef struct {
	node *first;
	node *last;
}queueC;

static queueC queuePtr;

//Forward declaration of functions.
static node *createNode(int value);
static int destroyNode(node *nodePtr);

count = 0;

int enqueue(int value) {
	node *newNode;
	newNode = createNode(value);
	if (newNode == NULL) {
		return 0;
	}

	++count;
	//Check if there is only one element in the list.
	if (queuePtr.first == NULL) {
		queuePtr.first = newNode;
		queuePtr.last = newNode;
		return 1;
	}
	else {
		queuePtr.last->next = newNode;
		queuePtr.last = newNode;
		queuePtr.last->next = NULL;
		return 1;
	}
}

static node *createNode(int value) {
	//Allocating memory for the new node.
	node *newNode = MALLOC(sizeof(node));
	assert(newNode && "ERROR, unable to allocate requaried memory");

	newNode->data = value;
	newNode->next = NULL;

	return newNode;
}

int dequeue(int *value) {	
	// check if queue contains node(s).
	if (queuePtr.first) {

		node *tmp = queuePtr.first;

		//Over 2 nodes in the queue.
		if (tmp->next != NULL) { 
			//BEWARE! can be wrong if there is only 2 nodes in the list!
			queuePtr.first = tmp->next;
			*value = destroyNode(tmp);
			return 1; 
		}
		else {
			//One node in the queue
			*value = destroyNode(tmp);
			tmp = NULL;
			queuePtr.first = NULL;
			queuePtr.last = NULL;
			return 1;
		}
	}
	
	return 0;
}

static int destroyNode(node *nodePtr) {
	int value = nodePtr->data;
	free(nodePtr);
	return value;

	/*Calling free() on a pointer doesn't change it, only marks memory as free. 
	The pointer will still point to the same location which will contain the 
	same value, but that value can now get overwritten at any time. To ensure that it
	doesn't point to anything set the pointer to NULL after freeing it (see dequeu for setting it to NULL).*/
}

void printQueue() {
	node *tmp = queuePtr.first;
	if (tmp == NULL) {
		printf("\nQueue is empty!\n");
	}
	else {
		printf("\nThe element(s) in the list are: \n");
		while (tmp != NULL) {
			printf("%i", tmp->data, "\n");
			//Move one step forward in the queue.
			tmp = tmp->next;
			printf(" -> ");
		}
		printf("NULL");
	}
}

int deleteNode(int data) {
	// Edge-case 1: Kön är tom
	// Edge-case 2: Kön har 1 element.
	// { 1, 9 }

	node *it = queuePtr.first;
	node *prev = NULL;

	// Loop from previous to deal with edge case of deleting the only element.
	while (prev != queuePtr.last) {

		// We've found the node.
		if (it && it->data == data) {

			// Deals with edge cases for 1 element, or deleting first or last element.
			queuePtr.first = (it == queuePtr.first) ? it->next : queuePtr.first;
			queuePtr.last = (it == queuePtr.last) ? prev : queuePtr.last;
			
			if (prev) {
				prev->next = it->next;
			}

			destroyNode(it);
			--count;
			return 1;
		}

		prev = it;
		it = it->next;
	}

	// Deleting the single element in the list.
	if (it && it->data == data) {
		destroyNode(it);
		queuePtr.first = queuePtr.last = NULL;
		--count;
		return 1;
	}

	return 0;
}

//Cleaning up the memory before exit the program...
void cleanUpMemory() {
	//ensures program dont crash if 0 nodes has been inserted.
	if (queuePtr.first == NULL) {
		return;
	}

	node *currPtr = queuePtr.first;
	node *nextPtr = queuePtr.first->next;

	while (currPtr != NULL) {
		//Move one step forward in the queue.
		free(currPtr);
		--count;
		if (nextPtr == NULL) {
			return;
		}
		else {
			currPtr = nextPtr;
			nextPtr = nextPtr->next;
		}
	}
}


