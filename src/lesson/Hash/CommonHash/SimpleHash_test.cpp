/*
 * SimpleHash_test.cpp
 *
 *  Created on: 2014年5月20日
 *      Author: Jayin Ton
 */

#include "SimpleHash.h"
#include <iostream>
#include <string>
using namespace std;

void simplehash() {
	cout << "===simple====" << endl;
	cout << getHashIndex("mars", 100) << endl;
	cout << getHashIndex("mars", 100) << endl;
	cout << getHashIndex("json", 100) << endl;
	cout << getHashIndex("jsp", 100) << endl;
	cout << getHashIndex("Tim Kong", 100) << endl;

	cout << "===Java hash_string====" << endl;
	cout << hash_string("mars", 100) << endl;
	cout << hash_string("mars", 100) << endl;
	cout << hash_string("json", 100) << endl;
	cout << hash_string("jsp", 100) << endl;
	cout << hash_string("Tim Kong", 100) << endl;

	cout << "===hash_fnv1a====" << endl;
	cout << hash_fnv1a("mars", 100) << endl;
	cout << hash_fnv1a("mars", 100) << endl;
	cout << hash_fnv1a("json", 100) << endl;
	cout << hash_fnv1a("jsp", 100) << endl;
	cout << hash_fnv1a("Tim Kong", 100) << endl;
}

int main(int argc, char **argv) {
	simplehash();
	return 0;
}
