#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
long long n,a,b,c,ans;

int main() {
	scanf("%lld %lld %lld %lld",&n,&a,&b,&c);
	for (long long i=0;i<n+1;++i){
		for (long long j=0;j<n+1;++j){
			long long x3=(n-a*i-b*j)/c;
			if (x3>=0 && a*i+b*j+c*x3==n){
				ans=max(ans,i+j+x3);
				//cout << i << " " << j << " " << x3 << endl;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
