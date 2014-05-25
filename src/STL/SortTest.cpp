/*
 * SortTest.cpp
 *
 *  Created on: 2014年5月25日
 *      Author: Jayin Ton
 */
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

bool cmp(int i, int j) {
	return i > j;
}

void sortTest() {
	int myints[] = { 32, 71, 12, 45, 26, 80, 53, 33 };
	vector<int> myvector(myints, myints + 8);
	sort(myvector.begin(), myvector.end(),cmp);
	// print out content:
	cout << "myvector contains:";
	for (vector<int>::iterator it = myvector.begin(); it != myvector.end();
			++it)
		cout << ' ' << *it;
	cout << '\n';
}

void go(int num) {
	cout << num << endl;
}

void (*func)(int);

int main(int argc, char **argv) {
	sortTest();
//	(*go)(12);

}

