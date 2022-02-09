#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N=100+9;

int vid,vis[N],reached[N];

void dfs(int src,vector<int> (&adj)[N]){
	if (vis[src]==vid) return;
	vis[src]=vid;
	for (int i=0;i<adj[src].size();++i){
		if (vis[adj[src][i]]!=vid) dfs(adj[src][i],adj);
	}
}


int main() {
	int t,n,a,cs=1;
	scanf("%d",&t);
	while (t--){
		vid=0;
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		vector<int> adj[N];
		for (int i=0;i<n;++i)
			for (int j=0;j<n;++j){
				scanf("%d",&a);
				if(a) adj[i].push_back(j);
			}
		string s;
		vector<string> ans;
		++vid;
		dfs(0,adj);
		for (int i=0;i<n;++i) reached[i]=vis[i];
		for (int i=0;i<n;++i){
			s="|";
			++vid;
			vis[i]=vid;
			dfs(0,adj);
			for (int j=0;j<n;++j){
				( (vis[j]!=vid || i==0 || i==j) && (reached[j]) )? s+="Y|" : s+="N|";
			}
			ans.push_back(s);
		}
		s="+";
		for(int i=0;i<ans[0].size()-2;++i) s+="-";
		s+="+";
		printf("Case %d:\n",cs++);
		for(int i=0;i<ans.size();++i){
			cout<<s<<endl<<ans[i]<<endl;
		}
		cout<<s<<endl;
	}
    return 0;
}

















