#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

bool valid(int c,int* arr,int n,int d){
	int curr=arr[0],num=1;
	for (int i=1;i<n;++i){
		if (arr[i]-curr>=d) ++num,curr=arr[i];
	}
	return (num>=c);
}

int main() {
	int t,n,c,arr[100009];
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&c);
		for (int i=0;i<n;++i) scanf("%d",&arr[i]);
		sort(arr,arr+n);

		int s=0,e=1000000000;
		while (s<e){
			int mid = s+(e-s+1)/2;
			(valid(c,arr,n,mid))? s=mid : e=mid-1;
		}
		printf("%d\n",s);
	}
	return 0;
}


















