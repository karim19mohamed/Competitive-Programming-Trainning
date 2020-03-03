#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

ll FactN_PrimePower(ll n,ll p){
	ll pow=0;
	for(ll i=p;i<=n;i*=p) pow+=n/i;
	return pow;
}

ll n;
int main() {
	while (cin>>n){
		ll tens=10;
		ll ans=1;
		for (ll i=2;i<=n;++i){
			ans*=i;
			if (ans>10){
				ll tmp=ans/tens;
				while (ans == tmp*tens){
					//dbg3(i,ans,tmp);
					ans/=tens;
					tmp=ans/tens;
				}
			}
			if (ans%100000!=0) ans%=100000;
		}
		ans=ans%10;
		if (n/10000) printf("%lld -> %lld\n",n,ans);
		else if (n/1000) printf(" %lld -> %lld\n",n,ans);
		else if (n/100) printf("  %lld -> %lld\n",n,ans);
		else if (n/10) printf("   %lld -> %lld\n",n,ans);
		else printf("    %lld -> %lld\n",n,ans);
		//dbg3(ans,pow,tens);
	}
	return 0;
}









