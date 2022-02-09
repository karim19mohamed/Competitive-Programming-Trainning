#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 2000 + 9;

int vid, vis[N];

bool dfs(int src, vector<int> (&adj)[N]) {
	//bool ans=1;
	for (int i = 0; i < adj[src].size(); ++i) {
		if (vis[adj[src][i]] != vid && vis[adj[src][i]] != vid + 1) {
			vis[adj[src][i]] = (vis[src] == vid) ? vid + 1 : vid;
			dfs(adj[src][i], adj);
		} else if (vis[adj[src][i]] == vis[src]) {
			return false;
		}
	}
	return true;
}

int main() {
	int n, m, x, y;
	while (scanf("%d", &n) && n) {
		scanf("%d", &m);
		vector<int> adj[N], rev_adj[N];
		for (int i = 0; i < m; ++i) {
			scanf("%d %d", &x, &y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int ans = 1;
		++vid;
		vis[0] = vid;
		ans = dfs(0, adj);
		++vid;
		(ans) ? puts("BICOLORABLE.") : puts("NOT BICOLORABLE.");
	}
	return 0;
}

