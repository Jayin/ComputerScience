/*
 * SortTree.cpp
 *
 *  Created on: 2014年5月19日
 *      Author: Jayin Ton
 */

#include "SortTree.h"

SortTree::SortTree() {
	root = NULL;
}

SortTree::~SortTree() {
	if (root != NULL){
		released(root);
		cout<<"release finish"<<endl;
	}

}

void SortTree::released(Node* p) {
	if(p == NULL)
		return;
	released(p->lchild);
	released(p->rchild);
	cout<<"release ->"<<p->data<<endl;
	delete p;
}

void SortTree::add(int data) {
	if (root == NULL) {
		root = create(data);
	} else {
		add(this->root, data);
	}

}

Node* SortTree::add(Node* p, int data) {
	if (p == NULL) {
		p = create(data);
	} else {
		if (data < p->data) {
			p->lchild = add(p->lchild, data);
		} else {
			p->rchild = add(p->rchild, data);
		}
	}
	return p;
}

Node* SortTree::create(int data) {
	Node *node = new Node;
	node->data = data;
	node->lchild = NULL;
	node->rchild = NULL;
	cout << "create ->" << node->data << endl;
	return node;
}

void SortTree::inOrder() {
	SortTree::inOrder(root);
}

void SortTree::inOrder(Node* p) {
	if (p == NULL) {
		return;
	} else {
		inOrder(p->lchild);
		cout << p->data << " ";
		inOrder(p->rchild);
	}
}

