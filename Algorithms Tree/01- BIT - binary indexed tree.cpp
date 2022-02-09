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
		n = 1 << (int) ceil(log2(n));
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
	T kth_element_binary_search(int idx) {
		T st = 0, en = sz - 1;
		while (st < en) {
			T mid = st + (en - st) / 2;
			(get(mid) > idx) ? en = mid : st = mid + 1;
		}
		return st;
	}
	T kth_element_optimized(int idx) {
		int st = 0, sum = idx;
		for (int i = sz / 2; i; i /= 2)
			if (v[st + i - 1] <= sum)
				sum -= v[(st += i) - 1];
		return st;
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif
	int n, q;
	ll a;
	cin >> n;
	BIT<ll> tree(n);
	for (int i = 0; i < n; ++i) {
		cin >> a;
		tree.update(a, i);
	}
	cin >> q;
	char c;
	int st, en, idx;
	ll x;

	while (q--) {
		cin >> c;
		if (c == 'q') {
			cin >> st >> en;
			printf("%lld\n", tree.query(st - 1, en - 1));
		} else {
			cin >> idx >> x;
			tree.update(x, idx - 1);
		}
	}
	return 0;
}

