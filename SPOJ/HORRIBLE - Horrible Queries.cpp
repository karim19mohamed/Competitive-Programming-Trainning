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

const int N = 1e5 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e8;

struct node;
extern node *empty;
enum DIR {
	L, R
};
struct node {
	ll v, sum;
	int p, sz;
	node *child[2], *par;
	ll lazy_prop;

	node() {
		v = sz = sum = 0;
		p = INT_MIN;
		child[L] = child[R] = par = this;
		lazy_prop = 0;
	}
	node(int val, node *l = empty, node *r = empty) {
		v = sum = val;
		p = rand();
		child[L] = l;
		child[R] = r;
		par = empty;
		lazy_prop = 0;
		push_up();
	}
	void push_up() {
		child[L]->par = child[R]->par = this;
		sum = child[L]->sum + child[R]->sum + v;
		sz = child[L]->sz + child[R]->sz + 1;
	}
	void push_down() {
		if (lazy_prop) {
			for (int i = 0; i < 2; ++i) {
				child[i]->operation(lazy_prop);
			}
			lazy_prop = 0;
		}
	}
	void operation(ll lazy) {
		if (this == empty) return;
		v += lazy;
		sum += lazy * sz;
		lazy_prop += lazy;
	}
};
node *empty = new node();

void split(node *rt, int ls_sz, node *&ls, node *&ge) {
	if (rt == empty) {
		ls = ge = empty;
		return;
	}
	rt->push_down();
	int left_sz = rt->child[L]->sz;
	if (ls_sz <= left_sz) {
		split(rt->child[L], ls_sz, ls, rt->child[L]);
		ge = rt;
	} else {
		split(rt->child[R], ls_sz - left_sz - 1, rt->child[R], ge);
		ls = rt;
	}
	rt->push_up();
	rt->par = empty;
}
node *merege(node *ls, node *ge) {
	if (ls == empty) return ge;
	if (ge == empty) return ls;
	ls->push_down();
	ge->push_down();
	if (ls->p > ge->p) {
		ls->child[R] = merege(ls->child[R], ge);
		ls->push_up();
		return ls;
	} else {
		ge->child[L] = merege(ls, ge->child[L]);
		ge->push_up();
		return ge;
	}
}
void print(node *rt, int depth = 0) {
	if (rt == empty) return;
	print(rt->child[L], depth + 1);
	printf("%s%2lld,%2d\n", string(5 * depth, ' ').c_str(), rt->v, rt->p);
	print(rt->child[R], depth + 1);
}
ll getByIndex(node *rt, int indx) {
	rt->push_down();
	if (indx == rt->child[L]->sz) return rt->v;
	int sum = rt->child[L]->sz + 1;
	if (indx < rt->child[L]->sz) return getByIndex(rt->child[L], indx);
	else return getByIndex(rt->child[R], indx - sum);
}
void unlazy(node *rt) {
	if (rt == empty) return;
	unlazy(rt->par);
	rt->push_down();
}
DIR dir(node *par, node *child) {
	return (DIR) (par->child[R] == child);
}
int getIndex(node *curr) {
	unlazy(curr);
	int res = curr->child[L]->sz;
	while (curr->par != empty) {
		if (dir(curr->par, curr) == R) res += curr->par->child[L]->sz + 1;
		curr = curr->par;
	}
	return res;
}
ll sub_quary_do_operation(node *&rt, int st, int en, int val = 0) {
	node *beginning, *ending;
	split(rt, en + 1, rt, ending);
	split(rt, st, beginning, rt);
	ll res = -1;
	rt->operation(val);
	res = rt->sum;
	rt = merege(merege(beginning, rt), ending);
	return res;
}

node *arr[N];
void solve() {
	int n, c;
	scanf("%d%d", &n, &c);
	node *rt = empty;
	for (int i = 0; i < n; ++i) {
		arr[i] = new node(0);
		rt = merege(rt, arr[i]);

	}

	for (int i = 0; i < c; ++i) {
		int q, bg, en;
		ll ans, val;
		scanf("%d", &q);
		if (q) {
			scanf("%d%d", &bg, &en);
			ans = sub_quary_do_operation(rt, bg - 1, en - 1);
			printf("%lld\n", ans);
		} else {
			scanf("%d%d%lld", &bg, &en, &val);
			ans = sub_quary_do_operation(rt, bg - 1, en - 1, val);
		}
	}
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
