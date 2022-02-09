#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 10 + 9, M = 20 + 9;
int n, a[N];
int dp_2d[N][M];
int solve_2d(int idx, int last) {
	if (idx < 0) {
		return 0;
	}
	int& ret = dp_2d[idx][last];
	if (~ret)
		return ret;
	ret = solve_2d(idx - 1, last);
	if (a[idx] < last) {
		ret = max(ret, 1 + solve_2d(idx - 1, a[idx]));
	}
	return ret;
}
int dp_1d[N];
int solve_1d(int idx) {
	if (idx < 0)
		return 0;

	int& ret = dp_1d[idx];
	if (~ret)
		return ret;

	ret = 1;
	for (int last = 0; last < idx; ++last)
		if (a[idx] > a[last]) {
			ret = max(ret, 1 + solve_1d(last));
		}
	return ret;
}
int dp_iter[N];
int iter() {
	for (int idx = 0; idx <= n; ++idx) {
		int& ret = dp_iter[idx];
		ret = 1;
		for (int last = 0; last < idx; ++last)
			if (a[idx] > a[last]) {
				ret = max(ret, 1 + dp_iter[last]);
			}
	}
	return dp_iter[n];
}
void prtsolve(int idx) {
	if (idx < 0)
		return;

	int ret = solve_1d(idx);
	for (int last = 0; last < idx; ++last)
		if (a[idx] > a[last] && ret == 1 + solve_1d(last)) {
			prtsolve(last);
			break;
		}
	if (a[idx] != M)
		cout << a[idx] << " ";
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif
	memset(dp_1d, -1, sizeof(dp_1d));
	memset(dp_2d, -1, sizeof(dp_2d));
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	a[n] = M;
	int ans = iter() - 1;
	printf("%d\n", ans);
	//prtsolve(n);
	return 0;
}

