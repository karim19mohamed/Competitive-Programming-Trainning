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
	ll ret = LLONG_MAX;
	int dig = num_of_digits(n);
	ll ten = 10;
	for (int i = 2; i < dig; ++i)
		ten *= 10;
	ll num_ten = 10;
	for (int sst = 1; sst < 10; ++sst) {
		ll num = 0;
//		dbg(st);
		ll cur = num_ten;
		int tmp = 2;
		while (num <= n && tmp > 0) {
			if (sst >= cur) cur *= 10;
//			dbg3(cur, st, num);
			num *= cur;
			num += sst;
			++sst;
			--tmp;
		}
		dbg(num);
		ret = min(ret, num);
	}
	while (ten != 1) {
		ll num = 0;
		ll st = n / ten;
//		dbg(st);
		ll cur = num_ten;
		while (num <= n) {
			if (st >= cur) cur *= 10;
//			dbg3(cur, st, num);
			num *= cur;
			num += st;
			++st;
		}
//		dbg(num);
		ret = min(ret, num);
		st = (n / ten) + 1;
		num = 0;
		cur = num_ten;
		while (num <= n) {
			if (st >= cur) cur *= 10;
			num *= cur;
			num += st;
			++st;
		}
//		dbg(num);
		ret = min(ret, num);
		st = num_ten / 10;
		num = 0;
		cur = num_ten;
		while (num <= n) {
			if (st >= cur) cur *= 10;
			num *= cur;
			num += st;
			++st;
		}
		ret = min(ret, num);

		ten /= 10;
		num_ten *= 10;
	}
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

	for (int i = 1; i < 100000; ++i) {
		ll ans = i + 1;
		while (!naive(ans)) {
			++ans;
		}
		ll ans2 = find_nxt(i);
		if (ans != ans2) {
			dbg(i);
			dbg2(ans, ans2);
			break;
		}
	}
//	printf("%lld\n", ans2);
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

