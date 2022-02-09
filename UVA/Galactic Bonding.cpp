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

const int N = 1000 + 9, M = 1e9 - 9;
const int Mod_M = 1e9 + 7;

vector<int> adj[N];
int vid, vis[N];

void dfs(int src) {
	vis[src] = vid;
	for (int i = 0; i < adj[src].size(); ++i) {
		if (vis[adj[src][i]] != vid) dfs(adj[src][i]);
	}
}

void solve() {
	int n;
	float d, x[N], y[N];
	scanf("%d%f", &n, &d);
	for (int i = 0; i < n; ++i)
		scanf("%f%f", &x[i], &y[i]);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			float dis = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
			dis = sqrtf(dis);
			if (dis - d < 1e-3) {
				adj[i].push_back(j), adj[j].push_back(i);
				//dbg3(i, j, dis);
			}
		}
	}
	++vid;
	int ans = 0;
	for (int i = 0; i < n; ++i)
		if (vis[i] != vid) {
			dfs(i);
			++ans;
		}
	printf("%d\n", ans);
	for (int i = 0; i < n; ++i)
		adj[i].clear();
}
int main() {
	_init_();
	int t, cs = 1;
	scanf("%d", &t);
	while (t--) {
		printf("Case %d: ", cs++);
		solve();
	}
	return 0;
}
