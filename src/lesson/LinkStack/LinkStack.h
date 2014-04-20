/*
 * LinkStack.h
 * 链栈
 *  Created on: 2014年4月20日
 *      Author: Jayin Ton
 */

#ifndef LINKSTACK_H_
#define LINKSTACK_H_

#include <iostream>

template<class T> struct Node {
	T data;
	Node<T> *next;
};

template<class T> class LinkStack {
public:
	LinkStack();
	virtual ~LinkStack();
	void Push(T t);
	T Pop(); //出栈释放空间
	T GetTop();
	bool isEmpty();

private:
	Node<T> *top;
};

template<class T> LinkStack<T>::LinkStack() {
	top = NULL;
}

template<class T> LinkStack<T>::~LinkStack() {
}

template<class T> void LinkStack<T>::Push(T t) {
	Node<T>* node = new Node<T>;
	node->data = t;
	node->next = top;
	top = node;
}

template<class T> T LinkStack<T>::Pop() {
	if (top == NULL)
		throw "under flow";
	Node<T> *tmp = top;
	top = top->next;
	T res = tmp->data;
	delete tmp;
	return res;
}

template<class T> T LinkStack<T>::GetTop() {
	return top == NULL ? NULL : top->data;
}

template<class T>  bool LinkStack<T>::isEmpty() {
	return top == NULL ? true : false;
}

#endif /* LINKSTACK_H_ */
