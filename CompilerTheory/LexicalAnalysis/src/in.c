#include <stdio.h>

/**
 * 这是注释
 */
void test(){
	printf("%d",233);
	if(1 >=2 ){
		printf("1>=2!");
	}else{
		printf("1<2!");
	}

	//logic op
	if(1<2 && 3>4 || 2>1){
		printf("233");
	}
}

//注释2
int go(){

	int i = 1;
	i++;
	i*=233;
	i--;
	i=i-1;

	i = i>>2;
	i = ~i;

	float c = 2.12;
	float z = \
		2;
	char *s = "233\t";
	char cc = 'B';
	return 0;
}
