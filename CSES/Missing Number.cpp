#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 2e5 + 9;
bool a[N];

int main() {
	int n, num;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i)
		scanf("%d", &num), a[num] = 1;
	for (int i = 1; i <= n; ++i)
		if (!a[i]) {
			printf("%d\n", i);
			break;
		}
	return 0;
}

