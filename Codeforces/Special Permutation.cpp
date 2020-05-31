#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int t,n;
int tmp[]={3,1,4,8,10,6,2,5,7,9};
int t1[]={-1,1},t2[]={1,-1,2},t3[]={1,3,-1,2};
int t4[]={-1,3,1,4,2},
	t5[]={-1,3,1,4,2,5},
	t6[]={-1,3,1,4,6,2,5},
	t7[]={-1,3,1,4,6,2,5,7},
	t8[]={-1,3,1,4,8,6,2,5,7},
	t9[]={-1,3,1,4,8,6,2,5,7,9};

vector <int> solve(vector <int> v,int rem,int tens){
	if (rem==0){
		v.push_back(-1);
		return v;
	}
	switch (rem) {
		case 1:
			for (int i=0;i<2;++i) v.push_back(t1[i]+tens);
			break;
		case 2:
			for (int i=0;i<3;++i) v.push_back(t2[i]+tens);
			break;
		case 3:
			for (int i=0;i<4;++i) v.push_back(t3[i]+tens);
			break;
		case 4:
			for (int i=0;i<5;++i) v.push_back(t4[i]+tens);
			break;
		case 5:
			for (int i=0;i<6;++i) v.push_back(t5[i]+tens);
			break;
		case 6:
			for (int i=0;i<7;++i) v.push_back(t6[i]+tens);
			break;
		case 7:
			for (int i=0;i<8;++i) v.push_back(t7[i]+tens);
			break;
		case 8:
			for (int i=0;i<9;++i) v.push_back(t8[i]+tens);
			break;
		case 9:
			for (int i=0;i<10;++i) v.push_back(t9[i]+tens);
			break;
		default:
			break;
	}
	return v;
}

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if (n<4){
			puts("-1");
			continue;
		}
		vector <int> ans;
		int iti=n/10,tens=0;
		int rem=n%10;
		for (int i=0;i<iti;++i){
			for (int j=0;j<10;++j){
				ans.push_back(tmp[j]+tens);
			}
			tens+=10;
		}
		int last=-1;
		if (ans.size()){
			last=ans[ans.size()-1];
			ans.pop_back();
		}
		ans=solve(ans,rem,tens);
		for(int i=0;i<(int)ans.size();++i){
			if (ans[i]<0 && last!=-1) cout<< last<<" \n"[i==ans.size()-1];
			else if (ans[i]>0) cout<< ans[i]<<" \n"[i==ans.size()-1];
		}
	}
	return 0;
}










