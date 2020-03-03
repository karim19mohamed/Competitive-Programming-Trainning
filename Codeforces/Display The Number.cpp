#include <bits/stdc++.h>
using namespace std;
int n[109],t;

int main() {
	scanf("%d",&t);
	for (int i=0;i<t;++i) scanf("%d",&n[i]);
	for (int i=0;i<t;++i){
		if (n[i]==2) printf("1");
		else if (n[i]==3) printf("7");
		else if (n[i]%2==0){
			for (int j=0;j<n[i]/2;++j) printf("1");
		}else{
			printf("7");
			for (int j=0;j<(n[i]-2)/2;++j) printf("1");
		}
		printf("\n");
	}
	return 0;
}
