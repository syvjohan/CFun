#include <stdio.h>
#include <stdlib.h>

struct binTree {
	int data;
	struct binTree *right, *left;
};

typedef struct binTree node;

//insert value in the tree
void insert(node **tree, int value) {
	node *temp = NULL;
	if (!(*tree)) {
		// Allocate memory.
		temp = (*node)malloc(sizeof(node));
		temp->left = temp->right = NULL;
		temp->data = value;
		*tree = temp;
		return;
	}

	// if the inserted value is lower put it to the left
	if (value < (*tree)->data) {
		insert(&(*tree)->left, value);
	}
	// if the inserted value is higher put it to the rigth
	else if (value > (*tree)->data) {
		insert(&(*tree)->right, value)
	}
}

// Delete all nodes in the tree.
void deleteTree(node *tree) {
	if (tree) {
		deleteTree(tree->left);
		deleteTree(tree->rigth);
		// Free memory
		free(tree);
	}
}

//Search the tree for a specific  value.
node* search(node **tree, int value) {
	//If there is no tree
	if (!(*tree)) {
		return NULL;
	}

	//If the searched value is lower then the node value.
	if (value < (*tree)->data) {
		search(&((*tree)->left), value);
	}
	//If the searched value is higher then the node value.
	else if (value > (*tree)->data) {
		search(&((*tree)->right), value);
	}
	//If the searched value is equal to the root.
	else if (value == (*tree)->data) {
		return *tree;
	}
}

//Pre-order priority left where it's possible
void printPreorder(node *tree) {
	if (tree) {
		printf("%d\n", tree->data);
		print_preorder(tree->left);
		print_preorder(tree->right);
	}
}

//Post-order left child -> right child -> parent.
void printPostorder(node *tree) {
	if (tree) {
		printPostorder(tree->left);
		printPostorder(tree->right);
		printf("%d\n", tree->data);
	}
}

//In-order left child -> parent -> right child.
void printInorder(node *tree) {
	if (tree) {
		printInorder(tree->left);
		printf("%d\n", tree->data);
		printInorder(tree->right);
	}
}


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

     /* Printing nodes of tree */
    printf("Pre Order Display\n");
    print_preorder(root);

    printf("In Order Display\n");
    print_inorder(root);

    printf("Post Order Display\n");
    print_postorder(root);

    /* Search node into tree */
    tmp = search(&root, 4);
    if (tmp)
    {
        printf("Searched node=%d\n", tmp->data);
    }
    else
    {
        printf("Data Not found in tree.\n");
    }

    /* Deleting all nodes of tree */
    deltree(root);

	return 0;
}