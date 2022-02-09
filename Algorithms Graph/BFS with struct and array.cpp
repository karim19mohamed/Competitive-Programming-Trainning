#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N=26+9+'A',M=1e4+9;
int vid,vis[N];

struct node{
	char n;
	int p;
}q[N];

int bfs(const char &src,const char &dest,vector<char> (&a)[N]){
	q[0]={src,-1};
	vis[src]=++vid;
	int qsz=1;
	for (int i=0;i<qsz;++i){
		char u=q[i].n;
		if (u==dest) return i;
		for (auto v : a[u]){
			if (vis[v]==vid) continue;
			q[qsz++]={v,i};
			vis[v]=vid;
		}
	}
	return -1;
}

void printpath(int idx){
	if (idx==-1){
		return;
	}
	printpath(q[idx].p);
	cout<<q[idx].n;
}

int main() {
	int t,m,qq;
	string x,y;
	scanf("%d",&t);
	while (t--){
		scanf("%d %d",&m,&qq);
		vector<char> a[N];
		for (int i=0;i<m;++i){
			cin >> x >> y;
			a[x[0]].push_back(y[0]),a[y[0]].push_back(x[0]);
		}
		while (qq--){
			cin >> x >> y;
			int ans=bfs(x[0],y[0],a);
			printpath(ans);
			cout<< endl;
		}
		if (t) cout << endl;
	}
    return 0;
}

















