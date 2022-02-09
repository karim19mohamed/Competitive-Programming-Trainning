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

const int N = 100 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

vector<int> all;
ll all_sum;
ll dp[N][499 * 100];
ll rec(int idx, ll sum, ll product) {
	if (product > all_sum) return 0;
	if (idx == -1) {
		if (sum == product) {
			return sum;
		}
		return 0;
	}
	ll& ret = dp[idx][product];
	if (~ret) return ret;
	ret = rec(idx - 1, sum + all[idx], product);
	ret = max(ret, rec(idx - 1, sum, product * all[idx]));

	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	int n, p, m;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &p, &m);
		while (m--) {
			all.push_back(p);
			all_sum += p;
		}
	}
	ll ans = 0;
	ans = rec(all.size() - 1, 0, 1);

	printf("%lld\n", ans);
	all.erase(all.begin(), all.end());
	all_sum = 0;
}

int main() {
	_init_();
	int t, cs = 1;
	scanf("%d", &t);
	while (t--) {
		printf("Case #%d: ", cs++);
		solve();
	}
	return 0;
}

