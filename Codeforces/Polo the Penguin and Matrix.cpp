#include <bits/stdc++.h>
using namespace std;
int n,m,d,num,ans;
int a[1000009];

int main() {
	scanf("%d %d %d",&n,&m,&d);
	for (int i=0;i<n*m;++i){
		scanf("%d",&a[i]);
	}
	bool dxd=0;
	for (int j=0;j<n*m;++j){
		num=a[j];
		int tmp_ans=0;
		for (int i=0;i<n*m;++i){
			if( (a[i]-num)%d==0 ){
				tmp_ans+=abs( (a[i]-num)/d );
			}else{
				tmp_ans=-1;
				break;
			}
		}
		if (tmp_ans!=-1){
			if (!dxd){
				ans=tmp_ans;
				dxd=1;
			}else{
				ans=min(ans,tmp_ans);
			}
		}else{
			ans=-1;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
