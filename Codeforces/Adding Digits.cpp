#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
long long a,b,n,c;
bool ans;

int main() {
	scanf("%lld %lld %lld",&a,&b,&n);
	a*=10;
	for(int i=0;i<10;++i){
		c=a+i;
		if(c%b==0){
			ans=1;
			a=c;
			break;
		}
	}
	if (ans){
		printf("%lld",a);
		for (long long i=0;i<n-1;++i) printf("0");
	}else{
		printf("-1");
	}
	printf("\n");
	return 0;
}
