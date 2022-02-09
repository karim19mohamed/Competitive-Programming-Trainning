#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 100 + 9, M = 1073741824;
bool is_prime(int n) {
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);
#endif
	string s;
	while (getline(std::cin, s)) {
		int num = 0;
		for (auto c : s) {
			if (c >= 'a' && c <= 'z')
				num += (c - 'a' + 1);
			else if (c >= 'A' && c <= 'Z')
				num += (c - 'A' + 27);
		}
		bool ans = is_prime(num);
		(ans) ? puts("It is a prime word.") : puts("It is not a prime word.");
	}

	return 0;
}

