#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 10000 + 9, M = 60 + 9;

int main() {
	long long n, l, u, ans;
	bitset<32> a, b, c, d;
	while (scanf("%lld %lld %lld", &n, &l, &u) != EOF) {
		a = n, b = l, c = u, d = 0;
		for (int i = 31; i >= 0; --i) {
			if (d.to_ulong() < l) {
				if (b[i]) {
					d[i] = 1;
					continue;
				}
			}
			if (!a[i]) {
				d[i] = 1;
				if (d.to_ulong() > u)
					d[i] = 0;
			}
		}
		ans = d.to_ulong();
		printf("%lld\n", ans);

	}
	return 0;
}
