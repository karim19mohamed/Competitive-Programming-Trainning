#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

using namespace std;
const int N = 10000 + 9;
vector<ll> prime_factorization(ll num) { //O(sqrt(n))
	vector<ll> v;
	for (ll i = 2; i * i <= num; ++i)
		while (num % i == 0)
			v.push_back(i), num /= i;
	if (num != 1)
		v.push_back(num);
	return v;
}

int t;
ll a, b, c;

void solve(ll x, ll y, ll z, int idx, vector<ll> &prime, bool &ans) {
	if (idx == (int) prime.size()) {
		ll sum = x + y + z, sum_sq = x * x + y * y + z * z;
		if (sum == a && sum_sq == c && !ans && x != y && x != z && y != z) {
			ans = 1;
			ll tmp[] = { x, y, z };
			sort(tmp, tmp + 3);
			printf("%lld %lld %lld\n", tmp[0], tmp[1], tmp[2]);
		}
		return;
	}
	solve(x, y, z * prime[idx], idx + 1, prime, ans);
	solve(x, y * prime[idx], z, idx + 1, prime, ans);
	solve(x * prime[idx], y, z, idx + 1, prime, ans);
}

int main() {

	scanf("%d", &t);
	while (t--) {
		scanf("%lld %lld %lld", &a, &b, &c);
		vector<ll> prime = prime_factorization(b);
		bool ans = 0;
		solve(-1, -1, 1, 0, prime, ans);
		if (!ans)
			solve(1, 1, 1, 0, prime, ans);
		if (!ans)
			puts("No solution.");
	}
	return 0;
}

