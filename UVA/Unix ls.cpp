#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

using namespace std;
const int N = 1000 + 9;

int main() {
	int n;
	string s;
	while (scanf("%d", &n) == 1) {
		set<string> ans;
		int Longest = 0, col, row;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			Longest = max(Longest, (int) s.size());
			ans.insert(s);
		}
		col = 1 + (60 - Longest) / (Longest + 2);
		row = (n + col - 1) / col;
		vector<string> output(row);
		set<string>::iterator it = ans.begin();
		int cnt = 1;
		for (int i = 0; i < n;) {
			int tmp = 0;
			while (tmp++ < row) {
				s = *it;
				string space(Longest - s.size(), ' ');
				if (cnt != col && i < n - row) {
					space += "  ";
				}
				output[tmp - 1] += s + space;
				++it;
				++i;
				if (i >= n)
					break;
			}
			++cnt;
		}
		puts("------------------------------------------------------------");
		for (int i = 0; i < row; ++i)
			cout << output[i] << endl;
	}
	return 0;
}

