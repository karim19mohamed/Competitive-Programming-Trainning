#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;


int main() {
	int t,n,tmp=5;
	scanf("%d",&t);
	vector <int> pyramid;
	pyramid.push_back(2);
	while (pyramid.back()<1000000001){
		pyramid.push_back(pyramid.back()+tmp);
		tmp+=3;
	}
	//dbg(pyramid.size());
	while(t--){
		scanf("%d",&n);
		int ans=0;
		for(int i=pyramid.size()-1;i>=0;--i){
			if (n-pyramid[i]>=0){
				int d=n/pyramid[i];
				n-=pyramid[i]*d,ans+=d;
			}
			if (n==1 || n==0) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}










