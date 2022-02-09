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

const int N = 3000 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

int n, arr[N][5];

int dp[N];
int rec(int idx, int a, int b, int c, int d, int e) {
	if (idx == n) {
		return min( { a, b, c, d, e });
	}

	int& ret = dp[idx];
	if (~ret) return ret;

	ret = rec(idx + 1, a, b, c, d, e);
	int a_new = max(a, arr[idx][0]);
	int b_new = max(b, arr[idx][1]);
	int c_new = max(c, arr[idx][2]);
	int d_new = max(d, arr[idx][3]);
	int e_new = max(e, arr[idx][4]);
	ret = max(ret, rec(idx + 1, a_new, b_new, c_new, d_new, e_new));
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 5; ++j)
			scanf("%d", &arr[i][j]);
	int ans = rec(0, 0, 0, 0, 0, 0);
	printf("%d\n", ans);
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

