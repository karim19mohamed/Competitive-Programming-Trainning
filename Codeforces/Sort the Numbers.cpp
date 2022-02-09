#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 100 + 9;

int main() {
	ifstream inFile;
	ofstream outfile;
	inFile.open("sort.in");
	outfile.open("sort.out");
	int n, a;
	while (inFile >> n) {
		vector<int> v;
		for (int i = 0; i < n; ++i) {
			inFile >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		outfile << v[0];
		for (int i = 1; i < n; ++i) {
			outfile << " " << v[i];
		}
		outfile << endl;
	}
	return 0;
}
