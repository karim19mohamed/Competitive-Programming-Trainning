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

void solve() {
	priority_queue<pair<ll, ll>> q;
	int n;
	ll k, a, b;
	scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%lld%lld", &a, &b);
		q.push( { -a, -b });
	}
	ll st = -q.top().F;
	ll ans = 1;
	while (!q.empty()) {
		a = -q.top().F, b = -q.top().S;
		if (b <= st + k) {
			q.pop();
		} else if (st + k >= a) {
			q.pop();
			ll num = ceil(((b - (st + k)) * 1.0) / (k * 1.0));
			ans += num;
			st = st + num * k;
			//dbg3(ans, num, st);
		} else {
			++ans;
			st = -q.top().F;
		}
		//dbg4(ans, st, a, b);
	}
	printf(" %lld", ans);
}
int main() {
	_init_();
	int t, cs = 1;
	scanf("%d", &t);
	while (t--) {
		printf("Case #%d:", cs++);
		solve();
		puts("");
	}
	return 0;
}