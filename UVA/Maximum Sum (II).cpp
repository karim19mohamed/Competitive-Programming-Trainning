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
	int n, a;
	while (scanf("%d", &n) && n) {
		vector<int> ans;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a);
			if (a > 0)
				ans.push_back(a);
		}
		if (ans.empty())
			ans.push_back(0);
		for (int i = 0; i < ans.size(); ++i) {
			cout << ans[i] << " \n"[i + 1 == ans.size()];
		}

	}
	return 0;
}

