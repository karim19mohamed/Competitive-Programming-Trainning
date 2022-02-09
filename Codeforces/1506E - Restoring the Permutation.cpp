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

void solve() {
	int n, q[N];
	bool vis[N], vis2[N];
	memset(vis, 0, sizeof(vis));
	memset(vis2, 0, sizeof(vis2));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", q + i);
	vector<int> min_ans;
	vector<int> max_ans;
	int num = 1;
	min_ans.push_back(q[0]);
	max_ans.push_back(q[0]);
	vis[q[0]] = vis2[q[0]] = 1;
	for (int i = 1; i < n; ++i) {
		if (!vis[q[i]]) {
			min_ans.push_back(q[i]);
			max_ans.push_back(q[i]);
			vis[q[i]] = vis2[q[i]] = 1;
		} else {
			while (vis[num])
				++num;
			min_ans.push_back(num++);
			int idx = max_ans.size() - 1;
			int k = max_ans[idx];
			while (vis2[k - 1]) {
				--idx;
				k = max_ans[idx];
			}
			max_ans.push_back(k - 1);
			vis2[k - 1] = 1;
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%d%c", min_ans[i], " \n"[i == n - 1]);
	for (int i = 0; i < n; ++i)
		printf("%d%c", max_ans[i], " \n"[i == n - 1]);
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

