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

void _init_() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
#endif
}

const int N = 100 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

void solve() {
	int n, m;
	vector<pair<int, int> > lines;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		lines.push_back(make_pair(u, v));
	}
	int ans = 0;
	int dis = 1;
	while (dis != n) {
		for (int i = 1; i <= n - dis; ++i) {
			int cur_u = i, cur_v = i + dis;
			bool flag = 1;
			for (int j = 0; j < int(lines.size()) && flag; ++j) {
				int u = lines[j].F, v = lines[j].S;
				if (cur_u == u && cur_v == v) flag = 0;
				if (cur_v > v && v > cur_u && (u < cur_u || u > cur_v)) flag = 0;
				if (cur_u < u && cur_v > u && (v < cur_u || v > cur_v)) flag = 0;
			}
//			dbg2(cur_u, cur_v);
			if (flag) {
				lines.push_back(make_pair(cur_u, cur_v));
//				dbg2(cur_u, cur_v);
				++ans;
			}
		}
		++dis;
	}
	printf("%d\n", ans);
}

int main() {
	_init_();
//	int t;
//	scanf("%d", &t);
//	while (t--) {
	solve();
//	}
	return 0;
}

