#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int t,n;
ll a[100009],a1,neg_a2;

int main() {
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		for (int i=0;i<n;++i) scanf("%lld",&a[i]);
		bool ans=1;
		for (int i=0;i<n;++i){
			a1+=a[i];
			if (a1<=0){
				ans=0;
				break;
			}
		}
		a1=0;
		for (int i=n-1;i>=0;--i){
			a1+=a[i];
			if (a1<=0){
				ans=0;
				break;
			}
		}
		(ans)? puts("YES") : puts("NO");
		a1=0;
	}

	return 0;
}
