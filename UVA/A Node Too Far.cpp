#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N=20000,M=1e4+9;
int vid,vis[N];

void bfs(const int &src,vector<int> (&a)[N],vector<int> (&level)[N]){
	queue<int> q;
	q.push(src);
	vis[src]=++vid;
	int lvl=0, pre=0;
	while (!q.empty()){
		int qsz=q.size();
		level[src].push_back(pre+qsz);
		pre=level[src].back();
		while (qsz--){
			int u=q.front();
			q.pop();
			for (auto v : a[u]){
				if (vis[v]!=vid){
					q.push(v);
					vis[v]=vid;
				}
			}
		}
		++lvl;
	}
}

int main() {
	int m,x,y,cs=1;
	while (scanf("%d",&m) && m){
		int n=0;
		vector<int> a[N],level[N];
		vector<bool> tmp(N,false);
		for (int i=0;i<m;++i){
			scanf("%d %d",&x,&y);
			if (!tmp[x]) tmp[x]=1,++n;
			if (!tmp[y]) tmp[y]=1,++n;
			a[x].push_back(y),a[y].push_back(x);
		}
		while (scanf("%d %d",&x,&y) && x+y){
			if (level[x].empty()) bfs(x,a,level);
			int ans= (y<level[x].size())? level[x].back()-level[x][y]: 0;
			ans+=(n-level[x].back());
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n"
					,cs++,ans,x,y);
		}
	}
    return 0;
}

















