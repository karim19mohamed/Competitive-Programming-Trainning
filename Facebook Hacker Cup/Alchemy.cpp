#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 50 + 9, M = 20 + 9;

string solve(string s) {
	string res = "";
	int i;
	for (i = 0; i < (int) s.size() - 2; ++i) {
		int A_cnt = 0, B_cnt = 0;
		(s[i] == 'A') ? ++A_cnt : ++B_cnt;
		(s[i + 1] == 'A') ? ++A_cnt : ++B_cnt;
		(s[i + 2] == 'A') ? ++A_cnt : ++B_cnt;
		if (A_cnt < 3 && A_cnt > B_cnt)
			res += 'A', i += 2;
		else if (B_cnt < 3 && A_cnt < B_cnt)
			res += 'B', i += 2;
		else
			res += s[i];
	}
	for (; i < (int) s.size(); ++i)
		res += s[i];
	return res;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
//#ifdef ECLIPSE
	freopen("alchemy_input.txt", "rt", stdin);
	freopen("output.out", "wt", stdout);
//#endif
	int t, n, cs = 1;
	cin >> t;
	string s;
	while (t--) {
		cin >> n >> s;
		string tmp = solve(s);
		while (tmp.size() != s.size()) {
			s = tmp;
			tmp = solve(s);
		}
		printf("Case #%d: ", cs++);
		(s.size() == 1) ? printf("Y\n") : printf("N\n");
	}
	return 0;
}

