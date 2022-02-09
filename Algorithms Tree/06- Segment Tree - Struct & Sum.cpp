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

const int N = 1e5 + 9, SEG = 262144; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e8;

int n, arr[N];
struct node {
	int best;

	node(int val) {
		best = val;
	}
	node() {
		best = 0;
	}

} seg[SEG];
node operator+(const node &lf, const node &rt) {
	node ret;
	ret.best = lf.best + rt.best;
	return ret;
}

void build(int si = 0, int ss = 0, int se = n - 1) {
	if (ss == se) {
		seg[si] = node(arr[ss]);
		return;
	}

	int mid = (se + ss) / 2, lf = 2 * si + 1, rt = lf + 1;
	build(lf, ss, mid);
	build(rt, mid + 1, se);

	seg[si] = (seg[lf] + seg[rt]);
}

void update(int qi, int val, int si = 0, int ss = 0, int se = n - 1) {
	if (ss == se) {
		arr[ss] = val;
		seg[si] = node(val);
		return;
	}
	if (qi < ss || qi > se) return;

	int mid = (se - ss) / 2, lf = 2 * si + 1, rt = lf + 1;
	update(qi, val, lf, ss, mid);
	update(qi, val, rt, mid + 1, se);

	seg[si] = (seg[lf] + seg[rt]);
}

node query(int qs, int qe, int si = 0, int ss = 0, int se = n - 1) {
	// [qs   ss se   qe]
	if (qs <= ss && qe >= se) return seg[si];
	// [qs qe   ss se] || [ss se   qs qe]
	if (qe < ss || qs > se) return node();

	int mid = (se + ss) / 2, lf = 2 * si + 1, rt = lf + 1;
	return query(qs, qe, lf, ss, mid) + query(qs, qe, rt, mid + 1, se);
}

void solve() {

}
int main() {
	_init_();

	solve();

	return 0;
}
