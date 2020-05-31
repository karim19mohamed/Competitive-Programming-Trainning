#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int t,n,q,cs=1;
ll a[1000009],x[1000009],_x[1000009],y[1000009],_y[1000009];
void solve(){
	ll num=2,neg=-1;
	x[0]=a[0],y[0]=a[0];
	for (int i=1;i<n;++i){
		x[i]=x[i-1]+neg*num*a[i];
		y[i]=y[i-1]+neg*a[i];
		++num,neg*=-1;
	}
	num=2,neg=-1;
	_x[0]=a[1],_y[0]=a[1];
	for (int i=1;i<n-1;++i){
		_x[i]=_x[i-1]+neg*num*a[i+1];
		_y[i]=_y[i-1]+neg*a[i+1];
		//dbg(x[i]);
		++num,neg*=-1;
	}
}

int main() {
    scanf("%d",&t);
    while(t--){
    	scanf("%d %d",&n,&q);
    	ll ans=0;
    	for (int i=0;i<n;++i) scanf("%lld",&a[i]);
    	solve();
    	bool update=0;
    	for (int i=0;i<q;++i){
    		string s;
    		int l,r;
    		cin>>s>>l>>r;
    		if (s[0]=='U'){
    			a[l-1]=r;
    			update=1;
    		}else{
    			if (update){
    				solve();
    				update=0;
    			}
    			ll res;
    			if (l%2){
    				if (l-2>=0){
    					res=x[r-1]-x[l-2]-(l-1)*(y[r-1]-y[l-2]);
    				}else{
    					res=x[r-1];
    				}
    			}else{
    				if (l-3>=0){
    					res=_x[r-2]-_x[l-3]-(l-2)*(_y[r-2]-_y[l-3]);
    					//dbg4(_x[r-2],_x[l-3],_y[r-2],_y[l-3]);
    				}else{
    					res=_x[r-2];
    					//dbg(_x[r-2]);
    				}

    			}
    			ans+=res;
    			//dbg2(res,ans);
    		}
    	}
    	printf("Case #%d: %lld\n",cs++,ans);
    }

    return 0;
}









