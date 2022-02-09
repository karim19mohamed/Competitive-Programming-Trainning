#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 99 + 9;

int vid, vis[N][N], ans[N][N];
int i_m[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int j_m[] = { 1, 0, -1, 1, -1, 1, 0, -1 };
char c = 'W';

int dfs(int i, int j, vector<string> &adj, const int &n, const int &m) {
	if (adj[i][j] != c)
		return 0;
	vis[i][j] = vid;
	int sum = 1;
	for (int idx = 0; idx < 8; ++idx) {
		int n_i = i + i_m[idx], n_j = j + j_m[idx];
		if (n_i < 0 || n_i >= n || n_j < 0 || n_j >= m)
			continue;
		if (vis[n_i][n_j] != vid && adj[n_i][n_j] == c)
			sum += dfs(n_i, n_j, adj, n, m);
	}
	return sum;
}
void fill_same_ans(const int &n, const int &m, const int &sum) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (vis[i][j] == vid)
				ans[i][j] = sum;
}
void reset(const int &n, const int &m) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			ans[i][j] = 0;
}

int main() {
	int t, n, m, x, y, sum;
	scanf("%d", &t);
	string s;
	getline(std::cin, s);
	getline(std::cin, s);
	while (t--) {
		vector<string> adj;
		while (getline(std::cin, s) && (s[0] == 'W' || s[0] == 'L')) {
			adj.push_back(s);
		}
		n = adj.size(), m = adj[0].size();
		reset(n, m);
		stringstream is(s);
		is >> x >> y;
		//dbg3(x - 1, y - 1, adj[x - 1]);;
		++vid;
		sum = dfs(x - 1, y - 1, adj, n, m);
		fill_same_ans(n, m, sum);
		printf("%d\n", sum);
		while (getline(std::cin, s) && s.size()) {
			stringstream is(s);
			is >> x >> y;

			if (ans[x - 1][y - 1]) {
				printf("%d\n", ans[x - 1][y - 1]);
				continue;
			}
			++vid;
			sum = dfs(x - 1, y - 1, adj, n, m);
			fill_same_ans(n, m, sum);
			printf("%d\n", sum);
		}
		//dbg(t);
		if (t)
			puts("");
	}
	return 0;
}

