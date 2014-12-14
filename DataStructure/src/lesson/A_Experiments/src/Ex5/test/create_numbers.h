#include <cstdlib>
#include <fstream>
using namespace std;

int MAX = 10 * 1000;

int* create_random(int length, int from, int to) {
	int *nums = new int[length];
	for (int i = 0; i < length; i++) {
		//create [from,to]
		nums[i] = rand() % (to - from + 1) + from;
	}
	return nums;
}

void create_random_file(const char* filename, int length, int from, int to) {
	ofstream outfile;
	outfile.open(filename,ofstream::out );
	int *nums = create_random(length, from, to);
	for (int i = 0; i < length; i++) {
		outfile<<nums[i]<<" ";
	}
	outfile.close();
	cout<<"create file finish!"<<endl;
}

