#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N=1009;
char dna[]={'A','C','G','T'};
set<string> ans;
void solve(string s,int k,int change,int idx){
	if (k>change) ans.insert(s);
	if (k==change){
		ans.insert(s);
		return;
	}
	if (idx==s.size()) return;

	for (int j=0;j<4;++j){
		if (s[idx]!=dna[j]){
			char tmp=s[idx];
			s[idx]=dna[j];
			solve(s,k,change+1,idx+1);
			s[idx]=tmp;
		}else{
			solve(s,k,change,idx+1);
		}
	}
}

int main() {
	int t,n,k;
	string s;
	scanf("%d",&t);
	while (t--){
		scanf("%d %d",&n,&k);
		cin>>s;
		ans.insert(s);
		solve(s,k,0,0);
		cout << ans.size() << endl;
		for (set<string>::iterator it=ans.begin(); it!=ans.end(); ++it) cout << *it << endl;
		set<string> tmp;
		swap(tmp,ans);
	}
    return 0;
}

















