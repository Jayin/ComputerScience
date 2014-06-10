#include "../source/BinaryTree.h"
#include "../source/Entity.h"
#include "../../libs/utils.h"
#include <assert.h>
#include <iostream>
using namespace std;

void ex3_test_insert();
void ex3_test_depth();

int main() {
//	ex3_test_depth();
	ex3_test_insert();
	return 0;
}

void ex3_test_depth() {
	Entity e1(3, "Jayin", "CS"), e2(1, "Tom", "CS"), e3(2, "Mars", "CS"), e4(5,
			"Cam", "CS"), e5(4, "Rick", "CS");

	BinaryTree tree;
	tree.Insert(e1);
	tree.Insert(e2);
	tree.Insert(e3);
	tree.Insert(e4);
	tree.Insert(e5);

	assert(3 == tree.Depth());
	_::d("ex3_test_depth test pass");
}

void ex3_test_insert() {
	Entity e1(8, "Jayin", "CS"), e2(7, "Tom", "CS"), e3(9, "Mars", "CS"), e4(5,
			"Cam", "CS"), e5(2, "Rick", "CS"), e6(6, "Rick", "CS"), e7(1,
			"Rick", "CS"), e8(4, "Rick", "CS");

	BinaryTree tree;
	tree.Insert(e1);
	tree.Insert(e2);
	tree.Insert(e3);
	tree.Insert(e4);
	tree.Insert(e5);
	tree.Insert(e6);
	tree.Insert(e7);
	tree.Insert(e8);

	_::d("--PreOrder--");
	tree.PreOrder();
	_::d("");
	_::d("--END--");
	_::d("");

	_::d("--InOrder--");
	tree.InOrder();
	_::d("");
	_::d("--END--");
	_::d("");

	_::d("--PostOrder--");
	tree.PostOrder();
	_::d("");
	_::d("--END--");
	_::d("");

	assert(5 == tree.Depth());
	_::d("finish");
}

