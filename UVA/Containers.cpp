#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	string s;
	int cs=1;
	while(cin>>s && s!="end"){
		vector<char> v;
		for (int i=0;i<s.size();++i){
			bool found=0;
			for (int j=0;j<v.size();++j){
				if (v[j]>=s[i]){
					v[j]=s[i];
					found=1;
					break;
				}
			}
			if(!found) v.push_back(s[i]);
		}
		int ans=v.size();
		printf("Case %d: %d\n",cs++,ans);
	}
	return 0;
}


















