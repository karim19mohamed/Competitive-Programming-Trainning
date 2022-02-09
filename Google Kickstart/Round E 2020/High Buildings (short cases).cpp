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

int num[N], tmp[N], n, a, b, c;
bool chk() {
	int cnt_a = 0, cnt_b = 0, c_arr[N];
	int mx_a = 0, mx_b = 0;
	memset(c_arr, 0, sizeof c_arr);

	for (int i = 0; i < n; ++i)
		if (tmp[i] >= mx_a)
			mx_a = tmp[i], ++cnt_a, ++c_arr[i];
	for (int i = n - 1; i >= 0; --i)
		if (tmp[i] >= mx_b)
			mx_b = tmp[i], ++cnt_b, ++c_arr[i];
	int cnt_c = count(c_arr, c_arr + n, 2);
	//dbg3(cnt_a, cnt_b, cnt_c);
	return (cnt_a == a && cnt_b == b && cnt_c == c);
}
void solve(int idx = 0) {
	if (idx == n) {
		if (chk()) {
			for (int i = 0; i < n; ++i)
				num[i] = tmp[i];
		}
		return;
	}
	for (int i = 1; i <= n; ++i) {
		tmp[idx] = i;
		solve(idx + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif
	int t, cs = 1;
	cin >> t;
	while (t--) {
		cin >> n >> a >> b >> c;
		memset(num, 0, sizeof num);
		solve();
		if (num[0] == 0) {
			printf("Case #%d: IMPOSSIBLE\n", cs++);
			continue;
		}
		printf("Case #%d:", cs++);
		for (int i = 0; i < n; ++i)
			printf(" %d", num[i]);
		puts("");
	}
	return 0;
}

