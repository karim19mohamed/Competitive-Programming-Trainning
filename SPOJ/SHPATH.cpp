#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N=10009,M=190;
map<string,int> name_idx;

int dis[N];

void dijkstra(const int &src,vector<pair<int,int> > (&adj)[N],const int &n){
	fill(dis, dis + n, 1e9);
	priority_queue< pair<int,int>,vector<pair<int,int> >,greater<> > q;
	q.push({0,src});
	dis[src]=0;
	while (!q.empty()){
		int u=q.top().second;
		int c=q.top().first;
		q.pop();
		if (dis[u]!=c) continue;
		for (auto v : adj[u]){
			if (dis[v.first]>v.second+c){
				q.push({v.second+c,v.first});
				dis[v.first]=v.second+c;
			}
		}
	}
}

int main() {
	int t,n,p,nr,cost,r;
	string s,a,b;
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		vector<pair<int,int> > adj[N];
		for (int i=0;i<n;++i){
			cin>>s;
			name_idx[s]=i;
			scanf("%d",&p);
			while(p--){
				scanf("%d %d",&nr,&cost);
				adj[i].push_back({nr-1,cost});
			}
		}
		scanf("%d",&r);
		while(r--){
			cin>>a>>b;
			//dbg2(name_idx[a],name_idx[b]);
			dijkstra(name_idx[a],adj,n);
			printf("%d\n",dis[name_idx[b]]);
		}
	}
    return 0;
}

















