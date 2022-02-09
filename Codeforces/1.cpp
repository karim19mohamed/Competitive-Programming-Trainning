#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N=20;

int main() {
	string s;
	cin>>s;
	set<char> c;
	for (int i=0;i<s.size();++i) c.insert(s[i]);
	for (set<char>::iterator it=c.begin(); it!=c.end(); ++it) cout << *it;
	cout << endl;
    return 0;
}

















