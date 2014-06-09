#include "../source/Vector.h"
#include "../../libs/utils.h"
#include <iostream>

using namespace std;

int ex1test() {
	Vector<int> v;
	v.Insert(1);
	v.Insert(2);
	v.Insert(3);
	v.Insert(4);
	v.Insert(5);
	v.Insert(6);
	_::d(v.Length());
	_::d(v.Get(0));
	_::d(v.Get(1));
	v.Delete(3);
	_::d(v.Length());
	_::d(v.Get(3));
	_::d(v.Get(4));
	return 0;
}

int main() {
	return ex1test();
}

