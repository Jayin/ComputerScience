/*
 * TraversalBinaryTree.h
 *
 *  Created on: 2014年5月20日
 *      Author: Jayin Ton
 */

#ifndef TRAVERSALBINARYTREE_H_
#define TRAVERSALBINARYTREE_H_
#include <iostream>
#include <queue>
#include <stack>
using namespace std;


#ifndef struct_node
#define struct_node
typedef struct _Node {
	int data;
	_Node *lchild, *rchild;
} Node;
#endif

typedef stack<Node*> Stack;

class TraversalBinaryTree {
public:
	TraversalBinaryTree(Node *treeRoot);
	virtual ~TraversalBinaryTree();
	void PreOrder();
	void PreOrder2();
	void InOrder();
	void PostOrder();
	void LeveOrder();
private:
	Node *root;
	void PreOrder(Node* p);
	void PreOrder2(Node* p);
	void InOrder(Node* p);
	void PostOrder(Node* p);
	void LeveOrder(Node* p);
	void Released(Node* p);
};

#endif /* TRAVERSALBINARYTREE_H_ */
