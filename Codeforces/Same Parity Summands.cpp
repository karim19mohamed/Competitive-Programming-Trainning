#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int t,n,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		if (k>n){
			puts("NO");
			continue;
		}
		if (n==k){
			puts("YES");
			for (int i=0;i<k;++i) cout << "1" << " \n"[i==k-1];
			continue;
		}
		if (n%2==0){
			if (n/2>=k){
				puts("YES");
				for (int i=0;i<k-1;++i) printf("2 ");
				printf("%d\n",n-2*(k-1));
			}else if ((n-k+1)%2){
				puts("YES");
				for (int i=0;i<k-1;++i) printf("1 ");
				printf("%d\n",n-(k-1));
			}else{
				puts("NO");
			}
		}else{
			if (k%2==0){
				puts("NO");
			}else{
				puts("YES");
				for (int i=0;i<k-1;++i) printf("1 ");
				printf("%d\n",n-k+1);
			}
		}
	}
	return 0;
}










