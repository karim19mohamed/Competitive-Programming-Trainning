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

const int N = 1e5 + 9, M = 1e4 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

vector<int> sieve(ll n) {
	vector<bool> is_prime(n + 1, true);
	vector<int> prime;
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
vector<int> dp() {
	vector<int> ret(100000 + 9, 1e9);
	vector<int> prime = sieve(20178);
	ll a;
	int d;
	for (int i = 0; i < (int) prime.size(); ++i) {
		for (int j = i + 1; j < (int) prime.size(); ++j) {
			a = prime[i] * prime[j];
			d = min(prime[i] - 1, prime[j] - prime[i]);
			if (d <= 100000 && ret[d] > a) {
				ret[d] = a;
			}
		}
	}
	int num = 1e9;
	for (int i = ret.size() - 1; i >= 0; --i) {
		num = min(ret[i], num);
		ret[i] = num;
	}
	return ret;
}

void solve(vector<int> all) {
	int n;
	int ans;
	scanf("%d", &n);
	ans = all[n];
	printf("%d\n", ans);
}

int main() {
	_init_();
	int t;
	scanf("%d", &t);
	vector<int> all = dp();
	while (t--) {
		solve(all);
	}
	return 0;
}
