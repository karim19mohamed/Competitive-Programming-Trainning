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
	char s[N];
	scanf("%s", s);
	list<char> ans;
	bool d = 0;
	for (int i = 0; s[i]; ++i) {
		if (s[i] == 'R') {
			d ^= 1;
			continue;
		}
		if (!d) {
			ans.push_front(s[i]);
		} else {
			ans.push_back(s[i]);
		}
	}
//	dbg(s);
	vector<char> res;
	stack<char> st;
	for (std::list<char>::iterator it = ans.begin(); it != ans.end(); ++it) {
		if (st.empty()) {
			st.push(*it);
			continue;
		}
		if (st.top() != *it) {
			st.push(*it);
		} else {
			st.pop();
		}
	}
	while (!st.empty()) {
		res.push_back(st.top());
		st.pop();
	}
	if (!d) {
		for (int i = 0; i < int(res.size()); ++i)
			printf("%c", res[i]);
		puts("");
	} else {
		for (int i = int(res.size()) - 1; i >= 0; --i)
			printf("%c", res[i]);
		puts("");
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

