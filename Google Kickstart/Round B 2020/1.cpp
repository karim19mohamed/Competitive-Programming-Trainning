#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;



int main() {
	int n,t,h[109],cs=1;
	scanf("%d",&t);
	while(t--){
		int ans=0;
		scanf("%d",&n);
		for (int i=0;i<n;++i) scanf("%d",&h[i]);
		for (int i=1;i<n-1;++i) if (h[i]>h[i-1] && h[i]>h[i+1]) ++ans;
		printf("Case #%d: %d\n",cs++,ans);
	}
	return 0;
}















