#include <bits/stdc++.h>
using namespace std;
int n;
double nn,ans;

int main() {
	scanf("%d",&n);
	nn=n;
	while (nn!=0){
		ans+=(1/nn);
		--nn;
	}
	printf("%.7lf\n",ans);
	return 0;
}
