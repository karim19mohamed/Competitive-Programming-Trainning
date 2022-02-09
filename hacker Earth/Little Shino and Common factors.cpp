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

const int N = 1000 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

set<ll> generate_divisors(ll a, ll b) {
	set<ll> v;
	ll i;
	for (i = 1; i * i < a; ++i)
		if (a % i == 0) v.insert(i), v.insert(a / i);
	if (i * i == a) v.insert(i);

	for (i = 1; i * i < b; ++i)
		if (b % i == 0) v.insert(i), v.insert(b / i);
	if (i * i == b) v.insert(i);
	return v;
}

void solve() {
	ll a, b;
	scanf("%lld%lld", &a, &b);
	set<ll> divisors = generate_divisors(a, b);
	std::set<ll>::iterator it;
	ll ans = 0;
	for (it = divisors.begin(); it != divisors.end(); ++it) {
		ll num = *it;
		if (a % num == 0 && b % num == 0) ++ans;
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

