#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;



int main() {
	int n,m,a[100009],cdf[100009],q;
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		cdf[i]=cdf[i-1]+a[i];
	}
	scanf("%d",&m);
	for (int i=0;i<m;++i){
		scanf("%d",&q);
		int s=0,e=n;
		while(s<e){
			int mid=s+(e-s)/2;
			(cdf[mid]<q)? s=mid+1 : e=mid;
		}
		printf("%d\n",s);
	}
	return 0;
}


















