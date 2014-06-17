#include "PostfixExp.h"
#include <iostream>
#include <cstdio>
using namespace std;

void test_PostfixExp(){
	//输出后缀表达式
	cout<<"input a expression: (e.g: 1*2+2+3*2  )"<<endl;
	cout<<"The PostfixExp is : "<<PostExp::get_postfixExp()<<endl;

	//计算表达式的值
	cout<<"input a expression: (e.g: 1*2+2+3*2  )";
	double r = PostExp::cal_postfixExp();
	printf("result = %lf",r);
}

int main(){
	test_PostfixExp();
	return 0;
}
