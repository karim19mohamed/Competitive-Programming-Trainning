#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
long long x,y,n,f[6],ans;


int main() {
	scanf("%lld %lld %lld",&x,&y,&n);
	f[0]=x;
	f[1]=y;
	f[2]=y-x;
	f[3]=-x;
	f[4]=-y;
	f[5]=x-y;
	ans=(f[(n-1)%6]+1000000007*2)%1000000007;
	printf("%lld\n",ans);
	return 0;
}
