#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg5(x,y,z,q,k) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<", "<<#k<<" = "<<k<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 3e5 + 9, M = 1e5 + 9, Max_ans = 200 * 2000 + 9;
int currency[] = { 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5 };

ll dp[11][N];
ll solve(int idx, int n) {
	if (n == 0)
		return 1;
	if (idx < 0)
		return 0;
	ll& ret = dp[idx][n];
	if (~ret)
		return ret;
	ret = solve(idx - 1, n);
	if (currency[idx] <= n)
		ret += solve(idx, n - currency[idx]);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif
	string t;
	int n, num1, num2;
	memset(dp, -1, sizeof(dp));
	while (cin >> t) {
		for (int i = 0; i < (int) t.size(); ++i)
			if (t[i] == '.')
				t[i] = ' ';
		stringstream ob(t);
		ob >> num1 >> num2;
		for (int i = 0; i < (int) t.size(); ++i)
			if (t[i] == ' ')
				t[i] = '.';
		n = num1 * 100 + num2;
		//dbg2(t, n);
		if (!n)
			break;
		ll ans = solve(10, n);
		//printf("%6.2lf%17lld\n", t, ans);
		cout << setw(6) << t << setw(17) << ans << endl;
	}
	return 0;
}

