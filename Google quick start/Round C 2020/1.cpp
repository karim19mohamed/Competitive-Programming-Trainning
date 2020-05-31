#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
    int t,n,k,a[1000009],cs=1;
    scanf("%d",&t);
    while(t--){
    	scanf("%d %d",&n,&k);
    	int tmp=k,ans=0;
    	bool idx=0;
    	int cnt=0;
    	for (int i=0;i<n;++i){
    		scanf("%d",&a[i]);
    		if (a[i]==k){
    			cnt=1;
    			idx=1;
    			tmp=k-1;
    		}else if (idx){
    			if (a[i]==tmp){
    				++cnt;
    				--tmp;
    			}else{
    				cnt=0;
    				idx=0;
    				tmp=k;
    			}
    		}
    		if (tmp==0){
				idx=cnt=0;
				tmp=k;
				++ans;
			}
    	}
    	if (tmp==0 && idx) ++ans;
    	printf("Case #%d: %d\n",cs++,ans);
    }

    return 0;
}









