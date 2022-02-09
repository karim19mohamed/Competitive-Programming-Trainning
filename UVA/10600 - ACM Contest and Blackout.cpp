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

const int N = 100 + 9, M = 3e6 - 9;
const int Mod_M = 1e9 + 7;

struct DSU {
	int nsets, pat[N], sz[N];
	DSU(int n) {
		nsets = n;
		fill(sz, sz + n, 1);
		iota(pat, pat + n, 0);
	}
	int find(int u) {
		return (pat[u] == u) ? u : pat[u] = find(pat[u]);
	}
	bool join(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return 0;
		if (sz[v] < sz[u]) swap(u, v);
		pat[u] = v;
		sz[v] += sz[u];
		return 1;
	}
	int size(int u) {
		u = find(u);
		return sz[u];
	}
};

int from[M], to[M], cst[M], sorted[M], n, m;
vector<int> selected_edges;
int kruskal(bool flag) {
	DSU dsu(n);
	sort(sorted, sorted + m, [](int a,int b) {
		return cst[a]<cst[b];
	});
	int ret = 0;
	for (int i = 0; i < m; ++i) {
		int idx = sorted[i];
		bool x = dsu.join(from[idx], to[idx]);
		if (x) {
			ret += cst[idx];
			if (flag) selected_edges.push_back(idx);
		}

	}
	return ret;
}
int second_sol() {
	int res = 1e9;
	//dbg(selected_edges.size());
	for (int i = 0; i < (int) selected_edges.size(); ++i) {
		int idx = selected_edges[i];
		int tmp = cst[idx];
		cst[idx] = 1e5;
		int num = kruskal(0);
		//dbg2(i, num);
		res = min(res, num);
		cst[idx] = tmp;
	}
	return res;
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		from[i] = --u;
		to[i] = --v;
		cst[i] = c;
		sorted[i] = i;
	}

	int s1 = kruskal(1);

	int s2 = second_sol();
	printf("%d %d\n", s1, s2);
	selected_edges.clear();
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
