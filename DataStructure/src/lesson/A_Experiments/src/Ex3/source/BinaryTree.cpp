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
	if (root == NULL) {
		root = create(e);
	} else {
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

Node* BinaryTree::Search(Entity e) {
	return Search(root, e);
}

Node* BinaryTree::Search(Node *p, Entity e) {
	Node* father = SearchFather(p, e);
	if (father == NULL)
		return NULL;
	else {
		if (father->lchild != NULL && father->lchild->data.getId() == e.getId())
			return father->lchild;
		return father->rchild;
	}
}

Node* BinaryTree::SearchFather(Entity e) {
	return SearchFather(root, e);
}

Node* BinaryTree::SearchFather(Node *p, Entity e) {
	if (p == NULL) {
		return NULL;
	}
	if ((p->lchild != NULL && p->lchild->data.getId() == e.getId())
			|| (p->rchild != NULL && p->rchild->data.getId() == e.getId())) {
		return p;
	}
	if (e.getId() < p->data.getId()) {
		return this->SearchFather(p->lchild, e);
	} else {
		return this->SearchFather(p->rchild, e);
	}
	return NULL;
}

bool BinaryTree::Delete(Entity e) {
	Node *father = SearchFather(e);
	if (father == NULL)
		return false;
	Node *target = Search(father, e);
	if (target->lchild != NULL || target->rchild != NULL) {
		if (target->lchild != NULL && target->rchild != NULL) {
			//two child trees & rebuild right tree
			queue<Node*> q = GetNodes(target->rchild);
			if (target == father->lchild) {
				father->lchild = target->lchild;
			} else {
				father->rchild = target->lchild;
			}
			while (q.size() > 0) {
				Insert(q.front()->data);
				q.pop();
			}
		} else if (target->lchild != NULL) {
			//left tree
			if (target == father->lchild) {
				father->lchild = target->lchild;
			} else {
				father->rchild = target->lchild;
			}
		} else {
			//right tree
			if (target == father->lchild) {
				father->lchild = target->rchild;
			} else {
				father->rchild = target->rchild;
			}
		}
	} else {
		if (target == father->lchild) {
			father->lchild = NULL;
		} else {
			father->rchild = NULL;
		}

	}
	delete target;
	return true;

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
		if (q.size() == 0) {
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
	Stack visit, start;
	if (p != NULL)
		start.push(p);
	while (!start.empty()) {
		if (!visit.empty()
				&& start.top()->data.getId() == visit.top()->data.getId()) {
			cout << visit.top()->data.getId() << " ";
			start.pop(), visit.pop();
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

queue<Node*> BinaryTree::GetNodes() {
	return GetNodes(root);
}

queue<Node*> BinaryTree::GetNodes(Node *p) {
	queue<Node*> result;
	if (p == NULL)
		return result;
	queue<Node*> q;
	queue<Node*> tmp;
	q.push(p);
	result.push(p);
	makeEmpty(tmp);
	while (q.size() > 0) {

		Node* n = q.front();
		q.pop();
		if (n->lchild != NULL) {
			tmp.push(n->lchild);
			result.push(n->lchild);
		}

		if (n->rchild != NULL) {
			tmp.push(n->rchild);
			result.push(n->rchild);
		}
		if (q.size() == 0) {
			copy(q, tmp);
			makeEmpty(tmp);
		}
	}
	return result;
}
