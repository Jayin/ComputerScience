#include "h/LinkList.h"
#include <iostream>
#include <assert.h>
using namespace std;

void InsertAndDelete() {
	SimpleLinkList<int> l;
	l.Insert(0, 1);
	l.Insert(1, 2);
	l.Insert(2, 3);
	l.Insert(3, 4);
	l.PrintList();
	l.Delete(0);
	l.PrintList();
}

void Get() {
	SimpleLinkList<int> l;
	l.Insert(0, 1);
	l.Insert(1, 2);
	l.Insert(2, 3);
	l.Insert(3, 4);
	assert(2 == l.Get(1));
	assert(3 == l.Get(2));
	assert(4 == l.Get(3));
    cout<<"Get() test pass"<<endl;
}

//int main() {
//	InsertAndDelete();
//	Get();
//	return 0;
//}

