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

const int N = 2e5 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

bool a_[N], b_[N];

void solve() {
	int n;
	ll k, a[N], b[N];

	scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &a[i]);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &b[i]);
	a_[0] = b_[0] = true;
	for (int i = 0; i < n - 1; ++i) {
		if (a_[i]) {
			if (abs(a[i] - a[i + 1]) <= k) {
				a_[i + 1] = true;
			}
			if (abs(a[i] - b[i + 1]) <= k) {
				b_[i + 1] = true;
			}
		}
		if (b_[i]) {
			if (abs(b[i] - a[i + 1]) <= k) {
				a_[i + 1] = true;
			}
			if (abs(b[i] - b[i + 1]) <= k) {
				b_[i + 1] = true;
			}
		}
	}
	(a_[n - 1] || b_[n - 1]) ? puts("Yes") : puts("No");
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

