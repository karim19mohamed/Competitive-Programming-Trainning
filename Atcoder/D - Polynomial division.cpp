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

const int N = 300 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

int a[N], b[N], c[N];

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i <= n + m; ++i)
		scanf("%d", &c[i]);

	b[m] = c[n + m] / a[n];
	int d = 0;
	int cur_c = n + m - 1;
	for (int bi = m - 1; bi >= 0; --bi) {
		ll sum = 0;
		for (int ai = n - 1; ai >= n - 1 - d; --ai) {
			int tmp = cur_c - ai;
			sum += a[ai] * b[tmp];
		}
		b[bi] = (c[cur_c] - sum) / a[n];
		--cur_c;
		++d;
	}
	for (int i = 0; i < m; ++i)
		printf("%d ", b[i]);
	printf("%d\n", b[m]);

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

