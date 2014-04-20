#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

void work(){
	 int n;
		 while(cin>>n){
		 	vector<string> ans;
		    string in,out;
		    stack<char> s;
		    cin>>in>>out;
		    int left = n;
		    int numIn =0,numOut=0;
		    while(numIn<n){
		    	//in
		    	while(s.size()==0 || s.top()!=out[numOut]){
		    		s.push(in[numIn++]);
		    		ans.push_back("in");
		    	}
		    	while (s.size()>0 && s.top()==out[numOut]){
	                numOut++;
	                s.pop();
	                ans.push_back("out");
		    	}
		    }
		    if(numOut==n){
		    	cout<<"Yes."<<endl;
		    	for(std::vector<string>::iterator it=ans.begin();it!=ans.end();++it){
		    		cout<<*it<<endl;
		        }
		    }else{
		    	cout<<"No."<<endl;
		    }
		    cout<<"FINISH"<<endl;
		 }
}
//
//int main(){
//	work();
//	return 0;
//}

