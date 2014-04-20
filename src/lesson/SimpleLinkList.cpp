#include "h/SimpleLinkList.h"

LinkList::LinkList() {
	data = 0;
	next = NULL;
	this->head = this;
	this->tail = this;
}

LinkList::~LinkList() {
//	release();
	cout<<"release finish"<<endl;
}

void LinkList::add(int d) {
	LinkList* p = new LinkList();
	p->next = NULL;
	p->data = d;
	tail->next = p;
	tail = p;
}

void LinkList::pop(){
	if(head->next ==NULL)
		return;
	LinkList* first = head->next;
	head->next = first->next;
	delete first;
}

long LinkList::length() {
	LinkList* p = head->next;
	int res = 0;
	while (p) {
		res++;
		p = p->next;
	}
	return res;
}

int LinkList::getFirst(){
    if(head->next == NULL){
    	return head->data;
    }else{
    	return head->next->data;
    }
}

void LinkList::print_list(){
    LinkList* p = head->next;
    while(p){
    	cout<<p->data<<endl;
    	p = p->next;
    }
}

void LinkList::release(){
	LinkList* p = head->next;
	while(p){
		LinkList* tmp = p;
		p = p->next;
		delete tmp;
	}
}


