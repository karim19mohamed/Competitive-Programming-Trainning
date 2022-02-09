#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 5 * 100000 + 9;
int vis[N], idx;

int main() {
	int n, a[N];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int pt = n / 2, ans = n;
	for (int i = 0; i < n / 2 && pt < n; ++i) {
		while (a[i] * 2 > a[pt] && pt < n) {
			++pt;
		}
		if (pt == n)
			break;
		if (a[i] * 2 <= a[pt]) {
			++pt;
			--ans;
		}
	}
	//dbg_array(a, n);
	printf("%d\n", ans);
	return 0;
}

