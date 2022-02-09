#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 100 + 9;

int vid, vis[N][N];
int i_m[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int j_m[] = { 1, 0, -1, 1, -1, 1, 0, -1 };
char c;

void dfs(int i, int j, vector<string> &adj, const int &n, const int &m) {
	vis[i][j] = vid;
	for (int idx = 0; idx < 8; ++idx) {
		int n_i = i + i_m[idx], n_j = j + j_m[idx];
		if (n_i < 0 || n_i >= n || n_j < 0 || n_j >= m)
			continue;
		if (vis[n_i][n_j] != vid && adj[n_i][n_j] == c)
			dfs(n_i, n_j, adj, n, m);
	}
}

int main() {
	int n, m, x, y;
	string s;
	while (scanf("%d %d", &n, &m) && n + m) {
		vector<string> adj;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			adj.push_back(s);
		}
		++vid;
		c = '@';
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (vis[i][j] != vid && adj[i][j] == c) {
					dfs(i, j, adj, n, m);
					++ans;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

