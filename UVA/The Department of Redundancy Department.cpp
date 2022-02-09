#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int n;
	map<int, int> arr;
	vector<int> x;
	while (scanf("%d", &n) != EOF) {
		if (!arr[n])
			x.push_back(n);
		++arr[n];
	}
	for (int i = 0; i < x.size(); ++i) {
		cout << x[i] << " " << arr[x[i]] << endl;
	}
	return 0;
}

