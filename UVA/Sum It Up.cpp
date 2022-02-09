#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N=20;

int t,n,a[N],vis[N];
set <string> ans;
void print_a(){
	string s="";
	bool tmp=0;
	for (int i=0;i<n;++i){
		if (vis[i]){
			if (tmp) s+="+";
			s+=to_string(a[i]);
			tmp=1;
		}
	}
	ans.insert(s);
}

void solve(int idx,int sum){
	if (sum>t) return;
	if (sum==t){
		print_a();
		return;
	}
	if (idx==n){
		if (sum==t) print_a();
		return;
	}
	solve(idx+1,sum);
	vis[idx]=1;
	solve(idx+1,sum+a[idx]);
	vis[idx]=0;
}

int main() {
	while (scanf("%d %d",&t,&n) && n){
		for (int i=0;i<n;++i) scanf("%d",&a[i]);
		printf("Sums of %d:\n",t);
		solve(0,0);
		if (!ans.size()){
			puts("NONE");
			continue;
		}
		for (set<string>::reverse_iterator it=ans.rbegin(); it!=ans.rend(); ++it) cout << *it << endl;
		set <string> tmp;
		swap(ans,tmp);
	}
    return 0;
}

















