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

const int N = 100 + 9, M = 10 + 9;
const int Mod_M = 1e8;
int n1, n2, k1, k2;

int dp[M][M][N][N];
int rec(int foot, int hors, int allfoot, int allhors) {
	if (allfoot == n1 && allhors == n2) {
		return 1;
	}
	//dbg4(foot, hors, allfoot, allhors);

	int& ret = dp[foot][hors][allfoot][allhors];
	if (~ret) return ret;

	ret = 0;
	if (foot < k1 && allfoot < n1) {
		ret += rec(foot + 1, 0, allfoot + 1, allhors) % Mod_M;
	}
	if (hors < k2 && allhors < n2) {
		ret += rec(0, hors + 1, allfoot, allhors + 1) % Mod_M;
	}
	return ret % Mod_M;
}

void solve() {
	memset(dp, -1, sizeof dp);
	//dbg(dp[0][1][0][1]);
	scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
	int ans = rec(0, 0, 0, 0) % Mod_M;
	printf("%d\n", ans);
}
int main() {
	_init_();

	solve();

	return 0;
}
