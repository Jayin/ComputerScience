/*
 * PostfixExp_test.cpp
 *
 *  Created on: 2014年6月16日
 *      Author: Jayin Ton
 */

#include "PostfixExp.h"
#include <iostream>
#include <cstdio>
using namespace std;

void test_PostfixExp(){
//	cout<<PostExp::get_postfixExp();
	double r = PostExp::cal_postfixExp1();
	printf("%lf",r);
}

int main(){
	test_PostfixExp();
	return 0;
}
