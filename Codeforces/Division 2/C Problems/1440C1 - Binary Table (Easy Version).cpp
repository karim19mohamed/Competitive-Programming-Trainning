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
	freopen("input.in", "rt", stdin);
//	freopen("output.out", "wt", stdout);
#endif
}

const int N = 100 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

void solve() {
	int n, m;
	char s[N][N];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s", s[i]);
	int k = 0, a[3 * N * N][6];
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			if (s[i][j] == '1') {
				a[k][0] = i, a[k][1] = j;
				s[i][j] = '0';
				if (s[i][j + 1] == '1') {
					a[k][2] = i, a[k][3] = j + 1;
					s[i][j + 1] = '0';
					if (s[i + 1][j] == '1') {
						a[k][4] = i + 1, a[k][5] = j;
						s[i + 1][j] = '0';
					} else {
						a[k][4] = i + 1, a[k][5] = j + 1;
						s[i + 1][j + 1] = (s[i + 1][j + 1] == '1') ? '0' : '1';
					}
				} else {
					a[k][2] = i + 1, a[k][3] = j;
					a[k][4] = i + 1, a[k][5] = j + 1;
					s[i + 1][j] = (s[i + 1][j] == '1') ? '0' : '1';
					s[i + 1][j + 1] = (s[i + 1][j + 1] == '1') ? '0' : '1';
				}
				++k;
			}
		}
		if (s[i][m - 1] == '1') {
			a[k][0] = i, a[k][1] = m - 1;
			s[i][m - 1] = '0';
			a[k][2] = i + 1, a[k][3] = m - 1;
			a[k][4] = i + 1, a[k][5] = m - 2;
			s[i + 1][m - 1] = (s[i + 1][m - 1] == '1') ? '0' : '1';
			s[i + 1][m - 2] = (s[i + 1][m - 2] == '1') ? '0' : '1';
			++k;
		}
	}
	for (int j = 0; j < m - 1; ++j) {
		if (s[n - 1][j] == '1') {
			s[n - 1][j] = '0';
			a[k][0] = n - 1, a[k][1] = j;
			a[k][2] = n - 2, a[k][3] = j;
			a[k][4] = n - 2, a[k][5] = j + 1;
			++k;
			if (s[n - 1][j + 1] != '1') {
				a[k][0] = n - 1, a[k][1] = j;
				a[k][2] = n - 2, a[k][3] = j;
				a[k][4] = n - 1, a[k][5] = j + 1;
				++k;
				a[k][0] = n - 1, a[k][1] = j;
				a[k][2] = n - 1, a[k][3] = j + 1;
				a[k][4] = n - 2, a[k][5] = j + 1;
				++k;
			} else {
				s[n - 1][j + 1] = '0';
				a[k][0] = n - 1, a[k][1] = j + 1;
				a[k][2] = n - 2, a[k][3] = j;
				a[k][4] = n - 2, a[k][5] = j + 1;
				++k;
			}

		}
	}
	if (s[n - 1][m - 1] == '1') {
		a[k][0] = n - 1, a[k][1] = m - 1;
		a[k][2] = n - 2, a[k][3] = m - 1;
		a[k][4] = n - 2, a[k][5] = m - 2;
		++k;
		a[k][0] = n - 1, a[k][1] = m - 1;
		a[k][2] = n - 2, a[k][3] = m - 2;
		a[k][4] = n - 1, a[k][5] = m - 2;
		++k;
		a[k][0] = n - 1, a[k][1] = m - 1;
		a[k][2] = n - 1, a[k][3] = m - 2;
		a[k][4] = n - 2, a[k][5] = m - 1;
		++k;
	}
	printf("%d\n", k);
	for (int i = 0; i < k; ++i)
		for (int j = 0; j < 6; ++j)
			printf("%d%c", a[i][j] + 1, " \n"[j == 5]);

}
int main() {
	_init_();
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
