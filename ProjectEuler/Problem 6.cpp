#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

ll n=100,sum_squares,square_sum,ans;

int main() {
	for (int i=1;i<=n;++i){
		sum_squares+=i*i;
		square_sum+=i;
	}
	square_sum*=square_sum;
	ans=square_sum-sum_squares;
	dbg(ans);
	return 0;
}























