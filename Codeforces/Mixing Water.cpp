#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 100000 + 9;
int T;
double h, c, t;
vector<int> odd;

double valid(int mid) {
	int num = odd[mid] / 2;
	double res = c * num + h * (num + 1);
	res /= (odd[mid] * 1.0);
	//dbg3(res, t, odd[mid]);
	return res;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	//freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);
#endif
	cin >> T;
	for (int i = 0; i < 2e6; ++i)
		if (i % 2)
			odd.push_back(i);
	while (T--) {
		cin >> h >> c >> t;
		if (t == h) {
			puts("1");
			continue;
		} else if (t == (h + c) / 2.0) {
			puts("2");
			continue;
		}
		int s = 0, e = odd.size() - 1;
		while (s < e) {
			int mid = s + (e - s + 1) / 2;
			(valid(mid) > t) ? s = mid : e = mid - 1;
			//dbg(e);
		}
		int ans = odd[s];
		double curr = valid(s);
		int ans1 = odd[s], ans2 = odd[s] + 2, ans3 = 2;
		if (s < (int) odd.size() - 1) {
			double res1 = valid(s), res2 = valid(s + 1);
			//dbg2(res1, res2);
			if (abs(res1 - t) > abs(res2 - t)) {
				ans = ans2;
				curr = res2;
			}
		}
		double res3 = (h + c) / 2.0;
		if (abs(res3 - t) <= abs(curr - t))
			ans = 2;
		printf("%d\n", ans);
	}

	return 0;
}

