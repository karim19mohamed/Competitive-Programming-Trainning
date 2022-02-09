#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 2 * 100000 + 9;

int main() {
	int t, n, arr[N], cs = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &arr[i]);
		int ans = 0, large_pre = -1;
		for (int i = 0; i < n; ++i) {
			if (arr[i] > large_pre) {
				if (i == n - 1) {
					++ans;
				} else if (arr[i] > arr[i + 1]) {
					++ans;
				}
			}
			large_pre = max(large_pre, arr[i]);
		}
		printf("Case #%d: %d\n", cs++, ans);
	}
	return 0;
}

