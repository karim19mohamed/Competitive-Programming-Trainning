#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<double> point;
#define endl '\n'
#define F first
#define S second
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define dbg2(x,y) cerr<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cerr<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cerr<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define FOR(sz) for(int i = 0; i < sz; ++i)
#define dbg_array(x,sz) FOR(sz) cerr << x[i] << " \n"[i==sz-1]
#define X real()
#define Y imag()

const int d4i[4] = { -1, 0, 1, 0 }, d4j[4] = { 0, 1, 0, -1 };
const int d8i[8] = { -1, -1, 0, 1, 1, 1, 0, -1 }, d8j[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void _init_() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//	freopen("output.out", "wt", stdout);
#endif
}

const int N = 5e4 + 200 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

int vid, vis[N];
vector<int> adj[N];

int bfs(const int &src, const int &dest) {
	queue<pair<int, int>> q;
	q.push( { src, 1 });
	vis[src] = ++vid;
	while (!q.empty()) {
		int qsz = q.size();
		while (qsz--) {
			int u = q.front().F;
			int lvl = q.front().S;
			q.pop();
			if (u == dest) return 1 + lvl;
			for (auto v : adj[u]) {
				if (vis[v] != vid) {
					q.push( { v, (v > 'Z') ? lvl : lvl + 1 });
					vis[v] = vid;
				}
			}
		}
	}
	return -1;
}

void solve() {
	char s[N][29];
	int dis[200][200];
	int n, q, id = 200;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s[i]);
		for (int j = 0; s[i][j]; ++j) {
			adj[s[i][j]].push_back(id);
			adj[id].push_back(s[i][j]);
		}
		++id;
	}
	for (int i = 'A'; i <= 'Z'; ++i) {
		dis[i][i] = 2;
		for (int j = i + 1; j <= 'Z'; ++j) {
			int ret = bfs(i, j);
			dis[i][j] = dis[j][i] = ret;
		}
	}
	while (q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		int ans = INT_MAX;
		for (int i = 0; s[a][i]; ++i) {
			for (int j = 0; s[b][j]; ++j) {
				if (dis[s[a][i]][s[b][j]] != -1) {
//					dbg3(s[a][i], s[b][i], dis[s[a][i]][s[b][j]]);
					ans = min(ans, dis[s[a][i]][s[b][j]]);
				}
			}
		}
		if (ans == INT_MAX) ans = -1;
		printf("%d%c", ans, " \n"[q == 0]);
	}
	for (int i = 'A'; i <= id; ++i)
		adj[i].clear();
}
int main() {
	_init_();
	int t, cs = 1;
	scanf("%d", &t);
	while (t--) {
		printf("Case #%d: ", cs++);
		solve();
	}
	return 0;
}
