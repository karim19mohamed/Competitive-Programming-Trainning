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

void _init_() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//	freopen("output.out", "wt", stdout);
#endif
}

const int N = 3e4 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

vector<ll> m;
void dp() {
	for (ll i = 1; i < 10001; ++i) {
		ll num = i * i * i;
		m.push_back(num);
	}
}
bool binarysearch2(ll num) { // TTTTTTTTTFFFF
	int s = 0, e = m.size() - 1;
	while (s < e) {
		int mid = s + (e - s + 1) / 2;
		(m[mid] > num) ? e = mid - 1 : s = mid;
	}
	return m[s] == num;
}

void solve() {
	ll n;
	scanf("%lld", &n);
	bool ans = 0;
	for (int i = 0; i < (int) m.size(); ++i) {
		ll b = n - m[i];
		if (binarysearch2(b)) {
			ans = 1;
			break;
		}
	}
	(ans) ? puts("YES") : puts("NO");

}

int main() {
	_init_();
	dp();
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}

