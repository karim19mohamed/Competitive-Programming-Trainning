#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	ll a,b,g,l;
	while(t--){
		scanf("%lld%lld",&g,&l);
		if (l%g!=0){
			printf("-1\n");
			continue;
		}
		a=g,b=l;
		printf("%lld %lld\n",a,b);
	}
	return 0;
}









