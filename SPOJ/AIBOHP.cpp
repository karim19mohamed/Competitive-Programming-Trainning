#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 6100 + 9, M = 61000 + 9;
string s;
bool palindrom_chk(string tmp) {
	int sz = tmp.size();
	for (int i = 0; i < (int) tmp.size() / 2; ++i)
		if (tmp[i] != tmp[sz - 1 - i])
			return 0;
	return 1;
}
int dp[N][N];
int solve(string s, int for_idx, int back_idx) {
	if (for_idx >= back_idx) {
		return 0;
	}
	int& res = dp[for_idx][back_idx];
	if (~res && res != M)
		return res;
	res = M;
	if (s[for_idx] == s[back_idx]) {
		res = min(res, solve(s, for_idx + 1, back_idx - 1));
	} else {
		res = min(res, 1 + solve(s, for_idx, back_idx - 1));
		res = min(res, 1 + solve(s, for_idx + 1, back_idx));
	}
	return res;
}
int solve_iterative(string s) {
	int n = s.size();
	int table[n][n], for_idx, back_idx;
	memset(table, 0, sizeof(table));
	for (for_idx = n - 2; for_idx >= 0; --for_idx) {
		for (back_idx = for_idx + 1; back_idx < n; ++back_idx) {
			if (s[for_idx] == s[back_idx]) {
				table[for_idx][back_idx] = table[for_idx + 1][back_idx - 1];
			} else {
				table[for_idx][back_idx] = 1
						+ min(table[for_idx + 1][back_idx],
								table[for_idx][back_idx - 1]);
			}
		}
	}
	return table[0][n - 1];
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		int ans = solve_iterative(s);
		printf("%d\n", ans);
	}
	return 0;
}

