#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

using namespace std;
const int N = 9 + 9;
vector<pair<int, int> > divisions[100];
bool vis[N];

void solve(ll n, int idx) {
	if (idx == 10) {
		ll a = n / 100000, b = n % 100000;
		ll num = a / b;
		if (num * b == a)
			divisions[num].push_back( { (int) a, (int) b });
		return;
	}
	for (int i = 0; i <= 9; ++i) {
		if (!vis[i]) {
			vis[i] = 1;
			solve(n * 10 + i, idx + 1);
			vis[i] = 0;
		}
	}
}

int main() {
	int n;
	solve(0, 0);
	bool flag = 0;
	while (scanf("%d", &n) && n) {
		if (flag)
			puts("");
		if (divisions[n].size() == 0) {
			printf("There are no solutions for %d.\n", n);
			flag = 1;
			continue;
		}
		for (auto a : divisions[n]) {
			printf("%05d / %05d = %d\n", a.first, a.second, n);
		}
		flag = 1;
	}
	return 0;
}

