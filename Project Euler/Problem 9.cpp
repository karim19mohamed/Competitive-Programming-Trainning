#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

//a + b + c = 1000.
ll ans,a,b,c;

int main() {
	for (int i=1;i<=1000;++i){
		for (int j=1;j<=1000;++j){
			a=i,b=j,c=1000-a-b;
			if (c<=0) continue;
			if (a>b && a>c && a*a==b*b+c*c){
				ans=a*b*c;dbg3(a,b,c);
				break;
			}else if (b>a && b>c && b*b==a*a+c*c){
				ans=a*b*c;dbg3(a,b,c);
				break;
			}else if (c>b && c>a && c*c==b*b+a*a){
				ans=a*b*c;dbg3(a,b,c);
				break;
			}

		}
	}
	dbg(ans);
	return 0;
}























