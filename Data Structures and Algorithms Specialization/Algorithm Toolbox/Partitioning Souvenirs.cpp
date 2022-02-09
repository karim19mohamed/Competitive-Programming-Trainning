#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 20 + 9, M = 30 * 20 - 9;
const ll Mod_M = 1e9 + 7;

int arr[N], total;
int dp[N][M][M];
bool solve(int idx, int w1 = 0, int w2 = 0) {
	if (idx < 0) {
		if (w1 == w2 && total - w1 - w2 == w1)
			return 1;
		return 0;
	}
	int& ret = dp[idx][w1][w2];
	if (~ret)
		return ret;
	ret = solve(idx - 1, w1 + arr[idx], w2);
	ret = ret | solve(idx - 1, w1, w2 + arr[idx]);
	ret = ret | solve(idx - 1, w1, w2);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif
	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		total += arr[i];
	}
	//dbg2(n, w);
	cout << solve(n - 1) << endl;
	return 0;
}

