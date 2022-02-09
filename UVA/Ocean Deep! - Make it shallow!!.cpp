#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 1e9 + 9, M = 131071;

void solve(vector<char> &binary) {
	int n = 0, two = 1;
	for (int i = binary.size() - 1; i >= 0; --i) {
		if (binary[i] == '1')
			n = (n + two) % M;
		two = (two * 2) % M;
	}
	n = n % M;
	(!n) ? puts("YES") : puts("NO");
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);
#endif
	string s;
	vector<char> binary;
	while (cin >> s) {
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '#') {
				solve(binary);
				binary.clear();
				continue;
			}
			binary.push_back(s[i]);
		}

	}
	return 0;
}

