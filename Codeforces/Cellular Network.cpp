#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 100000 + 9;
int n, m;
ll city[N], tower[N];
bool valid(ll r) {
	int num = 0, idx_city = 0;
	for (int i = 0; i < m && idx_city < n; ++i) {
		ll min_r = tower[i] - r, max_r = tower[i] + r;
		while (idx_city < n && city[idx_city] >= min_r
				&& city[idx_city] <= max_r)
			++num, ++idx_city;
	}
	return num >= n;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
	freopen("output.out", "wt", stdout);
#endif
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> city[i];
	for (int i = 0; i < m; ++i)
		cin >> tower[i];

	ll s = 0, e = 1 + 2e9;
	while (s < e) {
		ll mid = s + (e - s) / 2;
		(valid(mid)) ? e = mid : s = mid + 1;
		//dbg(e);
	}
	printf("%lld\n", s);
	return 0;
}

