#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
    int t,n,e[1000009];
    scanf("%d",&t);
    vector<int> v(1000009,0);

    while(t--){
    	set<int> s;
		set<int>::iterator it;
    	scanf("%d",&n);
    	for (int i=0;i<n;++i){
    		scanf("%d",&e[i]);
    		++v[e[i]];
    		s.insert(e[i]);
    	}
    	int ans=0,rem=0;
    	for (it=s.begin(); it!=s.end(); ++it){
    		int num=*it;
    		//dbg3(num,ans,rem);
    		ans=ans+(v[num]+rem)/num;
    		rem=(v[num]+rem)%num;
    		v[num]=0;
    	}
    	printf("%d\n",ans);
    }
    return 0;
}









