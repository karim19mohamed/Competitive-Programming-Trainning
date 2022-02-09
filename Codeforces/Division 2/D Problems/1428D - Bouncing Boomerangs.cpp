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

template<typename T_n> void read(T_n &n) {
	cin >> n;
}
template<typename T_n, typename T_a> void read(T_a a[], T_n n) {
	for (int i = 0; i < n; ++i)
		cin >> a[i];
}
template<typename T_n, typename T_a> void read(vector<T_a> &a, T_n n) {
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
}
void _init_() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);
#endif
}

const int N = 1e5 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e8;

void solve() {
	int n, a[N], row[N], col[N];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		row[i] = col[i] = 0;
	}
	for (int i = n - 1; i >= 0; --i)
		if (a[i] > 1) {
			puts("-1");
			return;
		} else {
			break;
		}
	vector<pair<int, int>> ans;
	int x = n - 1, y = 0, two_y = 0, last_three = -1;
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] == 0) {
			--x;
		} else if (a[i] == 1) {
			ans.push_back( { x, y });
			++row[x], ++col[y];
			++y, --x;
		} else if (a[i] == 2) {
			while (two_y < (int) ans.size() && col[ans[two_y].S] >= 2) {
				++two_y;
			}
			if (two_y >= (int) ans.size()) {
				puts("-1");
				return;
			}
			int tmp = ans[two_y].S;
			ans.push_back( { x, tmp });
			++row[x], ++col[tmp];
			++two_y;
			--x;
		} else if (a[i] == 3) {
			int tmp;
			if (last_three == -1) {
				while (two_y < (int) ans.size() && row[ans[two_y].F] >= 2) {
					++two_y;
				}
				if (two_y >= (int) ans.size()) {
					puts("-1");
					return;
				}
				tmp = ans[two_y].F;
				++two_y;
			} else {
				tmp = ans[last_three].F;
			}
			last_three = ans.size();
			ans.push_back( { x, y });
			++row[x], ++col[y];
			ans.push_back( { tmp, y });
			++row[tmp], ++col[y];
			++y, --x;
		}
	}
	printf("%d\n", (int) ans.size());
	for (auto v : ans) {
		printf("%d %d\n", n - v.S, v.F + 1);
	}

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
