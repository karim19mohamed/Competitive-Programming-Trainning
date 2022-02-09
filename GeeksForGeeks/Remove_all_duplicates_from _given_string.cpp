// https://practice.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string/0

#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

//template<struct T>;
int t,res=1;
string s;
vector <bool> vis(126*2,false);
int main() {
	//code
	scanf("%d",&t);
	while(t--){
	    cin>>s;
	    for (int i=0;i<s.size();++i)
	        if(vis[s[i]+126]!=res){
	            cout<<s[i];
	            vis[s[i]+126]=res;
	        }
	    ++res;
	}
	return 0;
}
















