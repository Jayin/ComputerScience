/*
 * LinkQueue_test.cpp
 *
 *  Created on: 2014年4月22日
 *      Author: Jayin Ton
 */
#include "LinkQueue.h"
#include <assert.h>
#ifdef test_LinkQueue
#define test_LinkQueue

void print_list(LinkQueue<int> &q);
void test_add();
void test_get();
#endif

void print_list(LinkQueue<int> &q) {
	cout << "data:" << endl;
	while (!q.isEmpty()) {
		int d = q.pop();
		cout << d << " ";
	}
	cout << endl;
}

void test_add() {
	LinkQueue<int> q;
	q.add(1);
	q.add(2);
	q.add(3);
	q.add(4);
	print_list(q);
}

void test_get() {
	LinkQueue<int> q;
	q.add(1);
	q.add(2);
	q.add(3);
	q.add(4);
	assert(1 == q.GetFirst());
	assert(4 ==q.GetLast());
}

//int main() {
// 	test_add();
//	test_get();
//	cout<<"test pass"<<endl;
//	return 0;
//}
//
