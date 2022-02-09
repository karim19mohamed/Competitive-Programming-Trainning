#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 200000 + 9, M = 190;

int vid, vis[N];

void dfs(int src, vector<int> (&adj)[N]) {

	vis[src] = vid;
	for (int i = 0; i < adj[src].size(); ++i) {
		if (vis[adj[src][i]] != vid)
			dfs(adj[src][i], adj);
	}
}

int main() {
	ifstream inFile;
	ofstream outfile;
	inFile.open("b4.in");
	outfile.open("b4.out");
	int n, m, a, b;
	inFile >> n >> m;
	//dbg2(n, m);
	vector<int> adj[N];
	for (ll i = 0; i < m; ++i) {
		inFile >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	++vid;
	vector<bool> ans(n + 1, 0);
	priority_queue<pair<pair<int, int>, int>,
			vector<pair<pair<int, int>, int> >, greater<> > q;
	for (int i = 1; i <= n; ++i) {
		int tmp = 0, tmp2 = adj[i].size();
		for (auto node : adj[i])
			tmp += adj[node].size();

		q.push( { { -tmp2, -tmp }, i });
	}
	int sum = 0;
	while (!q.empty()) {
		int i = q.top().second;
		if (vis[i] != vid) {
			ans[i] = 1;
			++sum;
			//dfs(i, adj);
			for (int j = 0; j < adj[i].size(); ++j) {
				vis[adj[i][j]] = vid;
			}
		}
		q.pop();
	}
	cout << sum << endl;
	outfile << sum << endl;
	outfile << ans[1];
	for (int i = 2; i <= n; ++i) {
		outfile << " " << ans[i];
	}
	outfile << endl;
	return 0;
}
