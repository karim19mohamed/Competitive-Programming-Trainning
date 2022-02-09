#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 1000 + 9;

int main() {
	int t, n, cs = 1;
	scanf("%d", &t);
	string s;
	while (t--) {
		scanf("%d", &n);
		cin >> s;
		int ans = 0, idx = 0;
		while (idx < n) {
			if (s[idx] == '.') {
				++ans;
				idx += 3;
			} else {
				++idx;
			}
		}
		printf("Case %d: %d\n", cs++, ans);
	}
	return 0;
}

