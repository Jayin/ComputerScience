/*
 * LinkQueue.h
 *
 *  Created on: 2014年4月22日
 *      Author: Jayin Ton
 */

#ifndef LINKQUEUE_H_
#define LINKQUEUE_H_
#include <iostream>
using namespace std;

template<class T> struct Node {
	T data;
	Node *next;
};

template<class T>
class LinkQueue {
public:
	LinkQueue();
	virtual ~LinkQueue();
	void add(T t);
	T pop();
	int Size();
	bool isEmpty();
	T GetFirst();
	T GetLast();
private:
	Node<T> *font, *rear;
};

template<class T> LinkQueue<T>::LinkQueue() {
	font = rear = new Node<T>;  //带头结点
	font->next = NULL;
}

template<class T> LinkQueue<T>::~LinkQueue() {
	while (!isEmpty()) {
		Node<T> *tmp = font;
		font = font->next;
		delete tmp;
	}
	delete font;
}

template<class T> void LinkQueue<T>::add(T t) {
	Node<T> *tmp = new Node<T>;
	tmp->data =t;
	tmp->next = NULL;
	rear->next = tmp;
	rear = tmp;
}

template<class T> T LinkQueue<T>::pop() {
	if(isEmpty()){
		throw "It's empty";
	}
	Node<T> *tmp =font->next;
	T res = tmp->data;
	font->next = tmp->next;
	delete tmp;
	return res;
}

template<class T> int LinkQueue<T>::Size(){
	Node<T> *p = font->next;
	int len = 0;
	while(p){
		len++;
		p = p->next;
	}
	return len;
}

template<class T> T LinkQueue<T>::GetFirst(){
	if(isEmpty())throw "It's empty";
	return font->next->data;
}

template<class T> T LinkQueue<T>::GetLast(){
	if(isEmpty()) throw "It's empty";
	return rear->data;
}

template<class T> bool LinkQueue<T>::isEmpty() {
	return font->next == NULL;
}

#endif /* LINKQUEUE_H_ */
