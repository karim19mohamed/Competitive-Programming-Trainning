#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 100 + 9, M = 400 - 9;
const ll Mod_M = 1e9 + 7;

int t, n, a, b, c, ans[N], cs = 1;
bool chk() {
	int cnt_a = 0, cnt_b = 0, c_arr[N];
	int mx_a = 0, mx_b = 0;
	memset(c_arr, 0, sizeof c_arr);

	for (int i = 0; i < n; ++i)
		if (ans[i] >= mx_a)
			mx_a = ans[i], ++cnt_a, ++c_arr[i];
	for (int i = n - 1; i >= 0; --i)
		if (ans[i] >= mx_b)
			mx_b = ans[i], ++cnt_b, ++c_arr[i];
	int cnt_c = count(c_arr, c_arr + n, 2);
	return (cnt_a == a && cnt_b == b && cnt_c == c);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);
#endif
	cin >> t;
	while (t--) {
		cin >> n >> a >> b >> c;
		for (int i = 0; i < n; ++i)
			ans[i] = 1;
		for (int i = 0; i < a - c; ++i)
			ans[i] = n - 1;
		for (int i = a - c; i < a; ++i)
			ans[i] = n;
		int cnt_ones = count(ans, ans + n, 1);
		if (cnt_ones < b - c && !chk()) {
			printf("Case #%d: IMPOSSIBLE\n", cs++);
			continue;
		}

		bool flag = 0;
		for (int i = 0; i < b - c; ++i)
			ans[n - 1 - i] = n - 1, flag = 1;
		if (!flag && n != 1 && !chk()) {
			if (a > 1) {
				swap(ans[n - 1], ans[a - 1]);
			} else {
				printf("Case #%d: IMPOSSIBLE\n", cs++);
				continue;
			}
		}
		if (chk()) {
			printf("Case #%d:", cs++);
			for (int i = 0; i < n; ++i)
				printf(" %d", ans[i]);
			puts("");
		} else {
			printf("Case #%d: IMPOSSIBLE\n", cs++);
		}
	}
	return 0;
}

