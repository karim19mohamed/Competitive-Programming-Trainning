#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N_bags = 50 + 9, Max_weight = 1000 + 9;
int bags[N_bags][2], dp[N_bags][Max_weight];

int solve(int idx, int truck) {
	if (idx < 0)
		return 0;
	int& ret = dp[idx][truck];
	if (~ret)
		return ret;
	ret = solve(idx - 1, truck);
	if (bags[idx][0] <= truck)
		ret = max(ret, bags[idx][1] + solve(idx - 1, truck - bags[idx][0]));
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif
	int t, truck, m;
	cin >> t;
	while (t--) {
		memset(dp, -1, sizeof(dp));
		cin >> truck >> m;
		for (int i = 0; i < m; ++i)
			cin >> bags[i][0] >> bags[i][1];
		int ans = solve(m - 1, truck);
		printf("Hey stupid robber, you can get %d.\n", ans);
	}
	return 0;
}

