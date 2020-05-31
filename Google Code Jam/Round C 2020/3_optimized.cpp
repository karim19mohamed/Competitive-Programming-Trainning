#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;


int main() {
    int t,n,a[1000009],cs=1;
    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
    	ll ans=0;
    	int shift=0,pref=0;
    	for (int i=0;i<n;++i){
    		scanf("%d",&a[i]);
    		shift+=abs(a[i]);
    	}
    	vector<int> cnt(2*shift+1,0);
    	cnt[shift]=1;
    	for (int i=0;i<n;++i){
    		pref+=a[i];
    		for (int j=0;j*j<=shift+pref;++j){
    			//dbg(ans);
    			ans+=cnt[shift+pref-j*j];
    		}
    		++cnt[shift+pref];
    	}
    	printf("Case #%d: %lld\n",cs++,ans);
    }

    return 0;
}









