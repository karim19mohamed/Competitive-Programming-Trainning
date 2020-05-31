#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int t,n,q,cs=1;
ll arr[1000009],x[1000009],_x[1000009],y[1000009],_y[1000009],le[1000009],ri[1000009];
void solve(){
	int num=2,neg=-1;
	x[0]=arr[0],y[0]=arr[0];
	for (int i=1;i<n;++i){
		x[i]=x[i-1]+neg*num*arr[i];
		y[i]=y[i-1]+neg*arr[i];
		++num,neg*=-1;
	}
	num=2,neg=-1;
	_x[0]=arr[1],_y[0]=arr[1];
	for (int i=1;i<n-1;++i){
		_x[i]=_x[i-1]+neg*num*arr[i+1];
		_y[i]=_y[i-1]+neg*arr[i+1];
		//dbg(x[i]);
		++num,neg*=-1;
	}
}

const int nax = 1<<18;

struct FenwickTree {
  ll data[nax];
  FenwickTree() {
    fill_n(data, nax, 0);
  }
  void add(int i, int v) {
    for (i += 5; i < nax; i += i&-i)
      data[i] += v;
  }
  ll sum(int i) {
    ll ret = 0;
    for (i += 5; i; i -= i&-i)
      ret += data[i];
    return ret;
  }
  ll sum(int l, int r) {
    return sum(r-1)-sum(l-1);
  }
};

ll second_code() {
	FenwickTree a, b;
    for (int i = 0; i < n; i++) {
    	ll v=arr[i];
    	a.add(i, (i%2?-1:1)*v);
    	b.add(i, (i%2?-1:1)*i*v);
    }
    ll ans = 0;
    /*while (q--) {
    	char type='Q';
    	if (type == 'U') {
			int i, v;
			cin >> i >> v;
			i--;
			ll diff = v-(i%2?-1:1)*a.sum(i, i+1);
			a.add(i, (i%2?-1:1)*diff);
			b.add(i, (i%2?-1:1)*i*diff);
    	}else if (type == 'Q'){*/
    	for (int i=0;i<q;++i){
    		int l=le[i], r=ri[i];
    		l--;
    		ans += (l%2 ? -1 : 1)*(b.sum(l, r)+(1-l)*a.sum(l, r));
    	}
    	/*} else assert(0);
    }*/
    return ans;
}

int main() {
    while(1){
		n= rand() % 200000 + 1,q=rand() % 100 + 1;
    	ll ans=0;
    	for (int i=0;i<n;++i){
    		arr[i]=rand() % 100 + 1;
    	}
    	solve();
    	for (int i=0;i<q;++i){
    		le[i]=rand() % n + 1;
    		ri[i]=(n-le[i])?rand() % (n-le[i]) + le[i] : le[i];
    	}
    	for (int i=0;i<q;++i){
    		int l=le[i],r=ri[i];
    		/*if (s[0]=='U'){
    			a[l-1]=r;
    			solve();
    		}else{*/
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
    		//}
    	}
    	ll tmp=second_code();

    	if (ans!=tmp){
    		dbg2(ans,tmp);
    		for (int i=0;i<n;++i) cout<<arr[i]<<" ";
    		puts("");
    		for (int i=0;i<q;++i) cout<<le[i]<<" "<<ri[i]<< endl;
    		break;
    	}
    }

    return 0;
}









