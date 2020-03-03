#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;
const int N=100+100+2,M=N*N;
int t,n,m,head[N],nxt[M],to[M],cap[M],ne,a=-1,b=-1,src,snk;
long long c=-1,cost[M];

void init(int n) {
	memset(head, -1, n * sizeof(head[0]));
	ne = 0;
	a=b=-1;
	c=-1;
}
void addEdge(int f, int t,int c,long long cc) {
	nxt[ne] = head[f];
	to[ne] = t;
	cap[ne]=c;
	cost[ne]=cc;
	head[f] = ne++;
}
void addAugEdge(int f, int t, int c,long long cc) {
	addEdge(f, t, c,cc);
	addEdge(t, f, 0,cc);
}
int vid,vis[N];
int dfsFlow (int i,int FLOW){
    if (i==snk) return FLOW;
    if (!FLOW) return 0;
    if (vis[i]==vid) return 0;

    vis[i]=vid;
    for (int k=head[i];~k;k=nxt[k]){
        int j=to[k];
        int c=cap[k];
        int f=dfsFlow(j,min(FLOW,c));
        if (f){
            cap[k]-=f;
            cap[k^1]+=f;
            swap(cost[k],cost[k^1]);
            cout << cost[k^1] << "  " << cost[k] << endl;
            return f;
        }
    }
    return 0;
}
int maxflow(){
    if (src==snk) return 1e4;
    int flow=0,f;
    while (vid++,f=dfsFlow(src,50000)){
        flow+=f;
    }
    return flow;
}
long long dfs(int i){
    vis[i]=vid;
    long long ans=0;
    for (int k=head[i];~k;k=nxt[k]){
        int j=to[k];
        long long c=cost[k];
        if (vis[j]!=vid){
            if (i!=snk && j!=src){
                ans=ans+c+dfs(j);
            }
            cout << c << endl;
        }
    }
    return ans;
}

#define cf(ID) ID-1
#define ce(ID) ID+n-1

int main()
{
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        scanf("%d%d",&n,&m);
        init(n+m+2);
        src=n+m+2-1;
        snk=n+m+2-2;
        for (int j=1;j<=n;j++) addAugEdge(src,cf(j),1,0);
        for (int j=1;j<=m;j++) addAugEdge(ce(j),snk,1,0);
        while (scanf("%d%d%lld",&a,&b,&c),a){
            addAugEdge (cf(a),ce(b),1,c);
            //cout << cf(a) << "  " << ce(b) << "  " << c << endl;
        }
        int f=maxflow();
        vid++;
        long long ans=dfs(snk);
        printf("%lld\n",ans);
    }
    return 0;
}
