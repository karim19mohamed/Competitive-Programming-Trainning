#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

ll extend_GCD(ll a,ll b,ll &x,ll &y){ // a>b
	if (a<0){
		ll r = extend_GCD(-1*a,b,x,y);
		x*=-1;
		return r;
	}
	if (b<0){
		ll r = extend_GCD(a,-1*b,x,y);
		y*=-1;
		return r;
	}
	if (b==0){
		x=1,y=0;
		return a;
	}
	ll gcd = extend_GCD(b,a%b,y,x);
	// now x = y_previous & y = x_previous
	// calculate y = x_previous - (a/b) * y_previous
	y-=(a/b)*x;
	return gcd;
}
ll ldioph (ll a,ll b,ll c,ll &x,ll &y,bool &found){
	ll gcd = extend_GCD(a,b,x,y);
	if (found=c%gcd==0){
		x*=c/gcd,y*=c/gcd;
	}
	return gcd;
}
bool check_answer_in_range (ll a,ll b,ll c,ll X1,ll Y1,ll X2,ll Y2){ //[X1,Y1] [X2,Y2]
	ll x,y;
	bool found;
	ll gcd = (a>b)? ldioph (a,b,c,x,y,found) : ldioph (b,a,c,x,y,found);
	if (!found) return false;
	ll k1=ceil((X1-x)/a),k2=ceil((X2-y)/b);
	ll xx1=x+k1*b , yy1=y-k1*a , xx2=x-k1*b , yy2=y+k1*a;
	ll xx3=x+k2*b , yy3=y-k2*a , xx4=x-k2*b , yy4=y+k2*a;
	if (X1+a*x>=0 && Y1+a*x<=){
		return true;
	}else if (Y1+a*xx1>=0 && Y1+a*xx1<=F){
		return true;
	}else if(Y1+a*xx2>=0 && Y1+a*xx2<=F ){
		return true;
	}else if(Y1+a*xx3>=0 && Y1+a*xx3<=F ){
		return true;
	}else if(Y1+a*xx4>=0 && Y1+a*xx4<=F ){
		return true;
	}
	return false;
}


int main() {

	return 0;
}

















