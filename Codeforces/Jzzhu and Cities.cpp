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
int n, m, k;
ll dis[N];

struct edge {
	int u, v;
	ll c;
};

void dijkstra(const int &src) {
	memset(dis, '?', n * sizeof dis[0]);
	fill(dis, dis + n + 1, 1e9);
	priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<> > q;
	q.push( { 0, src });
	dis[src] = 0;
	while (!q.empty()) {
		int u = q.top().S;
		ll c = q.top().F;
		q.pop();
		if (dis[u] != c) continue;
		for (auto v : adj[u]) {
			if (dis[v.F] > v.S + c) {
				q.push( { v.S + c, v.F });
				dis[v.F] = v.S + c;
			}
		}
	}
}
edge reach[M], train[M];
int cntreach, cnttrain;
bool mainedge[N];
int relax() {
	int ret = 0;
	for (int i = 0; i < cntreach; ++i) {
		int src = reach[i].u, dest = reach[i].v;
		ll c = reach[i].c;
		if (dis[dest] - dis[src] == c) mainedge[dest] = 1;
	}
	for (int i = 0; i < cnttrain; ++i) {
		int src = train[i].u, dest = train[i].v;
		ll c = train[i].c;
		if (dis[dest] - dis[src] != c || mainedge[dest]) ++ret;
		else mainedge[dest] = 1;
	}
	return ret;
}

void solve() {
	scanf("%d%d%d", &n, &m, &k);
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		--a, --b;
		adj[a].push_back( { b, c });
		adj[b].push_back( { a, c });
		reach[cntreach++]= {a,b,c};
		reach[cntreach++]= {b,a,c};
	}
	for (int i = 0; i < k; ++i) {
		scanf("%d%d", &b, &c);
		--b;
		adj[0].push_back( { b, c });
		train[cnttrain++]= {0,b,c};
	}
	int ans = 0;
	dijkstra(0);
	ans = relax();
	printf("%d\n", ans);
}
int main() {
	_init_();

	solve();

	return 0;
}
