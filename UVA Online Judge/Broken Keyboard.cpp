#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

///////////////////////////// have problem in a[b[c
int main() {
	char s[1000000];
	while(scanf("%s",s)!=EOF){
		int len = strlen (s);
		deque <string> q;
		//dbg(len);
		bool direction=0;
		string ans="",tmp="";
		for (int i=0;i<len;++i){
			if (s[i]=='['){
				direction=1;
				continue;
			}else if (s[i]==']'){
				direction=0;
				continue;
			}else{
				if(!direction){
					if (tmp.size()>0) q.push_front(tmp),tmp="";
					ans = ans+s[i];
				}else{
					if (ans.size()>0) q.push_back(ans),ans="";
					tmp = tmp+s[i];
				}
			}
		}
		if (tmp.size()>0) q.push_front(tmp),tmp="";
		if (ans.size()>0) q.push_back(ans),ans="";
		while(!q.empty()) printf("%s",&q.front()[0]),q.pop_front();
		printf("\n");
	}
	return 0;
}


















