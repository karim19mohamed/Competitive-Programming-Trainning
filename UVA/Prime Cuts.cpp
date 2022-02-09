#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 1000 + 9, M = 1073741824;
vector<int> ranges(N);
vector<int> sieve(int n) {
	vector<bool> is_prime(n + 1, true);
	vector<int> prime;
	prime.push_back(1);
	ranges[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (!is_prime[i]) {
			ranges[i] = prime.size();
			continue;
		} else {
			prime.push_back(i);
			for (int j = 2; i * j <= n; ++j) {
				is_prime[i * j] = 0;
			}
		}
		ranges[i] = prime.size();
	}
	return prime;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);
#endif
	int n, c;
	vector<int> prime = sieve(N);
	while (cin >> n >> c) {
		int sz = ranges[n], cnt, center;
		center = (sz % 2) ? sz / 2 - c + 1 : sz / 2 - c;
		cnt = (sz % 2) ? 2 * c - 1 : 2 * c;
		//dbg3(sz, center, cnt);
		printf("%d %d:", n, c);
		if (center < 0)
			center = 0, cnt = sz;
		for (int i = center; i < center + cnt; ++i)
			printf(" %d", prime[i]);
		printf("\n\n");
	}

	return 0;
}

