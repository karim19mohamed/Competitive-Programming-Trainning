#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 10009, M = 190;

int vid, vis[N];

void dfs(int src, vector<int> (&adj)[N]) {
	vis[src] = vid;
	for (int i = 0; i < adj[src].size(); ++i) {
		if (vis[adj[src][i]] != vid) dfs(adj[src][i], adj);
	}
}

int main() {
	int n, m, q, x, y;
	vector<int> adj[N];
	string r;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		cin >> x >> r >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			++vid;
			dfs(i, adj);
		}
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d", &x, &y);
		(vis[x - 1] == vis[y - 1]) ? puts("YES") : puts("NO");
	}
	return 0;
}

