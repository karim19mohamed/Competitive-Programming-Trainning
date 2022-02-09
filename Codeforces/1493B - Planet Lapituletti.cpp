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

const int N = 1000 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

vector<int> generate() {
	vector<int> ret(N, -1);
	int a[5] = { 0, 1, 2, 5, 8 };
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			int x = a[i], y = a[j];
			int num = x * 10 + y;
			if (x == 2) {
				x = 5;
			} else if (x == 5) {
				x = 2;
			}
			if (y == 2) {
				y = 5;
			} else if (y == 5) {
				y = 2;
			}
			ret[num] = x + y * 10;
		}
	}
	return ret;
}
int solution(vector<int> all, int a, int m, int h) {
	int ans = -1;
	while (ans == -1) {
		if (all[a] != -1 && all[a] < m) {
			ans = a;
		}
		a = (a + 1) % h;
	}
	return ans;
}

void solve(vector<int> all) {
	int h, m;
	scanf("%d%d", &h, &m);
	int a, b;
	char c;
	scanf("%d%c%d", &a, &c, &b);
	int ans_h = solution(all, a, m, h);
	int ans_m = solution(all, b, h, m);
//	dbg2(ans_h, ans_m);
	if (ans_h > a || ans_h < a) {
		ans_m = 0;
	} else if (ans_h == a && ans_m < b) {
		ans_h = solution(all, (a + 1) % h, m, h);
		ans_m = 0;
	}

	if (ans_h / 10 == 0) printf("0");
	printf("%d:", ans_h);
	if (ans_m / 10 == 0) printf("0");
	printf("%d\n", ans_m);
}

int main() {
	_init_();
	vector<int> all = generate();
	int t;
	scanf("%d", &t);
	while (t--) {
		solve(all);
	}
	return 0;
}

