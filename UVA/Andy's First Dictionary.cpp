#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	string s;
	set<string> dict;
	set<string>::iterator it;
	while (!cin.eof()) {
		cin >> s;
		string ans = "";
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] < 'A' || (s[i] > 'Z' && s[i] < 'a') || s[i] > 'z') {
				if (ans.size())
					dict.insert(ans);
				ans = "";
			} else {
				if (s[i] < 97)
					s[i] += 32;
				ans += s[i];
			}
		}
		if (ans.size())
			dict.insert(ans);
		//for (it=dict.begin(); it!=dict.end(); ++it) cout<<*it<<endl;
		//cout<< endl;
	}
	for (it = dict.begin(); it != dict.end(); ++it)
		cout << *it << endl;
	return 0;
}

