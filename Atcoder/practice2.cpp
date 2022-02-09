#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<double> point;
#define endl '\n'
#define F first
#define S second
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define dbg2(x,y) cerr<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cerr<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cerr<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define FOR(sz) for(int i = 0; i < sz; ++i)
#define dbg_array(x,sz) FOR(sz) cerr << x[i] << " \n"[i==sz-1]
#define X real()
#define Y imag()

const int d4i[4] = { -1, 0, 1, 0 }, d4j[4] = { 0, 1, 0, -1 };
const int d8i[8] = { -1, -1, 0, 1, 1, 1, 0, -1 }, d8j[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void _init_() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
#endif
}

const int N = 20 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

int solution1(int a, int b, int w) {
	int ans1 = 0;
	int tmp = w * 1000;
	int res = 0;
	while (tmp - a >= 0) {
		tmp -= a;
		res++;
		if (res >= a && res <= b) {
			ans1 = res;
		}
	}
	return ans1;
}
int solution2(int a, int b, int w) {
	if (w >= a && w <= b) return 1;

	int ans2 = 0;
	int tmp = w * 1000;
	int res = 0;
	int i = b;
	while (i >= a && tmp > 0) {
		int num = tmp - i;
		if (num > b) {
			tmp = num;
			++res;
			continue;
		} else {
			--i;
		}
		if (num >= a && num <= b) {
			res++;
			ans2 = res;
			break;
		}
	}
	return ans2;
}

void solve() {
	int a, b, w;
	scanf("%d%d%d", &a, &b, &w);
	if (w * 1000 < a) {
		puts("UNSATISFIABLE");
		return;
	}
	int ans1 = solution1(a, b, w);
	int ans2 = solution2(a, b, w);
	dbg2(ans1, ans2);
	if (ans1 == 0 || ans2 == 0) {
		puts("UNSATISFIABLE");
		return;
	}
	printf("%d %d\n", ans2, ans1);

}

int main() {
	_init_();
//	int t;
//	scanf("%d", &t);
//	while (t--) {
	solve();
//	}
	return 0;
}

