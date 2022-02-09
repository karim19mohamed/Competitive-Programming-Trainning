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

const int N = 3e4 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

void solve() {
	int n, a[N], c[3], ans = 0;
	c[0] = c[1] = c[2] = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		c[a[i] % 3]++;
	}
//	dbg3(c[0], c[1], c[2]);
	int num = n / 3;
	for (int i = 0; i < 3; ++i) {
		int forward = (i + 1) % 3, backward = (i - 1 >= 0) ? i - 1 : 2;
		int excess = c[i] - num;
		if (excess > 0 && i == 0) {
			c[forward] += excess;
			ans += excess;
			c[i] -= excess;
			continue;
		}
		if (excess > 0 && num - c[forward] > 0) {
			int rem = min(num - c[forward], excess);
			c[forward] += rem;
			c[i] -= rem;
			excess -= rem;
			ans += rem;
		}
		if (excess > 0 && num - c[backward] > 0) {
			int rem = min(num - c[backward], excess);
			c[backward] += rem;
			c[i] -= rem;
			excess -= rem;
			ans += 2 * rem;
		}
//		dbg3(c[0], c[1], c[2]);
	}
	printf("%d\n", ans);

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

