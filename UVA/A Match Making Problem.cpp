#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 10000 + 9, M = 60 + 9;
int vis[N], vid;

int main() {
	int n, m, cs = 1, a[N], b[N];
	priority_queue<pair<int, pair<int, int>> > q;
	while (scanf("%d %d", &n, &m) && n + m) {
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for (int i = 0; i < m; ++i)
			scanf("%d", &b[i]);
		if (n <= m) {
			printf("Case %d: 0\n", cs++);
			continue;
		}
		sort(a, a + n);
		printf("Case %d: %d %d\n", cs++, n - m, a[0]);
	}
	return 0;
}
