#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 1e9 + 9, M = 1073741824;

int GCD(int a, int b) { // a>b
	if (b == 0)
		return a;
	return GCD(b, a % b);
}
vector<int> generate_divisors(int num) {
	vector<int> v;
	int i;
	for (i = 1; i * i < num; ++i)
		if (num % i == 0)
			v.push_back(i), v.push_back(num / i);
	if (i * i == num)
		v.push_back(i);
	return v;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);
#endif
	int a, b, n, low, high, gcd;
	cin >> a >> b >> n;
	gcd = GCD(max(a, b), min(a, b));
	vector<int> div = generate_divisors(gcd);
	//dbg(div.size());
	sort(div.begin(), div.end());
	while (n--) {
		cin >> low >> high;
		int ans = -1;
		for (int i = div.size() - 1; i >= 0; --i) {
			//dbg(div[i]);
			if (div[i] <= high && div[i] >= low) {
				ans = div[i];
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

