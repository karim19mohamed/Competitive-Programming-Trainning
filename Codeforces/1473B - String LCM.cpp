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

const int N = 20 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

bool in_it(char big[], char small[], int num) {
	int idx = 0, i = 0;
	while (num) {
		if (big[idx] != small[i]) return 0;
		++idx, ++i;
		if (idx == strlen(big)) {
			idx = 0;
			--num;
		}
		if (i == strlen(small)) i = 0;
	}
	return i == 0;
}

void solve() {
	char s[N], t[N];
	scanf("%s%s", s, t);
	if (strlen(s) < strlen(t)) swap(s, t);
	bool ans_exit = 0;
	int ans;
	for (int i = 1; i <= strlen(s) * strlen(t); ++i) {
		ans_exit = in_it(s, t, i);
		if (ans_exit) {
			ans = i;
			break;
		}
	}
	if (!ans_exit) {
		puts("-1");
		return;
	}
	while (ans--)
		printf("%s", s);
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

