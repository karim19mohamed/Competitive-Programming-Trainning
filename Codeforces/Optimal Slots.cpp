#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 1e4 + 9, M = 1000 + 9;
int n;
ll a[N], dp[N][M];
ll solve(int idx, int sum) {
	if (idx == n)
		return 0;

	ll& ret = dp[idx][sum];
	if (~ret)
		return ret;

	ret = solve(idx + 1, sum);
	if (a[idx] <= sum)
		ret = max(ret, a[idx] + solve(idx + 1, sum - a[idx]));
	return ret;
}
void prtsolve(int idx, int sum) {
	if (idx == n)
		return;
	int ret = solve(idx, sum);
	if (a[idx] <= sum && ret == a[idx] + solve(idx + 1, sum - a[idx])) {
		printf("%lld ", a[idx]);
		prtsolve(idx + 1, sum - a[idx]);
	} else if (ret == solve(idx + 1, sum)) {
		//dbg(a[idx]);
		prtsolve(idx + 1, sum);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif
	int t;
	while (cin >> t) {
		if (!t)
			break;
		cin >> n;
		ll sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			sum += a[i];
		}
		memset(dp, -1, sizeof dp);
		ll ans_sum = solve(0, t);
		prtsolve(0, t);
		printf("%lld\n", ans_sum);
	}
	return 0;
}

