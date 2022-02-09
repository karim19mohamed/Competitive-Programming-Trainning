#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 1000000 + 9;
int vid, vis[N], required[N], filled_required[N];
queue<int> arrange;

vector<int> bfs(vector<int> (&a)[N], const int &n) {
	vector<int> ans;
	fill(filled_required, filled_required + n + 1, 0);
	priority_queue<int> q;
	while (!arrange.empty()) {
		int src = arrange.front();
		q.push(-src);
		vis[src] = vid;
		arrange.pop();
	}
	while (!q.empty()) {
		int qsz = q.size();
		while (qsz--) {
			int u = -q.top();
			q.pop();
			if (filled_required[u] != required[u]) {
				vis[u] = vid - 1;
				continue;
			} else {
				ans.push_back(u);
			}
			for (auto v : a[u]) {
				++filled_required[v];
				if (vis[v] != vid) {
					q.push(-v);
					vis[v] = vid;
				}
			}
		}
	}
	return ans;
}

int main() {
	int n, m, a, b;
	while (scanf("%d %d", &n, &m) && n + m) {
		fill(required, required + n + 1, 0);
		vector<int> adj[N];
		vector<bool> to_begin_from(n, 1);

		for (int i = 0; i < m; ++i) {
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
			to_begin_from[b] = 0;
			required[b]++;
		}
		for (int i = 1; i <= n; ++i) {
			if (to_begin_from[i])
				arrange.push(i);
		}
		++vid;
		vector<int> ans = bfs(adj, n);
		if ((int) ans.size() != n) {
			puts("IMPOSSIBLE");
		} else {
			for (auto u : ans)
				printf("%d\n", u);
		}

	}
	return 0;
}

