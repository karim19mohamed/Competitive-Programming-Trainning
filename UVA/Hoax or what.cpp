#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

using namespace std;
const int N = 5000 + 9;

int main() {
	int n;
	while (scanf("%d", &n) && n) {
		int bills;
		ll tmp;
		ll ans = 0;
		multiset<ll> q;
		multiset<ll>::reverse_iterator it1;
		multiset<ll>::iterator it2;
		while (n--) {
			scanf("%d", &bills);
			for (int i = 0; i < bills; ++i) {
				scanf("%lld", &tmp);
				q.insert(tmp);

			}
			it2 = q.begin();
			it1 = q.rbegin();
			ans += *it1 - *it2;
			q.erase(it2);
			q.erase(--q.end());
		}
		printf("%lld\n", ans);

	}
	return 0;
}

