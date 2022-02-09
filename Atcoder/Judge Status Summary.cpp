#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const ll N = 100 + 9, M = 400 - 9, Max_ans = 1LL * (1e16);
int vis[N];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);
#endif
	int n;
	cin >> n;
	string s;
	while (n--) {
		cin >> s;
		++vis[s[0] - 'A'];
	}
	printf("AC x %d\n", vis['A' - 'A']);
	printf("WA x %d\n", vis['W' - 'A']);
	printf("TLE x %d\n", vis['T' - 'A']);
	printf("RE x %d\n", vis['R' - 'A']);
	return 0;
}

