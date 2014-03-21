#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int a,b,c;
	int i,j,k;
	bool use[8000+100];
	while(cin>>a>>b>>c)
	{
		memset(use,false,sizeof(use));
		if(a==b && b==c && c==0)
	      break;
	    for(i=0;i<=a;i++)
	    	for(j=0;j<=b;j++)
	    		for(k=0;k<=c;k++) 
                   use[i+j*2+k*5]=true;
       for(i=a+1;;i++)
       {
           if(!use[i])
           {
             printf("%d\n",i);
             break;
           }
        }	 
	}
	return 0;
}
