#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl

using namespace std;

int main() {
	string s, a, b;
	map<string, string> m;
	while (getline(std::cin, s) && s.size()) {
		stringstream in(s);
		in >> a >> b;
		m[b] = a;
	}
	while (cin >> b) {
		if (m.count(b))
			cout << m[b] << endl;
		else
			puts("eh");
	}
	return 0;
}

