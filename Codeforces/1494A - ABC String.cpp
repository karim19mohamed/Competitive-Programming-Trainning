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
	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
#endif
}

const int N = 50 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

bool chk(bool bracket[], char s[]) {
	stack<char> stk;
	for (int i = 0; s[i]; ++i) {
		int c = s[i] - 'A';
		if (bracket[c] == 0) {
			stk.push('(');
		} else {
			if (stk.empty()) return 0;
			stk.pop();
		}
	}
	if (!stk.empty()) return 0;
	return 1;
}

void solve() {
	char s[N];
	scanf("%s", s);
	bool ans = 0;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k) {
				bool bracket[] = { i, j, k };
				ans |= chk(bracket, s);
			}
	(ans) ? puts("YES") : puts("NO");
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

