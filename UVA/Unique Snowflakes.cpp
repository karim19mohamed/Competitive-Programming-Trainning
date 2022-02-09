#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;


int main() {
	int t,n,cnt=1;
	scanf("%d",&t);
	map <int,int> vis;
	while(t--){
		scanf("%d",&n);
		vector <int> a(n);

		for (int i=0;i<n;++i) scanf("%d",&a[i]);
		int ans=1,pt1=0,pt2=0;
		while (pt1<n){
			vis[a[pt1]]=cnt;
			while (pt2+1<n && vis[a[pt2+1]]!=cnt){
				vis[a[++pt2]]=cnt;
			}
			ans=max(ans,pt2-pt1+1);
			vis[a[pt1]]=0;
			++pt1;
			if (pt1>pt2) pt2=pt1;
		}
		printf("%d\n",ans);
		cnt++;
	}

    return 0;
}









