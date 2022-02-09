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

const int N = 1e6 + 9, M = 10 + 9;
const int Mod_M = 1e9 + 7;

int f[N];
char str[N], pat[N];

int getnewlen(int len, char c) {
	while (len && c != pat[len]) {
		len = f[len - 1];
	}
	return len + (c == pat[len]);
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
	int n;
	scanf("%d %s", &n, pat);
	computef();
	for (int i = 0; i < n; ++i) {
		int len = i + 1 - f[i];
		if ((i + 1) % len == 0 && f[i]) printf("%d %d\n", i + 1, (i + 1) / len);
	}
}
int main() {
	_init_();
	int t, cs = 1;
	scanf("%d", &t);
	bool flag = 0;
	while (t--) {
		if (flag) puts("");
		printf("Test case #%d\n", cs++);
		solve();
		flag = 1;
	}
	return 0;
}
