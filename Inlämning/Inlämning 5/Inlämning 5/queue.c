#include "defs.h"
#include "queue.h"
#include <assert.h>

static node *createNode(T value);
static T destroyNode(node *node_ref);

count = 0;

//TODO kontrollera att noden har blivit Tillagd!!!
int enqueue(T value) {
	node *newNode;
	assert(newNode->data, "The inserted nodes value can't be NULL");
	newNode = createNode(&value);
	++count;

	//Check if there is only one element in the list.
	if (count == 1) {
		queueref.first = newNode;
		queueref.last = newNode;
	}

	return 1;
}

static node *createNode(T value) {
	node *newNode = malloc(sizeof(node));

	newNode->data = value;
	newNode->next = NULL;
	assert(newNode, "ERROR, unable to allocate requaried memory");
	return &newNode;
}

int dequeu(int *value) {	
	if (count == 1) {
		destroyNode(&queueref.first);
		queueref.first = NULL;
		queueref.last = NULL;
		return 1;
	}
	else  if (count == 2) {
		node *tmp = queueref.first;
		value = tmp->data;
		queueref.first = tmp->next;
		queueref.first = tmp->data;
		destroyNode(&tmp);
		value =  queueref.last = queueref.first;
		return 1;
	}
	else if (count > 2) {
		node *tmp = queueref.first;
		queueref.first = tmp->next;
		queueref.first = tmp->data;
		value = destroyNode(&tmp);
		return 1;
	}
	else {
		return 0;
	}
}

static T destroyNode(node *node_ref) {
	T *tmp = node_ref->data;
	free(node_ref);
	node_ref = NULL;
	--count;

	return tmp;
}

void printQueue() {
	node *tmp = queueref.first;
	if (tmp) {
		printf("\nQueue is empty!\n");
	}
	else {
		printf("\nThe element(s) in the list are: \n");
		while (tmp != NULL) {
			printf("%i", tmp->data, "\n");
			tmp = tmp->next;
		}
	}
}

//TODO! Avlägsna en nod mitt i kön
int deleteNode(T data) {
	node *prevPtr = queueref.first;
	node *currPtr = prevPtr->next;
	if (prevPtr) {
		printf("\nQueue is empty!\n");
	}
	else {
		//First element.
		if (prevPtr->data == data) {
			currPtr = queueref.first;
			free(prevPtr);
			--count;
			return 1;
		}
		//Last element.
		else if (currPtr->data == data && currPtr->data == queueref.last) {
			queueref.last = prevPtr;
			free(currPtr);
			--count;
			return 1;
		}
		//Element in the middle.
		else {
			while (currPtr->data != data || currPtr->data != queueref.last) {
				//take one step forward in the queue.
				prevPtr = prevPtr->next;
				currPtr = currPtr->next;

				if (currPtr->data == data) {
					currPtr->next = prevPtr;
					free(currPtr);
					--count;
					return 1;
				}
				else {
					//printf("\nThe value could not be found in the queue!\n");
					return 0;
				}
			}
		}
	}

	//printf("\nThe value could not be found in the queue!\n");
	return 0;
}



