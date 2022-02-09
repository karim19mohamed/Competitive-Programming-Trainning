#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<double> point;
#define endl '\n'
#define f first
#define s second
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

const int N = 1e5 + 9, M = 10 + 9;
const int Mod_M = 1e9 + 7;

int root, nxt[N][M], cnt[N], nNodes, hasChild[N];
bool ok[N];

int createNode() {
	memset(nxt[nNodes], -1, sizeof nxt[nNodes]);
	ok[nNodes] = hasChild[nNodes] = cnt[nNodes] = 0;
	return nNodes++;
}
void init_tries() {
	nNodes = 0;
	root = createNode();
}
void addstring(char s[]) {
	int cur = root;
	for (int i = 0; s[i]; ++i) {
		int& child = nxt[cur][s[i] - '0'];
		if (child == -1) {
			++hasChild[cur];
			child = createNode();
		}
		cur = child;
	}
	++cnt[cur];
}
int cntstring(char s[]) {
	int cur = root;
	for (int i = 0; s[i]; ++i) {
		int& child = nxt[cur][s[i] - '0'];
		if (child == -1) child = createNode();
		cur = child;
	}
	return cnt[cur];
}
bool add(char s[]) { // add strings and check if one is prefix of another
	int cur = root;
	for (int i = 0; s[i]; ++i) {
		int& child = nxt[cur][s[i] - '0'];
		if (child == -1) {
			++hasChild[cur];
			child = createNode();
		}
		cur = child;
		if (ok[cur]) return 0;
	}
	ok[cur] = 1;
	if (hasChild[cur]) return 0;
	return 1;
}

void solve() {
	int n;
	cin >> n;
	init_tries();
	bool ans = 1;
	char s[M];
	while (n--) {
		cin >> s;
		addstring(s);
		cout << s << " " << cntstring(s) << endl;
	}
}
int main() {
	_init_();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
