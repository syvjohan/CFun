#include "defs.h"
#include "queue.h"
#include <assert.h>

//#define DEFINE_QUEUE(TYPE) \
//	typedef struct TYPE##_node_s{ \
//		struct TYPE##_node_s *first; \
//		struct TYPE##_node_s *last; \
//	}TYPE##_node_t;
//
//DEFINE_QUEUE(int)
//DEFINE_QUEUE(double)

//int_node_t node44;
//double_node_t nodedouble;
//
//void b() {
//		
//}

typedef struct {
	int data;
	struct node *next;
}node;

typedef struct {
	node *first;
	node *last;
}queueC;

static queueC queueRef;

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
	if (queueRef.first == NULL) {
		queueRef.first = newNode;
		queueRef.last = newNode;
		return 1;
	}
	else {
		queueRef.last->next = newNode;
		queueRef.last = newNode;
		return 1;
	}
}

static node *createNode(int value) {
	node *newNode = MALLOC(sizeof(node));
	assert(newNode && "ERROR, unable to allocate requaried memory");

	newNode->data = value;
	newNode->next = NULL;

	return newNode;
}

int dequeue(int *value) {	
	// queue contains node(s).
	if (queueRef.first) {

		node *tmp = queueRef.first;

		//Over 2 nodes in the queue.
		if (tmp->next != NULL) { 
			//BEWARE! can be wrong if there is only 2 nodes in the list!
			queueRef.first = tmp->next;
			*value = destroyNode(tmp);
			return 1; 
		}
		else {
			//One node in the queue
			*value = destroyNode(tmp);
			tmp = NULL;
			queueRef.first = NULL;
			queueRef.last = NULL;
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
	doesn't point to anything set the pointer to NULL after freeing it.*/
}

void printQueue() {
	node *tmp = queueRef.first;
	if (tmp == NULL) {
		printf("\nQueue is empty!\n");
	}
	else {
		printf("\nThe element(s) in the list are: \n");
		while (tmp != NULL) {
			printf("%i", tmp->data, "\n");
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

	node *it = queueRef.first;
	node *prev = NULL;

	// Loop from previous to deal with edge case of deleting the only element.
	while (prev != queueRef.last) {

		// We've found the node.
		if (it && it->data == data) {

			// Deals with edge cases for 1 element, or deleting first or last element.
			queueRef.first = (it == queueRef.first) ? it->next : queueRef.first;
			queueRef.last = (it == queueRef.last) ? prev : queueRef.last;
			
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
		queueRef.first = queueRef.last = NULL;
		--count;
		return 1;
	}

	return 0;
}



