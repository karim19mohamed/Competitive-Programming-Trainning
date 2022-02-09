#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 200000 + 9, M = 400 - 9;
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

template<typename T2>
struct multiSET {
	BIT<T2> tree;
	explicit multiSET(int n) :
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

template<typename T3>
struct SET {
	BIT<T3> tree;
	T3 sz;
	explicit SET(T3 n) :
			tree(n), sz(n) {
	}
	void insert(T3 val) {
		if (!cnt(val))
			tree.update(1, val);
	}
	void erase(T3 val) {
		if (cnt(val))
			tree.update(-1, val);
	}
	int cnt(T3 val) {
		return tree.query(val, val);
	}
	T3 size() {
		return tree.get(sz - 1);
	}
	T3 lowercount(T3 val) {
		return tree.get(val - 1);
	}
	T3 kth_element(T3 idx) {
		//return tree.kth_element_binary_search(idx);
		return tree.kth_element_optimized(idx);
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif
	int q;
	cin >> q;
	char c[N];
	int x[N], xsort[N], x_sz = 0;
	for (int i = 0; i < q; ++i) {
		cin >> c[i] >> x[i];
		if (c[i] != 'K')
			xsort[x_sz++] = x[i];
	}
	sort(xsort, xsort + x_sz);
	map<int, int> compress, uncompress;
	for (int i = 0; i < x_sz; ++i)
		compress[xsort[i]] = i, uncompress[i] = xsort[i];
	SET<int> tree_set(x_sz);
	for (int i = 0; i < q; ++i) {
		if (c[i] == 'I') {
			tree_set.insert(compress[x[i]]);
		} else if (c[i] == 'D') {
			tree_set.erase(compress[x[i]]);
		} else if (c[i] == 'C') {
			printf("%d\n", tree_set.lowercount(compress[x[i]]));
		} else {
			if (tree_set.size() < x[i]) {
				puts("invalid");
			} else {
				printf("%d\n", uncompress[tree_set.kth_element(x[i] - 1)]);
			}
		}
	}

	return 0;
}

