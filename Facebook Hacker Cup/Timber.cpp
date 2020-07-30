#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const ll N = 800000 + 9, M = -6e9 - 9;
int n;
vector<pair<ll, ll>> a;

ll dp[N][2];
ll solveright(int idx, int dir) { // defualt dir = 0
	ll& ret = dp[idx][dir];
	if (~ret)
		return ret;

	ret = a[idx].second;
	ll post_pos = a[idx].first + ret;  // 0
	if (dir)
		post_pos = a[idx].first;

	for (int i = 0; i < n; ++i) {
		if (i == idx)
			continue;
		if (a[i].first == post_pos)
			ret = max(ret, a[idx].second + solveright(i, 0));

		if (a[i].first - a[i].second == post_pos)
			ret = max(ret, a[idx].second + solveright(i, 1));
	}
	return ret;
}
ll solveleft(int idx, int dir) { // defualt dir = 1
	ll& ret = dp[idx][dir];
	if (~ret)
		return ret;

	ret = a[idx].second;
	ll pre_pos = a[idx].first - ret;  // 0
	if (!dir)
		pre_pos = a[idx].first;

	for (int i = 0; i < n; ++i) {
		if (i == idx)
			continue;
		if (a[i].first == pre_pos)
			ret = max(ret, a[idx].second + solveleft(i, 1));

		if (a[i].first + a[i].second == pre_pos)
			ret = max(ret, a[idx].second + solveleft(i, 0));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
//#ifdef ECLIPSE
	freopen("timber_input.txt", "rt", stdin);
	//freopen("output.out", "wt", stdout);
//#endif
	int t, cs = 1;
	ll p, h;
	cin >> t;
	while (t--) {
		a.clear();
		memset(dp, -1, sizeof dp);
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> p >> h;
			a.push_back( { p, h });
		}
		//sort(a.begin(), a.end());
		ll ans = 0;
		for (int i = 0; i < n; ++i) {
			ll tmp1 = solveright(i, 0);
			ll tmp2 = solveleft(i, 1);
			ans = max(ans, max(tmp1, tmp2));
		}
		printf("Case #%d: %lld\n", cs++, ans);
	}
	return 0;
}

