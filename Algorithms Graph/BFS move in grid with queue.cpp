#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N=10,M=1e4+9;
int vid,vis[N][N];
int i_m[]={ 1, 1,-1,-1, 2, 2,-2,-2};
int j_m[]={ 2,-2, 2,-2, 1,-1, 1,-1};

struct node{
	int x,y;
};

int bfs(const node &src,const node &dest){
	queue<node> q;
	q.push(src);
	vis[src.x][src.y]=++vid;
	int lvl=0;
	while (!q.empty()){
		int qsz=q.size();
		while (qsz--){
			node u=q.front();
			q.pop();
			if (u.x==dest.x && u.y==dest.y) return lvl;
			for (int i=0;i<8;++i){
				int ii=i_m[i],jj=j_m[i];
				if (u.x+ii<0 || u.x+ii>=8) continue;
				if (u.y+jj<0 || u.y+jj>=8) continue;
				if (vis[u.x+ii][u.y+jj]==vid) continue;
				q.push({u.x+ii,u.y+jj});
				vis[u.x+ii][u.y+jj]=vid;
			}
		}
		++lvl;
	}
	return -1;
}

int main() {
	string x,y;
	while (cin>>x>>y){
		node src={x[0]-'a',x[1]-'1'},dest={y[0]-'a',y[1]-'1'};
		int ans=bfs(src,dest);
		cout<<"To get from "<<x<<" to "<<y<<" takes "<<ans<<" knight moves.\n";
	}
    return 0;
}

















