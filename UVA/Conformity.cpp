#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int n,a[10009][5];
	while (scanf("%d", &n) && n){
		map < string,int> m;
		queue<string> q;
		int max_pop=1;
		for (int i=0;i<n;++i){
			for (int j=0;j<5;++j) scanf("%d", &a[i][j]);
			sort(a[i],a[i]+5);
			string tmp="";
			for (int j=0;j<5;++j) tmp+=to_string(a[i][j]);
			++m[tmp];
			max_pop=max(max_pop,m[tmp]);
			q.push(tmp);
		}
		int ans=0;
		while(!q.empty()){
			if (m[q.front()]==max_pop) ++ans;
			q.pop();
		}
		printf("%d\n",ans);
	}
    return 0;
}









