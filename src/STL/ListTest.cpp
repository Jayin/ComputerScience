#include<list>
#include<iostream>

void print(std::list<int> l ){
	for(std::list<int>::iterator it = l.begin();it != l.end();it++){
		std::cout<<*it<<' ';
	}
	std::cout<<'\n';
}

void init(){

  std::list<int> first;                               
  std::list<int> second (4,100);                      
  std::list<int> third (second.begin(),second.end());  
  std::list<int> fourth (third);                      

  int myints[] = {16,2,77,29};
  std::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of fifth are: ";
  print(fifth);

  std::cout << '\n';

}
void resize(){
  std::list<int> mylist;

  for (int i=1; i<10; ++i) mylist.push_back(i);

  mylist.resize(5);
  mylist.resize(8,100);
  mylist.resize(2,200);

  std::cout << "mylist contains:";
  for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';
	
}

// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

void merge(){
  std::list<double> first, second;

  first.push_back (3.1);
  first.push_back (2.2);
  first.push_back (2.9);

  second.push_back (3.7);
  second.push_back (7.1);
  second.push_back (1.4);

  first.sort();
  second.sort();

  first.merge(second);

  // (second is now empty)

  second.push_back (2.1);

  first.merge(second,mycomparison);

  std::cout << "first contains:";
  for (std::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

int main(){
	
	init();
    //resize();
   // megery();
    return 0;	
} 


