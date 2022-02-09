#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 1000 + 9, M = 1073741824;
vector<bool> is_prime(N + 1, true);
vector<int> sieve(int n) {
	vector<int> prime;
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i <= n; ++i) {
		if (!is_prime[i]) {
			continue;
		} else {
			prime.push_back(i);
			for (int j = 2; i * j <= n; ++j) {
				is_prime[i * j] = 0;
			}
		}
	}
	return prime;
}
vector<int> lucky(vector<int> &prime) {
	vector<int> ans;
	int tmp = N, num = 30;
	while (tmp) {
		int cnt = 0;
		for (auto p : prime) {
			if (!(num % p))
				++cnt;
			if (cnt == 3)
				break;
		}
		if (cnt == 3) {
			ans.push_back(num);
			--tmp;
		}
		++num;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);
#endif
	int t, n, k;
	cin >> t;
	vector<int> prime = sieve(N);
	vector<int> ans = lucky(prime);
	//dbg(ans.back());
	while (t--) {
		cin >> n;
		printf("%d\n", ans[n - 1]);
	}
	return 0;
}

