#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

using namespace std;
map<string, int> m;

int main() {
	string s, proc;
	queue<string> q;
	int idx = 1;
	proc = "a";
	for (int i = 0; i < 26; ++i) {
		m[proc] = idx++;
		q.push(proc);
		++proc[0];
	}
	bool end_of_list = 0;
	while (!q.empty()) {
		proc = q.front();
		int sz = proc.size();
		string c = "a";
		for (int i = 0; i < 26; ++i) {
			bool chk = 1;
			for (int j = 0; j < sz; ++j)
				if (proc[j] >= c[0])
					chk = 0;
			if (chk) {
				string compin = proc + c;
				m[compin] = idx++;
				q.push(compin);
				if (compin == "vwxyz") {
					end_of_list = 1;
					break;
				}
			}
			++c[0];
		}
		q.pop();
		if (end_of_list)
			break;
	}
	while (cin >> s) {
		printf("%d\n", m[s]);
	}

	return 0;
}

