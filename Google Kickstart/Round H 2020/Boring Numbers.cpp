#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
	freopen("input.in", "rt", stdin);
//	freopen("output.out", "wt", stdout);
#endif
}

const int N = 200 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

bool boring_check(ll n) {
	ll d = 1e18;
	while (n / d == 0)
		d /= 10;
	bool odd = 1;
	while (d) {
		if (((n / d) & 1) != odd) return false;
		n %= d;
		odd ^= 1;
		d /= 10;
	}
	return true;
}
ll small_TC(ll l, ll r) {
	ll ret = 0;
	for (ll i = l; i <= r; ++i) {
		if (boring_check(i)) {
//			dbg(i);
			++ret;
		}
	}
	return ret;
}
ll cnt_from_zero(ll n, unsigned long long &d) {
	d = 0;
	ll five = 0;
	ll ret = 0;
	while (d * 10LL + 9LL <= n) {
		d = d * 10LL + 9LL;
		++five;
	}
	while (five) {
		ll tmp = 1;
		for (int i = 0; i < five; ++i) {
			tmp *= 5;
		}
		--five;
		ret += tmp;
	}
	return ret;
}
ll f(ll n, ll sq, int num) {
	ll ret = 0;
	while (num < n) {
		ll tmp = 1;
		for (int i = 0; i < sq; ++i) {
			tmp *= 5;
		}
		ret += tmp;
		num += 2;
	}
	return ret;
}
ll cnt_strict(ll n) {
	ll d = 1e18, sq = 18;
	while (n / d == 0)
		d /= 10, --sq;
	bool odd = 1;
	ll ret = 0;
	while (d) {
		if (odd) {
			ret += f(n / d, sq, 1);
		} else {
			ret += f(n / d, sq, 0);
		}
		if (((n / d) & 1) != odd) {
			return ret;
		}
		--sq;
		odd ^= 1;
		n %= d;
		d /= 10;
	}
	return ret;
}
ll large_TC(ll l, ll r) {
	unsigned long long before_l = 0;
	unsigned long long dr, dl;
	if (l - 1) {
		before_l = cnt_from_zero(l - 1, dl);
		if (dl < l - 1) before_l += cnt_strict(l - 1);
	}
	ll before_r = cnt_from_zero(r, dr);
	if (dr < r) before_r += cnt_strict(r);
	if (boring_check(r)) ++before_r;
	if (l - 1 && boring_check(l - 1)) ++before_l;

//	dbg4(before_r, before_l, dr, dl);
	return before_r - before_l;
}

void solve() {
	ll l, r;
	scanf("%lld%lld", &l, &r);
//	ll ans = small_TC(l, r);
//	printf("%lld  ", ans);
	ll ans2 = large_TC(l, r);
	printf("%lld\n", ans2);
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
