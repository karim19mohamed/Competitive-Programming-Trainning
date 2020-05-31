#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

void dig(ll n,ll &min_d,ll &max_d){
	while(n){
		min_d=min(min_d,n%10);
		max_d=max(max_d,n%10);
		n/=10;
	}
}

int main() {
    int t;
    ll a,k;
    scanf("%d",&t);
    while(t--){
    	scanf("%lld %lld",&a,&k);
    	k--;
    	ll ans=a;
    	ll min_d=10,max_d=0;
    	while (min_d && k--){
    		min_d=10,max_d=0;
    		dig(a,min_d,max_d);
    		//dbg2(min_d,max_d);
    		ans=a+min_d*max_d;
    		a=ans;
    	}
    	printf("%lld\n",ans);
    }
    return 0;
}









