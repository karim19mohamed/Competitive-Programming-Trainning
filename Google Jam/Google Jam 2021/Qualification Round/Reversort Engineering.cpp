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

const int N = 100 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

int n, a[N];

void revert(int st, int en) {
	while (st < en) {
		swap(a[st], a[en]);
		++st;
		--en;
	}
}

int revert_sort() {
	int ret = 0;
	for (int i = 0; i < n - 1; ++i) {
		int mx = a[i];
		int idx = i;
		for (int j = i + 1; j < n; ++j) {
			if (mx > a[j]) mx = a[j], idx = j;
		}
		ret += idx - i + 1;
		revert(i, idx);
	}
	return ret;
}

int create_a(int cost) {
	int st = 0, en = n - 1;
	bool direction = 0; // a
	int sz = n, num = 1;
	while (sz > 1) {
		if (cost - (sz + sz - 2) >= 0) {
			cost -= sz;
			(!direction) ? a[en--] = num : a[st++] = num;
			direction ^= 1;
		} else {
			--cost;
			(!direction) ? a[st++] = num : a[en--] = num;
		}
//		dbg(cost);
		++num;
		--sz;
	}
	a[st] = num;
	return cost;
}

void solve() {
	int cost;
	scanf("%d%d", &n, &cost);
	int res = create_a(cost);
	if (res == 0) {
		for (int i = 0; i < n; ++i) {
			printf("%d%c", a[i], " \n"[i == n - 1]);
		}
	} else {
		puts("IMPOSSIBLE");
	}
//	int ans = revert_sort();
//	dbg(ans);
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

