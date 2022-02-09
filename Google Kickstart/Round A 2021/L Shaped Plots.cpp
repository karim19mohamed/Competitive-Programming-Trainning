#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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

int r, c, a[N][N];
int cda[N][N][4];
void right_to_left() {
	for (int i = 0; i < r; ++i) {
		for (int j = 1; j < c; ++j) {
			if (!a[i][j]) {
				continue;
			}
			cda[i][j][0] = cda[i][j - 1][0] + a[i][j - 1];
		}
	}
}
void left_to_right() {
	for (int i = 0; i < r; ++i) {
		for (int j = c - 2; j >= 0; --j) {
			if (!a[i][j]) {
				continue;
			}
			cda[i][j][1] = cda[i][j + 1][1] + a[i][j + 1];
		}
	}
}
void up_to_down() {
	for (int j = 0; j < c; ++j) {
		for (int i = 1; i < r; ++i) {
			if (!a[i][j]) {
				continue;
			}
			cda[i][j][2] = cda[i - 1][j][2] + a[i - 1][j];
		}
	}
}
void down_to_up() {
	for (int j = 0; j < c; ++j) {
		for (int i = r - 2; i >= 0; --i) {
			if (!a[i][j]) {
				continue;
			}
			cda[i][j][3] = cda[i + 1][j][3] + a[i + 1][j];
		}
	}
}

int calculate(int num1, int num2) {
	int ret = 0;
	num1++, num2++;
	if (num1 > 1 && num2 > 1) {
		for (int i = 2; i <= num1 && i * 2 <= num2; ++i) {
			ret++;
		}
		for (int i = 2; i <= num2 && i * 2 <= num1; ++i) {
			ret++;
		}
	}
	return ret;
}

void solve() {

	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			scanf("%d", &a[i][j]);
	memset(cda, 0, sizeof(cda));
	right_to_left();
	left_to_right();
	up_to_down();
	down_to_up();
//	 debugging
//	for (int i = 0; i < r; ++i) {
//		puts("");
//		for (int j = 0; j < c; ++j)
//			printf("%d ", cda[i][j][3]);
//	}
	int ans = 0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (!a[i][j]) continue;
			int up, down, left, right;
			left = cda[i][j][0];
			right = cda[i][j][1];
			up = cda[i][j][2];
			down = cda[i][j][3];
			// up - right
			int res1 = calculate(up, right);
			// up - left
			int res2 = calculate(up, left);
			// down - right
			int res3 = calculate(down, right);
			// down - left
			int res4 = calculate(down, left);
			int total_res = res1 + res2 + res3 + res4;
			ans += total_res;
//			dbg3(i, j, total_res);
		}
	}
	printf("%d\n", ans);
}

int main() {
	_init_();
	int t, cs = 1;
	scanf("%d", &t);
	while (t--) {
		printf("Case #%d: ", cs++);
		solve();
	}
	return 0;
}

