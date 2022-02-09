#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 1e5 + 9, M = 20 + 9;
int n;
ll a[N];
ll valid(ll k) {
	priority_queue<ll> q;
	ll ans = 0;
	for (ll i = 0; i < n; ++i) {
		ll cost = a[i] + (i + 1) * k;
		q.push(-cost);
	}
	while (k--) {
		ans -= q.top();
		q.pop();
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif

	ll s;
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int st = 0, et = n;
	ll cost = 0;
	while (st < et) {
		int mid = st + (et - st + 1) / 2;
		ll tmp = valid((ll) mid);
		(tmp <= s) ? st = mid, cost = tmp : et = mid - 1;
	}
	cost = valid(st);
	printf("%d %lld\n", st, cost);
	return 0;
}

