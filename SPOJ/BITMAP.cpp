#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N=190,M=190;
int ans[N][M];
int vid,vis[N][M];

int i_m[]={1,-1,0, 0};
int j_m[]={0, 0,1,-1};
int t,n,m;

struct node{
	int x,y;
};

void bfs(vector<string> &a){
	queue<node> q;
	for (int i=0;i<n;++i) for (int j=0;j<m;++j) if (a[i][j]=='1'){
		node src={i,j};
		vis[src.x][src.y]=++vid;
		ans[src.x][src.y]=0;
		q.push(src);
	}
	while (!q.empty()){
		int qsz=q.size();
		while (qsz--){
			node u=q.front(),v;
			q.pop();
			for (int i=0;i<4;++i){
				v.x=u.x+i_m[i];
				v.y=u.y+j_m[i];

				if (v.x<0 || v.x>=n) continue;
				if (v.y<0 || v.y>=m) continue;
				if (vis[v.x][v.y]==vid) continue;
				//dbg2(v.x,v.y);
				q.push(v);
				vis[v.x][v.y]=vid;
				ans[v.x][v.y]=min(ans[v.x][v.y],ans[u.x][u.y]+1);
				//ans[v.x][v.y]=min(ans[v.x][v.y],abs(v.x-src.x)+abs(v.y-src.y));
			}
		}
	}
}

int main() {

	scanf("%d",&t);
	while (t--){
		scanf("%d %d",&n,&m);
		for (int i=0;i<n;++i) for (int j=0;j<m;++j) ans[i][j]=100000;
		string s;
		vector<string> a;
		for (int i=0;i<n;++i) cin>>s,a.push_back(s);
		bfs(a);
		for (int i=0;i<n;++i){
			for (int j=0;j<m;++j){
				printf("%d",ans[i][j]);
				if (j!=m-1) printf(" ");
			}
			puts("");
		}
	}
    return 0;
}

















