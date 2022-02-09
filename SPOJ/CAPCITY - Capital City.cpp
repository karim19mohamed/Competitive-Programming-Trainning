#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define dbg2(x,y) cerr<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cerr<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cerr<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define FOR(sz) for(int i = 0; i < sz; ++i)
#define dbg_array(x,sz) FOR(sz) cerr << x[i] << " \n"[i==sz-1]
using namespace std;

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

const int N = 1e5 + 9, M = 2e5 - 9;
const int Mod_M = 1e9 + 7;

vector<int> adj[N];
int vis[N], vid, stk[N], stksz;
int component_cnt, comp_id[N], tim, lowlink[N], dfst[N];
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
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		adj[a - 1].push_back(b - 1);
	}
	tarjan(n);
	int id = 0;
	for (int i = 0; i < component_cnt; ++i) {
		if (notsnk[i] != vid) {
			id = i;
		}
	}
	cout << count(comp_id, comp_id + n, id) << endl;
	bool flag = 0;
	for (int i = 0; i < n; ++i) {
		if (comp_id[i] == id) {
			if (flag) cout << " ";
			cout << i + 1;
			flag = 1;
		}
	}
	cout << endl;
}

int main() {
	_init_();
	solve();
	return 0;
}

