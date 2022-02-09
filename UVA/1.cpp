#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 5 * 100000 + 9;
int vis[N], idx;

int main() {
	int n, a[N];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int small = 0, ans1 = 1;
	++idx;
	for (int i = 1; i < n && small < n; ++i) {
		if (a[small] * 2 <= a[i]) {
			vis[small] = vis[i] = idx;
			while (vis[small] == idx && small < n)
				++small;
		} else {
			++ans1;
		}
	}
	int big = n - 1, ans2 = 1;
	++idx;
	for (int i = n - 2; i >= 0 && big >= 0; --i) {
		if (a[i] * 2 <= a[big]) {
			vis[big] = vis[i] = idx;
			while (vis[big] == idx && big >= 0)
				--big;
		} else {
			++ans2;
		}
	}
	//dbg2(ans1, ans2);
	printf("%d\n", min(ans1, ans2));
	return 0;
}

