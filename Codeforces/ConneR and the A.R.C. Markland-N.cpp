#include <bits/stdc++.h>
using namespace std;
int t,n,s,k,ans[1009],k_i[1009];
map <int,bool> m;

int main() {
	scanf("%d",&t);
	for (int i=0;i<t;++i){
		scanf("%d %d %d",&n,&s,&k);
		for (int j=0;j<k;++j){
			scanf("%d",&k_i[j]);
			m[k_i[j]]=1;
		}
		if(!m[s]) ans[i]=0;
		else{
			int x=s+1,y=s-1,a=0;
			while (a==0){
				if (!m[x] && x<=n) a=x-s;
				else if (!m[y] && y>0) a=s-y;
				else ++x,--y;
			}
			ans[i]=a;
		}
		for (int j=0;j<k;++j){
			m[k_i[j]]=0;
		}
		//cout << "sdasd" << endl;
	}
	for (int i=0;i<t;++i){
		printf("%d\n",ans[i]);
	}
	return 0;
}
