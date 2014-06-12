#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <cstdlib>
using namespace std;

class _ {
public:
	static void d(const char *msg) {
		cout << msg << endl;
	}

	static void d(long msg) {
		cout << msg << endl;
	}

	static int stringtoi(const char* str) {
		return atoi(str);
	}

	static const char* stringcat(const char * a, const char * b) {
		char *tmp = new char[strlen(a)+strlen(b)];
		strcpy(tmp, a);
		strcat(tmp, b);
		return tmp;
	}
};

#endif

