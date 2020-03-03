#include <bits/stdc++.h>
using namespace std;
int n,k,p,t;
priority_queue <pair<int,int> > q;
map <pair<int,int>,int> m;

int main() {
	scanf("%d %d",&n,&k);
	for (int i=0;i<n;++i){
		scanf("%d %d",&p,&t);
		q.push(make_pair(p,-1*t));
		++m[make_pair(p,-1*t)];
	}
	for (int i=0;i<k-1;++i){
		q.pop();
		cout << "dsaasd" << endl;
	}
	//p=q.top().first;
	//t=q.top().second;
	printf("%d\n",m[q.top()]);
	//cout << p<<" " << t <<endl;
	return 0;
}
