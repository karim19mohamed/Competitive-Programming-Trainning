#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int n, a[109][109];
	while (scanf("%d", &n) && n) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &a[i][j]);
		int x = -1, y = -1;
		bool ch = 1, ok = 1;
		for (int i = 0; i < n; ++i) {
			int row = 0, col = 0;
			for (int j = 0; j < n; ++j) {
				row += a[i][j], col += a[j][i];
			}
			if (row % 2 || col % 2)
				ok = 0;
			if (row % 2)
				(x == -1) ? x = i : ch = 0;
			if (col % 2)
				(y == -1) ? y = i : ch = 0;
		}
		if (ok)
			puts("OK");
		else if (ch)
			printf("Change bit (%d,%d)\n", x + 1, y + 1);
		else
			puts("Corrupt");
	}

	return 0;
}

