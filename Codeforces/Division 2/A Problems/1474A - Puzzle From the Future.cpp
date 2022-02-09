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
	char s[N], ans[N];
	scanf("%d%s", &n, s);
	ans[0] = '1';
	s[0] = s[0] + 1;
	for (int i = 1; i < n; ++i) {
		for (char j = '1', k = 1; k >= 0; --j, --k) {
			if (s[i] + k != s[i - 1]) {
				ans[i] = j;
				s[i] = s[i] + j - '0';
				break;
			}
		}
//		printf("%s\n", s);
	}
	for (int i = 0; i < n; ++i)
		printf("%c", ans[i]);
	puts("");
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

