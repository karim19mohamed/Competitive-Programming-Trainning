#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int n,k,a[100009];
bool valid(int l){
	int num=1,curr=a[0];
	for(int i=0;i<n;++i){
		if (a[i]-curr+1>l) ++num,curr=a[i];
	}
	//dbg2(l,num);
	return (num<=k);
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;++i) scanf("%d",&a[i]);

		int st=0,et=10000000000;
		while(st<et){
			int mid=st+(et-st)/2;
			(valid(mid))? et=mid : st=mid+1;
		}
		cout<< st << endl;
	}
	return 0;
}




















