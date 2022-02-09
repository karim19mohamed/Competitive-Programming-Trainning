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
	int t, n, a[N];
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		bool flag = 0;
		for (int i = 0; i < n; ++i) {
			if (flag)
				printf(" ");
			printf("1");
			flag = 1;
		}
		puts("");
	}
	return 0;
}

