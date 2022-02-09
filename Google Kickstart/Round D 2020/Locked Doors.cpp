#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 2 * 100000 + 9;

int main() {
	int t, n, q, stat, steps, arr[N], cs = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &q);
		for (int i = 0; i < n - 1; ++i)
			scanf("%d", &arr[i]);
		printf("Case #%d:", cs++);
		for (int i = 0; i < q; ++i) {
			scanf("%d %d", &stat, &steps);
			int pt_back = stat - 2, pt_for = stat - 1;
			--steps;
			int ans = stat;
			while (steps--) {
				if (pt_back < 0) {
					ans = pt_for + 2;
					++pt_for;
					continue;
				}
				if (pt_for >= n - 1) {
					ans = pt_back + 1;
					--pt_back;
					continue;
				}
				if (arr[pt_back] < arr[pt_for] && pt_back >= 0) {
					ans = pt_back + 1;
					--pt_back;
				} else if (arr[pt_back] > arr[pt_for] && pt_for <= n - 1) {
					ans = pt_for + 2;
					++pt_for;
				}
				//dbg3(ans, arr[pt_back], arr[pt_for]);
			}
			printf(" %d", ans);
		}
		puts("");
	}
	return 0;
}

