#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 1e4 + 9, M = 1e4 + 9;
int vid, vis[N];
vector<int> adj[N];

int bfs(const int &src, const int &dest) {
	queue<int> q;
	q.push(src);
	vis[src] = ++vid;
	int lvl = 0;
	while (!q.empty()) {
		int qsz = q.size();
		while (qsz--) {
			int u = q.front();
			q.pop();
			if (u == dest) return lvl;
			for (auto v : adj[u]) {
				if (vis[v] != vid) {
					q.push(v);
					vis[v] = vid;
				}
			}
		}
		++lvl;
	}
	return -1;
}

int main() {
	int t, n, m, x, y;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; ++i) {
			scanf("%d %d", &x, &y);
			adj[x].push_back(y), adj[y].push_back(x);
		}
		int ans = bfs(1, n);
		printf("%d\n", ans);
	}
	return 0;
}

