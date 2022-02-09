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

const int N = 20 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

void solve() {
	char a[N], b[N];
	scanf("%s%s", a, b);
	int n1 = strlen(a), n2 = strlen(b);
	int sz = 0, ans = 0;
	while (sz <= min(n1, n2)) {
		for (int st1 = 0; st1 < n1; ++st1) {
			for (int st2 = 0; st2 < n2; ++st2) {
				bool chk = 1;
				int cnt = 0;
				while (cnt < sz) {
					if (st1 + cnt >= n1 || st2 + cnt >= n2) {
						chk = 0;
						break;
					}
					if (a[st1 + cnt] != b[st2 + cnt]) chk = 0;
					++cnt;
				}
				if (chk) ans = sz;
			}
		}
		++sz;
	}
	ans = (n1 - ans) + (n2 - ans);
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

