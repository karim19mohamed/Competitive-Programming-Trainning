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

const int N = 1e5 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e8;

int n, w, wheel[N];

ll naive() {
	ll ans = LLONG_MAX;
	for (int i = 1; i <= n; ++i) {
		ll tmp = 0;
		for (int j = 0; j < w; ++j) {
			tmp += min(min(abs(i + n - wheel[j]), abs(wheel[j] + n - i)), abs(wheel[j] - i));
		}
//		dbg2(i, tmp);
		ans = min(ans, tmp);
	}
	return ans;
}
ll solve(ll i) {
	ll rt = 0;
	for (int j = 0; j < w; ++j) {
		rt += min(min(abs(i + n - wheel[j]), abs(wheel[j] + n - i)), abs(wheel[j] - i));
	}
	return rt;
}

ll binarysearch1() { // FFFFFFFTTTT
	ll s = 1, e = n;
	ll ans = LLONG_MAX;
	while (s < e) {
		ll mid = s + (e - s) / 2;
		ll tmp = solve(mid);
		if (tmp < ans) {
			e = mid;
			ans = tmp;
//			dbg(ans);
		} else {
			s = mid + 1;
		}
	}
	return ans;
}
ll binarysearch2() { // FFFFFFFTTTT
	ll s = n, e = 1;
	ll ans = LLONG_MAX;
	while (s < e) {
		ll mid = s + (e - s) / 2;
		ll tmp = solve(mid);
		if (tmp < ans) {
			e = mid;
			ans = tmp;
//			dbg(ans);
		} else {
			s = mid + 1;
		}
	}
	return ans;
}

void solve() {
	scanf("%d %d", &w, &n);
	for (int i = 0; i < w; ++i)
		scanf("%d", wheel + i);
	ll tmp = naive();
	ll ans = min(binarysearch1(), binarysearch2());
//	dbg(tmp);
	printf("%lld\n", ans);
}
int main() {
	_init_();
	int t, cs = 1;
	scanf("%d", &t);
	while (t--) {
		printf("Case #%d: ", cs++);
		solve();
	}
	return 0;
}
