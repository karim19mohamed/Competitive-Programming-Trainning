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

const int N = 1e5 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

void solve() {
	int n;
	ll c[N];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &c[i]);
	}
	ll ans = n * c[0] + n * c[1];
	ll curr = c[0] + c[1];
	ll min_odd = c[1], min_even = c[0];
	int rem_odd = n - 1, rem_even = n - 1;
	for (int i = 2; i < n; ++i) {
		curr += c[i];
		if (i % 2) {
			//odd
			rem_odd--;
			if (c[i] < min_odd) {
				min_odd = c[i];
			}
		} else {
			//even
			rem_even--;
			if (c[i] < min_even) {
				min_even = c[i];
			}
		}
		ll res = curr + rem_odd * min_odd + rem_even * min_even;
		ans = min(ans, res);
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

