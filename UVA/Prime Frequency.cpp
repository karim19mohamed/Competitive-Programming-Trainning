#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

vector <bool> sieve(int num){
	vector <bool> is_prime (num+1,true);
	is_prime[0]=is_prime[1]=0;
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

int t,cs;
string s,ans;
int main() {
	vector <bool> prime=sieve(2009);
	scanf("%d",&t);
	while (t--){
		cin >> s;
		map <char,int> m;
		for (int i=0;i<s.size();++i) ++m[s[i]];
		char tmp;
		for (int i=0;i<10;++i) if (m.count('0'+i) && prime[m['0'+i]]) tmp='0'+i,ans=ans+tmp;
		for (int i=0;i<26;++i) if (m.count('A'+i) && prime[m['A'+i]]) tmp='A'+i,ans=ans+tmp;
		for (int i=0;i<26;++i) if (m.count('a'+i) && prime[m['a'+i]]) tmp='a'+i,ans=ans+tmp;
		printf("Case %d: ",++cs);
		if(ans.size()) cout << ans << endl;
		else printf("empty\n");
		ans="";
	}
	return 0;
}









