#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 20000 + 9, M = 1000 + 9;
string a, b;
int dp[N][N];
int solve(int idx_a, int idx_b) {
	if (idx_a < 0)
		return (idx_b >= 0) ? idx_b + 1 : 0;
	if (idx_b < 0)
		return (idx_a >= 0) ? idx_a + 1 : 0;
	int& ret = dp[idx_a][idx_b];
	if (~ret && ret != N)
		return ret;
	ret = N;
	if (a[idx_a] == b[idx_b]) {
		ret = min(ret, solve(idx_a - 1, idx_b - 1));
	} else {
		//delete
		ret = min(ret, 1 + solve(idx_a - 1, idx_b));
		//insert
		ret = min(ret, 1 + solve(idx_a, idx_b - 1));
		//replace
		ret = min(ret, 1 + solve(idx_a - 1, idx_b - 1));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		memset(dp, -1, sizeof(dp));
		cin >> a >> b;
		int ans = solve(a.size() - 1, b.size() - 1);
		printf("%d\n", ans);
	}
	return 0;
}

