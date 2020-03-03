#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int t,n,a[2009],num_even,num_odd;

int main() {
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		num_even=num_odd=0;
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
			(a[i]%2)? ++num_odd : ++num_even;
		}
		if (num_odd==0) puts("NO");
		else if (num_even==0 && num_odd%2==1) puts("YES");
		else if (num_even==0 && num_odd%2==0) puts("NO");
		else puts("YES");
	}

	return 0;
}
