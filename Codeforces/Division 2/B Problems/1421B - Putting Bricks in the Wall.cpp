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

const int N = 200 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e8;

int n;
char a[N][N];

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%s", a[i]);
	vector<pair<int, int>> ans;
	if (a[1][0] == a[0][1]) {
		if (a[n - 1][n - 2] == a[1][0]) ans.push_back( { n - 1, n - 2 });
		if (a[n - 2][n - 1] == a[1][0]) ans.push_back( { n - 2, n - 1 });
	} else if (a[n - 1][n - 2] == a[n - 2][n - 1]) {
		if (a[1][0] == a[n - 1][n - 2]) ans.push_back( { 1, 0 });
		if (a[0][1] == a[n - 1][n - 2]) ans.push_back( { 0, 1 });
	} else {
		(a[1][0] != '0') ? ans.push_back( { 1, 0 }) : ans.push_back( { 0, 1 });
		(a[n - 1][n - 2] != '1') ? ans.push_back( { n - 1, n - 2 }) : ans.push_back( { n - 2, n - 1 });
	}
	printf("%d\n", (int) ans.size());
	for (int i = 0; i < (int) ans.size(); ++i) {
		printf("%d %d\n", ans[i].F + 1, ans[i].S + 1);
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
