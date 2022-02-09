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
	int p, sz, freq;
	node *child[2];

	node() {
		v = sz = freq = 0;
		p = INT_MIN;
		child[L] = child[R] = this;
	}
	node(int val, node *l = empty, node *r = empty) {
		v = val;
		p = rand();
		freq = 1;
		child[L] = l;
		child[R] = r;
		push_up();
	}
	void push_up() {
		sz = child[L]->sz + child[R]->sz + freq;
	}
};
node *empty = new node();

void split(node *rt, const ll val, node *&ls, node *&ge) {
	if (rt == empty) {
		ls = ge = empty;
		return;
	}
	if (val < rt->v) {
		split(rt->child[L], val, ls, rt->child[L]);
		ge = rt;
	} else {
		split(rt->child[R], val, rt->child[R], ge);
		ls = rt;
	}
	rt->push_up();
}
node *merege(node *ls, node *ge) {
	if (ls == empty) return ge;
	if (ge == empty) return ls;
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
void insert(node *&rt, node *nd) {
	if (rt == empty) {
		rt = nd;
		return;
	}
	if (nd->p > rt->p) {
		split(rt, nd->v, nd->child[L], nd->child[R]);
		rt = nd;
	} else if (nd->v < rt->v) {
		insert(rt->child[L], nd);
	} else {
		insert(rt->child[R], nd);
	}
	rt->push_up();
}
bool freq_increased(node *&rt, const ll &val) {
	if (rt == empty) return false;
	if (rt->v == val) {
		++rt->freq;
		return true;
	}
	bool ret = freq_increased((val < rt->v) ? rt->child[L] : rt->child[R], val);
	if (ret) rt->push_up();
	return ret;
}
void insert(node *&rt, const ll &val) {
	if (!freq_increased(rt, val)) insert(rt, new node(val));
}
void erase(node *&rt, const ll &val) {
	if (rt == empty) return;
	if (val < rt->v) {
		erase(rt->child[L], val);
	} else if (val > rt->v) {
		erase(rt->child[R], val);
	} else {
		if (rt->freq > 1) {
			--rt->freq;
		} else {
			node *tmp = rt;
			rt = merege(tmp->child[L], tmp->child[R]);
			delete tmp;
		}
	}
	rt->push_up();
}
void print(node *rt, int depth = 0) {
	if (rt == empty) return;
	print(rt->child[L], depth + 1);
	printf("%s%2lld,%2d\n", string(5 * depth, ' ').c_str(), rt->v, rt->p);
	print(rt->child[R], depth + 1);
}
ll getByIndex(node *rt, int indx) {
	if (indx == rt->child[L]->sz) return rt->v;

	int sum = rt->child[L]->sz + rt->freq;
	if (indx < rt->child[L]->sz) return getByIndex(rt->child[L], indx);
	else return getByIndex(rt->child[R], indx - sum);
}
int getCount(node *&rt, const ll &val) {
	if (rt == empty) return 0;
	if (rt->v == val) return rt->freq;
	return getCount((val < rt->v) ? rt->child[L] : rt->child[R], val);
}
int lower_bound(node *&rt, const ll &val) {
	if (rt == empty) return 0;
	if (rt->v == val) return rt->child[L]->sz;

	if (rt->v < val) return rt->child[L]->sz + rt->freq + lower_bound(rt->child[R], val);

	return lower_bound(rt->child[L], val);
}

void solve() {
	int n, val;
	char type;
	node *rt = empty;
	scanf("%d", &n);
	while (n--) {
		scanf(" %c %d", &type, &val);
		switch (type) {
		case 'I':
			if (getCount(rt, val) == 0) insert(rt, val);
			break;
		case 'D':
			erase(rt, val);
			break;
		case 'K':
			if (val > rt->sz) puts("invalid");
			else printf("%lld\n", getByIndex(rt, val - 1));
			break;
		case 'C':
			printf("%d\n", lower_bound(rt, val));
			break;
		}
//		print(rt);
//		puts("----------------------------------------------");
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
