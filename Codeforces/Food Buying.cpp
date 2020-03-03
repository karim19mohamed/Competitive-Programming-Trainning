#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int t;
ll n;

int main() {
	scanf("%d",&t);
	while (t--){
		scanf("%lld",&n);
		ll ans=0,num,x=10000000000,tmp;
		while(n!=0){
			if (n/x==0){
				x/=10;
				continue;
			}
			//cout << ans << " " << n << endl;
			num=n/x;
			tmp=n+num*floor(x/10);
			num=tmp/x;
			n=n+num*floor(x/10);
			ans+=num*x;
			n-=num*x;
			if (x!=1 && n==0) ++ans;
			x/=10;
		}
		printf("%lld\n",ans);
	}

	return 0;
}
