#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 10 + 9, M = 400 - 9;
const ll Mod_M = 1e9 + 7;
int a[N][N];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		a[0][i] = a[i][0] = 1;
	for (int i = 1; i < n; ++i)
		for (int j = 1; j < n; ++j)
			a[i][j] = a[i - 1][j] + a[i][j - 1];
	printf("%d\n", a[n - 1][n - 1]);
	return 0;
}

