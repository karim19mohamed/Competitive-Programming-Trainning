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
bool check_path (vector <ll> X,vector <ll> Y,ll A,ll B,ll E,ll F){
	bool ans_exist1=0,ans_exist2=0;
	queue <ll> connected_to_bingn;
	vector <ll> connected_to_ennd;
	for (ll i=0;i<E;++i){
		if (A-Y[i]>=0 && (A-Y[i])%X[i]==0) ans_exist1=1,connected_to_bingn.push(i);//,dbg2("begin",i);
		if (B-Y[i]>=0 && (B-Y[i])%X[i]==0) ans_exist2=1,connected_to_ennd.push_back(i);//,dbg2("end",i);
	}
	vector <bool> chk(E,0);
	bool ans=0;
	while (!connected_to_bingn.empty() && ans_exist1 && ans_exist2){
		ll curr=connected_to_bingn.front();
		connected_to_bingn.pop();
		chk[curr]=1;
		ll X1=X[curr],Y1=Y[curr];
		ll X2,Y2;
		for (int i=0;i<(int)connected_to_ennd.size();++i) if (curr==connected_to_ennd[i]) return 1;
		for (ll i=0;i<E;++i){
			if (chk[i]) continue;
			X2=X[i],Y2=Y[i];
			ll x,y;
			bool found;
			//dbg3 (X1,X2,Y2-Y1);
			ll gcd = (X1>X2)? ldioph (X1,-X2,Y2-Y1,x,y,found) : ldioph (-X2,X1,Y2-Y1,x,y,found);
			//dbg(found);
			if (!found) continue;
			ll k1=ceil((Y1-x)/X1),k2=ceil((Y2-y)/X2);
			ll xx1=x+k1*X2 , yy1=y-k1*-1*X1 , xx2=x-k1*X2 , yy2=y+k1*-1*X1;
			ll xx3=x+k2*X2 , yy3=y-k2*-1*X1 , xx4=x-k2*X2 , yy4=y+k2*-1*X1;
			if (Y1+X1*x>=0 && Y1+X1*x<=F){
				connected_to_bingn.push(i);
			}else if (Y1+X1*xx1>=0 && Y1+X1*xx1<=F){
				connected_to_bingn.push(i);
			}else if(Y1+X1*xx2>=0 && Y1+X1*xx2<=F ){
				connected_to_bingn.push(i);
			}else if(Y1+X1*xx3>=0 && Y1+X1*xx3<=F ){
				connected_to_bingn.push(i);
			}else if(Y1+X1*xx4>=0 && Y1+X1*xx4<=F ){
				connected_to_bingn.push(i);
			}
			//dbg4(Y1+X1*(xx1),Y2+X2*(yy1),Y1+X1*(xx2),Y2+X2*(yy2));
			//dbg4(Y1+X1*(xx3),Y2+X2*(yy3),Y1+X1*(xx4),Y2+X2*(yy4));
			//cout << endl;
		}
	}
	return ans;
}


int main() {
	ll N,F,E,A,B;
	scanf("%lld",&N);
	while(N--){
		scanf("%lld %lld %lld %lld",&F,&E,&A,&B);
		vector <ll> X,Y;
		for (ll i=0;i<E;++i){
			ll input1,input2;
			scanf("%lld %lld",&input1,&input2);
			X.push_back(input1),Y.push_back(input2);
		}

		bool ans=check_path (X,Y,A,B,E,F);


		(ans)? printf("It is possible to move the furniture.\n") : printf("The furniture cannot be moved.\n");
	}
	return 0;
}

















