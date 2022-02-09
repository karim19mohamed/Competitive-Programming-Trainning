#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N=2000+9;

int vid,vis[N];

void dfs(int src,vector<int> (&adj)[N]){

	vis[src]=vid;
	for (int i=0;i<adj[src].size();++i){
		if (vis[adj[src][i]]!=vid) dfs(adj[src][i],adj);
	}
}

int main() {
	int n,m,x,y,p;
	while (scanf("%d %d",&n,&m) && n+m){
		vector<int> adj[N],rev_adj[N];
		for (int i=0;i<m;++i){
			scanf("%d %d %d",&x,&y,&p);
			adj[x-1].push_back(y-1);
			rev_adj[y-1].push_back(x-1);
			if(p==2) adj[y-1].push_back(x-1) , rev_adj[x-1].push_back(y-1);
		}
		++vid;
		dfs(0, adj);
		int ans=1,ans_rev=1;
		for (int i=0;i<n;++i)
			if (vis[i]!=vid){
				ans=0;
				break;
			}
		++vid;
		dfs(0, rev_adj);
		for (int i=0;i<n;++i)
			if (vis[i]!=vid){
				ans_rev=0;
				break;
			}
		printf("%d\n",ans&ans_rev);

	}
    return 0;
}
















