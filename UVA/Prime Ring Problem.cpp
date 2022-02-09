#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int a[20],n,vis[20];
vector <bool> isprime;
void print_a(){
	for (int i=0;i<n;++i) cout<<a[i]<<" \n"[i==n-1];
}

void solve(int idx){
	if (idx==n){
		if (isprime[ a[0]+a[n-1] ]) print_a();
		return;
	}
	for (int i=2;i<=n;++i){
		if (isprime[ a[idx-1]+i ] && !vis[i]){
			vis[i]=1;
			a[idx]=i;
			solve(idx+1);
			vis[i]=0;
		}
	}

}

vector <bool> sieve(int n){
	vector <bool> is_prime (n+1,true);
	for (int i=2;i<=n;++i){
		if (!is_prime[i]) continue;
		else {
			for (int j=2;i*j<=n;++j){
				is_prime[i*j]=0;
			}
		}
	}
	return is_prime;
}

int main() {
	isprime=sieve(40);
	int cs=1;
	bool tmp=0;
	while (scanf("%d",&n)==1){
		if (tmp) puts("");
		printf("Case %d:\n",cs++);
		a[0]=1;
		vis[1]=1;
		solve(1);
		tmp=1;
	}
    return 0;
}

















