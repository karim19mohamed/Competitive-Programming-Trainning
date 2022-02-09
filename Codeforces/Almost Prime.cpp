#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 100000 + 9;

set<int> prime_factorization(int num) { //O(sqrt(n))
	set<int> v;
	for (int i = 2; i * i <= num; ++i) {
		if (num % i == 0)
			v.insert(i);
		while (num % i == 0)
			num /= i;
	}
	if (num != 1)
		v.insert(num);
	return v;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);
#endif
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 6; i <= n; ++i) {
		set<int> prime = prime_factorization(i);
		if (prime.size() == 2) {
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}

