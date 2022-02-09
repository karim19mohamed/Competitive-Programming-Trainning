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
#define OO 1e9

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

const int N = 30000 + 9, M = 400 - 9;
const ll Mod_M = 1e9 + 7;

template<typename T>
struct BIT {
	vector<T> v;
	int sz;
	explicit BIT(int n) {
		v.resize(n);
		sz = n;
	}
	T get(int i) {
		T ret;
		ret = 0;
		for (++i; i; i -= (i & -i))
			ret += v[i - 1];
		return ret;
	}
	void update(T val, int i) {
		for (++i; i <= sz; i += (i & -i))
			v[i - 1] += val;
	}
	T query(int st, int en) {
		return (en > 0) ? get(en) - get(st - 1) : get(en);
	}
	void print() {
		for (int i = 0; i < sz; ++i)
			cout << get(i) << " ";
		cout << endl;
	}
};

template<typename T2>
struct SET {
	BIT<T2> tree;
	explicit SET(int n) :
			tree(n) {
	}
	void insert(T2 val) {
		tree.update(1, val);
	}
	void erase(T2 val) {
		tree.update(-1, val);
	}
	T2 lowercount(T2 val) {
		return tree.get(val - 1);
	}
};

void solve() {
	int n, a[N], idx = 0;
	vector<string> inp;
	map<string, int> m;
	char tmp[29];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", tmp);
		inp.push_back(tmp);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%s", tmp);
		m[tmp] = idx++;
	}
	for (int i = 0; i < n; ++i) {
		a[i] = m[inp[i]];
		//dbg2(inp[i], m[inp[i]]);
	}
	SET<ll> tree_set(n);
	ll ans = 0;
	for (int i = n - 1; ~i; --i) {
		tree_set.insert(a[i]);
		ans += tree_set.lowercount(a[i]);
	}
	printf("%lld\n", ans);
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
