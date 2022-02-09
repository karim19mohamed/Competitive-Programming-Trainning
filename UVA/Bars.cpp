#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

using namespace std;
const int N = 20 + 9;
int bars[N];
bool solve(int num, int idx, const int &n, const int &p) {
	if (idx == p)
		return num == n;
	bool ans = 0;
	ans |= solve(num + bars[idx], idx + 1, n, p);
	ans |= solve(num, idx + 1, n, p);
	return ans;
}

int main() {
	int t, n, p;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &p);
		for (int i = 0; i < p; ++i)
			scanf("%d", &bars[i]);
		(solve(0, 0, n, p)) ? puts("YES") : puts("NO");
	}
	return 0;
}

