#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

vector<bool> v(10000009,0);
void perf_squ(){
	for (int i=0;i*i<10000009;++i){
		v[i*i]=1;
	}
}

int main() {
    int t,n,a[1000009],cs=1;
    perf_squ();
    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
    	int ans=0;
    	vector<int> cnt(n+1,0);
    	for (int i=0;i<n;++i){
    		scanf("%d",&a[i]);
    		cnt[i]= (i==0)? a[i]:cnt[i-1]+a[i];
    		if (cnt[i]>=0 && v[cnt[i]]) ++ans;
    	}
    	for (int i=0;i<n;++i){
    		for (int j=i+1;j<n;++j){
    			if (cnt[j]-cnt[i]>=0 && v[cnt[j]-cnt[i]]) ++ans;
    		}
    	}
    	printf("Case #%d: %d\n",cs++,ans);
    }

    return 0;
}









