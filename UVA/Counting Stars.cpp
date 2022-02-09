#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 101 + 9;
int i_m[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int j_m[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) && n + m) {
		vector<string> adj;
		string s;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			adj.push_back(s);
		}
		int ans = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				if (adj[i][j] == '*') {
					int tmp = 1;
					for (int k = 0; k < 8; ++k)
						if (i + i_m[k] < n && j + j_m[k] < m && i + i_m[k] >= 0
								&& j + j_m[k] >= 0
								&& adj[i + i_m[k]][j + j_m[k]] == '*')
							tmp = 0;
					ans += tmp;
				}
			}
		printf("%d\n", ans);
	}
	return 0;
}

