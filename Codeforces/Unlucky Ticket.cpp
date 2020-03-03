#include <bits/stdc++.h>
using namespace std;
int n;
string s;
bool b,ans=1;
priority_queue <int> q1,q2;

int main() {
	cin >> n >> s;
	for (int i=0;i<n;++i){
		q1.push(s[i]-'0');
		q2.push(s[(2*n)-1-i]-'0');
	}
	(q1.top()<q2.top())? b=1 : b=0;
	while(!q1.empty()){
		if (b && q1.top()>=q2.top()){
			ans=0;
			break;
		}else if (!b && q1.top()<=q2.top()){
			ans=0;
			break;
		}
		q1.pop();
		q2.pop();
	}
	(ans) ? printf("YES\n") : printf("NO\n");
	return 0;
}
