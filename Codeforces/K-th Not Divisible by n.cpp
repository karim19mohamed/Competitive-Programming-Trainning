// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int t;
	ll n,k;
	scanf("%d",&t);
	while(t--){
		scanf("%lld %lld",&n,&k);
		ll l,div,rem,pos;
		l=n-1;
		div=k/l;
		rem=k%l;
		pos=div*n;
		if (rem==0){
			printf("%lld\n",pos-1);
		}else if(rem==1){
			printf("%lld\n",pos+1);
		}else{
			printf("%lld\n",pos+rem);
		}

	}
	return 0;
}










