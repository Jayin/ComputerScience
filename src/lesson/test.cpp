#include "h/SimpleLinkList.h"
#include <iostream>
#include <assert.h>
using namespace std;


int main(){

  LinkList l;
  l.add(1);
  l.add(2);
  l.add(3);
  cout<<l.length()<<endl;
  cout<<"first="<<l.getFirst()<<endl;
  l.print_list();
  l.pop();
  l.print_list();
  l.pop();
  l.print_list();

}
