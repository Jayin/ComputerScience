#include "h/LinkList.h"
#include <iostream>
#include <assert.h>
using namespace std;


int main() {
	SimpleLinkList<int> l;
	l.Insert(0,1);
	l.PrintList();
	l.Delete(0);
	l.PrintList();

}

