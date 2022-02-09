#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N=50000+9;

int vid,vis[N],reached[N];

int dfs(int src,vector<int> (&adj)[N]){
	vis[src]=vid;
	int n=1;
	for (int i=0;i<adj[src].size();++i){
		if (vis[adj[src][i]]!=vid){
			n+=dfs(adj[src][i],adj);
		}
	}
	reached[src]=n;
	return n;
}


int main() {
	int t,n,a,b,cs=1;
	scanf("%d",&t);
	while (t--){
		vector<int> adj[N];
		scanf("%d",&n);
		for (int i=0;i<n;++i){
			scanf("%d %d",&a,&b);
			adj[a].push_back(b);
		}
		++vid;
		for (int i=1;i<=n;++i){
			if (reached[i]) continue;
			dfs(i,adj);
			++vid;
		}
		int ans,connections=0;
		for (int i=1;i<=n;++i){
			if(reached[i]>connections){
				connections=reached[i];
				ans=i;
			}
			reached[i]=0;
		}
		printf("Case %d: %d\n",cs++,ans);
	}
    return 0;
}
















