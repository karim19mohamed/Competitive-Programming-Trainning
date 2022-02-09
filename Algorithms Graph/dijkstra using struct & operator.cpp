#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 999 + 9, M = 999 + 9;

int dis[N][N], arr[N][N];
int i_m[] = { 1, -1, 0, 0 };
int j_m[] = { 0, 0, 1, -1 };

struct node {
	int cost, x, y;
};
struct minheap {
	bool operator()(node const& p1, node const& p2) {
		if (p1.cost != p2.cost)
			return p1.cost > p2.cost;
		else if (p1.x != p2.x)
			return p1.x > p2.x;
		return p1.y > p2.y;
	}
};
struct maxheap {
	bool operator()(node const& p1, node const& p2) {
		if (p1.cost != p2.cost)
			return p1.cost > p2.cost;
		else if (p1.x != p2.x)
			return p1.x > p2.x;
		return p1.y > p2.y;
	}
};

void dijkstra(int i, int j, const int &n, const int &m) {
	for (int i = 0; i < n; ++i)
		fill(dis[i], dis[i] + m, 1e9);
	priority_queue<node, vector<node>, minheap> q;
	q.push( { arr[i][j], i, j });
	dis[i][j] = arr[i][j];
	while (!q.empty()) {
		int u_x = q.top().x, u_y = q.top().y;
		int c = q.top().cost;
		q.pop();
		if (dis[u_x][u_y] != c)
			continue;
		for (int k = 0; k < 4; ++k) {
			int n_i = u_x + i_m[k], n_j = u_y + j_m[k];
			if (n_i < 0 || n_i >= n || n_j < 0 || n_j >= m)
				continue;
			if (dis[n_i][n_j] > arr[n_i][n_j] + c) {
				q.push( { arr[n_i][n_j] + c, n_i, n_j });
				dis[n_i][n_j] = arr[n_i][n_j] + c;
			}
		}
	}
}

int main() {
	int t, n, m;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", &arr[i][j]);
		dijkstra(0, 0, n, m);
		printf("%d\n", dis[n - 1][m - 1]);
	}
	return 0;
}

