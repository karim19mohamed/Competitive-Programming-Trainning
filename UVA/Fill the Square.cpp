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

const int N = 10 + 9, M = 28 - 9;
int n;
vector<string> grid;
bool outofbound(int x, int y, int n, int m) {
	return !(x >= 0 && x < n && y >= 0 && y < m);
}

void flood() {
	bool f[M];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] != '.') continue;
			memset(f, 0, sizeof f);
			for (int k = 0; k < 4; ++k) {
				int newi = i + d4i[k], newj = j + d4j[k];

				if (outofbound(newi, newj, n, n) || grid[newi][newj] == '.') continue;
				char c = grid[newi][newj];

				f[c - 'A'] = 1;
			}
			for (int k = 0; k < M; ++k)
				if (!f[k]) {
					grid[i][j] = 'A' + k;
					break;
				}
		}
	}
}

void solve() {

	scanf("%d", &n);
	char tmp[N];
	for (int i = 0; i < n; ++i) {
		scanf("%s", tmp);
		grid.push_back(tmp);
	}
	flood();
	for (int i = 0; i < n; ++i) {
		printf("%s\n", grid[i].c_str());
	}
	grid.clear();
}
int main() {
	_init_();
	int t, cs = 1;
	scanf("%d", &t);
	while (t--) {
		printf("Case %d:\n", cs++);
		solve();
	}
	return 0;
}
