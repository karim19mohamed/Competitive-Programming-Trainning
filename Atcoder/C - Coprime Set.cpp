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

const int N = 2e4 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

int n;
vector<int> ans;

ll GCD(ll a, ll b) { // a>b
	if (b == 0) return a;
	return GCD(b, a % b);
}

bool checker() {
	for (int i = 0; i < int(ans.size()); ++i) {
		for (int j = i + 1; j < int(ans.size()); ++j) {
			ll gcd;
			if (ans[i] > ans[j]) gcd = GCD(ans[i], ans[j]);
			else if (ans[i] < ans[j]) gcd = GCD(ans[j], ans[i]);
			else {
				dbg2(ans[i], ans[j]);
				return false;
			}

			if (gcd == 1) {
				return false;
			}
		}
	}
	ll gcd = ans[0];
	for (int i = 1; i < int(ans.size()); ++i) {
		gcd = GCD(gcd, ans[i]);
	}

	return gcd == 1;
}
void solve() {
	scanf("%d", &n);
	ans.push_back(6);
	ans.push_back(10);
	ans.push_back(15);
	for (int i = 16; i < 10001; ++i)
		if (GCD(i, 6) > 1 && GCD(i, 10) > 1 && GCD(i, 15) > 1) ans.push_back(i);

//	dbg(ans.size());
//	dbg(checker());
	for (int i = 0; i < n; ++i)
		printf("%d%c", ans[i], " \n"[i == int(ans.size()) - 1]);
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

