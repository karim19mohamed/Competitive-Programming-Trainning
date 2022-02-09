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

const int N = 30 + 9, M = 1000 - 9;
int arr[N], loss[N], origin[N];
vector<int> chosen;

ll dp[N][M];
ll rec(int idx, int weight) {
	if (idx < 0) return 0;
	if (weight == 0) return 0;

	ll& ret = dp[idx][weight];
	if (~ret) return ret;
	ret = rec(idx - 1, weight);
	if (loss[idx] <= weight) ret = max(ret, arr[idx] + rec(idx - 1, weight - loss[idx]));

	return ret;
}

void printpath(int n, int weight, int ans) {
	while (ans != 0) {
		for (int i = 0; i < n; ++i) {
			if (dp[i][weight] == ans) {
				chosen.push_back(i);
				weight -= loss[i];
				ans -= arr[i];
				break;
			}
		}
	}
}

void solve() {
	int t, n, w;
	bool flag = 0;
	while (scanf("%d%d%d", &t, &w, &n) == 3) {
		memset(dp, -1, sizeof dp);
		if (flag) puts("");
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &loss[i], &arr[i]);
			origin[i] = loss[i];
			loss[i] = 3 * w * loss[i];
		}
		ll ans = rec(n - 1, t);
		printf("%lld\n", ans);
		printpath(n, t, ans);
		printf("%d\n", (int) chosen.size());
		sort(chosen.begin(), chosen.end());
		for (int i = 0; i < (int) chosen.size(); ++i) {
			int idx = chosen[i];
			printf("%d %d\n", origin[idx], arr[idx]);
		}
		chosen.clear();
		flag = 1;
	}
}
int main() {
	_init_();

	solve();

	return 0;
}
