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

template<typename T_n> void read(T_n &n) {
	cin >> n;
}
template<typename T_n, typename T_a> void read(T_a a[], T_n n) {
	for (int i = 0; i < n; ++i)
		cin >> a[i];
}
template<typename T_n, typename T_a> void read(vector<T_a> &a, T_n n) {
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
}
void _init_() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);
#endif
}

const int N = 5000 + 9, M = 10 + 9;
const int Mod_M = 1e8;
int n, m, k;
ll p[N], sum[N];

ll dp[N][N];
ll rec(int idx, int group) {
	if (group == k) {
		return 0;
	}
	if (idx == n) {
		return 0;
	}

	ll& ret = dp[idx][group];
	if (~ret) return ret;

	ret = rec(idx + 1, group);
	if (idx < n - m + 1) {
		ret = max(ret, sum[idx] + rec(idx + m, group + 1));
	}
	return ret;
}

void solve() {
	memset(dp, -1, sizeof dp);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &p[i]);
	for (int i = 0; i < m; ++i) {
		sum[0] += p[i];
	}
	for (int i = 1; i < n - m + 1; ++i) {
		sum[i] = sum[i - 1] - p[i - 1] + p[i + m - 1];
	}
	//dbg_array(sum, n);
	ll ans = rec(0, 0);
	printf("%lld\n", ans);
}
int main() {
	_init_();

	solve();

	return 0;
}
