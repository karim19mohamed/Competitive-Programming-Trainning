#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 2e5 + 9;

int main() {
	ll n;
	scanf("%lld", &n);
	ll num = n;
	printf("%lld", num);
	while (num != 1) {
		if (num % 2 == 0)
			num /= 2;
		else
			num = num * 3 + 1;
		printf(" %lld", num);
	}
	puts("");
	return 0;
}

