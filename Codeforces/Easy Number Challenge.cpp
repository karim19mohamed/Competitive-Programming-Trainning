#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const ll N = 1e6 + 9, M = 1073741824;
vector<ll> v(N, -1);
ll prime_factorization(ll num) { //O(sqrt(n))
	ll ret = 1;
	for (ll i = 2; i * i <= num; ++i) {
		ll tmp = 1;
		while (num % i == 0) {
			++tmp;
			num /= i;
		}
		ret *= tmp;
	}
	if (num != 1)
		ret *= 2;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif
	int a, b, c;

	cin >> a >> b >> c;
	int ans = 0;
	for (int i = 1; i <= a; ++i)
		for (int j = 1; j <= b; ++j)
			for (int k = 1; k <= c; ++k) {
				if (v[i * j * k] == -1)
					v[i * j * k] = prime_factorization(i * j * k);
				ans += v[i * j * k];
			}
	ans %= M;
	printf("%d\n", ans);
	return 0;
}

