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

const int N = 100 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

int num_digits(ll n) {
	int ret = 0;
	while (n) {
		n /= 10;
		++ret;
	}
	return ret;
}
ll binarysearch1(ll num, ll st, ll en) { // FFFFFFFTTTT
	ll s = st, e = en;
	while (s < e) {
		ll mid = s + (e - s) / 2;
		(mid > num) ? e = mid : s = mid + 1;
	}
	return s;
}

void solve() {
	int n;
	ll a[N];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &a[i]);
	ll ans = 0;
	ll pre_ans = 0, big_num = 1e15;
	bool flag = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i - 1]) continue;
		if (flag) {
			int cur_digits = num_digits(a[i]);
			ans += pre_ans - cur_digits;
			continue;
		}
		ll st = a[i], en = a[i];
		int cur_digits = num_digits(a[i]);
		int pre_digits = num_digits(a[i - 1]);
		ans += pre_digits - cur_digits;
		pre_ans = cur_digits;
		while (pre_digits - cur_digits > 0) {
			st = st * 10;
			en = en * 10 + 9;
			++cur_digits;
		}
		if (en <= a[i - 1]) {
			st = st * 10;
			en = en * 10 + 9;
			++ans;
//			dbg2(en, a[i - 1]);
		}
		ll min_a = binarysearch1(a[i - 1], st, en);
		a[i] = min_a;
		if (en > big_num) {
			flag = 1;
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%lld ", a[i]);
	printf("%lld\n", ans);
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

