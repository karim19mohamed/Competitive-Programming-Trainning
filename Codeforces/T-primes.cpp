#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100009];
int prime[10000000];

int main() {
	cin >> n;
	for (int i=0;i<n;++i) cin >> a[i];
	for (int i=0;i<n;++i){
		if (a[i]==1){
			cout << "NO" << endl;
			continue;
		}
		long long num=sqrt(a[i]);
		if (num*num==a[i]){
			bool Tprime=1;
			if (prime[num]==0){
				long long tmp=sqrt(num);
				for (int j=2;j<=tmp;++j){
					if (num%j==0){
						Tprime=0;
						prime[num]=2;
						break;
					}
					long long x=(num+j-1)/j;
					x*=j;
					prime[x]=2;
				}
				if (Tprime){
					prime[num]=1;
				}
			}else if (prime[num]==2){
				Tprime=0;
			}
			(Tprime) ? cout << "YES" << endl : cout << "NO" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	return 0;
}
