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

const int N = 1000 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

void solve() {
	int r, c, a[N][N];
	scanf("%d%d", &r, &c);
	priority_queue<pair<int, pair<int, int>>> q;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j) {
			scanf("%d", &a[i][j]);
			pair<int, pair<int, int>> tmp = { a[i][j], { i, j } };
			q.push(tmp);
		}
	int ans = 0;
	while (!q.empty()) {
		int x = q.top().S.F, y = q.top().S.S;
		int h = a[x][y];
		if (q.top().F != h) {
			q.pop();
			continue;
		}
//		bool modify = 0;
		for (int i = 0; i < 4; ++i) {
			int new_x = x + d4i[i], new_y = y + d4j[i];
			if (new_x < 0 || new_x >= r) continue;
			if (new_y < 0 || new_y >= c) continue;
			int dif = h - a[new_x][new_y];
			if (dif > 1) {
//				dbg4(x, y, new_x, new_y);
//				modify = 1;
				ans += h - a[new_x][new_y] - 1;
				a[new_x][new_y] = h - 1;
				pair<int, pair<int, int>> tmp = { a[new_x][new_y], { new_x, new_y } };
				q.push(tmp);
			}
		}
		q.pop();
	}
	for (int i = 0; i < r; ++i) {
		puts("");
		for (int j = 0; j < c; ++j) {
			printf("%d ", a[i][j]);
		}
	}
	printf("%d\n", ans);
}

int main() {
	_init_();
	int t, cs = 1;
	scanf("%d", &t);
	while (t--) {
		printf("Case #%d: ", cs++);
		solve();
	}
	return 0;
}

