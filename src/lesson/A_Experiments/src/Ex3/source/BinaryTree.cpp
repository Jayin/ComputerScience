#include "BinaryTree.h"

BinaryTree::BinaryTree() {
	this->root = NULL;
}

BinaryTree::~BinaryTree() {
	Released(root);
}

Node* BinaryTree::create(Entity e) {
	Node *node = new Node();
	node->data = e;
	node->lchild = NULL;
	node->rchild = NULL;
	return node;
}

void BinaryTree::Insert(Entity e) {
	if(root ==NULL){
		root = create(e);
	}else{
		Insert(root, e);
	}
}

Node* BinaryTree::Insert(Node *p, Entity e) {
	if (p == NULL) {
		p = create(e);
	} else {
		if (e.getId() < p->data.getId()) {
			p->lchild = Insert(p->lchild, e);
		} else {
			p->rchild = Insert(p->rchild, e);
		}
	}
	return p;
}

void BinaryTree::Delete(Entity e) {

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

int BinaryTree::Depth() {
	Node *p = root;
	int depth = 0;
	if (p == NULL)
		return 0;
	queue<Node*> q;
	queue<Node*> tmp;
	q.push(p);
	makeEmpty(tmp);
	while (q.size() > 0) {

		Node* n = q.front();
		q.pop();
		if (n->lchild != NULL)
			tmp.push(n->lchild);
		if (n->rchild != NULL)
			tmp.push(n->rchild);
//		cout << n->data.getId() << " "; //visit
		if (q.size() == 0) {
//			cout << endl;
			depth++;
			copy(q, tmp);
			makeEmpty(tmp);
		}
	}
	return depth;
}

void BinaryTree::PreOrder() {
	Node *p = root;
	Stack s;
	while (p != NULL || !s.empty()) {
		while (p != NULL) {
			cout << p->data.getId() << " ";
//			p->data.print();
			s.push(p);
			p = p->lchild;
		}
		if (!s.empty()) {
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}
}

void BinaryTree::InOrder() {
	Node* p = root;
	Stack s;
	while (p != NULL || !s.empty()) {
		while (p != NULL) {
			s.push(p);
			p = p->lchild;
		}
		if (!s.empty()) {
			p = s.top();
			cout << p->data.getId() << " ";
			s.pop();
			p = p->rchild;
		}
	}
}

void BinaryTree::PostOrder() {
	Node* p = root;
	Stack visit, start;//typedef stack<Node*> Stack;
	if (p != NULL)
		start.push(p);
	while (!start.empty()) {
		if (!visit.empty() && start.top()->data.getId() == visit.top()->data.getId()) {
			cout << visit.top()->data.getId() << " ";//visit that point
			start.pop(),visit.pop();
		} else {
			Node* tmp = start.top();
			visit.push(tmp);
			if (tmp->rchild != NULL) {
				start.push(tmp->rchild);
			}
			if (tmp->lchild != NULL) {
				start.push(tmp->lchild);
			}
		}
	}
}

void BinaryTree::Released(Node* p) {
	if (p == NULL)
		return;
	Released(p->lchild);
	Released(p->rchild);
	delete p;
}
