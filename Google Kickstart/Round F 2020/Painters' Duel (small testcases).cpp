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

const int N = 20 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e8;
vector<pair<int, int>> adj[N][N];

void construct() {
	int odd = 1;
	for (int i = 1; i <= 6; ++i) {
		for (int j = 2; j <= odd; ++j) {
			adj[i][j].push_back( { i, j - 1 });
			adj[i][j - 1].push_back( { i, j });
		}
		odd += 2;
	}
	odd = 1;
	for (int i = 1; i <= 6; ++i) {
		for (int j = 1; j <= odd; j += 2) {
			adj[i][j].push_back( { i + 1, j + 1 });
			adj[i + 1][j + 1].push_back( { i, j });
		}
		odd += 2;
	}
}

int s;
int vis[N][N], vid;
int tme[N][N];
int block[N][N], bid;

void dfsa(int x, int y, int t = 0) {
	vis[x][y] = vid;
	tme[x][y] = min(tme[x][y], t);
	for (auto v : adj[x][y]) {
		int nx = v.F, ny = v.S;
		if (nx <= s && vis[nx][ny] != vid && block[nx][ny] != bid) {
			dfsa(nx, ny, t + 1);
		}
	}
}
void dfsb(int x, int y, int t = 0) {
	vis[x][y] = vid;
	if (t < tme[x][y]) {
		tme[x][y] = -t;
	}
	for (auto v : adj[x][y]) {
		int nx = v.F, ny = v.S;
		if (nx <= s && vis[nx][ny] != vid && block[nx][ny] != bid) {
			dfsb(nx, ny, t + 1);
		}
	}
}

void solve() {
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j < N; ++j) {
			tme[i][j] = 1e9;
		}
	}
	int ax, ay, bx, by, c;
	scanf("%d%d%d%d%d%d", &s, &ax, &ay, &bx, &by, &c);
	int x, y;
	++bid;
	for (int i = 0; i < c; ++i) {
		scanf("%d%d", &x, &y);
		block[x][y] = bid;
	}
	++vid;
	dfsa(ax, ay);
	++vid;
	dfsb(bx, by);
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i < N; ++i)
		for (int j = 1; j < N; ++j) {
			if (tme[i][j] != 1e9 && tme[i][j] > -1) {
				ans1 = max(ans1, tme[i][j]);
				//dbg2(i, j);
			} else if (tme[i][j] < 0) {
				ans2 = max(ans2, -tme[i][j]);
			}
		}
	printf(" %d", ans1 - ans2);
}
int main() {
	_init_();
	construct();
	int t, cs = 1;
	scanf("%d", &t);
	while (t--) {
		printf("Case #%d:", cs++);
		solve();
		puts("");
	}
	return 0;
}
