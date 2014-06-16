/*
 * PostfixExp.h
 *
 *  Created on: 2014年6月16日
 *      Author: Jayin Ton
 */

#ifndef POSTFIXEXP_H_
#define POSTFIXEXP_H_

#include <vector>
#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

namespace PostExp {

static string input() {
	string tmp;
	cin >> tmp;
	return tmp;
}

static int get_level(char c) {
	if (c == '(')
		return 0;
	else if (c == '+' || c == '-')
		return 1;
	else
		return 2;
}

static string get_postfixExp() {
	string raw = input();
	int len = raw.size();
	stack<char> opt;
	vector<string> res;
	string tmp; //保存一个数
	string result;
	for (int i = 0; i < len; i++) {

		if ((raw[i] >= '0' && raw[i] <= '9') || raw[i] == '.') {
			if (i + 1 < len
					&& ((raw[i + 1] >= '0' && raw[i + 1] <= '9')
							|| raw[i + 1] == '.')) {
				tmp += raw[i];
			} else {
				tmp += raw[i];
				res.push_back(tmp);
				tmp.clear();
			}
		} else if (raw[i] == '(') {
			opt.push(raw[i]);
		} else if (raw[i] == ')') {
			while (!opt.empty() && opt.top() != '(') {
				res.push_back(string(1, opt.top()));
				opt.pop();
			}
			//pop the '('
			opt.pop();
		} else {
			//operation
			if (opt.empty()) {
				opt.push(raw[i]);

			} else {
				if (get_level(raw[i]) > get_level(opt.top())) {
					opt.push(raw[i]);
				} else {
					res.push_back(string(1, opt.top()));
					opt.pop();
					opt.push(raw[i]);
				}
			}
		}
	}
	while (!opt.empty()) {
		res.push_back(string(1, opt.top()));
		opt.pop();
	}
	len = res.size();
	for (int i = 0; i < len; i++) {
		result += res[i] + " ";
	}
	return result;
}

static void print(vector<double> res, stack<char> opt) {
	cout << "res-->";
	for (vector<double>::iterator it = res.begin(); it != res.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	cout << "opt-->";
	while (!opt.empty()) {
		cout << opt.top() << " ";
		opt.pop();
	}
	cout << endl;
}

static double deal_with(vector<double> &res, stack<char> &opt) {
	char opteration = opt.top();
	opt.pop();
	double b = res.back();
	res.pop_back();
	double a = res.back();
	res.pop_back();
	double result = 0;
	if (opteration == '+') {
		result = a + b;
	} else if (opteration == '-')
		result = a - b;
	else if (opteration == '/')
		result = a / b;
	else if (opteration == '*')
		result = a * b;
	cout << "deal with: " << a << opteration << b << "=" << result << endl;
	return result;
}

static double cal_postfixExp1() {
	string raw = input();
	int len = raw.size();
	stack<char> opt;
	vector<double> res;
	string tmp; //保存一个数
	for (int i = 0; i < len; i++) {
		cout << "deal with: " << raw[i] << endl;
		if ((raw[i] >= '0' && raw[i] <= '9') || raw[i] == '.') {
			if (i + 1 < len
					&& ((raw[i + 1] >= '0' && raw[i + 1] <= '9')
							|| raw[i + 1] == '.')) {
				tmp += raw[i];
			} else {
				tmp += raw[i];
				res.push_back(strtod(tmp.c_str(), NULL));
				tmp.clear();
			}
		} else if (raw[i] == '(') {
			opt.push(raw[i]);
		} else if (raw[i] == ')') {
			while (!opt.empty() && opt.top() != '(') {
				//todo 处理括号内容
				double t = deal_with(res, opt);
				res.push_back(t);
			}
			//pop the '('
			opt.pop();
		} else {
			//operation
			if (opt.empty()) {
				opt.push(raw[i]);

			} else {
				if (get_level(raw[i]) > get_level(opt.top())) {
					opt.push(raw[i]);
				} else {
					//todo 处理符号
					double t = deal_with(res, opt);
					res.push_back(t);
					opt.push(raw[i]);
				}
			}
		}
	}
	while (!opt.empty()) {
		//处理剩下的
		double t = deal_with(res, opt);
		res.push_back(t);
	}
	return res.back();
}

}

#endif /* POSTFIXEXP_H_ */
