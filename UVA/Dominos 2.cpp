#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 10000 + 9;

int vid, vis[N];

void dfs(int src, vector<int> (&adj)[N]) {

	vis[src] = vid;
	for (int i = 0; i < adj[src].size(); ++i) {
		if (vis[adj[src][i]] != vid)
			dfs(adj[src][i], adj);
	}
}

int main() {
	int t, n, m, l, x, y;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &l);
		vector<int> adj[N];
		for (int i = 0; i < m; ++i) {
			scanf("%d %d", &x, &y);
			adj[x - 1].push_back(y - 1);
		}
		++vid;
		for (int i = 0; i < l; ++i) {
			scanf("%d", &x);
			if (vis[x - 1] != vid)
				dfs(x - 1, adj);
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (vis[i] == vid)
				++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}
