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

const int N = 2e5 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

int n, a[N];
int solution() {
	priority_queue<pair<int, int>> q;
	int freq = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i] == a[i - 1]) {
			++freq;
		} else {
//			dbg(freq);
			q.push(make_pair(freq, 1));
			freq = 1;
		}
	}
//	dbg(freq);
	q.push(make_pair(freq, 1));
	int ans = 1e7, cnt = 0;
	while (q.size() > 1) {
		int curr = q.top().F, num_times = q.top().S;
//		dbg2(curr, num_times);
		q.pop();
		if (q.top().F == curr) {
			num_times += q.top().S;
			q.pop();
			q.push(make_pair(curr, num_times));
			continue;
		}
		ans = min(ans, n - curr * num_times);
		int del = (curr - q.top().F) * num_times;
		cnt += del;

		pair<int, int> second_curr = q.top();
		q.pop();
		pair<int, int> tmp = { second_curr.F, second_curr.S + num_times };
		q.push(tmp);

	}
	ans = min(ans, cnt);
	return ans;
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	sort(a, a + n);
	int ans = solution();
	printf("%d\n", ans);

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

