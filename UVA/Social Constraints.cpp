#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 8 + 9;
int seats[N], vis[N];

int solve(int idx, const int &n, vector<pair<int, int>> (&rule)[N]) {
	if (idx == n) {
		for (int i = 0; i < n; ++i) {
			for (auto v : rule[i]) {
				int j = v.first, c = v.second;
				if (c > 0 && abs(seats[i] - seats[j]) > c)
					return 0;
				if (c < 0 && abs(seats[i] - seats[j]) < -c)
					return 0;
			}
		}
		return 1;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (vis[i])
			continue;
		seats[idx] = i, vis[i] = 1;
		ans += solve(idx + 1, n, rule);
		seats[idx] = -1, vis[i] = 0;
	}
	return ans;
}

int main() {
	int n, m, a, b, c;
	while (scanf("%d %d", &n, &m) && n + m) {
		vector<pair<int, int>> rule[N];
		memset(seats, 1, sizeof(seats));

		for (int i = 0; i < m; ++i) {
			scanf("%d %d %d", &a, &b, &c);
			rule[a].push_back( { b, c });
		}
		int ans = solve(0, n, rule);
		printf("%d\n", ans);
	}
	return 0;
}

