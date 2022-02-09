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

const int N = 500 + 9, M = 10 + 9;
const int Mod_M = 1e8;

ll mat[N][N];
int n, sorted[N];
bool vis[N];
stack<ll> ans;
void floyed() {
	for (int idx = 0; idx < n; ++idx) {
		int k = sorted[idx];
		vis[k] = 1;
		ll res = 0;
		for (int a = 0; a < n; ++a)
			for (int b = 0; b < n; ++b) {
				auto newpath = mat[a][k] + mat[k][b];
				if (newpath < mat[a][b]) mat[a][b] = newpath;
				if (vis[a] && vis[b]) res += mat[a][b];
			}
		ans.push(res);
	}
}

void solve() {
	memset(mat, '?', sizeof mat);
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> mat[i][j];
	for (int i = n - 1; ~i; --i) {
		cin >> sorted[i];
		sorted[i]--;
	}
	floyed();
	bool flag = 0;
	while (!ans.empty()) {
		if (flag) cout << " ";
		cout << ans.top();
		flag = 1;
		ans.pop();
	}
	cout << endl;
}
int main() {
	_init_();

	solve();

	return 0;
}
