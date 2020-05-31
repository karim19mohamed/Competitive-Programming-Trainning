#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	ll n,q,a,sum[100009],q1,q2,ans;
	scanf("%lld",&n);
	for (int i=0;i<n;++i){
		scanf("%lld",&a);
		sum[i]= (i!=0)? sum[i-1]+a : a;
	}
	scanf("%lld",&q);
	for (int i=0;i<n;++i){
		scanf("%lld %lld",&q1,&q2);
		ans= (q1!=0)? sum[q2]-sum[q1-1] : sum[q2];
		printf("%lld\n",ans);
	}
	return 0;
}


















