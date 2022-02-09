#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const ll N = 1e5 + 9, M = 1e9 + 7;
int t, k, a, b;
ll dp[N];
ll solve(int length) {
	if (length <= 0) {
		return length == 0;
	}
	ll& ret = dp[length];
	if (~ret)
		return ret;
	ret = (solve(length - 1) + M) % M;
	ret = (ret + solve(length - k) + M) % M;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif
	cin >> t >> k;
	memset(dp, -1, sizeof(dp));
	ll tmp = solve(N - 1);
	vector<ll> cdf(N + 1, 0);
	for (int i = 1; i < N; ++i) {
		cdf[i] = (cdf[i - 1] + dp[i] + M) % M;
	}
	while (t--) {
		cin >> a >> b;
		ll ans1 = cdf[b], ans2 = cdf[a - 1];
		printf("%lld\n", (ans1 - ans2 + M) % M);
	}
	return 0;
}

