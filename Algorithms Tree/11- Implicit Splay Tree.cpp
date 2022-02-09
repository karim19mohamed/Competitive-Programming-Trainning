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

const int N = 5e5 + 9, SEG = 131072; // SEG = 1 << ((int) ceil(log2(N)) + 1)
const int Mod_M = 1e8;

struct node;
extern node *empty;
enum DIR {
	L, R
};
struct node {
	ll v;
	int sz;
	node *child[2], *par;
	bool lazy_prop;

	node() {
		v = sz = 0;
		child[L] = child[R] = par = this;
		lazy_prop = 0;
	}
	node(int val, node *l = empty, node *r = empty) {
		v = val;
		par = empty;
		child[L] = l;
		child[R] = r;
		push_up();
	}
	void push_up() {
		sz = child[L]->sz + child[R]->sz + 1;
		for (int i = 0; i < 2; ++i)
			if (child[i] != empty) child[i]->par = this;
	}
	void push_down() {
		if (lazy_prop) {
			for (int i = 0; i < 2; ++i)
				child[i]->operation();
			lazy_prop = false;
		}
	}
	void operation() {
		if (this == empty) return;
		swap(child[L], child[R]);
		lazy_prop ^= 1;
	}
};
node *empty = new node();
void link(node *par, node *child, DIR dir) {
	if (par != empty) {
		par->child[dir] = child;
		par->push_up();
	}
	if (child != empty) {
		child->par = par;
	}
}
DIR dir(node *par, node *child) {
	return (DIR) (par->child[R] == child);
}
void rotate(node *rt, DIR dr) {
	/*
	 .     p                           q
	 .    / \     <--shift right--    / \
	 .   a   q    ---shift left-->   p   c
	 .      / \                     / \
	 .     b   c                   a   b
	 . consider rt as p to get rid of call-of-reference
	 */
	node *par = rt->par;
	DIR dpar = dir(par, rt);
	node *q = rt->child[!dr];
	node *b = q->child[dr];
	link(rt, b, (DIR) !dr);
	link(q, rt, dr);
	link(par, q, dpar);
}
node *splay(node *curr) {
	while (curr->par != empty) {
		node *par = curr->par;
		DIR pd = dir(par, curr);
		if (par->par == empty) {
			rotate(par, (DIR) !pd);
			continue;
		}
		node *grnd_par = par->par;
		DIR gd = dir(grnd_par, par);
		if (pd == gd) {
			rotate(grnd_par, (DIR) !gd);
			rotate(par, (DIR) !pd);
		} else {
			rotate(par, (DIR) !pd);
			rotate(grnd_par, (DIR) !gd);
		}
	}
	return curr;
}
node *splay(node *rt, int indx) {
	rt->push_down();
	int left_sz = rt->child[L]->sz;
	if (left_sz == indx) rt = splay(rt);
	else if (indx < left_sz) rt = splay(rt->child[L], indx);
	else rt = splay(rt->child[R], indx - left_sz - 1);
	return rt;
}
node *merege(node *ls, node *ge) {
	if (ls == empty) return ge;
	if (ge == empty) return ls;
	ls->push_down();
	ge->push_down();
	ge = splay(ge, 0);
	link(ge, ls, L);
	return ge;
}
void split(node *rt, int left_sz, node *&ls, node *&ge) {
	if (left_sz == rt->sz) {
		ls = rt;
		ge = empty;
		return;
	}
	rt->push_down();
	rt = splay(rt, left_sz);
	ls = rt->child[L];
	link(empty, ls, L);
	link(rt, empty, L);
	ge = rt;
}
void print(node *rt, int depth = 0) {
	if (rt == empty) return;
	print(rt->child[L], depth + 1);
	printf("%s(%2lld,%2lld)\n", string(7 * depth, ' ').c_str(), rt->v, rt->par->v);
	print(rt->child[R], depth + 1);
}

void unlazy(node *rt) {
	if (rt == empty) return;
	unlazy(rt->par);
	rt->push_down();
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
void sub_quary_do_operation(node *&rt, int st, int en) {
	node *beginning, *ending;
	split(rt, en + 1, rt, ending);
	split(rt, st, beginning, rt);
	rt->operation();
	rt = merege(merege(beginning, rt), ending);
}
node *arr[N];
void solve() {
	int n, a;
	while (scanf("%d", &n), n) {
		node *rt = empty;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a);
			arr[i] = new node(a);
			rt = merege(rt, arr[i]);
		}
		stable_sort(arr, arr + n, [](node *a,node *b) {
			return a->v <b->v;
		});
		for (int i = 0; i < n; ++i) {
			int idx = getIndex(arr[i]);
			printf("%d%c", idx + 1, " \n"[i == n - 1]);
			sub_quary_do_operation(rt, i, idx);
		}
	}
}
int main() {
	_init_();
//	int t;
//	cin >> t;
//	while (t--) {
	solve();
//	}
	return 0;
}
