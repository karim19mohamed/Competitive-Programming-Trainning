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
	freopen("input.in", "rt", stdin);
//	freopen("output.out", "wt", stdout);
#endif
}

const int N = 1e5 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

queue<int> need_paint[N];

void solve() {
	int n, m, a[N], b[N], c[N];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < n; ++i)
		scanf("%d", b + i);
	for (int i = 0; i < m; ++i)
		scanf("%d", c + i);

	int get_rid[N];
	int painted = -1;
	memset(get_rid, 0, sizeof(get_rid));
	for (int i = 0; i < n; ++i) {
		if (a[i] == b[i]) get_rid[a[i]] = i + 1;
		else need_paint[b[i]].push(i);
	}
	bool no_ans = 0;
	stack<int> ans;
	for (int i = m - 1; i >= 0; --i) {
		int idx = painted;
		if (!need_paint[c[i]].empty()) {
			idx = need_paint[c[i]].front();
			need_paint[c[i]].pop();
			painted = idx;
		} else if (get_rid[c[i]]) {
			idx = get_rid[c[i]] - 1;
			painted = idx;

		} else if (painted != -1) {
			idx = painted;
		} else {
			no_ans = 1;
			break;
		}
		ans.push(idx + 1);
	}
	for (int i = 0; i < n; ++i)
		while (!need_paint[b[i]].empty()) {
			need_paint[b[i]].pop();
			no_ans = 1;
		}
	if (no_ans) {
		puts("NO");
		for (int i = 0; i < n; ++i)
			return;
	}
	puts("YES");
	while (!ans.empty()) {
		printf("%d", ans.top());
		ans.pop();
		printf("%c", " \n"[ans.empty()]);
	}
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

