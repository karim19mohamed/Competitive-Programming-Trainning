#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 1e5 + 9, M = 400 - 9;
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

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif
	int n, a[N], asort[N];
	int mx = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		asort[i] = a[i];
		mx = max(mx, a[i]);
	}
	sort(asort, asort + n);
	map<int, int> compress;
	for (int i = 0; i < n; ++i)
		compress[asort[i]] = i;
	SET<ll> tree_set(n);
	ll ans = 0;
	for (int i = n - 1; ~i; --i) {
		tree_set.insert(compress[a[i]]);
		ans += tree_set.lowercount(compress[a[i]]);
	}
	printf("%lld\n", ans);
	return 0;
}

