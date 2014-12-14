#ifndef LINKLIST_H_
#define LINKLIST_H_

#include<iostream>
using namespace std;

template<class T>
struct Node {
	T data;
	Node* next;
};

template<class T>
class SimpleLinkList {
public:
	SimpleLinkList<T>();
	~SimpleLinkList();

	//get the length of array
	int Length();

	//return the position of the given T
	//return -1 if not exist
	int Locate(T t);

	//return the element by given specify position(since 0)
	T Get(int position);

	//insert the element into the end of LinkList
	void Insert(T element);

	//insert the element into the given specfy postion of LinkList
	void Insert(int position, T element);

	//delete the element by given specify position(since 0)
	void Delete(int position);

	//return true if the array is empty
	bool Empty();
private:
	Node<T> *first;
	Node<T>* GetNode(int positon);
};

template<class T>
SimpleLinkList<T>::SimpleLinkList() {
	first = new Node<T>;
	first->next = NULL;
}

template<class T>
SimpleLinkList<T>::~SimpleLinkList() {
	if (Length() > 0) {
		for (int i = Length() - 1; i >= 0; i--) {
			Delete(i);
		}
	}
}

template<class T>
int SimpleLinkList<T>::Length() {
	int len = 0;
	Node<T> *p = first->next;
	while (p) {
		len++;
		p = p->next;
	}
	return len;
}

template<class T>
int SimpleLinkList<T>::Locate(T t) {
	int pos = -1;
	Node<T> *p = first->next;
	while (p) {
		pos++;
		if (p->data == t) {
			break;
		}
	}
	return pos;
}

template<class T>
T SimpleLinkList<T>::Get(int i) {
	if (i < 0 || i >= Length())
		throw "index out of bound";
	int pos = 0;
	Node<T> *p = first->next;
	while (pos < i) {
		pos++;
		p = p->next;
	}
	return p->data;
}

template<class T>
Node<T> *SimpleLinkList<T>::GetNode(int i) {
	if (i < 0 || i >= Length())
		throw "index out of bound";
	int pos = 0;
	Node<T> *p = first->next;
	while (pos < i) {
		pos++;
		p = p->next;
	}
	return p;
}


template<class T>
void SimpleLinkList<T>::Insert(T element) {
	this->Insert(Length(),element);
}

//注意头和尾
template<class T>
void SimpleLinkList<T>::Insert(int position, T element) {
	if (position < 0 || position > Length()) {
		throw "index out of bound";
	}
	Node<T>* node = new Node<T>;
	node->data = element;
	if (position == 0) {
		node->next = first->next;
		first->next = node;
	} else if (position == Length()) {
		Node<T> *last = GetNode(Length() - 1);
		node->next = NULL;
		last->next = node;
	} else {
		Node<T> *last = GetNode(position - 1);
		node->next = last->next;
		last->next = node;
	}
}

template<class T>
void SimpleLinkList<T>::Delete(int position) {
	if (position < 0 || position > Length()) {
		throw "index out of bound";
	}
	Node<T> *tmp = NULL;
	if (position == 0) {
		tmp = first->next;
		first->next = tmp->next;
	} else {
		Node<T> *p = GetNode(position - 1);
		tmp = p->next;
		p->next = tmp->next;
	}
	delete tmp;
}



template<class T>
bool SimpleLinkList<T>::Empty(){
	return Length() == 0;
}

#endif /* LINKLIST_H_ */
