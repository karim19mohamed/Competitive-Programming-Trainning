#include <bits/stdc++.h>
using namespace std;
int n,a[100],f,ans;

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;++i){
		scanf("%d",&a[i]);
		f+=a[i];
	}
	//cout << f << endl;
	for (int i=0;i<n;++i){
		int c=f;
		for (int j=i;j<n;++j){
			if (a[j]==0) ++c;
			else --c;
			ans=max(ans,c);
		}
	}
	printf("%d\n",ans);
	return 0;
}
