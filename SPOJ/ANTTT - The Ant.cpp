#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<double> point;
#define endl '\n'
#define f first
#define s second
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

const int N = 1000 + 9, M = 2e5 - 9;
const int Mod_M = 1e9 + 7;

vector<int> adj[N];
int vis[N], vid, stk[N], stksz;
int component_cnt, comp_id[N], tim, lowlink[N], dfst[N];
int notsrc[N], notsnk[N];

void dfs_simple(int src) {
	vis[src] = vid;
	for (auto v : adj[src]) {
		if (vis[v] != vid) dfs_simple(v);
	}
}

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
bool Onsegment(point st, point en, point p) {
	return min(st.X, en.X) <= p.X && p.X <= max(st.X, en.X) && min(st.Y, en.Y) <= p.Y && p.Y <= max(st.Y, en.Y);
}
int orientation(point st, point en, point p) {
	int val = (en.Y - st.Y) * (p.X - en.X) - (p.Y - en.Y) * (en.X - st.X);
	if (val == 0) return 0; //colinear
	return (val > 0) ? 1 : 2; // 1->clockwise & 2->counterclockwise
}
bool twosegment_intersect(point st1, point en1, point st2, point en2) {
	// (st1, en1, st2) and (st1, en1, st2) have different orientations and
	// (st2, en2, st1) and (st2, en2, en1) have different orientations
	int o1 = orientation(st1, en1, st2);
	int o2 = orientation(st1, en1, en2);
	int o3 = orientation(st2, en2, st1);
	int o4 = orientation(st2, en2, en1);
	if (o1 != o2 && o3 != o4) return true;
	if (o1 == 0 && Onsegment(st1, en1, st2)) return true;
	if (o2 == 0 && Onsegment(st1, en1, st2)) return true;
	if (o3 == 0 && Onsegment(st2, en2, st1)) return true;
	if (o4 == 0 && Onsegment(st2, en2, en1)) return true;
	return false;
}
point twoline_intersect(point st1, point en1, point st2, point en2) {
	double a1, a2, b1, b2, c1, c2, det;
	a1 = st1.Y - en1.Y;
	b1 = -(st1.X - en1.X);
	c1 = st1.X * a1 + st1.Y * b1;
	a2 = st2.Y - en2.Y;
	b2 = -(st2.X - en2.X);
	c2 = st2.X * a2 + st2.Y * b2;
	det = a1 * b2 - a2 * b1;
	if (det == 0) return 0;
	point intersect((c1 * b2 - c2 * b1) / det, (c1 * a2 - c2 * a1) / -det);
	return intersect;
}

void solve() {
	memset(vis, 0, sizeof vis);
	int n, m, a, b, c, d;
	cin >> n >> m;
	point st[n], en[n];
	for (int i = 0; i < n; ++i) {
		cin >> a >> b >> c >> d;
		point tmp1(a, b), tmp2(c, d);
		st[i] = tmp1;
		en[i] = tmp2;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (twosegment_intersect(st[i], en[i], st[j], en[j])) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	for (int i = 0; i < n; ++i)
		if (!vis[i]) {
			++vid;
			dfs_simple(i);
		}
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		cout << ((vis[a - 1] == vis[b - 1]) ? "YES" : "NO") << endl;
	}
	for (int i = 0; i < n; ++i)
		adj[i].clear();
}
int main() {
	_init_();
	int t;
	read(t);
	while (t--) {
		solve();
	}
	return 0;
}

