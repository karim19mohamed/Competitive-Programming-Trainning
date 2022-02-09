#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int t, cs = 1;
	string path;
	scanf("%d", &t);
	while (t--) {
		vector<int> adj[30];
		cin >> path;
		stack<char> s;
		for (auto c : path) {
			if (s.empty()) {
				s.push(c);
			} else if (s.top() == c) {
				s.pop();
			} else {
				adj[s.top() - 'A'].push_back(c - 'A');
				adj[c - 'A'].push_back(s.top() - 'A');
				s.push(c);
			}
		}
		printf("Case %d\n", cs++);
		for (int i = 0; i < 30; ++i) {
			if (adj[i].size()) {
				printf("%c = %d\n", 'A' + i, (int) (adj[i].size()));
			}
		}
	}
	return 0;
}

