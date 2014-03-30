#include "call.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
	node *root;
	node *tmp;
	//int i;

	root = NULL;

	//insert nodes
	insert(&root, 9);
	insert(&root, 4);
    insert(&root, 15);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 17);
    insert(&root, 2);

     //Printing nodes of tree
    printf("Pre Order Display\n");
    printPreorder(root);

    printf("In Order Display\n");
    printInorder(root);

    printf("Post Order Display\n");
    printPostorder(root);

    // Search node into tree 
    tmp = searchTree(&root, 4);
    if (tmp)
    {
        printf("Searched node=%d\n", tmp->data);
    }
    else
    {
        printf("Data Not found in tree.\n");
    }

    //Deleting all nodes of tree
    deleteTree(root);
    
	return 0;
}
