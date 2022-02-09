#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 1000 + 9;
int vis[N], idx;

int main() {
	int t, n, a[N];
	scanf("%d", &t);
	queue<string> q;
	while (t--) {
		scanf("%d", &n);
		int ans = 0;
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		sort(a, a + n);
		if (n == 1) {
			printf("%d\n%d\n", a[0], a[0]);
		} else if (n == 2) {
			printf("%d\n%d %d\n", a[1], a[0], a[1]);
		} else {
			int idx = (n % 2);
			q.push(to_string(a[0]) + " " + to_string(a[1]));
			ans += a[1];
			for (int i = n - 1; i >= 2 + idx; i -= 2) {
				int num1 = a[i] + a[1] + a[1] + a[0];
				int num2 = a[i] + a[i - 1] + a[0] + a[0];
				if (num1 < num2) {
					ans += num1;
					q.push(to_string(a[0]));
					q.push(to_string(a[i - 1]) + " " + to_string(a[i]));
					q.push(to_string(a[1]));
					q.push(to_string(a[0]) + " " + to_string(a[1]));
				} else {
					ans += num2;
					q.push(to_string(a[0]));
					q.push(to_string(a[i]) + " " + to_string(a[0]));
					q.push(to_string(a[0]));
					q.push(to_string(a[i - 1]) + " " + to_string(a[0]));
				}
			}
			if (idx) {
				ans += a[2] + a[0];
				q.push(to_string(a[0]));
				q.push(to_string(a[0]) + " " + to_string(a[2]));
			}
			printf("%d\n", ans);
			while (!q.empty()) {
				cout << q.front() << endl;
				q.pop();
			}
		}
		if (t)
			puts("");
	}
	return 0;
}

