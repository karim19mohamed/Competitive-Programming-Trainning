#include <bits/stdc++.h>
using namespace std;
string s[4];
bool a[4][4],ans;

int main() {
	cin >> s[0] >> s[1] >> s[2] >> s[3];
	for (int i=0;i<4;++i){
		for (int j=0;j<4;++j){
			if (s[i][j]=='.') a[i][j]=1;
		}
	}
	for (int i=0;i<3;++i){
		for (int j=0;j<3;++j){
			int num=a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];
			if (num==0 || num==4 || num==1 || num==3) ans=1;
		}
	}
	(ans) ? cout << "YES" << endl : cout << "NO" << endl;
	return 0;
}
