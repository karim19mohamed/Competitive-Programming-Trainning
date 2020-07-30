#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const ll N = 1e6 + 9, M = 1e6 - 9, Max_ans = 1LL * (1e16);
int n, m;
ll c[N], dp[N];
ll solve(int idx) {
	if (idx + m >= n - 1)
		return 0;

	ll& ret = dp[idx];
	if (~ret && ret != Max_ans)
		return ret;

	ret = Max_ans;
	for (int i = idx + 1; i <= idx + m && i < n; ++i) {
		if (c[i])
			ret = min(ret, c[i] + solve(i));
	}
	//dbg2(c[idx], ret);
	return ret;
}
ll iter_solve_two_loops(int n) {
	ll iter_dp[n];
	//memset(iter_dp, , sizeof iter_dp);
	for (int idx = n - 1; idx >= 0; --idx) {
		ll& ret = iter_dp[idx];
		ret = Max_ans;
		for (int i = idx + 1; i <= idx + m && i < n; ++i) {
			if (c[i])
				ret = min(ret, c[i] + iter_dp[i]);
			if (i == n - 1) {
				ret = 0;
				break;
			}
		}
	}
	return iter_dp[0];
}
ll iter_solve(int n) {
	ll iter_dp[n];
	//memset(iter_dp, , sizeof iter_dp);
	priority_queue<pair<ll, int>> q;
	for (int idx = n - 1; idx >= 0; --idx) {
		ll& ret = iter_dp[idx];
		ret = Max_ans;
		if (n - 1 <= idx + m) {
			ret = 0;
		} else {
			while (!q.empty() && q.top().second > idx + m)
				q.pop();
			if (!q.empty()) {
				ret = -q.top().first;
			}
		}
		if (c[idx] != 0)
			q.push( { -ret - c[idx], idx });
	}
	return iter_dp[0];
}

int num, a, b, pi[N];
ll ci[N];

int prepare_c() {
	vector<int> a_to_root, b_to_root;
	int tmp_a = a, tmp_b = b;
	a_to_root.push_back(a);
	b_to_root.push_back(b);
	while (pi[tmp_a]) {
		a_to_root.push_back(pi[tmp_a]);
		tmp_a = pi[tmp_a];
	}
	while (pi[tmp_b]) {
		b_to_root.push_back(pi[tmp_b]);
		tmp_b = pi[tmp_b];
	}
	int comman_anc = -1;
	while (a_to_root.back() == b_to_root.back()) {
		comman_anc = a_to_root.back();
		a_to_root.pop_back();
		b_to_root.pop_back();
	}
	int idx = 0;
	for (int i = 0; i < (int) a_to_root.size(); ++i)
		c[idx++] = ci[a_to_root[i]];
	c[idx++] = ci[comman_anc];
	for (int i = (int) b_to_root.size() - 1; i >= 0; --i)
		c[idx++] = ci[b_to_root[i]];
	dbg_array(c, idx);
	return idx;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
//#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
	//freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);
//#endif
	int t, cs = 1;
	cin >> t;
	while (t--) {
		cin >> num >> m >> a >> b;
		for (int i = 1; i <= num; ++i)
			cin >> pi[i] >> ci[i];
		//cout << pi[2] << endl;
		n = prepare_c();
		// prepare c
		c[0] = c[n - 1] = 0;
		ll ans3 = iter_solve(n);
		if (ans3 >= Max_ans)
			printf("Case #%d: -1\n", cs++);
		else
			printf("Case #%d: %lld\n", cs++, ans3);
	}
	return 0;
}

