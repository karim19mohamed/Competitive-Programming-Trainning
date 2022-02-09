#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

vector <bool> sieve(int num){
	vector <bool> is_prime (num+1,true);
	is_prime[1]=0;
	vector <int> prime;
	for (int i=2;i<=num;++i){
		if (!is_prime[i]) continue;
		else {
			prime.push_back(i);
			for (int j=2;i*j<=num;++j){
				is_prime[i*j]=0;
			}
		}
	}
	return is_prime;
}
int get_two_primes(int x,vector <bool> prime){
	int tmp=x-2;
	while(tmp>0){
		if (prime[tmp] && prime[x-tmp]){
			return tmp;
		}
		--tmp;
	}
	return tmp;
}

int n;
int main() {
	vector <bool> prime=sieve(10000000);
	while (cin>>n){
		if (n<8){
			puts("Impossible.");
			continue;
		}
		if (n%2) n=n-2-3,printf("2 3");
		else n=n-2-2,printf("2 2");
		//cout << endl;
		//dbg(n);
		int tmp;
		tmp=get_two_primes(n,prime);
		printf(" %d %d\n",tmp,n-tmp);
	}
	return 0;
}









