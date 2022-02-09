#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 200000 + 9, M = 1e9 + 7;
ll n = 1;
vector<int> p;
ll POW(ll b, unsigned long long p, ll mod) {
	if (p == 0)
		return 1;
	ll sq = POW(b, p / 2, mod);
	sq = (sq * sq) % mod;
	if (p % 2)
		sq = (sq * b) % mod;
	return sq;
}
ll sqrt_from_primefactors(vector<int> &prime_factors, int mod) {
	ll ans = 1, curr = prime_factors[0], tmp = prime_factors[0];
	bool flag = 0;
	for (int i = 1; i < (int) prime_factors.size(); ++i) {
		if (prime_factors[i] != curr) {
			//dbg(tmp);
			ans = (ans * tmp) % mod;
			curr = prime_factors[i], tmp = prime_factors[i], flag = 0;
		} else {
			if (flag)
				tmp = (tmp * prime_factors[i]) % mod;
			flag = !flag;
		}
	}
	ans = (ans * tmp) % mod;
	//dbg(tmp);
	return ans;
}
void divisor_cnt(map<int, int> &freq, set<int> &distinct, ll &ans) {
	set<int>::iterator it = distinct.begin();
	bool cal_sqrt = 1;
	int ans_sq = 1;
	for (it = distinct.begin(); it != distinct.end(); ++it)
		if (freq[*it] % 2 == 0) {
			cal_sqrt = 0;
			break;
		}
	if (cal_sqrt) {
		ans_sq = sqrt_from_primefactors(p, M);
	}
	it = distinct.begin();
	ll po = ((freq[*it] * (freq[*it] - 1)) / 2) % (M - 1);
	n *= *it;
	++it;
	for (; it != distinct.end(); ++it) {
		po = (po * freq[*it] * (freq[*it] - 1)) % (M - 1);
		n = (n * *it) % M;
		dbg2(*it, po);
	}
	ans = (POW(n, po, M)) % M;
	ans = (ans * ans_sq) % M;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif
	int m, a;

	map<int, int> freq;
	set<int> distinct;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a;
		if (!freq[a]) {
			freq[a] = 1;
		}
		++freq[a];
		distinct.insert(a);
		p.push_back(a);
	}
	sort(p.begin(), p.end());
	ll ans = 1;
	divisor_cnt(freq, distinct, ans);
	printf("%lld\n", ans);
	return 0;
}

