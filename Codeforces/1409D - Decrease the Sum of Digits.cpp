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

const int N = 18 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

int check(char n[], int s) {
	int sum = 0;
	for (int i = 0; n[i]; ++i)
		sum += n[i] - '0';
	return sum;
}

void solve() {
	char n[N];
	int s;
	scanf("%s%d", n, &s);
	int sum = check(n, s);
	ll ans = 0, ten = 1, rem = 0;
	int idx = strlen(n) - 1;
	while (sum > s) {
		int num = 0;
		if (idx < 0) {
			num = rem;
			rem = 0;
		} else {
			num = 10 - (n[idx] - '0') - rem;
			rem = 1;
			sum -= n[idx] - '0' + ((idx != int(strlen(n)) - 1) ? 1 : 0);
		}
		ans += ten * num;
//		dbg4(n[idx], ans, sum, rem);
		++sum;
		--idx;
		ten *= 10;
	}
	printf("%lld\n", ans);
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

