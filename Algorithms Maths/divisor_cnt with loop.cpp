#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 200000 + 9, M = 1e9 + 7;
ll divisor_cnt(vector<int> &prime_factors) {
	ll ans = 1, curr = prime_factors[0], tmp = 2;
	for (int i = 1; i < (int) prime_factors.size(); ++i) {
		if (prime_factors[i] != curr) {
			ans *= tmp;
			curr = prime_factors[i], tmp = 2;
		} else {
			++tmp;
		}
	}
	ans *= tmp;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif
	int m, a;
	ll n = 1;
	vector<int> p;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a;
		n = (n * a) % M;
		p.push_back(a);
	}
	sort(p.begin(), p.end());
	return 0;
}

