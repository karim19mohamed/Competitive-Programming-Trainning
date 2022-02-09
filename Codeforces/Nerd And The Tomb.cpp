#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N=1009;
int n,m,x,y;
char a[N][N];
bool vis[N][N];

int floodfill(int s1,int s2){
	if (a[s1][s2]=='*') return 0;
	if (s1<0 || s1>=n) return 0;
	if (s2<0 || s2>=m) return 0;

	//dbg3(s1,s2,a[s1][s2]);
	int ans=(a[s1][s2]=='#')?1:0;
	if (s1-1>=0 && !vis[s1-1][s2]){
		vis[s1-1][s2]=1;
		ans+=floodfill(s1-1,s2);
	}if (s2-1>=0 && !vis[s1][s2-1]){
		vis[s1][s2-1]=1;
		ans+=floodfill(s1,s2-1);
	}if (s1+1<n && !vis[s1+1][s2]){
		vis[s1+1][s2]=1;
		ans+=floodfill(s1+1,s2);
	}if (s2+1<m && !vis[s1][s2+1]){
		vis[s1][s2+1]=1;
		ans+=floodfill(s1,s2+1);
	}
	return ans;
}

int main() {
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;++i) for (int j=0;j<m;++j) cin>>a[i][j];
	scanf("%d %d",&x,&y);
	--x,--y;
	vis[x][y]=1;
	int ans=floodfill(x,y);
	printf("%d\n",ans);
    return 0;
}

















