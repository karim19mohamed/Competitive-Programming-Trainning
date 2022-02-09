#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 10000 + 9;

int main() {
	int n, a[N];
	bool flag = 0;
	queue<int> q[N];
	while (scanf("%d", &n) && n) {
		if (flag)
			puts("");
		flag = 1;
		int ans = 0, tmp = 0, curr = -1;
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		sort(a, a + n);
		for (int i = 0; i < n; ++i) {
			(a[i] == curr) ? ++tmp : tmp = 1, curr = a[i];
			ans = max(ans, tmp);
		}
		printf("%d\n", ans);
		for (int i = 0; i < n; ++i) {
			q[i % ans].push(a[i]);
		}
		for (int i = 0; i < ans; ++i) {
			while (!q[i].empty()) {
				printf("%d", q[i].front());
				q[i].pop();
				if (!q[i].empty())
					printf(" ");
			}
			puts("");
		}
	}
	return 0;
}

