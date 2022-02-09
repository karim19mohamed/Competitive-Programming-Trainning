#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 2e5 + 9;

int main() {
	string s;
	cin >> s;
	int num = 1, ans = 1;
	char curr = s[0];
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] == curr) {
			++num;
		} else {
			curr = s[i];
			ans = max(ans, num);
			num = 1;
		}
	}
	ans = max(ans, num);
	printf("%d\n", ans);
	return 0;
}

