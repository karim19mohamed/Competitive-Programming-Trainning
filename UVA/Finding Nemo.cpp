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

const int N = 199 + 9, M = 1e9 - 9;
const int Mod_M = 1e9 + 7;

#define node pair<int,pair<int,pair<int,int>>>

int n, m;
map<node, int> grid;

int dis[N][N];

void dijkstra() {
	memset(dis, '?', sizeof dis);
	//fill(dis, dis + n + 1, 1e9);
	priority_queue<pair<int, pair<int, int>>> q;
	q.push( { 0, { 0, 0 } });
	dis[0][0] = 0;
	while (!q.empty()) {
		pair<int, pair<int, int>> u = q.top();
		int x = u.S.F, y = u.S.S;
		int c = -u.F;
		q.pop();
		if (dis[x][y] != c) continue;
		for (int i = 0; i < 4; ++i) {
			int newx = x + d4i[i], newy = y + d4j[i];
			if (newx < 0 || newy < 0 || newx > 200 || newy > 200) continue;
			int val = grid[ { x, { y, { newx, newy } } }];
			if (val == 1) continue;
			val = (val == 2) ? 1 : 0;
			if (dis[newx][newy] > c + val) {
				q.push( { -(c + val), { newx, newy } });
				dis[newx][newy] = c + val;
			}
		}
	}
}

void solve() {
	while (scanf("%d%d", &m, &n) == 2 && n != -1) {
		for (int i = 0; i < m; ++i) {
			int x, y, t, d;
			scanf("%d%d%d%d", &x, &y, &d, &t);
			if (d) {
				for (int move = 0; move < t; ++move) {
					grid[ { x, { y + move, { x - 1, y + move } } }] = 1;
					grid[ { x - 1, { y + move, { x, y + move } } }] = 1;
				}
			} else {
				for (int move = 0; move < t; ++move) {
					grid[ { x + move, { y, { x + move, y - 1 } } }] = 1;
					grid[ { x + move, { y - 1, { x + move, y } } }] = 1;
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			int x, y, d;
			scanf("%d%d%d", &x, &y, &d);
			if (d) {
				grid[ { x, { y, { x - 1, y } } }] = 2;
				grid[ { x - 1, { y, { x, y } } }] = 2;
			} else {
				grid[ { x, { y, { x, y - 1 } } }] = 2;
				grid[ { x, { y - 1, { x, y } } }] = 2;
			}
		}
		float f1, f2;
		scanf("%f%f", &f1, &f2);
		int d1 = f1, d2 = f2;
		dijkstra();
		if (d1 < 200 && d2 < 200) {
			int ans = (dis[d1][d2] > 1e7) ? -1 : dis[d1][d2];
			printf("%d\n", ans);
		} else {
			puts("0");
		}
		grid.clear();
		//vis.clear();
	}
}
int main() {
	_init_();

	solve();

	return 0;
}
