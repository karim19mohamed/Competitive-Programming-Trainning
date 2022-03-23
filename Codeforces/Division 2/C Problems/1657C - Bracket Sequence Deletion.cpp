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

const int N = 5e5 + 9, M = 1e8 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e9 + 7;

void solve() {
	int n;
	char s[N];
	scanf("%d%s", &n, s);

	int c = 0, r = n, cur_indx = 0;

	stack<char> regular_stack;
	bool put_in_stack = true;

	vector<char> pal_vector;

	for (int i = 0; i < n; ++i) {
		// regular check
		if (put_in_stack) {
			if (s[i] == ')' && regular_stack.size() == 0) {
				put_in_stack = false;
			} else if (s[i] == ')') {
				regular_stack.pop();
				if (regular_stack.size() == 0) {
					++c;
					r = r - (i - cur_indx + 1);
					// reset palindrome check
					vector<char>().swap(pal_vector);
//					pal_vector.clear();
					cur_indx = i + 1;
					continue;
//					dbg(i);
				}
			} else {
				regular_stack.push(s[i]);
			}
		}

		// palindrome check
		pal_vector.push_back(s[i]);
		if (pal_vector.size() >= 2) {
			bool pal_checker = true;
			int sz = (int) pal_vector.size();
			for (int j = 0; j < sz / 2; ++j) {
				if (pal_vector[j] != pal_vector[sz - 1 - j]) {
					pal_checker = false;
					break;
				}
			}
			if (pal_checker) {
				++c;
				r = r - (i - cur_indx + 1);
				// reset palindrome check
				vector<char>().swap(pal_vector);
//				pal_vector.clear();
				cur_indx = i + 1;
				stack<char>().swap(regular_stack);
				put_in_stack = true;
//				dbg(i);
			}
		}

	}
	printf("%d %d\n", c, r);
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

