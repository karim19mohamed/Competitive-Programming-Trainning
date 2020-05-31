#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

ll n,k,a[100009],b[100009];
bool valid(ll q){
	ll magic=k;
	for (ll i=0;i<n;++i){
		if (b[i]-q*a[i]<0) magic-=(q*a[i]-b[i]);
		if (magic<0) return false;
	}
	//dbg2(q,magic);
	return (magic>=0);
}

int main() {
	scanf("%lld %lld",&n,&k);
	for (ll i=0;i<n;++i) scanf("%lld",&a[i]);
	for (ll i=0;i<n;++i) scanf("%lld",&b[i]);

	ll st=0,et=10000000000;
	while(st<et){
		ll mid=st+(et-st+1)/2;
		(valid(mid))? st=mid : et=mid-1;
	}
	cout<< st << endl;
	return 0;
}




















