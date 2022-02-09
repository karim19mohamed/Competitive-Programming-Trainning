#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const ll N = 1e4 + 9, M = 1073741824;
int t, n, cs = 1;
ll a[N], dp[N];
ll solve(int idx) {
	if (idx < 0) {
		return 0;
	}
	ll& ret = dp[idx];
	if (~ret)
		return ret;
	ret = max(ret, solve(idx - 1));
	ret = max(ret, a[idx] + solve(idx - 2));
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif
	cin >> t;
	while (t--) {
		memset(dp, -1, sizeof(dp));
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		ll ans = solve(n - 1);
		//dbg_array(dp, n);
		printf("Case %d: %lld\n", cs++, ans);
	}
	return 0;
}

