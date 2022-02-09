#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg5(x,y,z,q,k) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<", "<<#k<<" = "<<k<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 200 + 9, M = 4e4 + 9, Max_ans = 200 * 2000 + 9;
int n, a, b, h[N];

int dp[2][N][M][3];
int solve(int idx, int col_a, int col_b, int last) { // 1 a 0 b
	if (idx < 0)
		return 0;
	if (~dp[0][idx][col_a][last])
		return dp[0][idx][col_a][last];
	if (~dp[1][idx][col_b][last])
		return dp[1][idx][col_b][last];
	int ret = Max_ans;
	int unattrack = (idx != n - 1) ? min(h[idx], h[idx + 1]) : 0;
	if (last) {
		if (h[idx] <= col_a)
			ret = min(ret, solve(idx - 1, col_a - h[idx], col_b, 1));
		if (h[idx] <= col_b)
			ret = min(ret,
					unattrack + solve(idx - 1, col_a, col_b - h[idx], 0));
	}
	if (!last) {
		if (h[idx] <= col_b)
			ret = min(ret, solve(idx - 1, col_a, col_b - h[idx], 0));
		if (h[idx] <= col_a)
			ret = min(ret,
					unattrack + solve(idx - 1, col_a - h[idx], col_b, 1));
	}
	dp[0][idx][col_a][last] = dp[1][idx][col_b][last] = ret;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i)
		cin >> h[i];
	memset(dp, -1, sizeof(dp));
	int ans = solve(n - 1, a, b, 2);
	(ans < 200 * 200 * 3) ? printf("%d\n", ans) : puts("-1");
	return 0;
}

