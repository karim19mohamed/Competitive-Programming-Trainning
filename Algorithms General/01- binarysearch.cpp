#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<double> point;
#define endl '\n'
#define f first
#define s second
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

void _init_() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);
#endif
}

const int N = 1e6 + 9, M = 1e3 + 9;
const int Mod_M = 1e9 + 7;

int arr[N], onlamp[N], sz = 0;

int binarysearch1(int num) { // FFFFFFFTTTT
	int s = 0, e = sz - 1;
	while (s < e) {
		int mid = s + (e - s) / 2;
		(onlamp[mid] >= num) ? e = mid : s = mid + 1;
	}
	return (onlamp[s] >= num) ? onlamp[s] : -1;
}
int binarysearch2(int num) { // TTTTTTTTTFFFF
	int s = 0, e = sz - 1;
	while (s < e) {
		int mid = s + (e - s + 1) / 2;
		(onlamp[mid] >= num) ? e = mid - 1 : s = mid;
	}
	return (onlamp[s] >= num) ? onlamp[s] : -1;
}

void solve() {

}
int main() {
	_init_();

	solve();

	return 0;
}
