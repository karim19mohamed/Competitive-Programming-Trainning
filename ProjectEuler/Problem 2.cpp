#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

ll f1=1,f2=2,n=4000000,ans,sss;

int main() {
	ans=2;
	while (f2<=n){
		ll tmp=f2;
		f2=f1+f2;
		f1=tmp;
		if(f2%2==0){
			ans+=f2;
			dbg2(f2,ans);
		}
		dbg(f2);
	}
	dbg(ans);
	return 0;
}























