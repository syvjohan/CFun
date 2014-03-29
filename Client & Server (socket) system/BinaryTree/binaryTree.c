#include <stdio.h>
#include "binaryTreeHeader.h"

// Initialize root to nullptr for use in future functions.
BinaryTree::BinaryTree()
{
	root = nullptr;
}

// Destructor
BinaryTree::~BinaryTree()
{
	InnorderDestroyTree(root);
}

void BinaryTree::DestroyTree()
{
	InnorderDestroyTree(root);
	root = nullptr;
}

// Delete the nodes one by one. Start with the left node then right node. Then jump up one step.
// When it comes to the root it stops and continues at the right child of the root. Recursive function
void BinaryTree::InnorderDestroyTree(Node *node)
{
	if(node != nullptr)
	{
		InnorderDestroyTree(node->left);
		InnorderDestroyTree(node->right);
		delete node;
	}
}

void BinaryTree::DestroyNode(T key)
{
	InnerDestroyNode(key);
}

// Delete a node in the tree with an specified value.
void BinaryTree::InnerDestroyNode(T key)
{
	Node *node = Search(key); // create a new node and search the tree after the specified value.

	// Check to se if the node has a value.
	if(node != nullptr)
	{
		//if the searched node has two children and none of them is a nullptr.
		if(node->left && node->right)
		{
			// In-order succesor. The far left node in the right subtree.
			Node* successor = node->right;
			while(successor->left)
			{
				successor = successor->left;
			}

			successor->left = node->left;
			node->left->parent = successor;

			// Check to see if the succesor is the right node.
			if(node->right !=  successor)
			{
				successor->right = node->right;
				node->right->parent = successor;
				node->right->left = nullptr;
			}
			// Check to se if the node has a parent.
			if(node->parent)
			{
				// If the parents left child is a node, make it the right child.
				if(node->parent->left == node)
				{
					node->parent->left = successor;
				}
				else
				{
					node->parent->right = successor;
				}

				successor->parent = node->parent;
			}
			else
			{
				successor->parent = nullptr;
				root = successor;
			}
		}
		//If the node has one child (^ exclusive or)
		else if(!node->left  ^ !node->right)
		{
			// If left node !is a nullptr.
			if(node->left != nullptr)
			{
				node->left->parent = node->parent; // The left node switch parent
				// If the node has a parent
				if(node->parent)
				{
					// If the parent has a node to the left. Make that node to a left child of the parent.
					if(node->parent->left == node)
						node->parent->left = node->left;
					else
						// else the parent has a node to the right. Make that node to be  a left child of the parent.
						node->parent->right = node->left;
				}
				else
					// If it is a root set the node to be the left child.
				{
					root = node->left;
				}
			}
			// The left node was a nullptr.
			else
			{
				node->right->parent = node->parent; // The right node switch parent.
				// if the node has a parent
				if(node->parent)
				{
					// If the parent has a node to the right. Make that node to a right child of the parent.
					if(node->parent->right == node)
						node->parent->right = node->right;
					else
						// else the parent has a node to the left. Make that node to be  a right child of the parent.
						node->parent->left = node->right;
				}
				else
					// If it is a root set the node to be the right child.
				{
					root = node->right;
					root->parent = nullptr;
				}
			}
		}
		// The node has no children.
		else
		{
			if (node->parent)
			{
				if (node->parent->left == node)
				{
					node->parent->left = nullptr;
				} 
				else 
				{
					node->parent->right = nullptr;
				}
			} 
			else 
			{
				// the root is nullptr.
				root = nullptr;
			}
		}
	}
	// Delete the requested node.
	delete node;
}

// Insert a node in the tree. Recursive function
void BinaryTree::InnerInsert(T key, Node *node)
{
	// if the value is lower than the value in the node
	if(key < node->keyValue)
	{
		// if the left node is not nullptr. Insert the value to the left node.
		if(node->left != nullptr) 
		{
			InnerInsert(key, node->left); // Recursive function
		}
		else
		{
			node->left = new Node; // Allocate memory and create a new node at the left node.
			node->left->keyValue = key; // put the inserted value into the new node.
			node->left->left = nullptr; // sets the left child of the child to nullptr.
			node->left->right = nullptr; // sets the left child of the child to nullptr.
			node->left->parent = node; // sets  the left childs parent to be the node.
		}
	}
	// if the inserted node is equal or higher than the exixting nodes.
	else if(key >= node->keyValue)
	{
		if(node->right != nullptr)
		{
			InnerInsert(key, node->right); // Recursive function
		}
		else
		{
			node->right = new Node;
			node->right->keyValue = key;
			node->right->right = nullptr;
			node->right->left = nullptr;
			node->right->parent = node;
		}
	}
}

void BinaryTree::Insert(T key)
{
	if( root != nullptr)
	{
		InnerInsert(key, root);
	}
	else
	{
		root = new Node;
		root->keyValue = key;
		root->left = nullptr;
		root->right = nullptr;
		root->parent = nullptr;
	}
}

// Recursive function. Search the tree after a keyValue which are equal to the the value 
// the function is searching for or it reaches an uninitialized value.
Node *BinaryTree::InnerSearch(T key, Node *node) 
{
	if(node != nullptr)
	{
		// looking for the child node, if the inserted value is equal to the
		// existring value. Return the node back.
		if(key == node->keyValue)
		{
			printf("%sThe searched value(", key "%s )is in the tree");
			return node;
		}
		// if the inserted value is lower than the existing value
		// jump one step to left. The function is calling it´s self untill
		// the value in the node is larger than the value the program is trying to insert.
		if(key < node->keyValue)
		{ 
			puts("going left in the tree");
			return InnerSearch(key, node->left);
		}
		// if the inserted value is higher than the existing value
		// jump one step to right. The function is calling it´s self untill
		// the value in the node is lower than the value the program is trying to insert.
		else
		{
			puts("going right in the tree");
			return InnerSearch(key, node->right);
		}
	}
	// if the search function didn´t find what is looking for it return nullptr.
	else
	{
		printf("%sThe searched value (", key") %sis not in the tree");
		return nullptr;
	}
}

Node *BinaryTree::Search(T key)
{
	return InnerSearch(key, root);
}

void BinaryTree::Traverse()
{
	InorderTraversal(root);
}

// Traverse through the tree and print all the values in the tree.
void BinaryTree::InorderTraversal(Node *node)
{
	if(node == nullptr)
	{
		return;
	}
	InorderTraversal(node->left);
	puts(node->keyValue);
	InorderTraversal(node->right);
}


