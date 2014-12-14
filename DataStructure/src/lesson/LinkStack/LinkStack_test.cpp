/*
 * LinkStack_test.cpp
 *
 *  Created on: 2014年4月20日
 *      Author: Jayin Ton
 */

#include "LinkStack.h"
#include <iostream>
#include <assert.h>

using namespace std;

void printList(LinkStack<int> stack){
   cout<<"stack :"<<endl;
   while(!stack.isEmpty()){
	   cout<<stack.Pop()<<" ";
   }
   cout<<endl;
}

void push(){
	LinkStack<int> stack ;
	stack.Push(1);
	assert(1==stack.GetTop());

	stack.Push(2);
	assert(2==stack.GetTop());

	stack.Push(3);
	assert(3==stack.GetTop());
	printList(stack);
	cout<<"test pass"<<endl;
}

//
//int main(){
//	push();
//	return 0;
//}

