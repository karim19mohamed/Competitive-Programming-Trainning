// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int t,n,k,tens;
	int ans[10];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		k=0;
		tens=1;
		while(n){
			if (n%10){
				ans[k]=n%10;
				ans[k]*=tens;
				++k;
			}
			n/=10;
			tens*=10;
		}
		printf("%d\n",k);
		for(int i=0;i<k;++i) cout<<ans[i]<<" \n"[i==k-1];
	}
	return 0;
}










