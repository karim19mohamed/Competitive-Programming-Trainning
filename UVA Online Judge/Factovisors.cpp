#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

ll FactN_PrimePower(ll n,ll p){
	ll pow=0;
	for(ll i=p;i<=n;i*=p) pow+=n/i;
	return pow;
}
vector <ll> prime_factorization(ll num){ //O(sqrt(n))
	vector <ll> v;
	for (ll i=2;i*i<=num;++i) while(num%i==0) v.push_back(i),num/=i;
	if (num!=1) v.push_back(num);
	return v;
}
bool is_prime(ll n){
	if (n==2) return true;
	if (n<2 || n%2==0) return false;
	for (ll i=3;i*i<n;i+=2){
		if (n%i==0){
			return false;
		}
	}
	return true;
}

ll n,m;
int main() {
	while (cin>>n>>m){
		if (m==0) {
			printf("%lld divides %lld!\n",m,n);
			continue;
		}
		vector <ll> prim_fact = prime_factorization (m);
		map <ll,ll> a;
		bool ans=1;
		for (ll i=0;i<prim_fact.size();++i) ++a[prim_fact[i]];
		for (ll i=0;i<prim_fact.size();++i){
			ll pow = FactN_PrimePower(n,prim_fact[i]);
			if (pow<a[prim_fact[i]]){
				ans=0;
				break;
			}
		}
		(ans)? printf("%lld divides %lld!\n",m,n):printf("%lld does not divide %lld!\n",m,n);
	}
	printf("\n");
	return 0;
}









