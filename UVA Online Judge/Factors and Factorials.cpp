#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

vector <int> prime_factorization(int num){
	vector <int> v;
	for (int i=2;i*i<=num;++i) while(num%i==0) v.push_back(i),num/=i;
	if (num!=1) v.push_back(num);
	return v;
}

int n;
int main() {
	while (cin>>n && n!=0){
		map <int,int> m;
		int bid_factor=0;
		for(int i=2;i<=n;++i){
			vector <int> factors = prime_factorization(i);
			for(int j=0;j<factors.size();++j){
				m[factors[j]]++;
				bid_factor=max(bid_factor,factors[j]);
			}
		}
		if (n/100) printf("%d! =",n);
		else if (n/10) printf(" %d! =",n);
		else printf("  %d! =",n);
		int cnt=0;
		for(int i=2;i<=bid_factor;++i){
			if(cnt>14) cnt=0,printf("\n      ");
			if (m.count(i)){
				if(m[i]/100) printf("%d",m[i]);
				else if (m[i]/10) printf(" %d",m[i]);
				else printf("  %d",m[i]);
				++cnt;
			}
		}
		printf("\n");
	}
	return 0;
}









