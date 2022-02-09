#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

ll POW (ll b,ll p){ // a>b
	if (p==0) return 1;
	ll sq=POW(b,p/2);
	sq=(sq*sq);
	if (p%2) sq=(sq*b);
	return sq;
}
bool check_fib (vector<ll> f,ll a,ll b,ll m){
	ll c;
	for (int i=0;i<f.size();++i){
		c=(a%m+b%m)%m;
		if (f[i]!=c) return false;
		b=a;
		a=c;
	}
	return true;
}
vector <ll> fib (ll m){
	vector<ll> f;
	f.push_back(0),f.push_back(1);
	ll a,b,c;
	while(1){
		a=f[f.size()-1],b=f[f.size()-2];
		c=(a%m+b%m)%m;
		if (c==0){
			if (check_fib(f,a,b,m)) break;
		}
		f.push_back(c);
	}
	return f;
}

int main() {
	ll n;
	ll m;
	vector <ll> f[21];
	for (ll i=1;i<21;++i){
		ll m=POW(2,i);
		f[i]=fib(m);
	}

	while (cin>>n>>m){
		if (m==0){
			printf("0\n");
			continue;
		}
		n%=(long long)f[m].size();
		printf("%d\n",f[m][n]);
	}


	return 0;
}























