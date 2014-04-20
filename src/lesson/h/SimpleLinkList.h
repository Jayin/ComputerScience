

#ifndef LINKLIST_H_
#define LINKLIST_H_

#include<iostream>
using namespace std ;


class LinkList {
public:
	int data;
	LinkList* head;
	LinkList* next;
	LinkList* tail;
	LinkList();
	virtual ~LinkList();
	void add(int);
	void pop();
    long length();
    int getFirst();
    void print_list();
private:
    void release();
};

#endif /* LINKLIST_H_ */
