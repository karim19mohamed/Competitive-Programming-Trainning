#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 1e5 + 9, M = 400 - 9;
const ll Mod_M = 1e9 + 7;

vector<int> adj[N];
int vis[N], vid, stk[N], stksz;
int component_cnt, comp_id[N], tim, lowlink[N], dfst[N];
int notsrc[N], notsnk[N];
void dfs(int u) {
	comp_id[u] = -1;
	dfst[u] = lowlink[u] = tim++;
	vis[u] = vid;
	stk[stksz++] = u;
	for (auto v : adj[u]) {
		if (vis[v] != vid) {
			dfs(v);
			lowlink[u] = min(lowlink[u], lowlink[v]);
		} else if (comp_id[v] == -1) {
			lowlink[u] = min(lowlink[u], lowlink[v]);
		}
	}
	if (dfst[u] == lowlink[u]) {
		do {
			comp_id[stk[--stksz]] = component_cnt;
		} while (stk[stksz] != u);
		++component_cnt;
	}
}

void tarjan(int n) {
	++vid;
	tim = stksz = component_cnt = 0;
	for (int i = 0; i < n; ++i)
		if (vis[i] != vid)
			dfs(i);
	for (int u = 0; u < n; ++u) {
		for (auto v : adj[u]) {
			if (comp_id[u] == comp_id[v])
				continue;
			notsrc[comp_id[v]] = vid;
			notsnk[comp_id[u]] = vid;
		}
	}
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
		while (cin >> m, m)
			adj[i].push_back(m - 1);
	}
	tarjan(n);
	int srccnt = component_cnt - count(notsrc, notsrc + component_cnt, vid);
	int snkcnt = component_cnt - count(notsnk, notsnk + component_cnt, vid);
	printf("%d\n", srccnt);
	cout << ((component_cnt == 1) ? 0 : max(srccnt, snkcnt)) << endl;

	return 0;
}

