#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;


int main() {
	int t,n;
	ll sz[1000009];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int ans=1;
		for (int i=1;i<=n;++i) scanf("%lld",&sz[i]);
		vector <int> v (n+1,1);
		for (int i=n;i>=1;--i){
			int tmp=1;
			for (int j=2;i*j<n+1;++j){
				if (sz[i*j]>sz[i]) tmp=max(tmp,v[i]+v[i*j]);
			}
			v[i]=tmp;
		}
		for (int i=1;i<=n;++i){
			//dbg2(i,v[i]);
			ans=max(ans,v[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}










