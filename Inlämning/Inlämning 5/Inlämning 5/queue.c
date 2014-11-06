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
//
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
static int destroyNode(node *nodeRef);

count = 0;

//TODO kontrollera att noden har blivit Tillagd!!!
int enqueue(int value) {
	node *newNode;
	assert(newNode->data && "The inserted nodes value can't be NULL");
	newNode = createNode(&value);
	queueRef.last = newNode; //Add node at last place in the list.
	++count;

	//Check if there is only one element in the list.
	if (count == 1) {
		queueRef.first = newNode;
		queueRef.last = newNode;
	}

	return 1;
}

static node *createNode(int value) {
	node *newNode = malloc(sizeof(node));
	assert(newNode && "ERROR, unable to allocate requaried memory");

	newNode->data = value;
	newNode->next = NULL;

	return &newNode;
}

int dequeue(int *value) {	
	// queue is empty.
	if (queueRef.first) {
		node *tmp = queueRef.first;
		queueRef.first = tmp->next;
		*value = destroyNode(tmp);
		return 1;
	}

	return 0;
}

static int destroyNode(node *nodeRef) {
	int tmp = nodeRef->data;
	free(nodeRef);
	nodeRef = NULL;
	--count;

	return tmp;
}

void printQueue() {
	node *tmp = queueRef.first;
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

int deleteNode(int data) {
	// Edge-case 1: Kön är tom
	// Edge-case 2: Kön har 1 element.
	// { 1 }

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

////Delete a node somewhere in the queue.
//int deleteNode(int data) {
//	node *prevPtr = queueRef.first;
//	node *currPtr = prevPtr->next;
//	if (prevPtr) {
//		printf("\nQueue is empty!\n");
//	}
//	else {
//		if (count > 2) {
//			//First element.
//			if (prevPtr->data == data) {
//				currPtr = queueRef.first;
//				free(prevPtr);
//				--count;
//				return 1;
//			}
//			//Last element.
//			else if (currPtr->data == data && currPtr == queueRef.last) {
//				queueRef.last = prevPtr;
//				free(currPtr);
//				--count;
//				return 1;
//			}
//			//Element in the middle.
//			else {
//				while (currPtr->data != data || currPtr != queueRef.last) {
//					//take one step forward in the queue.
//					prevPtr = prevPtr->next;
//					currPtr = currPtr->next;
//
//					if (currPtr->data == data) {
//						currPtr->next = prevPtr;
//						free(currPtr);
//						--count;
//						return 1;
//					}
//					else {
//						//printf("\nThe value could not be found in the queue!\n");
//						return 0;
//					}
//				}
//			}
//		}
//		else {
//			if (count == 2) {
//				if (prevPtr->data == data) {
//					queueRef.first = queueRef.last;
//					free(prevPtr);
//					return 1;
//				}
//				else if (currPtr->data == data) {
//					queueRef.last = queueRef.first;
//					free(currPtr);
//					return 1;
//				}
//				else {
//					return 0;
//					//printf("\nThe value could not be found in the queue!\n");
//				}
//
//			} //count == 1;
//			else if (prevPtr->data == data && count == 1) {
//				free(prevPtr);
//				queueRef.first = NULL;
//				queueRef.last = NULL; //if somereason 2 pointers point to same object this prevent heap corruption.
//				printf("\nQueue is now empty!\n");
//				return 1;
//			}
//			else {
//				//printf("\nThe value could not be found in the queue!\n");
//				return 0;
//			}
//		}
//		
//	}
//
//	//printf("\nThe value could not be found in the queue!\n");
//	return 0;
//}



