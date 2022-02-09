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

template<typename T_n> void read(T_n &n) {
	cin >> n;
}
template<typename T_n, typename T_a> void read(T_a a[], T_n n) {
	for (int i = 0; i < n; ++i)
		cin >> a[i];
}
template<typename T_n, typename T_a> void read(vector<T_a> &a, T_n n) {
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
}
void _init_() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);
#endif
}

const int N = 3e5 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e8;

vector<int> adj[N];
int vis[N], vid, stk[N], stksz;
int component_cnt, comp_id[N], comp_sz[N], tim, lowlink[N], dfst[N];
int notsrc[N], notsnk[N];
void dfs(int u) {
	comp_id[u] = -1;
	dfst[u] = lowlink[u] = tim++;
	vis[u] = vid;
	stk[stksz++] = u;
	for (auto v : adj[u]) {
		if (vis[v] != vid) {
			dfs(v);
			lowlink[u] = min(lowlink[u], lowlink[v]);
		} else if (comp_id[v] == -1) {
			lowlink[u] = min(lowlink[u], lowlink[v]);
		}
	}
	if (dfst[u] == lowlink[u]) {
		do {
			comp_id[stk[--stksz]] = component_cnt;
			++comp_sz[component_cnt];
		} while (stk[stksz] != u);
		++component_cnt;
	}
}

void tarjan(int n) {
	++vid;
	tim = stksz = component_cnt = 0;
	for (int i = 0; i < n; ++i)
		if (vis[i] != vid) dfs(i);
	for (int u = 0; u < n; ++u) {
		for (auto v : adj[u]) {
			if (comp_id[u] == comp_id[v]) continue;
			notsrc[comp_id[v]] = vid;
			notsnk[comp_id[u]] = vid;
		}
	}
}

void solve() {
	int n;
	char s[N];
	scanf("%d%s", &n, s);
	for (int i = 0; i < n; ++i)
		adj[i].clear();
	for (int i = 0; s[i]; ++i) {
		if (s[i] == '-') {
			adj[i].push_back((i + 1) % n);
			adj[(i + 1) % n].push_back(i);
		} else if (s[i] == '>') {
			adj[i].push_back((i + 1) % n);
		} else {
			adj[(i + 1) % n].push_back(i);
		}
	}
	int ans = n;
	tarjan(n);
	for (int i = 0; i < component_cnt; ++i) {
		if (comp_sz[i] == 1) --ans;
		comp_sz[i] = 0;
	}

	printf("%d\n", ans);

}
int main() {
	_init_();
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
