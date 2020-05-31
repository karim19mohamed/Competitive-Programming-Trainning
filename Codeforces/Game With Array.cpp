#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
    int n,s;
    scanf("%d %d",&n,&s);
    if (n==s || s/n==1){
    	puts("NO");
    }else{
    	puts("YES");
    	for (int i=0;i<n-1;++i){
    		printf("2 ");
    		s-=2;
    	}
    	printf("%d\n",s);
    	puts("1");
    }

    return 0;
}









