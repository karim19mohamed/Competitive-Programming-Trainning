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

const int N = 2000 + 9, M = 1e4 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

int binarysearch2(int n) { // TTTTTTTTTFFFF
	int s = 0, e = n;
	while (s < e) {
		int mid = s + (e - s + 1) / 2;
		(mid + mid - 1 + mid - 2 <= n) ? s = mid : e = mid - 1;
	}
	return (s - 2 >= 0 && s + s - 1 + s - 2 == n) ? s : -1;
}

ll rec(int idx, ll ans, const int n, const ll num) {
	if (idx == n) {
		return (ans % num == 0) ? ans : -1;
	}
	ll ret = -1;
	ret = max(ret, rec(idx + 1, ans * 10 + 1, n, num));
	ret = max(ret, rec(idx + 1, ans * 10 + 2, n, num));
	return ret;
}

void solve() {
	int n;
	ll ans, num = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		num *= 2;
	ans = rec(0, 0, n, num);
	printf("%lld\n", ans);
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

