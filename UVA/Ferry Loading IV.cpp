#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

using namespace std;

int main() {
	int t, l, m, car;
	string s;
	scanf("%d", &t);
	while (t--) {
		queue<int> left, right;
		scanf("%d %d", &l, &m);
		l *= 100;
		for (int i = 0; i < m; ++i) {
			cin >> car >> s;
			if (s[0] == 'l' && car <= l)
				left.push(car);
			else
				right.push(car);
		}
		bool position = 0;
		int ans = 0;
		while (!left.empty() || !right.empty()) {
			int cargo = 0;
			if (position) {
				while (!right.empty()) {
					int tmp = right.front();
					if (cargo + tmp <= l)
						cargo += right.front();
					else
						break;
					right.pop();
				}
			} else {
				while (!left.empty()) {
					int tmp = left.front();
					if (cargo + tmp <= l)
						cargo += left.front();
					else
						break;
					left.pop();
				}
			}
			//dbg(cargo);
			position ^= 1;
			++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}

