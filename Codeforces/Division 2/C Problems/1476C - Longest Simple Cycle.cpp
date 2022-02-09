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

const int N = 1e5 + 9, M = 1e4 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

void solve() {
	int n;
	ll len[N], a[N], b[N], ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &len[i]);
		len[i]--;
	}
	for (int i = 0; i < n; ++i)
		scanf("%lld", &a[i]);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &b[i]);
	ans = len[n - 1];
	ll tmp = ans, tmp2 = 0;
	for (int i = n - 2; i >= 0; --i) {
		tmp += 2;
		if (b[i + 1] == a[i + 1]) {
			ans = max(ans, tmp);
			tmp = len[i];
		} else if (i == 0) {
			tmp += abs(b[i + 1] - a[i + 1]);
			ans = max(ans, tmp);
		} else {
			tmp2 = tmp + abs(b[i + 1] - a[i + 1]);
			tmp += len[i] - abs(b[i + 1] - a[i + 1]);
			if (len[i] > tmp) {
				tmp = len[i];
			}
			ans = max(ans, max(tmp, tmp2));
		}
	}
	printf("%lld\n", ans);
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

