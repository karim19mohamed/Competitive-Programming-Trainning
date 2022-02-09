#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
    ll a,b,c,d;
    scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
    ll all=(d-c+1)*(c-b+1)*(b-a+1);
    ll z=c;
    while (z<b+c && z<d){
    	++z;
    }
    if (z==d && z<b+c){
    	printf("%lld\n",all);
    }else{
    	ll wrong=(d-z+1)*(c-b+1)*(b-a+1);
    	printf("%lld\n",all-wrong);
    }

    return 0;
}









