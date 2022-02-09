#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N=10009,M=190;

int vid,vis[N];

int bfs(const int &src,const int &dest,vector<int> (&a)[N]){
	queue<int> q;
	q.push(src);
	vis[src]=++vid;
	int lvl=0;
	while (!q.empty()){
		int qsz=q.size();
		while (qsz--){
			int u=q.front();
			q.pop();
			if (u==dest) return lvl;
			for (auto v : a[u]){
				if (vis[v]!=vid){
					q.push(v);
					vis[v]=vid;
				}
			}
		}
		++lvl;
	}
	return -1;
}

int main() {
	int n,m,q,x,y;
	vector<int> adj[N];
	string r;
	scanf("%d %d",&n,&m);
	for (int i=0;i<m;++i){
		cin >> x >> r >> y;
		adj[x-1].push_back(y-1);
		adj[y-1].push_back(x-1);
	}

	scanf("%d",&q);
	while (q--){
		scanf("%d %d",&x,&y);
		int ans=bfs(x-1,y-1,adj);
		(ans==1)? puts("YES") : puts("NO");
	}
    return 0;
}

















