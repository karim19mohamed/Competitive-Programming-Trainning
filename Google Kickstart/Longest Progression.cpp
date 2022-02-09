#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> point;
#define endl '\n'
#define F first
#define S second
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define dbg2(x,y) cerr<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cerr<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cerr<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define FOR(sz) for(int i = 0; i < sz; ++i)
#define dbg_array(x,sz) FOR(sz) cerr << x[i] << " \n"[i==sz-1]
#define X real()
#define Y imag()

const int d4i[4] = { -1, 0, 1, 0 }, d4j[4] = { 0, 1, 0, -1 };
const int d8i[8] = { -1, -1, 0, 1, 1, 1, 0, -1 }, d8j[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void _init_() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
#endif
}

const int N = 3e5 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

ll solution(ll a[], int n) {
	ll ans = 2;
	ll cnt = 2, cur = a[1] - a[0];
	vector<ll> diff, first, last;
	first.push_back(0);
	for (int i = 2; i < n; ++i) {
		if (a[i] - a[i - 1] == cur) {
			++cnt;
		} else {
			diff.push_back(cur);
			last.push_back(i - 1);
			if (i + 1 < n && a[i - 1] + 2 * cur == a[i + 1]) ++cnt;
			++cnt;
			ans = max(ans, cnt);
			cnt = 2;
			cur = a[i] - a[i - 1];
			first.push_back(i - 1);
		}
	}
	ans = max(ans, cnt);
	diff.push_back(cur);
	last.push_back(n - 1);
//	dbg3(diff.size(), first.size(), last.size());
//	for (int i = 0; i < int(diff.size()); ++i)
//		dbg3(diff[i], first[i], last[i]);
	for (int i = 0; i < int(diff.size()) - 2; ++i) {
		ll t1 = last[i] - first[i] + 1, t2 = last[i + 1] - first[i + 1] + 1, t3 = last[i + 2] - first[i + 2] + 1;
		if (diff[i] == diff[i + 2] && t2 == 2) {
			if (a[last[i]] + 2 * diff[i] == a[first[i + 2]] && first[i + 2] - last[i] == 2) {
				ans = max(ans, t1 + t3);
//				dbg3(diff[i], first[i], last[i]);
//				dbg(a[last[i]]);
			}
		}
		if (i + 3 < int(diff.size())) {
			ll t4 = last[i + 3] - first[i + 3] + 1;
			if (diff[i] == diff[i + 3] && t2 == 2 && t3 == 2) {
				if (a[last[i]] + 2 * diff[i] == a[first[i + 3]]) {
					ans = max(ans, t1 + t4 + 1);
				}
			}
		}
	}
	return ans;
}

void solve() {
	int n;
	ll a[N], b[N];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
		b[n - 1 - i] = a[i];
	}
	ll ans1 = solution(a, n), ans2 = solution(b, n);
//	dbg2(ans1, ans2);
	int ans = max(ans1, ans2);
	printf("%d\n", ans);

}

int main() {
	_init_();
	int t, cs = 1;
	scanf("%d", &t);
	while (t--) {
		printf("Case #%d: ", cs++);
		solve();
	}
	return 0;
}

