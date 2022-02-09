#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 100 + 9;

int vid, vis[N], val[N], last_node;

int dfs(int src, vector<int> (&adj)[N]) {
	vis[src] = vid;
	int sum = val[src], nxt = -1, nxt_val = 0;
	for (int i = 0; i < adj[src].size(); ++i) {
		if (vis[adj[src][i]] != vid && val[adj[src][i]] > nxt_val)
			nxt = adj[src][i], nxt_val = val[adj[src][i]];
	}
	if (nxt != -1)
		sum += dfs(nxt, adj);
	else
		last_node = src;
	return sum;
}

int main() {
	int t, n, m, x, y, sum, cs = 1;
	scanf("%d", &t);
	while (t--) {
		vector<int> adj[N];
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
			scanf("%d", &x), val[i] = x;
		for (int i = 0; i < m; ++i)
			scanf("%d %d", &x, &y), adj[x].push_back(y);
		++vid;
		int sum = dfs(0, adj);
		printf("Case %d: %d %d\n", cs++, sum, last_node);
	}
	return 0;
}
