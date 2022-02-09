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

template<typename T_n> void read(T_n &n) {
	cin >> n;
}
template<typename T_n, typename T_a> void read(T_a a[], T_n n) {
	for (int i = 0; i < n; ++i)
		cin >> a[i];
}
template<typename T_n, typename T_a> void read(vector<T_a> &a, T_n n) {
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
}
void _init_() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);
#endif
}

const int N = 300 + 9, M = 1e9 - 9;
int vid, vis[N][N][3];
vector<string> adj;
int n, m;

int bfs() {
	pair<int, int> src, dest;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (adj[i][j] == 'S') src= {i,j};
			if (adj[i][j]=='E')
			dest= {i,j};
		}
	queue<pair<int, int>> q;
	q.push(src);
	++vid;
	//vis[src.F][src.S][0] = ++vid;
	int lvl = 0;
	while (!q.empty()) {
		int qsz = q.size();
		while (qsz--) {
			auto u = q.front();
			q.pop();
			//dbg2(u.F, u.S);
			if (u.F == dest.F && u.S == dest.S) return lvl;

			int move = 1 + (lvl % 3);
			//dbg(move);
			int m_x1 = u.F + move, m_y1 = u.S + move;
			int m_x2 = u.F - move, m_y2 = u.S - move;

			if (m_x1 < n && vis[m_x1][u.S][move - 1] != vid) {
				//dbg2(m_x1, u.S);
				bool flag = 1;
				for (int i = m_x1; i > u.F; --i)
					if (adj[i][u.S] == '#') flag = 0;

				if (flag) q.push( { m_x1, u.S }), vis[m_x1][u.S][move - 1] = vid;
			}
			if (m_x2 >= 0 && vis[m_x2][u.S][move - 1] != vid) {
				//dbg2(m_x2, u.S);
				bool flag = 1;
				for (int i = m_x2; i < u.F; ++i)
					if (adj[i][u.S] == '#') flag = 0;

				if (flag) q.push( { m_x2, u.S }), vis[m_x2][u.S][move - 1] = vid;
			}

			if (m_y1 < m && vis[u.F][m_y1][move - 1] != vid) {
				//dbg2(u.F, m_y1);
				bool flag = 1;
				for (int i = m_y1; i > u.S; --i)
					if (adj[u.F][i] == '#') flag = 0;

				if (flag) q.push( { u.F, m_y1 }), vis[u.F][m_y1][move - 1] = vid;
			}
			if (m_y2 >= 0 && vis[u.F][m_y2][move - 1] != vid) {
				//dbg2(u.F, m_y2);
				bool flag = 1;
				for (int i = m_y2; i < u.S; ++i)
					if (adj[u.F][i] == '#') flag = 0;

				if (flag) q.push( { u.F, m_y2 }), vis[u.F][m_y2][move - 1] = vid;
			}

		}
		++lvl;
	}
	return -1;
}

void solve() {

	scanf("%d%d", &n, &m);
	char tmp[309];
	for (int i = 0; i < n; ++i) {
		scanf("%s", tmp);
		adj.push_back(tmp);
	}
	int ans = bfs();
	if (ans == -1) {
		puts("NO");
	} else {
		printf("%d\n", ans);
	}
	adj.clear();
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
