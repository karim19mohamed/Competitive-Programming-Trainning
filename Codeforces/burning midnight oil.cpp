#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int n,k;
bool valid(int v){
	int sum=v;
	while(v){
		v/=k;
		sum+=v;
	}
	return (sum>=n);
}

int main() {
	scanf("%d %d",&n,&k);

	int st=0,et=1000000009;
	while(st<et){
		int mid=st+(et-st)/2;
		(valid(mid))? et=mid : st=mid+1;
	}
	cout<< st << endl;
	return 0;
}




















