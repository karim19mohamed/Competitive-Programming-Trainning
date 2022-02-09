#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

vector <ll> prime_factorization(ll num){
	vector <ll> v;
	for (ll i=2;i*i<=num;++i) while(num%i==0) v.push_back(i),num/=i;
	if (num!=1) v.push_back(num);
	return v;
}

ll n;
int main() {
	while(cin>>n && n){
		ll non_negative=n;
		if (non_negative<0) non_negative*=(-1);
		(n<0)? printf("%lld = -1 x",n) : printf("%lld =",n);
		vector <ll> prime_factors = prime_factorization(non_negative);
		for (int i=0;i<prime_factors.size();++i){
			printf(" %lld",prime_factors[i]);
			if (i!=prime_factors.size()-1) printf(" x");
		}
		printf("\n");
	}

	return 0;
}









