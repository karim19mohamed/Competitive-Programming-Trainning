#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

vector <ll> m (1000009) ;
vector <ll> sieve(ll n){
	for (ll i=2;i<=n;++i) m[i]=i;
	vector <bool> is_prime (n+1,true);
	vector <ll> prime;
	for (ll i=2;i<=n;++i){
		if (!is_prime[i]) continue;
		else {
			prime.push_back(i);
			for (int j=2;i*j<=n;++j){
				is_prime[i*j]=0;
				m[i*j]=min(i,m[i,j]);
			}
		}
	}
	return prime;
}

int main() {
	int t;
	ll n,k;
	vector <ll> prime=sieve(1000009);
	//dbg(prime.size());
	scanf("%d",&t);
	while(t--){
		scanf("%lld %lld",&n,&k);
		ll ans=n+m[n]+(k-1)*2;
		printf("%lld\n",ans);

	}
	return 0;
}










