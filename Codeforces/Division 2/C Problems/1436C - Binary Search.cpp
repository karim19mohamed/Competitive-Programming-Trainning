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
//	freopen("output.out", "wt", stdout);
#endif
}

const int N = 1e3 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

int track[N];
int n, x, pos;
void binarysearch_tack() {
	int left = 0, right = n;
	while (left < right) {
		int mid = (left + right) / 2;
//		dbg(mid);
		(mid <= pos) ? left = mid + 1 : right = mid;
		if (mid < pos) track[mid] = -1;
		else if (mid > pos) track[mid] = 1;
	}
//	dbg(left);
}

void solve() {
	scanf("%d%d%d", &n, &x, &pos);
	binarysearch_tack();
	ll ans = 1, less = x - 1, greater = n - x, all = n - 1;
	for (int i = 0; i < n; ++i) {
		if (track[i] == -1) {
			ans = (ans * less) % Mod_M;
			--less;
			--all;
		} else if (track[i] == 1) {
			ans = (ans * greater) % Mod_M;
			--greater;
			--all;
		}

	}
	for (int i = 1; i <= all; ++i) {
		ans = (ans * i) % Mod_M;
	}
	printf("%lld\n", ans);
}
int main() {
	_init_();
//	int t;
//	scanf("%d", &t);
//	while (t--) {
	solve();
//	}
	return 0;
}
