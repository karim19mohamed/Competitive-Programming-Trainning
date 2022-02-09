#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> point;
#define endl '\n'
#define F first
#define S second
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define dbg2(x,y) cerr<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cerr<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cerr<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define FOR(sz) for(int i = 0; i < sz; ++i)
#define dbg_array(x,sz) FOR(sz) cerr << x[i] << " \n"[i==sz-1]
#define X real()
#define Y imag()

const int d4i[4] = { -1, 0, 1, 0 }, d4j[4] = { 0, 1, 0, -1 };
const int d8i[8] = { -1, -1, 0, 1, 1, 1, 0, -1 }, d8j[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void _init_() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
#endif
}

const int N = 1e6 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

void solve() {
	int n;
	scanf("%d", &n);
	int num = (n - 1) * 3 / 2;
	bool flag = 0;
	for (int i = 0; i < n; ++i) {
		int tmp = num;
		for (int j = i + 1; j < n; ++j) {
			if (flag) printf(" ");
			if (int(tmp / 3) > 0) {
				printf("1");
				tmp -= 3;
			} else if (tmp % 3 > 0) {
				printf("0");
				tmp -= 1;
			} else {
				printf("-1");
			}
			flag = 1;
		}
	}
	puts("");
}

int main() {
	_init_();
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}

