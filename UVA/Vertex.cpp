#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N=100+9;

int vid,vis[N];

void dfs(int src,vector<int> (&adj)[N]){

	//vis[src]=vid;
	for (int i=0;i<adj[src].size();++i){
		if (vis[ adj[src][i] ]!=vid){
			vis[adj[src][i]]=vid;
			dfs(adj[src][i],adj);
		}
	}
}

int main() {
	int n,x,y,q;
	while (scanf("%d",&n) && n){
		vector<int> adj[N];
		while (scanf("%d",&x) && x){
			while (scanf("%d",&y) && y) adj[x-1].push_back(y-1);
		}
		scanf("%d",&q);
		while(q--){
			scanf("%d",&x);
			++vid;
			dfs(x-1,adj);
			int ans=0;
			for (int i=0;i<n;++i){
				if(vis[i]!=vid) ++ans;
			}
			printf("%d",ans);
			for (int i=0;i<n;++i) if(vis[i]!=vid) printf(" %d",i+1);
			puts("");
		}
	}
    return 0;
}

















