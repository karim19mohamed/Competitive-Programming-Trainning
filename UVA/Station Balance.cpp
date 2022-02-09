#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 10 + 9;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
	freopen("output.out", "wt", stdout);
#endif
	int c, s, cs = 1;
	ll arr[N];
	while (cin >> c >> s) {
		double imbalance = 0.0, avg = 0.0;
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < s; ++i) {
			cin >> arr[i];
			avg += arr[i];
		}
		avg /= (1.0 * c);
		sort(arr, arr + 2 * c);
		printf("Set #%d\n", cs++);
		for (int i = 0; i < c; ++i) {
			if (i < 10)
				printf(" ");
			printf("%d:", i);
			if (arr[i])
				printf(" %lld", arr[i]);
			if (arr[2 * c - i - 1])
				printf(" %lld", arr[2 * c - i - 1]);
			imbalance += abs(arr[i] + arr[2 * c - i - 1] - avg);
			puts("");
		}
		printf("IMBALANCE = %.5lf\n\n", imbalance);
	}
	return 0;
}

