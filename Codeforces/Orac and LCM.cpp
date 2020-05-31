#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

ll GCD (ll a,ll b){ // a>b
	if (b==0) return a;
	return GCD (b,a%b);
}

ll LCM (ll a,ll b){
	return (a>b)? a*b/GCD(a,b) : a*b/GCD(b,a);
}

int main() {
	int n;
	ll a[1000009];
	scanf("%d",&n);
	vector <ll> pre(n,0),suf(n,0);
	for (int i=0;i<n;++i) scanf("%lld",&a[i]);
	pre[0]=a[0],suf[n-1]=a[n-1];
	for (int i=1;i<n;++i) pre[i]=GCD( max(pre[i-1],a[i]),min(pre[i-1],a[i]) );
	for (int i=n-2;i>0;--i) suf[i]=GCD( max(suf[i+1],a[i]),min(suf[i+1],a[i]) );
	ll ans=1;
	for (int i=0;i<n;++i){
		if (i-1<0) ans=LCM(ans,suf[i+1]);
		else if (i+1>=n) ans=LCM(ans,pre[i-1]);
		else ans=LCM(ans,GCD(pre[i-1],suf[i+1]));
	}
	printf("%lld\n",ans);
	return 0;
}










