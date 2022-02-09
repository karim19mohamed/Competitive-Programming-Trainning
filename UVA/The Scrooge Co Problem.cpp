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

const int N = 99 + 9, M = 1e9 - 9;
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
map<string, int> m;
map<int, string> place;
void printpathUtil(int a, int b) {
	if (mnk[a][b] == -1) return;
	int k = mnk[a][b];
	printpathUtil(a, k);
	printf(" %s", place[k].c_str());
	printpathUtil(k, b);
}
void printpath(int a, int b) {
	printf("%s", place[a].c_str());
	printpathUtil(a, b);
	printf(" %s\n", place[b].c_str());
}

void solve() {
	memset(mat, '?', sizeof mat);
	memset(mnk, -1, sizeof mnk);
	scanf("%d", &n);
	char tmp[39];
	for (int i = 0; i < n; ++i) {
		scanf("%s", tmp);
		m[tmp] = i;
		place[i] = tmp;
	}
	int c;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &c);
			if (c != -1) mat[i][j] = c;
		}
	}
	floyed();
	int mtraveler;
	scanf("%d", &mtraveler);
	while (mtraveler--) {
		char emp[39], p1[39], p2[39];
		scanf("%s%s%s", emp, p1, p2);
		int cost = mat[m[p1]][m[p2]];
		if (cost > 1e6) {
			printf("Sorry Mr %s you can not go from %s to %s\n", emp, p1, p2);
		} else {
			printf("Mr %s to go from %s to %s, you will receive %d euros\n", emp, p1, p2, cost);
			printf("Path:");
			printpath(m[p1], m[p2]);
		}
	}
	m.clear();
	place.clear();
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
