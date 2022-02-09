#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

using namespace std;
const int N = 1000 + 9;

int main() {
	int n, a[N][2];
	while (scanf("%d", &n) && n) {
		vector<int> ans(N, 0);
		bool tmp = 1;
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &a[i][0], &a[i][1]);
			int pos = i + 1 + a[i][1];
			if (pos < 1 || pos > n || ans[pos])
				tmp = 0;
			else
				ans[pos] = a[i][0];
		}
		for (int i = 1; i <= n; ++i) {
			if (!ans[i]) {
				tmp = 0;
				break;
			}
		}
		if (!tmp) {
			puts("-1");
			continue;
		}
		for (int i = 1; i <= n; ++i) {
			if (i - 1)
				printf(" ");
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}

