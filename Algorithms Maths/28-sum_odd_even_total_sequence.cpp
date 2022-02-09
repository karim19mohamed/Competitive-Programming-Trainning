#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

ll sum_odd_seq(ll k){
	ll n;
	n=(k+1)/2;
	return n*n;
}
ll sum_even_seq(ll k){
	ll n;
	n=((k+2)/2)-1;
	return n*(n+1);
}
ll sum_total_seq(ll k){
	return k*(k+1)/2;
}

int main() {
	ll n=9;
	dbg2(n,sum_odd_seq(n));
	dbg2(n+1,sum_even_seq(n+1));
	dbg2(n,sum_total_seq(n));
	return 0;
}




















