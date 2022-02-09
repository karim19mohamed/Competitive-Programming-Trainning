#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 2 * 100000 + 9;
int t, n, arr[N], cs = 1;
int solve(int curr, int idx, int brek) {
	if (idx == n) {
		return brek;
	}
	int ans = N;
	if (arr[idx - 1] < arr[idx] && curr < 3) {
		ans = min(ans, solve(curr + 1, idx + 1, brek));
	} else if (arr[idx - 1] > arr[idx] && curr > 0) {
		ans = min(ans, solve(curr - 1, idx + 1, brek));
	} else if (arr[idx - 1] == arr[idx]) {
		ans = min(ans, solve(curr, idx + 1, brek));
	} else {
		for (int i = 0; i < 4; ++i) {
			ans = min(ans, solve(i, idx + 1, brek + 1));
			//dbg4(curr, arr[idx - 1], arr[idx], ans);
		}
	}
	return ans;
}

int main() {

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &arr[i]);
		int ans = N;
		for (int i = 0; i < 4; ++i)
			ans = min(ans, solve(i, 1, 0));
		printf("Case #%d: %d\n", cs++, ans);
	}
	return 0;
}

