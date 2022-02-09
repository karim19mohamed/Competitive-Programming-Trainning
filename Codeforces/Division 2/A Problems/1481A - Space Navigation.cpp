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

const int N = 1e5 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

/*
 * if 𝑠𝑖=U, you move to (𝑥,𝑦+1);
 if 𝑠𝑖=D, you move to (𝑥,𝑦−1);
 if 𝑠𝑖=R, you move to (𝑥+1,𝑦);
 if 𝑠𝑖=L, you move to (𝑥−1,𝑦).
 */

void solve() {
	int x, y, u = 0, d = 0, r = 0, l = 0;
	char s[N];
	scanf("%d%d%s", &x, &y, s);
	(x > 0) ? r += x : l -= x;
	(y > 0) ? u += y : d -= y;
	for (int i = 0; s[i]; ++i) {
		if (s[i] == 'U') --u;
		else if (s[i] == 'D') --d;
		else if (s[i] == 'R') --r;
		else --l;
	}
	(u <= 0 && d <= 0 && r <= 0 && l <= 0) ? puts("YES") : puts("NO");
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

