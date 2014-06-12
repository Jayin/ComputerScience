#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
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

	static const char* itostirng(int integer) {
		if(integer ==0)
			return "0";
		int len = (int) (log10(abs(integer)) + 1);
		char *tmp = new char[len];
		sprintf(tmp, "%d", integer);
		return tmp;
	}

	static const char* stringcat(const char * a, const char * b) {
		char *tmp = new char[strlen(a) + strlen(b)];
		strcpy(tmp, a);
		strcat(tmp, b);
		return tmp;
	}
};

#endif

