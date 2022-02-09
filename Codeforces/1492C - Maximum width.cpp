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

int n, m;
char s[N], t[N];

int dp[N];

int rec(int idx_s, int idx_t, int pre_p) {
	if (idx_t == m) return 0;
	if (idx_s == n) return 0;

	int& ret = dp[pre_p + 1];
	if (~ret) return ret;

	ret = rec(idx_s + 1, idx_t, pre_p);
	if (s[idx_s] == t[idx_t]) {
		if (pre_p == -1) {
			ret = max(ret, rec(idx_s + 1, idx_t + 1, idx_s));
		} else {
			ret = max(max(ret, idx_s - pre_p), rec(idx_s + 1, idx_t + 1, idx_s));
		}
	}
	return ret;
}

vector<int> get_first() {
	vector<int> ret;
	int idx = 0;
	for (int i = 0; i < n; ++i) {
		if (idx == m) break;
		if (s[i] == t[idx]) {
			ret.push_back(i);
			++idx;
		}
	}
	return ret;
}
vector<int> get_last() {
	vector<int> ret(m);
	int idx = m - 1;
	for (int i = n - 1; i >= 0; --i) {
		if (idx == -1) break;
		if (s[i] == t[idx]) {
			ret[idx] = i;
			--idx;
		}
	}
	return ret;
}
int solution() {
	vector<int> first = get_first();
	vector<int> last = get_last();
	int ans = 0;
	for (int i = 0; i < m - 1; ++i)
		ans = max(ans, last[i + 1] - first[i]);
	return ans;
}

void solve() {
	scanf("%d%d%s%s", &n, &m, s, t);
	memset(dp, -1, sizeof(dp));
//	int ans = rec(0, 0, -1); // TLE
	int ans = solution(); // AC

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

