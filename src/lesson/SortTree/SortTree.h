/*
 * SortTree.h
 *	二叉排序树
 *  Created on: 2014年5月19日
 *      Author: Jayin Ton
 */

#ifndef SORTTREE_H_
#define SORTTREE_H_

#include <iostream>
using namespace std;

#ifndef struct_node
#define struct_node
typedef struct _Node {
	int data;
	_Node *lchild, *rchild;
} Node;
#endif

class SortTree {
public:
	SortTree();
	virtual ~SortTree();
	void add(int data);
	void inOrder();
	Node* getTree();
private:
	Node* root;
	void inOrder(Node*);
	Node* add(Node* p,int data);
	Node* create(int data);
	void released(Node* p);
};

#endif /* SORTTREE_H_ */
