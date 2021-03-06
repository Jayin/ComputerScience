/*
 * TraversalBinaryTree_test.cpp
 *
 *  Created on: 2014年5月20日
 *      Author: Jayin Ton
 */

#include "TraversalBinaryTree.h"
#include "../SortTree/SortTree.h"
#include <queue>
using namespace std;

void TraversalBinaryTreetest() {
	cout << "test start" << endl;
	SortTree t;
	t.add(2);
	t.add(7);
	t.add(3);
	t.add(9);
	t.add(4);
	t.add(5);
	t.add(6);
	cout << "=======source tree inOrder========" << endl;
	t.inOrder();
	cout << endl << "=======result========" << endl;
	TraversalBinaryTree *tree = new TraversalBinaryTree(t.getTree());
	cout << "PreOrder" << endl;
	tree->PreOrder();
	cout << endl;

	cout << "PreOrder2" << endl;
	tree->PreOrder2();
	cout << endl;

	cout << "InOrder" << endl;
	tree->InOrder();
	cout << endl;

	cout << "InOrder2" << endl;
	tree->InOrder2();
	cout << endl;

	cout << "PostOrder" << endl;
	tree->PostOrder();
	cout << endl;

	cout << "PostOrder2" << endl;
	tree->PostOrder2();
	cout << endl;

	cout << "LeverOrder" << endl;
	tree->LeveOrder();
	cout << endl;
}

//int main() {
//	TraversalBinaryTreetest();
//	return 0;
//}
