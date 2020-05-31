#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

bool comp(string s1,string s2){
	return (s1+s2>s2+s1)? 1:0;
}

int main() {
    int n;
    vector <string> s(59);
    while(scanf("%d",&n) && n){
    	string tmp;
    	vector<int> ans(n,n);
    	priority_queue<pair<int,string> > q;
    	for (int i=0;i<n;++i) cin>>tmp,s[i]=tmp;
    	for (int i=0;i<n;++i){
    		for (int j=i+1;j<n;++j){
    			int num=comp(s[i],s[j]);
    			ans[i]-=(num)? 1:0;
    			ans[j]-=(!num)? 1:0;
    		}
    		dbg2(ans[i],s[i]);
    		q.push({-ans[i],s[i]});
    	}
    	while(!q.empty()){
    		cout << q.top().second;
    		q.pop();
    	}
    	puts("");
    }

    return 0;
}









