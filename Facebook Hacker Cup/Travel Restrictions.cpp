#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 50 + 9, M = 20 + 9;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("travel_restrictions_input.txt", "rt", stdin);
	freopen("output.out", "wt", stdout);
#endif
	int t, n, cs = 1;
	string I, O;
	char ans[N][N];
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> I >> O;
		printf("Case #%d: \n", cs++);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				ans[i][j] = 'N';
		for (int i = 0; i < n; ++i) {
			ans[i][i] = 'Y';
			int j = i + 1, transit = i;
			while (j < n) {
				if (O[transit] == 'Y' && I[j] == 'Y') {
					ans[i][j] = ans[transit][j] = 'Y';
				} else {
					break;
				}
				transit = j;
				j = j + 1;
			}
			j = i - 1, transit = i;
			while (j >= 0) {
				if (O[transit] == 'Y' && I[j] == 'Y') {
					ans[i][j] = ans[transit][j] = 'Y';
				} else {
					break;
				}
				transit = j;
				j = j - 1;
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				printf("%c", ans[i][j]);
			}
			puts("");
		}
	}
	return 0;
}

