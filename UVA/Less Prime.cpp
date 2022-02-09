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

template<typename T_n> void read(T_n &n) {
	cin >> n;
}
template<typename T_n, typename T_a> void read(T_a a[], T_n n) {
	for (int i = 0; i < n; ++i)
		cin >> a[i];
}
template<typename T_n, typename T_a> void read(vector<T_a> &a, T_n n) {
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
}
void _init_() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);
#endif
}

const int N = 10000 + 9, M = 1000 - 9;
vector<ll> prime;
vector<ll> sieve(ll n) {
	vector<bool> is_prime(n + 1, true);
	vector<ll> prime;
	for (int i = 2; i <= n; ++i) {
		if (!is_prime[i]) continue;
		else {
			prime.push_back(i);
			for (int j = 2; i * j <= n; ++j) {
				is_prime[i * j] = 0;
			}
		}
	}
	return prime;
}

void solve() {
	int n;
	scanf("%d", &n);
	ll ans;
	for (int i = 0; i < (int) prime.size(); ++i) {
		if (prime[i] <= n && prime[i] * 2 > n) {
			ans = prime[i];
			break;
		}
	}
	printf("%lld\n", ans);
}
int main() {
	_init_();
	int t;
	scanf("%d", &t);
	prime = sieve(N);
	while (t--) {
		solve();
	}
	return 0;
}
