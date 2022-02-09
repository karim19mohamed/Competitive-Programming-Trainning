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

const int N = 1e4 + 9, M = 1e4 + 9;
const int Mod_M = 1e9 + 7;

string str, pat;

int dp[N][M], vis[N][M], vid;
int rec_match(int idx = 0, int patidx = 0) {
	if (idx == (int) str.size()) {
		return patidx;
	}
	int& ret = dp[idx][patidx];
	if (vis[idx][patidx] == vid) return ret;

	vis[idx][patidx] = vid;
	ret = 1 + rec_match(idx + 1, patidx);
	if (str[idx] == pat[patidx]) ret = min(ret, rec_match(idx + 1, (patidx + 1) % (int) pat.size()));
	return ret;
}

void solve() {
	getline(std::cin, str);
	getline(std::cin, pat);
	++vid;
	int ans = rec_match();
	cout << ans << endl;
}
int main() {
	_init_();
	int t;
	string tmp;
	cin >> t;
	//scanf("%d", &t);
	getline(std::cin, tmp);
	while (t--) {
		solve();
	}

	return 0;
}
