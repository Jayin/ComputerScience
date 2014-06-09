#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
using namespace std;

class _ {
public :
	static void d(const char *msg) {
		cout << msg << endl;
	}

	static void d(long msg) {
		cout << msg << endl;
	}
};

#endif

