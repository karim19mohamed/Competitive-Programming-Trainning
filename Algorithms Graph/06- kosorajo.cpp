#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 1e5 + 9, M = 400 - 9;
const ll Mod_M = 1e9 + 7;

vector<int> adj[N], adjR[N];
int vis[N], vid, stk[N], stksz;
int comp_id[N];
int notsrc[N], notsnk[N];
void dfs(int u) {
	if (vis[u] == vid)
		return;
	vis[u] = vid;
	for (auto v : adj[u])
		dfs(v);
	stk[stksz++] = u;
}
void dfs_extract_component(int u, int cid) {
	if (vis[u] == vid)
		return;
	vis[u] = vid;
	comp_id[u] = cid;
	for (auto v : adjR[u])
		dfs_extract_component(v, cid);
}

int kosoraju(int n) {
	++vid;
	for (int i = 0; i < n; ++i)
		dfs(i);
	++vid;
	int component_cnt = 0;
	while (stksz) {
		stksz--;
		if (vis[stk[stksz]] != vid)
			dfs_extract_component(stk[stksz], component_cnt++);
	}
	for (int u = 0; u < n; ++u) {
		for (auto v : adj[u]) {
			if (comp_id[u] == comp_id[v])
				continue;
			notsrc[comp_id[v]] = vid;
			notsnk[comp_id[u]] = vid;
		}
	}
	return component_cnt;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif
	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		while (cin >> m, m) {
			adj[i].push_back(m - 1);
			adjR[m - 1].push_back(i);
		}
	}
	int component_cnt = kosoraju(n);
	int srccnt = component_cnt - count(notsrc, notsrc + component_cnt, vid);
	int snkcnt = component_cnt - count(notsnk, notsnk + component_cnt, vid);
	printf("%d\n", srccnt);
	cout << ((component_cnt == 1) ? 0 : max(srccnt, snkcnt)) << endl;

	return 0;
}

