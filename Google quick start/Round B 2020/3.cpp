#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

ll cnt[4];

int main() {
	int t,cs=1;
	scanf("%d",&t);
	string s;
	stack <ll> tmp;
	while(t--){
		cin >> s;
		ll ans1=0,ans2=0,rep=1,grid=1000000000;
		for (ll i=0;i<s.size();++i){
			if (s[i]=='(') continue;
			if (s[i]>='0' && s[i]<='9'){
				tmp.push(rep);
				rep=(rep*s[i]-'0')%grid;
				continue;
			}else if (s[i]==')'){
				dbg(rep);
				rep=tmp.top();
				tmp.pop();
				continue;
			}
			switch (s[i]) {
				case 'N':
					cnt[0]+=rep;
					cnt[0]%=grid;
					break;
				case 'S':
					cnt[1]+=rep;
					cnt[1]%=grid;
					break;
				case 'E':
					cnt[2]+=rep;
					cnt[2]%=grid;
					break;
				case 'W':
					cnt[3]+=rep;
					cnt[3]%=grid;
					break;
			}
		}
		if (cnt[0]>cnt[1]){
			cnt[0]-=cnt[1];
			cnt[0]%=grid;
			if (cnt[0]){
				ans1=grid-cnt[0];
			}
		}else if (cnt[0]<cnt[1]){
			cnt[1]-=cnt[0];
			cnt[1]%=grid;
			ans1=ans1+cnt[1];
		}
		if (cnt[2]>cnt[3]){
			cnt[2]-=cnt[3];
			cnt[2]%=grid;
			ans2=ans2+cnt[2];
		}else if (cnt[2]<cnt[3]){
			cnt[3]-=cnt[2];
			cnt[3]%=grid;
			if (cnt[3]){
				ans2=grid-cnt[3];
			}
		}
		printf("Case #%d: %lld %lld\n",cs++,ans2+1,ans1+1);
		cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;
	}
	return 0;
}









