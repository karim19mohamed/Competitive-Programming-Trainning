#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 100 + 9;

int vid, vis[N][N];

void dfs(int i, int j, vector<vector<bool>> &grid, const int &n, const int &m,
		int i_m[], int j_m[]) {
	vis[i][j] = vid;
	for (int idx = 0; idx < 8; ++idx) {
		int n_i = i + i_m[idx], n_j = j + j_m[idx];
		if (n_i < 0 || n_i >= n || n_j < 0 || n_j >= m)
			continue;
		if (vis[n_i][n_j] != vid && !grid[n_i][n_j])
			dfs(n_i, n_j, grid, n, m, i_m, j_m);
	}
}

int main() {
	int t, n, m, x, y, w, cs = 1;
	scanf("%d", &t);
	while (t--) {
		vector<vector<bool>> grid;
		scanf("%d %d %d %d", &n, &m, &x, &y);
		for (int i = 0; i < n; ++i) {
			vector<bool> tmp(m, 0);
			grid.push_back(tmp);
		}
		int i_m[] = { x, y, -x, -y, x, y, -x, -y };
		int j_m[] = { y, x, y, x, -y, -x, -y, -x };
		scanf("%d", &w);
		for (int i = 0; i < w; ++i) {
			scanf("%d %d", &x, &y);
			grid[x][y] = 1;
		}
		++vid;
		dfs(0, 0, grid, n, m, i_m, j_m);
		set<pair<int, int> > unique_m;
		for (int k = 0; k < 8; ++k)
			unique_m.insert( { i_m[k], j_m[k] });
		int even = 0, odd = 0, cnt_zero = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] || vis[i][j] != vid)
					continue;
				int cnt = 0;
				for (set<pair<int, int>>::iterator it = unique_m.begin();
						it != unique_m.end(); ++it) {
					pair<int, int> p = *it;
					int n_i = i + p.first, n_j = j + p.second;
					if (n_i >= 0 && n_i < n && n_j >= 0 && n_j < m
							&& !grid[n_i][n_j] && vis[n_i][n_j] == vid) {
						++cnt;
					}

				}
				if (cnt)
					(cnt % 2) ? ++odd : ++even;
				if (i == 0 && j == 0)
					cnt_zero = cnt;
			}
		}
		if (cnt_zero)
			printf("Case %d: %d %d\n", cs++, even, odd);
		else
			printf("Case %d: 1 0\n", cs++);
	}
	return 0;
}
