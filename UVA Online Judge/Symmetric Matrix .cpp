#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int t,n,cse=1;
	char c;
	ll a[100][100];
	scanf("%d",&t);
	while (t--){
		for (int i=0;i<4;++i) scanf("%c",&c);
		scanf("%d",&n);
		bool ans=1;
		for (int i=0;i<n;++i) for (int j=0;j<n;++j){
			scanf("%lld",&a[i][j]);
			if (a[i][j]<0) ans=0;
		}
		for (int i=0;i<n;++i){
			for (int j=0;j<n;++j){
				if (a[i][j]!=a[n-1-i][n-1-j]){
					ans=0;
					break;
				}
			}
			if (!ans) break;
		}
		(ans)? printf("Test #%d: Symmetric.\n",cse++): printf("Test #%d: Non-symmetric.\n",cse++);
	}
	return 0;
}

















