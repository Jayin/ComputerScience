#include "../source/Vector.h"
#include "../../libs/utils.h"
#include <iostream>
#include <assert.h>
using namespace std;

int ex1_test() {
	_::d("ex1_test_insert:");
	Vector<int> v;
	v.Insert(0);
	v.Insert(1);
	v.Insert(2);
	v.Insert(3);
	v.Insert(4);
	v.Insert(5);

	_::d(v.Length());
	assert(v.Length() == 6);

	_::d(v.Get(0));
	assert(v.Get(0) == 0);

	_::d(v.Get(3));
	assert(v.Get(3) == 3);

	v.Delete(3);

	_::d(v.Length());
	assert(v.Length() == 5);

	_::d(v.Get(0));
	assert(v.Get(0) == 0);

	_::d(v.Get(3));
	assert(v.Get(3) == 4);

	_::d("ex1_test_insert:pass all test");
	return 0;
}

//int main() {
//	return ex1_test();
//}

