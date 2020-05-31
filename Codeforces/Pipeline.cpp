#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

bool valid (ll mid,ll k,ll n){
	ll sum=(k+2)+(k*(k+1)/2)-(mid*(mid+1)/2);
	//dbg4(k,mid_idx,mid,sum);
	return sum>=n;
}
int main() {
	ll n,k,ans;
	cin>>n>>k;
	if (n==1){
		puts("0");
		return 0;
	}else if (k>=n){
		puts("1");
		return 0;
	}

	ll s=0,e=k-2;
	while(s<e){
		ll mid=s+(e-s+1)/2;
		(valid(mid-1,k-2,n))? s=mid : e=mid-1;
	}
	(valid(s-1,k-2,n))? cout<<k-s<<endl:cout<<-1<<endl;
	return 0;
}





















