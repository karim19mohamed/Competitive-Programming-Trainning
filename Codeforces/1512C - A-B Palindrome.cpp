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

const int N = 2e5 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

void solve() {
	int a, b;
	char s[N];
	scanf("%d%d%s", &a, &b, s);
	int sz = a + b;
	int st = 0, en = sz - 1;
	while (st < en) {
		if (s[st] == '1' && s[en] == '1') b -= 2;
		else if (s[st] == '0' && s[en] == '0') a -= 2;
		else if (s[st] == '1' && s[en] == '?') s[en] = '1', b -= 2;
		else if (s[st] == '?' && s[en] == '1') s[st] = '1', b -= 2;
		else if (s[st] == '0' && s[en] == '?') s[en] = '0', a -= 2;
		else if (s[st] == '?' && s[en] == '0') s[st] = '0', a -= 2;
		++st, --en;
	}

	st = 0, en = sz - 1;
	while (st < en) {
		if (s[st] == '?' && s[en] == '?') {
			if (a - 2 >= 0) {
				a -= 2;
				s[st] = '0', s[en] = '0';
			} else {
				b -= 2;
				s[st] = '1', s[en] = '1';
			}
		}
		++st, --en;
	}
	if (sz % 2) {
		int mid = sz / 2;
		if (s[mid] == '?') {
			if (a - 1 >= 0) {
				a--, s[mid] = '0';
			} else {
				b--, s[mid] = '1';
			}
		} else if (s[mid] == '0') {
			a--;
		} else {
			b--;
		}
	}
	bool palindrome = 1;
	st = 0, en = sz - 1;
	while (st < en) {
		if (s[st] != s[en]) {
			palindrome = 0;
			break;
		}
		++st, --en;
	}
	if (a < 0 || b < 0 || !palindrome) {
		puts("-1");
	} else {
		printf("%s\n", s);
	}

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

