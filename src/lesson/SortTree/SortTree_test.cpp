/*
 * SortTree_test.cpp
 *
 *  Created on: 2014年5月19日
 *      Author: Jayin Ton
 */

#include "SortTree.h"
#include <iostream>
using namespace std;

void SortTreeTest() {
	cout<<"SortTreeTest start"<<endl;
	SortTree t;
	t.add(2);
	t.add(3);
	t.add(1);
	t.add(4);
	t.inOrder();
}

//int main() {
//
//	SortTreeTest();
//	return 0;
//}

