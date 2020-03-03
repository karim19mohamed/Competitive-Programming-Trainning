#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int p,c,cs=1,e;
	char ch;
	while (cin>>p>>c && p){
		queue <int> q,emergency;
		map <int,bool> m;
		printf("Case %d:\n",cs++);
		if (p>c) p=c;
		for(int i=1;i<=p;++i) q.push(i);
		for (int i=0;i<c;++i){
    		scanf(" %c",&ch);
    		int a;
    		if(ch=='N'){
    			if (!emergency.empty()){
    				a=emergency.front();
    				emergency.pop();
					printf("%d\n",a);
					q.push(a);
					m[a]=1;
					continue;
    			}
				while (m[q.front()]){
					m[q.front()]=0;
					q.pop();
				}
    			a=q.front();
    			q.pop();
    			printf("%d\n",a);
    			q.push(a);
    		}else{
    			scanf("%d",&e);
    			emergency.push(e);
    		}
		}
	}
	return 0;
}


















