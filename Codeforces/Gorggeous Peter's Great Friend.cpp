#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define dbg_array(x,sz) for (int i = 0; i < sz; ++i) cout << x[i] << " \n"[i==sz-1]
using namespace std;

const int N = 1e4 + 9, M = 1000 + 9;
map<string, int> nametoint, probtoint;
map<int, string> inttoname, inttoprob;
map<int, int> ans;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
//freopen("output.out", "wt", stdout);
#endif
	int cand, prob, sub, score, idx = 1;
	string s, a, b, c;
	cin >> cand >> prob >> sub;
	for (int i = 0; i < cand; ++i) {
		cin >> s;
		nametoint[s] = idx;
		inttoname[idx] = s;
		++idx;
	}
	for (int i = 0; i < prob; ++i) {
		cin >> s >> score;
		probtoint[s] = score;
		inttoprob[score] = s;
	}
	while (sub--) {
		cin >> a >> b >> c;
		if (c == "AC") {
			if (nametoint.count(a) && probtoint.count(b)) {
				ans[nametoint[a]] += probtoint[b];
			}
		}
	}
	for (int i = 1; i <= cand; ++i) {
		cout << inttoname[i] << " " << ans[i] << endl;
	}
	return 0;
}

