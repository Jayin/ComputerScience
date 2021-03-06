#include <iostream>
#include "../source/Sort.h"
#include "./create_numbers.h"
#include "../../libs/utils.h"
using namespace std;
/**
 * @param length:数组长度
 * @param from,to:残生随机数范围[from,to]
 */
void test_quick_sort(const char* filename, int length, int from, int to);
void test_pop_sort(const char* filename, int length, int from, int to);
void create_file();
void sort_test_main();

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
//////////////////
// Main         //
//////////////////

//int main() {
//	sort_test_main();
//	return 0;
//}



void sort_test_main(){
	create_file();

	test_pop_sort("src/Ex5/test/random_10.txt", 10, 1, 100);
//	test_pop_sort("src/Ex5/test/random_1000.txt", 1000, 1, 1000);
//	test_pop_sort("src/Ex5/test/random_10000.txt", 10000, 1, 10000);
//	test_pop_sort("src/Ex5/test/random_100000.txt", 100000, 1, 100000);

//	test_quick_sort("src/Ex5/test/random_10.txt", 10, 1, 100);
//	test_quick_sort("src/Ex5/test/random_1000.txt", 1000, 1, 1000);
//	test_quick_sort("src/Ex5/test/random_10000.txt", 10000, 1, 10000);
//	test_quick_sort("src/Ex5/test/random_100000.txt", 100000, 1, 100000);
}

void create_file() {
	create_random_file("src/Ex5/test/random_10.txt", 10, 1, 100);
	create_random_file("src/Ex5/test/random_1000.txt", 1000, 1, 1000);
	create_random_file("src/Ex5/test/random_10000.txt", 10000, 1, 10000);
	create_random_file("src/Ex5/test/random_100000.txt", 100000, 1, 100000);
}

void test_quick_sort(const char* filename, int length, int from, int to) {
	cout << "----quick sort test " << filename << " ----" << endl;
	ifstream fin;
	ofstream fout;

	const char* outfilename = _::stringcat(_::stringcat("src/Ex5/test/result_qsort_",_::itostirng(length)),".txt");
	fin.open(filename, ifstream::in);
	fout.open(outfilename,ofstream::out);
	int *a = new int[length];

	for (int i = 0; i < length; i++) {
		fin >> a[i];
//		cout<<a[i]<<" ";
	}
	cout<<endl;
	quick_sort(a, 0, length - 1);

	for (int i = 0; i < length; i++) {
		fout<<a[i]<<" ";
//		cout<<a[i]<<" ";
	}
	fin.close();
	fout.close();
	cout << endl;
	cout << "----END ----" << endl;
}

void test_pop_sort(const char* filename, int length, int from, int to) {
	cout << "----pop sort test " << filename << " ----" << endl;
	ifstream fin;
	ofstream fout;

	const char* outfilename = _::stringcat(_::stringcat("src/Ex5/test/result_popsort_",_::itostirng(length)),".txt");
	fin.open(filename, ifstream::in);
	fout.open(outfilename,ofstream::out);
	int *a = new int[length];

	for (int i = 0; i < length; i++) {
		fin >> a[i];
//		cout<<a[i]<<" ";
	}
	cout<<endl;

	pop_sort(a,length);

	for (int i = 0; i < length; i++) {
		fout<<a[i]<<" ";
//		cout<<a[i]<<" ";
	}
	fin.close();
	fout.close();
	cout << endl;
	cout << "----END ----" << endl;
}


