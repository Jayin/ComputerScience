#ifndef VECTOR_H_
#define VECTOR_H_

#include <exception>
#include <cstring>
#include <cstdlib>
#include "../../libs/utils.h"
using namespace std;

template<class T>
class Vector {
public:
	Vector();
	Vector(int capacity);
	virtual ~Vector();

	//get the length of array
	int Length();

	//return the element by given specify position(since 0)
	T Get(int position);

	//insert the element into the end of array
	void Insert(T element);

	//insert the element into the given specfy postion of array
	void Insert(int position, T element);

	//delete the element by given specify position(since 0)
	void Delete(int position);

	//return true if the array is empty
	bool Empty();

private:
	T *head;
	int _capacity;
	int _len;

	void released();
};

template<class T>
Vector<T>::Vector() {
	new (this) Vector(32);
}

template<class T>
Vector<T>::Vector(int capacity) {
	this->_capacity = capacity;
	head = new T[_capacity];
	_len = 0;
}

template<class T>
Vector<T>::~Vector() {
	released();
}

template<class T>
int Vector<T>::Length() {
	return this->_len;
}

template<class T>
T Vector<T>::Get(int position) {
	if (position < 0 || position >= this->_len) {
		throw "Index Out  Of Bound";
	}
	return head[position];
}

template<class T>
void Vector<T>::Insert(T element) {
	this->Insert(this->_len, element);
}

template<class T>
void Vector<T>::Insert(int position, T element) {
	//range of [0,_len]
	if (position < 0 || position > this->_len) {
		throw "Index Out  Of Bound";
	}
	if (this->_len >= this->_capacity) {
		//increase the array, catcat that exception
		T *newArray = new T[this->_capacity * 2];
		try {
			memcpy(newArray, this->head, this->_len * sizeof(T));
			_capacity *= 2;
		} catch (exception &e) {
			_::d(e.what());
		}
	}
	//insert
	head[position] = element;
	if (position == _len) {
		_len++;
	}
}

template<class T>
void Vector<T>::Delete(int position) {
	if (position < 0 || position >= this->_len) {
		throw "Index Out  Of Bound";
	}

	for (int i = position; i < this->_len; i++) {
		head[i] = head[i + 1];
	}
	this->_len--;
}

template<class T>
bool Vector<T>::Empty() {
	return Length() == 0;
}

template<class T>
void Vector<T>::released() {
	free(head);
}

#endif /* VECTOR_H_ */
