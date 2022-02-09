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

const int N = 1000000 + 9, M = 10 + 9;
const int Mod_M = 1e8;

int n, k;
ll p[N];

bool valid(ll mid) {
	ll sum = 0, num = 0, mx = 0;
	int group = 0;
	int i;
	for (i = 0; i < n && group < k; ++i) {
		mx = max(mx, p[i]);
		++num;
		ll tmp = mx * num;
		if (tmp <= mid) {
			sum = tmp;
		} else {
			num = 0;
			mx = 0;
			sum = 0;
			//if (sum > mid) return 0;
			++group;
			--i;
		}
	}
	//bool asda = (i == n && group <= k);
	//dbg2(mid, asda);
	return (i == n && group <= k);
}

ll binarysearch1() { // FFFFFFFTTTT
	ll s = 0, e = 1e13;
	while (s < e) {
		ll mid = s + (e - s) / 2;
		(valid(mid)) ? e = mid : s = mid + 1;
	}
	return s;
}

void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &p[i]);
	ll ans = binarysearch1();
	printf("%lld\n", ans);
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
