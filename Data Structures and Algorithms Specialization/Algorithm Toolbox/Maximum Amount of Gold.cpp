#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 300 + 9, M = 1e4 - 9;
const ll Mod_M = 1e9 + 7;

int arr[N];
ll dp[N][M];
ll solve(int idx, int weight) {
	if (idx < 0)
		return 0;
	ll& ret = dp[idx][weight];
	if (~ret)
		return ret;
	ret = solve(idx - 1, weight);
	if (arr[idx] <= weight)
		ret = max(ret, arr[idx] + solve(idx - 1, weight - arr[idx]));
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif
	memset(dp, -1, sizeof(dp));
	int w, n;
	cin >> w >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	//dbg2(n, w);
	cout << solve(n - 1, w) << endl;
	return 0;
}

