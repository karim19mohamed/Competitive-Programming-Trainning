#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 5 * 100000 + 9;
int vis[N], idx;
int GCD(int a, int b) { // a>b
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

int LCM(int a, int b) {
	return a * b / GCD(a, b);
}
vector<int> prime_factorization(int num) { //O(sqrt(n))
	vector<int> v;
	for (int i = 2; i * i <= num; ++i)
		while (num % i == 0)
			v.push_back(i), num /= i;
	if (num != 1)
		v.push_back(num);
	return v;
}

int main() {
	/*int tmp = 10000000, ans1, ans2;
	 for (int i = 1; i < 175; ++i) {
	 int a = 175 - i, b = i;
	 if (a < b)
	 swap(a, b);
	 if (LCM(a, b) < tmp) {
	 tmp = LCM(a, b);
	 ans1 = a, ans2 = b;
	 }
	 }
	 dbg2(ans1, ans2);
	 */
	int t, n, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n % 2 == 0) {
			a = b = n / 2;
			printf("%d %d\n", a, b);
			continue;
		}
		vector<int> prime_factors = prime_factorization(n);
		a = n / prime_factors[0];
		b = n - a;
		printf("%d %d\n", a, b);
	}
	return 0;
}

