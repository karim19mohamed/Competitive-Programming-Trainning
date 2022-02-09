#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
	freopen("input.in", "rt", stdin);
//	freopen("output.out", "wt", stdout);
#endif
}

const int N = 1e6 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

int freq_a[200], freq_b[200];

void solve() {
	int n, k;
	char a[N], b[N];
	scanf("%d%d%s%s", &n, &k, a, b);
	for (int i = 0; i < n; ++i)
		++freq_a[a[i]], ++freq_b[b[i]];
	bool ans = 1;
	for (int i = 'a'; i <= 'z'; ++i) {
		if (freq_b[i] > freq_a[i]) {
			ans = 0;
			break;
		}
		freq_a[i] -= freq_b[i];
		int tra = (freq_a[i] / k);
		tra *= k;
		freq_a[i + 1] += tra;
	}
	(ans) ? puts("Yes") : puts("No");
	memset(freq_a, 0, sizeof freq_a);
	memset(freq_b, 0, sizeof freq_b);
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
