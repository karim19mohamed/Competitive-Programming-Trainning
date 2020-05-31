#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int n,a=-2e9,b=2e9;
int conditions[10009][3];
bool valid (int b){
	//dbg(b);
	for (int i=0;i<n;++i){
		if (conditions[i][0]==1){

			if (!(b>conditions[i][1]) && conditions[i][2]) return false;
			else if (b>conditions[i][1] && !conditions[i][2]) return false;

		}else if (conditions[i][0]==2){

			if (!(b<conditions[i][1]) && conditions[i][2]) return false;
			else if (b<conditions[i][1] && !conditions[i][2]) return false;

		}else if (conditions[i][0]==3){

			if (!(b>=conditions[i][1]) && conditions[i][2]) return false;
			else if (b>=conditions[i][1] && !conditions[i][2]) return false;

		}else if (conditions[i][0]==4){

			if (!(b<=conditions[i][1]) && conditions[i][2]) return false;
			else if (b<=conditions[i][1] && !conditions[i][2]) return false;
		}
	}
	return true;
}

int main() {
	char s[20];
	scanf("%d",&n);
	gets(s);
	for (int i=0;i<n;++i){
		gets(s);
		char c1,c2,ans;
		int num;
		if(s[1]=='='){
			sscanf(s," %c %c %d %c",&c1,&c2,&num,&ans);
			if (ans=='Y' && c1=='>' && num>=a) a=num;
			else if (ans=='N' && c1=='<' && num>a) a=num;
			conditions[i][0]= (c1=='>')? 3 : 4;
			conditions[i][1]=num;
			conditions[i][2]= (ans=='Y')? 1 : 0;
		}else{
			sscanf(s," %c %d %c",&c1,&num,&ans);
			if (ans=='Y' && c1=='>' && num>a) a=num;
			else if (ans=='N' && c1=='<' && num>=a) a=num;
			conditions[i][0]= (c1=='>')? 1 : 2;
			conditions[i][1]=num;
			conditions[i][2]= (ans=='Y')? 1 : 0;
		}
	}
	//dbg(a);
	int st=a , et=2e9;
	while(st<et){
		int mid= ((st>=0 && et>=0) || (st<=0 && et<=0))? st+(et-st+1)/2 : (st+et)/2;
		(valid(mid))? st=mid : et=mid-1;
	}
	(valid(st))?  printf("%d\n",st):puts("Impossible");
	return 0;
}


















