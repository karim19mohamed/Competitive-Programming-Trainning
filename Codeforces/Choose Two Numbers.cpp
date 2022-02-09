#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const ll N = 100 + 9, M = 400 - 9, Max_ans = 1LL * (1e16);
int a[N], b[N];
bool vis[M];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);
#endif
	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		vis[a[i]] = 1;
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
		vis[b[i]] = 1;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!vis[a[i] + b[j]]) {
				printf("%d %d\n", a[i], b[j]);
				return 0;
			}
		}
	}
	return 0;
}

