/*
 * TraversalBinaryTree.cpp
 *
 *  Created on: 2014年5月20日
 *      Author: Jayin Ton
 */

#include "TraversalBinaryTree.h"

TraversalBinaryTree::TraversalBinaryTree(Node *treeRoot) {
	root = treeRoot;
}

TraversalBinaryTree::~TraversalBinaryTree() {
	Released(root);
}

void TraversalBinaryTree::Released(Node* p) {
	if (p == NULL)
		return;
	Released(p->lchild);
	Released(p->rchild);
	delete p;
}

void TraversalBinaryTree::PreOrder() {
	PreOrder(root);
}

void TraversalBinaryTree::PreOrder2() {
	PreOrder2(root);
}

void TraversalBinaryTree::PreOrder(Node* p) {
	if (p == NULL)
		return;
	cout << p->data << " ";
	PreOrder(p->lchild);
	PreOrder(p->rchild);
}

void TraversalBinaryTree::PreOrder2(Node* p) {
	Stack s;
	while(p != NULL || !s.empty()){
		while(p != NULL){
			cout<<p->data<<" ";
			s.push(p);
			p = p->lchild;
		}
		if(!s.empty()){
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}
}
void TraversalBinaryTree::InOrder() {
	InOrder(root);
}

void TraversalBinaryTree::InOrder(Node* p) {
	if (p == NULL)
		return;
	InOrder(p->lchild);
	cout << p->data << " ";
	InOrder(p->rchild);
}

void TraversalBinaryTree::PostOrder() {
	PostOrder(root);
}

void TraversalBinaryTree::PostOrder(Node* p) {
	if (p == NULL)
		return;
	PostOrder(p->lchild);
	PostOrder(p->rchild);
	cout << p->data << " ";
}

void makeEmpty(queue<Node*> &q) {
	while (q.size()) {
		q.pop();
	}
}

void copy(queue<Node*> &target, queue<Node*> src) {
	while (src.size()) {
		target.push(src.front());
		src.pop();
	}
}

void TraversalBinaryTree::LeveOrder() {
	LeveOrder(root);
}

void TraversalBinaryTree::LeveOrder(Node* p) {
	if (p == NULL)
		return;
	queue<Node*> q;
	queue<Node*> tmp;
	q.push(p);

	while (q.size() > 0) {
		makeEmpty(tmp);
		Node* n = q.front();
		q.pop();
		if (n->lchild != NULL)
			tmp.push(n->lchild);
		if (n->rchild != NULL)
			tmp.push(n->rchild);
		cout << n->data << " "; //visit
		if (q.size() == 0) {
			cout << endl;
			copy(q, tmp);
		}
	}
}

