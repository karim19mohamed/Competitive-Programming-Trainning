#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int n, m;
	ll cs = 1;
	map<ll, ll> a;
	while (scanf("%d %d", &n, &m) && n + m) {
		int num, ans = 0;
		for (int i = 0; i < n; ++i)
			scanf("%d", &num), a[num] = cs;
		for (int i = 0; i < m; ++i) {
			scanf("%d", &num);
			if (a[num] == cs)
				++ans;
		}
		printf("%d\n", ans);
		++cs;
	}

	return 0;
}

