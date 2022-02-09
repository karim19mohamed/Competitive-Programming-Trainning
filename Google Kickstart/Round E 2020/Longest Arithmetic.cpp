#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 2e5 + 9, M = 400 - 9;
const ll Mod_M = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif
	int t, n, a[N], cs = 1;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int ans = 0, tmp = 2, curr = a[1] - a[0];
		for (int i = 2; i < n; ++i) {
			if (a[i] - a[i - 1] == curr) {
				++tmp;
			} else {
				ans = max(ans, tmp);
				tmp = 2, curr = a[i] - a[i - 1];
			}
			//dbg2(tmp, curr);
		}
		ans = max(ans, tmp);
		printf("Case #%d: %d\n", cs++, ans);
	}
	return 0;
}

