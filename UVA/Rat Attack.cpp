#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 1025;
int city[N][N], vis[N][N], vid;
int i_m[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int j_m[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

// max(abs(x2 − x1), abs(y2 − y1)) ≤ d
void pop_dist(int x, int y, const int &m_x, const int &m_y, const int &d,
		const int &val) {
	if (max(abs(x - m_x), abs(y - m_y)) > d) {
		return;
	}
	vis[x][y] = vid;
	city[x][y] += val;
	for (int i = 0; i < 8; ++i) {
		int n_x = x + i_m[i], n_y = y + j_m[i];
		if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N || vis[n_x][n_y] == vid)
			continue;
		pop_dist(n_x, n_y, m_x, m_y, d, val);
	}
}

int main() {
	int t, d, n, x, y, rat;
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < N; ++i) {
			memset(city[i], 0, sizeof(city[i]));
		}
		scanf("%d %d", &d, &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d %d %d", &x, &y, &rat);
			++vid;
			pop_dist(x, y, x, y, d, rat);

		}
		int ans_x = 0, ans_y = 0, sum = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (city[i][j] > sum) {
					sum = city[i][j], ans_x = i, ans_y = j;
				}
			}
		}
		printf("%d %d %d\n", ans_x, ans_y, sum);
	}
	return 0;
}

