#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
#endif
}

const int N = 20 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

int cnt_in[N], cnt_out[N];
vector<int> adj[N];

int vis[N];
bool edges[N][N];

ll dfs(int src, int a = -1, int b = -1, int c = -1) {
	int d = 0;
	if (a != -1) ++d;
	if (a != -1 && b != -1 && edges[a][b] && edges[a][src] && edges[b][src]) ++d;
	if (a != -1 && b != -1 && c != -1 && edges[a][b] && edges[a][c] && edges[b][c] && edges[a][src] && edges[b][src]
			&& edges[c][src]) ++d;
	ll ret = 3 - d;
	vis[src] = 1;
	for (int i = 0; i < int(adj[src].size()); ++i) {
		if (vis[adj[src][i]] == 0) {
			if (a == -1 || !edges[a][adj[src][i]]) {
				ret *= dfs(adj[src][i], src);
			} else if (b == -1 || !edges[a][adj[src][i]]) {
				ret *= dfs(adj[src][i], a, src);
			} else {
				ret *= dfs(adj[src][i], a, b, src);
			}
		}
	}
	return ret;
}

void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		--a, --b;
		cnt_out[a]++;
		cnt_in[b]++;
		adj[a].push_back(b);
		adj[b].push_back(a);
		edges[a][b] = edges[b][a] = 1;
	}
	ll ans = 1;
	for (int i = 0; i < n; ++i)
		if (!vis[i]) ans *= dfs(i);

	(ans > 0) ? printf("%lld\n", ans) : puts("0");
}

int main() {
	_init_();
//	int t;
//	int cs = 1;
//	scanf("%d", &t);
//	while (t--) {
//		printf("Case #%d: ", cs++);
	solve();
//	}
	return 0;
}

