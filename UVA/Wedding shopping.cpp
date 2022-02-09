#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const ll N = 20 + 9, M = 200 + 9;
int t, money, c, k[N], a[N][N];
int dp[N][M];
int solve(int cat, int mon) {
	if (cat < 0) {
		return 0;
	}
	int& ret = dp[cat][mon];
	if (~ret)
		return ret;
	for (int i = 0; i < k[cat]; ++i) {
		if (mon >= a[cat][i]) {
			int tmp = solve(cat - 1, mon - a[cat][i]);
			if (~tmp)
				ret = max(ret, a[cat][i] + tmp);
		}
	}
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
		cin >> money >> c;
		for (int i = 0; i < c; ++i) {
			cin >> k[i];
			for (int j = 0; j < k[i]; ++j)
				cin >> a[i][j];
		}
		int ans = solve(c - 1, money);
		if (~ans)
			printf("%d\n", ans);
		else
			puts("no solution");
	}
	return 0;
}

