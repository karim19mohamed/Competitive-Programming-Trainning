#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 1000 + 9;

int vid, vis[N][N], vis_num[N];
int i_m[] = { 1, 0, -1, 0 };
int j_m[] = { 0, 1, 0, -1 };

void dfs(int num, int i, int j, vector<vector<int> > &adj) {
	vis[i][j] = vid;
	for (int idx = 0; idx < 4; ++idx) {
		int n_i = i + i_m[idx], n_j = j + j_m[idx];
		if (n_i < 0 || n_i >= adj.size() || n_j < 0 || n_j >= adj[0].size())
			continue;
		if (vis[n_i][n_j] != vid && adj[n_i][n_j] == num)
			dfs(num, n_i, n_j, adj);
	}
}

int main() {
	int n, a1, a2;
	string s;
	while (scanf("%d", &n) && n) {
		getline(std::cin, s);
		vector<vector<int> > adj;
		for (int i = 0; i < n; ++i) {
			vector<int> tmp(n, 0);
			adj.push_back(tmp);
		}
		for (int i = 1; i < n; ++i) {
			getline(std::cin, s);
			stringstream sin(s);
			while (sin >> a1 >> a2) {
				adj[a1 - 1][a2 - 1] = i;
			}
		}
		bool ans = 1;
		++vid;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (vis[i][j] != vid) {
					if (vis_num[adj[i][j]] == vid) {
						ans = 0;
						break;
					}
					vis_num[adj[i][j]] = vid;
					dfs(adj[i][j], i, j, adj);
				}

			}
		}
		(ans) ? puts("good") : puts("wrong");

	}
	return 0;
}

