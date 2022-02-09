#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

using namespace std;

int main() {
	int t, n, member, cs = 1;
	string s;
	while (scanf("%d", &t) && t) {
		map<int, int> team, idx_team, cnt;
		for (int i = 0; i < t; ++i) {
			scanf("%d", &n);
			for (int j = 0; j < n; ++j) {
				scanf("%d", &member);
				team[member] = i + 1;
			}
		}
		printf("Scenario #%d\n", cs++);
		int idx = 1;
		priority_queue<pair<pair<int, int>, int> > data_str;
		while (cin >> s && s[0] != 'S') {
			if (s[0] == 'E') {
				scanf("%d", &member);
				if (cnt[team[member]] == 0) {
					data_str.push( { { -idx, -idx }, member });
					idx_team[team[member]] = idx;
					//dbg3(idx, idx, member);
					++idx;
					++cnt[team[member]];
				} else {
					data_str.push(
							{ { -idx_team[team[member]], -idx }, member });
					//dbg3(idx_team[team[member]], idx, member);
					++idx;
					++cnt[team[member]];
				}
			} else {
				member = data_str.top().second;
				printf("%d\n", member);
				--cnt[team[member]];
				data_str.pop();
			}
		}
		puts("");
	}
	return 0;
}

