#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
long long n,a[100009],b[100009],num_seg;
long long l,r;
stack <long long> q;

int main() {
	scanf("%lld",&n);
	for (long long i=0;i<n;++i){
		scanf("%lld",&a[i]);
		b[i]=a[i];
	}
	sort(b,b+n);
	bool seg=0;
	for (long long i=0;i<n;++i){
		if (i<n-1 && a[i]>a[i+1] && !seg){
			l=i;
			seg=1;
		}
		if (seg){
			q.push(a[i]);
		}
		if (i<n-1 && a[i]<a[i+1] && seg){
			r=i;
			break;
		}
	}
	if (!seg){
		printf("yes\n");
		printf("1 1\n");
	}else{
		if (r<=l) r=n-1;
		long long idx=l;
		while(!q.empty()){
			a[idx]=q.top();
			++idx;
			q.pop();
		}
		bool ans=1;
		for(long long i=0;i<n;++i){
			if (a[i]!=b[i]) ans=0;
		}
		if(ans){
			printf("yes\n");
			printf("%lld %lld\n",l+1,r+1);
		}else{
			printf("no\n");
		}
	}
	return 0;
}
