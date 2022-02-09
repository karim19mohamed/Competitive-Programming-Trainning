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
	char s[N];
	scanf("%s", s);
	int digits[10];
	memset(digits, 0, sizeof(digits));
	int max_length = 0;
	for (int i = 0; s[i]; ++i) {
		++digits[s[i] - '0'];
	}
	for (int i = 0; i < 10; ++i) {
		max_length = max(max_length, digits[i]);
		if (digits[i] == 0) continue;
		for (int j = i + 1; j < 10; ++j) {
			int cur = -1, cnt = 0, first = 0;
			for (int idx = 0; s[idx]; ++idx) {
				int num = s[idx] - '0';
				if (cur == -1 && (num == i || num == j)) {
					if (num == i) {
						++cnt;
						cur = j;
						first = i;
					} else {
						++cnt;
						cur = i;
						first = j;
					}
				} else if (num == cur) {
					if (num == i) {
						++cnt;
						cur = j;
					} else {
						++cnt;
						cur = i;
					}
				}
			}
			if (cur != first) --cnt;
			max_length = max(max_length, cnt);
//			dbg3(i, j, cnt);
		}
	}
//	dbg2(max_length, int(strlen(s)));
	printf("%d\n", int(strlen(s)) - max_length);
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

