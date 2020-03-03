#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int a[1009],b[1009],n,ans,bottle[1009];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;++i){
		scanf("%d %d",&a[i],&b[i]);
		++bottle[a[i]];
	}
	for (int i=0;i<n;++i){
		int x=a[i];
		bool open=0;
		for (int j=0;j<n;++j){
			if (i==j) continue;
			if (b[j]==x){
				open=1;
				break;
			}
		}
		if (!open) ++ans;
	}
	printf("%d\n",ans);
	return 0;
}
