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
	//return false if delete faild
	bool Delete(Entity e);

	//return the depth of the binary tree
	int Depth();

	//return the Node of entity on the tree
	//return NULL if not exist
	Node* Search(Entity e);

	//print the binary tree in PreOrder
	void PreOrder();

	//print the binary tree in InOrder
	void InOrder();

	//print the binary tree in PostOrder
	void PostOrder();

	//print the binary tree in LeveOrder
	void LeveOrder();

	//return all son nodes of under the node-p of the tree
	queue<Node*> GetNodes();

private:
	Node *root;

	//Insert entity sorted by id
	Node* Insert(Node *p, Entity e);

	//return the father Node of entity on the tree
	//return NULL if not exist
	Node* Search(Node *p, Entity e);

	Node* SearchFather(Entity e);

	Node* SearchFather(Node *p, Entity e);

	//release the tree
	void Released(Node *p);

	//create one Node
	Node* create(Entity e);

	//return all nodes of under the node-p of the tree
	queue<Node*> GetNodes(Node *p);

};

#endif /* BINARYTREE_H_ */
