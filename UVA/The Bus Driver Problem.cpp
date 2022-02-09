#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 100 + 9;

int main() {
	int n, d, r, morning[N], evening[N];
	while (scanf("%d %d %d", &n, &d, &r) && n + d + r) {
		for (int i = 0; i < n; ++i)
			scanf("%d", &morning[i]);
		for (int i = 0; i < n; ++i)
			scanf("%d", &evening[i]);
		sort(morning, morning + n);
		sort(evening, evening + n, greater<int>());
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (morning[i] + evening[i] > d)
				ans += (r * (morning[i] + evening[i] - d));
		}
		printf("%d\n", ans);
	}
	return 0;
}

