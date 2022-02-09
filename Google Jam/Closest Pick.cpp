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

const int N = 30 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

int n, k, a[N];

double naive() {
	double p = 0.0;
	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= k; ++j) {
			double cnt = 0;
			for (int c = 1; c <= k; ++c) {
				bool flag = 1;
				int tmp = min(abs(i - c), abs(j - c));
				for (int j = 0; j < n; ++j) {
					int num = abs(c - a[j]);
					if (num <= tmp) flag = 0;
				}
				if (flag) ++cnt;
			}
			cnt /= k;
			p = max(p, cnt);
		}
	}
	return p;
}

void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
//	int m[N][N];
//	for (int i = 1; i <= k; ++i) {
//		for (int j = 0; j < n; ++j) {
//			m[i][j] = abs(i - j);
//		}
//	}
//	if (k > 100) return;
	double p_naive = naive();
//	dbg(p_naive);
	double p = 0.0;
	vector<double> all, second_ans;
	sort(a, a + n);
	for (int i = 0; i < n - 1; ++i) {
		ll st = a[i], en = a[i + 1];
		ll mid = st + 1;
		if (mid >= en) continue;
		ll r2 = mid + (en - mid) / 2;
		ll num = r2 - mid + 1;
		if (abs(en - r2) <= abs(mid - r2)) --num;
		all.push_back(num);
//		dbg2(mid, num);
		ll mid2 = en - 1;
		if (mid <= st) continue;
		second_ans.push_back(mid2 - mid + 1);

	}
	if (a[n - 1] < k) {
		all.push_back(k - (a[n - 1] + 1) + 1);
	}
	if (a[0] > 1) {
		all.push_back(a[0] - 1);
	}
//	dbg(all.back());
	sort(all.begin(), all.end());
	int sz = all.size();
	if (sz > 1) {
		p = (all[sz - 1] / k) + (all[sz - 2] / k);
	} else if (sz == 1) {
		p = (all[0] / k);
	}
	for (int i = 0; i < int(second_ans.size()); ++i) {
		double tmp = (second_ans[i] * 1.0) / k;
		p = max(p, tmp);
	}
	printf("%.6lf\n", p);

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

