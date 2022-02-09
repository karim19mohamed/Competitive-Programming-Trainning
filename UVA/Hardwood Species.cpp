#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

using namespace std;

int main() {
	int t;
	string s;
	scanf("%d", &t);
	getline(std::cin, s);
	getline(std::cin, s);
	while (t--) {
		map<string, float> m;
		set<string> name;
		float total = 0;
		while (getline(std::cin, s) && s.size()) {
			++m[s];
			++total;
			name.insert(s);
			//dbg(s);
		}
		for (set<string>::iterator it = name.begin(); it != name.end(); ++it) {
			float ans = 100 * m[*it] / total;
			cout << *it;
			printf(" %.4f\n", ans);
		}
		if (t)
			puts("");
	}

	return 0;
}
