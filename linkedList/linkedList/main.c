#include <stdio.h>
#include <stdlib.h>


typedef struct listNode {
	char data;
	struct listNode *nextPtr;
}ListNode;

typedef ListNode *ListNodePtr;

void insert( ListNodePtr *sPtr, char value);
char erase(ListNodePtr *sPtr, char value);
int isEmpty(ListNodePtr *sPtr);
void printList(ListNodePtr currentPtr);
void instructions(void);

int main(void) {
	ListNodePtr startPtr = NULL;
	int choice;
	char item;

	instructions();
	printf("\n");
	scanf("%d", &choice);

	while (choice != 3) {

		switch (choice)
		{
		case 1:
			printf( "Enter a character: " );
			scanf("\n%c", &item);
			insert(&startPtr, item);
			printList(startPtr);
			printf("\n\n");
			instructions();
			break;
		case 2:
			if (!isEmpty(startPtr)) {
				printf("enter an character to delete: ");
				scanf("\n%c", &item);
				//if character is found delete it
				if (erase( &startPtr, item)) {
					printf("%c deleted item", item);
					printList(startPtr);
				} else {
					printf("%c not found", item);
				}
			} else {
				printf("list is empy");
			}
			printf("\n\n");
			instructions();
		break;
		default:
			printf("invalid choice\n");
			instructions();
			break;
		}
		scanf("%d", &choice);
	}

	printf("end");

	system("pause");
	return 0;
}

void insert( ListNodePtr *sPtr, char value) {
	ListNodePtr newPtr;
	ListNodePtr previousePtr;
	ListNodePtr currentPtr;

	newPtr = malloc(sizeof(ListNode)); //create the new node.

	if (newPtr != NULL) {//check if space is available
		newPtr->data = value; //place input value in node.
		newPtr->nextPtr = NULL; // the new node does not link to another node.

		previousePtr = NULL;
		currentPtr = *sPtr;

		while (currentPtr != NULL && value > currentPtr->data) {
			previousePtr = currentPtr; //walk to...
			currentPtr = currentPtr->nextPtr; // this node!
		}

		//insert node at beginning of list
		if (previousePtr == NULL) {
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		} else {//insert new node between previousPtr and currentPtr 
			previousePtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	} else {
		printf("%c no memory available, not inserted", value);
	}

}

char erase(ListNodePtr *sPtr, char value) {
	ListNodePtr previousePtr;
	ListNodePtr currentPtr;
	ListNodePtr tempPtr;

	//delete first node.
	if ( value == ( *sPtr )->data) {
		tempPtr = *sPtr; //hold node for erasing.
		*sPtr = (*sPtr )->nextPtr;
		free(tempPtr);
		return value;
	} else {
		previousePtr = *sPtr;
		currentPtr = (*sPtr)->nextPtr;

		//looping to find the correct location in the list!
		while(currentPtr != NULL && currentPtr->data != value) {
			previousePtr = currentPtr; // walk to....
			currentPtr = currentPtr->nextPtr; //this node..
		}

		if (currentPtr != NULL) {
			tempPtr = currentPtr;
			previousePtr->nextPtr = currentPtr->nextPtr;
			free(tempPtr);
			return value;
		}
	}
	return '\0';
}

//Return 1 if the list is empty, 0 otherwise.
int isEmpty(ListNodePtr *sPtr) {
	return sPtr == NULL;
}

void printList(ListNodePtr currentPtr) {
	if (currentPtr == NULL) {
		printf("list is empty");
	} else {
		printf("The list is: \n");

		while (currentPtr != NULL) {
			printf("%c-->", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		printf("NULL\n\n");
	}
}

void instructions(void) {
	printf("Enter your choice: \n"
		"Press 1 to insert an element into the list. \n"
		"Press 2 to delete an element from the list. \n"
		"Press 3 to end. \n");
}