#include <iostream>
#include "../source/QuickSort.h"
#include "./create_numbers.h"
#include "../../libs/utils.h"
using namespace std;
/**
 * @param length:数组长度
 * @param from,to:残生随机数范围[from,to]
 */
void test_quick_sort(const char* filename, int length, int from, int to);

void create_file();

void test() {
	int x = _::stringtoi("123456");
	cout << x << endl;
	const char* a = _::stringcat("name:", "jackson");
	cout << a << endl;
	const char* s = _::itostirng(0);
	cout << s << endl;
	s = _::itostirng(-0);
	cout << s << endl;

	s =_::itostirng(+1234);
	  cout<<s<<endl;

}
int main() {
//	test_quick_sort(200000, 1, 5000);
//	create_file();
//	test_quick_sort("src/Ex5/test/random_1000.txt", 1000, 1, 1000);
//	test_quick_sort("src/Ex5/test/random_10.txt", 10, 1, 100);
	test();
	return 0;
}

void create_file() {
	create_random_file("src/Ex5/test/random_10.txt", 10, 1, 100);
	create_random_file("src/Ex5/test/random_1000.txt", 1000, 1, 1000);
	create_random_file("src/Ex5/test/random_10000.txt", 10000, 1, 10000);
	create_random_file("src/Ex5/test/random_100000.txt", 100000, 1, 100000);
}

void test_quick_sort(const char* filename, int length, int from, int to) {
	cout << "----test " << filename << " ----" << endl;
	ifstream fin;
	ofstream fout;
	fin.open(filename, ifstream::in);
//	fout.open(_::stringcat(filename,))
	int *a = new int[length];
	cout << "file read:" << endl;
	for (int i = 0; i < length; i++) {
		fin >> a[i];
		cout << a[i] << " ";
	}
	fin.close();
	cout << "\nfile read  end" << endl;
	quick_sort(a, 0, length - 1);
	cout << "\nsort result:" << endl;
	for (int i = 0; i < length; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "----END ----" << endl;
}

