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

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);
#endif
	int n, k;
	cin >> n >> k;
	vector<int> prime = sieve(n);
	int cnt = 0;
	for (int i = 0; i < (int) prime.size() - 1; ++i) {
		int num = prime[i] + prime[i + 1] + 1;
		if (num <= n && is_prime[num]) {
			//dbg3(num, prime[i], prime[i + 1]);
			++cnt;
		}
		if (cnt == k)
			break;
	}
	(cnt == k) ? puts("YES") : puts("NO");
	return 0;
}

