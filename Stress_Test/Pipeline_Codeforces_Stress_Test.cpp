#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

bool valid (ll mid,ll k,ll n){
	ll sum=(k+2)+(k*(k+1)/2)-(mid*(mid+1)/2);
	//dbg4(k,mid_idx,mid,sum);
	return sum>=n;
}

ll naive(ll n,ll k) {
	ll ans=1,pips;
	pips=k;
	while(k--){
		if (pips>=n) break;
		++ans;
		pips+=(k-1);
	}
	ans = (pips>=n)? ans:-1;
	return ans;
}
int main() {
	ll n,k,ans;
	//while(1){
	//cin>>n>>k;
	while(1){
		n= rand() % 100 + 1,k=rand() % 100 + 2;
		//n=78,k=17;
		//n=6,k=3;
		//******************* main Algorithm *******************
		if (n==1){
			puts("0");
			continue;
		}else if (k>=n){
			cout<<"1"<<endl;
			continue;
		}
		ll s=0,e=k-2;
		while(s<e){
			ll mid=s+(e-s+1)/2;
			(valid(mid-1,k-2,n))? s=mid : e=mid-1;
		}
		ans=(valid(s-1,k-2,n))? k-s:-1;
		//******************* compare main Algorithm with naive *******************
		ll ans_naive=naive(n,k);
		if (ans_naive!=ans){
			dbg2(ans_naive,ans);
			dbg2(n,k);
			break;
		}
		cout<<n<<" "<<k<< endl;
	}
	return 0;
}




















