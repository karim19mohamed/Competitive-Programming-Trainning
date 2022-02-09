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

const int N = 30 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

int num_of_digits(ll n) {
	int ret = 0;
	while (n) {
		n /= 10;
		++ret;
	}
	return ret;
}
//bool leading_zero(ll n, ll ten){
//	ll num = n/ten;
//}

ll nxt(ll n, int num_digits) {
	ll ten = 1, ret = 0;
	while (num_digits--) {
		ll num = n / 10;
		ret = num * ten;
		ten *= 10;
		n /= 10;
	}
	++ret;
	return ret;
}
ll find_nxt(ll n) {
	ll ret = 0;

	return ret;
}
bool naive(ll num) {
	int digit = num_of_digits(num);
	ll ten = 10;
	for (int i = 1; i <= digit; ++i) {
		ll st = num % ten;
		ll tmp = num / ten;
//		dbg(st);
		bool flag = 1;
		if (tmp == 0) return 0;
		if (num_of_digits(st) != i) {
			ten *= 10;
			continue;
		}
		int cur_digit = i;
		ll cur_ten = ten;
		while (tmp) {
			ll target = st - 1;
			if (num_of_digits(target) != cur_digit) {
				cur_ten /= 10;
				--cur_digit;
			}
			if (cur_digit <= 0) {
				flag = 0;
				break;
			}
			ll nxt = tmp % cur_ten;
			tmp = tmp / cur_ten;
//			dbg2(tmp, nxt);
			if (num_of_digits(nxt) != cur_digit && tmp != 0) {
				flag = 0;
				break;
			}
			if (nxt != st - 1) {
				flag = 0;
				break;
			} else {
				st = nxt;
			}
		}
		ten *= 10;
		if (flag) return 1;
	}
	return 0;
}

void solve() {
	ll n;
	scanf("%lld", &n);
	if (n > 1e9) return;
	ll ans = n + 1;
//	dbg(naive(ans));
	while (!naive(ans)) {
//		dbg(ans);
		++ans;
	}
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

