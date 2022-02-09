#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int t, n, m, a[10][10], cs = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		string s;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			for (int j = 0; j < s.size(); ++j)
				a[i][j] = s[j] - '0';
		}
		scanf("%d", &m);
		int aa, bb;
		while (m--) {
			cin >> s;
			if (s == "transpose") {
				for (int i = 0; i < n; ++i)
					for (int j = i + 1; j < n; ++j)
						swap(a[i][j], a[j][i]);
			} else if (s == "inc") {
				for (int i = 0; i < n; ++i)
					for (int j = 0; j < n; ++j)
						a[i][j] = (a[i][j] + 1 + 10) % 10;
			} else if (s == "dec") {
				for (int i = 0; i < n; ++i)
					for (int j = 0; j < n; ++j)
						a[i][j] = (a[i][j] - 1 + 10) % 10;
			} else if (s == "row") {
				scanf("%d %d", &aa, &bb);
				for (int i = 0; i < n; ++i)
					swap(a[aa - 1][i], a[bb - 1][i]);
			} else {
				scanf("%d %d", &aa, &bb);
				for (int i = 0; i < n; ++i)
					swap(a[i][aa - 1], a[i][bb - 1]);
			}
		}
		printf("Case #%d\n", cs++);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				printf("%d", a[i][j]);
			puts("");
		}
		puts("");
	}

	return 0;
}

