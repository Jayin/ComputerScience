#include "../source/Topsort.h"
#include <iostream>
using namespace std;

//输入样例1:
//3 3
//1 2
//1 3
//2 3
//
//应该输出:无回路
//
//
//输入样例2:
//4 5
//1 2
//1 3
//2 4
//3 4
//4 3
//
//应该输出:有回路
//
//输入样例3:
//4 5
//1 2
//1 3
//2 4
//3 4
//4 1
//
//应该输出:有回路


//int main() {
//	if(solve(input())){
//		cout<<"无回路";
//	}else{
//		cout<<"有回路";
//	}
//	return 0;
//}
