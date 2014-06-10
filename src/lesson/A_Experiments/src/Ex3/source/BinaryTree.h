#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include "Entity.h"
#include <queue>
#include <stack>
using namespace std;


typedef struct _node {
	Entity data;
	struct _node *lchild, *rchild;
} Node;

typedef stack<Node*> Stack;

class BinaryTree {
public:
	BinaryTree();
	virtual ~BinaryTree();

	//Insert entity sorted by id
	void Insert(Entity e);

	//delete given entity on the tree
	void Delete(Entity e);

	//return the depth of the binary tree
	int Depth();

	//print the binary tree in PreOrder
	void PreOrder();

	//print the binary tree in InOrder
	void InOrder();

	//print the binary tree in PostOrder
	void PostOrder();

	//print the binary tree in LeveOrder
	void LeveOrder();

private:
	Node *root;

	//Insert entity sorted by id
	Node* Insert(Node *p,Entity e);

	//release the tree
	void Released(Node *p);

	Node* create(Entity e);

};

#endif /* BINARYTREE_H_ */
