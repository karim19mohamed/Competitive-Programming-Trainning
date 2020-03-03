#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

vector <ll> prime_factorization(ll num){ //O(sqrt(n))
	vector <ll> v;
	for (ll i=2;i*i<=num;++i) while(num%i==0) v.push_back(i),num/=i;
	if (num!=1) v.push_back(num);
	return v;
}
vector <ll> generate_divisors(ll num){
	vector <ll> v;
	ll i;
	for (i=1;i*i<num;++i) if (num%i==0) v.push_back(i),v.push_back(num/i);
	if (i*i==num) v.push_back(i);
	return v;
}
bool coprime(ll a,ll b){
	vector <ll> a_factors = prime_factorization(a);
	for (int i=0;i<(int)a_factors.size();++i) if (b%a_factors[i]==0) return false;
	return true;
}

int main() {
	ll n,c;
	while(cin>>n && n){
		vector <ll> divisors = generate_divisors(n);
		c=1;
		for (int i=0;i<(int)divisors.size();++i){
			for (int j=i+1;j<(int)divisors.size();++j){
				if (coprime(divisors[i],divisors[j])) ++c;
			}
		}
		printf("%lld %lld\n",n,c);
	}
	return 0;
}









