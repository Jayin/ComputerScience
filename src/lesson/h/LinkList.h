
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
	int Length();
	int Locate(T t); //return -1 if not exist
	T Get(int position);//start from 0
	void Insert(int position,T t);//start from 0
	void Delete(int position);//start from 0
	void PrintList();
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
	first = new Node<T>;
	first->next = NULL;
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

//注意头和尾
template<class T>
void SimpleLinkList<T>::Insert(int position, T t) {
	if (position < 0 || position > Length()) {
		throw "index out of bound";
	}
	Node<T>* node = new Node<T>;
	node->data = t;
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
	if(position == 0){
		tmp = first->next;
		first->next = tmp->next;
	}else{
		Node<T> *p  = GetNode(position-1);
		tmp = p->next;
		p->next = tmp->next;
	}
	delete tmp;
}

template<class T>
void SimpleLinkList<T>::PrintList(){
	Node<T> *p = first->next;
	cout<<"List:"<<endl;
	while(p){
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}
#endif /* LINKLIST_H_ */
