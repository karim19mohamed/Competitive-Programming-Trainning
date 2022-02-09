#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 15 + 9;
bool row[N], col[N], dig1[N * 3], dig2[N * 3];

bool attacked(int x, int y) {
	return (row[x] || col[y] || dig1[x + y] || dig2[x - y + N]) ? 1 : 0;
}
void set_queen(int x, int y) {
	row[x] = col[y] = dig1[x + y] = dig2[x - y + N] = 1;
}
void unset_queen(int x, int y) {
	row[x] = col[y] = dig1[x + y] = dig2[x - y + N] = 0;
}

int solve(int q, int col, vector<string> &chess_b, const int &n) {
	if (col == n) {
		return (q == n);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!attacked(i, col) && chess_b[i][col] == '.') {
			set_queen(i, col);
			ans += solve(q + 1, col + 1, chess_b, n);
			unset_queen(i, col);
		}
	}
	return ans;
}

int main() {
	int n, cs = 1;

	string s;
	while (scanf("%d", &n) && n) {
		vector<string> chess_b;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			chess_b.push_back(s);
		}
		int ans = solve(0, 0, chess_b, n);
		printf("Case %d: %d\n", cs++, ans);
	}
	return 0;
}

