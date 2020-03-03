#include <bits/stdc++.h>
using namespace std;
int n,m,a[100009],l[100009],ans[100009];
bool exist[100009];

int main() {
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;++i) scanf("%d",&a[i]);
	for (int i=0;i<m;++i) scanf("%d",&l[i]);
	int num=0;
	for (int i=n-1;i>=0;--i){
		if (!exist[a[i]]){
			exist[a[i]]=1;
			++num;
			ans[i]=num;
		}else{
			ans[i]=num;
		}
	}
	for (int i=0;i<m;++i){
		printf("%d\n",ans[l[i]-1]);
	}
	return 0;
}
