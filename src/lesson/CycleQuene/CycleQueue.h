/*
 * CycleQueue.h
 *
 *  Created on: 2014年4月22日
 *      Author: Jayin Ton
 */

#ifndef CYCLEQUEUE_H_
#define CYCLEQUEUE_H_

#include <iostream>
using namespace std;

const int QueueSize = 100;
template<class T>
class CycleQueue {
public:
	CycleQueue();
	virtual ~CycleQueue();
	void add(T t);
	T pop();
	T getHead();
	T getRear();
	bool isEmpty();
	bool isFull();
	int Size();
	int MaxSize();
private:
	int font, rear;
	T data[QueueSize];
};

template<class T> CycleQueue<T>::CycleQueue() {
	font = rear = 0;
}

template<class T> CycleQueue<T>::~CycleQueue() {
	//
}

template<class T> T CycleQueue<T>::getHead() {
	if (isEmpty()) {
		return NULL;
	} else {
		return data[font];
	}
}

template<class T> T CycleQueue<T>::getRear() {
	if (isEmpty()) {
		return NULL;
	} else {
		return data[rear];
	}
}

template<class T> void CycleQueue<T>::add(T t) {
	if (isFull()) {
		throw "It's full";
	} else {
		rear = (rear + 1) % QueueSize;
		data[rear] = t;
	}
}

template<class T> T CycleQueue<T>::pop() {
	if (isEmpty()) {
		throw "It's empty";
	} else {
		font = (font + 1) % QueueSize;
		return data[font ];
	}
}

template<class T> bool CycleQueue<T>::isEmpty() {
	return font == rear;
}

template<class T> bool CycleQueue<T>::isFull() {
	return (rear + 1) % QueueSize == font;
}

template<class T> int CycleQueue<T>::MaxSize() {
	return QueueSize;
}

template<class T> int CycleQueue<T>::Size() {
	if (rear >= font)
		return rear - font;
	else {
		return QueueSize + rear - font;
	}
}


#endif /* CYCLEQUEUE_H_ */
