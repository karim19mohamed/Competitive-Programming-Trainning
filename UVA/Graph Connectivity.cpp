#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 26 + 9;

int vid, vis[N];

void dfs(int src, vector<int> (&adj)[N]) {

	vis[src] = vid;
	for (int i = 0; i < adj[src].size(); ++i) {
		if (vis[adj[src][i]] != vid)
			dfs(adj[src][i], adj);
	}
}

int main() {
	int t, n;
	string s;
	scanf("%d", &t);
	while (t--) {
		vector<int> adj[N];
		char c;
		scanf(" %c", &c);
		n = c - 'A';
		getline(std::cin, s);
		while (getline(std::cin, s) && s.size()) {
			adj[s[0] - 'A'].push_back(s[1] - 'A');
			adj[s[1] - 'A'].push_back(s[0] - 'A');
		}
		++vid;
		int ans = 0;
		for (int i = 0; i <= n; ++i) {
			if (vis[i] != vid) {
				++ans;
				dfs(i, adj);
			}
		}
		printf("%d\n", ans);
		if (t)
			puts("");
	}
	return 0;
}

