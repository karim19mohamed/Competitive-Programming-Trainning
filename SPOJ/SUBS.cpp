#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

bool valid(string x,string y,int m){
	int idy=0;
	for (int i=0;i<x.size();++i){
		for (int j=0;j<m;++j){
			while (idy<y.size() && x[i]!=y[idy]) ++idy;
			if (idy>=y.size() || x[i]!=y[idy]) return false;
			++idy;
		}
	}
	return true;
}

int main() {
	int t;
	string x,y;
	scanf("%d",&t);
	while(t--){
		cin>>x>>y;
		int s=0,e=600000;
		while (s<e){
			int mid=s+(e-s+1)/2;
			(valid(x,y,mid))? s=mid : e=mid-1;
		}
		printf("%d\n",s);
	}
	return 0;
}


















