// https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array/0
#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int t,n,k,arr[10000009];

//TTTTTTTTTTTTTTTTFFFFFFFFFFFF
int BS(int s,int e){
	while(s<e){
		int mid=s+(e-s+1)/2;
		(arr[mid]<=k)? s=mid : e=mid-1;
	}
	return (arr[s]==k)? s: -1;
}

int main() {
	//code
	scanf("%d",&t);
	while(t--){
		int min_arr=100000009,idx=0;
		scanf("%d",&n);
		for (int i=0;i<n;++i){
			scanf("%d",&arr[i]);
			if (min_arr>arr[i]) idx=i,min_arr=arr[i];
		}
		scanf("%d",&k);
		int ans1=BS(0,idx-1),ans2=BS(idx,n-1);
		(ans1==-1)? printf("%d\n",ans2):printf("%d\n",ans1);
	}
	return 0;
}
















