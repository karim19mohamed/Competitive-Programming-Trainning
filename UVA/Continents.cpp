#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 20 + 9;

int vid, vis[N][N];
int i_m[] = { 1, 0, -1, 0 };
int j_m[] = { 0, 1, 0, -1 };
char c;

int dfs(int i, int j, vector<string> &adj, const int &n, const int &m) {
	vis[i][j] = vid;
	int sum = 1;
	for (int idx = 0; idx < 4; ++idx) {
		int n_i = i + i_m[idx], n_j = (j + j_m[idx] + m) % m;
		if (n_i < 0 || n_i >= n || n_j < 0 || n_j >= m)
			continue;
		if (vis[n_i][n_j] != vid && adj[n_i][n_j] == c)
			sum += dfs(n_i, n_j, adj, n, m);
	}
	return sum;
}

int main() {
	int n, m, x, y;
	string s;
	while (scanf("%d %d", &n, &m) == 2) {
		vector<string> adj;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			adj.push_back(s);
		}
		scanf("%d %d", &x, &y);
		++vid;
		c = adj[x][y];
		int sum = dfs(x, y, adj, n, m);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (vis[i][j] != vid && adj[i][j] == c) {
					sum = dfs(i, j, adj, n, m);
					ans = max(ans, sum);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

