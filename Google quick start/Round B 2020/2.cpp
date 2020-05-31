#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;



int main() {
	int t,n,cs=1;
	ll d,x[1009];
	scanf("%d",&t);
	while(t--){
		scanf("%d %lld",&n,&d);
		ll ans=d;
		for (int i=0;i<n;++i) scanf("%lld",&x[i]);
		for (int i=n-1;i>=0;--i) if (ans%x[i]!=0) ans=(ans/x[i])*x[i];
		printf("Case #%d: %lld\n",cs++,ans);
	}
	return 0;
}















