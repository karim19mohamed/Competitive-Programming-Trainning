#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg5(x,y,z,q,k) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<", "<<#k<<" = "<<k<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 1e3 + 9, M = 1e5 + 9, Min_ans = -(1e8 + 9);
int n, m;
vector<vector<int>> a;
vector<int> row_vis;

void set_ones(int i) {
	if (i > 0)
		++row_vis[i - 1];
	if (i < n - 1)
		++row_vis[i + 1];
}
void set_zeros(int i) {
	if (i > 0)
		--row_vis[i - 1];
	if (i < n - 1)
		--row_vis[i + 1];
}

int solve(int i, int j, int row) {
	if (i < 0 || j < 0)
		return 0;

	int ret = max(solve(i - 1, m - 1, row), solve(i, j - 1, row));
	if (!row_vis[i]) {
		set_ones(i);
		ret = max(ret,
				a[i][j]
						+ max(solve(i, j - 2, i - 1),
								solve(i - 2, m - 1, i - 1)));
		set_zeros(i);
	}
	return ret;
}

int iter_solve() {
	vector<vector<int>> dp(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (j == 0)
				dp[i][j] = a[i][j];
			else if (j == 1)
				dp[i][j] = max(a[i][j], dp[i][j - 1]);
			else
				dp[i][j] = max(a[i][j] + dp[i][j - 2], dp[i][j - 1]);
		}
	vector<int> row(n, 0);
	for (int i = 0; i < n; ++i)
		if (i == 0)
			row[i] = dp[i][m - 1];
		else if (i == 1)
			row[i] = max(dp[i][m - 1], row[i - 1]);
		else
			row[i] = max(dp[i][m - 1] + row[i - 2], row[i - 1]);
	return row[n - 1];
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif
	while (cin >> n >> m && n + m) {
		a.clear(), row_vis.clear();
		a.resize(n, vector<int>(m, 0));
		row_vis.resize(n, 0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> a[i][j];
			}
		}
		//int ans = solve(n - 1, m - 1, -1);
		int ans2 = iter_solve();
		//printf("%d\n", ans);
		printf("%d\n", ans2);

	}
	return 0;
}

