#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
#endif
}

const int N = 2e5 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

vector<ll> all;
void generate() {
	for (int i = 0; i < 1e5; ++i) {
		ll a = i + 1;
		if ((a * a - 1) % 2 == 0) {
			ll b = (a * a - 1) / 2;
			ll c = b + 1;
			if (c * c == a * a + b * b) all.push_back(c);
		}
	}
}
int binarysearch2(int num) { // TTTTTTTTTFFFF
	int s = 0, e = all.size() - 1;
	while (s < e) {
		int mid = s + (e - s + 1) / 2;
		(all[mid] > num) ? e = mid - 1 : s = mid;
	}
	return s;
}

void solve() {
	int n;
	scanf("%d", &n);
	int ans = binarysearch2(n);
	printf("%d\n", ans);
}

int main() {
	_init_();
	generate();
//	dbg(all.size());
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}

