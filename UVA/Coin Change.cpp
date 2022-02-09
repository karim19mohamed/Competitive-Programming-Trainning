#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 7489 + 9, M = 5 + 9;
int arr[] = { 50, 25, 10, 5, 1 };
ll dp[M][N];
ll solve(int idx, int weight) {
	if (idx < 0)
		return 0;
	if (weight == 0)
		return 1;
	ll& ret = dp[idx][weight];
	if (~ret)
		return ret;
	ret = solve(idx - 1, weight);
	if (weight >= arr[idx])
		ret += solve(idx, weight - arr[idx]);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif
	int n;
	memset(dp, -1, sizeof(dp));
	while (cin >> n) {
		//dbg(n);
		ll ans = solve(4, n);
		printf("%lld\n", ans);
	}
	return 0;
}

