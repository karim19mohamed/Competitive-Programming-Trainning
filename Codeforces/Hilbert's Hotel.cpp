#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;


int main() {
	int t,n,a[1000009];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int shft=ceil(1000000009/n)*n;
		int k=0;
		for (int i=0;i<n;++i){
			scanf("%d",&a[i]);
			a[i]=(a[i]+shft+k)%n;
			++k;
		}
		bool ans=1;
		map<int,bool> vis;
		for (int i=0;i<n;++i){
			if (!vis[a[i]]) vis[a[i]]=1;
			else{
				ans=0;
				break;
			}
		}
		(ans)? puts("YES"):puts("NO");
	}
	return 0;
}










