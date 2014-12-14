/*
 * ReverseString.cpp
 *题目描述
 给定一个字符串，要求把字符串前面的若干个字符移动到字符串的尾部，如把字符串“abcdef”前面的2个字符“ab” 移动到字符串的尾部，即变成“cdefab”。
 请写一个函数完成此功能，要求对长度为n的字符串操作的时间复杂度为 O(n)，空间复杂度为 O(1)。
 *  Created on: 2014年6月6日
 *      Author: Jayin Ton
 */
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void ReverseString(char *s, int from, int to) {
	while (from < to) {
		char t = s[from];
		s[from++] = s[to];
		s[to--] = t;
	}
}

void LeftRotateString(char *s, int n, int m) {
	m %= n;               //若要左移动大于n位，那么和%n 是等价的
	ReverseString(s, 0, m - 1); //反转[0..m - 1]，套用到上面举的例子中，就是X->X^T，即 abc->cba
	ReverseString(s, m, n - 1); //反转[m..n - 1]，例如Y->Y^T，即 def->fed
	ReverseString(s, 0, n - 1); //反转[0..n - 1]，即如整个反转，(X^TY^T)^T=YX，即 cbafed->defabc。
}

//int main() {
//	char str[] = "abcdefg";
//	LeftRotateString(str, 7, 3);
//	cout << str << endl;
//	return 0;
//}

