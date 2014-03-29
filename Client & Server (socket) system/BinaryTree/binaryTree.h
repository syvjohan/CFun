#ifndef binaryTree.h
#define binaryTree.h

typedef int T;
//Store the keyValue, parent and contains the two child
struct Node
{
	T keyValue;
	Node *parent;
	Node *left;
	Node *right;
};
class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	void DestroyTree();
	void Insert(T key);
	Node *Search(T key);
	void DestroyNode(T key);
	void Traverse();
private: 
	void InnorderDestroyTree(Node *node);
	void InnerDestroyNode(T key); 
	void InnerInsert(T key, Node *node);
	Node *InnerSearch(T key, Node *node);
	void InorderTraversal(Node *node);

	Node *root;
};
#endif // !BINARYSEARCHTREE.H