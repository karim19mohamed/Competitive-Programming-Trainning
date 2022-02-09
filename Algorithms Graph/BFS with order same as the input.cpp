#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 100 + 9, M = 190;
int vid, vis[N], required[N], filled_required[N];
queue<int> arrange;
map<string, int> name_to_int;
map<int, string> int_to_name;

void bfs(vector<int> (&a)[N], const int &n) {
	fill(filled_required, filled_required + n, 0);
	priority_queue<int> q;
	while (!arrange.empty()) {
		int src = arrange.front();
		q.push(-src);
		vis[src] = vid;
		arrange.pop();
	}
	while (!q.empty()) {
		int qsz = q.size();
		while (qsz--) {
			int u = -q.top();
			q.pop();
			if (filled_required[u] != required[u]) {
				vis[u] = vid - 1;
				continue;
			} else {
				cout << " " << int_to_name[u];
			}
			for (auto v : a[u]) {
				++filled_required[v];
				if (vis[v] != vid) {
					q.push(-v);
					vis[v] = vid;
				}
			}
		}
	}
}

int main() {
	int n, m, cs = 1;
	string s1, s2;
	while (scanf("%d", &n) != EOF) {
		fill(required, required + n, 0);
		vector<int> adj[N];
		vector<bool> to_begin_from(n, 1);
		for (int i = 0; i < n; ++i) {
			cin >> s1;
			name_to_int[s1] = i;
			int_to_name[i] = s1;
		}
		scanf("%d", &m);
		for (int i = 0; i < m; ++i) {
			cin >> s1 >> s2;
			adj[name_to_int[s1]].push_back(name_to_int[s2]);
			to_begin_from[name_to_int[s2]] = 0;
			required[name_to_int[s2]]++;
		}
		for (int i = 0; i < n; ++i) {
			if (to_begin_from[i])
				arrange.push(i);
		}
		printf("Case #%d: Dilbert should drink beverages in this order:", cs++);
		++vid;
		bfs(adj, n);
		printf(".\n\n");
	}
	return 0;
}

