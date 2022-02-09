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

const int N = 1e5 + 9, M = 1e6 - 9;
const int Mod_M = 1e9 + 7;

vector<pair<int, ll> > adj[N];
int n, m, k, vis[N], vid;
ll dis[N];

ll prim(int src = 0) {
	ll cost = 0;
	++vid;
	memset(dis, '?', n * sizeof dis[0]);
	priority_queue<pair<int, ll>, vector<pair<int, ll>>, greater<>> q;
	dis[src] = 0;
	q.push( { 0, src });
	while (!q.empty()) {
		int u = q.top().S;
		int c = q.top().F;
		q.pop();
		if (dis[u] != c) continue;
		vis[u] = vid;
		cost += c;
		for (auto v : adj[u]) {
			if (v.S < dis[v.F] && vis[v.F] != vid) {
				dis[v.F] = v.S;
				q.push( { v.S, v.F });
			}
		}
	}
	return cost;
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		--u, --v;
		adj[u].emplace_back(v, c);
		adj[v].emplace_back(u, c);
	}
	ll ans = prim();
	printf("%lld\n", ans);
}
int main() {
	_init_();

	solve();

	return 0;
}
