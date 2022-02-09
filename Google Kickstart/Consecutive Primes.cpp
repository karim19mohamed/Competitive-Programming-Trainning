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

vector<ll> sieve(ll n) {
	vector<bool> is_prime(n + 1, true);
	vector<ll> prime;
	vector<ll> ret;
	for (int i = 2; i <= n; ++i) {
		if (!is_prime[i]) continue;
		else {
			prime.push_back(i);
			if (i != 2) {
				ll num = i * prime[prime.size() - 2];
//				dbg2(num, prime.back() - prime[prime.size() - 2]);
				if (num > 1e18) break;
				ret.push_back(num);
			}
			for (int j = 2; i * j <= n; ++j) {
				is_prime[i * j] = 0;
			}
		}
	}
	return ret;
}

vector<ll> prime;
int binarysearch2(ll num) { // TTTTTTTTTFFFF
	int s = 0, e = prime.size() - 1;
	while (s < e) {
		int mid = s + (e - s + 1) / 2;
		(prime[mid] > num) ? e = mid - 1 : s = mid;
	}
	return s;
}

bool is_prime(ll n) {
	if (n == 2) return true;
	if (n < 2 || n % 2 == 0) return false;
	for (ll i = 3; i * i <= n; i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}

void solve() {
	ll n;
	scanf("%lld", &n);
//	int idx = binarysearch2(n);
//	ll ans = prime[idx];
//	printf("%lld\n", ans);
	ll ans = 1;
	ll k = ceil(sqrt(n)) + 1000;
	while (1) {
		if (is_prime(k)) {
			ll tmp = k - 1;
			while (!is_prime(tmp)) {
				--tmp;
			}
			ans = k * tmp;
			if (ans <= n) break;
		}
		--k;
	}
	printf("%lld\n", ans);
}

int main() {
	_init_();
//	prime = sieve(1e5);
//	printf("%lld\n", prime.back());
	int t, cs = 1;
	scanf("%d", &t);
	while (t--) {
		printf("Case #%d: ", cs++);
		solve();
	}
	return 0;
}

