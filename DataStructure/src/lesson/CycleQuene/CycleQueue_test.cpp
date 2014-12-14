/*
 * CycleQueue_test.cpp
 *
 *  Created on: 2014年4月22日
 *      Author: Jayin Ton
 */

#include "CycleQueue.h"
#include <iostream>
#include <assert.h>
#include <exception>

#ifdef test_CycleQueue
#define test_CycleQueue

void test_add() {
	CycleQueue<int> q;
	q.add(1);
	q.add(2);
	q.add(3);
	q.add(4);
	print_list(q);
}

#endif
using namespace std;

void print_list(CycleQueue<int> &q) {
	cout << "data:" << endl;
	while (!q.isEmpty()) {
		int d = q.pop();
		cout << d << " ";
	}
	cout << endl;
}

void test_opt() {
	CycleQueue<int> q;
	q.add(1);
	q.add(2);
	q.add(3);
	q.add(4);
	print_list(q);
	assert(0 == q.Size());
	try {
		q.pop();
	} catch (const char* str) {
		cout << str << endl;
	}
	for (int i = 0; i < q.MaxSize() - 1; i++) {
		q.add(i);
	}
	print_list(q);
	try {
		q.add(q.MaxSize());
	} catch (const char* e) {
		cout << e << endl;
	}

}

//int main(int argc, char **argv) {
//	test_add();
//	test_opt();
//	cout<<"test pass"<<endl;
//}
//
