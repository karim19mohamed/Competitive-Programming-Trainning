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

const int N = 1e5 + 9, M = 1e5 + 9;
const int Mod_M = 1e9 + 7;

char s1[N], s2[N], ans[N];

char gen_DifChar(char a, char b) {
	char t = (a != 'z') ? a + 1 : 'a';
	if (t != b) {
		return t;
	}
	t = (b != 'z') ? b + 1 : 'a';
	return t;
}

void solve() {
	int n, t;
	scanf("%d%d%s%s", &n, &t, s1, s2);
	for (int i = 0; i < n; ++i)
		ans[i] = 'A';
	int dif1 = n, dif2 = n;
	for (int i = 0; s1[i] && dif1 > t; ++i)
		if (s1[i] == s2[i]) ans[i] = s1[i], dif1--, dif2--;
	for (int i = 0; s1[i] && dif1 > t; ++i) {
		if (ans[i] == 'A') ans[i] = s1[i], dif1--;
	}
	for (int i = 0; s2[i] && dif2 > t; ++i) {
		if (ans[i] == 'A') ans[i] = s2[i], dif2--;
	}
	for (int i = 0; i < n; ++i)
		if (ans[i] == 'A') ans[i] = gen_DifChar(s1[i], s2[i]);
	if (dif1 != t || dif2 != t) puts("-1");
	else printf("%s\n", ans);
}
int main() {
	_init_();
	solve();
	return 0;
}
