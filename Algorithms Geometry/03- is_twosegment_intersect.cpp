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

const int N = 1000 + 9, M = 2e5 - 9;
const int Mod_M = 1e9 + 7;

bool is_p_On_segment(point st, point en, point p) {
	return min(st.X, en.X) <= p.X && p.X <= max(st.X, en.X) && min(st.Y, en.Y) <= p.Y && p.Y <= max(st.Y, en.Y);
}
int three_points_orientation(point st, point en, point p) {
	int val = (en.Y - st.Y) * (p.X - en.X) - (p.Y - en.Y) * (en.X - st.X);
	if (val == 0) return 0; //colinear
	return (val > 0) ? 1 : 2; // 1->clockwise & 2->counterclockwise
}
bool is_twosegment_intersect(point st1, point en1, point st2, point en2) {
	// (st1, en1, st2) and (st1, en1, st2) have different orientations and
	// (st2, en2, st1) and (st2, en2, en1) have different orientations
	int o1 = three_points_orientation(st1, en1, st2);
	int o2 = three_points_orientation(st1, en1, en2);
	int o3 = three_points_orientation(st2, en2, st1);
	int o4 = three_points_orientation(st2, en2, en1);
	// if crossing each others
	if (o1 != o2 && o3 != o4) return true;
	// colinear conditions
	if (o1 == 0 && is_p_On_segment(st1, en1, st2)) return true;
	if (o2 == 0 && is_p_On_segment(st1, en1, st2)) return true;
	if (o3 == 0 && is_p_On_segment(st2, en2, st1)) return true;
	if (o4 == 0 && is_p_On_segment(st2, en2, en1)) return true;
	return false;
}

void solve() {
	point st(1, 3), en(4, 3), st2(3, 4), en2(3, 1);
	cout << is_twosegment_intersect(st, en, st2, en2) << endl;
}
int main() {
	_init_();
	solve();

	return 0;
}

