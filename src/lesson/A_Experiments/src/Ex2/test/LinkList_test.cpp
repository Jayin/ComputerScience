#include "../source/LinkList.h"
#include "../../libs/utils.h"
#include <iostream>
#include <assert.h>
using namespace std;

void ex2_test_InsertAndDelete() {
	_::d("");
	_::d("ex2_test_InsertAndDelete() test start:");
	SimpleLinkList<int> l;
	assert(l.Empty());
	l.Insert(1);
	l.Insert(2);
	l.Insert(3);
	l.Insert(4);

	assert(1 == l.Get(0));

	l.Delete(0);
	assert(2 == l.Get(0));
	_::d("ex2_test_InsertAndDelete() test pass");
}

void ex2_test_get() {
	_::d("");
	_::d("ex2_test_get() test start");
	SimpleLinkList<int> l;
	l.Insert(0, 1);
	l.Insert(1, 2);
	l.Insert(2, 3);
	l.Insert(3, 4);
	assert(2 == l.Get(1));
	assert(3 == l.Get(2));
	assert(4 == l.Get(3));
	_::d("ex2_test_get() test pass");
}

//int main() {
//	ex2_test_InsertAndDelete();
//	ex2_test_get();
//	return 0;
//}

