#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

ll comp(ll n,ll m,ll n_m){
	ll ans=1,tmp;
	if (n_m>2) tmp=2;
	for (ll i=m+1;i<=n;++i){
		if (i>n_m){
			ans*=i;
			if (tmp<=n_m && ans%tmp==0) ans/=tmp,++tmp;
		}
	}
	return ans;
}
ll n,m;
int main() {
	while (cin>>n>>m && n!=0){
		ll ans= (n-m>m)? comp(n,n-m,m) : comp(n,m,n-m);
		printf("%lld things taken %lld at a time is %lld exactly.\n",n,m,ans);
	}
	return 0;
}























