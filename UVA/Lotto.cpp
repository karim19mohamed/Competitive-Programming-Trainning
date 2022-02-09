#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

using namespace std;
const int N = 13 + 9;
int num[N], ans[6];
int k;
void solve(int idx, int idx2) {
	if (idx2 == 6) {
		printf("%d", ans[0]);
		for (int i = 1; i < 6; ++i)
			printf(" %d", ans[i]);
		puts("");
		return;
	}
	if (idx == k)
		return;
	ans[idx2] = num[idx];
	solve(idx + 1, idx2 + 1);
	solve(idx + 1, idx2);
}

int main() {
	bool flag = 0;
	while (scanf("%d", &k) && k) {
		if (flag)
			puts("");
		for (int i = 0; i < k; ++i)
			scanf("%d", &num[i]);
		solve(0, 0);
		flag = 1;
	}
	return 0;
}

