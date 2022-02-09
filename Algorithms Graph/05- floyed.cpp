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
#define OO 1e9

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

const int N = 128 + 9, M = 1e9 - 9;
const int Mod_M = 1e9 + 7;

int mat[N][N], mnk[N][N], n;
void floyed() {
	for (int k = 0; k < n; ++k)
		for (int a = 0; a < n; ++a)
			for (int b = 0; b < n; ++b) {
				auto newpath = mat[a][k] + mat[k][b];
				if (newpath < mat[a][b]) mat[a][b] = newpath, mnk[a][b] = k;
			}
}
void printpathUtil(char a, char b) {
	if (mnk[a][b] == -1) return;
	char k = mnk[a][b];
	printpathUtil(a, k);
	printf(" %c", k);
	printpathUtil(k, b);
}
void printpath(char a, char b) {
	printf("%c", a);
	printpathUtil(a, b);
	printf(" %c", b);
}

void solve() {
	memset(mat, '?', sizeof mat);
	memset(mnk, -1, sizeof mnk);
	n = 128;
	int m;
	scanf("%d", &m);
	while (m--) {
		char a, b;
		int c;
		scanf(" %c %c %d", &a, &b, &c);
		mat[a][b] = mat[b][a] = min(c, mat[a][b]);
	}
	floyed();
	char ans;
	int d = OO;
	for (int i = 0; i < n; ++i)
		if (mat[i]['Z'] < d && i < 'Z') d = mat[i]['Z'], ans = i;
	printf("%c %d\n", ans, d);
	printpath(ans, 'Z');
}
int main() {
	_init_();

	solve();

	return 0;
}
