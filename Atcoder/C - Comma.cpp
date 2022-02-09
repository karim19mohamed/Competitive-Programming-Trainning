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
	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
#endif
}

const int N = 20 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

ll digit_cnt(ll num) {
	ll digits = 0;
	while (num) {
		++digits;
		num /= 10;
	}
	return digits;
}
ll ten_cnt(ll num) {
	ll ten = 1;
	while (num) {
		num /= 10;
		ten *= 10;
	}
	return ten;
}

void solve() {
	ll n;
	scanf("%lld", &n);
	ll digits = 0, num = n, ten = 1;
	while (num) {
		++digits;
		num /= 10;
		ten *= 10;
	}
	ll ans = 0;
	num = n;
	while (digits) {
		ll comma = (digits / 3) - 1 + ((digits % 3) ? 1 : 0);
		ten /= 10;
		ll cnt = (num % ten) + 1;
		ans += comma * cnt;
		num -= cnt;
		digits = digit_cnt(num);
		ten = ten_cnt(num);
//		dbg3(digits, comma, num);
	}
	printf("%lld\n", ans);
}

int main() {
	_init_();
//	int t;
//	scanf("%d", &t);
//	while (t--) {
	solve();
//	}
	return 0;
}

