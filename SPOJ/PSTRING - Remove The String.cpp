#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<double> point;
#define endl '\n'
#define f first
#define s second
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

template<typename T_n> void read(T_n &n) {
	cin >> n;
}
template<typename T_n, typename T_a> void read(T_a a[], T_n n) {
	for (int i = 0; i < n; ++i)
		cin >> a[i];
}
template<typename T_n, typename T_a> void read(vector<T_a> &a, T_n n) {
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
}
void _init_() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);
#endif
}

const int N = 1e4 + 9, M = 1e3 + 9;
const int Mod_M = 1e9 + 7;

int f[M];
char str[N], pat[M];

int dpl[N][128], visl[N][128], vidl;
int getnewlen(int len, char c) {
	if (c == pat[len]) return len + 1;
	if (!len) return 0;

	int& ret = dpl[len][c];
	if (visl[len][c] == vidl) return ret;
	visl[len][c] = vidl;

	ret = getnewlen(f[len - 1], c);

	return ret;
}

void computef() {
	f[0] = 0;
	for (int i = 1; pat[i]; ++i)
		f[i] = getnewlen(f[i - 1], pat[i]);
}

void printffunction() {
	for (int i = 0; pat[i]; ++i)
		printf("%d ", f[i]);
	puts("");
}

int dp[N][M], vis[N][M], vid;
int tmp = 0;
int match_rec(int idx = 0, int len = 0) {
	if (!str[idx]) return 0;

	int& ret = dp[idx][len];
	if (vis[idx][len] == vid) return ret;
	vis[idx][len] = vid;

	ret = 1 + match_rec(idx + 1, len);
	int newlen = getnewlen(len, str[idx]);
	if (pat[newlen]) ret = min(ret, match_rec(idx + 1, newlen));

	return ret;
}

vector<int> match_pos() {
	vector<int> ret;
	int len = 0;
	for (int i = 0; str[i]; ++i) {
		len = getnewlen(len, str[i]);
		if (!pat[len]) ret.push_back(i - len + 1);
	}
	return ret;
}

void solve() {
	while (scanf("%s %s", str, pat) == 2) {
		++vid, ++vidl;
		computef();
		int ans = match_rec();
		printf("%d\n", ans);
	}
}
int main() {
	_init_();
	solve();
	return 0;
}
