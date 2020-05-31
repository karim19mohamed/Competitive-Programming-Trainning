#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int n,a=-2e9,b=2e9,bool_a,bool_b;
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
			if (ans=='Y'){
				if(c1=='>'){
					if (num>=a) a=num,bool_a=1;
				}else{
					if (num<=b) b=num,bool_b=1;
				}
			}else{
				if(c1=='>'){
					if (num<b) b=num,bool_b=0;
				}else{
					if (num>a) a=num,bool_a=0;
				}
			}
			conditions[i][0]= (c1=='>')? 3 : 4;
			conditions[i][1]=num;
			conditions[i][2]= (ans=='Y')? 1 : 0;
		}else{
			sscanf(s," %c %d %c",&c1,&num,&ans);
			if (ans=='Y'){
				if(c1=='>'){
					if (num>a) a=num,bool_a=0;
				}else{
					if (num<b) b=num,bool_b=0;
				}
			}else{
				if(c1=='>'){
					if (num<=b) b=num,bool_b=1;
				}else{
					if (num>=a) a=num,bool_a=1;
				}
			}
			conditions[i][0]= (c1=='>')? 1 : 2;
			conditions[i][1]=num;
			conditions[i][2]= (ans=='Y')? 1 : 0;
		}
	}
	//dbg2(a,b);
	if (b<a) puts("Impossible");
	else if (b==a && !valid(a) ) puts("Impossible");
	else if (b==a) printf("%d\n",a);
	else if (valid(a+1)) printf("%d\n",a+1);
	else puts("Impossible");

	return 0;
}


















