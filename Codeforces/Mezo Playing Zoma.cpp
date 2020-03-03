#include <bits/stdc++.h>
using namespace std;
int n,l,r;
string s;

int main() {
	scanf("%d",&n);
	cin >> s;
	for (int i=0;i<s.size();++i) (s[i]=='R')? ++r : ++l;
	printf("%d\n",r+l+1);
	return 0;
}
