#include <bits/stdc++.h>
using namespace std;
long long n,k,ans;
string s;
priority_queue < pair<long long,char> > q;
map <char,long long> m;

int main() {
	scanf("%lld %lld",&n,&k);
	cin >> s;
	for (long long i=0;i<n;++i) ++m[s[i]];
	for (int i=0;i<27;++i) if(m['A'+i]!=0) q.push(make_pair(m['A'+i],'A'+i));
	while(k>0){
		long long x=q.top().first;
		if (k>=x){
			k-=x;
			ans+=x*x;
		}else{
			ans+=k*k;
			k=0;
		}
		q.pop();
	}
	printf("%lld\n",ans);
	return 0;
}
